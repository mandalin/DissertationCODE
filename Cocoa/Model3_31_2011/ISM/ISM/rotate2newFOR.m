function [Transf,Transfi]=rotate2newFOR(Test); 
% with the input of a plane containing corners, the transformation matrix
% to rotate the corners onto a plane parallel to the Z=0 plane, and the 
% transformation matrix to rotate it back are returned.

%For use in testing : 
%
%projected_corners= [  39.7866    6.8917   -5.8378; 39.7866  -32.8949    4.7720 ; -39.7866  -32.8949    4.7720; -39.7866    6.8917   -5.8378];
%projected_plane_norm=[ 0   -0.2577   -0.9662];
%Test2=struct('name','temp','num_corners',length(projected_corners),'corners',projected_corners,'norm_vector',projected_plane_norm,'normalized_norm_vector',projected_plane_norm);
%xlabel('x'); ylabel('y'); zlabel('z');
%patch(Test.corners(:,1),Test.corners(:,2),Test.corners(:,3),1)


i=[1,0,0];
j=[0,1,0];
k=[0,0,1];

between1n2=[Test.corners(2,:)-Test.corners(1,:)];
o(1,:)=between1n2/sqrt(between1n2(1)^2+between1n2(2)^2+between1n2(3)^2);
o(3,:)=Test.normalized_norm_vector;
o(2,:)=cross(o(1,:),o(3,:));

d=[i;j;k];
alpha_x =acosd(dot(d(1,:),o(1,:)));
beta_x  =acosd(dot(d(2,:),o(1,:)));
gamma_x =acosd(dot(d(3,:),o(1,:)));

alpha_y =acosd(dot(d(1,:),o(2,:)));
beta_y  =acosd(dot(d(2,:),o(2,:)));
gamma_y =acosd(dot(d(3,:),o(2,:)));

alpha_z =acosd(dot(d(1,:),o(3,:)));
beta_z  =acosd(dot(d(2,:),o(3,:)));
gamma_z =acosd(dot(d(3,:),o(3,:)));

temps=[alpha_x, alpha_y, alpha_z; beta_x, beta_y, beta_z; gamma_x,...
	   gamma_y, gamma_z];

if(max(max(imag(temps)~=zeros(3,3)))==1)
display('one of the rotational angles was imaginary, probably a fluke of rounding');
temps
display('This is the real part that was used')
temps=real(temps)
end

alpha_x=real(alpha_x);
alpha_y=real(alpha_y);
alpha_z=real(alpha_z);

beta_x=real(beta_x);
beta_y=real(beta_y);
beta_z=real(beta_z);

gamma_x=real(gamma_x);
gamma_y=real(gamma_y);
gamma_z=real(gamma_z);



Transf=[cosd(alpha_x), cosd(alpha_y), cosd(alpha_z);cosd(beta_x),...
		cosd(beta_y), cosd(beta_z);cosd(gamma_x), cosd(gamma_y),...
		cosd(gamma_z)];
Transfi=inv(Transf);
