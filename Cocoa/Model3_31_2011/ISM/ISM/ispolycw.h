//
//  ispolycw.h
//  ISM
//
//  Created by Amanda Lind on 4/6/11.
//  Copyright 2011 Pennsylvania State University. All rights reserved.
//


//determining if a polygon is CW is simple for a convex polygon, and may be determined by the cross product of two side

//determining if a concave polygon is clockwise/counter-clockwise, however, is a little more complicated: we calculate the polygon area.
//if the polygon area is positive then the polygon is ordered counter clockwise. A negative area indicates the vertices are ordered clockwise


  //  bool ispolycw(std::vector<corner> corners)
  //  {
  //      bool isclockwise;
  //      double a=0;
  //      int num_corners=corners.size();
        
  //      for (int index=0; index<num_corners; index++)
  //      {  
  //          if (index=num_corners-1)
  //              a=a+(corners[index].x * corners[0].y - corners[0].x * corners[index].y);
  //         else
  //              a=a+(corners[index].x * corners[index+1].y - corners[index+1].x * corners[index].y);
  //      }
  //      a=a*.5;
  //      
  //      if(a<0)     isclockwise=true;
  //      else        isclockwise=false;
  //                
  //      return isclockwise;
  //      
  //      
  //  }