/*
 *  center.h
 *  ISM
 *
 *  Created by Amanda Lind on 3/24/11.
 *  Copyright 2011 Pennsylvania State University. All rights reserved.
 *
 */

position_vector center(wall::wall test)
{	
	std::vector<double> x;
	std::vector<double> y;
	std::vector<double> z;
	std::vector<double> tobesummed, cx_tosum, cy_tosum;


	//Here we make these little x y and z vectors. doubling the first corner as the last corner
	for (int i=0; i<test.corners.size(); i++)
	{	x.push_back(test.corners[i].x);
		y.push_back(test.corners[i].y);
		z.push_back(test.corners[i].z);
	}
	x.push_back(test.corners[0].x);
	y.push_back(test.corners[0].y);
	z.push_back(test.corners[0].z);

	/*for (int i=0; i<test.corners.size(); i++)
	 {		std::cout<<"corner "<<i<<std::endl;
	 std::cout<<"    "<<x[i]<<" x"<<std::endl;
	 std::cout<<"    "<<y[i]<<" y"<<std::endl;
	 std::cout<<"    "<<z[i]<<" z"<<std::endl;
	 }*/	

	double a=0;	
	// this is a weighted integration. 	
	for(int i=0; i<test.corners.size(); i++)
	{	 tobesummed.push_back(x[i]*y[i+1]-x[i+1]*y[i]);
		a=a+.5*tobesummed[i];
		//std::cout<<"    "<<tobesummed[i]<<" tobesummed"<<std::endl;
		//std::cout<<"    "<<a<<" a"<<std::endl;
		}
		//std::cout<<"////////////"<<std::endl;
		
		double cx=0;
		for(int i=0; i<test.corners.size(); i++)
		{	 cx_tosum.push_back((x[i]+x[i+1])*(x[i]*y[i+1]-x[i+1]*y[i]));
			cx=cx+(1/(6*a))*cx_tosum[i];
			//std::cout<<"    "<<cx_tosum[i]<<" cx_tosum"<<std::endl;
			//std::cout<<"    "<<cx<<" cx"<<std::endl;
		}
		//std::cout<<"////////////"<<std::endl;
		
		double cy=0; 
		for(int i=0; i<test.corners.size(); i++)
		{	 cy_tosum.push_back((y[i]+y[i+1])*(x[i]*y[i+1]-x[i+1]*y[i]));
			cy=cy+(1/(6*a))*cy_tosum[i]; 
			//std::cout<<"    "<<cy_tosum[i]<<" cy_tosum"<<std::endl;
			//std::cout<<"    "<<cy<<" cy"<<std::endl;
		}
		
		double cz=test.corners[0].v[2];

		position_vector result(cx, cy, cz);
		return result;
}		


/* MATLAB
 function [cx,cy,cz]=center(corners)
%Given a Plane Structure, This returns the center of gravity ASSUMING it is
%parallel the Z=0 plane. 

%test=[0,0,0;6,0,0;9,3,0;3,3,0];
%test=[0,0,0;4,0,0;4,6,0;0,6,0];
%test_n=cross(test(2,:)-test(1,:),test(3,:)-test(1,:)) ;
%Test=struct('name','test','num_corners',4,'corners',test,'norm_vector',test_n,'normalized_norm_vector',test_n/sqrt(test_n(1)^2+test_n(2)^2+test_n(3)^2),'reflection_coeff',1);

%patch(Test.corners(:,1),Test.corners(:,2),Test.corners(:,3),1)
%corners=Test.corners;
%patch(corners(:,1),corners(:,2),corners(:,3),1)
%hold on

x=corners(:,1); x=[x;x(1)];
y=corners(:,2); y=[y;y(1)];
z=corners(:,3); z=[z;z(1)];

for i=1:length(corners)
tobesummed(i)=(x(i).*y(i+1)-x(i+1).*y(i));
end
A=(1/2)*sum(tobesummed);

for i=1:length(corners)
cx_tosum(i)=(x(i)+x(i+1))*((x(i)*y(i+1)-x(i+1)*y(i)));
end
cx=(1/(6*A))*sum(cx_tosum);

for i=1:length(corners)
cy_tosum(i)=(y(i)+y(i+1))*(x(i)*y(i+1)-x(i+1)*y(i));
end
cy=(1/(6*A))*sum(cy_tosum);
cz=corners(1,3);
*/