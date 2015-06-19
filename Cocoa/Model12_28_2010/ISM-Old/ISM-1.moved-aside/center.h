/*
 *  center.h
 *  ISM
 *
 *  Created by Amanda Lind on 3/24/11.
 *  Copyright 2011 Pennsylvania State University. All rights reserved.
 *
 */

/*
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