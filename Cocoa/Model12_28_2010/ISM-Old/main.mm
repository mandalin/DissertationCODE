//
//  main.m
//  ISM
//
//  Created by Amanda Lind on 12/29/10.
//  Copyright Pennsylvania State University 2010. All rights reserved.
//

#import <Cocoa/Cocoa.h>

/*
 *  Find_Images.cpp
 *  ISM
 *
 *  Created by Amanda Lind on 12/29/10.
 *  Copyright 2010 Pennsylvania State University. All rights reserved.
 *
 */


/////////// From standard library included by Lind:
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>

#include <cmath>
#include <complex> //does this conflict with Complex.h file associated with fftw++ ?
					// answered on page 11 of fftw3manual.pdf
					//
					//If you have a C compiler, such as gcc, that supports the recent C99 standard, and
					//you #include <complex.h> before <fftw3.h>, then fftw_complex is the native
					//double-precision complex type and you can manipulate it with ordinary arithmetic.
					//Otherwise, FFTW defines its own complex type, which is bit-compatible with the C99
					//complex type.
#include <numeric>
#include <valarray>

/////////// From fftw++
#include"fftw3.h"

/////////// Modules from Thesis
// Module Appendix A.3
#include "pyth_sum.h"
#include "x_from_X.h"
#include "LinearSpectrum.h"
#include "hankel_2.h"

/////////// Modules created for C++ convenience /classes
#include "position_vector_class.h"
#include "storage_adapters.hpp"
#include "INVERT_MATRIX.hpp"
#include "wall.h"
#include "source.h"
/////////// From TR1 for Special Functions
#include "boost/math/tr1.hpp"
#include <boost/tr1/array.hpp>
#include <boost/tr1/complex.hpp>
#include <boost/math/complex.hpp>
#include <boost/tr1/functional.hpp>
#include <boost/tr1/memory.hpp>
#include <boost/tr1/random.hpp>
#include <boost/tr1/regex.hpp>
#include <boost/tr1/tuple.hpp>
#include <boost/tr1/type_traits.hpp>
#include <boost/tr1/utility.hpp>
#include <boost/tr1/cmath.hpp>
#include <boost/math/special_functions/bessel.hpp>
//for matrix math
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/lu.hpp>
#include <boost/numeric/ublas/io.hpp>

//#include "boost/math/complex.hpp"
//#include "boost/array.hpp"

//More Modules From Thesis
#include "geometry2.h"
#include "rotate2newFOR.h"
#include "inside.h"
#include "pointinpoly.h"
#include "pointinplane.h"
#include "pointvisible.h"
#include "center.h"
#include "centerOgravity.h"
#include "shaded.h"
 
//Graphics
#include <GLUT/glut.h>
#include <OpenGL/glext.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

//---- MAIN ---------------------------------------------------------------------------------------
//---- MAIN ---------------------------------------------------------------------------------------
//---- MAIN ---------------------------------------------------------------------------------------
//---- MAIN ---------------------------------------------------------------------------------------

