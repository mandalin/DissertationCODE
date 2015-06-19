/*
 *  pyth_sum.h
 *  ISM
 *
 *  Created by Amanda Lind on 12/7/10.
 *  Copyright 2010 Pennsylvania State University. All rights reserved.
 *
 */

double pyth_sum (std::vector<double> a)
{
	double pythagorean_sum=0;
	
	for(int i=0; i < a.size(); i++)
	{ 
		pythagorean_sum=pythagorean_sum+a[i]*a[i];
	}
	
	pythagorean_sum=std::sqrt(pythagorean_sum);
	
	
	return (pythagorean_sum);
}