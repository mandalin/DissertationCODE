/*
 *  pointinpoly.h
 *  ISM
 *
 *  Created by Amanda Lind on 3/15/11.
 *  Copyright 2011 Pennsylvania State University. All rights reserved.
 *
 */

bool pointinpoly(position_vector onepoint, std::vector<position_vector> vertices)
{
	bool result=true;

	int numVertices;
	numVertices=vertices.size();


	position_vector p, arg1, arg2;
	arg1=sub(vertices[numVertices-1],onepoint);
	arg2=sub(vertices[0],onepoint);
	p = cross(arg1, arg2);

	for (int i = 0; i < numVertices - 1; i++)
	{
		position_vector q;
		arg1=sub(vertices[i], onepoint);
		arg2=sub(vertices[i+1], onepoint);
		q = cross(arg1, arg2);
		if (dot(p, q) < 0)
			result=false;
	}
	return result;

}