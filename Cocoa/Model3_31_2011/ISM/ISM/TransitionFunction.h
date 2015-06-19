//
//  TransitionFunction.h
//  ISM
//
//  Created by Amanda Lind on 12/3/12.
//  Copyright (c) 2012 Pennsylvania State University. All rights reserved.
//

#ifndef ISM_TransitionFunction_h
#define ISM_TransitionFunction_h


void TransitionFunction(double arg, fftw_complex*& result)
{
    double fresnelarg=std::sqrt(2.0*arg/pi);

    double Real_Part_Of_Transition_Function;
    double Imag_Part_Of_Transition_Function;
    double term1, term2, term3, term4;
    
    term1= std::cos(arg)     * (-2*fresnel_s(fresnelarg)+1) ;
    term2= std::sin(arg)     * ( 2*fresnel_c(fresnelarg)-1) ;
    term3= std::cos(arg) * ( -2*fresnel_c(fresnelarg)+1) ; // This Term is Imaginary
    term4= std::sin(arg) * (-2*fresnel_s(fresnelarg)+1) ; // This Term is Imaginary
    
    Real_Part_Of_Transition_Function= std::sqrt(pi*arg/2) * (term1+term2);
    Imag_Part_Of_Transition_Function= std::sqrt(pi*arg/2) * (term3+term4);

    result[0][0]=Real_Part_Of_Transition_Function;
    result[0][1]=Imag_Part_Of_Transition_Function;
    
    //std::cout <<endl<< "The Value of the Transition Function, evaluated at "<<arg<<" = "<<Real_Part_Of_Transition_Function<<" + i "<<Imag_Part_Of_Transition_Function;
}
#endif
