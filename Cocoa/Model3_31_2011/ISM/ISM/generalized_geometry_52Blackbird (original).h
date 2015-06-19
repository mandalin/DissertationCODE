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
radius_of_geom=500*mPERft;
position_vector height(0,0,2.6); //height of the house is approximated at 2.6
position_vector ext_wall_height(0,0,2.46);

position_vector ref(0,0,0);

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

corner ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8, ct9, ct10, ct11, ct12, ct13, ct14;
ct1=add(c1,height); ct2=add(c2,height); ct3=add(c3,height); ct4=add(c4,height); ct5=add(c5,height); ct6=add(c6,height); ct7=add(c7,height); ct8=add(c8,height);
ct9=add(c9,height); ct10=add(c10,height); ct11=add(c11,height); ct12=add(c12,height); ct13=add(c13,height); ct14=add(c14,height);



//reflected portion of house
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
crt1=add(cr1,height); crt2=add(cr2,height); crt3=add(cr3,height); crt4=add(cr4,height); crt5=add(cr5,height); crt6=add(cr6,height);
crt7=add(cr7,height); crt8=add(cr8,height); crt9=add(cr9,height); crt10=add(cr10,height); crt11=add(cr11,height); 
crt12=add(cr12,height); crt13=add(cr13,height); crt14=add(cr14,height);


// Radius Corners
    corner cr_edge0, cr_edge1, cr_edge2, cr_edge3;
    cr_edge0.assign(-radius_of_geom*sqrt(2),-radius_of_geom*sqrt(2),0);
    cr_edge1.assign(-radius_of_geom*sqrt(2),radius_of_geom*sqrt(2),0);
    cr_edge2.assign(radius_of_geom*sqrt(2),radius_of_geom*sqrt(2),0);
    cr_edge3.assign(radius_of_geom*sqrt(2),-radius_of_geom*sqrt(2),0);
    
// 52 Blackbird.m contains code for rating thebuilding so that y is true north. This is not necessary, and instead we opt to rotate the incident angle. 


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
    
//  Rotate Corners so that microphone receiver positions, and arrival angles are kosher
    
    position_vector i(1,0,0);
	position_vector j(0,1,0);
	position_vector k(0,0,1);
    
    std::vector<position_vector> d;
	d.push_back(i); d.push_back(j); d.push_back(k); //d is just the diagonal identity matrix
    
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
    
    unsigned face_corn_inds[33][4]=
    {   {c1_, ct1_, ct2_, c2_},
        {c2_, ct2_, ct3_, c3_},
        {c3_, ct3_, ct4_, c4_},
        {c4_, ct4_, ct5_, c5_},
        {c5_, ct5_, ct6_, c6_},
        {c6_, ct6_, ct7_, c7_},
        {c7_, ct7_, ct6_, c6_},
        {c6_, ct6_, ct8_, c8_},
        {c8_, ct8_, ct9_, c9_},
        {c9_, ct9_, ct10_, c10_},
        {c10_, ct10_, ct11_, c11_}, //10
        {c11_, ct11_, ct12_, c12_},
        {c12_, ct12_, ct13_, c13_},
        {c13_, ct13_, ct14_, c14_},
        {c14_, ct14_, ct1_, c1_}, //14
        
        //beginning the reflected side
        {crt1_, cr1_, cr2_, crt2_},
        {crt2_, cr2_, cr3_, crt3_},
        {crt3_, cr3_, cr4_, crt4_},
        {crt4_, cr4_, cr5_, crt5_},
        {crt5_, cr5_, cr6_, crt6_},
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
        {crt14_, cr14_, cr1_, crt1_},
    
        {c6_, cr6_, crt6_, ct6_},
        {cr5_, c5_, ct5_, crt5_},};
    
    
unsigned roof_corn_inds[26]={ crt2_, crt3_, crt4_, crt5_, ct5_, ct4_, ct3_, ct2_, ct1_, ct14_, ct13_, ct12_, ct11_, ct10_, ct9_, ct8_, ct6_, crt6_, crt8_, crt9_, crt10_, crt11_, crt12_, crt13_, crt14_, crt1_  };
    
