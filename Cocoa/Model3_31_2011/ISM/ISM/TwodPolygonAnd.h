//
//  2dPolygonAnd.h
//  ISM
//
//  Created by Amanda Lind on 4/19/11.
//  Copyright 2011 Pennsylvania State University. All rights reserved.


//THIS FUNCTION REQUIRES THAT THE TWO POLYGONS BE COPLANAR !!

void TwodPolygonAnd(std::vector<corner> rotated_corners1, std::vector<corner> rotated_corners2, std::vector<corner> & unioncorners, std::vector<int> & numpointsperpoly )
{
        corner tempcorner;


        int numcorners1= rotated_corners1.size();
        int numcorners2= rotated_corners2.size();


        position_vector v1,v2,normr;
        double magnitude;

        v1=sub(rotated_corners1[0],rotated_corners1[1]);
        v2=sub(rotated_corners1[3],rotated_corners1[2]);
        normr=cross(v1,v2);
        magnitude=pyth_sum(normr.v);
        normr.assign(normr.x/magnitude, normr.y/magnitude, normr.z/magnitude);

        namespace gtl = boost::polygon;
        using namespace boost::polygon::operators;
        using namespace gtl;

        //Make types for polygons, points, and sets of polygons 
        typedef boost::polygon::polygon_data<int>                   Poly; 
        typedef boost::polygon::polygon_traits<Poly>::point_type    Point; 
        typedef std::vector<boost::polygon::polygon_data<int> >     PolySet;

        //Points Polygon1
        Point *pts1;
        pts1=new Point[numcorners1];
        for (int index=0; index<numcorners1; index++)
        {
            pts1[index]=gtl::construct<Point>(rotated_corners1[index].x*1000.0, rotated_corners1[index].y*1000.0);
        }

        //Polygon 2
        Point *pts2;
        pts2=new Point[numcorners2];
        for (int index=0; index<numcorners2; index++)
        {
            pts2[index]=gtl::construct<Point>(rotated_corners2[index].x*1000.0, rotated_corners2[index].y*1000.0);
            //mult by 1000 because it rounds to integers.         
        }


        Poly poly1, poly2; 
        gtl::set_points(poly1, pts1, pts1+numcorners1); 
        gtl::set_points(poly2, pts2, pts2+numcorners2); 

        PolySet polys; 

        using namespace boost::polygon::operators; 
        boost::polygon::assign(polys, poly1 & poly2); 

        std::size_t num_polys=polys.size();
        std::size_t num_points_in_poly;

        std::vector<Point> pts; 
//       // std::vector<corner> unioncorners;
//       // std::vector<int> numpointsperpoly; 

        unioncorners.clear();
        numpointsperpoly.clear();
        pts.clear();


        if(num_polys==0);
        //{    return ;}


        std::cout<<" We expect "<<num_polys<<" polynomials"<<std::endl;
        for(std::size_t i = 0; i < num_polys; ++i) 
        { 
            pts.insert(pts.end(), polys[i].begin(), polys[i].end()); 
            num_points_in_poly=pts.size();
            numpointsperpoly.push_back(num_points_in_poly);
            
            std::cout<<" We expect "<<num_points_in_poly<<" points in this poly"<<std::endl;
            for(int index =0; index < num_points_in_poly; index++)
            {    std::cout<<" Here are the stubborn points x= "<<gtl::x(pts[index])<<", y= "<<gtl::y(pts[index])<<std::endl;
                tempcorner.assign(gtl::x(pts[index])/1000.0,gtl::y(pts[index])/1000.0,rotated_corners1[0].z);
                unioncorners.push_back(tempcorner);
                
            }
            pts.clear();
        }    


        std::cout<<"The number of corners defining the union is "<<unioncorners.size()<<std::endl;
    
    delete[] pts1;
    delete[] pts2;
    
}