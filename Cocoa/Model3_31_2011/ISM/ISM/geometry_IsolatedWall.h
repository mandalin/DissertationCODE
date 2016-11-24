//
//  geometry_IsolatedWall.h
//  ISM
//
//  Created by mandalin on 5/25/15.
//
//

#ifndef ISM_geometry_IsolatedWall_h

std::vector<wall> geometry_generalized_IsolatedWall( std::vector<corner> & unique_corners)
{

    
    //The isolated wall is defined with the origin defined as the location where the line defined by the microphone array and face of the wall closest to the boom wavefront intersect.
    
double wallheight1=36*0.0254;       //#inches, converted to meters.
double wallheight2=(36+6)*0.0254;   //#inches, converted to meters.
double walllength1south=192*0.0254; //#inches, converted to meters.
double walllength1north=84*0.0254;  //#inches, converted to meters.
double blockwidth=5*0.0254;         //#inches, converted to meters.
    
    
    position_vector ref(0,0,0);
    
    corner c1, c2, c3, c4, c5, c6,c1_b,c2_b,c3_b,c4_b, c5_b,c6_b, cf1,cf2,cf3,cf4,temp, temp1;
    
    c1=ref;
    
    temp.assign(0,0,wallheight1);                       c2=add(ref,temp);
    temp.assign(0,walllength1north,0);                  c3=add(c2,temp);
    temp.assign(0,0,-wallheight1);                      c4=add(c3,temp);
    
    temp.assign(0,-walllength1south,0);                 c5=add(c2,temp);
    temp.assign(0,0,-wallheight1);                      c6=add(c5,temp);
    
    cf1.assign(-5,-walllength1south-1,0);
    cf2.assign(5,-walllength1south-1,0);
    cf3.assign(5,walllength1north,0);
    cf4.assign(-5,walllength1north,0);

    temp.assign(-blockwidth,0,0);
                    c1_b=add(c1,temp);
                    c2_b=add(c2,temp);
                    c3_b=add(c3,temp);
                    c4_b=add(c4,temp);
                    c5_b=add(c5,temp);
                    c6_b=add(c6,temp);
    
    //push all original corners back into a single vector
    std::vector<corner> all_unique_corners;
    
    all_unique_corners.push_back(c1);   //0
    all_unique_corners.push_back(c2);   //1
    all_unique_corners.push_back(c3);   //2
    all_unique_corners.push_back(c4);   //3
    all_unique_corners.push_back(c5);   //4
    all_unique_corners.push_back(c6);   //5
    all_unique_corners.push_back(c1_b);   //6
    all_unique_corners.push_back(c2_b);   //7
    all_unique_corners.push_back(c3_b);   //8
    all_unique_corners.push_back(c4_b);   //9
    all_unique_corners.push_back(c5_b);   //10
    all_unique_corners.push_back(c6_b);   //11
    all_unique_corners.push_back(cf1);   //12
    all_unique_corners.push_back(cf2);   //13
    all_unique_corners.push_back(cf3);   //14
    all_unique_corners.push_back(cf4);   //15
    

    //indices of planes
    unsigned eastwall_inds[4]={3, 2, 4,5};
    unsigned westwall_inds[4]={11, 10, 8, 9};
    unsigned northwall_inds[4]={9, 8, 2, 3};
    unsigned southwall_inds[4]={11, 5,4,10};
    unsigned topwall_inds[4]={10, 4, 2, 8};
    
    unsigned south_floor_inds[4]={12,13,5,11};
    unsigned west_floor_inds[4]={12, 11,9, 15};
    unsigned north_floor_inds[4]={15, 9 ,3 ,14};
    unsigned east_floor_inds[4]={13, 14, 3, 5};
    
    
    //  Rotate Corners so that microphone receiver positions, and arrival angles are kosher
    position_vector i_vec(1,0,0);
	position_vector j_vec(0,1,0);
	position_vector k_vec(0,0,1);
    //
    std::vector<position_vector> d_vec;
	d_vec.push_back(i_vec); d_vec.push_back(j_vec); d_vec.push_back(k_vec); //d is just the diagonal identity matrix
    
    double berrings_az=-0.03490658504;       //radians of counter-clockwise rotation from an aerial perspective, 4 degrees
    double  theta=  -berrings_az;
    double  a11=    cos(theta);
    double  a12=    -sin(theta);
    double  a13=    0;
    double  a21=    sin(theta);
    double  a22=    cos(theta);
    double  a23=    0;
    double  a31=    0;
    double  a32=    0;
    double  a33=    1;
    
    double initialValues[3][3] = {
		a11, a12, a13,
		a21, a22, a23,
		a31, a32, a33
	};
    
    boost::numeric::ublas::matrix<double> Transfb;
    Transfb = boost::numeric::ublas::make_matrix_from_pointer(initialValues); //in storage_adapters.hpp
    
    boost::numeric::ublas::matrix<double>  CornerRotated(all_unique_corners.size(),3), CornerTempRotated(1,3), CornerTemp(1,3);
    
	for(int i=0; i<all_unique_corners.size(); i++)
	{
		initialValues[0][0]=all_unique_corners[i].v[0];
		initialValues[0][1]=all_unique_corners[i].v[1];
		initialValues[0][2]=all_unique_corners[i].v[2];
		CornerTemp = boost::numeric::ublas::make_matrix_from_pointer(initialValues); //in storage_adapters.hpp
		//std::cout<<"-------------"<<std::endl;
		//std::cout<<CornerTemp<<std::endl<<std::endl;
		CornerTempRotated=boost::numeric::ublas::prod(CornerTemp,Transfb);
		//std::cout<<CornerTempRotated<<std::endl<<std::endl;
		CornerRotated(i,0)=CornerTempRotated(0,0);
		CornerRotated(i,1)=CornerTempRotated(0,1);
		CornerRotated(i,2)=CornerTempRotated(0,2);
		//std::cout<<CornerRotated<<std::endl<<std::endl;
        
        all_unique_corners[i].assign(CornerRotated(i,0),CornerRotated(i,1),CornerRotated(i,2));
	}
    
    
    //definition of planes
    wall * tempwall;
    wall northwall(northwall_inds,4);
    wall southwall(southwall_inds,4);
    wall eastwall(eastwall_inds,4);
    wall westwall(westwall_inds,4);
    wall topwall(topwall_inds,4);
    
    wall southfloor(south_floor_inds,4);
    wall eastfloor(east_floor_inds,4);
    wall northfloor(north_floor_inds,4);
    wall westfloor(west_floor_inds,4);
    
    //Identify which are floor planes
    northfloor.floorplane=true;
    southfloor.floorplane=true;
    eastfloor.floorplane=true;
    westfloor.floorplane=true;
    
    
    //include all planes in a vector
    std::vector<wall> walls;
    walls.push_back(northwall);
    walls.push_back(southwall);
    walls.push_back(eastwall);
    walls.push_back(westwall);
    walls.push_back(topwall);
    
    walls.push_back(northfloor);
    walls.push_back(southfloor);
    walls.push_back(eastfloor);
    walls.push_back(westfloor);

    
    // This part s
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

#define ISM_geometry_IsolatedWall_h

//Do nothing if the token is already defined.

#endif
