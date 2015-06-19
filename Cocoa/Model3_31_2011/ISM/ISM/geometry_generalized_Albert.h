

/*
 *  geometry_generalized_Albert.h
 *  ISM
 *
 *  Created by Amanda Lind on 11/29/11.
 *  Copyright 2011 Pennsylvania State University. All rights reserved.
 *
 */

//This is the geometry for the Box shaped building

std::vector<wall> geometry_generalized_Albert( std::vector<corner> & unique_corners)
{
    
    //define useful geometric constants
    double wall_height=3.75;
    double wall_length=19.66;
    double wall_width=12.24;
    double ridge_height=6.55;
    double radius=500;
    
    //declare and initialize corners
    corner southwall4(-wall_width/2 , -wall_length/2, 0);//1-3
    corner southwall3(-wall_width/2 , -wall_length/2, wall_height);//2-2
    corner southwall2(+wall_width/2 , -wall_length/2, wall_height);//3-1
    corner southwall1(+wall_width/2 , -wall_length/2, 0);//4-0
    
    corner westwall4(-wall_width/2 , +wall_length/2, 0);//5-5
    corner westwall3(-wall_width/2 , +wall_length/2, wall_height);//6-4
    corner westwall2=southwall3;
    corner westwall1=southwall4;
    
    corner northwall4(+wall_width/2 , +wall_length/2, 0);//7-7
    corner northwall3(+wall_width/2 , +wall_length/2, wall_height);//8-6
    corner northwall2=westwall3;
    corner northwall1=westwall4;
    
    corner eastwall4=southwall1;//9-9
    corner eastwall3=southwall2;//10-8
    corner eastwall2=northwall3;
    corner eastwall1=northwall4;
    
    corner floor4(-radius*sqrt(2), -radius*sqrt(2), 0);//13-15
    corner floor3(-radius*sqrt(2), radius*sqrt(2), 0);//14-14
    corner floor2(radius*sqrt(2),radius*sqrt(2),0);//15-13
    corner floor1(radius*sqrt(2),-radius*sqrt(2),0);//16-12
    
    corner ridge_north(0,+wall_length/2,ridge_height);
    corner ridge_south(0,-wall_length/2,ridge_height);
    
    //push all original corners back into a single vector
    std::vector<corner> all_unique_corners;
    
    all_unique_corners.push_back(southwall1);   //0
    all_unique_corners.push_back(southwall2);   //1
    all_unique_corners.push_back(southwall3);   //2
    all_unique_corners.push_back(southwall4);   //3
    
    all_unique_corners.push_back(westwall3);    //4
    all_unique_corners.push_back(westwall4);    //5
    
    all_unique_corners.push_back(northwall3); //6
    all_unique_corners.push_back(northwall4); //7
    
    all_unique_corners.push_back(floor1);       //8
    all_unique_corners.push_back(floor2);       //9
    all_unique_corners.push_back(floor3);       //10
    all_unique_corners.push_back(floor4);       //11
    all_unique_corners.push_back(ridge_south);  //12
    all_unique_corners.push_back(ridge_north);  //13
    
    //eastwall2 has no unique corners.
    
    //definition of planes with their indices
    unsigned southwall_inds[5]={0,1,12,2,3};
    unsigned westwall_inds[4]={3,2,4,5};
    
    unsigned northwall_inds[5]={5,4,13,6,7};
    unsigned eastwall_inds[4]={7,6,1,0};
    
    
    unsigned northfloor_inds[4]={9,10,5,7};
    unsigned southfloor_inds[4]={0,3,11,8};
    unsigned eastfloor_inds[4]={8,9,7,0};
    unsigned westfloor_inds[4]={3,7,10,11};
    
    unsigned east_roof_inds[4]={1,6,13,12};
    unsigned west_roof_inds[4]={ 13, 4, 2, 12 };
    
    
    wall * tempwall;
    wall northwall(northwall_inds,5);
    wall southwall(southwall_inds,5);
    wall eastwall(eastwall_inds,4);
    wall westwall(westwall_inds,4);
    wall east_roof(east_roof_inds,4);
    wall west_roof(west_roof_inds,4);
    
    wall northfloor(northfloor_inds,4);
    wall southfloor(southfloor_inds,4);
    wall eastfloor(eastfloor_inds,4);
    wall westfloor(westfloor_inds,4);
    northfloor.floorplane=true;
    southfloor.floorplane=true;
    eastfloor.floorplane=true;
    westfloor.floorplane=true;
    
    
    
    std::vector<wall> walls;
    
    
    walls.push_back(northwall);
    walls.push_back(southwall);
    walls.push_back(eastwall);
    walls.push_back(westwall);
    walls.push_back(east_roof);
    walls.push_back(west_roof);
    
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
        
        
        std::cout<<"Wall "<<index<<" contains the corners"<<std::endl;
        for(int corni=0; corni<numcorners; corni++)
        {   std::cout<<walls[index].corners[corni].x<<" "<<walls[index].corners[corni].y<<" "<<walls[index].corners[corni].z<<std::endl;
            
        }
        
    }
    
    walls[0].unique_corners=unique_corners;
    
    
	return walls;
}
