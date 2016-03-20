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
    std::vector< double> v;
    double x=NaN;
    double y=NaN;
    double z=NaN;
    
	position_vector(){ x=NaN; y=NaN; z=NaN; v.clear(); v.push_back(x); v.push_back(y); v.push_back(z);};
	
    position_vector(long double xpt, long double ypt, long double zpt){ x=xpt; y=ypt; z=zpt; v.clear(); v.push_back(x); v.push_back(y); v.push_back(z);};
    
    
	void assign ( double xval,  double yval,  double zval)
	{ if(xval>0 && xval<1E-13) {xval=0;} if(yval>0 && yval<1E-13){yval=0;} if(zval>0 && zval<1E-13){zval=0;}
        x=xval; y=yval; z=zval;
        v.clear(); v.push_back(xval); v.push_back(yval); v.push_back(zval); return;}
    
    void assign (position_vector vec)
	{ if(vec.x>0 && vec.x<1E-13) {vec.x=0;} if(vec.y>0 && vec.y<1E-13){vec.y=0;} if(vec.z>0 && vec.z<1E-13){vec.z=0;}
        x=vec.x; y=vec.y; z=vec.z;
        v.clear(); v.push_back(vec.x); v.push_back(vec.y); v.push_back(vec.z); return;}
	
    
	
};

position_vector cross(position_vector a, position_vector b)
{
    position_vector tempa, tempb;
    
    tempa=a;
    tempb=b;
    position_vector crsprdct(a.v[1]*b.v[2]-a.v[2]*b.v[1], a.v[2]*b.v[0]-a.v[0]*b.v[2], a.v[0]*b.v[1]-a.v[1]*b.v[0]);
	return crsprdct;
}

long double magnitude(position_vector a)
{	long double mag=sqrt(a.v[0]*a.v[0]+a.v[1]*a.v[1]+a.v[2]*a.v[2]);
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

position_vector mult( position_vector left,   double right)
{
	position_vector result(left.x * right,left.y * right,left.z * right);
	return result;
}

position_vector add( position_vector left,   position_vector right)
{
	position_vector result(left.x + right.x,left.y + right.y,left.z + right.z);
	return result;
}


long double dot(position_vector left,   position_vector right)
{
	long double result;
	result=left.v[0]*right.v[0] + left.v[1]*right.v[1] + left.v[2]*right.v[2];
	return result;
}

void print(position_vector vec)
{	std::cout<<vec.x<<"i "<<vec.y<<"j "<<vec.z<<"k "<<std::endl;
}
typedef position_vector corner;