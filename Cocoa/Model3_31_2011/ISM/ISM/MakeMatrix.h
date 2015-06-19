//
//  MakeMatrix.h
//  ISM
//
//  Created by Amanda Lind on 4/12/11.
//  Copyright 2011 Pennsylvania State University. All rights reserved.
//

void  MakeMatrix(std::vector<corner> orig_corners1, boost::numeric::ublas::matrix<double> & Orig_corn1)
{
    const int numcorners1=orig_corners1.size();
    
for (unsigned i = 0; i < numcorners1; ++ i)
    {    Orig_corn1(i, 0)=orig_corners1[i].x;
        Orig_corn1(i, 1)=orig_corners1[i].y;
        Orig_corn1(i, 2)=orig_corners1[i].z;
    }
      
}


//
//
//double a11=std::cos(alpha_xr);
//double a12=std::cos(alpha_yr);
//double a13=std::cos(alpha_zr);
//double a21=std::cos(beta_xr);
//double a22=std::cos(beta_yr);
//double a23=std::cos(beta_zr);
//double a31=std::cos(gamma_xr);
//double a32=std::cos(gamma_yr); 
//double a33=std::cos(gamma_zr) ;
//
//double initialValues[3][3] = {
//    a11, a12, a13,
//    a21, a22, a23,
//    a31, a32, a33
//};