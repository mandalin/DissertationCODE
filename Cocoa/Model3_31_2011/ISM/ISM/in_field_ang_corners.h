 //
//  in_field_ang_corners.h
//  ISM
//
//  Created by Amanda Lind on 4/6/11.
//  Copyright 2011 Pennsylvania State University. All rights reserved.
//

/*
given a specific mother source, and new mother wall, this code determines 
if ANY of the new mother wall is in the field angle generated by the
mother source ITS mother wall. True is returned if ANY of the potential
mother wall is within the field angle, and corners defining the
illuminated portion (within the field angle) are returned. 
 */

bool in_field_angle_corners(std::vector<source> sources /*sources*/, 
                            std::vector<wall> walls /*planes*/, 
                            int mother_q_i /*mother_source_index*/, 
                            int mother_w_i /*mother_wall_index*/,
                            int new_mother_w_i/*new_mother_wall_index*/, 
                            std::vector<corner> & new_corners, 
                            std::vector<int> & numpointsperpoly)
{   
    bool is_in_field_angle=false;
    bool corner_on_reflective_side=false;
    position_vector corner_;
    //is at least one corner of the new mother wall on the reflecting side of the infinite plane containing the mother wall and not included as a corner in the mother wall ?
 
    for( int cornerind=0; cornerind<walls[new_mother_w_i].corners.size(); cornerind++)
    {
        corner_=walls[new_mother_w_i].corners[cornerind];
        
        std::cout<<"new corners ("<<walls[new_mother_w_i].corners[cornerind].x<<", "<<walls[new_mother_w_i].corners[cornerind].y<<", "<<walls[new_mother_w_i].corners[cornerind].z<<")"<<std::endl;
        
        corner_on_reflective_side= (inside( corner_ , walls[mother_w_i], false,0)) || corner_on_reflective_side;
    }
    
    for( int cornerind=0; cornerind<walls[mother_w_i].corners.size(); cornerind++)
    {
        std::cout<<"old corners ("<<walls[mother_w_i].corners[cornerind].x<<", "<<walls[mother_w_i].corners[cornerind].y<<", "<<walls[mother_w_i].corners[cornerind].z<<")"<<std::endl;
    }
    
    
    if(!corner_on_reflective_side)
    {    return corner_on_reflective_side;}
    
    
    
    
    
    
    
   is_in_field_angle=true;
    new_corners.clear();
   // std::vector<corner>    projected_corners;
    std::vector<corner>    mthr_wall_corners;
    std::vector<corner>    potential_mother_wall_corners=walls[new_mother_w_i].corners;
    
    position_vector projected_plane_norm=walls[new_mother_w_i].normal;
    position_vector projected_plane_point=walls[new_mother_w_i].center;
    double projected_plane_d=dot(projected_plane_point,projected_plane_norm);
    position_vector src_point(sources[mother_q_i].position.x,sources[mother_q_i].position.y,sources[mother_q_i].position.z);

    mthr_wall_corners=walls[mother_w_i].corners;
    
    double a,b,c,d,xa,ya,za,xb,yb,zb,t;
    
    a=projected_plane_norm.x;
    b=projected_plane_norm.y;
    c=projected_plane_norm.z;
    d=projected_plane_d;
    corner temp_corner;
    
    xa=src_point.x;
    ya=src_point.y;
    za=src_point.z;
    
     corner projected_corner_temp;
     wall projected_cornered_wall;

    for(int index=mthr_wall_corners.size()-1; index >= 0; index--)  
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
      //  projected_corners.push_back(projected_corner_temp);
        projected_cornered_wall.corners.push_back(projected_corner_temp);
      //  std::cout<<projected_corner_temp.x<<" "<<projected_corner_temp.y<<projected_corner_temp.z<<std::endl;
     }
    
   
  
  //  projected_cornered_wall.corners=projected_corners;
    projected_cornered_wall.normal=walls[new_mother_w_i].normal;
    projected_cornered_wall.num=new_mother_w_i;
    projected_cornered_wall.reflection_coeff=walls[new_mother_w_i].reflection_coeff;
    projected_cornered_wall.center=centerOgravity(projected_cornered_wall);

    
    bool center_inside, temp_point_inside, calculate_plane_union=0;

    
    //Is the projected plane on the proper side of the wall ? See sketch on 7/29/2011
    
    center_inside=inside(projected_cornered_wall.center, walls[mother_w_i], false,0 );
    
    //calculate_plane_union=center_inside;
    calculate_plane_union=center_inside;
    
  
    int num_potential_corners=potential_mother_wall_corners.size();

    is_in_field_angle=0;
    
    if(calculate_plane_union)
    {
 
        
        planeunion(walls[new_mother_w_i],projected_cornered_wall, new_corners,numpointsperpoly); 
    
        
        for( int cornerind=0; cornerind<new_corners.size(); cornerind++)
        {
            if(abs(new_corners[cornerind].x) < 1E-10) {new_corners[cornerind].x=0;}
            if(abs(new_corners[cornerind].y) < 1E-10) {new_corners[cornerind].y=0;}
            if(abs(new_corners[cornerind].z) < 1E-10) {new_corners[cornerind].z=0;}
                                                              
            std::cout<<"projected corners ("<<new_corners[cornerind].x<<", "<<new_corners[cornerind].y<<", "<<new_corners[cornerind].z<<")"<<std::endl;
        }
    
        
        if(new_corners.size()==0)
        {   is_in_field_angle=0;
        }
        else
        {   is_in_field_angle=1;
        }
    }
    
   // std::cout<<"Whether any part of plane "<<new_mother_w_i<<" is iluminated by the field angle generated by sourcce "<<mother_q_i<<" and wall "<<mother_w_i<<" is indicated by 'is_in_field_ang'="<<is_in_field_angle<<std::endl;
    
    
   // plot_InFieldAngle(sources, walls, new_corners, new_mother_w_i, mother_q_i,mother_w_i);
    
    
    
    
    return is_in_field_angle;
    
}
