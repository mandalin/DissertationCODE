//
//  generalized_geometry_52Blackbird.h
//  ISM
//
//  Created by Amanda Lind on 11/8/11.
//  Copyright 2011 Pennsylvania State University. All rights reserved.
//

#ifndef ISM_generalized_geometry_52Blackbird_h
#define ISM_generalized_geometry_52Blackbird_h

std::vector<wall> generalized_geometry_52Blackbird( std::vector<corner> & all_unique_corners, double berrings_az )
{

//% *1.-------Notes------*
            //double berrings_az=   283.4958; // as calculated by LongLatxyz, drawings on 1/4/10, and google maps
//% rotate the entire geometry by az counter clockwise around z axis
//% in order for north to align with the y axis. 

double seconds_of_reflection=2.5;
double radius_of_geom=343*seconds_of_reflection ;

    


//% *2.-------Definition of Corners------*
//
    double mPERft=.3048;
double mPERin=.0254;
radius_of_geom=300*mPERft;
double height=2.4638; //height of the house is approximated at 2.6
position_vector ext_wall_height(0,0,2.4638);

position_vector ref(0,0,0);

    
//Corners Comprising House with flat roof    
corner c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14, temp, temp1;
c1=ref;

temp.assign(0,61*mPERft+1.5*mPERin,0);      c2=add(ref,temp);
temp.assign(12*mPERft+9*mPERin,0, 0);       c3=add(c2,temp);
temp.assign(0,2*mPERft+10*mPERin,0);        c4=add(c3,temp);
temp.assign(30*mPERft+6.5*mPERin,0,0);      c5=add(c4,temp);

temp.assign(20*mPERft+8*mPERin,0,0);        c14=add(c1,temp);
temp.assign(0,21*mPERft,0);                 c13=add(c14,temp);
temp.assign(4*mPERft+1.5*mPERin,0,0);       c12=add(c13,temp);
temp.assign(0,7*mPERft+18*mPERin,0);        c11=add(c12,temp);
temp.assign(0,11*mPERft+17.5*mPERin,0);     c10=add(c11,temp);



temp.assign(16*mPERft+31*mPERin,0,0);      c7=add(c11,temp);
temp.assign(0,5*mPERft+6*mPERin,0);        c6=add(c7,temp);
temp.assign(-11*mPERft-18*mPERin,0,0);     c8=add(c6,temp);
c9.assign(c8.x,c10.y,0);           
    c11.y=c6.y-1.69;
    
corner ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14;
ct1=add(c1,ext_wall_height); ct2=add(c2,ext_wall_height); ct3=add(c3,ext_wall_height); ct4=add(c4,ext_wall_height); ct5=add(c5,ext_wall_height); ct6=add(c6,ext_wall_height); ct7=add(c7,ext_wall_height); ct8=add(c8,ext_wall_height);
ct9=add(c9,ext_wall_height); ct10=add(c10,ext_wall_height); ct11=add(c11,ext_wall_height); ct12=add(c12,ext_wall_height); ct13=add(c13,ext_wall_height); ct14=add(c14,ext_wall_height);


    ct4.assign(ct4.x,ct4.y, ct4.z-0.0655);
    ct5.assign(ct5.x,ct5.y, ct5.z-0.0655);

//Reflected Corners Comprising House with flat roof
corner cr1, cr2, cr3, cr4, cr5, cr6, cr7, cr8, cr9, cr10, cr11, cr12, cr13, cr14;
corner temp2;
    
temp.assign(2*43*mPERft+2*3.5*mPERin,5.5*mPERft,0);
temp1.assign(-1,1,1);
    
temp2=mult(c1,temp1);   cr1=add(temp,temp2);
temp2=mult(c2,temp1);   cr2=add(temp,temp2);
temp2=mult(c3,temp1);   cr3=add(temp,temp2);
temp2=mult(c4,temp1);   cr4=add(temp,temp2);
temp2=mult(c5,temp1);   cr5=add(temp,temp2);
temp2=mult(c6,temp1);   cr6=add(temp,temp2);
temp2=mult(c7,temp1);   cr7=add(temp,temp2);
temp2=mult(c8,temp1);   cr8=add(temp,temp2);
temp2=mult(c9,temp1);   cr9=add(temp,temp2);
temp2=mult(c10,temp1);   cr10=add(temp,temp2);
temp2=mult(c11,temp1);   cr11=add(temp,temp2);
temp2=mult(c12,temp1);   cr12=add(temp,temp2);
temp2=mult(c13,temp1);   cr13=add(temp,temp2);
temp2=mult(c14,temp1);   cr14=add(temp,temp2);

corner crt1, crt2, crt3, crt4, crt5, crt6, crt7, crt8, crt9, crt10, crt11, crt12, crt13, crt14;
crt1=add(cr1,ext_wall_height); crt2=add(cr2,ext_wall_height); crt3=add(cr3,ext_wall_height); crt4=add(cr4,ext_wall_height); crt5=add(cr5,ext_wall_height); crt6=add(cr6,ext_wall_height);
crt7=add(cr7,ext_wall_height); crt8=add(cr8,ext_wall_height); crt9=add(cr9,ext_wall_height); crt10=add(cr10,ext_wall_height); crt11=add(cr11,ext_wall_height); 
crt12=add(cr12,ext_wall_height); crt13=add(cr13,ext_wall_height); crt14=add(cr14,ext_wall_height);


// Radius Corners
corner cr_edge0, cr_edge1, cr_edge2, cr_edge3;
cr_edge0.assign(-radius_of_geom*sqrt(2),-radius_of_geom*sqrt(2),0);
cr_edge1.assign(-radius_of_geom*sqrt(2),radius_of_geom*sqrt(2),0);
cr_edge2.assign(radius_of_geom*sqrt(2),radius_of_geom*sqrt(2),0);
cr_edge3.assign(radius_of_geom*sqrt(2),-radius_of_geom*sqrt(2),0);
    
    
    //push all original corners back into a single vector
    
    all_unique_corners.push_back(c1);       int c1_=0; 
    all_unique_corners.push_back(c2);       int c2_=1; 
    all_unique_corners.push_back(c3);       int c3_=2; 
    all_unique_corners.push_back(c4);       int c4_=3; 
    all_unique_corners.push_back(c5);       int c5_=4; 
    all_unique_corners.push_back(c6);       int c6_=5; 
    all_unique_corners.push_back(c7);       int c7_=6; 
    all_unique_corners.push_back(c8);       int c8_=7; 
    all_unique_corners.push_back(c9);       int c9_=8; 
    all_unique_corners.push_back(c10);       int c10_=9; 
    all_unique_corners.push_back(c11);       int c11_=10; 
    all_unique_corners.push_back(c12);       int c12_=11; 
    all_unique_corners.push_back(c13);       int c13_=12; 
    all_unique_corners.push_back(c14);       int c14_=13;  
    
    all_unique_corners.push_back(ct1);       int ct1_=14; 
    all_unique_corners.push_back(ct2);       int ct2_=15; 
    all_unique_corners.push_back(ct3);       int ct3_=16; 
    all_unique_corners.push_back(ct4);       int ct4_=17; 
    all_unique_corners.push_back(ct5);       int ct5_=18; 
    all_unique_corners.push_back(ct6);       int ct6_=19; 
    all_unique_corners.push_back(ct7);       int ct7_=20; 
    all_unique_corners.push_back(ct8);       int ct8_=21; 
    all_unique_corners.push_back(ct9);       int ct9_=22; 
    all_unique_corners.push_back(ct10);       int ct10_=23; 
    all_unique_corners.push_back(ct11);       int ct11_=24; 
    all_unique_corners.push_back(ct12);       int ct12_=25; 
    all_unique_corners.push_back(ct13);       int ct13_=26; 
    all_unique_corners.push_back(ct14);       int ct14_=27; 
    
    all_unique_corners.push_back(cr1);       int cr1_=28; 
    all_unique_corners.push_back(cr2);       int cr2_=29; 
    all_unique_corners.push_back(cr3);       int cr3_=30; 
    all_unique_corners.push_back(cr4);       int cr4_=31; 
    all_unique_corners.push_back(cr5);       int cr5_=32; 
    all_unique_corners.push_back(cr6);       int cr6_=33; 
    all_unique_corners.push_back(cr7);       int cr7_=34; 
    all_unique_corners.push_back(cr8);       int cr8_=35; 
    all_unique_corners.push_back(cr9);       int cr9_=36; 
    all_unique_corners.push_back(cr10);       int cr10_=37; 
    all_unique_corners.push_back(cr11);       int cr11_=38; 
    all_unique_corners.push_back(cr12);       int cr12_=39; 
    all_unique_corners.push_back(cr13);       int cr13_=40; 
    all_unique_corners.push_back(cr14);       int cr14_=41; 
    
    all_unique_corners.push_back(crt1);       int crt1_=42; 
    all_unique_corners.push_back(crt2);       int crt2_=43; 
    all_unique_corners.push_back(crt3);       int crt3_=44; 
    all_unique_corners.push_back(crt4);       int crt4_=45; 
    all_unique_corners.push_back(crt5);       int crt5_=46; 
    all_unique_corners.push_back(crt6);       int crt6_=47; 
    all_unique_corners.push_back(crt7);       int crt7_=48; 
    all_unique_corners.push_back(crt8);       int crt8_=49; 
    all_unique_corners.push_back(crt9);       int crt9_=50; 
    all_unique_corners.push_back(crt10);      int crt10_=51; 
    all_unique_corners.push_back(crt11);      int crt11_=52; 
    all_unique_corners.push_back(crt12);      int crt12_=53; 
    all_unique_corners.push_back(crt13);      int crt13_=54; 
    all_unique_corners.push_back(crt14);      int crt14_=55; 
    
    all_unique_corners.push_back(cr_edge0); int cr_edge0_=56;
    all_unique_corners.push_back(cr_edge1); int cr_edge1_=57;
    all_unique_corners.push_back(cr_edge2); int cr_edge2_=58;
    all_unique_corners.push_back(cr_edge3); int cr_edge3_=59;
    
    
    
//=======================================================================    
    
// Sidewalk and Column Corners    
    corner datumW;
    datumW.assign(c14.x, c14.y, c14.z);
    double colwidth=0.4572; //meters
 
    corner c100, c101, c102, c103, c104, c105, c106, c107, c108, c109, c110, c111, c112, c113, c114, c115, c116, c117, c118, c119, c120, c121, c122;

    temp.assign(-6.10060152,0,0);               c100=add(datumW,temp);
    temp.assign(-2.436021617,0,0);              c101=add(datumW,temp);
    temp.assign(-2.436021617,-1.188448161,0);   c102=add(datumW,temp);
    temp.assign(1.842391761,-1.188448161,0);    c103=add(datumW,temp);
    temp.assign(1.842391761, all_unique_corners[11].y,0);     c104=add(datumW,temp);
    c105.assign(all_unique_corners[11].x, all_unique_corners[11].y ,0);
    c106.assign(all_unique_corners[5].x, all_unique_corners[5].y, 0);
    
    c107.assign(all_unique_corners[5].x,all_unique_corners[5].y- 1.2192,0);
    c108.assign(all_unique_corners[5].x,all_unique_corners[5].y- 1.2192-colwidth,0);
    c109.assign(all_unique_corners[5].x-colwidth, all_unique_corners[5].y- 1.2192-colwidth,0);
    c110.assign(all_unique_corners[5].x-colwidth, all_unique_corners[5].y- 1.2192,0);
    c111.assign(all_unique_corners[7].x+colwidth,  all_unique_corners[5].y- 1.2192-colwidth,   0);
    c112.assign(all_unique_corners[7].x,    all_unique_corners[5].y- 1.2192-colwidth,0);
    c113.assign(all_unique_corners[7].x,    all_unique_corners[5].y- 1.2192,0);
    c114.assign(all_unique_corners[7].x+colwidth,    all_unique_corners[5].y- 1.2192,0);
    c115.assign(all_unique_corners[7].x,    datumW.y- 2.436318729,0);
    c116.assign(datumW.x - .277205533,    datumW.y - 2.436318729,0);  
    c117.assign(datumW.x - .277205533,    datumW.y  -20,0);  
    c118.assign(datumW.x - 6.10060152,    datumW.y  -20,0);  
    c119.assign(all_unique_corners[11].x,   all_unique_corners[5].y- 1.2192-colwidth,0);  
    c120.assign(all_unique_corners[11].x+(colwidth/2),    all_unique_corners[5].y- 1.2192-colwidth,0);
    c121.assign(all_unique_corners[11].x+(colwidth/2),  all_unique_corners[5].y- 1.2192,0);
    c122.assign(all_unique_corners[11].x,  all_unique_corners[5].y- 1.2192,0);    
    
    
    all_unique_corners.push_back(c100); int c100_=60;
    all_unique_corners.push_back(c101); int c101_=61;
    all_unique_corners.push_back(c103); int c103_=62;
    all_unique_corners.push_back(c104); int c104_=63;
    all_unique_corners.push_back(c105); int c105_=64;
    all_unique_corners.push_back(c106); int c106_=65;
    all_unique_corners.push_back(c107); int c107_=66;
    all_unique_corners.push_back(c108); int c108_=67;
    all_unique_corners.push_back(c109); int c109_=68;
    all_unique_corners.push_back(c110); int c110_=69;
    all_unique_corners.push_back(c111); int c111_=70;
    all_unique_corners.push_back(c112); int c112_=71;
    all_unique_corners.push_back(c113); int c113_=72;
    all_unique_corners.push_back(c114); int c114_=73;
    all_unique_corners.push_back(c115); int c115_=74;
    all_unique_corners.push_back(c116); int c116_=75;
    all_unique_corners.push_back(c117); int c117_=76;
    all_unique_corners.push_back(c118); int c118_=77;
    all_unique_corners.push_back(c119); int c119_=78;
    all_unique_corners.push_back(c120); int c120_=79;
    all_unique_corners.push_back(c121); int c121_=80;
    all_unique_corners.push_back(c122); int c122_=81;
    

    //column tops
    double colheight=2.4638;
    corner c107t, c108t, c109t, c110t, c111t, c112t, c113t, c114t, c115t, c116t, c117t, c118t, c119t, c120t, c121t, c122t;
    
    c107t.assign(all_unique_corners[5].x,all_unique_corners[5].y- 1.2192,colheight);
    c108t.assign(all_unique_corners[5].x,all_unique_corners[5].y- 1.2192-colwidth,colheight);
    c109t.assign(all_unique_corners[5].x-colwidth,all_unique_corners[5].y- 1.2192-colwidth,colheight);
    c110t.assign(all_unique_corners[5].x-colwidth,all_unique_corners[5].y- 1.2192,colheight);
    c111t.assign(all_unique_corners[7].x+colwidth,    all_unique_corners[5].y- 1.2192-colwidth,   colheight);
    c112t.assign(all_unique_corners[7].x,    all_unique_corners[5].y- 1.2192-colwidth,colheight);
    c113t.assign(all_unique_corners[7].x,    all_unique_corners[5].y- 1.2192,colheight);
    c114t.assign(all_unique_corners[7].x+colwidth,    all_unique_corners[5].y- 1.2192,colheight);
    c115t.assign(all_unique_corners[7].x,    datumW.y- 2.436318729,colheight);
    c116t.assign(datumW.x + 5.546190453,    datumW.y - 2.436318729,colheight);  
    c117t.assign(datumW.x - .277205533,    datumW.y  -3.369250535,colheight);  
    c118t.assign(datumW.x - 6.10060152,    datumW.y  -3.369250535,colheight);  
    c119t.assign(all_unique_corners[11].x,   all_unique_corners[5].y- 1.2192-colwidth,colheight);  
    c120t.assign(all_unique_corners[11].x+(colwidth/2),    all_unique_corners[5].y- 1.2192-colwidth,colheight);
    c121t.assign(all_unique_corners[11].x+(colwidth/2),  all_unique_corners[5].y- 1.2192,colheight);
    c122t.assign(all_unique_corners[11].x,  all_unique_corners[5].y- 1.2192,colheight);    
    
    all_unique_corners.push_back(c107t); int c107t_=82;
    all_unique_corners.push_back(c108t); int c108t_=83;
    all_unique_corners.push_back(c109t); int c109t_=84;
    all_unique_corners.push_back(c110t); int c110t_=85;
    all_unique_corners.push_back(c111t); int c111t_=86;
    all_unique_corners.push_back(c112t); int c112t_=87;
    all_unique_corners.push_back(c113t); int c113t_=88;
    all_unique_corners.push_back(c114t); int c114t_=89;
    all_unique_corners.push_back(c115t); int c115t_=90;
    all_unique_corners.push_back(c116t); int c116t_=91;
    all_unique_corners.push_back(c117t); int c117t_=92;
    all_unique_corners.push_back(c118t); int c118t_=93;
    all_unique_corners.push_back(c119t); int c119t_=94;
    all_unique_corners.push_back(c120t); int c120t_=95;
    all_unique_corners.push_back(c121t); int c121t_=96;
    all_unique_corners.push_back(c122t); int c122t_=97;
    
    //Reflected Sidewalk and Column Corners
    corner cr100, cr101, cr102, cr103, cr104, cr105, cr106, cr107, cr108, cr109, cr110, cr111, cr112, cr113, cr114, cr115, cr116, cr117, cr118, cr119, cr120, cr121, cr122;
   
    temp.assign(2*43*mPERft+2*3.5*mPERin,5.5*mPERft,0);
    temp1.assign(-1,1,1);
    
    temp2=mult(c100,temp1);   cr100=add(temp,temp2); int cr100_=98;
    temp2=mult(c101,temp1);   cr101=add(temp,temp2); int cr101_=99;
    temp2=mult(c102,temp1);   cr102=add(temp,temp2); int cr102_=100;
    temp2=mult(c103,temp1);   cr103=add(temp,temp2); int cr103_=101;
    temp2=mult(c104,temp1);   cr104=add(temp,temp2); int cr104_=102;
    temp2=mult(c105,temp1);   cr105=add(temp,temp2); int cr105_=103;
    temp2=mult(c106,temp1);   cr106=add(temp,temp2); int cr106_=104;
    temp2=mult(c107,temp1);   cr107=add(temp,temp2); int cr107_=105;
    temp2=mult(c108,temp1);   cr108=add(temp,temp2); int cr108_=106;
    temp2=mult(c109,temp1);   cr109=add(temp,temp2); int cr109_=107;
    temp2=mult(c110,temp1);   cr110=add(temp,temp2); int cr110_=108;
    temp2=mult(c111,temp1);   cr111=add(temp,temp2); int cr111_=109;
    temp2=mult(c112,temp1);   cr112=add(temp,temp2); int cr112_=110;
    temp2=mult(c113,temp1);   cr113=add(temp,temp2); int cr113_=111;
    temp2=mult(c114,temp1);   cr114=add(temp,temp2); int cr114_=112;
    temp2=mult(c115,temp1);   cr115=add(temp,temp2); int cr115_=113;
    temp2=mult(c116,temp1);   cr116=add(temp,temp2); int cr116_=114;
    temp2=mult(c117,temp1);   cr117=add(temp,temp2); int cr117_=115;
    temp2=mult(c118,temp1);   cr118=add(temp,temp2); int cr118_=116;
    temp2=mult(c119,temp1);   cr119=add(temp,temp2); int cr119_=117;
    temp2=mult(c120,temp1);   cr120=add(temp,temp2); int cr120_=118;
    temp2=mult(c121,temp1);   cr121=add(temp,temp2); int cr121_=119;
    temp2=mult(c122,temp1);   cr122=add(temp,temp2); int cr122_=120;

    all_unique_corners.push_back(cr100); 
    all_unique_corners.push_back(cr101); 
    all_unique_corners.push_back(cr102); 
    all_unique_corners.push_back(cr103); 
    all_unique_corners.push_back(cr104); 
    all_unique_corners.push_back(cr105); 
    all_unique_corners.push_back(cr106); 
    all_unique_corners.push_back(cr107); 
    all_unique_corners.push_back(cr108); 
    all_unique_corners.push_back(cr109); 
    all_unique_corners.push_back(cr110); 
    all_unique_corners.push_back(cr111); 
    all_unique_corners.push_back(cr112);
    all_unique_corners.push_back(cr113); 
    all_unique_corners.push_back(cr114); 
    all_unique_corners.push_back(cr115); 
    all_unique_corners.push_back(cr116); 
    all_unique_corners.push_back(cr117); 
    all_unique_corners.push_back(cr118); 
    all_unique_corners.push_back(cr119);
    all_unique_corners.push_back(cr120); 
    all_unique_corners.push_back(cr121); 
    all_unique_corners.push_back(cr122); 
    
    
    //reflected column tops
    corner cr107t, cr108t, cr109t, cr110t, cr111t, cr112t, cr113t, cr114t, cr115t, cr116t, cr117t, cr118t, cr119t, cr120t, cr121t, cr122t;
    
    temp2=mult(c107t,temp1);   cr107t=add(temp,temp2); int cr107t_=121;
    temp2=mult(c108t,temp1);   cr108t=add(temp,temp2); int cr108t_=122;
    temp2=mult(c109t,temp1);   cr109t=add(temp,temp2); int cr109t_=123;
    temp2=mult(c110t,temp1);   cr110t=add(temp,temp2); int cr110t_=124;
    temp2=mult(c111t,temp1);   cr111t=add(temp,temp2); int cr111t_=125;
    temp2=mult(c112t,temp1);   cr112t=add(temp,temp2); int cr112t_=126;
    temp2=mult(c113t,temp1);   cr113t=add(temp,temp2); int cr113t_=127;
    temp2=mult(c114t,temp1);   cr114t=add(temp,temp2); int cr114t_=128;
    temp2=mult(c115t,temp1);   cr115t=add(temp,temp2); int cr115t_=129;
    temp2=mult(c116t,temp1);   cr116t=add(temp,temp2); int cr116t_=130;
    temp2=mult(c117t,temp1);   cr117t=add(temp,temp2); int cr117t_=131;
    temp2=mult(c118t,temp1);   cr118t=add(temp,temp2); int cr118t_=132;
    temp2=mult(c119t,temp1);   cr119t=add(temp,temp2); int cr119t_=133;
    temp2=mult(c120t,temp1);   cr120t=add(temp,temp2); int cr120t_=134;
    temp2=mult(c121t,temp1);   cr121t=add(temp,temp2); int cr121t_=135;
    temp2=mult(c122t,temp1);   cr122t=add(temp,temp2); int cr122t_=136;
    
    all_unique_corners.push_back(cr107t); 
    all_unique_corners.push_back(cr108t); 
    all_unique_corners.push_back(cr109t); 
    all_unique_corners.push_back(cr110t); 
    all_unique_corners.push_back(cr111t); 
    all_unique_corners.push_back(cr112t);
    all_unique_corners.push_back(cr113t); 
    all_unique_corners.push_back(cr114t); 
    all_unique_corners.push_back(cr115t); 
    all_unique_corners.push_back(cr116t); 
    all_unique_corners.push_back(cr117t); 
    all_unique_corners.push_back(cr118t); 
    all_unique_corners.push_back(cr119t);
    all_unique_corners.push_back(cr120t); 
    all_unique_corners.push_back(cr121t); 
    all_unique_corners.push_back(cr122t); 
    
    all_unique_corners.push_back(c102); int c102_=137; //this was missing above. 

    
    //pitched roof
    double a,b,c,d,e,f,g,h,i,j,k,l,m,n,o, p;
    a=0.29711204;
    b=0.59422408;
    c=0.59422408;
    d=0.29711204;
    e=2.228340301;
    h=1.2192;
    i=0.29711204;
    j=i*2;
    k=b;
    l=i;
    m=b;
    n=9.32931806;
    p=l;
    double ubheight=.1237;
    double ubheight2=.2476;
    double ublength=.29;
    double ublength2=.29*2;
    double ebheight= 0.0655;
    double eblength= 0.0273;
    
    //Pitched Roof Corners 
    corner c200u, c201u, c202u,c203u,  c204u,c205u, c208u, c209u, c210u, c211u, c212u, c213u, c214u, c218u, c219u,c220u, c221u, c222u, c223u, c224u, c225u;
    corner c200b, c201b, c202b,c203b,  c204b,c205b,c206b, c207b, c208b, c209b, c210b, c211b, c212b, c213b, c214b, c218b, c219b, c220b, c221b, c222b, c223b, c224b, c225b;
    corner c200e, c201e, c202e,c203e,  c204e,c205e,c206e, c207e, c208e, c209e, c210e, c211e, c212e, c213e, c214e, c218e, c219e, c220e, c221e, c222e, c223e, c224e, c225e, c226t;
    corner c210t, c215t, c216t, c217t, c224t, c225t;
    
    //under
    c200u.assign(all_unique_corners[15].x, all_unique_corners[15].y, height );
    c201u.assign(all_unique_corners[16].x, all_unique_corners[16].y, height);
    c202u.assign(all_unique_corners[17].x, all_unique_corners[17].y, height);
    c203u.assign(all_unique_corners[24].x, all_unique_corners[17].y, height);
    c204u.assign(all_unique_corners[24].x, all_unique_corners[17].y, height);
    //c205u.assign(c200u.x, c202u.y-4.8768, height+2.032);
    c205u.assign(c200u.x, 44.41*.3048, height+2.032);
    
    //c206u.assign();
    //c207u.assign();
    c208u.assign(all_unique_corners[14].x,all_unique_corners[24].y, height);
    c209u.assign(all_unique_corners[14].x,all_unique_corners[14].y, height);
//    c210u.assign(all_unique_corners[0].x/2,all_unique_corners[0].y, height+(.4166)*((all_unique_corners[0].x/2)-c209u.x));
    double tempx=(all_unique_corners[13].x)/2.0;
    double tempheight=(.4166)*tempx;
    c210u.assign(tempx,all_unique_corners[0].y, height+tempheight);
    
    c211u.assign(all_unique_corners[13].x,all_unique_corners[13].y, height);
    c212u.assign(all_unique_corners[12].x,all_unique_corners[12].y, height);
    c213u.assign(all_unique_corners[11].x,all_unique_corners[11].y, height);
    c214u.assign(all_unique_corners[24].x,all_unique_corners[24].y, height);
//    c215u.assign();
//    c216u.assign();
//    c217u.assign();
    c218u.assign(all_unique_corners[46].x,all_unique_corners[46].y, height);
    c219u.assign(all_unique_corners[18].x,all_unique_corners[18].y, height);
    c222u.assign(all_unique_corners[47].x,all_unique_corners[47].y, height);
    c223u.assign(all_unique_corners[19].x,all_unique_corners[19].y, height);
    
    c220u.assign(c218u.x, c205u.y+(1.65100/2), c205u.z-(.4166)*(1.65100/2) );
    c221u.assign(c219u.x, c205u.y+(1.65100/2), c205u.z-(.4166)*(1.65100/2) );

    c226t.assign(c219u.x, c205u.y+(1.65100/2), c205u.z-(.4166)*(1.65100/2) );
    
    //bottom

    
    c200b.assign(c200u.x-l, c200u.y+k, height-ubheight2);
    c201b.assign(c201u.x-l, c201u.y+k, height-ubheight2);
    c202b.assign(c202u.x, c202u.y+j, height-ubheight2-(.4166)*(c202u.y-c201u.y));
    c203b.assign(c203u.x, c202u.y+j, height-ubheight2-(.4166)*(c202u.y-c201u.y));
    c204b.assign(c203u.x, c202u.y+i, height-ubheight2-(.4166)*(c202u.y-c201u.y));
    c205b.assign(c205u.x-l, c205u.y, c200b.z+ubheight2+(.4166)*(c200b.y+eblength - c205u.y));
    c206b.assign(c205u.x-l, c208u.y, c205u.z - (.4166)*(c205u.y-c208u.y));
    c207b.assign(c205u.x-l, c208u.y-p,c206b.z-(.4166)*p );
    c208b.assign(c205u.x-m, c208u.y, height-ubheight2);
    c209b.assign(c208b.x, c209u.y-a, height-ubheight2);
    c210b.assign(c210u.x, c210u.y-a, c210u.z);
    c211b.assign(c211u.x+b, c211u.y-a, height-ubheight2);
    c212b.assign(c212u.x+b, c212u.y-c, height-ubheight2);
    c213b.assign(c213u.x+ublength2, c213u.y-c, height-ubheight2);
    c214b.assign(c214u.x+ublength2, c214u.y-c, height-ubheight2);
    //c215b.assign();
    //c216b.assign(); 
    //c217b.assign();
    c218b.assign(c218u.x+l, c218u.y+i, c218u.z-ubheight2);
    c219b.assign(c218b.x, c219u.y+i, c219u.z-ubheight2);
    c220b.assign(c218b.x, c205u.y-(1.65100/2),  c205b.z-(.4166)*(1.65100/2));
    c222b.assign(c222u.x, c214b.y, c222u.z-ubheight2);
    c223b.assign(all_unique_corners[19].x-l, all_unique_corners[19].y-d, c214b.z);
    c221b.assign(c223b.x, c220b.y, c220b.z);

    
    //edge
    c200e.assign(c200b.x, c200b.y+eblength, c200b.z+ebheight);
    c201e.assign(c201b.x, c201b.y+eblength, c201b.z+ebheight);
    c202e.assign(c201e.x, c202b.y+eblength, c202b.z+ebheight);
    c203e.assign(c203b.x, c203b.y+eblength, c203b.z+ebheight);
    c204e.assign(c204b.x, c204b.y+eblength, c204b.z+ebheight);
    c205e.assign(c205b.x-eblength, c205b.y, c205b.z+ebheight);
    c206e.assign(c206b.x-eblength, c206b.y, c206b.z+ebheight);
    c207e.assign(c207b.x-eblength, c207b.y, c207b.z+ebheight);
    c208e.assign(c208b.x-eblength, c208b.y, c208b.z + ebheight);
    c209e.assign(c209b.x-eblength, c209b.y, c209b.z + ebheight);
    c210e.assign(c210b.x, c210b.y, c210b.z + ebheight);
    c211e.assign(c211b.x+eblength, c211b.y, + c210b.z +ebheight);
    c212e.assign(c212b.x+eblength, c212b.y-eblength, + c212b.z +ebheight);
    c213e.assign(c213b.x+eblength, c213b.y-eblength, + c213b.z +ebheight);
    c214e.assign(c214b.x+eblength, c214b.y-eblength, + c214b.z +ebheight);
    //c215e.assign();
    //c216e.assign();
    //c217e.assign();
    c218e.assign(c218b.x, c218b.y +eblength, c218b.z+ebheight);
    c219e.assign(c219b.x, c219b.y, c219b.z+ebheight);
    c220e.assign(c220b.x+eblength, c220b.y, c220b.z+ebheight);
    c221e.assign(c221b.x-eblength, c221b.y, c221b.z+ebheight);
    c222e.assign(c218e.x, c214e.y, c214e.z);
    c223e.assign(c221b.x, c222e.y-(c218e.y-c219e.y), c222e.z);
    
    //top
//    c200t.assign();
//    c201t.assign();
//    c202t.assign();
//    c203t.assign();
//    c204t.assign();
//    c205t.assign();
//    c206t.assign();
//    c207t.assign();
//    c208t.assign();
//    c209t.assign();
    c210t.assign(c210e.x, c210e.y, c209e.z+ (.4166)*(c210t.x-c209e.x));
//    c211t.assign();
//    c212t.assign();
//    c213t.assign();
//    c214t.assign();
    c215t.assign(c210t.x, c212e.y+(c212e.x-c210e.x), c210e.z);
    double temp_difference=(c213e.x-c212e.x)/2.0;
    c216t.assign(c215t.x+temp_difference, c215t.y+temp_difference,c208e.z+(.4166)*(c216t.z-c208e.x));
    c217t.assign(c216t.x, c216t.y+(c214b.y-c213b.y), c216t.z);
   // c218t.assign(c218e.x, c218);
   // c219t.assign();
    c224t.assign(c218e.x, c205e.y, c205e.z);
    c225t.assign(c224t.x, c224t.y-1.65100, c224t.z);
    c225u.assign(c218u.x, c225t.y, c225t.z-ebheight );
    c225b.assign(c218b.x, c225t.y, c225t.z-ebheight );
    //c222t.assign();
    //c223t.assign();
  
    
    //pragmatic solutions elevations...
    
    c200e.assign(c200e.x, c200e.y, c205e.z-(5.0/12.0)*(c200e.y-c205e.y));
    c201e.assign(c201e.x, c201e.y, c205e.z-(5.0/12.0)*(c201e.y-c205e.y));
    c202e.assign(c202e.x, c202e.y, c205e.z-(5.0/12.0)*(c202e.y-c205e.y));
    c203e.assign(c203e.x, c203e.y, c205e.z-(5.0/12.0)*(c203e.y-c205e.y));
    c204e.assign(c204e.x, c204e.y, c205e.z-(5.0/12.0)*(c204e.y-c205e.y));
    c219e.assign(c219e.x, c219e.y, c205e.z-(5.0/12.0)*(c219e.y-c205e.y));

    c215t.assign(c215t.x, c215t.y, c210e.z);
    c217t.assign(c217t.x, c217t.y, c210e.z+(5.0/12.0)*(c216t.x-c215t.x));
    c216t.assign(c216t.x, c216t.y, c217t.z);
    c209e.assign(c209e.x, c209e.y, c210e.z-(5.0/12.0)*(c210e.x-c209e.x));
   // c217t.assign(c217t.x, c217t.y, c205e.z-(5.0/12.0)*(c205e.y-c217t.y));
    c214e.assign(c214e.x, c214e.y, c217t.z-(5.0/12.0)*(c214e.x-c217t.x));
    c222e.assign(c222e.x, c222e.y, c205e.z-(5.0/12.0)*(c205e.y-c222e.y));
    
    c211e.assign(c211e.x, c211e.y,c209e.z);
    c212e.assign(c212e.x, c212e.y,c209e.z);
    c213e.assign(c213e.x, c213e.y,c209e.z);
    c214e.assign(c214e.x, c214e.y,c209e.z);
    c222e.assign(c222e.x, c222e.y,c209e.z);

    
    c210t.assign(c210t.x,  c210t.y, c210e.z+ebheight);
    c215t.assign(c215t.x,  c215t.y, c210t.z);
    c216t.assign(c216t.x,  c216t.y, c215t.z+(5.0/12.0)*(c216t.x-c215t.x));
    c217t.assign(c217t.x, c217t.y, c216t.z);
    c219e.assign(c219e.x, c219e.y, c204e.z);
    
    
    c205e.assign(c205e.x, c205e.y, c217t.z + (5.0/12.0)*(c205e.y-c217t.y) );
    c205u.assign(c205u.x, c205u.y, c205e.z-ebheight);
    c224t.assign(c224t.x, c205u.y, c205e.z );
    c224u.assign(c219u.x, c205u.y, c224t.z-ebheight );
    c224b.assign(c219b.x, c205u.y, c224t.z-ebheight );
    
    c200e.assign(c200e.x, c200e.y, c205e.z-(5.0/12.0)*(c200e.y-c205e.y));
    c201e.assign(c201e.x, c201e.y, c205e.z-(5.0/12.0)*(c201e.y-c205e.y));
    c202e.assign(c202e.x, c202e.y, c205e.z-(5.0/12.0)*(c202e.y-c205e.y));
    c203e.assign(c203e.x, c203e.y, c205e.z-(5.0/12.0)*(c203e.y-c205e.y));
    c204e.assign(c204e.x, c204e.y, c205e.z-(5.0/12.0)*(c204e.y-c205e.y));
    c219e.assign(c219e.x, c219e.y, c205e.z-(5.0/12.0)*(c219e.y-c205e.y));
    c206e.assign(c206e.x, c206e.y, c205e.z-(5.0/12.0)*(c205e.y-c206e.y));
    c207e.assign(c206e.x, c206e.y, c205e.z-(5.0/12.0)*(c205e.y-c207e.y));
    
    //under
    c200u.assign(all_unique_corners[15].x, all_unique_corners[15].y, c205u.z+(5.0/12.0)*(c205u.y-c200u.y));
    c201u.assign(all_unique_corners[16].x, all_unique_corners[16].y, c200u.z);
    c202u.assign(all_unique_corners[17].x, all_unique_corners[17].y, c200u.z-(5.0/12.0)*(c202u.y-c200u.y));
    c203u.assign(all_unique_corners[24].x, all_unique_corners[17].y, c200u.z-(5.0/12.0)*(c202u.y-c200u.y));
    c204u.assign(all_unique_corners[24].x, all_unique_corners[17].y, c200u.z-(5.0/12.0)*(c202u.y-c200u.y));
    c219u.assign(c219u.x, c219u.y, c202u.z);
    c218u.assign(c218u.x, c218u.y, c202u.z);
    c219b.assign(c219u.x, c204u.y, c204u.z);
    c218b.assign(c218u.x, c204u.y, c204u.z);
    
    c205b.assign(c205e.x, c205e.y, c205e.z-ebheight);
    c210b.assign(c210e.x, c210e.y, c210e.z-ebheight);
    
    //c208b.assign(c208e.x+eblength, c208e.y, c209b.z);
    c208u.assign(c209u.x, c208b.y, c209u.z);
    c207b.assign(c207e.x, c208e.y+eblength, c208e.z+(5.0/12.0)*(c207e.y-c208e.y));
    c205u.assign(c209u.x, c205e.y, c205b.z);
    
    //fixing eaves
    corner c207u;
    c207b.assign(c207e.x, c207e.y, c207e.z-ebheight);
    c207u.assign(c209u.x, c207e.y, c207b.z);
    c205b.assign(c205e.x, c205e.y, c205e.z-ebheight);
    c205u.assign(c209u.x, c205e.y, c205b.z);

    c200u.assign(c209u.x, c200u.y, c205u.z-(5.0/12.0)*(c200u.y-c205u.y));    
   // c200b.assign(c200b.x, c200b.y, c205b.z-(5.0/12.0)*(c200u.y-c205u.y));


    
    all_unique_corners.push_back(c200u); int c200_=138; //this is just so i dont have to fix the numbering... its a dummy
    
    all_unique_corners.push_back(c200u); int c200u_=139;
    all_unique_corners.push_back(c201u); int c201u_=140;
    all_unique_corners.push_back(c202u); int c202u_=141;
    all_unique_corners.push_back(c203u); int c203u_=142;
    all_unique_corners.push_back(c204u); int c204u_=143;
    all_unique_corners.push_back(c205u); int c205u_=144;
  //  all_unique_corners.push_back(c206u); int c206u_=145;
  //  all_unique_corners.push_back(c207u); int c207u_=146;
    all_unique_corners.push_back(c208u); int c208u_=145;
    all_unique_corners.push_back(c209u); int c209u_=146;
    all_unique_corners.push_back(c210u); int c210u_=147;
    all_unique_corners.push_back(c211u); int c211u_=148;
    all_unique_corners.push_back(c212u); int c212u_=149;
    all_unique_corners.push_back(c213u); int c213u_=150;
    all_unique_corners.push_back(c214u); int c214u_=151;
  //  all_unique_corners.push_back(c215u); int c215u_=54;
  //  all_unique_corners.push_back(c216u); int c216u_=155;
  //  all_unique_corners.push_back(c217u); int c217u_=156;
    all_unique_corners.push_back(c218u); int c218u_=152;
    all_unique_corners.push_back(c219u); int c219u_=153;
    all_unique_corners.push_back(c222u); int c222u_=154; 
    all_unique_corners.push_back(c223u); int c223u_=155;
    
    
    all_unique_corners.push_back(c200b); int c200b_=156;
    all_unique_corners.push_back(c201b); int c201b_=157;
    all_unique_corners.push_back(c202b); int c202b_=158;
    all_unique_corners.push_back(c203b); int c203b_=159;
    all_unique_corners.push_back(c204b); int c204b_=160;
    all_unique_corners.push_back(c205b); int c205b_=161;
    all_unique_corners.push_back(c206b); int c206b_=162;
    all_unique_corners.push_back(c207b); int c207b_=163;
    all_unique_corners.push_back(c208b); int c208b_=164;
    all_unique_corners.push_back(c209b); int c209b_=165;
    all_unique_corners.push_back(c210b); int c210b_=166;
    all_unique_corners.push_back(c211b); int c211b_=167;
    all_unique_corners.push_back(c212b); int c212b_=168;
    all_unique_corners.push_back(c213b); int c213b_=169;
    all_unique_corners.push_back(c214b); int c214b_=170;
//    all_unique_corners.push_back(c215b); int c215b_=177;
//    all_unique_corners.push_back(c216b); int c216b_=178;
//    all_unique_corners.push_back(c217b); int c217b_=179;
    all_unique_corners.push_back(c218b); int c218b_=171;
    all_unique_corners.push_back(c219b); int c219b_=172;
    all_unique_corners.push_back(c220b); int c220b_=173;
    all_unique_corners.push_back(c221b); int c221b_=174;
    all_unique_corners.push_back(c222b); int c222b_=175;
    all_unique_corners.push_back(c223b); int c223b_=176;
    
    all_unique_corners.push_back(c201e); int c201e_=177;
    all_unique_corners.push_back(c202e); int c202e_=178;
    all_unique_corners.push_back(c203e); int c203e_=179;
    all_unique_corners.push_back(c204e); int c204e_=180;
    all_unique_corners.push_back(c205e); int c205e_=181;
    all_unique_corners.push_back(c206e); int c206e_=182;
    all_unique_corners.push_back(c207e); int c207e_=183;
    all_unique_corners.push_back(c208e); int c208e_=184;
    all_unique_corners.push_back(c209e); int c209e_=185;
    all_unique_corners.push_back(c210e); int c210e_=186;
    all_unique_corners.push_back(c211e); int c211e_=187;
    all_unique_corners.push_back(c212e); int c212e_=188;
    all_unique_corners.push_back(c213e); int c213e_=189;
    all_unique_corners.push_back(c214e); int c214e_=190;
//    all_unique_corners.push_back(c215e); int c215e_=200;
//    all_unique_corners.push_back(c216e); int c216e_=201;
//    all_unique_corners.push_back(c217e); int c217e_=202;
    all_unique_corners.push_back(c218e); int c218e_=191;
    all_unique_corners.push_back(c219e); int c219e_=192;
//    all_unique_corners.push_back(c220e); int c220e_=205;
//    all_unique_corners.push_back(c221e); int c221e_=206;
    all_unique_corners.push_back(c222e); int c222e_=193;
    all_unique_corners.push_back(c223e); int c223e_=194;
    
//    all_unique_corners.push_back(c200t); int c200t_=208;
//    all_unique_corners.push_back(c201t); int c201t_=209;
//    all_unique_corners.push_back(c202t); int c202t_=210;
//    all_unique_corners.push_back(c203t); int c203t_=211;
//    all_unique_corners.push_back(c204t); int c204t_=212;
//    all_unique_corners.push_back(c205t); int c205t_=213;
//    all_unique_corners.push_back(c206t); int c206t_=214;
//    all_unique_corners.push_back(c207t); int c207t_=215;
//    all_unique_corners.push_back(c208t); int c208t_=216;
//    all_unique_corners.push_back(c209t); int c209t_=217;
    all_unique_corners.push_back(c210t); int c210t_=195;
//    all_unique_corners.push_back(c211t); int c211t_=219;
//    all_unique_corners.push_back(c212t); int c212t_=220;
//    all_unique_corners.push_back(c213t); int c213t_=221;
//    all_unique_corners.push_back(c214t); int c214t_=195;
    all_unique_corners.push_back(c215t); int c215t_=196;
    all_unique_corners.push_back(c216t); int c216t_=197;
    all_unique_corners.push_back(c217t); int c217t_=198;
//    all_unique_corners.push_back(c218t); int c218t_=226;
//    all_unique_corners.push_back(c219t); int c219t_=227;
//    all_unique_corners.push_back(c220t); int c220t_=228;
//    all_unique_corners.push_back(c221t); int c221t_=229;
//    all_unique_corners.push_back(c222t); int c222t_=230;
    all_unique_corners.push_back(c224t); int c224t_=199;
    all_unique_corners.push_back(c225t); int c225t_=200;
    
    all_unique_corners.push_back(c200e); int c200e_=201;
    

    //Reflected Pitched Roof Corners
    corner cr200u, cr201u, cr202u,cr203u,  cr204u,cr205u, cr207u, cr208u, cr209u, cr210u, cr211u, cr212u, cr213u, cr214u, cr218u, cr219u, cr222u, cr223u;
    corner cr200b, cr201b, cr202b,cr203b,  cr204b,cr205b,cr206b, cr207b, cr208b, cr209b, cr210b, cr211b, cr212b, cr213b, cr214b, cr218b, cr219b, cr220b, cr221b, cr222b, cr223b;
    corner cr200e, cr201e, cr202e,cr203e,  cr204e,cr205e,cr206e, cr207e, cr208e, cr209e, cr210e, cr211e, cr212e, cr213e, cr214e, cr218e, cr219e, cr222e, cr223e;
    corner cr210t, cr215t, cr216t, cr217t, cr224t, cr225t;
    
    temp.assign(2*43*mPERft+2*3.5*mPERin,5.5*mPERft,0);
    temp1.assign(-1,1,1);
    
    temp2=mult(c200u,temp1);   cr200u=add(temp,temp2);
    temp2=mult(c201u,temp1);   cr201u=add(temp,temp2);
    temp2=mult(c202u,temp1);   cr202u=add(temp,temp2);
    temp2=mult(c203u,temp1);   cr203u=add(temp,temp2);
    temp2=mult(c204u,temp1);   cr204u=add(temp,temp2);
    temp2=mult(c205u,temp1);   cr205u=add(temp,temp2);
    //temp2=mult(c206u,temp1);   cr206u=add(temp,temp2);
    //temp2=mult(c207u,temp1);   cr207u=add(temp,temp2);
    temp2=mult(c208u,temp1);   cr208u=add(temp,temp2);
    temp2=mult(c209u,temp1);   cr209u=add(temp,temp2);
    temp2=mult(c210u,temp1);   cr210u=add(temp,temp2);
    temp2=mult(c211u,temp1);   cr211u=add(temp,temp2);
    temp2=mult(c212u,temp1);   cr212u=add(temp,temp2);
    temp2=mult(c213u,temp1);   cr213u=add(temp,temp2);
    temp2=mult(c214u,temp1);   cr214u=add(temp,temp2);
//    temp2=mult(c215u,temp1);   cr215u=add(temp,temp2);
//    temp2=mult(c216u,temp1);   cr216u=add(temp,temp2);
//    temp2=mult(c217u,temp1);   cr217u=add(temp,temp2);
    temp2=mult(c218u,temp1);   cr218u=add(temp,temp2);
    temp2=mult(c219u,temp1);   cr219u=add(temp,temp2);
//    temp2=mult(c220u,temp1);   cr220u=add(temp,temp2);
//    temp2=mult(c221u,temp1);   cr221u=add(temp,temp2);
    temp2=mult(c222u,temp1);   cr222u=add(temp,temp2);
    temp2=mult(c223u,temp1);   cr223u=add(temp,temp2);
//    temp2=mult(c224u,temp1);   cr224u=add(temp,temp2);
 //   temp2=mult(c225u,temp1);   cr225u=add(temp,temp2);
    
    temp2=mult(c200b,temp1);   cr200b=add(temp,temp2);
    temp2=mult(c201b,temp1);   cr201b=add(temp,temp2);
    temp2=mult(c202b,temp1);   cr202b=add(temp,temp2);
    temp2=mult(c203b,temp1);   cr203b=add(temp,temp2);
    temp2=mult(c204b,temp1);   cr204b=add(temp,temp2);
    temp2=mult(c205b,temp1);   cr205b=add(temp,temp2);
    temp2=mult(c206b,temp1);   cr206b=add(temp,temp2);
    temp2=mult(c207b,temp1);   cr207b=add(temp,temp2);
    temp2=mult(c208b,temp1);   cr208b=add(temp,temp2);
    temp2=mult(c209b,temp1);   cr209b=add(temp,temp2);
    temp2=mult(c210b,temp1);   cr210b=add(temp,temp2);
    temp2=mult(c211b,temp1);   cr211b=add(temp,temp2);
    temp2=mult(c212b,temp1);   cr212b=add(temp,temp2);
    temp2=mult(c213b,temp1);   cr213b=add(temp,temp2);
    temp2=mult(c214b,temp1);   cr214b=add(temp,temp2);
//    temp2=mult(c215b,temp1);   cr215b=add(temp,temp2);
//    temp2=mult(c216b,temp1);   cr216b=add(temp,temp2);
//    temp2=mult(c217b,temp1);   cr217b=add(temp,temp2);
    temp2=mult(c218b,temp1);   cr218b=add(temp,temp2);
    temp2=mult(c219b,temp1);   cr219b=add(temp,temp2);
    temp2=mult(c220b,temp1);   cr220b=add(temp,temp2);
    temp2=mult(c221b,temp1);   cr221b=add(temp,temp2);
    temp2=mult(c222b,temp1);   cr222b=add(temp,temp2);
    temp2=mult(c223b,temp1);   cr223b=add(temp,temp2);
//    temp2=mult(c224b,temp1);   cr224b=add(temp,temp2);
//    temp2=mult(c225b,temp1);   cr225b=add(temp,temp2);


    temp2=mult(c200e,temp1);   cr200e=add(temp,temp2);
    temp2=mult(c201e,temp1);   cr201e=add(temp,temp2);
    temp2=mult(c202e,temp1);   cr202e=add(temp,temp2);
    temp2=mult(c203e,temp1);   cr203e=add(temp,temp2);
    temp2=mult(c204e,temp1);   cr204e=add(temp,temp2);
    temp2=mult(c205e,temp1);   cr205e=add(temp,temp2);
    temp2=mult(c206e,temp1);   cr206e=add(temp,temp2);
    temp2=mult(c207e,temp1);   cr207e=add(temp,temp2);
    temp2=mult(c208e,temp1);   cr208e=add(temp,temp2);
    temp2=mult(c209e,temp1);   cr209e=add(temp,temp2);
    temp2=mult(c210e,temp1);   cr210e=add(temp,temp2);
    temp2=mult(c211e,temp1);   cr211e=add(temp,temp2);
    temp2=mult(c212e,temp1);   cr212e=add(temp,temp2);
    temp2=mult(c213e,temp1);   cr213e=add(temp,temp2);
    temp2=mult(c214e,temp1);   cr214e=add(temp,temp2);
//    temp2=mult(c215e,temp1);   cr215e=add(temp,temp2);
//    temp2=mult(c216e,temp1);   cr216e=add(temp,temp2);
//    temp2=mult(c217e,temp1);   cr217e=add(temp,temp2);
    temp2=mult(c218e,temp1);   cr218e=add(temp,temp2);
    temp2=mult(c219e,temp1);   cr219e=add(temp,temp2);
//    temp2=mult(c220e,temp1);   cr220e=add(temp,temp2);
//    temp2=mult(c221e,temp1);   cr221e=add(temp,temp2);
    temp2=mult(c222e,temp1);   cr222e=add(temp,temp2);
    temp2=mult(c223e,temp1);   cr223e=add(temp,temp2);
//    temp2=mult(c224e,temp1);   cr224e=add(temp,temp2);
//    temp2=mult(c225e,temp1);   cr225e=add(temp,temp2);
    
    
    
//    temp2=mult(c200t,temp1);   cr200t=add(temp,temp2);
//    temp2=mult(c201t,temp1);   cr201t=add(temp,temp2);
//    temp2=mult(c202t,temp1);   cr202t=add(temp,temp2);
//    temp2=mult(c203t,temp1);   cr203t=add(temp,temp2);
//    temp2=mult(c204t,temp1);   cr204t=add(temp,temp2);
//    temp2=mult(c205t,temp1);   cr205t=add(temp,temp2);
//    temp2=mult(c206t,temp1);   cr206t=add(temp,temp2);
//    temp2=mult(c207t,temp1);   cr207t=add(temp,temp2);
//    temp2=mult(c208t,temp1);   cr208t=add(temp,temp2);
//    temp2=mult(c209t,temp1);   cr209t=add(temp,temp2);
    temp2=mult(c210t,temp1);   cr210t=add(temp,temp2);
//    temp2=mult(c211t,temp1);   cr211t=add(temp,temp2);
//    temp2=mult(c212t,temp1);   cr212t=add(temp,temp2);
//    temp2=mult(c213t,temp1);   cr213t=add(temp,temp2);
//    temp2=mult(c214t,temp1);   cr214t=add(temp,temp2);
    temp2=mult(c215t,temp1);   cr215t=add(temp,temp2);
    temp2=mult(c216t,temp1);   cr216t=add(temp,temp2);
    temp2=mult(c217t,temp1);   cr217t=add(temp,temp2);
//    temp2=mult(c218t,temp1);   cr218t=add(temp,temp2);
//    temp2=mult(c219t,temp1);   cr219t=add(temp,temp2);
//    temp2=mult(c220t,temp1);   cr220t=add(temp,temp2);
//    temp2=mult(c221t,temp1);   cr221t=add(temp,temp2);
//    temp2=mult(c222t,temp1);   cr222t=add(temp,temp2);
//    temp2=mult(c223t,temp1);   cr223t=add(temp,temp2);
    temp2=mult(c224t,temp1);   cr224t=add(temp,temp2);
    temp2=mult(c225t,temp1);   cr225t=add(temp,temp2);

//    c200b.assign(c200u.x-l, c200u.y+k, height-ubheight2);
//    c201b.assign(c201u.x-l, c201u.y+k, height-ubheight2);
//    c202b.assign(c202u.x, c202u.y+j, height-ubheight2-(.4166)*(c202u.y-c201u.y));
//    c203b.assign(c203u.x, c202u.y+j, height-ubheight2-(.4166)*(c202u.y-c201u.y));
//    c204b.assign(c203u.x, c202u.y+i, height-ubheight2-(.4166)*(c202u.y-c201u.y));
//    c205b.assign(c205u.x-l, c205u.y, c200b.z+ubheight2+(.4166)*(c200b.y+eblength - c205u.y));
//    c206b.assign(c205u.x-l, c208u.y, c205u.z - (.4166)*(c205u.y-c208u.y));
//    c207b.assign(c205u.x-l, c208u.y-p,c206b.z-(.4166)*p );
//    c208b.assign(c205u.x-m, c205u.y, height+ubheight2);
//    c209b.assign(c208b.x, c209u.y-a, height+ubheight2);
//    c210b.assign(c210u.z, c210u.y-a, c210u.z);
//    c211b.assign(c211u.x+b, c211u.y-a, c211u.z-ubheight2);
//    c212b.assign(c212u.x+b, c212u.y-c, c212u.z-ubheight2);
//    c213b.assign(c213u.x+d, c213u.y-c, c213u.z-ubheight2);
//    c214b.assign(c214u.x+d, c214u.y-c, c214u.z-ubheight2);
//    //c215b.assign();
//    //c216b.assign(); 
//    //c217b.assign();
//    c218b.assign(c218u.x+l, c218u.y+i, c218u.z-ubheight2);
//    c219b.assign(c218b.x, c219u.y+i, c219u.z-ubheight2);
//    c220b.assign(c218b.x, c205u.y-(1.65100/2.0),  c205b.z-(.4166)*(1.65100/2.0));
//    c222b.assign(c222u.x, c214b.y, c222u.z-ubheight2);
//    c223b.assign(all_unique_corners[19].x-l, all_unique_corners[19].y-d, c214b.z);
//    c221b.assign(c223b.x, c220b.y, c220b.z);
//    
//    
//    //edge
//    c200e.assign(c200b.x, c200b.y+eblength, c200b.z+ebheight);
//    c201e.assign(c201b.x, c201b.y+eblength, c201b.z+ebheight);
//    c202e.assign(c202b.x, c202b.y+eblength, c202b.z+ebheight);
//    c203e.assign(c203b.x, c203b.y+eblength, c203b.z+ebheight);
//    c204e.assign(c204b.x, c204b.y+eblength, c204b.z+ebheight);
//    c205e.assign(c205b.x, c205b.y, c205b.z+ebheight);
//    c206e.assign(c206b.x, c206b.y, c206b.z+ebheight);
//    c207e.assign(c207b.x, c207b.y, c207b.z+ebheight);
//    c208e.assign(c208b.x-eblength, c208b.y, c208b.z + ebheight);
//    c209e.assign(c209b.x-eblength, c209b.y, c209b.z + ebheight);
//    c210e.assign(c210b.x, c210b.y, c210b.z + ebheight);
//    c211e.assign(c211b.x+eblength, c211b.y, + c210b.z +ebheight);
//    c212e.assign(c212b.x+eblength, c212b.y-eblength, + c212b.z +ebheight);
//    c213e.assign(c213b.x+eblength, c213b.y-eblength, + c213b.z +ebheight);
//    c214e.assign(c214b.x+eblength, c214b.y-eblength, + c214b.z +ebheight);
//    //c215e.assign();
//    //c216e.assign();
//    //c217e.assign();
//    c218e.assign(c218b.x, c218b.y +eblength, c218b.z+ebheight);
//    c219e.assign(c219b.x, c219b.y, c219b.z+ebheight);
//    //c220e.assign(c220b.x);
//    //c221e.assign();
//    c222e.assign(c218e.x, c214e.y, c214e.z);
//    c223e.assign(c221b.x, c222e.y-(c218e.y-c219e.y), c222e.z);
//    
//    //top
//    //    c200t.assign();
//    //    c201t.assign();
//    //    c202t.assign();
//    //    c203t.assign();
//    //    c204t.assign();
//    //    c205t.assign();
//    //    c206t.assign();
//    //    c207t.assign();
//    //    c208t.assign();
//    //    c209t.assign();
//    c210t.assign(c210e.x, c210e.y, c209e.z+ (.4166)*(c210t.x-c209e.x));
//    //    c211t.assign();
//    //    c212t.assign();
//    //    c213t.assign();
//    //    c214t.assign();
//    c215t.assign(c210t.x, c212e.y+(c212e.x-c210e.x), c210e.z);
//   // double temp_difference=(c213e.x-c212e.x)/2;
//    c216t.assign(c215t.x+temp_difference, c215t.y+temp_difference,c208e.z+(.4166)*(c216t.z-c208e.x));
//    c217t.assign(c216t.x, c216t.y+(c214b.y-c214b.y), c216t.z);
//    // c218t.assign(c218e.x, c218);
//    // c219t.assign();
//    c224t.assign(c218e.x, c205e.y, c205e.z);
//    c225t.assign(c224t.x, c224t.y-1.65100, c224t.z);
//    //c222t.assign();
//    //c223t.assign();
    cr219e.assign(cr219e.x, cr219e.y, c202u.z);    
    cr219u.assign(cr219u.x, cr219u.y, c202u.z);
    cr218e.assign(cr218e.x, cr218e.y, cr202u.z);    
    cr218u.assign(cr218u.x, cr218u.y, cr202u.z);    
    
    //Pragmatic Reflected
//    cr206e.assign(cr206e.x, cr206e.y, c206e.z); 
//    cr207e.assign(cr207e.x, cr207e.y, c207e.z);    
//    cr208e.assign(cr208e.x, cr208e.y, c208e.z); 
//    cr208u.assign(cr208u.x, cr208u.y, c208u.z); 
//    
//    cr209e.assign(cr209e.x, cr209e.y, c209e.z);  
//    cr209u.assign(cr209u.x, cr209u.y, c209u.z); 
//  
//    cr217t.assign(cr217t.x, cr217t.y, c217t.z);
//    cr216t.assign(cr216t.x, cr216t.y, c216t.z);
//    cr215t.assign(cr215t.x, cr215t.y, c215t.z);
//    cr210e.assign(cr210e.x, cr210e.y, c210e.z);

    c226t.assign(cr219u.x, c205u.y+(1.65100/2), c205u.z-(.4166)*(1.65100/2) );
    corner  cr224u;
    c224u.assign(c219u.x, c224t.y, c224t.z );
    temp2=mult(c224u,temp1);   cr224u=add(temp,temp2); 
    
    //all_unique_corners.push_back(c200); int c200_=138;
    all_unique_corners.push_back(cr201u); int cr201u_=202;
    all_unique_corners.push_back(cr202u); int cr202u_=203;
    all_unique_corners.push_back(cr203u); int cr203u_=204;
    all_unique_corners.push_back(cr204u); int cr204u_=205;
    all_unique_corners.push_back(cr205u); int cr205u_=206;
    //  all_unique_corners.push_back(c206u); int c206u_=145;
    //  all_unique_corners.push_back(c207u); int c207u_=146;
    all_unique_corners.push_back(cr208u); int cr208u_=207;
    all_unique_corners.push_back(cr209u); int cr209u_=208;
    all_unique_corners.push_back(cr210u); int cr210u_=209;
    all_unique_corners.push_back(cr211u); int cr211u_=210;
    all_unique_corners.push_back(cr212u); int cr212u_=211;
    all_unique_corners.push_back(cr213u); int cr213u_=212;
    all_unique_corners.push_back(cr214u); int cr214u_=213;
    //  all_unique_corners.push_back(c215u); int c215u_=54;
    //  all_unique_corners.push_back(c216u); int c216u_=155;
    //  all_unique_corners.push_back(c217u); int c217u_=156;
    all_unique_corners.push_back(cr218u); int cr218u_=214;
    all_unique_corners.push_back(cr219u); int cr219u_=215;
    all_unique_corners.push_back(cr222u); int cr222u_=216; 
    all_unique_corners.push_back(cr223u); int cr223u_=217;
    
    
    all_unique_corners.push_back(cr200b); int cr200b_=218;
    all_unique_corners.push_back(cr201b); int cr201b_=219;
    all_unique_corners.push_back(cr202b); int cr202b_=220;
    all_unique_corners.push_back(cr203b); int cr203b_=221;
    all_unique_corners.push_back(cr204b); int cr204b_=222;
    all_unique_corners.push_back(cr205b); int cr205b_=223;
    all_unique_corners.push_back(cr206b); int cr206b_=224;
    all_unique_corners.push_back(cr207b); int cr207b_=225;
    all_unique_corners.push_back(cr208b); int cr208b_=226;
    all_unique_corners.push_back(cr209b); int cr209b_=227;
    all_unique_corners.push_back(cr210b); int cr210b_=228;
    all_unique_corners.push_back(cr211b); int cr211b_=229;
    all_unique_corners.push_back(cr212b); int cr212b_=230;
    all_unique_corners.push_back(cr213b); int cr213b_=231;
    all_unique_corners.push_back(cr214b); int cr214b_=232;
    //    all_unique_corners.push_back(cr215b); int cr215b_=177;
    //    all_unique_corners.push_back(cr216b); int cr216b_=178;
    //    all_unique_corners.push_back(cr217b); int cr217b_=179;
    all_unique_corners.push_back(cr218b); int cr218b_=233;
    all_unique_corners.push_back(cr219b); int cr219b_=234;
    all_unique_corners.push_back(cr220b); int cr220b_=235;
    all_unique_corners.push_back(cr221b); int cr221b_=236;
    all_unique_corners.push_back(cr222b); int cr222b_=237;
    all_unique_corners.push_back(cr223b); int cr223b_=238;
    
    all_unique_corners.push_back(cr200e); int cr200e_=239;
    all_unique_corners.push_back(cr201e); int cr201e_=240;
    all_unique_corners.push_back(cr202e); int cr202e_=241;
    all_unique_corners.push_back(cr203e); int cr203e_=242;
    all_unique_corners.push_back(cr204e); int cr204e_=243;
    all_unique_corners.push_back(cr205e); int cr205e_=244;
    all_unique_corners.push_back(cr206e); int cr206e_=245;
    all_unique_corners.push_back(cr207e); int cr207e_=246;
    all_unique_corners.push_back(cr208e); int cr208e_=247;
    all_unique_corners.push_back(cr209e); int cr209e_=248;
    all_unique_corners.push_back(cr210e); int cr210e_=249;
    all_unique_corners.push_back(cr211e); int cr211e_=250;
    all_unique_corners.push_back(cr212e); int cr212e_=251;
    all_unique_corners.push_back(cr213e); int cr213e_=252;
    all_unique_corners.push_back(cr214e); int cr214e_=253;
    //    all_unique_corners.push_back(cr215e); int cr215e_=200;
    //    all_unique_corners.push_back(cr216e); int cr216e_=201;
    //    all_unique_corners.push_back(cr217e); int cr217e_=202;
    all_unique_corners.push_back(cr218e); int cr218e_=254;
    all_unique_corners.push_back(cr219e); int cr219e_=255;
    //    all_unique_corners.push_back(cr220e); int cr220e_=205;
    //    all_unique_corners.push_back(cr221e); int cr221e_=206;
    all_unique_corners.push_back(cr222e); int cr222e_=256;
    all_unique_corners.push_back(cr223e); int cr223e_=257;
    
    //    all_unique_corners.push_back(cr200t); int cr200t_=208;
    //    all_unique_corners.push_back(cr201t); int cr201t_=209;
    //    all_unique_corners.push_back(cr202t); int cr202t_=210;
    //    all_unique_corners.push_back(cr203t); int cr203t_=211;
    //    all_unique_corners.push_back(cr204t); int cr204t_=212;
    //    all_unique_corners.push_back(cr205t); int cr205t_=213;
    //    all_unique_corners.push_back(cr206t); int cr206t_=214;
    //    all_unique_corners.push_back(cr207t); int cr207t_=215;
    //    all_unique_corners.push_back(cr208t); int cr208t_=216;
    //    all_unique_corners.push_back(cr209t); int cr209t_=217;
    all_unique_corners.push_back(cr210t); int cr210t_=258;
    //    all_unique_corners.push_back(cr211t); int cr211t_=219;
    //    all_unique_corners.push_back(cr212t); int cr212t_=220;
    //    all_unique_corners.push_back(cr213t); int cr213t_=221;
    //    all_unique_corners.push_back(cr214t); int cr214t_=195;
    all_unique_corners.push_back(cr215t); int cr215t_=259;
    all_unique_corners.push_back(cr216t); int cr216t_=260;
    all_unique_corners.push_back(cr217t); int cr217t_=261;
    //    all_unique_corners.push_back(cr218t); int cr218t_=226;
    //    all_unique_corners.push_back(cr219t); int cr219t_=227;
    //    all_unique_corners.push_back(cr220t); int cr220t_=228;
    //    all_unique_corners.push_back(cr221t); int cr221t_=229;
    //    all_unique_corners.push_back(cr222t); int cr222t_=230;
    all_unique_corners.push_back(cr224t); int cr224t_=262;
    all_unique_corners.push_back(cr225t); int cr225t_=263;
    all_unique_corners.push_back(cr200u); int cr200u_=264;
    
    all_unique_corners.push_back(c207u); int c207u_=265;
    all_unique_corners.push_back(cr207u); int cr207u_=266;
    
    all_unique_corners.push_back(c225u); int c225u_=267;
    all_unique_corners.push_back(c225b); int c225b_=268;
    
    all_unique_corners.push_back(c220u); int c220u_=269;
    all_unique_corners.push_back(c221u); int c221u_=270;
    all_unique_corners.push_back(c224u); int c224u_=271;
    all_unique_corners.push_back(c224b); int c224b_=272;
    all_unique_corners.push_back(c226t); int c226t_=273;
    all_unique_corners.push_back(cr224u); int cr224u_=274;
    

    
// 52 Blackbird.m contains code for rating thebuilding so that y is true north. This is not necessary, and instead we opt to rotate the incident angle. 

   
//  Rotate Corners so that microphone receiver positions, and arrival angles are kosher
    
    position_vector i_vec(1,0,0);
	position_vector j_vec(0,1,0);
	position_vector k_vec(0,0,1);
    
    std::vector<position_vector> d_vec;
	d_vec.push_back(i_vec); d_vec.push_back(j_vec); d_vec.push_back(k_vec); //d is just the diagonal identity matrix
    
   
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
	
    
//% *3.-------Definition of Walls------*
//definition of planes with their indices
    
    const unsigned num_wallfaces=28;
      unsigned face_corn_inds[num_wallfaces][4]=
    { //  {c1_, ct1_, ct2_, c2_},
      //  {c2_, ct2_, ct3_, c3_},
      //  {c3_, ct3_, ct4_, c4_},
       // {c4_, ct4_, ct5_, c5_},
        //{c5_, ct5_, ct6_, c6_},
        //{c6_, ct6_, ct7_, c7_}, //partition wall
        //{c7_, ct7_, ct6_, c6_}, //partition wall
        {c6_, ct6_, ct8_, c8_},
        {c8_, ct8_, ct9_, c9_},
        {c9_, ct9_, ct10_, c10_},
        {c10_, ct10_, ct11_, c11_}, //10
        {c11_, ct11_, ct12_, c12_},
        {c12_, ct12_, ct13_, c13_},
        {c13_, ct13_, ct14_, c14_},
      //  {c14_, ct14_, ct1_, c1_}, //14
        
        //beginning the reflected side
     //   {crt1_, cr1_, cr2_, crt2_},
     //   {crt2_, cr2_, cr3_, crt3_},
     //   {crt3_, cr3_, cr4_, crt4_},
     //   {crt4_, cr4_, cr5_, crt5_},
     // {crt5_, cr5_, cr6_, crt6_},
        {crt6_, cr6_, cr7_, crt7_},
        {crt7_, cr7_, cr6_, crt6_},
        {crt7_, cr7_, cr6_, crt6_},
        {crt6_, cr6_, cr8_, crt8_},
        {crt8_, cr8_, cr9_, crt9_},
        {crt9_, cr9_, cr10_, crt10_},
        {crt10_, cr10_, cr11_, crt11_},
        {crt11_, cr11_, cr12_, crt12_},
        {crt12_, cr12_, cr13_, crt13_},
        {crt13_, cr13_, cr14_, crt14_},
//        {crt14_, cr14_, cr1_, crt1_},
    
        {c6_, cr6_, crt6_, ct6_},
        {32,4,c219u_, c218u_},
        //{cr5_, c5_, ct5_, crt5_},
        
        
        //pitched roof walls.
        {2, 1, c200u_, c201u_},
        {3, 2, c201u_, c202u_},
        {4, 3, c202u_, c219u_},
        {29, 30, cr201u_, cr200u_},
        {30, 31, cr202u_, cr201u_},
        {31, 32, cr219u_, cr202u_},
    }; 
    


std::vector<wall> faces;   //can't preallocate a structure containing types of variable length
wall tempface; 
corner tempcorn;
unsigned tempinds[4];
unsigned corner_index;
for(int wall_num=0; wall_num<num_wallfaces; wall_num++)
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
        tempface.corners.push_back(tempcorn);

        
    }
    tempface.num=wall_num;
    tempface.setnorm();      
    tempface.floorplane=false;
    tempface.mother_wall_numpointsperpoly.push_back(tempface.num_corners);//assumes each face is a single polygon
    
    faces.push_back(tempface);
}

