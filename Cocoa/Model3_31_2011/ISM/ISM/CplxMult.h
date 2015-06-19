//
//  CplxMult.h
//  ISM
//
//  Created by Amanda Lind on 6/29/11.
//  Copyright 2011 Pennsylvania State University. All rights reserved.
//


void CplxMult(fftw_complex* num1, fftw_complex* num2,int N, fftw_complex*& result)
{   double mag1, mag2, phi1, phi2, magr,phir; 
    
    for(int index=0; index<N; index++)
    {   mag1=sqrt(num1[index][0]*num1[index][0]+num1[index][1]*num1[index][1]);
        mag2=sqrt(num2[index][0]*num2[index][0]+num2[index][1]*num2[index][1]);
        
        phi1=std::atan(num1[index][1]/num1[index][0]);
        phi2=std::atan(num2[index][1]/num2[index][0]);
        
        magr=mag1*mag2;
        phir=phi1+phi2;
        
        result[index][0]=magr*std::cos(phir);
        result[index][1]=magr*std::sin(phir);
    }
    return;
    
}

