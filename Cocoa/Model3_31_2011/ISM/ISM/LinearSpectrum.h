/*
 *  LinearSpectrum.h
 *  ISM
 *
 *  Created by Amanda Lind on 2/3/11.
 *  Copyright 2011 Pennsylvania State University. All rights reserved.
 *
 */

void LinearSpectrum (fftw_complex * x, fftw_complex * X, int N)
{
fftw_plan p;			//declare the plan (optimized way to calculate the FFT)
p=fftw_plan_dft_1d(N, x, X, FFTW_FORWARD, FFTW_ESTIMATE);   //This overwrites in and out... so do this before initializing
//initialize a plan for the FFT /FFTW_ESTIMATE is the fastest one
fftw_execute(p);		//execute the fft
fftw_destroy_plan(p);	//deconstruct
	return;
}