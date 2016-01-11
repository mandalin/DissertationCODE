//
//  BTMDiffraction.h
//  ISM
//
//  Created by Amanda Lind on 1/11/13.
//  Copyright (c) 2013 Pennsylvania State University. All rights reserved.
//

#ifndef ISM_BTMDiffraction_h
#define ISM_BTMDiffraction_h

bool BTMDiffraction(unsigned which_case, double theta_w,double ro,double thetao,double r,double theta, double Z,position_vector Ppos, position_vector Qpos, position_vector corner1, position_vector corner2, position_vector least_time_point, double co, double rho, double S, double fsdiff,unsigned Which_SIM__, unsigned Which_IR__, char* simulation_name, const char* directory)

{
    
    
    //   position_vector PposDiff, QposDiff;
    //  PposDiff.assign(12.2,12.21,.01);
    //   QposDiff.assign(12.2,12.21,.01);
    
    
    bool infinite_wedge=false;
    double least_time;
    double edge_distance_a, edge_time_a;
    double edge_distance_b, edge_time_b;
    double temp1, temp2;
    temp1=magnitude(sub(corner1, Ppos));
    temp2=magnitude(sub(corner1, Qpos));
    edge_distance_a = temp1 + temp2;
    temp1=magnitude(sub(corner2, Ppos));
    temp2=magnitude(sub(corner2, Qpos));
    edge_distance_b = temp1 + temp2;
    edge_time_a=edge_distance_a/co;
    edge_time_b=edge_distance_b/co;
    
    ////////////////////////////////////////////////////////
    //      This is For Validation      Fig 2 Medwin 1982 //
    ////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////
    //    S=1.0;
    //    rho=1.2;                                                        //
    //    Which_IR__=1;                                                   //
    //    theta_w=(pi/180.00)*270.0;                                      //
    //    // double ro, thetao, r, theta, Z;                              //
    //    //Source Coordinant in cylindrical (ro, thetao, 0) from Qpos    //
    //    ro=100.0;                                                       //
    //    thetao=pi/4.0;                                                  //
    //    //Receiver Coordinant in cylindrical (r, theta, Z) from Ppos    //
    //    double epsilon=(pi/180.0)*.1;                                   //
    //    theta=((pi/180.0)*225.0)+epsilon;                               //
    //    r=100.0;                                                        //
    //    Z=0;                                                            //
    //    co=340;                                                         //
    //    fsdiff=100000;                                                   //
    //    infinite_wedge=true;                                            //
    //////////////////////////////////////////////////////////////////////
    
    
    ////////////////////////////////////////////////////////
    //      This is For Validation      Fig 8 Medwin 1982 //
    ////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////
    //    S=1.0;                                                          //
    //    rho=1.2;                                                        //
    //    Which_IR__=1;                                                   //
    //    theta_w=(pi/180.00)*360.0;                                      //
    //    // double ro, thetao, r, theta, Z;                              //
    //    //Source Coordinant in cylindrical (ro, thetao, 0) from Qpos    //
    //    ro=.25;                                                         //
    //    thetao=(pi/180.0)*15.0;                                         //
    //    //Receiver Coordinant in cylindrical (r, theta, Z) from Ppos    //
    //    theta=((pi/180.0)*225.0);                                       //
    //    r=.25;                                                          //
    //    Z=0;                                                            //
    //    co=340;                                                         //
    //    fsdiff=80000;                                                   //
    //    infinite_wedge=true;                                            //
    //////////////////////////////////////////////////////////////////////
    
    least_time=(std::sqrt((r+ro)*(r+ro) + Z*Z))/co;
    
    double incident_sound_at_receiver_time=magnitude(sub(Ppos,Qpos))/co;
    double diffraction_delay=least_time-incident_sound_at_receiver_time;
    
    
    std::cout<<"For Simulation Number "<<Which_SIM__<<" Impulse Response Number "<< Which_IR__ <<std::endl;
    std::cout<<"Also know as Simulation: "<<simulation_name<<std::endl;
    std::cout<<"The diffraction delay is: "<<diffraction_delay;
    
    bool IR_written;
    double yarg, y, Beta_num_1, Beta_num_2, Beta_num_3, Beta_num_4 , Beta_denom_1, Beta_denom_2, Beta_denom_3, Beta_denom_4, Beta, p_of_t;
    
    
    //Create Empty IR
    // int Ndiff=end_of_edge_time*fsdiff+10;  //good for finite edges
    double longest_time;
    if(edge_time_a>edge_time_b)
    {   longest_time=edge_time_a;}
    else
    { longest_time=edge_time_b;}
    
    int Ndiff=round(fsdiff);//this could be better...????!!!!
    //Ndiff=100; //For Fig8 Medwin 1982
    
    std::vector<double> ImpulseResponse(Ndiff);
    
    double t, tau, yargtau;
    double source_to_apex_distance=magnitude(sub(Qpos,least_time_point));
    std::cout<<endl<<endl;
    for(int n_diff=1;  n_diff<Ndiff ;n_diff++ )
    {
        t=least_time+n_diff/fsdiff;
        
        yarg=((co*co*t*t) - ((r*r) + (ro*ro) + (Z*Z))) / (2.0*r*ro);
        //yargtau=((co*co*(2.0*(least_time*tau + tau*tau)))/(2.0*r*ro))+1;
        
        if(yarg  < 1)
        {    std::cout<<"Dude, there is an error, because the argument for y is negative and we are not prepared for imaginary number results"<<endl;
            ImpulseResponse[n_diff]=0;
            // return IR_written;
        }
        
        else
        {
            y=acosh(yarg);
            
            Beta_num_1 = sin( (pi / theta_w) * (pi + theta + thetao) );
            Beta_num_2 = sin( (pi / theta_w) * (pi + theta - thetao) );
            Beta_num_3 = sin( (pi / theta_w) * (pi - theta + thetao) );
            Beta_num_4 = sin( (pi / theta_w) * (pi - theta - thetao) );
            
            Beta_denom_1=1.0-(2.0* std::exp((-pi * y) / theta_w) * std::cos( (pi/theta_w) * (pi + theta + thetao)  )) + std::exp((-2.0*pi*y) / theta_w);
            Beta_denom_2=1.0-(2.0* std::exp((-pi * y) / theta_w) * std::cos( (pi/theta_w) * (pi + theta - thetao)  )) + std::exp((-2.0*pi*y) / theta_w);
            Beta_denom_3=1.0-(2.0* std::exp((-pi * y) / theta_w) * std::cos( (pi/theta_w) * (pi - theta + thetao)  )) + std::exp((-2.0*pi*y) / theta_w);
            Beta_denom_4=1.0-(2.0* std::exp((-pi * y) / theta_w) * std::cos( (pi/theta_w) * (pi - theta - thetao)  )) + std::exp((-2.0*pi*y) / theta_w);
            
            Beta= (Beta_num_1/Beta_denom_1) + (Beta_num_2/Beta_denom_2) + (Beta_num_3/Beta_denom_3) + (Beta_num_4/Beta_denom_4);
            
            
            
            //for spherical waves
            //p_of_t=((-S*rho*co)/(4.0*pi*theta_w)) * Beta * (1.0/(r*ro*std::sinh(y))) * std::exp((-pi*y) / theta_w);
            
            //for plane waves
            p_of_t=(source_to_apex_distance*4.0*pi) *((-S*rho*co)/(4.0*pi*theta_w)) * Beta * (1.0/(r*ro*std::sinh(y))) * std::exp((-pi*y) / theta_w);
            
            p_of_t=p_of_t/fsdiff;
            
            //   A  e1_________e2     case 1
            //      e1____A____e2     case 2
            //      e1_________e2 A   case 3
            
            if(! infinite_wedge)
            {
                switch (which_case)
                {
                    case 1:
                        if((t<edge_time_a)||(t>edge_time_b))
                        {   ImpulseResponse[n_diff]=0;}
                        else
                        {   ImpulseResponse[n_diff]=p_of_t/2;}
                        break;
                        
                    case 2:
                        if((t>edge_time_a) || (t>edge_time_b))
                        {   ImpulseResponse[n_diff]=p_of_t/2;}
                        else if((t>edge_time_a) && (t>edge_time_b))
                        {   ImpulseResponse[n_diff]=0;}
                        else
                        {   ImpulseResponse[n_diff]=p_of_t;}
                        break;
                        
                    case 3:
                        if((t<edge_time_b)||(t>edge_time_a))
                        {   ImpulseResponse[n_diff]=0;}
                        else
                        {   ImpulseResponse[n_diff]=p_of_t/2;}
                        break;
                        
                    default: cout << "UnspecifiedCase";
                        break;
                }
            }
            std::cout<<p_of_t<<" ";
            
        }
        
    }
    
    
    //////////////Plane Wave Scaling/////////////////////////
    double incident_pressure_at_apex,Prop_dist;
    position_vector src_to_apex;
    
    src_to_apex=sub(least_time_point,Qpos);
    Prop_dist=magnitude(src_to_apex);
    
    incident_pressure_at_apex=(rho*S/(4*pi*Prop_dist));
    
    /////////////Plane Wave Scaling to Ppos//////////////////
    double incident_pressure_at_ppos,Prop_dist_ppos;
    position_vector src_to_ppos;
    
    src_to_ppos=sub(Ppos,Qpos);
    Prop_dist_ppos=magnitude(src_to_ppos);
    
    incident_pressure_at_ppos=(rho*S/(4*pi*Prop_dist_ppos));
    
    
    /////////////////////////////////////////////////////////
    
    double A,FirstSamp;
    A= S*rho*Beta/(4*pi*theta_w*std::sqrt(2*least_time*ro*r))/incident_pressure_at_ppos;
    FirstSamp=A/incident_pressure_at_ppos;
    
    
    FILE * writeIR;
    writeIR = fopen (simulation_name,"w");
    IR_written=writeIR; //impulse response written successfully ?
    
    if(writeIR)
    {
        fprintf(writeIR,"%f = diffraction delay\n",diffraction_delay  );
        fprintf(writeIR,"%f = incident pressure at Ppos for Source Strength =1\n\n",incident_pressure_at_ppos  );
        
        //  fputs ("y=[",write);
        for(unsigned sample=0; sample<Ndiff; sample++)
        {
            fprintf(writeIR,"%f \n",(ImpulseResponse[sample]));
        }
        // fprintf(write,"];");
        
        fclose(writeIR);
        
    }
    else
    {
        std::cout<<"Couldnt Open FIle"<<std::endl;
    }
    
    //----------------------------------------------------------------------------------------------------------
    
    
    
    
    
    
    
    
    
    
    
    
    return IR_written;
    
    
}
#endif