unsigned floor0_corn_inds[4]={0,1,57,56 };   
unsigned floor1_corn_inds[10]={1,2,3,4,32,31,30,29,58,57};    
unsigned floor2_corn_inds[4]={29,28,59,58};   
unsigned floor3_corn_inds[22]={56,59,28,41,40,39,38,37,36,35,33,34,c8_,6,7,8,9,10,11,12,13,0};   

std::vector<wall> faces;   //can't preallocate a structure containing types of variable length
wall tempface; 
corner tempcorn;
unsigned tempinds[4];
unsigned corner_index;
for(int wall_num=0; wall_num<33; wall_num++)
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
    tempface.mother_wall_numpointsperpoly.push_back(tempface.num_corners);//assumes each face is a single polygon
    
    faces.push_back(tempface);
}

//flat roof
    wall roof(roof_corn_inds,26);
    
                        for(int ind=0; ind< 26; ind++)
                        {   
                            corner_index=roof.corner_indices[ind];
                            tempcorn=all_unique_corners[corner_index];
                            roof.corners.push_back(tempcorn);
                            
                        }
                        roof.num=faces.size();
                        roof.setnorm();  
                        roof.mother_wall_numpointsperpoly.push_back(26);//assumes each face is a single polygon
    faces.push_back(roof);
   
    ////////
    wall floor0(floor0_corn_inds,4);
    
    for(int ind=0; ind< 4; ind++)
    {   
        corner_index=floor0.corner_indices[ind];
        tempcorn=all_unique_corners[corner_index];
        floor0.corners.push_back(tempcorn);
        
    }
    floor0.num=faces.size();
    floor0.setnorm();  
    floor0.mother_wall_numpointsperpoly.push_back(4);//assumes each face is a single polygon
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
    floor1.mother_wall_numpointsperpoly.push_back(4);//assumes each face is a single polygon
    floor1.floorplane=true;
    faces.push_back(floor1);
    
    /////////////
    wall floor2(floor2_corn_inds,4);
    
    for(int ind=0; ind< 4; ind++)
    {   
        corner_index=floor2.corner_indices[ind];
        tempcorn=all_unique_corners[corner_index];
        floor2.corners.push_back(tempcorn);
        
    }
    floor2.num=faces.size();
    floor2.setnorm();  
    floor2.mother_wall_numpointsperpoly.push_back(4);//assumes each face is a single polygon
    floor2.floorplane=true;
    faces.push_back(floor2);
    
    ///
    wall floor3(floor3_corn_inds,22);
    
    for(int ind=0; ind< 22; ind++)
    {   
        corner_index=floor3.corner_indices[ind];
        tempcorn=all_unique_corners[corner_index];
        floor3.corners.push_back(tempcorn);
        
    }
    floor3.num=faces.size();
    floor3.setnorm();  
    floor3.mother_wall_numpointsperpoly.push_back(21);//assumes each face is a single polygon
    floor3.floorplane=true;
    faces.push_back(floor3);
    
