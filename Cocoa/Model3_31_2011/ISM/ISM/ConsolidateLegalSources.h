//
//  ConsolidateLegalSources.h
//  ISM
//
//  Created by Amanda Lind on 5/17/11.
//  Copyright 2011 Pennsylvania State University. All rights reserved.
//

// This code creates a new vector of sources for sources that are legal.
// Conversely, one could make a structure of pointers to the legal sources. 
// This actually makes the most sence. 

void ConsolidateLegalSources(std::vector<source> sources, std::vector<unsigned> & FinalSourcesIndex)
{
	
	for (int srcindex=0; srcindex<=sources.size() ; srcindex++)
	{
		if (sources[srcindex].legal)
		{	
            FinalSourcesIndex.push_back(srcindex);
		}
	}
    
    return ;
}