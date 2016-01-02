//
//  SubsamplePlane.h
//  ISM
//
//  Created by Amanda Lind on 12/2/11.
//  Copyright 2011 Pennsylvania State University. All rights reserved.
//

#ifndef ISM_SubsamplePlane_h
#define ISM_SubsamplePlane_h


//ASSUMES THE WALL IS ONLY COMPOSED OF A SINGLE POLYGON !

std::vector<position_vector> SubsamplePlane(wall wall1, double resolution, double distance_from_plane_in_direction_of_normal, bool AddEdgesToSubsample, double radius_of_sim) //resolution is in samples per meter
{

    
        std::vector<corner> orig_corners1;
        std::vector<corner> rotated_corners1;
        position_vector orig_normal_for_adding;
    
        orig_corners1=wall1.corners;
    
        orig_normal_for_adding.x=distance_from_plane_in_direction_of_normal*wall1.normal.x;
        orig_normal_for_adding.y=distance_from_plane_in_direction_of_normal*wall1.normal.y;
        orig_normal_for_adding.z=distance_from_plane_in_direction_of_normal*wall1.normal.z;

        
        const int numcorners1=orig_corners1.size();
        
        boost::numeric::ublas::matrix<double> Transf1(3,3), Transfi1(3,3);
        boost::numeric::ublas::matrix<double> Rotated_corn1(numcorners1,3);
        boost::numeric::ublas::matrix<double> Orig_corn1 (numcorners1, 3);
    

    
        for (unsigned i = 0; i < Orig_corn1.size1 (); ++ i)
        {  
            Orig_corn1(i, 0)=orig_corners1[i].x;
            Orig_corn1(i, 1)=orig_corners1[i].y;
            Orig_corn1(i, 2)=orig_corners1[i].z;
        }

    
        rotate2newFOR(wall1,Transf1,Transfi1);

        for(int i=0; i<3; i++ )
        {
            if(std::abs(Transf1(i,0))<1e-16)
            {Transf1(i,0)=0;}
            if(std::abs(Transf1(i,1))<1e-16)
            {Transf1(i,1)=0;}
            if(std::abs(Transf1(i,2))<1e-16)
            {Transf1(i,2)=0;}
            
            //std::cout<<Transf1(i,0)<<" "<<Transf1(i,1)<<" "<<Transf1(i,2)<<std::endl;
        }
        
        Rotated_corn1=boost::numeric::ublas::prod(Orig_corn1,Transf1);
            
        corner tempcorner;
        for(int index=0; index<numcorners1; index++)
        {           
            tempcorner.assign(Rotated_corn1(index,0),Rotated_corn1(index,1),Rotated_corn1(index,2));
            rotated_corners1.push_back(tempcorner);
        }
  
    
   std::vector<corner> sample_corners;
   std::vector<corner> rotated_sample_corners;
   
    //////////////// Add Edge Corners 
        std::vector<corner> rotated_edge_corners;
        position_vector towards_next_point, start_point;
        position_vector edge_point;
        double mag;
        int numsegs;
        
    if(AddEdgesToSubsample) 
    {
        for(int index=0; index<numcorners1-1; index++)
        {
            towards_next_point=sub(rotated_corners1[index+1],rotated_corners1[index]);
            mag=magnitude(towards_next_point);
            
            towards_next_point.x=(1/resolution)*towards_next_point.x/mag;
            towards_next_point.y=(1/resolution)*towards_next_point.y/mag;
            towards_next_point.z=0;
            
            start_point.x=rotated_corners1[index].x;
            start_point.y=rotated_corners1[index].y;
            start_point.z=rotated_corners1[index].z;
            rotated_edge_corners.push_back(start_point);
            numsegs=floor(mag*resolution);
            
            for(int num_segment=1; num_segment<= numsegs ; num_segment++ )
            {       
                edge_point=add(start_point,towards_next_point);
                rotated_edge_corners.push_back(edge_point);
                start_point.x=edge_point.x;
                start_point.y=edge_point.y;
                start_point.z=edge_point.z;
                
                
                rotated_sample_corners.push_back(start_point);
            }

        }
    }
    /////////////////
    
    
    //Calculate the Subsample Corners
    //given corners rotated_corners1, which should have a zero z values...
    


    long double minx=0; 
    long double miny=0; 
    long double maxx=0; 
    long double maxy=0;
    
     minx=rotated_corners1[0].x;
     maxx=rotated_corners1[0].x;
     miny=rotated_corners1[0].y;
     maxy=rotated_corners1[0].y;
    for(unsigned i=1; i<numcorners1; i++)
    {
        if (rotated_corners1[i].x <minx)
        {   minx=rotated_corners1[i].x;
        }
        if (rotated_corners1[i].x >maxx)
        {   maxx=rotated_corners1[i].x;
        }
        
        if (rotated_corners1[i].y <miny)
            miny=rotated_corners1[i].y;
        if (rotated_corners1[i].y >maxy)
            maxy=rotated_corners1[i].y;
    }
    
    position_vector temp_point;
    bool in_polygon;
    
    for ( double ysamp=miny+((maxx-minx)/abs(maxx-minx))/resolution; ysamp<maxy; ysamp=ysamp+((maxy-miny)/abs(maxy-miny))/resolution)
    {
        for(double xsamp=minx+((maxx-minx)/abs(maxx-minx))/resolution; xsamp<maxx; xsamp=xsamp+((maxx-minx)/abs(maxx-minx))/resolution)
        {
            temp_point.assign(xsamp, ysamp, rotated_corners1[0].z);
            in_polygon=pointinpoly(temp_point, rotated_corners1);
            if(in_polygon) //is this sample point within the rotated plane
            {   rotated_sample_corners.push_back(temp_point);
            }
        }
    }
    
    unsigned numsamples=rotated_sample_corners.size();
    //Rotate Subsample Corners back to original plane
    
    
    boost::numeric::ublas::matrix<double> Sample_Corners_Rot(  numsamples,3);
    boost::numeric::ublas::matrix<double> Sample_Corners(  numsamples,3);
    
    MakeMatrix(rotated_sample_corners, Sample_Corners_Rot); //in storage_adapters.hpp
    
    Sample_Corners=boost::numeric::ublas::prod( Sample_Corners_Rot, Transfi1);
    
    double tmpx, tmpy;
    //inner points
    for(int index=0; index<numsamples; index++)
    {
        tempcorner.assign(Sample_Corners(index,0),Sample_Corners(index,1),Sample_Corners(index,2));
        tempcorner=add(tempcorner,orig_normal_for_adding);
        
        tmpx=(tempcorner.x);
        tmpy=(tempcorner.y);
        if(( tmpx>=-radius_of_sim*.5) && (tmpx <= radius_of_sim)&&( tmpy>=-radius_of_sim*.5) && (tmpy <= radius_of_sim))
        {
            sample_corners.push_back(tempcorner);
   
        }
    }
    std::cout<<endl<<"Sample Points: "<<sample_corners.size()<<endl;
    return sample_corners;
}
    
    
    
    
    

    



#endif
