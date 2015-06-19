/*
 *  
 *  ISM
 *
 *  Created by Amanda Lind on 2/24/11.
 *  Copyright 2011 Pennsylvania State University. All rights reserved.
 *
 */

class position_vector{
public:
		std::vector<double> v;
	double x;
	double y;
	double z;
	position_vector(){ x=0.0; y=0.0; z=0.0;v.push_back(x); v.push_back(y); v.push_back(z);};
	position_vector(double xpt, double ypt, double zpt){ x=xpt; y=ypt; z=zpt; v.push_back(x); v.push_back(y); v.push_back(z);};

	
	void assign (double xval, double yval, double zval)
	{ if(xval>0 && xval<1E-13) {xval=0;} if(yval>0 && yval<1E-13){yval=0;} if(zval>0 && zval<1E-13){zval=0;}
	x=xval; y=yval; z=zval; v.empty(); v[0]=(xval); v[1]=yval; v[2]=zval; return;}
	
	
};

position_vector cross(position_vector a, position_vector b)
{	position_vector crsprdct(a.v[1]*b.v[2]-a.v[2]*b.v[1], a.v[2]*b.v[0]-a.v[0]*b.v[2], a.v[0]*b.v[1]-a.v[1]*b.v[0]);
	return crsprdct;
}

double magnitude(position_vector a)
{	double mag=sqrt(a.v[0]*a.v[0]+a.v[1]*a.v[1]+a.v[2]*a.v[2]);
	return mag;
}

position_vector sub( position_vector left,   position_vector right) 
{
	position_vector result(left.x - right.x,left.y - right.y,left.z - right.z);
	return result;
}

position_vector mult( position_vector left,   position_vector right) 
{
	position_vector result(left.x * right.x,left.y * right.y,left.z * right.z);
	return result;
}

position_vector add( position_vector left,   position_vector right) 
{
	position_vector result(left.x + right.x,left.y + right.y,left.z + right.z);
	return result;
}


double dot(position_vector left,   position_vector right)
{
	double result;
	result=left.v[0]*right.v[0] + left.v[1]*right.v[1] + left.v[2]*right.v[2];
	return result;
}



void print(position_vector vec)
{	std::cout<<vec.x<<"i "<<vec.y<<"j "<<vec.z<<"k "<<std::endl;
}
typedef position_vector corner;