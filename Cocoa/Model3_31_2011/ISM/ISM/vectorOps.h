//
//  vectorOps.h
//  ISM
//
//  Created by Amanda Lind on 6/30/11.
//  Copyright 2011 Pennsylvania State University. All rights reserved.
//


double maximum(std::vector<double> vec)
{   
    double temp_maximum = - std::numeric_limits<double>::max();
    
    for(int i =0; i<vec.size(); i++)
    {   if(vec[i]>temp_maximum)
        {temp_maximum =vec[i];}
    }
    return temp_maximum;
}

double minimum(std::vector<double> vec)
{   
    double temp_minimum = - std::numeric_limits<double>::max();
    
    for(int i =0; i<vec.size(); i++)
    {   if(vec[i]>temp_minimum)
    {temp_minimum =vec[i];}
    }
    return temp_minimum;
}


