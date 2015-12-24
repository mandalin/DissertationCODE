/*
 *  geometry2.h
 *  ISM
 *
 *  Created by Amanda Lind on 3/14/11.
 *  Copyright 2011 Pennsylvania State University. All rights reserved.
 *
 */

//Uses Types:
//	double, corner, wall, vector
//#include <vector>
//#include "wall.h"
	//#include "position_vector_class.h"
	//typedef position_vector corner

std::vector<wall> geometry2(void)
{
double wall_height=10*.3048;
double wall_length=20*.3048;
double wall_width=20*.3048;
double radius=50;

corner southwall4(-wall_width/2 , -wall_length/2, 0);
corner southwall3(-wall_width/2 , -wall_length/2, wall_height);
corner southwall2(+wall_width/2 , -wall_length/2, wall_height);
corner southwall1(+wall_width/2 , -wall_length/2, 0);

corner westwall4(-wall_width/2 , +wall_length/2, 0);
corner westwall3(-wall_width/2 , +wall_length/2, wall_height);
corner westwall2(-wall_width/2 , -wall_length/2, wall_height);
corner westwall1(-wall_width/2 , -wall_length/2, 0);

corner northwall4(+wall_width/2 , +wall_length/2, 0);
corner northwall3(+wall_width/2 , +wall_length/2, wall_height);
corner northwall2(-wall_width/2 , +wall_length/2, wall_height);
corner northwall1(-wall_width/2 , +wall_length/2, 0);

corner eastwall4(+wall_width/2 , -wall_length/2, 0);
corner eastwall3(+wall_width/2 , -wall_length/2, wall_height);
corner eastwall2(+wall_width/2 , +wall_length/2, wall_height);
corner eastwall1(+wall_width/2 , +wall_length/2, 0);

corner floor1(-radius, -radius, 0);
corner floor2(-radius, radius, 0);
corner floor3(radius,radius,0);
corner floor4(radius,-radius,0);

//definition of planes
wall southwall, northwall, eastwall, westwall, roof, southfloor, westfloor, northfloor;
wall eastfloor;

southwall.corners.push_back(southwall1);
southwall.corners.push_back(southwall2);
southwall.corners.push_back(southwall3);
southwall.corners.push_back(southwall4);

northwall.corners.push_back(northwall1);
northwall.corners.push_back(northwall2);
northwall.corners.push_back(northwall3);
northwall.corners.push_back(northwall4);

eastwall.corners.push_back(eastwall1);
eastwall.corners.push_back(eastwall2);
eastwall.corners.push_back(eastwall3);
eastwall.corners.push_back(eastwall4);

westwall.corners.push_back(westwall1);
westwall.corners.push_back(westwall2);
westwall.corners.push_back(westwall3);
westwall.corners.push_back(westwall4);

roof.corners.push_back(southwall2);
roof.corners.push_back(eastwall2);
roof.corners.push_back(northwall2);
roof.corners.push_back(westwall2);

southfloor.corners.push_back(floor1);
southfloor.corners.push_back(floor4);
southfloor.corners.push_back(southwall1);
southfloor.corners.push_back(southwall4);

westfloor.corners.push_back(floor2);
westfloor.corners.push_back(floor1);
westfloor.corners.push_back(westwall1);
westfloor.corners.push_back(westwall4);

northfloor.corners.push_back(floor3);
northfloor.corners.push_back(floor2);
northfloor.corners.push_back(northwall1);
northfloor.corners.push_back(northwall4);

eastfloor.corners.push_back(floor4);
eastfloor.corners.push_back(floor3);
eastfloor.corners.push_back(eastwall1);
eastfloor.corners.push_back(eastwall4);


// Generate vectors normal to the walls which are pointing inward
	northfloor.setnorm();
	southfloor.setnorm();
	eastfloor.setnorm();
	westfloor.setnorm();
	northwall.setnorm();
	southwall.setnorm();
	eastwall.setnorm();
	westwall.setnorm();
	roof.setnorm();
//walls


std::vector<wall> walls;
walls.push_back(northfloor); 
walls.push_back(southfloor);
walls.push_back(eastfloor);
walls.push_back(northwall);
walls.push_back(southwall);
walls.push_back(eastwall);
walls.push_back(westwall);
walls.push_back(roof);
	
	return walls;
}