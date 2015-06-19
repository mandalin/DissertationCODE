//
//  OneEdgeUTD.h
//  ISM
//
//  Created by Amanda Lind on 1/9/13.
//  Copyright (c) 2013 Pennsylvania State University. All rights reserved.
//

#ifndef ISM_OneEdgeUTD_h
#define ISM_OneEdgeUTD_h

bool OneEdgeUTD(Edge SingleEdge, position_vector Norm_Of_One_Wedge_Face, position_vector Qpos, position_vector Ppos, double co /*soundspeed*/, double fsdiff,unsigned Which_SIM__, unsigned Which_IR__, char* simulation_name, const char* directory,  std::vector<corner> unique_corners )
{
    
    
    
    //THIS STUFF COPIED FROM ONEEdgeBTM
    
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
    
    //This stuff unique to UTD
    double Phi,  Phi_prime,  alpha,  Beta_o,  s,  k, kappa ;
    position_vector s_vec, s_prime_vec, s_vec_normalized, s_vec_prime_normalized, e, Qe;
    bool valid_at_field_point;
    //Calculate Qes
    //Draw mental line from source to receiver
    //Mentally draw line that is edge
    //Find the vector perpendicular to both lines (cross product)
    //Find the distance between the two parrallel planes including each line (both share the same normal)
    //Translate the S->R line such that it is in the same plane with the edge line
    //Find their intersection.
    
    e.assign(SingleEdge.edge_vector_normalized);
    
    Qe.assign(apex_point);
    alpha=SingleEdge.alpha_w; //This is the solid angle of the wedge.
    //Calculate S
    s_prime_vec=sub(apex_point,Qpos);  //These correspond to Fig 4.5 Mcnamera
    s_vec_prime_normalized.assign(s_prime_vec.x/magnitude(s_vec), s_prime_vec.y/magnitude(s_vec), s_prime_vec.z/magnitude(s_vec));
    
    s_vec=sub(Ppos,apex_point);
    s=magnitude(s_vec);
    s_vec_normalized.assign(s_vec.x/s, s_vec.y/s, s_vec.z/s);
    //Calculate Beta_o
    
    double cos_Beta_o;                  //These correspond to eq 4.19 Mcnamera
    cos_Beta_o=dot(s_vec_normalized,e);
    Beta_o=acos(cos_Beta_o);
    
    if(Beta_o<0 || Beta_o>pi)
    {   std::cout<<" Beta_o is out of range"<<std::endl;
    }
    
    //Calculate Phi
    Phi=theta;
    //Calculate Phi'
    Phi_prime=thetao;
    //Define Frequencies
    const double pi = boost::math::constants::pi<double>();
    double fs=48000;
    double dt=1/fs;
    double T=1;         //seconds of PBN defined up top.
    int N=std::ceil(T/dt);
    T=N*dt;             //fix because of rounding.
    double df=1/(N*dt);
    
    std::vector<double> freqdom_single_sided;
    std::vector<double> freqdom_double_sided;
    
    for(int i=0;i<=N/2;i++)
    {    freqdom_single_sided.push_back(i*df);
    }
    
    for(int i=0;i<=N/2;i++)
    {    freqdom_double_sided.push_back(i*df);
    }
    
    if(N%2) //if N is odd
        for(int i=0; i<N/2;i++)
        {   freqdom_double_sided.push_back(-df*(std::floor(N/2)-i));
        }
    else
        for(int i=1; i<N/2;i++)
        {   freqdom_double_sided.push_back(-df*((N/2)-i));
        }
    
    
    //time domain
    std::vector<double> time_dom;
    for(int i=0; i<freqdom_double_sided.size(); i++)
    {      time_dom.push_back(i*dt);
    }
    
    //What does a perfect impulse look like ?
    int Nss=freqdom_single_sided.size();
    
    
    
    double Ed_over_Ei_real, Ed_over_Ei_imag;
    //Define kappa vector
    std::vector<double> kappa_vec;
    std::vector<double> valid_vec;
    
    //Where should UTD coeffs go
    fftw_complex* Ed_over_Ei = new fftw_complex[Nss];
    fftw_complex* ir = new fftw_complex[N];
    
    //set DC component to zero
    Ed_over_Ei[0][0]=0;
    Ed_over_Ei[0][1]=0;
    
    for(int i=1; i<Nss; i++)
    {
        k=(freqdom_double_sided[i]*2*pi)/co;
        UTDDiffractionCoeff(Phi,  Phi_prime, alpha,  Beta_o, s, k, kappa, valid_at_field_point, Ed_over_Ei_real, Ed_over_Ei_imag);
        kappa_vec.push_back(kappa);
        valid_vec.push_back(valid_at_field_point);
        Ed_over_Ei[i][0]=Ed_over_Ei_real;
        Ed_over_Ei[i][1]=Ed_over_Ei_imag;
    }
    
    x_from_X ( Ed_over_Ei, ir, freqdom_single_sided.size(), df, dt);
    
    //////////////////WriteOutputFile
    
    FILE * writeIR;
    writeIR = fopen (simulation_name,"w");
    bool IR_written;
    IR_written=writeIR; //impulse response written successfully ?
    
    if(writeIR)
    {
        //fprintf(writeIR,"%f \n",diffraction_delay  );
        //fprintf(writeIR,"%f \n\n",incident_pressure_at_apex  );
        
        //  fputs ("y=[",write);
        for(unsigned sample=0; sample<N; sample++)
        {
            fprintf(writeIR,"%f \n",ir[sample][0]);
        }
        // fprintf(write,"];");
        
        fclose(writeIR);
        
    }
    else
    {
        std::cout<<"Couldnt Open FIle"<<std::endl;
    }
    
    
    return IR_written;
    
    
}
#endif