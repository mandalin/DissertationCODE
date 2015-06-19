//
//  geometry3.h
//  ISM
//
//  Created by Amanda Lind on 4/13/11.
//  Copyright 2011 Pennsylvania State University. All rights reserved.
//



/*
 *  geometry2.h
 *  ISM
 *
 *  Created by Amanda Lind on 3/14/11.
 *  Copyright 2011 Pennsylvania State University. All rights reserved.
 *
 */

//This is the geometry for the L shaped building

std::vector<wall> geometry3(void)
{
    double wall_height=10*.3048;
    double wall_length=150*.3048;
    double wall_width=125*.3048;
    double wall_thickness=40*.3048;
    double radius=400;
    
    corner southwall4(0,0,0);//1-3
    corner southwall3(0,0,wall_height);//2-2
    corner southwall2(wall_width,0,wall_height);//3-1
    corner southwall1(wall_width,0,0);//4-0
    
    corner westwall4(0,wall_length,0);//5-5
    corner westwall3(0,wall_length,wall_height);//6-4
    corner westwall2(0,0,wall_height);                                   //2-2
    corner westwall1(0,0,0);                                            //1-3

    corner northwall1_4(wall_thickness,wall_length,0);//7-7
    corner northwall1_3(wall_thickness,wall_length,wall_height);//8-6
    corner northwall1_2(0,wall_length,wall_height);                     //6-4
    corner northwall1_1(0,wall_length,0);                               //5-5
    
    corner eastwall1_4(wall_thickness, wall_thickness,0);//9-9
    corner eastwall1_3(wall_thickness, wall_thickness, wall_height);//10-8
    corner eastwall1_2(wall_thickness, wall_length,wall_height);            //8-6
    corner eastwall1_1(wall_thickness, wall_length,0);                      //7-7
                     
     corner northwall2_4(wall_width,wall_thickness,0);//11-11
     corner northwall2_3(wall_width,wall_thickness,wall_height);//12-10
     corner northwall2_2(wall_thickness,wall_thickness,wall_height);        //10-8
     corner northwall2_1(wall_thickness,wall_thickness,0);                  //9-9
     
     corner eastwall2_4(wall_width, 0,0);                                   //4-0
     corner eastwall2_3(wall_width, 0, wall_height);                        //3-1
     corner eastwall2_2(wall_width, wall_thickness,wall_height);            //12-10
     corner eastwall2_1(wall_width, wall_thickness,0);                      //11-11                

    
    corner floor4(-radius, -radius, 0);//13-15
    corner floor3(-radius, radius, 0);//14-14
    corner floor2(radius,radius,0);//15-13
    corner floor1(radius,-radius,0);//16-12
    
    //definition of planes
    wall southwall, northwall1, eastwall1, northwall2, eastwall2, westwall, roof, southfloor, westfloor, northfloor;
    wall eastfloor;
    
    southwall.corners.push_back(southwall1);
    southwall.corners.push_back(southwall2);
    southwall.corners.push_back(southwall3);
    southwall.corners.push_back(southwall4);
    
    northwall1.corners.push_back(northwall1_1);
    northwall1.corners.push_back(northwall1_2);
    northwall1.corners.push_back(northwall1_3);
    northwall1.corners.push_back(northwall1_4);
                     
     northwall2.corners.push_back(northwall2_1);
     northwall2.corners.push_back(northwall2_2);
     northwall2.corners.push_back(northwall2_3);
     northwall2.corners.push_back(northwall2_4);
     
    eastwall1.corners.push_back(eastwall1_1);
    eastwall1.corners.push_back(eastwall1_2);
    eastwall1.corners.push_back(eastwall1_3);
    eastwall1.corners.push_back(eastwall1_4);
                     
     eastwall2.corners.push_back(eastwall2_1);
     eastwall2.corners.push_back(eastwall2_2);
     eastwall2.corners.push_back(eastwall2_3);
     eastwall2.corners.push_back(eastwall2_4);                 
    
    westwall.corners.push_back(westwall1);
    westwall.corners.push_back(westwall2);
    westwall.corners.push_back(westwall3);
    westwall.corners.push_back(westwall4);
    
    roof.corners.push_back(southwall2);//3
    roof.corners.push_back(eastwall2_2);//12
    roof.corners.push_back(northwall2_2);//10
    roof.corners.push_back(eastwall1_2);//8
    roof.corners.push_back(northwall1_2);//6
    roof.corners.push_back(westwall2);//2
    
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
    northfloor.corners.push_back(northwall1_1);
    northfloor.corners.push_back(northwall1_4);
    
    eastfloor.corners.push_back(floor4);
    eastfloor.corners.push_back(floor3);
    eastfloor.corners.push_back(eastwall1_4);
    eastfloor.corners.push_back(eastwall1_1);
     eastfloor.corners.push_back(eastwall2_4);
     eastfloor.corners.push_back(eastwall2_1);                 
    
    
    // Generate vectors normal to the walls which are pointing inward
	northfloor.setnorm();
	southfloor.setnorm();
	eastfloor.setnorm();
	westfloor.setnorm();
	northwall1.setnorm();
    northwall2.setnorm();
	southwall.setnorm();
	eastwall1.setnorm();
    eastwall2.setnorm();
	westwall.setnorm();
	roof.setnorm();
    
    
    // Generate vectors which state how many corners are in each polygons (since the vector of corners may represent many polygons)
	northfloor.mother_wall_numpointsperpoly.push_back(northfloor.corners.size());
	southfloor.mother_wall_numpointsperpoly.push_back(southfloor.corners.size());
	eastfloor.mother_wall_numpointsperpoly.push_back(eastfloor.corners.size());
	westfloor.mother_wall_numpointsperpoly.push_back(westfloor.corners.size());
	northwall1.mother_wall_numpointsperpoly.push_back(northwall1.corners.size());
    northwall2.mother_wall_numpointsperpoly.push_back(northwall2.corners.size());
	southwall.mother_wall_numpointsperpoly.push_back(southwall.corners.size());
	eastwall1.mother_wall_numpointsperpoly.push_back(eastwall1.corners.size());
    eastwall2.mother_wall_numpointsperpoly.push_back(eastwall2.corners.size());
	westwall.mother_wall_numpointsperpoly.push_back(westwall.corners.size());
	roof.mother_wall_numpointsperpoly.push_back(roof.corners.size());
    
    
    std::vector<wall> walls;
    walls.push_back(northfloor); 
    walls.push_back(southfloor);
    walls.push_back(eastfloor);
    walls.push_back(westfloor);
    walls.push_back(northwall1);
                         walls.push_back(northwall2);
    walls.push_back(southwall);
    walls.push_back(eastwall1);
                         walls.push_back(eastwall2);
    walls.push_back(westwall);
    walls.push_back(roof);
	
    //!Achtung! Here is where you would set the Reflection Coeffecients !
    
	return walls;
}
