//
//  planeunion.h
//  ISM
//
//  Created by Amanda Lind on 4/6/11.
//  Copyright 2011 Pennsylvania State University. All rights reserved.
//

template<class T> //I dont know what this noes or why it needs to be included :(

//std::vector<corner> planeunion(wall wall1, wall wall2)
int planeunion(wall  & wall1, wall & wall2)
{   std::vector<corner> orig_corners1;
    std::vector<corner> orig_corners2;
    std::vector<corner> rotated_corners1;
    std::vector<corner> rotated_corners2;
   
    orig_corners1=wall1.corners;
    orig_corners2=wall2.corners;
    
    
    const int numcorners1=orig_corners1.size();
    const int numcorners2=orig_corners2.size();
    
    boost::numeric::ublas::matrix<double> Transf1(3,3), Transfi1(3,3);
    boost::numeric::ublas::matrix<double> Transf2(3,3), Transfi2(3,3);
    boost::numeric::ublas::matrix<double> Rotated_corn1(numcorners1,3), Rotated_corn2(numcorners2,3);
    boost::numeric::ublas::matrix<double> Orig_corn1(numcorners1,3), Orig_corn2(numcorners2,3);
    
    double initialValues1[numcorners1][3];
    for(int index=0; index<numcorners1; index++)
    {   initialValues1[index][0]=orig_corners1[index].x;
        initialValues1[index][1]=orig_corners1[index].y;
        initialValues1[index][2]=orig_corners1[index].z;
    }
    
    
    double initialValues2[numcorners2][3];    
    for(int index=0; index<numcorners2; index++)
    {   initialValues2[index][0]=orig_corners2[index].x;
        initialValues2[index][1]=orig_corners2[index].y;
        initialValues2[index][2]=orig_corners2[index].z;
    }
    
    
    MakeMatrix(orig_corners1,Orig_corn1); //in storage_adapters.hpp
    MakeMatrix(orig_corners2,Orig_corn2); //in storage_adapters.hpp
    
    //Obtain transfer functions for the rotations
    rotate2newFOR(wall1,Transf1,Transfi1);
    rotate2newFOR(wall2,Transf2,Transfi2);
    
    Rotated_corn1=boost::numeric::ublas::prod(Orig_corn1,Transf1);
    Rotated_corn2=boost::numeric::ublas::prod(Orig_corn2,Transf2);
    
    corner tempcorner;
    for(int index=0; index<numcorners1; index++)
    {
        tempcorner.assign(Rotated_corn1(index,0),Rotated_corn1(index,1),Rotated_corn1(index,2));
        rotated_corners1.push_back(tempcorner);
    }
    
    for(int index=0; index<numcorners2; index++)
    {
        tempcorner.assign(Rotated_corn2(index,0),Rotated_corn2(index,1),Rotated_corn2(index,2));
        rotated_corners2.push_back(tempcorner);
    }
    
    position_vector v1,v2,normr;
    double magnitude;
    
    v1=sub(rotated_corners1[0],rotated_corners1[1]);
    v2=sub(rotated_corners1[3],rotated_corners1[2]);
    normr=cross(v1,v2);
    magnitude=pyth_sum(normr.v);
    normr.assign(normr.x/magnitude, normr.y/magnitude, normr.z/magnitude);
    
    //c1=round(corners_rotated1(:,1:2));%we dont care about precision higher than a meter..
    //c2=round(corners_rotated2(:,1:2));%
    
    
    //Rotated Corners are now available in array of position vector form    
    bool flipped=false;
    
    if (!(ispolycw(rotated_corners1)));
    {  flipped =1;
        rotated_corners1=flip(rotated_corners1);
    }
    
    if (!(ispolycw(rotated_corners2)));
    { 
        rotated_corners2=flip(rotated_corners2);
    }
    
    
    //these rotated corners now represent 2Dpolygons !
    //how to represent them in the boost library ?
    
    
    
    namespace gtl = boost::polygon;
    using namespace boost::polygon::operators;
    using namespace gtl;
    
    //Make types for polygons, points, and sets of polygons 
    typedef boost::polygon::polygon_data<int>                   Poly; 
    typedef boost::polygon::polygon_traits<Poly>::point_type    Point; 
    typedef std::vector<boost::polygon::polygon_data<int> >     PolySet;
    
    
    //Points Polygon1
    Point pts1[numcorners1];
    for (int index=0; index<numcorners1; index++)
    {
        pts1[index]=gtl::construct<Point>(rotated_corners1[index].x*1000, rotated_corners1[index].y*1000);
    }

    //Polygon 2
    Point pts2[numcorners2];
    for (int index=0; index<numcorners2; index++)
    {
        pts2[index]=gtl::construct<Point>(rotated_corners2[index].x*1000, rotated_corners2[index].y*1000);
        //mult by 1000 because it rounds to integers.         
    }
       
    
    Poly poly1, poly2; 
    gtl::set_points(poly1, pts1, pts1+numcorners1); 
    gtl::set_points(poly2, pts2, pts2+numcorners2); 
   
    PolySet polys; 
    
    using namespace boost::polygon::operators; 
    boost::polygon::assign(polys, poly1 & poly2); 
    
    for(std::size_t i = 0; i < polys.size(); ++i) { 
        std::vector<Point> pts; 
        pts.insert(pts.end(), polys[i].begin(), polys[i].end()); 
}    
