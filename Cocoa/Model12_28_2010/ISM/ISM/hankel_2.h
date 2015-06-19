/*
 *  hankel_2.h
 *  ISM
 *
 *  Created by Amanda Lind on 2/7/11.
 *  Copyright 2011 Pennsylvania State University. All rights reserved.
 *
 */
#include <boost/tr1/cmath.hpp>
#include <boost/math/special_functions/bessel.hpp>

void hankel_2(unsigned n, double x, fftw_complex*& h_n_2)
{
	
//	fftw_complex * h_n_2 = new fftw_complex[1];
	double  tempj, tempy, jn, yn;
	
	tempj=std::tr1::sph_bessel( n, x);
	tempy=std::tr1::sph_neumann( n, x);
	
	jn=sqrt(pi/(2*x))*tempj;
	yn=sqrt(pi/(2*x))*tempy;
	
	h_n_2[0][0]=jn;
	h_n_2[0][1]=-yn;
	
	return;
	//std::cout << h_n_2[0]<<" + "<< h_n_2[1]<<"i "<<std::endl;
	
}