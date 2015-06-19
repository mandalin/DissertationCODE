/*
 *  pointinpoly.h
 *  ISM
 *
 *  Created by Amanda Lind on 3/15/11.
 *  Copyright 2011 Pennsylvania State University. All rights reserved.
 *
 */

bool pointinpoly(position_vector onepoint, std::vector<position_vector> vertices)
{
    /* The points creating the polygon. */
    float x[vertices.size()];
    float y[vertices.size()];
    float x1,x2;
    
    /* The coordinates of the point */
    float px, py;
    
    px=onepoint.x;
    py=onepoint.y;
    
    /* How many times the ray crosses a line-segment */
    int crossings = 0;
    
    /* Coordinates of the points */
    for(int ind=0;ind<vertices.size(); ind++)
    { x[ind] = vertices[ind].x;     
      y[ind] = vertices[ind].y;
    }
    
    /* Iterate through each line */
    for ( int i = 0; i < vertices.size(); i++ ){
        
        /* This is done to ensure that we get the same result when
         the line goes from left to right and right to left */
        if ( x[i] < x[ (i+1)%vertices.size() ] ){
            x1 = x[i];
            x2 = x[(i+1)%vertices.size()];
        } else {
            x1 = x[(i+1)%vertices.size()];
            x2 = x[i];
        }
        
        /* First check if the ray is possible to cross the line */
        if ( px > x1 && px <= x2 && ( py < y[i] || py <= y[(i+1)%vertices.size()] ) ) {
            static const float eps = 0.000001;
            
            /* Calculate the equation of the line */
            float dx = x[(i+1)%vertices.size()] - x[i];
            float dy = y[(i+1)%vertices.size()] - y[i];
            float k;
            
            if ( fabs(dx) < eps ){
                k = INFINITY;   // math.h
            } else {
                k = dy/dx;
            }
            
            float m = y[i] - k * x[i];
            
            /* Find if the ray crosses the line */
            float y2 = k * px + m;
            if ( py <= y2 ){
                crossings++;
            }
        }
    }

   //  printf("                The point is crossing %d lines", crossings);
  //  std::cout<<std::endl;
    if ( crossings % 2 == 1 )
    {

        return true;
        
    }
        else
        return false;
        
  //  printf("\n");

}