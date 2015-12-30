/*
 *  pointvisible.h
 *  ISM
 *
 *  Created by Amanda Lind on 3/16/11.
 *  Copyright 2011 Pennsylvania State University. All rights reserved.
 *
 */


bool pointvisible(position_vector source_position,position_vector receiver_position,wall::wall ShadingPlane)
{
	position_vector n,diff,diff1,intersection;
	double d,d1,t,temp0,temp1;
	bool point_inside, center_is_visible, on_plane;
    

	source_position.v[0]=source_position.x;
	source_position.v[1]=source_position.y;
	source_position.v[2]=source_position.z;
    
	n=ShadingPlane.normal;
	d=dot(ShadingPlane.corners[0],n);
	temp0=dot(source_position,n);
	diff=sub(receiver_position,source_position);
	temp1=dot(diff,n);
	t=(d-temp0)/temp1;
	intersection.assign(source_position.v[0]+diff.v[0]*t,source_position.v[1]+diff.v[1]*t,source_position.v[2]+diff.v[2]*t);
    
    
    diff1=sub(receiver_position,ShadingPlane.corners[0]);
    d1=dot(diff1,n);
    if(d1==0)
    {   //receiver is on shading plane.
        on_plane=true;
    }
        
    bool absvar,tvar;
    absvar=(t>=0 && t<=1 )|| (t<=0 && t>=-1) ;
    tvar=(t>0); 
    
	if((absvar) && (tvar))  //this case is only true if plane is between source and receiver
	{	point_inside=pointinplane(intersection,ShadingPlane);
		center_is_visible=not(point_inside);
	//	std::cout<<"intersection point is inside "<<point_inside<<std::endl;
	}
	else
	{	center_is_visible=true;
	}
    
    if(on_plane)
    {center_is_visible=true;}
	
    return center_is_visible;
    
}
