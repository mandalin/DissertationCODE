//
//  CODE_FOR_TESTING_FUNCTIONS.cpp
//  ISM
//
//  Created by Amanda Lind on 11/15/11.
//  Copyright 2011 Pennsylvania State University. All rights reserved.
//

//The intention of this code, is that if a function is behaving questionably, the following code could be used to test that the function is working properly. This code was originally used to test that the functions were working properly. 

////////////////////////////////////////////////////////////////////////////////////////////////
/* test pyth_sum.h	
 
 double x=3.1;
 double y=2;
 double z=1;
 double hyp;	
 std::vector<double> a(3);
 a[0]=x;
 a[1]=y;
 a[2]=z;
 hyp=pyth_sum(a);
 std::cout << hyp; 
 
 //////////////////////////////////////////////////////////////////////////////////////////////// 
 */	//test pythsum.h Function
////////////////////////////////////////////////////////////////////////////////////////////////	
/* test fftw3.h
 fftw_complex *x, *X, *xtemp; //declare two pointers,    * -> dereference opperator ,   & -> address of operator
 
 
 //Essentially coppied from Matlab
 double	fs=8000;
 double	delta_t=1/fs;
 //	double		T=1;
 //	const int	N=floor(fs*T);
 const int	N=5;
 double		delta_f=fs/N;
 double *time,*frequency;		//time series and frequency bins
 
 x=(fftw_complex *) fftw_malloc(sizeof(fftw_complex)*N);   //allocating memory for input and output arrays
 X=(fftw_complex *) fftw_malloc(sizeof(fftw_complex)*N);  //allocating memory for input and output arrays
 xtemp=(fftw_complex *) fftw_malloc(sizeof(fftw_complex)*N); //Here is where we are temporarily putting the input fft
 
 //Initialize the Time Domain Signal
 for(int index=0 ; index < N ; index ++)
 {	xtemp[index][0]=0.0;
 xtemp[index][1]=0.0;
 }
 
 xtemp[1][0]=1.0;
 xtemp[1][1]=0.0;
 xtemp[2][0]=1.0;
 xtemp[2][1]=0.0;
 xtemp[3][0]=1.0;
 xtemp[3][1]=0.0;
 xtemp[4][0]=1.0;
 xtemp[4][1]=0.0;
 
 x=xtemp;
 
 
 
 //Initialize corresponding sample times and frequency bins
 time= (double *) malloc(sizeof(double)*N);
 frequency= (double *) malloc(sizeof(double)*N);
 for(int index=0 ; index < N ; index ++)
 {	time[index]=index*delta_t;
 frequency[index]=index*delta_f;
 }
 
 ////////////////////////////////////////////////////////////////////////////////////////////////
 */	//test that fftw3.h works
////////////////////////////////////////////////////////////////////////////////////////////////		
/* test that TR1 works 	
 
 long double hankel_2(unsigned n, long double x)
 {
 
 unsigned n =1;
 long double x=.2;
 fftw_complex   h_n_2;
 long double  tempj, tempy, jn, yn,;
 
 tempj=std::tr1::sph_bessell( n, x);
 tempy=std::tr1::sph_neumannl( n, x);
 
 jn=sqrt(pi/(2*x))*tempj;
 yn=sqrt(pi/(2*x))*tempy;
 
 h_n_2[0]=jn;
 h_n_2[1]=-yn;
 
 }
 ////////////////////////////////////////////////////////////////////////////////////////////////
 */	//test that TR1 works 		
///////////////////////////////////////////////////////////////////////////////////////////////	
/* // Test hankel_2.h Function
 
 unsigned n;
 double x;
 fftw_complex * h_n_2 = new fftw_complex[1];	
 
 n=1;
 x=.2;
 hankel_2( 0, x, h_n_2);
 std::cout << *h_n_2[0]<<" + "<<*h_n_2[1]<<"i "<<std::endl;
 */
////////////////////////////////////////////////////////////////////////////////////////////////
//*/	//test hankel_2.h Function
////////////////////////////////////////////////////////////////////////////////////////////////
/* Test x_from_X.h Function
 int N=10;
 fftw_complex* X = new fftw_complex[N];
 fftw_complex* x = new fftw_complex[N*2-1];
 
 for(int index=0; index<N; index++)
 {	X[index][0]=1;
 X[index][1]=0;
 std::cout<<X[index][0]<<" + "<<X[index][1]<<"i"<<std::endl;
 }
 
 x_from_X ( X, x, N);
 std::cout<<"YUP"<<std::endl;
 
 for(int index=0; index<N; index++)
 {
 std::cout<<x[index][0]<<" + "<<x[index][1]<<"i"<<std::endl;
 }
 ////////////////////////////////////////////////////////////////////////////////////////////////
 */	//test x_from_X.h Function
