/*
 *  x_from_X.h
 *  ISM
 *
 *  Created by Amanda Lind on 12/29/10.
 *  Copyright 2010 Pennsylvania State University. All rights reserved.
 *
 */

//( fftw_complex * freq_domain_in, fftw_complex * time_domain_out, int length)
void x_from_X ( fftw_complex * X,fftw_complex*& x, int N)
{
	fftw_complex* Xdoublesided = new fftw_complex[N*2-1];
	Xdoublesided = (fftw_complex*) realloc (X, sizeof(fftw_complex)*N*2-1);
	for(int index=N; index < N*2; index++)
	{	Xdoublesided[index][0] = X[N-1-(index-N)][0];
		Xdoublesided[index][1] = -X[N-1-(index-N)][1];
	}
	
	//for(int index=0; index< N*2-1; index++)
	//{	std::cout << Xdoublesided[index][0]<<" + "<< Xdoublesided[index][1]<<"i "<< std::endl ;
	//}
	
	fftw_plan p;			//declare the plan (optimized way to calculate the FFT)
	p=fftw_plan_dft_1d(N, Xdoublesided, x , FFTW_BACKWARD, FFTW_ESTIMATE);   //This overwrites in and out... so do this before initializing
															//initialize a plan for the FFT /FFTW_ESTIMATE is the fastest one
	fftw_execute(p);		//execute the fft
	fftw_destroy_plan(p);	//deconstruct
	delete [] Xdoublesided;
	//fftw_free(x);			//dealocate
	//fftw_free(X);			//dealocate

	return;
}
		


