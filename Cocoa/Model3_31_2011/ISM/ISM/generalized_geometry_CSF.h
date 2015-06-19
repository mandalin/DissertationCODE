//
//  generalized_geometry_CSF.h
//  ISM
//
//  Created by Amanda Lind on 11/19/11.
//  Copyright 2011 Pennsylvania State University. All rights reserved.
//

#ifndef ISM_generalized_geometry_CSF_h
#define ISM_generalized_geometry_CSF_h


std::vector<wall> generalized_geometry_CSF( std::vector<corner> & unique_corners )
{
    
    //% *1.-------Notes------*
   // double berrings_az=   NAn; // as calculated by LongLatxyz, drawings on 1/4/10, and google maps
    //% rotate the entire geometry by az counter clockwise around z axis
    //% in order for north to align with the y axis. 
    
    
    //% *2.-------Definition of Corners------*
    //
    double mPERft=.3048;
    double mPERin=0.0254;
    double height_of_CSF=20*mPERft;
    double eave_thickness=22*mPERin;
    double radius=600*mPERft;
    double curvature_fudge=.5;
    
    position_vector height(0,0,height_of_CSF); //height of the house is approximated at 2.6

    position_vector ref(0,0,0);  //Position of CSF40 Microphone
    
    corner c0, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14, c15, c16, temp, temp1;
    corner c0u, c1u, c2u, c3u, c4u, c5u, c6u, c7u, c8u, c9u, c10u, c11u, c12u, c13u, c14u, c15u, c16u;
    corner cf0,cf1,cf2,cf3;
    
    double front_roof_pitch=41/22;
    double front_eave_extension=3.25*mPERft;
    double front_eave_edge_height=front_roof_pitch*3.25*mPERft;
    
    c0.assign(ref);

    temp.assign(.3048*29.5*cos(pi/4), .3048*29.5*sin(pi/4),0 );             c1=add(ref,temp);  
    temp.assign(-.3048*64.333333*cos(pi/4), .3048*64.333333*sin(pi/4),0 );  c2=add(c1,temp);
    temp.assign(-.3048*96.583333*cos(pi/4), -.3048*96.583333*sin(pi/4),0 );  c3=add(c2,temp);
    
    temp.assign(.3048*20.833333*cos(pi/4),  -.3048*20.83333*sin(pi/4),0 );   c16=add(ref,temp);
    temp.assign(-.3048*31.33333*cos(pi/4),  -.3048*31.33333*sin(pi/4),0 );   c15=add(c16,temp);
    temp.assign(    0,                      -.3048*38.41666,0 );             c14=add(c15,temp);
    temp.assign(    .3048*21.08333,         0 ,             0 );             c13=add(c14,temp);
    temp.assign(    0,                      -.3048*55.08333,0 );             c12=add(c13,temp);
    temp.assign(    -.3048*76.5,            0,              0 );             c11=add(c12,temp);   
    temp.assign(    0,                      -.3048*10,      0 );             c10=add(c11,temp);
    temp.assign(    -.3048*52.8333,            0,           0 );             c9=add(c10,temp); 
    temp.assign(    0,                      .3048*10,       0 );             c8=add(c9,temp);
    temp.assign(    -.3048*62.6666,         .0,             0 );             c7=add(c8,temp);
    temp.assign(    0,                      .3048*86,       0 );             c6=add(c7,temp);
    
    temp.assign(    .3048*28.5,             0,              0 );             c5=add(c6,temp);
    
    temp.assign(    .3048*72.4166*cos(pi/4), .3048*72.4166*sin(pi/4),0 );    c4=add(c5,temp);
 
    
    temp.assign(0,0,174.75*mPERin); c0u=add(c0,temp);
    temp.assign(0,0,135*mPERin);   c1u=add(c1,temp);
    temp.assign(0,0,336*mPERin);    c2u=add(c2,temp);
    temp.assign(0,0,336*mPERin);    c3u=add(c3,temp);
    temp.assign(0,0,298*mPERin);    c4u=add(c4,temp);
    temp.assign(0,0,298*mPERin);    c5u=add(c5,temp);
    temp.assign(0,0,356*mPERin-eave_thickness);     c6u=add(c6,temp);
    temp.assign(0,0,356*mPERin-eave_thickness);     c7u=add(c7,temp);
    temp.assign(0,0,356*mPERin-eave_thickness);     c8u=add(c8,temp);
    temp.assign(0,0,356*mPERin-eave_thickness);     c9u=add(c9,temp);
    temp.assign(0,0,356*mPERin-eave_thickness);     c10u=add(c10,temp);
    temp.assign(0,0,356*mPERin-eave_thickness);     c11u=add(c11,temp);
    temp.assign(0,0,135*mPERin-eave_thickness);     c12u=add(c12,temp);
    temp.assign(0,0,135*mPERin);                    c13u=add(c13,temp);
    temp.assign(0,0,174.75*mPERin);                 c14u=add(c14,temp);
    temp.assign(0,0,174.75*mPERin);                 c15u=add(c15,temp);
    temp.assign(0,0,135*mPERin);                   c16u=add(c16,temp);

    corner c12e,c13e, c16e, c21e, c12eu, c13eu, c16eu, c21eu, c32, c36,c12ut,c13ut,c16ut,c21ut;
    
    temp.assign(front_eave_extension,0,-front_eave_extension*front_roof_pitch);     c12e=add(c12u,temp);
    temp.assign(front_eave_extension,0,-front_eave_extension*front_roof_pitch);     c13e=add(c13u,temp);
    temp.assign(front_eave_extension,0,-front_eave_extension*front_roof_pitch);     c16e=add(c16u,temp);
    temp.assign(0,152.32*mPERft,0);                                                        c21e=add(c12e,temp);
    
    temp.assign((1/front_roof_pitch)*eave_thickness,0,eave_thickness+curvature_fudge);      c12eu=add(c12e,temp);
    temp.assign((1/front_roof_pitch)*eave_thickness,0,eave_thickness+curvature_fudge);      c13eu=add(c13e,temp);
    temp.assign((1/front_roof_pitch)*eave_thickness,0,eave_thickness+curvature_fudge);      c16eu=add(c16e,temp);
    temp.assign(0,152.32*mPERft,0);                                                         c21eu=add(c12eu,temp);
    
  
    
    
     temp.assign(-(192-170)*mPERft,0,198*mPERin);                           c32=add(c12,temp);
     temp.assign(0,123*mPERft,0);                                           c36=add(c32,temp);

    
     temp.assign(0,0, eave_thickness);       c12ut=add(c12,temp);
     temp.assign(0,0, eave_thickness);       c13ut=add(c13,temp);
     temp.assign(0,0, eave_thickness);       c16ut=add(c16,temp);
     temp=sub(c16eu,c16ut); 
     temp.assign(-temp.x,-temp.x,0);         c21ut=add(c21eu,temp);
     c21ut.z=c16ut.z; c21ut.v[2]=c16ut.z;

        //Second Story
    
    corner c31, c33, c34, c35, c33u, c34u, c35u, c33t, c36t, c32t;
    
    temp.assign(0,0, 438.5*mPERin);                                         c31=add(c1,temp);
    temp.assign(-96.56*mPERft*sin(pi/4),-96.56*mPERft*sin(pi/4), 0);        c35=add(c31,temp);
    c35.z=318*mPERin-eave_thickness; c35.v[2]=c35.z;
    temp.assign(0,-22.78*mPERft, 0);                                        c34=add(c35,temp);    
    c34.z=318*mPERin-eave_thickness; c34.v[2]=c34.z;
    temp.assign(0,61.2*mPERft, 0);                                          c33=add(c32,temp);   
    
    
    c35u.assign(c35.x, c35.y, 438.5*mPERin);
    c34u.assign(c34.x, c34.y, 435*mPERin - eave_thickness );  
    c33u.assign(c33.x, c33.y, 435*mPERin - eave_thickness );  
    
    c33t.assign(c33.x, c33.y, c34.z);  
    c36t.assign(c36.x, c36.y, c34.z);  
    
    c32t.assign(c32.x, c32.y, c11u.z);  
    
    

    
    //floor corners
    temp.assign(-radius,-radius,0);                           cf0=add(c0,temp);
    temp.assign(-radius,radius,0);                           cf1=add(c0,temp);
    temp.assign(radius,radius,0);                           cf2=add(c0,temp);
    temp.assign(radius,-radius,0);                           cf3=add(c0,temp);    
    
    // 52 Blackbird.m contains code for rating thebuilding so that y is true north. This is not necessary, and instead we opt to rotate the incident angle. 
    
    
    //push all original corners back into a single vector
    std::vector<corner> all_unique_corners;
    
    all_unique_corners.push_back(c0); unsigned c0_=0;
    all_unique_corners.push_back(c1); unsigned c1_=1; 
    all_unique_corners.push_back(c2); unsigned c2_=2;
    all_unique_corners.push_back(c3); unsigned c3_=3;
    all_unique_corners.push_back(c4); unsigned c4_=4;
    all_unique_corners.push_back(c5); unsigned c5_=5;
    all_unique_corners.push_back(c6); unsigned c6_=6;
    all_unique_corners.push_back(c7); unsigned c7_=7;
    all_unique_corners.push_back(c8); unsigned c8_=8;
    all_unique_corners.push_back(c9); unsigned c9_=9;
    all_unique_corners.push_back(c10); unsigned c10_=10;
    all_unique_corners.push_back(c11); unsigned c11_=11;
    all_unique_corners.push_back(c12); unsigned c12_=12;
    all_unique_corners.push_back(c13); unsigned c13_=13;
    all_unique_corners.push_back(c14); unsigned c14_=14;
    all_unique_corners.push_back(c15); unsigned c15_=15;
    all_unique_corners.push_back(c16); unsigned c16_=16;
    
    all_unique_corners.push_back(c0u); unsigned c0u_=17;
    all_unique_corners.push_back(c1u); unsigned c1u_=18; 
    all_unique_corners.push_back(c2u); unsigned c2u_=19;
    all_unique_corners.push_back(c3u); unsigned c3u_=20;
    all_unique_corners.push_back(c4u); unsigned c4u_=21;
    all_unique_corners.push_back(c5u); unsigned c5u_=22;
    all_unique_corners.push_back(c6u); unsigned c6u_=23;
    all_unique_corners.push_back(c7u); unsigned c7u_=24;
    all_unique_corners.push_back(c8u); unsigned c8u_=25;
    all_unique_corners.push_back(c9u); unsigned c9u_=26;
    all_unique_corners.push_back(c10u); unsigned c10u_=27;
    all_unique_corners.push_back(c11u); unsigned c11u_=28;
    all_unique_corners.push_back(c12u); unsigned c12u_=29;
    all_unique_corners.push_back(c13u); unsigned c13u_=30;
    all_unique_corners.push_back(c14u); unsigned c14u_=31;
    all_unique_corners.push_back(c15u); unsigned c15u_=32;
    all_unique_corners.push_back(c16u); unsigned c16u_=33;  
    
    
   //Front Eave Corners
    all_unique_corners.push_back(c12e); unsigned c12e_=34;
    all_unique_corners.push_back(c13e); unsigned c13e_=35;
    all_unique_corners.push_back(c16e); unsigned c16e_=36;
    all_unique_corners.push_back(c21e); unsigned c21e_=37;
    
    all_unique_corners.push_back(c12eu); unsigned c12eu_=38;
    all_unique_corners.push_back(c13eu); unsigned c13eu_=39;
    all_unique_corners.push_back(c16eu); unsigned c16eu_=40;
    all_unique_corners.push_back(c21eu); unsigned c21eu_=41;
    
    all_unique_corners.push_back(c32); unsigned c32_=42;
    all_unique_corners.push_back(c36); unsigned c36_=43;
    
    //Floor Corners
    all_unique_corners.push_back(cf0); unsigned cf0_=44;
    all_unique_corners.push_back(cf1); unsigned cf1_=45;
    all_unique_corners.push_back(cf2); unsigned cf2_=46;
    all_unique_corners.push_back(cf3); unsigned cf3_=47;
    
    //Front Eave Curvature Corners (not used)
    all_unique_corners.push_back(c12ut); unsigned c12ut_=48;
    all_unique_corners.push_back(c13ut); unsigned c13ut_=49;
    all_unique_corners.push_back(c16ut); unsigned c16ut_=50;
    all_unique_corners.push_back(c21ut); unsigned c21ut_=51;
    
    //Second Floor
    all_unique_corners.push_back(c31); unsigned c31_=52;
    all_unique_corners.push_back(c33); unsigned c33_=53;
    all_unique_corners.push_back(c34); unsigned c34_=54;
    all_unique_corners.push_back(c35); unsigned c35_=55;
    all_unique_corners.push_back(c33u); unsigned c33u_=56; 
    all_unique_corners.push_back(c34u); unsigned c34u_=57;
    all_unique_corners.push_back(c35u); unsigned c35u_=58;
    
           
    all_unique_corners.push_back(c32t); unsigned c32t_=59; 
    all_unique_corners.push_back(c33t); unsigned c33t_=60; 
    all_unique_corners.push_back(c36t); unsigned c36t_=61; 
    
    //% *3.-------Definition of Walls------*
    //definition of planes with their indices
    
    unsigned face_corn_inds[26][4]=
    {   {c12_,c13_,c13u_,c12u_},
        {c13_,c14_,c14u_,c13u_},
        {c14_,c15_,c15u_,c14u_},
        {c15_,c16_,c16u_,c15u_},
        {c16_,c0_,c0u_,c16u_},
        {c0_,c1_,c1u_,c0u_},
        {c1_,c2_,c2u_,c31_},
        {c2_,c3_,c3u_,c2u_},
        {c3_,c4_,c4u_,c3u_},
        {c4_,c5_,c5u_,c4u_},
        {c5_,c6_,c6u_,c5u_},
        {c6_,c7_,c7u_,c6u_},
        {c7_,c8_,c8u_,c7u_},
        {c8_,c9_,c9u_,c8u_},
        {c9_,c10_,c10u_,c9u_},
        {c10_,c11_,c11u_,c10u_},
        
        //Front Of Eaves
        {c12e_, c13e_, c13eu_, c12eu_},
        {c13e_, c16e_, c16eu_, c13eu_},
        {c16e_, c21e_, c21eu_, c16eu_},
        //under Eaves
        {c12u_, c13u_, c13e_, c12e_},
        {c16e_, c16u_, c0u_, c21e_},
        //over eaves front
//        {c12eu_, c13eu_, c13ut_, c12ut_},
//        {c13eu_, c16eu_, c16ut_, c13ut_},
//        {c16eu_, c21eu_, c21ut_, c16ut_}
        
        //second floor
        {c34_, c35_, c35u_, c34u_},
        {c33_, c34_, c34u_, c33u_},
        {c33_, c36_, c36t_, c33t_},
        {c32t_, c32_, c33_, c33u_},
        {60,61,55,54}
        
    };
    

    
    
    unsigned floor0_corn_inds[4]={7,6,cf1_,cf0_};  
    unsigned floor1_corn_inds[8]={6,5,4,3,2,1,cf2_, cf1_};  
    unsigned floor2_corn_inds[9]={1,0,16,15,14,13,12,cf3_, cf2_};  
    unsigned floor3_corn_inds[8]={12,11,10,9,8,7,cf0_,cf3_};  
        
    std::vector<wall> faces;   //can't preallocate a structure containing types of variable length
    wall tempface; 
    unsigned tempinds[4];
    unsigned corner_index;
    position_vector tempcorn;
    
    for(int wall_num=0; wall_num<26; wall_num++)
    {
        tempinds[0]=face_corn_inds[wall_num][0];
        tempinds[1]=face_corn_inds[wall_num][1];
        tempinds[2]=face_corn_inds[wall_num][2];
        tempinds[3]=face_corn_inds[wall_num][3];
        
        tempface= wall(tempinds,4); 

        for(int ind=0; ind< 4; ind++)
        {   
            corner_index=tempface.corner_indices[ind];
            tempcorn=all_unique_corners[corner_index];
            tempface.corners.push_back(all_unique_corners[corner_index]);
            print(tempface.corners[ind]);
            
        }
        tempface.num=wall_num;  
        tempface.mother_wall_numpointsperpoly.push_back(tempface.num_corners);//assumes each face is a single polygon
        
        faces.push_back(tempface);
        faces[wall_num].setnorm();  
        print(faces[wall_num].corners[0]);
        print(faces[wall_num].normal);
        
    }
    
 //Front Eave 
    unsigned fronteave_inds[6]={c12eu_, c13eu_, c16eu_, c21eu_, c36_, c32_ };
    wall fronteave(fronteave_inds,6);
    for(int ind=0; ind< 6; ind++)
    {   
        tempcorn=all_unique_corners[fronteave.corner_indices[ind]];
        fronteave.corners.push_back(tempcorn);
    }       
    fronteave.num=faces.size();
    fronteave.setnorm();  
    fronteave.mother_wall_numpointsperpoly.push_back(6);//assumes each face is a single polygon
    faces.push_back(fronteave);//23
    
    
    
//Floors
    wall floor0(floor0_corn_inds,4);
    for(int ind=0; ind< 4; ind++)
    {   
        tempcorn=all_unique_corners[floor0.corner_indices[ind]];
        floor0.corners.push_back(tempcorn);
    }       
    floor0.num=faces.size();
    floor0.floorplane=true;
    floor0.setnorm();  
    floor0.mother_wall_numpointsperpoly.push_back(4);//assumes each face is a single polygon
    faces.push_back(floor0);//24
    
    
    
    wall floor1(floor1_corn_inds,8);
    for(int ind=0; ind< 8; ind++)
    {   
        tempcorn=all_unique_corners[floor1.corner_indices[ind]];
        floor1.corners.push_back(tempcorn);
    }       
    floor1.num=faces.size();
    floor1.floorplane=true;
    floor1.setnorm();  
    floor1.mother_wall_numpointsperpoly.push_back(8);//assumes each face is a single polygon
    faces.push_back(floor1);//25

    
    wall floor2(floor2_corn_inds,9);
    for(int ind=0; ind< 9; ind++)
    {   
        tempcorn=all_unique_corners[floor2.corner_indices[ind]];
        floor2.corners.push_back(tempcorn);
    }       
    floor2.num=faces.size();
    floor2.setnorm();
    floor2.floorplane=true;
    floor2.mother_wall_numpointsperpoly.push_back(9);//assumes each face is a single polygon
    faces.push_back(floor2);//26
    
    
    wall floor3(floor3_corn_inds,8);
    for(int ind=0; ind< 8; ind++)
    {   
        tempcorn=all_unique_corners[floor3.corner_indices[ind]];
        floor3.corners.push_back(tempcorn);
    }       
    floor3.num=faces.size();
    floor3.setnorm(); 
    floor3.floorplane=true;
    floor3.mother_wall_numpointsperpoly.push_back(8);//assumes each face is a single polygon
    faces.push_back(floor3);//27
    
    
    //Under Eave Plane
    unsigned undereave1_inds[6]={c13e_, c13u_, c14u_, c15u_, c16u_, c16eu_};
    wall undereave1(undereave1_inds,6);
    for(int ind=0; ind< 6; ind++)
    {   
        tempcorn=all_unique_corners[undereave1.corner_indices[ind]];
        undereave1.corners.push_back(tempcorn);
    }       
    undereave1.num=faces.size();
    undereave1.setnorm();  
    undereave1.mother_wall_numpointsperpoly.push_back(6);//assumes each face is a single polygon
    faces.push_back(undereave1);//28

    
    // Second Floor
    
    
    
    unsigned SecondFloor1_inds[5]={c1u_, c31_, c35u_, c35_, c36_};
    wall SecondFloor1(SecondFloor1_inds,5);
    for(int ind=0; ind< 5; ind++)
    {   
        tempcorn=all_unique_corners[SecondFloor1.corner_indices[ind]];
        SecondFloor1.corners.push_back(tempcorn);
    }       
    SecondFloor1.num=faces.size();
    SecondFloor1.setnorm();  
    SecondFloor1.mother_wall_numpointsperpoly.push_back(5);//assumes each face is a single polygon
    faces.push_back(SecondFloor1);//29

    
    
    //Side Wall
    unsigned sidewall_inds[8]=        {c11u_,c11_,c12_,c12u_, c12e_, c12eu_, c32_, c32t_};
    wall sidewall(sidewall_inds,8);
    
    for(int ind=0; ind< 8; ind++)
    {   
        tempcorn=all_unique_corners[sidewall.corner_indices[ind]];
        sidewall.corners.push_back(tempcorn);
    }       
    sidewall.num=faces.size();
    sidewall.setnorm();  
    sidewall.mother_wall_numpointsperpoly.push_back(8);//assumes each face is a single polygon
    faces.push_back(sidewall);//30
    
    
    //SloppyRoof
    unsigned sloppyroof_inds[15]=  {19,20,21,22,23,24,25,26,27,28,59,56,57,55,52};
    wall sloppyroof(sloppyroof_inds,15);
    
    for(int ind=0; ind< 15; ind++)
    {   
        tempcorn=all_unique_corners[sloppyroof.corner_indices[ind]];
        sloppyroof.corners.push_back(tempcorn);
    }       
    sloppyroof.num=faces.size();
    sloppyroof.setnorm();  
    sloppyroof.mother_wall_numpointsperpoly.push_back(15);//assumes each face is a single polygon
    //faces.push_back(sloppyroof);//31
    
    
    faces[0].unique_corners=all_unique_corners;
    unique_corners=all_unique_corners;

    return faces;
    
}


#endif
