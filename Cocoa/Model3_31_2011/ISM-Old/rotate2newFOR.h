/*
 *  rotate2newFOR.h
 *  ISM
 *
 *  Created by Amanda Lind on 2/24/11.
 *  Copyright 2011 Pennsylvania State University. All rights reserved.
 *
 */

// with the input of a plane containing corners, the transformation matrix
// to rotate the corners onto a plane parallel to the Z=0 plane, and the 
// transformation matrix to rotate it back are returned.
template<class T>
bool rotate2newFOR(wall::wall unrotated, boost::numeric::ublas::matrix<T>& Transf, boost::numeric::ublas::matrix<T>& Transfi)
{
	
	position_vector i(1,0,0);
	position_vector j(0,1,0);
	position_vector k(0,0,1);
	double temp;
	
	position_vector between1n2;
	
	between1n2=sub(unrotated.corners[1],unrotated.corners[0]);
	//std::cout<<"-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_"<<std::endl;
	
	//std::cout<<"between1n2 "<<between1n2.v[0]<<" "<<between1n2.v[1]<<" "<<between1n2.v[2]<<std::endl;
	
	temp=pyth_sum(between1n2.v);
	position_vector o1(between1n2.v[0]/temp,between1n2.v[1]/temp,between1n2.v[2]/temp);
	position_vector o2,o3;
	
	o3=unrotated.normal;
	o2=cross(o1,o3);
	//std::cout<<o1.v[0]<<" "<<o1.v[1]<<" "<<o1.v[2]<<" ,-o1"<<std::endl;
	//std::cout<<o2.v[0]<<" "<<o2.v[1]<<" "<<o2.v[2]<<" ,-o2"<<std::endl;
	//std::cout<<o3.v[0]<<" "<<o3.v[1]<<" "<<o3.v[2]<<" ,-o3"<<std::endl<<std::endl;
	
	
	std::vector<position_vector> d;
	d.push_back(i); d.push_back(j); d.push_back(k); //d is just the diagonal identity matrix

	std::complex<double> alpha_x, beta_x, gamma_x, alpha_y, beta_y, gamma_y, alpha_z, beta_z, gamma_z; 
	double alpha_xr, beta_xr, gamma_xr, alpha_yr, beta_yr, gamma_yr, alpha_zr, beta_zr, gamma_zr;
	
	
	//std::cout<<"======="<<std::endl;
	
	//this is really a real number, but we must declare it as complex since the output might be complexl	
	double temparg=dot(d[0],o1);
		//std::cout<<"temparg= "<<temparg<<std::endl;
	std::complex<double> arg(temparg,0);  
	alpha_x=std::tr1::acos(arg);
	//print(d[0]);
	//std::cout<<" dotted with "<<std::endl;
	//print(o1);
	//std::cout<<"gives "<<arg<<std::endl;
	//std::cout<<alpha_x<<" alpha_x"<<std::endl;


	arg = std::complex<double>(dot(d[1],o1),0);
	beta_x=std::tr1::acos(arg);
	//print(d[1]);
	//std::cout<<" dotted with "<<std::endl;
	//print(o1);
	//std::cout<<"gives "<<arg<<std::endl;
	//std::cout<<arg<<std::endl;
	//std::cout<<beta_x<<" beta_x"<<std::endl;
	
	arg = std::complex<double>(dot(d[2],o1),0);	
	gamma_x=std::tr1::acos(arg);
	//print(d[2]);
	//std::cout<<" dotted with "<<std::endl;
	//print(o1);
	//std::cout<<"gives "<<arg<<std::endl;
	//std::cout<<arg<<std::endl;
	//std::cout<<gamma_x<<" gamma_x"<<std::endl;
	
	//std::cout<<"----"<<std::endl;
	temparg=dot(d[0],o2);
			//std::cout<<"temparg= "<<temparg<<std::endl;
	arg = std::complex<double>(temparg,0);  
	alpha_y=std::tr1::acos(arg);
	//print(d[0]);
	//std::cout<<" dotted with "<<std::endl;
	//print(o2);
	//std::cout<<"gives "<<arg<<std::endl;
	//std::cout<<arg<<std::endl;
	//std::cout<<alpha_y<<" alpha_y"<<std::endl;
	//std::cout<<"----"<<std::endl;	
	
	arg = std::complex<double>(dot(d[1],o2),0);
	beta_y=std::tr1::acos(arg);
	//print(d[1]);
	//std::cout<<" dotted with "<<std::endl;
	//print(o2);
	//std::cout<<"gives "<<arg<<std::endl;
	//std::cout<<arg<<std::endl;
	//std::cout<<beta_y<<" beta_y"<<std::endl;
	
	arg = std::complex<double>(dot(d[2],o2),0);
	gamma_y=std::tr1::acos(arg);
	//print(d[2]);
	//std::cout<<" dotted with "<<std::endl;
	//print(o2);
	//std::cout<<"gives "<<arg<<std::endl;
	//std::cout<<arg<<std::endl;
	//std::cout<<gamma_y<<" gamma_y"<<std::endl;

	arg = std::complex<double>(dot(d[0],o3),0);  
	alpha_z=std::tr1::acos(arg);
	//print(d[0]);
	//std::cout<<" dotted with "<<std::endl;
	//print(o3);
	//std::cout<<"gives "<<arg<<std::endl;
	//std::cout<<arg<<std::endl;
	//std::cout<<alpha_z<<" alpha_z"<<std::endl;
	
	arg = std::complex<double>(dot(d[1],o3),0);
	beta_z=std::tr1::acos(arg);
	//print(d[1]);
	//std::cout<<" dotted with "<<std::endl;
	//print(o3);
	//std::cout<<"gives "<<arg<<std::endl;
	//std::cout<<arg<<std::endl;
	//std::cout<<beta_x<<" beta_z"<<std::endl;
	
	arg = std::complex<double>(dot(d[2],o3),0);
	gamma_z=std::tr1::acos(arg);
	//print(d[02]);
	//std::cout<<" dotted with "<<std::endl;
	//print(o3);
	//std::cout<<"gives "<<arg<<std::endl;

	alpha_xr=std::real(alpha_x); 
	beta_xr=std::real(beta_x); 
	gamma_xr=std::real(gamma_x); 
	alpha_yr=std::real(alpha_y); 
	beta_yr=std::real(beta_y);
	gamma_yr=std::real(gamma_y); 
	alpha_zr=std::real(alpha_z); 
	beta_zr=std::real(beta_z); 
	gamma_zr=std::real(gamma_z);
	//std::cout<<"======="<<std::endl;
	//std::cout<< alpha_xr <<" "<<alpha_yr<<" "<<alpha_zr<<std::endl;
	//std::cout<< beta_xr <<" "<<beta_yr<<" "<<beta_zr<<std::endl;
	//std::cout<< gamma_xr <<" "<<gamma_yr<<" "<<gamma_zr<<std::endl;
	
	double a11=std::cos(alpha_xr);
	double a12=std::cos(alpha_yr);
	double a13=std::cos(alpha_zr);
	double a21=std::cos(beta_xr);
	double a22=std::cos(beta_yr);
	double a23=std::cos(beta_zr);
	double a31=std::cos(gamma_xr);
	double a32=std::cos(gamma_yr); 
	double a33=std::cos(gamma_zr) ;

	double initialValues[3][3] = {
		a11, a12, a13,
		a21, a22, a23,
		a31, a32, a33
	};
	//std::cout<<"====="<<std::endl;
	//std::cout<<a11<<" "<<a12<<" "<<a13<<std::endl;
	//std::cout<<a21<<" "<<a22<<" "<<a23<<std::endl;
	//std::cout<<a31<<" "<<a32<<" "<<a33<<std::endl;
	
	Transf = boost::numeric::ublas::make_matrix_from_pointer(initialValues); //in storage_adapters.hpp
	InvertMatrix(Transf, Transfi);
	return true;
}