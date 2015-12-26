/*
 *  IsSourceEffective.h
 *  ISM
 *
 *  Created by Amanda Lind on 6/13/11.
 *  Copyright 2011 Pennsylvania State University. All rights reserved.
 *
 */


// This module determines whether a source is audible at the receiver. Audibility requires two checks. Given a vector of legal sources, in order for the source to be audible (1) the path the the receiver must not be obscured, and (2) the receiver must lie within the field angle of the source

//!ACHTUNG6! The faster test should happen first. Which test is faster ? infield angle or shaded ?

bool IsSourceEffective (std::vector<source> sources /*sources*/, 
                        std::vector<wall> walls /*planes*/, 
                        int mother_q_i /*mother_source_index*/, 
                        position_vector Ppos,
                        int num_original_planes)
{
    
    bool effective=false; 
    position_vector src_point(sources[mother_q_i].position.x, sources[mother_q_i].position.y, sources[mother_q_i].position.z);
    source Q =sources[mother_q_i];
    
    wall temporary_wall;
    
    //Inside Test////// check to see if the receiver is on the proper side of the reflecting plane ///////
    if(mother_q_i!=0)
    {
        bool is_inside=false;
        
        is_inside=inside( Ppos, walls[walls[sources[mother_q_i].mother_wall_ind].num], true,.01);
        
        if(!is_inside)
        {   std::cout<<"        Inaudible-> Receiver is on wrong side of motherwall"<<std::endl;
            return is_inside;
        }
    }
    
    
    
    //Shaded Test////// path between two points obscured by plane ////////////////////////////
    bool is_shaded=false;
    
        //calculate where line from source to receiver intersects with it's mother plane
        position_vector n,diff,intersection;
        double d,t,temp0,temp1;
        bool point_inside, center_is_visible;
    
    
        if(Q.source_number!=0) //if the source is the original source, then no need to refer to its mother source and mother plane to see if the ray illuminates the location with the receiver, also, no need to refer to the mother plane or mother source to see if the ray is occluded.
        {   n=walls[Q.mother_wall_ind].normal;
            d=dot(walls[Q.mother_wall_ind].corners[0],n);
            temp0=dot(src_point,n);
            diff=sub(Ppos,src_point);
            temp1=dot(diff,n);
            t=(d-temp0)/temp1;
            intersection.assign(src_point.v[0]+diff.v[0]*t, src_point.v[1]+diff.v[1]*t, src_point.v[2]+diff.v[2]*t);
        }
        else
        {   intersection.assign(src_point.v[0], src_point.v[1], src_point.v[2]);
        }
    
    
        //this portion draws a line from intersection to the receiver, and checks if the path is obscured by any planes.
        for (int i=0; i<num_original_planes;i++ )
        {   if(i==9)
            {   std::cout<<"Looking at Ground Plane"<<std::endl;
            }
        
        
            if(mother_q_i!=0)
            {   
                if((i!=Q.mother_wall_ind)&&(i!=walls[Q.mother_wall_ind].num))
                {     
                    std::cout<<"                Obscured by plane "<<i<<" ?"<<std::endl;
                    if(not(pointvisible(intersection,Ppos,walls[i])))
                    {
                        is_shaded=true;
                        std::cout<<"        Inaudible-> Path to Receiver is obsucred by wall "<<i<<std::endl;
                    }
                }
            }
            else
            { 
                if(not(pointvisible(src_point,Ppos,walls[i])))
                {
                    is_shaded=true;
                    std::cout<<"        Inaudible-> Path to Receiver is obsucred by wall "<<i<<std::endl;
                }
            }
        }

        if ((is_shaded)||(mother_q_i==0))   //original source does not have field angle or mother wall so only factor determining audibility is if it's "shaded"
        {   return !is_shaded; 
        }
        
    //In Field Angle ////////is receiver in the field angle of the source //////////////////////
    
    
        std::vector<corner>    projected_corners;
        std::vector<corner>    mthr_wall_corners;
        mthr_wall_corners=walls[Q.mother_wall_ind].corners;
        
        position_vector projected_plane_norm=walls[Q.mother_wall_ind ].normal; 
        
            //the norm may as well be the same as that of the mother wall, arbitrary
        position_vector projected_plane_point=Ppos;
        double projected_plane_d=dot(projected_plane_point,projected_plane_norm);

        double a,b,c,xa,ya,za,xb,yb,zb;
        
        a=projected_plane_norm.x;
        b=projected_plane_norm.y;
        c=projected_plane_norm.z;
        d=projected_plane_d;
        corner temp_corner;
        
        xa=src_point.x;
        ya=src_point.y;
        za=src_point.z;
                
        corner projected_corner_temp;
        
        for(int index=0; index < mthr_wall_corners.size(); index++)
        {   temp_corner=mthr_wall_corners[index];
            xb=temp_corner.x;
            yb=temp_corner.y;
            zb=temp_corner.z;  
            
            t=(d-a*xa-b*ya-c*za)/(a*(xb-xa)+b*(yb-ya)+c*(zb-za));
            double temp1a=xa+(xb-xa)*t;
            double temp2a=ya+(yb-ya)*t;
            double temp3a=za+(zb-za)*t;
            //test this part
            projected_corner_temp.assign(temp1a, temp2a, temp3a);
            projected_corners.push_back(projected_corner_temp);
        }
        
        wall field_angle_plane;
        field_angle_plane.num=NULL;
        field_angle_plane.corners=projected_corners;
        field_angle_plane.mother_wall_numpointsperpoly=walls[Q.mother_wall_ind].mother_wall_numpointsperpoly;
        field_angle_plane.normal=walls[Q.mother_wall_ind].normal;
        
        

        effective=pointinplane(Ppos,field_angle_plane);
    if(!effective)
        {        std::cout<<"        Inaudible-> Out of Field Angle"<<std::endl;}
    
    return effective;
    
}