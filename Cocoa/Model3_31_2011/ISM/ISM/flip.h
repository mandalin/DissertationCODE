//
//  flip.h
//  ISM
//
//  Created by Amanda Lind on 4/7/11.
//  Copyright 2011 Pennsylvania State University. All rights reserved.
//


std::vector<corner>  flip (std::vector<corner>   corners2flip)
{
    std::vector<corner> flipped_corners;
    
    for( int index=corners2flip.size()-1; index>=0; index--)
    {
        flipped_corners.push_back(corners2flip[index]);
        
    }
    
    return flipped_corners;

    
}