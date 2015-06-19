//
//  geometry3_2.h
//  ISM
//
//  Created by Amanda Lind on 7/8/11.
//  Copyright 2011 Pennsylvania State University. All rights reserved.
//

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

std::vector<wall> geometry_generalized( std::vector<corner> & unique_corners )
{
    
    //define useful geometric constants
    double wall_height=10*.3048;
    double wall_length=150*.3048;
    double wall_width=125*.3048;
    double wall_thickness=40*.3048;
//    double radius=400.3048;
      double radius=500*.3048;
  
    //declare and initialize corners
    corner southwall4(0,0,0);//1-3
    corner southwall3(0,0,wall_height);//2-2
    corner southwall2(wall_width,0,wall_height);//3-1
    corner southwall1(wall_width,0,0);//4-0
    
    corner westwall4(0,wall_length,0);//5-5
    corner westwall3(0,wall_length,wall_height);//6-4
    corner westwall2=southwall3;
    corner westwall1=southwall4;                      
    
    corner northwall1_4(wall_thickness,wall_length,0);//7-7
    corner northwall1_3(wall_thickness,wall_length,wall_height);//8-6
    corner northwall1_2=westwall3;           
    corner northwall1_1=westwall4;                 
    
    corner eastwall1_4(wall_thickness, wall_thickness,0);//9-9
    corner eastwall1_3(wall_thickness, wall_thickness, wall_height);//10-8
    corner eastwall1_2=northwall1_3;
    corner eastwall1_1=northwall1_4;                
    
    corner northwall2_4(wall_width,wall_thickness,0);//11-11
    corner northwall2_3(wall_width,wall_thickness,wall_height);//12-10
    corner northwall2_2=eastwall1_3;
    corner northwall2_1=eastwall1_4;
    
    corner eastwall2_4=southwall1;
    corner eastwall2_3=southwall2;          
    corner eastwall2_2=northwall2_3;        
    corner eastwall2_1=northwall2_4;                       
    
    
    corner floor4(-radius/1.3, -radius/1.3, 0);//13-15
    corner floor3(-radius/1.3, radius, 0);//14-14
    corner floor2(radius,radius,0);//15-13
    corner floor1(radius,-radius/1.3,0);//16-12
    
    //push all original corners back into a single vector
    std::vector<corner> all_unique_corners;
    
    all_unique_corners.push_back(southwall1);   //0
    all_unique_corners.push_back(southwall2);      //1
    all_unique_corners.push_back(southwall3);     //2
    all_unique_corners.push_back(southwall4);   //3
    all_unique_corners.push_back(westwall3);       //4
    all_unique_corners.push_back(westwall4);    //5
    all_unique_corners.push_back(northwall1_3);    //6
    all_unique_corners.push_back(northwall1_4); //7
    all_unique_corners.push_back(eastwall1_3);     //8
    all_unique_corners.push_back(eastwall1_4);  //9
    all_unique_corners.push_back(northwall2_3);    //10
    all_unique_corners.push_back(northwall2_4); //11
    all_unique_corners.push_back(floor1);       //12
    all_unique_corners.push_back(floor2);       //13
    all_unique_corners.push_back(floor3);       //14
    all_unique_corners.push_back(floor4);       //15
    //eastwall2 has no unique corners. 
    
    //definition of planes with their indices
    
    
    unsigned northwall1_inds[4]={5,4,6,7};
    unsigned northwall2_inds[4]={9,8,10,11}; 
    unsigned southwall_inds[4]={0,1,2,3};
    unsigned eastwall1_inds[4]={7,6,8,9};
    
    unsigned eastwall2_inds[4]={11,10,1,0};
    unsigned westwall_inds[4]={3,2,4,5};
    unsigned northfloor_inds[4]={5,7,13,14};     
    unsigned southfloor_inds[4]={12,0,3,15}; 
    
    unsigned eastfloor_inds[6]={13,7,9,11,0, 12};
    unsigned westfloor_inds[4]={3,5,14,15};
    unsigned roof_inds[7]={8, 6, 4, 2,1,10 }; //Whiy does this look strange if i start with a different corner first ?
    
    wall * tempwall;
    wall northwall1(northwall1_inds,4);
    wall northwall2(northwall2_inds,4);
    wall southwall(southwall_inds,4); 
    wall eastwall1(eastwall1_inds,4); 
    
    wall eastwall2(eastwall2_inds,4);
    wall westwall(westwall_inds,4);
    wall roof(roof_inds,6);
    
    wall northfloor(northfloor_inds,4); 
    wall southfloor(southfloor_inds,4);
    wall eastfloor(eastfloor_inds,6);
    wall westfloor(westfloor_inds,4); 
    
    
    std::vector<wall> walls;       
    
    
    walls.push_back(northwall1);
    walls.push_back(northwall2);
    walls.push_back(southwall);
    walls.push_back(eastwall1);
    
    walls.push_back(eastwall2);
    walls.push_back(westwall);
    walls.push_back(roof);
    
    northfloor.floorplane=true;
    southfloor.floorplane=true;
    eastfloor.floorplane=true;
    westfloor.floorplane=true;
    walls.push_back(northfloor);
    walls.push_back(southfloor);
    walls.push_back(eastfloor);    
    walls.push_back(westfloor);
    
    
    corner tempcorn;
    unique_corners=all_unique_corners;
    
    unsigned corner_index;
    unsigned numcorners;
    
    for(int index=0; index< walls.size(); index++)
    {   
        tempwall= & walls[index]; 
        numcorners= tempwall->num_corners;
        for(int ind=0; ind< numcorners; ind++)
        {   
            corner_index=tempwall->corner_indices[ind];
            tempcorn=unique_corners[corner_index];
            tempwall->corners.push_back(tempcorn);
            
        }
        tempwall->num=index;
        // Generate vectors normal to the walls which are pointing inward
        tempwall->setnorm();              
        tempwall->mother_wall_numpointsperpoly.push_back(tempwall->num_corners) ; //this assumes that each input wall is a single polygon
        //!Achtung! Here is where you would set the Reflection Coeffecients !
        
//        std::cout<<"Wall "<<index<<" contains the corners"<<std::endl;
//        for(int corni=0; corni<numcorners; corni++)
//        {   std::cout<<walls[index].corners[corni].x<<" "<<walls[index].corners[corni].y<<" "<<walls[index].corners[corni].z<<std::endl;
//        }
    }   
    
    walls[0].unique_corners=all_unique_corners;

    
	return walls;
}