////////////////////////////////////////////////////////////////////////////////////////////////
/*	
 //Define the Simple Geometry. In the future, replace this with a header of functions reading a text file. 
 
 //This simplest case consists of six unique corners
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
 wall southwall, northwall, eastwall, westwall, roof, southfloor, westfloor, northfloor, eastfloor;
 
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
 northfloor.normal= cross(sub(northfloor.corners[1],northfloor.corners[0]), sub(northfloor.corners[2],northfloor.corners[0]));
 southfloor.normal= cross(sub(southfloor.corners[1],southfloor.corners[0]), sub(southfloor.corners[2],southfloor.corners[0]));
 eastfloor.normal= cross(sub(eastfloor.corners[1],eastfloor.corners[0]), sub(eastfloor.corners[2],eastfloor.corners[0]));
 westfloor.normal= cross(sub(westfloor.corners[1],westfloor.corners[0]), sub(westfloor.corners[2],westfloor.corners[0]));
 northwall.normal= cross(sub(northwall.corners[1],northwall.corners[0]), sub(northwall.corners[2],northwall.corners[0]));
 southwall.normal= cross(sub(southwall.corners[1],southwall.corners[0]), sub(southwall.corners[2],southwall.corners[0]));
 eastwall.normal= cross(sub(eastwall.corners[1],eastwall.corners[0]), sub(eastwall.corners[2],eastwall.corners[0]));
 westwall.normal= cross(sub(westwall.corners[1],westwall.corners[0]), sub(westwall.corners[2],westwall.corners[0]));
 roof.normal= cross(sub(roof.corners[1],roof.corners[0]), sub(roof.corners[2],roof.corners[0]));
 
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
 */	//test gemometry3.h
////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////
/*
 corner testcorn1( 39.7866,    6.8917,   -5.8378);
 corner testcorn2(39.7866,  -32.8949,    4.7720 );
 corner testcorn3(-39.7866,  -32.8949,    4.7720);
 corner testcorn4(-39.7866,    6.8917,   -5.8378);
 
 wall testwall;
 testwall.corners.push_back(testcorn1);
 testwall.corners.push_back(testcorn2);
 testwall.corners.push_back(testcorn3);
 testwall.corners.push_back(testcorn4);
 testwall.setnorm();
 
 //declare the transformation matrices
 boost::numeric::ublas::matrix<double> Transf(3,3), Transfi(3,3);
 bool inversionsuccessful;
 
 inversionsuccessful=rotate2newFOR(testwall, Transf, Transfi);
 std::cout<<"============"<<std::endl;
 std::cout<< "Transf=" << Transf << std::endl << "Transfi=" << Transfi << std::endl;
 */	//test rotate2newFOR.h Function
////////////////////////////////////////////////////////////////////////////////////////////////
/*
 bool isinside;
 position_vector onepoint(5,5,-1);
 wall testwall;
 position_vector testcorn_1(0,   0,    0);
 position_vector testcorn_2(10,  0,    0);
 position_vector testcorn_3(10,  10,   0);
 position_vector testcorn_4(0,   10,   0);
 
 testwall.corners.push_back(testcorn_1);
 testwall.corners.push_back(testcorn_2);
 testwall.corners.push_back(testcorn_3);
 testwall.corners.push_back(testcorn_4);
 testwall.setnorm();
 
 isinside=inside( onepoint, testwall);
 std::cout<<"The Point is inside is "<<isinside<<std::endl;
 */	//test inside.h Function
////////////////////////////////////////////////////////////////////////////////////////////////
/*	
 position_vector onepoint(15,15,0);
 std::vector<position_vector> vertices;
 position_vector testcorn_1(0,   0,    0);
 position_vector testcorn_2(10,  0,    0);
 position_vector testcorn_3(10,  10,   0);
 position_vector testcorn_4(0,   10,   0);
 
 vertices.push_back(testcorn_1);
 vertices.push_back(testcorn_2);
 vertices.push_back(testcorn_3);
 vertices.push_back(testcorn_4);	
 
 bool insidepoly;
 insidepoly = pointinpoly(onepoint, vertices);
 std::cout<<insidepoly<<" inside poly"<<std::endl;
 */	//test point_in_poly.h Function
