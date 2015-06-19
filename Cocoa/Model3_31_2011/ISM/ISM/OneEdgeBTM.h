//
//  OneEdgeBTM.h
//  ISM
//
//  Created by Amanda Lind on 1/14/13.
//  Copyright (c) 2013 Pennsylvania State University. All rights reserved.
//

#ifndef ISM_OneEdgeBTM_h
#define ISM_OneEdgeBTM_h


void OneEdgeBTM(Edge SingleEdge, position_vector Norm_Of_One_Wedge_Face, position_vector Qpos, position_vector Ppos, double co /*soundspeed*/, double fsdiff,unsigned Which_SIM__, unsigned Which_IR__, char* simulation_name, const char* directory,  std::vector<corner> & unique_corners )
{
    
    position_vector source2receiver_vec;
    source2receiver_vec=sub( Ppos, Qpos);
    
    
    
    
    
    //Parameters we need:
    //Source Positon in cylindrical coordinants relative to edge (ro, thetao, 0)
    //Receiver Position in cylindrical coordinants relative to edge (r, theta, Z)
    //Z
    long double Z;
    Z=dot(source2receiver_vec, SingleEdge.edge_vector_normalized);
    position_vector cornerone2source;
    cornerone2source=sub(Qpos,unique_corners[SingleEdge.corner1ind]);
    long double src_dist_to_edge_intercept_from_corner1;
    src_dist_to_edge_intercept_from_corner1=dot(cornerone2source, SingleEdge.edge_vector_normalized);
    position_vector ClosestEdgePoint2Qpos;
    ClosestEdgePoint2Qpos.assign(src_dist_to_edge_intercept_from_corner1*SingleEdge.edge_vector_normalized.x, src_dist_to_edge_intercept_from_corner1*SingleEdge.edge_vector_normalized.y, src_dist_to_edge_intercept_from_corner1*SingleEdge.edge_vector_normalized.z);
    position_vector edge2Qpos;
    edge2Qpos=sub(Qpos,ClosestEdgePoint2Qpos);
    
    long double ro;
    ro=magnitude(edge2Qpos);
    
    long double thetao, thetao_temp;
    edge2Qpos.assign(edge2Qpos.x/ro, edge2Qpos.y/ro, edge2Qpos.z/ro);  //now this is a unit vector
    //Which side of the
    
    
    //WE ASSUME THAT THE CORNERS LISTED IN SingleEdge are rotating around the normal using right hand rule !
    position_vector temp1;  //this is the negative version of the edge vector
    temp1.assign(-SingleEdge.edge_vector_normalized.x, -SingleEdge.edge_vector_normalized.y, -SingleEdge.edge_vector_normalized.z);
    
    position_vector temp2;  //this is the normalized edge2Qposvector
    temp2.assign(edge2Qpos.x/magnitude(edge2Qpos), edge2Qpos.y/magnitude(edge2Qpos), edge2Qpos.z/magnitude(edge2Qpos));
    
    position_vector AlongFaceUnitVector;
    AlongFaceUnitVector=cross(temp1, Norm_Of_One_Wedge_Face);
    
    
    thetao_temp=dot(AlongFaceUnitVector,temp2);
    thetao=acos(thetao_temp);
    
    bool InFront;
    InFront=IsInfront(Qpos, Norm_Of_One_Wedge_Face, unique_corners[SingleEdge.corner1ind],.00001); //the last number is a little buffer, just in case you defined points on the surface
    
    if(!InFront)
    {   thetao=2*pi - thetao;
    }
    
    //So now we have (ro, thetao, 0) and (, , Z)... we still need r and theta
    position_vector cornerone2rec;
    cornerone2rec=sub(Ppos,unique_corners[SingleEdge.corner1ind]);
    long double rec_dist_to_edge_intercept_from_corner1;
    rec_dist_to_edge_intercept_from_corner1=dot(cornerone2rec, SingleEdge.edge_vector_normalized);
    position_vector ClosestEdgePoint2Ppos;
    ClosestEdgePoint2Ppos.assign(rec_dist_to_edge_intercept_from_corner1*SingleEdge.edge_vector_normalized.x, rec_dist_to_edge_intercept_from_corner1*SingleEdge.edge_vector_normalized.y, rec_dist_to_edge_intercept_from_corner1*SingleEdge.edge_vector_normalized.z);
    position_vector edge2Ppos;
    edge2Ppos=sub(Ppos,ClosestEdgePoint2Ppos);
    
    long double r;
    r=magnitude(edge2Ppos);
    
    double theta_temp, theta;
    temp2.assign(edge2Ppos.x/magnitude(edge2Ppos), edge2Ppos.y/magnitude(edge2Ppos), edge2Ppos.z/magnitude(edge2Ppos));
    theta_temp=dot(AlongFaceUnitVector,temp2);
    theta=acos(theta_temp);
    
    InFront=IsInfront(Ppos, Norm_Of_One_Wedge_Face, unique_corners[SingleEdge.corner1ind],.00001); //the last number is a little buffer, just in case you defined points on the surface
    
    if(!InFront)
    {theta=2*pi - theta;
    }
    
    
    bool SuccessfulBTM;
    double rho= 1.2, S=1;
    
    //variables for calculation of the apex point from svensson2006
    double rs, rr, za;
    position_vector apex_point;
    //calculate apex point
    rs=ro;
    rr=r;
    position_vector zvec, zvecnorm;
    zvec=sub(ClosestEdgePoint2Ppos,ClosestEdgePoint2Qpos);
    zvecnorm.assign(zvec.x/magnitude(zvec), zvec.y/magnitude(zvec), zvec.z/magnitude(zvec));
    za=Z*rs/(rs+rr); //from svensson2006, after nothing that zs=0, and zr=z for our setup
    apex_point.assign(za*zvecnorm.x,za*zvecnorm.y,za*zvecnorm.z);
    
    int which_case;
    //so now that we have the two edge points, and the apex point, three cases are possible.
    //   A  e1_________e2     case 1
    position_vector e1_2_A, e1_2_e2;
    double dot_prod;
    e1_2_A=sub(apex_point,unique_corners[SingleEdge.corner1ind]);
    e1_2_e2=sub(unique_corners[SingleEdge.corner2ind],unique_corners[SingleEdge.corner1ind]);
    dot_prod=dot(e1_2_A,e1_2_e2);
    if(dot_prod<0)
    {    which_case=1;
    }
    else
    {
        //      e1____A____e2     case 2
        if(za<Z)
        {   which_case=2;
        }
        //      e1_________e2 A   case 3
        if(za>Z)
        {   which_case=3;
        }
    }
    SuccessfulBTM=  BTMDiffraction(which_case, SingleEdge.theta_w, ro, thetao, r, theta,  Z, Ppos, Qpos, unique_corners[SingleEdge.corner1ind], unique_corners[SingleEdge.corner2ind], apex_point, co,  rho,  S,  fsdiff, Which_SIM__ /*whichsim*/, Which_IR__ /*whichrec*/,simulation_name, directory);
    
    
    
}
#endif