//flat roof
    
    //unsigned roof_corn_inds[26]={ crt2_, crt3_, crt4_, crt5_, ct5_, ct4_, ct3_, ct2_, ct1_, ct14_, ct13_, ct12_, ct11_, ct10_, ct9_, ct8_, ct6_, crt6_, crt8_, crt9_, crt10_, crt11_, crt12_, crt13_, crt14_, crt1_  };
//    
//    wall roof(roof_corn_inds,26);
//    
//                        for(int ind=0; ind< 26; ind++)
//                        {   
//                            corner_index=roof.corner_indices[ind];
//                            tempcorn=all_unique_corners[corner_index];
//                            roof.corners.push_back(tempcorn);
//                            
//                        }
//                        roof.num=faces.size();
//                        roof.setnorm();  
//                        roof.mother_wall_numpointsperpoly.push_back(26);//assumes each face is a single polygon
//    faces.push_back(roof);
    
//pitched roof. 
    
    //walls that change from the flat roof geometry. 
    unsigned S_wall1_inds[6]={0, c209u_, c208u_, c205u_, c200u_, 1};   
    unsigned E_wall1_inds[5]={0, 13, c211u_, c210u_, c209u_};   


    unsigned S_wall1r_inds[6]={cr1_, cr2_, cr200u_, cr205u_, cr208u_, cr209u_};   
    unsigned E_wall1r_inds[5]={cr1_, cr209u_, cr210u_, cr211u_, cr14_};  

    
    
    wall S_wall1_wall(S_wall1_inds,6);
    wall E_wall1_wall(E_wall1_inds,5);
    wall S_wall1r_wall(S_wall1r_inds,6);
    wall E_wall1r_wall(E_wall1r_inds,5);
    

    
    for(int ind=0; ind< 6; ind++)
    {   
        corner_index=S_wall1_wall.corner_indices[ind];
        tempcorn=all_unique_corners[corner_index];
        S_wall1_wall.corners.push_back(tempcorn);
        
    }
    S_wall1_wall.num=faces.size();
    S_wall1_wall.setnorm();  
    S_wall1_wall.mother_wall_numpointsperpoly.push_back(6);//assumes each face is a single polygon
    S_wall1_wall.floorplane=false;
    faces.push_back(S_wall1_wall);

    for(int ind=0; ind< 5; ind++)
    {   
        corner_index=E_wall1_wall.corner_indices[ind];
        tempcorn=all_unique_corners [corner_index];
        E_wall1_wall.corners.push_back(tempcorn);
        
    }
    E_wall1_wall.num=faces.size();
    E_wall1_wall.setnorm();  
    E_wall1_wall.mother_wall_numpointsperpoly.push_back(5);//assumes each face is a single polygon
    E_wall1_wall.floorplane=false;
    faces.push_back(E_wall1_wall);
    
    
    for(int ind=0; ind< 6; ind++)
    {   
        corner_index=S_wall1r_wall.corner_indices[ind];
        tempcorn=all_unique_corners[corner_index];
        S_wall1r_wall.corners.push_back(tempcorn);
        
    }
    S_wall1r_wall.num=faces.size();
    S_wall1r_wall.setnorm();  
    S_wall1r_wall.mother_wall_numpointsperpoly.push_back(6);//assumes each face is a single polygon
    S_wall1r_wall.floorplane=false;
    faces.push_back(S_wall1r_wall);
    
    
    for(int ind=0; ind< 5; ind++)
    {   
        corner_index=E_wall1r_wall.corner_indices[ind];
        tempcorn=all_unique_corners[corner_index];
        E_wall1r_wall.corners.push_back(tempcorn);
        
    }
    E_wall1r_wall.num=faces.size();
    E_wall1r_wall.setnorm();  
    E_wall1r_wall.mother_wall_numpointsperpoly.push_back(5);//assumes each face is a single polygon
    E_wall1r_wall.floorplane=false;
    faces.push_back(E_wall1r_wall);

    //Roof Pieces

    
    
    
    unsigned Roof1[8]={c219e_, c204e_, c203e_,c202e_, c201e_, c200e_, c205e_, c224t_ };
    unsigned Roof2[6]={c205e_, c207e_, c217t_, c214e_, c222e_, c224t_};
    unsigned Roof3[6]={ c209e_, c210t_, c215t_, c216t_, c217t_, c208e_};
    unsigned Roof4[4]={c214e_, c217t_, c216t_, c213e_};
    unsigned Roof5[4]={c212e_, c213e_, c216t_, c215t_};
    unsigned Roof6[4]={c211e_, c212e_, c215t_, c210t_};
    
    unsigned Roof1r[8]={cr219e_, cr224t_ , cr205e_, cr200e_, cr201e_,cr202e_, cr203e_, cr204e_};
    unsigned Roof2r[7]={cr224t_, cr224t_, cr222e_, cr214e_, cr217t_, cr207e_, cr205e_};
    unsigned Roof3r[6]={cr209e_, cr208e_, cr217t_, cr216t_, cr215t_, cr210t_};
    unsigned Roof4r[4]={cr214e_, cr213e_, cr216t_, cr217t_};
    unsigned Roof5r[4]={cr212e_, cr215t_, cr216t_, cr213e_};
    unsigned Roof6r[4]={cr211e_, cr210t_, cr215t_, cr212e_};
    
    wall Roof1_wall(Roof1,8);
    for(int ind=0; ind< 8; ind++)
    {   
        corner_index=Roof1_wall.corner_indices[ind];
        tempcorn=all_unique_corners[corner_index];
        Roof1_wall.corners.push_back(tempcorn);
        
    }
    Roof1_wall.num=faces.size();
    Roof1_wall.setnorm();  
    Roof1_wall.mother_wall_numpointsperpoly.push_back(8);//assumes each face is a single polygon
    Roof1_wall.floorplane=false;
    faces.push_back(Roof1_wall);
    
    
    wall Roof2_wall(Roof2,6);
    for(int ind=0; ind< 6; ind++)
    {   
        corner_index=Roof2_wall.corner_indices[ind];
        tempcorn=all_unique_corners[corner_index];
        Roof2_wall.corners.push_back(tempcorn);
        
    }
    Roof2_wall.num=faces.size();
    Roof2_wall.setnorm();  
    Roof2_wall.mother_wall_numpointsperpoly.push_back(6);//assumes each face is a single polygon
    Roof2_wall.floorplane=false;
    faces.push_back(Roof2_wall);
    
    
    
    wall Roof3_wall(Roof3,6);
    for(int ind=0; ind< 6; ind++)
    {   
        corner_index=Roof3_wall.corner_indices[ind];
        tempcorn=all_unique_corners[corner_index];
        Roof3_wall.corners.push_back(tempcorn);
        
    }
    Roof3_wall.num=faces.size();
    Roof3_wall.setnorm();  
    Roof3_wall.mother_wall_numpointsperpoly.push_back(6);//assumes each face is a single polygon
    Roof3_wall.floorplane=false;
    faces.push_back(Roof3_wall);
    
    wall Roof4_wall(Roof4,4);
    for(int ind=0; ind< 4; ind++)
    {   
        corner_index=Roof4_wall.corner_indices[ind];
        tempcorn=all_unique_corners[corner_index];
        Roof4_wall.corners.push_back(tempcorn);
        
    }
    Roof4_wall.num=faces.size();
    Roof4_wall.setnorm();  
    Roof4_wall.mother_wall_numpointsperpoly.push_back(4);//assumes each face is a single polygon
    Roof4_wall.floorplane=false;
    faces.push_back(Roof4_wall);
    
    wall Roof5_wall(Roof5,4);
    for(int ind=0; ind< 4; ind++)
    {   
        corner_index=Roof5_wall.corner_indices[ind];
        tempcorn=all_unique_corners[corner_index];
        Roof5_wall.corners.push_back(tempcorn);
        
    }
    Roof5_wall.num=faces.size();
    Roof5_wall.setnorm();  
    Roof5_wall.mother_wall_numpointsperpoly.push_back(4);//assumes each face is a single polygon
    Roof5_wall.floorplane=false;
    faces.push_back(Roof5_wall);
    
    wall Roof6_wall(Roof6,4);
    for(int ind=0; ind< 4; ind++)
    {   
        corner_index=Roof6_wall.corner_indices[ind];
        tempcorn=all_unique_corners[corner_index];
        Roof6_wall.corners.push_back(tempcorn);
        
    }
    Roof6_wall.num=faces.size();
    Roof6_wall.setnorm();  
    Roof6_wall.mother_wall_numpointsperpoly.push_back(4);//assumes each face is a single polygon
    Roof6_wall.floorplane=false;
    faces.push_back(Roof6_wall);
    
    
    wall Roof1r_wall(Roof1r,8);
    for(int ind=0; ind< 8; ind++)
    {   
        corner_index=Roof1r_wall.corner_indices[ind];
        tempcorn=all_unique_corners[corner_index];
        Roof1r_wall.corners.push_back(tempcorn);
        
    }
    Roof1r_wall.num=faces.size();
    Roof1r_wall.setnorm();  
    Roof1r_wall.mother_wall_numpointsperpoly.push_back(8);//assumes each face is a single polygon
    Roof1r_wall.floorplane=false;
    faces.push_back(Roof1r_wall);
    
    
    wall Roof2r_wall(Roof2r,7);
    for(int ind=0; ind< 7; ind++)
    {   
        corner_index=Roof2r_wall.corner_indices[ind];
        tempcorn=all_unique_corners[corner_index];
        Roof2r_wall.corners.push_back(tempcorn);
        
    }
    Roof2r_wall.num=faces.size();
    Roof2r_wall.setnorm();  
    Roof2r_wall.mother_wall_numpointsperpoly.push_back(7);//assumes each face is a single polygon
    Roof2r_wall.floorplane=false;
    faces.push_back(Roof2r_wall);
    
    
    
    wall Roof3r_wall(Roof3r,6);
    for(int ind=0; ind< 6; ind++)
    {   
        corner_index=Roof3r_wall.corner_indices[ind];
        tempcorn=all_unique_corners[corner_index];
        Roof3r_wall.corners.push_back(tempcorn);
        
    }
    Roof3r_wall.num=faces.size();
    Roof3r_wall.setnorm();  
    Roof3r_wall.mother_wall_numpointsperpoly.push_back(6);//assumes each face is a single polygon
    Roof3r_wall.floorplane=false;
    faces.push_back(Roof3r_wall);
    
    wall Roof4r_wall(Roof4r,4);
    for(int ind=0; ind< 4; ind++)
    {   
        corner_index=Roof4r_wall.corner_indices[ind];
        tempcorn=all_unique_corners[corner_index];
        Roof4r_wall.corners.push_back(tempcorn);
        
    }
    Roof4r_wall.num=faces.size();
    Roof4r_wall.setnorm();  
    Roof4r_wall.mother_wall_numpointsperpoly.push_back(4);//assumes each face is a single polygon
    Roof4r_wall.floorplane=false;
    faces.push_back(Roof4r_wall);
    
    wall Roof5r_wall(Roof5r,4);
    for(int ind=0; ind< 4; ind++)
    {   
        corner_index=Roof5r_wall.corner_indices[ind];
        tempcorn=all_unique_corners[corner_index];
        Roof5r_wall.corners.push_back(tempcorn);
        
    }
    Roof5r_wall.num=faces.size();
    Roof5r_wall.setnorm();  
    Roof5r_wall.mother_wall_numpointsperpoly.push_back(4);//assumes each face is a single polygon
    Roof5r_wall.floorplane=false;
    faces.push_back(Roof5r_wall);
    
    wall Roof6r_wall(Roof6r,4);
    for(int ind=0; ind< 4; ind++)
    {   
        corner_index=Roof6r_wall.corner_indices[ind];
        tempcorn=all_unique_corners[corner_index];
        Roof6r_wall.corners.push_back(tempcorn);
        
    }
    Roof6r_wall.num=faces.size();
    Roof6r_wall.setnorm();  
    Roof6r_wall.mother_wall_numpointsperpoly.push_back(4);//assumes each face is a single polygon
    Roof6r_wall.floorplane=false;
    faces.push_back(Roof6r_wall);

    //Eaves
    const unsigned numeaves=44;
    unsigned eaves_inds[numeaves][4]= 
    { 
        

     //SouthSIDE   
        //UnderSide of Eaves  
        //West Side of House (After Rotation)
//        {cr200b_, cr201b_, cr201u_, cr200u_},
//        {cr201b_, cr202b_, cr202u_, cr201u_},
//        {cr202b_, cr203b_, cr203u_, cr202u_},
//        {cr204b_, cr218b_, cr218u_, cr203u_},
        
        //South Side of House (After Rotation)
       // {cr205b_, cr200b_, cr200u_, cr205u_},
        {cr207b_, cr205b_, cr205u_, cr208u_},
         {cr209b_, cr208b_, cr208u_, cr209u_},
        
        //North and concave Sides (After Rotation)
        {cr209b_, cr209u_, cr210u_, cr210b_},
        {cr210b_, cr210u_, cr211u_, cr211b_},
        {cr211b_, cr211u_, cr212u_, cr212b_},
        {cr212b_, cr212u_, cr213u_, cr213b_},
        {cr213b_, cr213u_, cr214u_, cr214b_},
        {cr119t_, cr108t_, cr222b_, cr214b_}, 
        
        //Edges of Eaves
        //West Side of House (After Rotation)
//        {cr200b_, cr201b_, cr201e_, cr200e_},
//        {cr201b_, cr202b_, cr202e_, cr201e_},
//        {cr202b_, cr203b_, cr203e_, cr202e_},
//        {cr204b_, cr219b_, cr219e_, cr203e_},
        
        //South Side of House (After Rotation)
        {cr205b_, cr200b_, cr200e_, cr205e_},
        {cr207b_, cr205b_, cr205e_, cr207e_},
        {cr209b_, cr208b_, cr208e_, cr209e_},
        
        //North and croncrave Sides (After Rotation)
        { cr209e_, cr209b_, cr210b_, cr210t_},
        { cr210t_, cr210b_, cr211b_, cr211e_},
        { cr211e_, cr211b_, cr212b_,cr212e_},
        { cr212e_, cr212b_, cr213b_, cr213e_},
        { cr213e_, cr213b_, cr214b_, cr214e_},
        { cr214e_, cr214b_, cr222b_,cr222e_},
                
        //Reflected SIDE   
        
        //UnderSide of Eaves  
        //West Side of House (After Rotation)
//        { c201b_, c200b_, c200u_, c201u_},
//        { c202b_, c201b_, c201u_, c202u_},
//        { c203b_, c202b_, c202u_, c203u_},
//        { c218b_, c204b_, c203u_, c218u_},
        
        //South Side of House (After Rotation)
        { c200b_, c205b_, c205u_, c200u_},
        { c205b_, c207b_, c208u_, c205u_},
        { c208b_, c209b_, c209u_, c208u_},
        
        //North and Concave Sides (After Rotation)
        { c209u_, c209b_, c210b_, c210u_},
        { c210u_, c210b_, c211b_, c211u_},
        { c211u_, c211b_, c212b_,c212u_},
        { c212u_, c212b_, c213b_, c213u_},
        { c213u_, c213b_, c214b_, c214u_},
        { c119t_, c214b_, c222b_, c108t_},
        
        //Edges of Eaves
        //West Side of House (After Rotation)
//        {c201b_, c200b_, c200e_, c201e_},
//        { c202b_, c201b_, c201e_, c202e_},
//        { c203b_, c202b_, c202e_, c203e_},
//        {c219b_, c204b_, c203e_, c219e_},
        
        //South Side of House (After Rotation)
        { c200b_, c205b_, c205e_, c200e_},
        { c205b_, c207b_, c207e_, c205e_},
       { c208b_, c209b_, c209e_, c208e_},
        
        //North and Concave Sides (After Rotation)
        { c209b_, c209e_, c210t_ , c210b_},
        { c210b_, c210t_, c211e_, c211b_},
        { c211b_, c211e_, c212e_, c212b_},
        { c212b_, c212e_, c213e_, c213b_},
        { c213b_, c213e_, c214e_, c214b_},
        { c214b_, c214e_, c222e_, c222b_},


    };

   
    for(int wall_num=0; wall_num<numeaves; wall_num++)
    {
        tempinds[0]=eaves_inds[wall_num][0];
        tempinds[1]=eaves_inds[wall_num][1];
        tempinds[2]=eaves_inds[wall_num][2];
        tempinds[3]=eaves_inds[wall_num][3];
        
        tempface= wall(tempinds,4); 
        
        for(int ind=0; ind< 4; ind++)
        {   
            corner_index=tempface.corner_indices[ind];
            tempcorn=all_unique_corners[corner_index];
            tempface.corners.push_back(tempcorn);
            
            
        }
        tempface.num=wall_num;
        tempface.setnorm();             
        tempface.floorplane=false;
        tempface.mother_wall_numpointsperpoly.push_back(tempface.num_corners);//assumes each face is a single polygon
        
        faces.push_back(tempface);
    }