//
//    ///RoofGeometry
    position_vector DatumW;
    DatumW.assign(all_unique_corners[13]);
    
    corner c0u,c0l,c1u,c1l,c2u,c2l,c3u,c3l,c4u,c4l,c5u,c5l,c6u,c6l,c7u,c7l,c8u,c8l,c9u,c9l,c10u,c10l,c11u,c11l,c12u,c12l,c13u ,c13l,c__14,c__15,c__16,c__17;
    
    c0u.assign(     -6.513887913,	18.39690634,	3.080689744); c0u=add(c0u,DatumW); all_unique_corners.push_back(c0u);   int c0u_=60;
    c0l.assign(     -6.513887913,	18.30156537,	2.892740939); c0l=add(c0l,DatumW); all_unique_corners.push_back(c0l);      int c0l_=61;
    c1u.assign(     -2.633789252,	18.39690634,	3.080689744); c1u=add(c1u,DatumW); all_unique_corners.push_back(c1u);      int c1u_=62;
    c1l.assign(     -2.633789252,	18.30156537,	2.892740939); c1l=add(c1l,DatumW); all_unique_corners.push_back(c1l);      int c1l_=63;
    c2u.assign(     -2.633789252,	18.95616779,	2.826750025); c2u=add(c2u,DatumW); all_unique_corners.push_back(c2u);      int c2u_=64;
    c2l.assign(     -2.633789252,	18.86082682,	2.639636549); c2l=add(c2l,DatumW); all_unique_corners.push_back(c2l);      int c2l_=65;
    c3u.assign(     1.326500898,	18.91196425,	2.703121478); c3u=add(c3u,DatumW); all_unique_corners.push_back(c3u);      int c3u_=66;
    c3l.assign(     1.326500898,	18.81662328,	2.576151619); c3l=add(c3l,DatumW);  all_unique_corners.push_back(c3l);     int c3l_=67;
    c4u.assign(     1.326500898,	19.21738037,	2.700615494); c4u=add(c4u,DatumW); all_unique_corners.push_back(c4u);      int c4u_=68;
    c4l.assign(     1.326500898,	19.1220394,     2.511831361); c4l=add(c4l,DatumW); all_unique_corners.push_back(c4l);      int c4l_=69;
    c5u.assign(     -6.483816104,	13.82053992,	4.862444414); c5u=add(c5u,DatumW); all_unique_corners.push_back(c5u);      int c5u_=70;
    c5l.assign(     -6.483816104,	13.72519895,	4.862444414); c5l=add(c5l,DatumW); all_unique_corners.push_back(c5l);      int c5l_=71;
    c6u.assign(     -6.483816104,	8.990219831,	-6.620996798); c6u=add(c6u,DatumW); all_unique_corners.push_back(c6u);      int c6u_=72;
    c6l.assign(     -6.483816104,	8.894878864,	-6.620996798); c6l=add(c6l,DatumW); all_unique_corners.push_back(c6l);      int c6l_=73;
    c7u.assign(     -6.483816104,	8.685778789,	-6.620996798); c7u=add(c7u,DatumW);  all_unique_corners.push_back(c7u);     int c7u_=74;
    c7l.assign(     -6.483816104,	8.590437821,	-6.620996798); c7l=add(c7l,DatumW); all_unique_corners.push_back(c7l);      int c7l_=75;
    c8u.assign(     -6.817947313,	8.990219831,	2.592022851); c8u=add(c8u,DatumW);  all_unique_corners.push_back(c8u);     int c8u_=76;
    c8l.assign(     -6.744438447,	8.894878864,	2.412427327); c8l=add(c8l,DatumW);   all_unique_corners.push_back(c8l);    int c8l_=77;
    c9u.assign(     -6.817947313,	-0.609965506,	2.592022851); c9u=add(c9u,DatumW);   all_unique_corners.push_back(c9u);    int c9u_=78;
    c9l.assign(     -6.744438447,	-0.514624538,	2.412427327); c9l=add(c9l,DatumW);   all_unique_corners.push_back(c9l);    int c9l_=79;
    c10u.assign(	0.656567825,	-0.609965506,	2.592022851); c10u=add(c10u,DatumW);   all_unique_corners.push_back(c10u);    int c10u_=80;
    c10l.assign(	0.583058959,	-0.514624538,	2.412427327); c10l=add(c10l,DatumW);   all_unique_corners.push_back(c10l);    int c10l_=81;
    c11u.assign(	0.656567825,	5.793805567,	2.592022851); c11u=add(c11u,DatumW);   all_unique_corners.push_back(c11u);    int c11u_=82;
    c11l.assign(	0.583058959,	5.6984646,      2.412427327); c11l=add(c11l,DatumW);   all_unique_corners.push_back(c11l);    int c11l_=83;
    c12u.assign(	1.851086896,	5.793805567,	2.592022851); c12u=add(c12u,DatumW);   all_unique_corners.push_back(c12u);    int c12u_=84;
    c12l.assign(	1.783425326,	5.6984646,      2.412427327); c12l=add(c12l,DatumW);   all_unique_corners.push_back(c12l);    int c12l_=85;
    c13u.assign(	1.851086896,	8.386754846,	2.592022851); c13u=add(c13u,DatumW);   all_unique_corners.push_back(c13u);    int c13u_=86;
    c13l.assign(	1.783425326,	8.291413879,	2.412427327); c13l=add(c13l,DatumW);   all_unique_corners.push_back(c13l);    int c13l_=87;
    c__14.assign(	-3.080689744,	3.154919276,	4.142809324); c__14=add(c__14,DatumW);  all_unique_corners.push_back(c__14);     int c__14_=88;
    c__15.assign(	-3.080689744,	9.559015374,	4.142809324); c__15=add(c__15,DatumW);  all_unique_corners.push_back(c__15);     int c__15_=89;
    c__16.assign(	-2.477582912,	10.22640214,	4.401343346); c__16=add(c__16,DatumW);  all_unique_corners.push_back(c__16);     int c__16_=90;
    c__17.assign(	-2.477582912,	12.81035904,	4.401343346); c__17=add(c__17,DatumW);    all_unique_corners.push_back(c__17);   int c__17_=91;