////////////////////////////////////////////////////////////////////////////////////////////////	
/*
 bool pointinside;
 
 position_vector pointposition(5,50,-1);
 wall Plane;
 position_vector testcorn_1(0,   0,    0);
 position_vector testcorn_2(10,  0,    0);
 position_vector testcorn_3(10,  10,   0);
 position_vector testcorn_4(0,   10,   0);
 
 Plane.corners.push_back(testcorn_1);
 Plane.corners.push_back(testcorn_2);
 Plane.corners.push_back(testcorn_3);
 Plane.corners.push_back(testcorn_4);
 Plane.setnorm();
 
 pointinside= pointinplane( pointposition, Plane);
 
 std::cout<<pointinside<<std::endl;
 */	//test pointinplane.h Function
////////////////////////////////////////////////////////////////////////////////////////////////	
/*	
 bool point_visible;
 wall ShadingPlane;
 position_vector source_position(1,15,5), receiver_position(-1,15,5);
 
 
 position_vector testcorn_1(0,   0,    0);
 position_vector testcorn_2(0,  0,    10);
 position_vector testcorn_3(0,  10,   10);
 position_vector testcorn_4(0,   10,   0);
 
 ShadingPlane.corners.push_back(testcorn_1);
 ShadingPlane.corners.push_back(testcorn_2);
 ShadingPlane.corners.push_back(testcorn_3);
 ShadingPlane.corners.push_back(testcorn_4);
 ShadingPlane.setnorm();
 
 point_visible=pointvisible(source_position,receiver_position,ShadingPlane);
 
 std::cout<<"The visibility of the point is "<<point_visible<<std::endl;
 
 */	//test pointvisible.h Function		
////////////////////////////////////////////////////////////////////////////////////////////////		
/*		//test center.h Function 
 
 //corner testc1(0,0,0);
 //corner testc2(6,0,0);
 //corner testc3(9,3,0);
 //corner testc4(3,3,0);
 position_vector center_point;
 
 corner testc1(0,0,0);
 corner testc2(4,0,0);
 corner testc3(4,6,0);
 corner testc4(0,6,0);
 
 wall test;
 test.corners.push_back(testc1);
 test.corners.push_back(testc2);
 test.corners.push_back(testc3);
 test.corners.push_back(testc4);	
 test.setnorm();
 
 center_point=center(test);
 std::cout<<center_point.x<<" "<<center_point.y<<" "<<center_point.z<<std::endl;
 
 */	//test center.h	
////////////////////////////////////////////////////////////////////////////////////////////////	
/*		//test centerOgravity.h Function
 //corner testc1(0,0,0);
 //corner testc2(6,0,0);
 //corner testc3(9,3,0);
 //corner testc4(3,3,0);
 position_vector center_point;
 
 corner testc1(0,0,0);
 corner testc2(4,0,0);
 corner testc3(4,6,0);
 corner testc4(0,6,0);
 
 wall test;
 test.corners.push_back(testc1);
 test.corners.push_back(testc2);
 test.corners.push_back(testc3);
 test.corners.push_back(testc4);	
 test.setnorm();
 
 center_point=centerOgravity(test);
 std::cout<<center_point.x<<" "<<center_point.y<<" "<<center_point.z<<std::endl;
 
 */	//test centerOgravity.h
////////////////////////////////////////////////////////////////////////////////////////////////
/*		//Test planeunion.h
 boost::polygon::polygon_data<int> Test;
 
 wall wall1, wall2;
 
 corner tempcorn1(0,0,0);
 corner tempcorn2(0,0,30);
 corner tempcorn3(40,0,30);
 corner tempcorn4(40,0,0);
 
 std::vector<corner>  corners1;
 std::vector<corner> corners2;
 corners1.push_back(tempcorn1);
 corners1.push_back(tempcorn2);
 corners1.push_back(tempcorn3);
 corners1.push_back(tempcorn4);
 
 corner tempcorn5(10,9,0);
 corner tempcorn6(10,15,0);
 corner tempcorn7(20,15,0);
 corner tempcorn8(20,9,0);
 
 corners2.push_back(tempcorn5);
 corners2.push_back(tempcorn6);
 corners2.push_back(tempcorn7);
 corners2.push_back(tempcorn8);
 
 wall1.corners=corners1;
 wall2.corners=corners2;
 
 std::vector<int> numpointsperpoly;
 std::vector<corner> unioncorners;
 planeunion( wall1,  wall2,  unioncorners,  numpointsperpoly);
 */