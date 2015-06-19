//
//  source_output.h
//  ISM
//
//  Created by Amanda Lind on 5/17/11.
//  Copyright 2011 Pennsylvania State University. All rights reserved.
//



class source_output{
public:	
	// Overload the default constructor. 
	source_output() 
    {	source_number=0;
		position.x = 0.0; 
		position.y = 0.0;
		position.z = 0.0;
		order = 0;
		mother_source_ind=NULL;
		strength=0.0;
		audible=true;
        legal=true;
        mother_wall_ind=NULL;
    }
	
	// Constructor with parameters. 
	source_output(double long xpos, double long ypos, double long zpos, unsigned rdr, int mthr_src_ind, int mthr_wall_ind, long double strngth, bool adbl, bool lgl) 
	{	source_number=0;
		position.x = xpos; 
		position.y = ypos;
		position.z = zpos;
		order = rdr;
		mother_source_ind=mthr_src_ind;
		strength=strngth;
		audible=adbl;
		legal=lgl;
        mother_wall_ind=mthr_wall_ind;
        
    } 
    
	// Constructor with two parameters. 
	
	unsigned source_number;
	position_vector position;
	unsigned order;
	unsigned mother_source_ind;
	long double strength;
	bool audible;
	bool legal;
    unsigned  mother_wall_ind;
    
/// additional members not in the source class//////////////////////////
    std::vector<long double> strength_by_band;
    double delay;
    long double dist_to_rec;
    long double hankel;    
//////////////////////////////////////////////////////////////////////// 
   
    void set_dist_to_rec()
    {}
    
    void set_delay()
    {}
    
    void set_hankel()
    {}
    
    void  set_strength_by_band(std::vector<long double> strength_by_band_)
    {strength_by_band=strength_by_band_;}
    
    
    void  assign(double long xpos, double long ypos, double long zpos, unsigned rdr, unsigned mthr_src_ind, unsigned mthr_wall_ind, long double strngth, bool adbl, bool lgl) 
	{	source_number=0;
		position.x = xpos; 
		position.y = ypos;
		position.z = zpos;
		order = rdr;
		mother_source_ind=mthr_src_ind;
		strength=strngth;
		audible=adbl;
		legal=lgl;
        mother_wall_ind=mthr_wall_ind;
    } 
    
};