//   
    unsigned pitched_roof_inds4[15][4]=
    {
        //the ones that go around the perimeter
        {c0u_, c1u_, c1l_, c0l_},
        {c1u_, c2u_, c2l_, c1l_},
        {c2u_, c3u_, c3l_, c2l_},
        {c3u_, c4u_, c4l_, c3l_},
        {c0u_, c0l_, c5l_, c5u_},
        {c7u_, c5u_, c5l_, c7l_},
        {c8u_, c6u_, c6l_, c8l_},
        {c9u_, c8u_, c8l_, c9l_},
        {c10u_, c9u_, c9l_, c10l_},
        {c11u_, c10u_, c10l_, c11l_},
        {c12u_, c11u_, c11l_, c12l_},
        {c13u_, c12u_, c12l_, c13l_},
        
        //the ones on the top
        {c__17_, c__16_, c12u_, c13u_ },
        {c11u_, c12u_, c__16_, c__15_},
        {c10u_, c11u_, c__15_, c__14_},
    };
//    
//    
//    
    for(int wall_num=0; wall_num<15; wall_num++)
    {
        tempinds[0]=pitched_roof_inds4[wall_num][0];
        tempinds[1]=pitched_roof_inds4[wall_num][1];
        tempinds[2]=pitched_roof_inds4[wall_num][2];
        tempinds[3]=pitched_roof_inds4[wall_num][3];
        
        tempface= wall(tempinds,4); 
        
        for(int ind=0; ind< 4; ind++)
        {   
            corner_index=tempface.corner_indices[ind];
            tempcorn=all_unique_corners[corner_index];
            tempface.corners.push_back(tempcorn);
        }
        
        wall_num=faces.size();
        tempface.setnorm();               
        tempface.mother_wall_numpointsperpoly.push_back(tempface.num_corners);//assumes each face is a single polygon
        
        faces.push_back(tempface);
    }
//    

    
    
//    unsigned pitched_roof_inds3[11][3]=
//    {   {c__14_, c9u_, c10u_},
//     
//    };
//    
//    tempinds[0]=pitched_roof_inds3[0];
//    tempinds[1]=pitched_roof_inds3[1];
//    tempinds[2]=pitched_roof_inds3[2];
//    tempface= wall(tempinds,3); 
//
//    
//    unsigned pitched_roof_piece1[7]={c9u_,c__14_, c__15_, c__16_, c__17_, c7u_, c8u_};
//    
//    
    
    return faces;
    
}
#endif