/*
 *  wall.h
 *  ISM
 *
 *  Created by Amanda Lind on 2/28/11.
 *  Copyright 2011 Pennsylvania State University. All rights reserved.
 *
 */

//#include "position_vector_class.h" this needs to be included first

class wall{
public:
	wall(){ num=0; normal.x=0.0; normal.y=0.0,normal.z=0.0;};
	unsigned num;
	std::vector<corner> corners;
	position_vector normal;
	
	
	void setnorm()
	{	position_vector tempnorm;
		double tempmag;
		tempnorm= cross(sub(corners[1],corners[0]), sub(corners[2],corners[0]));
		tempmag=pyth_sum(tempnorm.v);
		normal.x=tempnorm.v[0]/tempmag;
		normal.y=tempnorm.v[1]/tempmag;
		normal.z=tempnorm.v[2]/tempmag;
		normal.v[0]=tempnorm.v[0]/tempmag;
		normal.v[1]=tempnorm.v[1]/tempmag;
		normal.v[2]=tempnorm.v[2]/tempmag;
	}
	
};