//
/////////////////////////////////
///// Floor Indices
//   
    unsigned floor0_corn_inds[6]={0,1,57,56,c118_, c100_ };   
    unsigned floor1_corn_inds[10]={1,2,3,4,32,31,30,29,58,57};    
    unsigned floor2_corn_inds[6]={29,28, cr100_, cr118_, 59,58};      
    unsigned floor3_corn_inds[19]={56, c118_, c117_, c116_, c115_, c112_, c111_, c109_, c108_, c107_, c106_, cr109_,cr111_, cr112_, cr115_, cr116_, cr117_, cr118_,59}; 
    
    unsigned floor4_corn_inds[7]={c101_, c102_, c103_,  c104_, c105_,  12, 13 };  
    unsigned floor5_corn_inds[7]={cr101_, cr14_, cr13_, cr105_, cr104_, cr103_, cr102_}; 
    unsigned floor6_corn_inds[25]={c100_, c118_, c117_ , c116_, c115_, c112_, c113_, c114_, c111_, c109_, c110_, c107_, c106_,7,8,9, c122_, c121_, c120_, c119_, c105_,c104_,  c103_,c102_, c101_  };
    unsigned floor7_corn_inds[21]={37,36,35, 33, cr107_, cr110_, cr109_, cr111_, cr114_, cr113_, cr112_, cr115_, cr116_, cr117_, cr118_, cr100_, cr101_, cr102_, cr103_, cr104_, cr105_};
    

    wall floor0(floor0_corn_inds,6);
    
    for(int ind=0; ind< 6; ind++)
    {   
        corner_index=floor0.corner_indices[ind];
        tempcorn=all_unique_corners[corner_index];
        floor0.corners.push_back(tempcorn);
        
    }
    floor0.num=faces.size();
    floor0.setnorm();  
    floor0.mother_wall_numpointsperpoly.push_back(6);//assumes each face is a single polygon
    floor0.floorplane=true;
    faces.push_back(floor0);
    //////////
    wall floor1(floor1_corn_inds,10);
    
    for(int ind=0; ind< 10; ind++)
    {   
        corner_index=floor1.corner_indices[ind];
        tempcorn=all_unique_corners[corner_index];
        floor1.corners.push_back(tempcorn);
        
    }
    floor1.num=faces.size();
    floor1.setnorm();  
    floor1.mother_wall_numpointsperpoly.push_back(10);//assumes each face is a single polygon
    floor1.floorplane=true;
    faces.push_back(floor1);
    
    /////////////
    wall floor2(floor2_corn_inds,6);
    
    for(int ind=0; ind< 6; ind++)
    {   
        corner_index=floor2.corner_indices[ind];
        tempcorn=all_unique_corners[corner_index];
        floor2.corners.push_back(tempcorn);
        
    }
    floor2.num=faces.size();
    floor2.setnorm();  
    floor2.mother_wall_numpointsperpoly.push_back(6);//assumes each face is a single polygon
    floor2.floorplane=true;
    faces.push_back(floor2);
    
    ///
    wall floor3(floor3_corn_inds,19);
    
    for(int ind=0; ind< 19; ind++)
    {   
        corner_index=floor3.corner_indices[ind];
        tempcorn=all_unique_corners[corner_index];
        floor3.corners.push_back(tempcorn);
        
    }
    floor3.num=faces.size();
    floor3.setnorm();  
    floor3.mother_wall_numpointsperpoly.push_back(19);//assumes each face is a single polygon
    floor3.floorplane=true;
    faces.push_back(floor3);
    
    ///
    wall floor4(floor4_corn_inds,7);
    
    for(int ind=0; ind< 7; ind++)
    {   
        corner_index=floor4.corner_indices[ind];
        tempcorn=all_unique_corners[corner_index];
        floor4.corners.push_back(tempcorn);
        
    }
    floor4.num=faces.size();
    floor4.setnorm();  
    floor4.mother_wall_numpointsperpoly.push_back(7);//assumes each face is a single polygon
    floor4.floorplane=true;
    faces.push_back(floor4);
    
