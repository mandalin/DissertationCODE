//
//  IsInfront.h
//  ISM
//
//  Created by Amanda Lind on 1/19/13.
//  Copyright (c) 2013 Pennsylvania State University. All rights reserved.
//

#ifndef ISM_IsInfront_h
#define ISM_IsInfront_h


bool IsInfront(position_vector onepoint, position_vector norm, position_vector onecorner,  double buffer) //buffer is what is slight offset of point in direction of the norm
{
	bool isinside;
	double dotprod;
    
    position_vector buffervec(buffer*norm.x/magnitude(norm) , buffer*norm.y/magnitude(norm) ,buffer*norm.z/magnitude(norm));
    
    onepoint=add(onepoint,buffervec);
    
	//std::cout<<onecorner.v[0]<<" "<<onecorner.v[1]<<" "<<onecorner.v[2]<<" corner"<<std::endl;
	dotprod = dot(sub(onepoint,onecorner),norm);
	//std::cout<<dotprod<<std::endl;
    
    //	if(dotprod>0 || ((dotprod==0)&&(on_surf_is_inside)))
    if(dotprod>0 || dotprod==0)
    {isinside=true;}
	else
    {isinside=false;}
    
	return isinside;
}
#endif