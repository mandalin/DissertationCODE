//
//  planeunion.h
//  ISM
//
//  Created by Amanda Lind on 4/13/11.
//  Copyright 2011 Pennsylvania State University. All rights reserved.
//
//
//  planeunion.h
//  ISM
//
//  Created by Amanda Lind on 4/6/11.
//  Copyright 2011 Pennsylvania State University. All rights reserved.
//


//take care when calling this function, that the coners defining each wall only contain one polygon !?

//this code really prefers if the two are co-planar....this is becaus we dont know if the rotation is clockwise or counter clockwise

void planeunion(wall & wall1, wall & wall2, std::vector<corner> & unioncorners,  std::vector<int> & numpointsperpoly)
{   std::vector<corner> orig_corners1;
    std::vector<corner> orig_corners2;
    std::vector<corner> rotated_corners1;
    std::vector<corner> rotated_corners2;
    
    orig_corners1=wall1.corners;
    orig_corners2=wall2.corners;
    

    const int numcorners1=orig_corners1.size();
    const int numcorners2=orig_corners2.size();
    
    boost::numeric::ublas::matrix<double> Transf1(3,3), Transfi1(3,3);
    boost::numeric::ublas::matrix<double> Transf2(3,3), Transfi2(3,3);
    boost::numeric::ublas::matrix<double> Rotated_corn1(numcorners1,3), Rotated_corn2(numcorners2,3);
 //   boost::numeric::ublas::matrix<double> Orig_corn1(numcorners1,3), Orig_corn2(numcorners2,3);
    
//    double initialValues1[numcorners1][3];
//    for(int index=0; index<numcorners1; index++)
//    {   initialValues1[index][0]=orig_corners1[index].x;
//        initialValues1[index][1]=orig_corners1[index].y;
//        initialValues1[index][2]=orig_corners1[index].z;
//    }
//    
//    
//    double initialValues2[numcorners2][3];    
//    for(int index=0; index<numcorners2; index++)
//    {   initialValues2[index][0]=orig_corners2[index].x;
//        initialValues2[index][1]=orig_corners2[index].y;
//        initialValues2[index][2]=orig_corners2[index].z;
//    }
//    
//    
//    MakeMatrix(orig_corners1,Orig_corn1); //in storage_adapters.hpp
//    MakeMatrix(orig_corners2,Orig_corn2); //in storage_adapters.hpp
    
    

    boost::numeric::ublas::matrix<double> Orig_corn1 (numcorners1, 3);
    for (unsigned i = 0; i < Orig_corn1.size1 (); ++ i)
    {    Orig_corn1(i, 0)=orig_corners1[i].x;
         Orig_corn1(i, 1)=orig_corners1[i].y;
         Orig_corn1(i, 2)=orig_corners1[i].z;
    }

    boost::numeric::ublas::matrix<double> Orig_corn2 (numcorners2, 3);
    for (unsigned i = 0; i < Orig_corn2.size1 (); ++ i)
    {    Orig_corn2(i, 0)=orig_corners2[i].x;
        Orig_corn2(i, 1)=orig_corners2[i].y;
        Orig_corn2(i, 2)=orig_corners2[i].z;
    }

    
    
    
//    std::cout<<" Find the Union between two planes, which contains the following corners "<<std::endl;
//     std::cout<<"   New Mother Wall"<<std::endl; 
//    std::cout << Orig_corn1 << std::endl;
//    std::cout<<"    Projected Field Angle from previous source & mother wall"<<std::endl; 
//    std::cout << Orig_corn2 << std::endl;

    
    //Obtain transfer functions for the rotations
    rotate2newFOR(wall1,Transf1,Transfi1);
    //rotate2newFOR(wall2,Transf2,Transfi2); should be identical to Transf1 and Transfi1 
    
//     std::cout<<std::endl;
//    
//    
//    std::cout<<" The transformation matrices which rotate these walls to be parallel with the z=0 plane are as follows "<<std::endl;
//    
    for(int i=0; i<3; i++ )
    {
        if(std::abs(Transf1(i,0))<1e-16)
        {Transf1(i,0)=0;}
        if(std::abs(Transf1(i,1))<1e-16)
        {Transf1(i,1)=0;}
        if(std::abs(Transf1(i,2))<1e-16)
        {Transf1(i,2)=0;}
        
        //std::cout<<Transf1(i,0)<<" "<<Transf1(i,1)<<" "<<Transf1(i,2)<<std::endl;
    }
    
    

    
    Rotated_corn1=boost::numeric::ublas::prod(Orig_corn1,Transf1);
    Rotated_corn2=boost::numeric::ublas::prod(Orig_corn2,Transf1);
    
    corner tempcorner;
    for(int index=0; index<numcorners1; index++)
    {           
        tempcorner.assign(Rotated_corn1(index,0),Rotated_corn1(index,1),Rotated_corn1(index,2));
        rotated_corners1.push_back(tempcorner);
    }
    
    for(int index=0; index<numcorners2; index++)
    {
        tempcorner.assign(Rotated_corn2(index,0),Rotated_corn2(index,1),Rotated_corn2(index,2));
        rotated_corners2.push_back(tempcorner);
    }
    
   // std::cout<<" Rotated Corners, Plane 1 contains the following corners "<<std::endl;
    for(int i=0; i<rotated_corners1.size(); i++)
    {//   std::cout<<rotated_corners1[i].x<<" "<<rotated_corners1[i].y<<" "<<rotated_corners1[i].z<<std::endl;
    }
    //std::cout<<"                                    Plane 2 contains the following corners "<<std::endl;
    for(int i=0; i<rotated_corners2.size(); i++)
    {//    std::cout<<rotated_corners2[i].x<<" "<<rotated_corners2[i].y<<" "<<rotated_corners2[i].z<<std::endl;
    }   
    
    position_vector v1,v2,normr;
    double magnitude;
    
    v1=sub(rotated_corners1[0],rotated_corners1[1]);
    v2=sub(rotated_corners1[3],rotated_corners1[2]);
    normr=cross(v1,v2);
    magnitude=pyth_sum(normr.v);
    normr.assign(normr.x/magnitude, normr.y/magnitude, normr.z/magnitude);
    
    //c1=round(corners_rotated1(:,1:2));%we dont care about precision higher than a meter..
    //c2=round(corners_rotated2(:,1:2));%
    
    
    
    //these rotated corners now represent 2Dpolygons !
    //how to represent them in the boost library ?
    
    std::vector<corner> unioncorners_rot;
    
    TwodPolygonAnd(rotated_corners1,rotated_corners2, unioncorners_rot, numpointsperpoly );
    //so now we have the corners representing the union of the two planes and we need to rotate them back to the 3D realm
    
    
    unioncorners.clear();
    if (numpointsperpoly.size()==0)
    {   return;
    }   
    
    //if there is only one polygon
    if (numpointsperpoly.size()==1)
    {
        boost::numeric::ublas::matrix<double> Union_Corners_Rot(numpointsperpoly[ 0 ],3);
        boost::numeric::ublas::matrix<double> Union_Corners(numpointsperpoly[ 0 ],3);
    
        MakeMatrix(unioncorners_rot, Union_Corners_Rot); //in storage_adapters.hpp
        
        Union_Corners=boost::numeric::ublas::prod( Union_Corners_Rot, Transfi1);

        for(int index=0; index<numpointsperpoly[0]; index++)
        {
            tempcorner.assign(Union_Corners(index,0),Union_Corners(index,1),Union_Corners(index,2));
            unioncorners.push_back(tempcorner);
        }
        return;
     }
    
    //if there are many polygon, do this for each     
    else;
   {   //!Achtung!  
       std::cout<<"OH MY, The projection of the field angle on one of the walls makes more than one polygon, you better write this part of the code !"<<std::endl;
//        for(int polynum=0; polynum<numpointsperpoly.size(); polynum++)
//        {
//            
//        }
       return;
//
   }   
    
}
