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
	position_vector n,diff,intersection;
	double d,t,temp0,temp1;
	bool point_inside, center_is_visible;
	
	n=ShadingPlane.normal;
	d=dot(ShadingPlane.corners[0],n);
	temp0=dot(source_position,n);
	diff=sub(receiver_position,source_position);
	temp1=dot(diff,n);
	t=(d-temp0)/temp1;
	intersection.assign(source_position.v[0]+diff.v[0]*t,source_position.v[1]+diff.v[1]*t,source_position.v[2]+diff.v[2]*t);


	if((abs(t)<=1) && (t>0))
	{	point_inside=pointinplane(intersection,ShadingPlane);
		center_is_visible=not(point_inside);
		std::cout<<"intersection point is inside "<<point_inside<<std::endl;
	}
	else
	{	center_is_visible=true;
	}
	
	return center_is_visible;
}
