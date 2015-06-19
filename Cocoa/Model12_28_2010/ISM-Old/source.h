/*
 *  source.h
 *  ISM
 *
 *  Created by Amanda Lind on 2/28/11.
 *  Copyright 2011 Pennsylvania State University. All rights reserved.
 *
 */


class source{
public:	
	// Overload the default constructor. 
	source() {	source_number=0;
		position.x = 0.0; 
		position.y = 0.0;
		position.z = 0.0;
		order = 0;
		mother_source=NULL;
		mother_source_number=0;
		mother_wall=NULL;
		mother_wall_number=0;
		strength=0.0;
		audible=true;
	legal=true;} ;
	
	// Constructor with parameters. 
	source(double long xpos, double long ypos, double long zpos, unsigned rdr, int mthr_src_nmbr, int mthr_wll_nmbr, long double strngth, bool adbl, bool lgl) 
	{	source_number=0;
		position.x = xpos; 
		position.y = ypos;
		position.z = zpos;
		order = rdr;
		mother_source=NULL;
		mother_source_number=mthr_src_nmbr;
		mother_wall=NULL;
		mother_wall_number=mthr_wll_nmbr;
		strength=strngth;
		audible=adbl;
		legal=lgl;} 
	// Constructor with two parameters. 
	
	unsigned source_number;
	position_vector position;
	unsigned order;
	source* mother_source;
	unsigned mother_source_number;
	wall* mother_wall;
	unsigned mother_wall_number;
	long double strength;
	bool audible;
	bool legal;
};