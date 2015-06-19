//
//  UTDDiffractionCoeff.h
//  ISM
//
//  Created by Amanda Lind on 12/4/12.
//  Copyright (c) 2012 Pennsylvania State University. All rights reserved.
//

#ifndef ISM_UTDDiffractionCoeff_h
#define ISM_UTDDiffractionCoeff_h

void UTDDiffractionCoeff(double Phi, double Phi_prime, double alpha, double Beta_o, double s, double k, double & kappa, bool & valid_at_field_point, double & Ed_over_Ei_real, double & Ed_over_Ei_imag)
{   // For now written with Phi only having one value
    // alpha is the interior wedge angle
    // Phi is the diffracted angle
    // Phi_prime is the incident angle
    // Beta_o is the incident angle perpendicular to the axis.  
    // s is the distances of the receiver from Qe
    
    

    double lambda=(2.0*pi)/k;
    double  n, a_plus, a_minu, Li, Lro, Lrn,  Spreading;
    double a_plus_Beta_plus, a_minu_Beta_plus, a_plus_Beta_minu, a_minu_Beta_minu, Beta_plus, Beta_minu;
    int N_plus, N_minu;
    
    // Definition of Parameters
    n=(2.0*pi-alpha)/pi;         //(4.26)
    Beta_plus=Phi+Phi_prime;    
    Beta_minu=Phi-Phi_prime;
    
    // Abort if Parameters fall out of range
    if(Phi<0 || Phi>n*pi)
    { std::cout<<std::endl<<"Phi is outside the allowable range"<<std::endl;
    }
    
    // N is the closest integer satisfying the equation....
    N_plus=round((pi+(Beta_plus))/(2.0*pi*n));        //(4.68-.69) 
    N_minu=round((-pi+(Beta_minu))/(2.0*pi*n));
    
    // Associated Function
    a_plus_Beta_plus= 2.0 * std::pow(std::cos( (2.0*n*pi*N_plus - Beta_plus) /2.0) ,2.0);
    a_minu_Beta_plus= 2.0 * std::pow(std::cos( (2.0*n*pi*N_minu - Beta_plus) /2.0) ,2.0);
    a_plus_Beta_minu= 2.0 * std::pow(std::cos( (2.0*n*pi*N_plus - Beta_minu) /2.0) ,2.0);
    a_minu_Beta_minu= 2.0 * std::pow(std::cos( (2.0*n*pi*N_minu - Beta_minu) /2.0) ,2.0);
    
    // Distance Parameters
    Li= s * std::pow(std::sin(Beta_o), 2.0);
    
    // Spreading Term 
    Spreading = 1/std::sqrt(s);
    
    // Putting all the pieces together
    fftw_complex * D1           =new fftw_complex[1];
    fftw_complex * D2           =new fftw_complex[1];
    fftw_complex * D3           =new fftw_complex[1];
    fftw_complex * D4           =new fftw_complex[1];
    fftw_complex * Dsoft        =new fftw_complex[1];
    fftw_complex * Dhard        =new fftw_complex[1];
    fftw_complex * Propagator   =new fftw_complex[1];
  
    fftw_complex * F1 = new fftw_complex[1];
    fftw_complex * F2 = new fftw_complex[1];
    fftw_complex * F3 = new fftw_complex[1];
    fftw_complex * F4 = new fftw_complex[1];
    
    fftw_complex * Ed_over_Ei = new fftw_complex[1];
    
    double TransFuncArg_a_plus_beta_minu = k*Li*a_plus_Beta_minu;
    double TransFuncArg_a_minu_beta_minu = k*Li*a_minu_Beta_minu;
    double TransFuncArg_a_plus_beta_plus = k*Li*a_plus_Beta_plus;
    double TransFuncArg_a_minu_beta_plus = k*Li*a_minu_Beta_plus;
    
    TransitionFunction(TransFuncArg_a_plus_beta_minu,   F1);
    TransitionFunction(TransFuncArg_a_minu_beta_minu,   F2);
    TransitionFunction(TransFuncArg_a_plus_beta_plus,   F3);
    TransitionFunction(TransFuncArg_a_minu_beta_plus,   F4);
    
    //for(int index=0; index<N; index++)
    //{ 
    
    double coeffreal=((-std::cos(-pi/4))/(2*n*std::sqrt(2*pi*k)*std::sin(Beta_o)));
    double coeffimag=((-std::sin(-pi/4))/(2*n*std::sqrt(2*pi*k)*std::sin(Beta_o)));
    
    //real part
    D1[0][0]= coeffreal * (1.0/std::tan((pi+Beta_minu)/(2*n))) * F1[0][0];     //(6.21)
    D2[0][0]= coeffreal * (1.0/std::tan((pi-Beta_minu)/(2*n))) * F2[0][0];     //(6.22)
    D3[0][0]= coeffreal * (1.0/std::tan((pi+Beta_plus)/(2*n))) * F3[0][0];     //(6.23)
    D4[0][0]= coeffreal * (1.0/std::tan((pi-Beta_plus)/(2*n))) * F4[0][0];     //(6.24)
    
    //imaginary part
    D1[0][1]= coeffimag * (1.0/std::tan((pi+Beta_minu)/(2*n))) * F1[0][1];     //(6.21)
    D2[0][1]= coeffimag * (1.0/std::tan((pi-Beta_minu)/(2*n))) * F2[0][1];     //(6.22)
    D3[0][1]= coeffimag * (1.0/std::tan((pi+Beta_plus)/(2*n))) * F3[0][1];     //(6.23)
    D4[0][1]= coeffimag * (1.0/std::tan((pi-Beta_plus)/(2*n))) * F4[0][1];     //(6.24)
    
    Dsoft[0][0] = D1[0][0] + D2[0][0] - (D3[0][0] + D4[0][0]);     //(6.20)
    Dsoft[0][1] = D1[0][1] + D2[0][1] - (D3[0][1] + D4[0][1]);     //(6.20)
    Dhard[0][0] = D1[0][0] + D2[0][0] + (D3[0][0] + D4[0][0]);
    Dhard[0][1] = D1[0][1] + D2[0][1] + (D3[0][1] + D4[0][1]);
    
    
    Propagator[0][0]=cos(-k*s);
    Propagator[0][1]=sin(-k*s);
    
    CplxMult(Dhard,Propagator, 1, Ed_over_Ei);
    
    Ed_over_Ei[0][0] = Ed_over_Ei[0][0] * Spreading;
    Ed_over_Ei[0][1] = Ed_over_Ei[0][1] * Spreading;
    
    //Test If Valid at Field point
    kappa = k*Li*std::pow(std::sin(Beta_o),2);    //(6.39)
    valid_at_field_point = (kappa >= 1)||((kappa > 3) && ((n>1.5)||(n<.6))); //(4.64)(6.39) 
    Ed_over_Ei_real=Ed_over_Ei[0][0];
    Ed_over_Ei_imag=Ed_over_Ei[0][1];
    
}
    

#endif
