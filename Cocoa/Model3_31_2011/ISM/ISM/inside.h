/*
 *  inside.h
 *  ISM
 *
 *  Created by Amanda Lind on 3/15/11.
 *  Copyright 2011 Pennsylvania State University. All rights reserved.
 *
 */

//Given a point and a plane, this function returns 1 if the point is on the side of the plane indicated by
//the normal. 

bool inside(position_vector onepoint, wall::wall testwall, bool on_surf_is_inside, double buffer)
{
	bool isinside;
	double dotprod;
	position_vector norm, onecorner;

    position_vector buffervec(buffer*testwall.normal.x/magnitude(testwall.normal) ,buffer*testwall.normal.y/magnitude(testwall.normal) ,buffer*testwall.normal.z/magnitude(testwall.normal));
    
    onepoint=add(onepoint,buffervec);
    
	norm=testwall.normal;

	
    
    //std::cout<<norm.v[0]<<" "<<norm.v[1]<<" "<<norm.v[2]<<" normal"<<std::endl;
	onecorner=testwall.corners[0];
	//std::cout<<onecorner.v[0]<<" "<<onecorner.v[1]<<" "<<onecorner.v[2]<<" corner"<<std::endl;
	dotprod = dot(sub(onepoint,onecorner),norm);
	//std::cout<<dotprod<<std::endl;

	if(dotprod>0 || ((dotprod==0)&&(on_surf_is_inside)))
		{isinside=true;}
	else
		{isinside=false;}

	return isinside;
}
	//std::cout<<dotprod<<std::endl<<isinside<<std::endl;

