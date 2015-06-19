/*
 *  x_from_X.h
 *  ISM
 *
 *  Created by Amanda Lind on 12/29/10.
 *  Copyright 2010 Pennsylvania State University. All rights reserved.
 *
 */

//( fftw_complex * freq_domain_in, fftw_complex * time_domain_out, int length)
// NOTE : THIS CODE ASSUMES THAT X IS DOUBLE SIDED ! 
void x_from_X ( fftw_complex *Xsinglesided,fftw_complex*& x, int Nss, double df, double dt)
{
   
   // for (int i=0; i<Nss; i++)
   // {
   //     std::cout<<Xsinglesided[i][0]<<" + "<<Xsinglesided[i][1]<<" i"<<std::endl;
   // }
    
    int N=Nss+Nss-1;
    fftw_plan p;			//declare the plan (optimized way to calculate the FFT)
    fftw_complex* Xdoublesided = new fftw_complex[N];
    
    
	p=fftw_plan_dft_1d(N, Xdoublesided, x , FFTW_BACKWARD, FFTW_ESTIMATE);   //This overwrites in and out... so do this before initializing
    //initialize a plan for the FFT /FFTW_ESTIMATE is the fastest one
    
    


    int doubleind=0;
    
    double Xrms=0;
    double tempreal;
    double tempimag;
    double tempMag;
    
    for(int i=0; i<Nss; i++)
    {  
        Xdoublesided[doubleind][0]=Xsinglesided[i][0];
        Xdoublesided[doubleind][1]=Xsinglesided[i][1];
        //std::cout<< Xdoublesided[doubleind][0]<<" + "<<Xdoublesided[doubleind][1]<<" i"<<std::endl;
       
        
        tempreal= Xdoublesided[doubleind][0];
        tempimag= Xdoublesided[doubleind][1];
        tempMag=std::sqrt(tempreal*tempreal+tempimag*tempimag);
        Xrms= tempMag*tempMag*df + Xrms;
        //std::cout<< tempreal <<" + "<<tempimag<<" i , |"<<tempMag<<"| , "<<Xrms<<" Xrms"<< std::endl;
        
         doubleind++;
        
    }
    
    for(int i=Nss-1; i>0; i--)
    {  
        Xdoublesided[doubleind][0]=Xsinglesided[i][0];
        Xdoublesided[doubleind][1]=-Xsinglesided[i][1];
        
        tempreal= Xdoublesided[doubleind][0];
        tempimag= Xdoublesided[doubleind][1];
        tempMag=std::sqrt(tempreal*tempreal+tempimag*tempimag);
        Xrms= tempMag*tempMag*df + Xrms;
    //    std::cout<< tempreal <<" + "<<tempimag<<" i , |"<<tempMag<<"| , "<<Xrms<<" Xrms"<< std::endl;
        
        doubleind++;
    }
    
    
    std::cout<< "The double sided frequency domain has "<<doubleind<<" samples"<<std::endl;
	//for(int index=0; index< N*2-1; index++)
	//{	std::cout << Xdoublesided[index][0]<<" + "<< Xdoublesided[index][1]<<"i "<< std::endl ;
	//}
	
	fftw_execute(p);		//execute the fft
    
    
    double tempPhase;
    double xrms=0;

    
    for(int i=0; i<N; i++)
    { 
        tempreal=x[i][0];
        tempimag=x[i][1];
        tempMag=std::sqrt(tempreal*tempreal+tempimag*tempimag);
        tempMag=tempMag*df;
        tempPhase=atan(tempimag/tempreal);
        
        x[i][0]=tempMag*cos(tempPhase);
        x[i][1]=tempMag*sin(tempPhase);
        xrms=tempMag*tempMag*dt+xrms;
        
  //      std::cout<< x[i][0] <<" + "<<x[i][1]<<" i , |"<<tempMag<<"| , "<<xrms<<" xrms"<< std::endl;
        
        
    }
    
    std::cout<<"Xrms = "<<Xrms<<" xrms = "<<xrms<<std::endl;

        
    delete[] Xdoublesided;
	fftw_destroy_plan(p);	//deconstruct
	//fftw_free(x);			//dealocate
	//fftw_free(X);			//dealocate

	return;
}
		


