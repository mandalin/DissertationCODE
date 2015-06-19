//
//  MSMOutput.h
//  ISM
//
//  Created by Amanda Lind on 5/17/11.
//  Copyright 2011 Pennsylvania State University. All rights reserved.
//p;
class source_output{
    public:	


    MSMOutput(double fs, std::vector<source_output>) 
	{	
        
    } 
    
    std::vector<source_output>  sources;
    int                         sampling rate;
    std::vector<double>         bin_frequencies;
  
    typedef std::vector<int> SourceNumber_ArrivalIndex;   //the source number and arrival index for sorting. 
    
};