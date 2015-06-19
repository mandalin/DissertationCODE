//
//  dhtm.h
//  ISM
//
//  Created by Amanda Lind on 7/1/11.
//  Copyright 2011 Pennsylvania State University. All rights reserved.
//


// This code accepts a single sided magnitude, mag and based upon it defines doublesided frequency content
// the frequency content has zero phase, so has 0 imagninary part, therefore the real part of the double
// sided frequency response is based soley on the input magnitude. 

void dhtm(std::vector<double> mag, int s, std::vector<double>& ytrunc, double df)
{   
    
//    std::cout<<"df"<<std::endl;
//    std::cout<<df<<std::endl;    
//    
//    std::cout<<"Single Sided Magnitude"<<std::endl;
//    for(int i=0; i<mag.size(); i++)
//    {
//        std::cout<<mag[i]<<" "<<std::endl;
//    }
    
    
    
    ytrunc.clear();
    //this function assumes that mag is already double sided. 
    
    //////////////////////////////////////////////          
    //                                          //
    //  Mag, as input, is a single sided vector //
    //           Make it Xdoublesided !         //
    //                                          //
    //////////////////////////////////////////////
    
    int doubleind=0;
    
    double Xrms=0;
    double tempreal;
    double tempimag;
    double tempMag;
    
    fftw_complex * Xdoublesided =new fftw_complex[mag.size()*2-1];
    unsigned Nss=mag.size();
    
    for(int i=0; i<Nss; i++)
    {  
        Xdoublesided[doubleind][0]=mag[i];
        Xdoublesided[doubleind][1]=0;
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
        Xdoublesided[doubleind][0]=mag[i];
        Xdoublesided[doubleind][1]=0;
        
        tempreal= Xdoublesided[doubleind][0];
        tempimag= Xdoublesided[doubleind][1];
        tempMag=std::sqrt(tempreal*tempreal+tempimag*tempimag);
        Xrms= tempMag*tempMag*df + Xrms;
        
        doubleind++;
    }
    
   int N=doubleind;
    
//    std::cout<<"Double Sided Magnitude"<<std::endl;
//    for(int i=0; i<Nss*2-1; i++)
//    {
//        std::cout<< Xdoublesided[i][0]<<" "<<std::endl;
//    }
    
    
    //////////////////////////////////////////////          
    //                                          //
    //         Preprocess the Magnitude         //
    //                                          //
    //////////////////////////////////////////////
    
    double dh1, dh2, S, max, min;
    
    max=0;
    min=1.0E10;
    for(int i=0; i<N; i++)
    {   
        if( Xdoublesided[i][0]>max)
        {   max=Xdoublesided[i][0];
        }
        
        if( Xdoublesided[i][0]<min)
        {   min=Xdoublesided[i][0];
        }

    }
    
    //dh1=max-1;        This scaling is only necessary with magnitudes that go below zero and above 1
    //dh2=0-min;
    
    //S=4/(( sqrt(1+dh1+dh2) + sqrt(1-dh1+dh2))*( sqrt(1+dh1+dh2) + sqrt(1-dh1+dh2)));
    
    fftw_complex * H2 =new fftw_complex[N];
    fftw_complex * H3 =new fftw_complex[N];    
    fftw_complex * HR =new fftw_complex[N];
    
    for (int i=0; i<N; i++)
    {
        //H2[i][0] = Xdoublesided[i][0]+dh2;
        H2[i][0] = Xdoublesided[i][0];
        H2[i][1] = 0;

        //H3[i][0] = H2[i][0]*S;
        H3[i][0] = H2[i][0];
        H3[i][1] = 0;    
        
        HR[i][0] = sqrt(H3[i][0])+1.0E-10;
        HR[i][1] = 0; 
    }
    
//    for(int i=0; i<5; i++)
//    {
//        std::cout<<HR[i][0]<<" + "<<HR[i][1]<<" i"<<std::endl;
//    }
    
    //////////////////////////////////////////////          
    //                                          //
    //  Create Sig,        .||||.               //
    //                           ||||           //
    //////////////////////////////////////////////
    
    
    std::vector<double> sig;

    
    for(int i=0; i< N; i++)
    {   if (i<N/2-1)
        {  sig.push_back(1);
        }
        else
        {  sig.push_back(-1);
        }
    }
    sig[0]=0;
    sig[std::floor(N/2)]=0;
    
    
//    std::cout<<"Sig"<<std::endl;
//    for(int i=0; i<N; i++)
//    {
//        std::cout<< sig[i]<<" "<<std::endl;
//    }
    //////////////////////////////////////////////          
    //                                          //
    // Calculate the ifft of the log magnitude  //
    //                                          //
    //////////////////////////////////////////////
    
    std::vector<double> logmag;
    fftw_complex * in_ =new fftw_complex[N];
    fftw_complex * LogMag =new fftw_complex[N];
    
    fftw_plan p;			//declare the plan (optimized way to calculate the FFT)
    p=fftw_plan_dft_1d(N, LogMag, in_ , FFTW_BACKWARD, FFTW_ESTIMATE);   //This overwrites in and out... so do this before initializing
    
    double temp1;
//    
//    std::cout<<"LogMag"<<std::endl;
    for(int i=0; i< N; i++)
    {   temp1=std::abs( HR[i][0]);
        //std::cout<<temp1<<std::endl;
//        std::cout<<temp1<<std::endl;   
        
        temp1=std::log(temp1);
        //std::cout<<temp1<<std::endl;
        
        logmag.push_back(temp1 ); //log is natural log log10 is 
        LogMag[i][0]=logmag[i];
        LogMag[i][1]=0;
    }
    
    
//    for(int i=0; i<5; i++)
//    {   
//        std::cout<<LogMag[i][0]<<" + "<<LogMag[i][1]<<" i"<<std::endl;
//    }
    //initialize a plan for the FFT /FFTW_ESTIMATE is the fastest one
    fftw_execute(p);		//execute the fft
    fftw_destroy_plan(p);	//deconstruct

    
    
//    std::cout<<"in_"<<std::endl;
//    for(int i=0; i<5; i++)
//    {   tempimag=in_[i][1]/N;
//        tempreal=in_[i][0]/N;
//        
//        std::cout<< tempreal<<" + "<< tempimag<< " i"<<std::endl;
//    }
    
    for(int i=0; i< N; i++)
    {   in_[i][1]=in_[i][1]/N;
        in_[i][0]=in_[i][0]/N;
    }
    //////////////////////////////////////////////////          
    //                                              //
    //    Calculate the fft of ifft of logmag*sig   //
    //                                              //
    //////////////////////////////////////////////////
    
    
    fftw_complex * sig_times_in =new fftw_complex[N];
    fftw_complex * ph =new fftw_complex[N];    
    double temp_sig_times_in_real, temp_sig_times_in_imag;
    
    fftw_plan p1;			//declare the plan (optimized way to calculate the FFT)
    p1=fftw_plan_dft_1d(N, sig_times_in, ph , FFTW_FORWARD, FFTW_ESTIMATE);   //This overwrites in and out... so do this before initializing
    
    for(int i=0; i< N; i++)
    {   
        tempimag=(double)in_[i][1];
        tempreal=(double)in_[i][0];
        temp1=(double)sig[i];
        
        temp_sig_times_in_real=temp1*tempreal;
        temp_sig_times_in_imag=temp1*tempimag;
        sig_times_in[i][0]=temp_sig_times_in_real;
        sig_times_in[i][1]=temp_sig_times_in_imag;

//        if(i<=5)
//        {
//            std::cout<<temp_sig_times_in_real<<" + "<<temp_sig_times_in_imag<<" i"<<std::endl;
//        }
    }
    
    
    
    
    
//    std::cout<<"Sig_times_in"<<std::endl;
//    for(int i=0; i<5; i++)
//    {
//        
//        std::cout<< sig_times_in[i][0]<<" + "<<sig_times_in[i][1]<<" i"<<std::endl;
//    }
    
    //initialize a plan for the FFT /FFTW_ESTIMATE is the fastest one
    fftw_execute(p1);		//execute the fft
    fftw_destroy_plan(p1);	//deconstruct
    
    //////////////////////////////////////////////          
    //                                          //
    //    Scale and complete the minimum phase  //
    //                                          //
    //////////////////////////////////////////////

    
    for(int i=0; i< N; i++) //mult by -j
    {   tempreal=ph[i][0];
        tempimag=ph[i][1];
        
        ph[i][0]=tempimag;
        ph[i][1]=tempreal*-1;  //multipling by negative j 
    }
    
//    std::cout<<"Phase"<<std::endl;
//    for(int i=0; i<5; i++)
//    {
//        std::cout<< ph[i][0]<<" + "<<ph[i][1]<<" i"<<std::endl;
//    }
    //////////////////////////////////////////////          
    //                                          //
    //       Get final time domain impulse      //
    //                                          //
    //////////////////////////////////////////////
    
    
    
    fftw_complex * FreqResp =new fftw_complex[N];
    fftw_complex * y =new fftw_complex[N];

    fftw_plan p2;			//declare the plan (optimized way to 
    p2=fftw_plan_dft_1d(N, FreqResp, y , FFTW_BACKWARD, FFTW_ESTIMATE);   //This overwrites in and out... so do this before initializing
    
   for(int i=0; i< N; i++) //mult by -j    
   {    

       FreqResp[i][0]=std::cos(ph[i][0]);
       FreqResp[i][1]=std::sin(ph[i][0]);
        
       FreqResp[i][0]=FreqResp[i][0]*HR[i][0];    //remember that Xdoublesided is based soley on the input magnitude, the only difference is that it is double sided. 
       FreqResp[i][1]=FreqResp[i][1]*HR[i][0];
    }
    
//    std::cout<<"FreqResp"<<std::endl;
//    for(int i=0; i<5; i++)
//    {
//        tempimag=FreqResp[i][1];
//        tempreal=FreqResp[i][0];
//        
//        std::cout<< tempreal<<" + "<<tempimag<<" i"<<std::endl;
//    }

    //initialize a plan for the FFT /FFTW_ESTIMATE is the fastest one
    fftw_execute(p2);		//execute the fft
    fftw_destroy_plan(p2);	//deconstruct
   
    
////    std::cout<<"y"<<std::endl;
//    for(int i=0; i<5; i++)
//    {   
//        tempimag=y[i][1]/N;
//        tempreal=y[i][0]/N;
////        std::cout<< tempreal<<" + "<<tempimag<<" i"<<std::endl;
//    }
    
    ytrunc.clear();
    for (int i = 0; i<N; i++) //this suggests that each impulse should be less than a second long. 
    {  
        tempreal=y[i][0]/N;
        ytrunc.push_back(tempreal);
     //   std::cout<<tempreal<<std::endl;
    }
    
    delete[] FreqResp;
    delete[] y;
    delete[] sig_times_in;
    delete[] ph;  
    delete[] Xdoublesided;
    delete[] H2;
    delete[] H3;    
    delete[] HR;
    delete[] in_;
    delete[] LogMag;
    

    return;
}