//    ///
    wall floor5(floor5_corn_inds,7);
    
    for(int ind=0; ind< 7; ind++)
    {   
        corner_index=floor5.corner_indices[ind];
        tempcorn=all_unique_corners[corner_index];
        floor5.corners.push_back(tempcorn);
        
    }
    floor5.num=faces.size();
    floor5.setnorm();  
    floor5.mother_wall_numpointsperpoly.push_back(7);//assumes each face is a single polygon
    floor5.floorplane=true;
    faces.push_back(floor5);
    
    ///
    wall floor6(floor6_corn_inds,25);
    
    for(int ind=0; ind< 25; ind++)
    {   
        corner_index=floor6.corner_indices[ind];
        tempcorn=all_unique_corners[corner_index];
        floor6.corners.push_back(tempcorn);
        
    }
    floor6.num=faces.size();
    floor6.setnorm();  
    floor6.mother_wall_numpointsperpoly.push_back(25);//assumes each face is a single polygon
    floor6.floorplane=true; //sidewalk
    faces.push_back(floor6);
    
    ///
    wall floor7(floor7_corn_inds,21);
    
    for(int ind=0; ind< 21; ind++)
    {   
        corner_index=floor7.corner_indices[ind];
        tempcorn=all_unique_corners[corner_index];
        floor7.corners.push_back(tempcorn);
            
    }
    floor7.num=faces.size();
    floor7.setnorm();  
    floor7.mother_wall_numpointsperpoly.push_back(21);//assumes each face is a single polygon
    floor7.floorplane=true; //sidewalk
    faces.push_back(floor7);
    
