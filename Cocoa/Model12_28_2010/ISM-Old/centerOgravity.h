/*
 *  centerOgravity.h
 *  ISM
 *
 *  Created by Amanda Lind on 3/24/11.
 *  Copyright 2011 Pennsylvania State University. All rights reserved.
 *
 */


 
position_vector centerOgravity(wall::wall Test)
{
	//calculate the inversion matrices
	boost::numeric::ublas::matrix<double> Transf(3,3), Transfi(3,3);
	bool inversionsuccessful;
	inversionsuccessful=rotate2newFOR(Test, Transf, Transfi);
	
	//rotate all the corners such that the plane is parallel to the ground plane
	int num_corners= Test.corners.size();
	boost::numeric::ublas::matrix<double>  CornerRotated(num_corners,3), CornerTempRotated(1,3), CornerTemp(1,3);
	double initialValues[1][3];
	
	for(int i=0; i<num_corners; i++)
	{	
		initialValues[0][0]=Test.corners[i].v[0];
		initialValues[0][1]=Test.corners[i].v[1];
		initialValues[0][2]=Test.corners[i].v[2];
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
	
	
	//Now make a temporary rotated wall
	std::cout<<"//Now make a temporary rotated wall"<<std::endl<<std::endl;		
	wall RotatedWall;	
	corner temp_corner;
	double temp_x, temp_y, temp_z;
	for(int i=0; i<num_corners; i++)
	{
		std::cout<<CornerRotated(i,0)<<" "<<CornerRotated(i,1)<<" "<<CornerRotated(i,2)<<std::endl;
		temp_x=CornerRotated(i,0);
		temp_y=CornerRotated(i,1);
		temp_z=CornerRotated(i,2);
		temp_corner.assign(temp_x,temp_y,temp_z);
		std::cout<<temp_corner.x<<" "<<temp_corner.y<<" "<<temp_corner.z<<std::endl;
		print(temp_corner);
		
		RotatedWall.corners.push_back(temp_corner);
	}
	RotatedWall.setnorm();	

	//Find the Center
	std::cout<<"//Find the Center"<<std::endl<<std::endl;		
	position_vector rotated_center; 
	rotated_center=center(RotatedWall);
	std::cout<<rotated_center.x<<" "<<rotated_center.y<<" "<<rotated_center.z<<std::endl<<std::endl;	
	
	//Rotate the center back to the original plane
	std::cout<<"//Rotate Center Back"<<std::endl<<std::endl;	
	initialValues[0][0]=rotated_center.x;
	initialValues[0][1]=rotated_center.y;
	initialValues[0][2]=rotated_center.z;
	CornerTemp = boost::numeric::ublas::make_matrix_from_pointer(initialValues);
	CornerTempRotated=boost::numeric::ublas::prod(CornerTemp,Transfi);
	//
	
	for (int i=0; i< 3; i++)
	{	if( (CornerTempRotated(0,i) > 0 && CornerTempRotated(0,i) < 5E-14) || ( CornerTempRotated(0,i) < 0 && CornerTempRotated(0,i) > -5E-14 ))
		{CornerTempRotated(0,i)=0;}
	}
	position_vector result(CornerTempRotated(0,0),CornerTempRotated(0,1),CornerTempRotated(0,2));
	return result;
}
 
 /*
function [cx,cy,cz]=centerOgravity(Test)
 %Calculates the centroid, or center of gravity of a plane in three
 %dimensions
 
 [Transf,Transfi]=rotate2newFOR(Test);
 
 orig_corners=Test.corners;
 
 for(i=1:length(orig_corners))
 corners_rotated(i,:)=orig_corners(i,:)*Transf;
 end
 
 % figure(1)
 % patch(orig_corners(:,1),orig_corners(:,2),orig_corners(:,3),1)
 % xlabel('x'),ylabel('y'),zlabel('z')
 % view([-56 38]);
 % 
 % figure(2)
 % patch(corners_rotated(:,1),corners_rotated(:,2),corners_rotated(:,3),1)
 % hold on
 % xlabel('x'),ylabel('y'),zlabel('z')
 % view([-56 38]);
 % 
 % 
 corners=corners_rotated;
 
 % now that it is parallel to the z=0 plane, we can find the center of 
 % gravity.
 [cx,cy,cz]=center(corners); %calculates the centroid of the rotated plane
 %figure(2)
 %hold on
 %plot3(cx,cy,cz,'ro')
 real_center=[cx,cy,cz]*Transfi;  %rotates the center back into the original 
 cx=real_center(1);
 cy=real_center(2);
 cz=real_center(3);
 %  figure(3)
 %  patch(orig_corners(:,1),orig_corners(:,2),orig_corners(:,3),1)
 %  hold on
 %  xlabel('x'),ylabel('y'),zlabel('z')
 %  view([-56 38]);
 %  plot3(cx,cy,cz,'ro')

*/