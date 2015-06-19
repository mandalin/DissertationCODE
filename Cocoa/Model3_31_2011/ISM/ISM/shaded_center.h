/*
 *  shaded_center.h
 *  ISM
 *
 *  Created by Amanda Lind on 3/24/11.
 *  Copyright 2011 Pennsylvania State University. All rights reserved.
 *
 */


bool shaded_center(    std::vector<wall> planes, 
                int PlaneIndex, position_vector source_position, 
               source q, int num_original_planes)

// Determines whether a path from a source to a the center of a potential
// mother plane is obscured by another plane

{
    bool is_shaded=false;
    position_vector center3dplane=planes[PlaneIndex].center;
    
	for (int i=0; i<num_original_planes;i++ )
	{
		if((i!=PlaneIndex)&&( (i!=planes[q.mother_wall_ind].num)||q.source_number==0) )
		{	
            if(not(pointvisible(source_position, center3dplane, planes[i])))
			{
				is_shaded=true;
				return is_shaded;
        
			}
        }

	}
	return is_shaded;
}