int main () 
{  	
    std::cout << "Hello, World!\n";

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
/* Test hankel_2.h Function
	
	unsigned n;
	double x;
	fftw_complex * h_n_2 = new fftw_complex[1];	
	
	n=1;
	x=.2;
	hankel_2( 0, x, h_n_2);
	std::cout << h_n_2[0]<<" + "<< h_n_2[1]<<"i "<<std::endl;
////////////////////////////////////////////////////////////////////////////////////////////////
*/	//test hankel_2.h Function
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
	std::vector<wall> planes;
	planes=geometry2();
	
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
// Now working from FAA_5_5_09.m	
	//*1.-------Constants-----------------------------------------------------*
	
	double co=345.0;
	int max_order=5;
	//Assume the receiver is directly under the flight track
	double s=5;         //%seconds of reflections/post boom noise
	double radius=s*co; //%radius of a sphere from which a reflection can reach the 
	//%receiver
	radius=30;
	
	//*2.----------When Solving for few freqs: 
	//	              these are the freqs you posess impedances for--------------*
			
	int	band_number=13;
	int num_bands=43;
	int nb[num_bands-1];
	int f_bands[num_bands-1];
	
	for(int i=1; i<=43; i++)
	{	nb[i]=i;
		f_bands[i]=10^(nb[i]/10);
	}
	
	//% *4a.------Definition of Receiver Position-------------------------------*
	double wall_length=20;								//% Assuming el = 45 degrees...
	position_vector Ppos(0,-(wall_length/2)-2,1.2);									//% receiver Position 1 gives 4 pulses
	//position_vector Ppos=(-8*sind(45),-8*sind(45)+(-(wall_length/2)-2),1.2);			//% receiver Position 2, 3 pulses
	//position_vector Ppos=(-10*sind(45),-10*sind(45)+(-(wall_length/2)-2),1.2);		//% receiver Position 3, 2 pulses
	
	//% *4b.------Definition of Source Position---------------------------------* 
	double M=1.4;
	double mu=asin(1/M)*(180/pi);  //%downstream mach angle, in degrees
	
	double theta_i=90-mu;  
	theta_i=45;
	double phi=45;
	//long double r=radius*10000000000;	//%Using trial and error to see how large r has to be 
										//for delays to converge
    double r=radius*1.0E10;	//%Using trial and error to see how large r has to be 
	
	position_vector temp(r*sin(theta_i*(pi/180))*cos(phi*(pi/180)),-r*sin(theta_i*(pi/180))*sin(phi*(pi/180)),r*cos(theta_i*(pi/180)));
	position_vector Qpos=add(Ppos,temp); 

	std::cout<<Qpos.x<< " "<<Qpos.y<<" "<<Qpos.z<<" Qpos"<<std::endl;
	
	std::cout<<Ppos.x<< " "<<Ppos.y<<" "<<Ppos.z<<" Ppos"<<std::endl;
	
	//%*-5.------Definition of First Order Mirrored sources
	//%          Generalize Sources into A structure----------------------------*
	
	int num_planes=planes.size() ;
	int num_sources=(num_planes-1)^max_order;

	//*-5a Add Mother Source
	std::vector<source> sources;
	source qtemp(Qpos.x,Qpos.y,Qpos.z,0/*order*/,NAN/*mothersource*/,NAN/*motherwall*/,1,0/*audible*/,1/*legal*/);
	sources.push_back(qtemp);
	
	//%*-5b Add First Order Image Sources
	bool is_shaded;
	position_vector n;
	position_vector mother_source_pos;
	position_vector new_source_pos;
	position_vector temp1;
	double d;
	
	for(int i=0; i<num_planes; i++)
	{	mother_source_pos=sources[0].position;
		n=planes[i].normal ;
		corner onecorner=planes[i].corners[1];
		temp1=sub(mother_source_pos,onecorner);
		d=dot(temp1,n);
		temp1.assign(d*2*n.x,d*2*n.x,d*2*n.x);
		new_source_pos=sub(mother_source_pos,temp1);
		if(d>0)
		{	is_shaded=shaded(planes,i,mother_source_pos,sources,0 /*sourceindex*/);
		}
		else
        {	is_shaded=true;} //% this forgoes calculating whether the source is 
							 //% shaded when already illegal (behind reflector)
		
		std::cout<<"The path from source 0 to the center of plane "<<i<<" is shaded: "<<is_shaded<<std::endl;
		
    }
	
	for(int i=0; i<planes.size(); i++)
	{
	std::cout<<"Plane["<<i<<"].normal= ";;
	print(planes[i].normal);
		std::cout<<std::endl;
	}
	

	
    /*
	if((d>0)&&(not(is_shaded))) %mother source must be inside for image 
		%to be created, and the  path to the mother 
		%plane must not be blocked by other planes
        q=add_source(q,qpos,order,mother_index,i,...
					 q.strength(mother_index,:).*P(i).reflection_coeff);
	q.legal(q.last_source)=true;
	q.mother_corners(q.last_source)={P(i).corners};
    end
    if((d<=0)||(is_shaded))
        q=add_source(q,qpos,order,mother_index,i,...
					 q.strength(mother_index,:).*P(i).reflection_coeff); 
	q.legal(q.last_source)=false;
    end
	end
	
	figure(2);
	hold on
	plot_ISM(P,q,1,2:q.last_source,Ppos);
	axis equal
	title('Mother and all first order mirrored sources','FontSize',14)
	*/
	return 0;	
}

//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------



