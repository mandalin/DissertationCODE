/*
 *  pointinplane.h
 *  ISM
 *
 *  Created by Amanda Lind on 3/16/11.
 *  Copyright 2011 Pennsylvania State University. All rights reserved.
 *
 */

//code assumes that the point is within the plane. 

bool pointinplane(position_vector pointposition,wall::wall Plane)
{
	int num_corners = Plane.corners.size(); 

	boost::numeric::ublas::matrix<double> Transf(3,3), Transfi(3,3), CornerTemp(1,3), CornerTempRotated(1,3);
	boost::numeric::ublas::matrix<double>  CornerRotated(num_corners,3);
	std::vector<corner> orig_corners;
		orig_corners=Plane.corners;


	rotate2newFOR(Plane,Transf,Transfi);

	double initialValues[1][3]; //this is where we will put the corners in matrix form. 
	position_vector point_rotated;	

	//rotate all the corners such that the plane is parallel to the ground plane
	for(int i=0; i<num_corners; i++)
	{	
		initialValues[0][0]=orig_corners[i].v[0];
		initialValues[0][1]=orig_corners[i].v[1];
		initialValues[0][2]=orig_corners[i].v[2];
		CornerTemp = boost::numeric::ublas::make_matrix_from_pointer(initialValues); //in storage_adapters.hpp
std::cout<<"-------------"<<std::endl;
std::cout<<CornerTemp<<std::endl<<std::endl;		
		CornerTempRotated=boost::numeric::ublas::prod(CornerTemp,Transf);
std::cout<<CornerTempRotated<<std::endl<<std::endl;	
		CornerRotated(i,0)=CornerTempRotated(0,0);
		CornerRotated(i,1)=CornerTempRotated(0,1);
		CornerRotated(i,2)=CornerTempRotated(0,2);
std::cout<<CornerRotated<<std::endl<<std::endl;		
	}
std::cout<<"ALL ROTATED CORNERS"<<std::endl;
	
	std::vector<corner> rotated_corners;
	rotated_corners.empty();
	//corner corner_rotated[num_corners];
	double temp_x, temp_y, temp_z;
	corner temp_corner;
	
	for(int i=0; i<num_corners; i++)
	{	//corner_rotated[i].assign(CornerRotated(i,0),CornerRotated(i,1),CornerRotated(i,2));
		std::cout<<CornerRotated(i,0)<<" "<<CornerRotated(i,1)<<" "<<CornerRotated(i,2)<<std::endl;
		temp_x=CornerRotated(i,0);
				temp_y=CornerRotated(i,1);
				temp_z=CornerRotated(i,2);
		temp_corner.assign(temp_x,temp_y,temp_z);
		std::cout<<temp_corner.x<<" "<<temp_corner.y<<" "<<temp_corner.z<<std::endl;
		print(temp_corner);
		
		rotated_corners.push_back(temp_corner);//this line broken

	}
std::cout<<"ALL ROTATED CORNERS IN VECTOR FORM"<<std::endl;	
		for(int i=0; i<num_corners; i++)
		{print(rotated_corners[i]);
			std::cout<<rotated_corners[i].v[0]<<" " <<rotated_corners[i].v[1]<<" "<<rotated_corners[i].v[2]<<std::endl;
		} 
	
	//rotate the original point to also meet that plane
	initialValues[0][0]=pointposition.v[0];
	initialValues[0][1]=pointposition.v[1];
	initialValues[0][2]=pointposition.v[2];
	CornerTemp = boost::numeric::ublas::make_matrix_from_pointer(initialValues); //in storage_adapters.hpp
std::cout<<CornerTemp<<std::endl;
	CornerTempRotated=boost::numeric::ublas::prod(CornerTemp,Transf);
	point_rotated.assign(CornerTempRotated(0,0),CornerTempRotated(0,1),CornerTempRotated(0,2));


	//% so now we have simple 2 dimensional thing....	
	bool pointinside;
	std::cout<<"====The Rotated Point Is:"<<std::endl;
	print(point_rotated);
	std::cout<<"====The Rotated Corners Are:"<<std::endl;
	for(int i=0; i< rotated_corners.size(); i++)
	{	print(rotated_corners[i]);
	}
	
	pointinside=pointinpoly(point_rotated, rotated_corners);

	return pointinside;

}