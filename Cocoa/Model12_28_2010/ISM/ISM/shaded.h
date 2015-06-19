/*
 *  shaded.h
 *  ISM
 *
 *  Created by Amanda Lind on 3/24/11.
 *  Copyright 2011 Pennsylvania State University. All rights reserved.
 *
 */


bool shaded(std::vector<wall> planes, int PlaneIndex, position_vector source_position, std::vector<source> q, int mother_index)
// Determines whether a path from a source to a the center of a potential
// mother plane is obscured by another plane

{
bool is_shaded=false;
	for (int i=0; i<planes.size();i++ )
	{
		if((i!=PlaneIndex)&&(i!=q[i].mother_wall_number))
		{	if(not(pointvisible(source_position,center(planes[i]),planes[i])))
			{
				is_shaded=true;
				return is_shaded;
			}
			else{}
		}
		else{}
	}
	return is_shaded;
}