//
///////RoofGeometry-Assemble Walls
////  
    unsigned columnsides_inds[22][4]=
    {
        //eastern most column

        {c109_, c108_, c108t_, c109t_},
        {c108_, c107_, c107t_, c108t_},
        {c107_, c110_, c110t_, c107t_},
        {c110_, c109_, c109t_, c110t_},
        
        //middle column
        {c111_, c114_, c114t_, c111t_},
        {c114_, c113_, c113t_, c114t_},
        {c113_, c112_, c112t_, c113t_},
        {c112_, c111_, c111t_, c112t_},
        
        //western most column
        {c119_, c120_, c120t_, c119t_},
        {c120_, c121_, c121t_, c120t_},
        {c121_, c122_, c122t_, c121t_},
        
        
        //eastern most column reflected
        {cr108_, cr109_, cr109t_, cr108t_},
        {cr107_, cr108_, cr108t_, cr107t_},
        {cr110_, cr107_, cr107t_, cr110t_},
        {cr109_, cr110_, cr110t_, cr109t_},
        
        //middle crolumn reflecrted
        {cr114_, cr111_, cr111t_, cr114t_},
        {cr113_, cr114_, cr114t_, cr113t_},
        {cr112_, cr113_, cr113t_, cr112t_},
        {cr111_, cr112_, cr112t_, cr111t_},
        
        //western most column reflecrted
        {cr120_, cr119_, cr119t_, cr120t_},
        {cr121_, cr120_, cr120t_, cr121t_},
        {cr122_, cr121_, cr121t_, cr122t_},

        
    };
    
    for(int wall_num=0; wall_num<22; wall_num++)
    {
        tempinds[0]=columnsides_inds[wall_num][0];
        tempinds[1]=columnsides_inds[wall_num][1];
        tempinds[2]=columnsides_inds[wall_num][2];
        tempinds[3]=columnsides_inds[wall_num][3];
        
        tempface= wall(tempinds,4); 
        
        for(int ind=0; ind< 4; ind++)
        {   
            corner_index=tempface.corner_indices[ind];
            tempcorn=all_unique_corners[corner_index];
            tempface.corners.push_back(tempcorn); 
            
            
        }

        tempface.floorplane=false;
        tempface.num=faces.size();
        tempface.setnorm();               
        tempface.mother_wall_numpointsperpoly.push_back(tempface.num_corners);//assumes each face is a single polygon
        
        faces.push_back(tempface);
    }
    
    
    const int num_corn_1=4;
  //  unsigned wallsmeet1_inds[num_corn_1]={c224t_, c219u_, c108t_,c222b_ };
    unsigned wallsmeet1_inds[num_corn_1]={c224u_, c222b_ ,  19, c226t_};
    wall wallsmeet1(wallsmeet1_inds,num_corn_1);
    
    for(int ind=0; ind< num_corn_1; ind++)
    {   
        corner_index=wallsmeet1.corner_indices[ind];
        tempcorn=all_unique_corners[corner_index];
        wallsmeet1.corners.push_back(tempcorn);
        
    }
    wallsmeet1.num=faces.size();
    wallsmeet1.setnorm();  
    wallsmeet1.mother_wall_numpointsperpoly.push_back(num_corn_1);//assumes each face is a single polygon
    wallsmeet1.floorplane=false;
    faces.push_back(wallsmeet1);
    
    
     const int num_corn_2=4;
    unsigned wallsmeetr_inds[num_corn_2]={cr224u_, cr219u_, c219u_, c226t_ };
    wall wallsmeetr(wallsmeetr_inds,num_corn_2);
    
    for(int ind=0; ind< num_corn_1; ind++)
    {   
        corner_index=wallsmeetr.corner_indices[ind];
        tempcorn=all_unique_corners[corner_index];
        wallsmeetr.corners.push_back(tempcorn);
        
    }
    wallsmeetr.num=faces.size();
    wallsmeetr.setnorm();  
    wallsmeetr.mother_wall_numpointsperpoly.push_back(num_corn_2);//assumes each face is a single polygon
    wallsmeetr.floorplane=false;
    faces.push_back(wallsmeetr);
    
    const int num_corn_3=6;
     unsigned undereave_inds[num_corn_3]={c119t_, 23, 22, 21, 19, c108t_ };
    //unsigned undereave_inds[num_corn_3]={24, 23, 22, 21};
    wall undereave(undereave_inds,num_corn_3);
    
    for(int ind=0; ind< num_corn_3; ind++)
    {   
        corner_index=undereave.corner_indices[ind];
        tempcorn=all_unique_corners[corner_index];
        undereave.corners.push_back(tempcorn);
        
    }
    undereave.num=faces.size();
    undereave.setnorm();  
    undereave.mother_wall_numpointsperpoly.push_back(num_corn_3);//assumes each face is a single polygon
    undereave.floorplane=false;
    faces.push_back(undereave);
    
    
    unsigned undereave_r_inds[num_corn_3]={ 47, 49, 50, 51, cr119t_, cr108t_};
    //unsigned undereave_r_inds[num_corn_3]={24, 23, 22, 21};
    wall undereave_r(undereave_r_inds,num_corn_3);
    
    for(int ind=0; ind< num_corn_3; ind++)
    {   
        corner_index=undereave_r.corner_indices[ind];
        tempcorn=all_unique_corners[corner_index];
        undereave_r.corners.push_back(tempcorn);
        
    }
    undereave_r.num=faces.size();
    undereave_r.setnorm();  
    undereave_r.mother_wall_numpointsperpoly.push_back(num_corn_3);//assumes each face is a single polygon
    undereave_r.floorplane=false;
    faces.push_back(undereave_r);
    
    //
    return faces;
    
}
#endif