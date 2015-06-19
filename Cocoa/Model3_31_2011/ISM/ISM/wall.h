/*
 *  wall.h
 *  ISM
 *
 *  Created by Amanda Lind on 2/28/11.
 *  Copyright 2011 Pennsylvania State University. All rights reserved.
 *
 */

//#include "position_vector_class.h" this needs to be included first

class wall{
public:
    unsigned num;
    bool floorplane;
    unsigned num_corners;
	position_vector normal;
    position_vector center;
    std::vector<double> reflection_coeff;
    std::vector<double> reflection_coeff_frequencies;
    std::vector<corner> corners;
    std::vector<int> mother_wall_numpointsperpoly;
    std::vector<unsigned> corner_indices;
    static std::vector<corner> unique_corners;   //the use of the word static here means that all instances of wall share the same value here.
    
    
	wall()
    { num=0;
        normal.assign(NaN,NaN,NaN);};
    
    wall(unsigned indices[],unsigned num_corners_)
    {   num=0; normal.assign(NaN,NaN,NaN);
        num_corners=num_corners_;
        floorplane=false;
        
        for(int i=0; i<num_corners;i++)
        { corner_indices.push_back(indices[i]);
        }
        
    }
    
    
    void assign(wall w)   //copy constructor
    {
        
        num=w.num;
        normal.assign(w.normal.x,w.normal.y,w.normal.z);
        num_corners=w.num_corners;
        floorplane=w.floorplane;
        corners.clear();
        for(int i=0; i<w.num_corners;i++)
        {   corner_indices.push_back(w.corner_indices[i]);
            corners.push_back(unique_corners[w.corner_indices[i]]);
        }
        return;
        
        
        
    };
    
    
    
    
	void setnorm()
	{	position_vector tempnorm;
		double tempmag;
		tempnorm= cross(sub(corners[1],corners[0]), sub(corners[2],corners[0]));
		tempmag=pyth_sum(tempnorm.v);
        
        normal.assign(tempnorm.v[0]/tempmag,tempnorm.v[1]/tempmag,tempnorm.v[2]/tempmag);
	}
    
    void reorder_corners()
	{
        position_vector tempnorm;
		double tempmag;
        bool flipped;
        
		tempnorm= cross(sub(corners[1],corners[0]), sub(corners[2],corners[0]));
		tempmag=pyth_sum(tempnorm.v);
        tempnorm.assign(tempnorm.v[0]/tempmag,tempnorm.v[1]/tempmag,tempnorm.v[2]/tempmag);
        
        
        if(tempnorm.x<.00001)
        {  tempnorm.x=0;}
        if(tempnorm.y<.00001)
        {  tempnorm.y=0;}
        if(tempnorm.z<.00001)
        {  tempnorm.z=0;}
        
        if(normal.x<.00001)
        {  normal.x=0;}
        if(normal.y<.00001)
        {  normal.y=0;}
        if(normal.z<.00001)
        {  normal.z=0;}
        
        flipped=!( (tempnorm.x >= 0) &&  (normal.x >= 0) );
        
        flipped=(!( (tempnorm.y >= 0) &&  (normal.y >= 0) )) || flipped;
        
        flipped=(!( (tempnorm.z >= 0) &&  (normal.z >= 0) )) || flipped;
        
        if(flipped)
        {    reverse(corners.begin(), corners.end());
        }
        
	}
    
    //void assign_corner_indices();
    
};