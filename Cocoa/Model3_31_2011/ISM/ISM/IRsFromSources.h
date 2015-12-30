//
//  IRsFromsources.h
//  ISM
//
//  Created by Amanda Lind on 12/15/11.
//  Copyright 2011 Pennsylvania State University. All rights reserved.
//

#ifndef ISM_IRsFromsources___h
#define ISM_IRsFromsources___h

bool IRsFromSources(position_vector Ppos__, std::vector<unsigned> LegalSourceIndices__, std::vector<source> sources__, std::vector<wall> planes__, unsigned num_original_walls__, double phi__, double theta_i__, unsigned Which_SIM__, unsigned Which_IR__, double co__, double s_, bool dont_use_filtering__, bool use_R_coeffs__, bool use_R_coeffs_and_Disk_Approx__, char* simulation_name, const char* directory)


{
    std::cout<<"~~~~~~~~~~~~~~Consolidating Effective sources~~~~~~~~~~~~~~"<<std::endl;
    
    print(Ppos__);
    
    
    bool temp_audible;
    
    std::vector<unsigned> EffectiveSourceIndices;   
    EffectiveSourceIndices.clear();
    
    //Push the indices of effective sources into the array
    for(int i=0; i<LegalSourceIndices__.size(); i++)
    {  
        std::cout<<"Source # "<<LegalSourceIndices__[i]<<std::endl;
        
        temp_audible=IsSourceEffective (sources__ /*sources__*/, planes__ /*planes__*/,LegalSourceIndices__[i], Ppos__, num_original_walls__);
        
        sources__[LegalSourceIndices__[i]].audible=temp_audible;
        
        if(temp_audible)
        {    EffectiveSourceIndices.push_back(LegalSourceIndices__[i]);}
        
    }
    
    
    //Prints Effective Sources
    for(int effective_ind=0 ; effective_ind < EffectiveSourceIndices.size() ; effective_ind++)
    {   sources__[EffectiveSourceIndices[effective_ind]].print(sources__,planes__,num_original_walls__);
        
    }
    
    /// Append Effective Source info to Simulation File. 
    
    
    
    FILE * write;
    
    // const char* directory = "/Users/mandalin/Desktop/Xcode Output/";
    
    const char* sources_ = "sources_";
    
    
    //Write A file to hoLf the information of source position 
    char* whole_filename_src = (char *) malloc(sizeof(char)*400);
    char * arrivalaz= (char*)malloc(200*sizeof(char));
    char * arrivalel= (char*)malloc(200*sizeof(char));
    char * sim_number= (char*)malloc(10*sizeof(char));
    
    double azimuth_angle= phi__;
    double elevation_angle=theta_i__;
    int sim_num=Which_SIM__;
    
    snprintf(arrivalaz, 79, "%f", azimuth_angle);
    snprintf(arrivalel, 79, "%f", elevation_angle);
    snprintf(sim_number, 79, "%i", sim_num);
    
    strcat(whole_filename_src,directory);
    strcat(whole_filename_src,simulation_name);
    strcat(whole_filename_src,"_");
    strcat(whole_filename_src,sim_number);
    strcat(whole_filename_src,"_");
    strcat(whole_filename_src,sources_);
    strcat(whole_filename_src,arrivalaz);
    strcat(whole_filename_src," az_");
    strcat(whole_filename_src,arrivalel);
    strcat(whole_filename_src," el.txt");    
    
    write = fopen (whole_filename_src,"a");
    
    if(write)
    {
        fprintf(write, "\n\n Audible Sources for IR number %i \n", Which_IR__);
        for(int sourceNumber=0; sourceNumber<EffectiveSourceIndices.size(); sourceNumber++)
        {
            fprintf(write, " %i", EffectiveSourceIndices[sourceNumber]);
            
        }
    }
    fclose(write);

    
    //
    ////////% *-9.------Make Pretty Picutres-------------------------------------*
    ////////% Plot Geometry. 
    
     //   plot_GeometryGeneral(planes__, sources__);
    
    
     //plot_SingleSource(planes__, sources__, sourceindex);
    
    
    ////////% *-10.------Determine Arrival Time For sources__-------------------------------------*
    ////    
    ////  
    
    position_vector vector_to_Ppos___from_Qpos;
    std::vector<long double> distance_from_Ppos__;
    std::vector<long double> path_difference;
    long double original_src_prop_distance;
    

    
    long double tempx, tempy, tempz;
    
    std::vector<double> delays;
    
    //Calculate the propogation distance from the initial source
    vector_to_Ppos___from_Qpos.assign(Ppos__.x-sources__[0].position.x,
                                      Ppos__.y-sources__[0].position.y,
                                      Ppos__.z-sources__[0].position.z);
    
    tempx=vector_to_Ppos___from_Qpos.x;
    tempy=vector_to_Ppos___from_Qpos.y;
    tempz=vector_to_Ppos___from_Qpos.z;
    
    original_src_prop_distance = std::sqrt(tempx*tempx + tempy*tempy + tempz*tempz);
    
    
    for(int effective_ind=0; effective_ind<EffectiveSourceIndices.size(); effective_ind++)
    {  // std::cout<<"source positions"<<std::endl;
        // std::cout<<sources__[EffectiveSourceIndices[effective_ind]].position.x<<" "<<sources__[EffectiveSourceIndices[effective_ind]].position.y<<" "<<sources__[EffectiveSourceIndices[effective_ind]].position.z<<std::endl;
        
        vector_to_Ppos___from_Qpos.assign(Ppos__.x-sources__[EffectiveSourceIndices[effective_ind]].position.x,
                                          Ppos__.y-sources__[EffectiveSourceIndices[effective_ind]].position.y, 
                                          Ppos__.z-sources__[EffectiveSourceIndices[effective_ind]].position.z);
        
        
        //        std::cout<<"vector_to_Ppos___from_Qpos"<<std::endl;
        //        std::cout<<vector_to_Ppos___from_Qpos.x<<" "<<vector_to_Ppos___from_Qpos.y<<" "<<vector_to_Ppos___from_Qpos.z<<std::endl;
        
        tempx=vector_to_Ppos___from_Qpos.x;
        tempy=vector_to_Ppos___from_Qpos.y;
        tempz=vector_to_Ppos___from_Qpos.z;
        distance_from_Ppos__.push_back( tempx*tempx + tempy*tempy + tempz*tempz );
        
        distance_from_Ppos__[effective_ind]=std::sqrt(distance_from_Ppos__[effective_ind]);
         std::cout<<"distance_from_Ppos__"<<std::endl;
         std::cout<<distance_from_Ppos__[effective_ind]<<std::endl;
        
        
    }
    
    for(int effective_ind=0; effective_ind<EffectiveSourceIndices.size(); effective_ind++)
    {
        path_difference.push_back(distance_from_Ppos__[effective_ind]-original_src_prop_distance);
        delays.push_back(path_difference[effective_ind]/co__);
         std::cout<<delays[effective_ind]<<std::endl;
        
    }
    
    //////////////////////////////////////////////////////    
    //                                                  //
    //    assemble the frequency and time domain !      ////////////////////////////////////////////////////////   
    //                                                  //
    //////////////////////////////////////////////////////    
    
    const double pi = boost::math::constants::pi<double>();
    double fs=48000;
    double dt=1/fs;
    double T=s_;         //seconds of PBN defined up top.
    int N=std::ceil(T/dt);
    T=N*dt;             //fix because of rounding.
    double df=1/(N*dt);
    
    //frequency domain
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
    
    fftw_complex* Xsinglesided = new fftw_complex[Nss];
    fftw_complex* x = new fftw_complex[N];
    
    
    for(int i=0; i<Nss; i++)
    {       Xsinglesided[i][0]=1;
        Xsinglesided[i][1]=0;
        
        //          std::cout<<Xsinglesided[i][0]<<" + "<<Xsinglesided[i][1]<<" i"<<std::endl;
    }
    x_from_X ( Xsinglesided, x, freqdom_single_sided.size(), df, dt);
    
    
    //this gives a perfect impulse demonstrating that the code is good, also the RMS match up for both time and frequency domain. 
    
    //       for(int i=0; i<Nss; i++)
    //       {    std::cout<<x[i][0]<<" + "<<x[i][1]<<" i"<<std::endl;
    //       }
    //////////////////////////////////////////////////////    
    //                                                  //
    //    Set Reflection Coeffecients                   ////////////////////////////////////////////////////////   
    //                                                  //
    //////////////////////////////////////////////////////   
    
    // Only do this for original planes__
    

    for(int wallnum=0; wallnum< num_original_walls__; wallnum++)
    {       
            for(int bin=0; bin<Nss; bin++)
            {    planes__[wallnum].reflection_coeff.push_back(1);
            }   
    }

    std::vector<double> R;
    
    
    //////////////////////////////////////////////////////    
    //                                                  //
    //    Store Source Positions + planes__             //  
    //                                                  //
    //////////////////////////////////////////////////////   
    
    
    
    //////////////////////////////////////////////////////    
    //                                                  //
    //   Now Let's Populate the IR !                    ////////////////////////////////////////////////////////   
    //                                                  //
    //////////////////////////////////////////////////////    
    
    
    //Calculate sample arrival times
    double temp_approx_sample;        
    std::vector <double> arrival_sample_index;
    double residue;    
    
    

    
    for(int effective_ind=0; effective_ind<EffectiveSourceIndices.size(); effective_ind++)
    {
        
        
        temp_approx_sample=delays[effective_ind]*fs;
        
        residue= (int)round(temp_approx_sample*100) % (int)100;
        
        if (residue>=50 || residue<1)
        {    arrival_sample_index.push_back((int)ceil(temp_approx_sample));}
        else
        {    arrival_sample_index.push_back((int)floor(temp_approx_sample));}
        
    }    
    
    
    //Create an empty IR
    
    std::vector<double> ImpulseResponse(N);
    

    
    
    for(int i=0; i<N; i++)
    {
        ImpulseResponse[i]=0;
    }
    
    //Populate
    
    unsigned Qind;
    
    if(dont_use_filtering__)
    {
        
        
        for (unsigned EffSrcInd=0; EffSrcInd<EffectiveSourceIndices.size(); EffSrcInd++)
        {
            Qind=EffectiveSourceIndices[EffSrcInd];
            
            if(Qind==0)
            {
                // for(unsigned bin=0; bin<N; bin++)   //this would be useful fore real reflecton coeffecients
                // {   
                //     X_R[bin][0]=1;
                //     X_R[bin][1]=0;
                // }
                
                ImpulseResponse[ arrival_sample_index[EffSrcInd] ]=1+ImpulseResponse[ arrival_sample_index[EffSrcInd] ]; 
            }
            
            else
            {
                
                // for(unsigned bin=0; bin<N; bin++)   //this would be useful fore real reflecton coeffecients
                // {   
                //     X_R[bin][0]=1;
                //     X_R[bin][1]=0;
                // }
                
                ImpulseResponse[ arrival_sample_index[EffSrcInd] ]=1+ImpulseResponse[ arrival_sample_index[EffSrcInd] ];             
                
            }
        }
    }
    
    
    
    
    unsigned Qind_temp, ref_order;
    position_vector Ppos___temp;
    // fftw_complex* X_R = new fftw_complex[Nss]; //the magnitude of the reflection;
    std::vector<double> FiltMagR;
    std::vector<double> DiskResp;
    
    //For Filtering
    std::vector<double> ytrunc;
    
    

    /////////////////////////////////////////////////////////////
    //                                                         //
    /////////////////////////////////////////////////////////////
    if(use_R_coeffs__)
    {    
        
        for (unsigned EffSrcInd=0; EffSrcInd<EffectiveSourceIndices.size(); EffSrcInd++)
        {
            Qind=EffectiveSourceIndices[EffSrcInd];
            
            if(Qind==0)
            {           
                ImpulseResponse[ arrival_sample_index[EffSrcInd] ]=1+ImpulseResponse[ arrival_sample_index[EffSrcInd] ]; 
            }
            
            else
            {
                
                R=planes__[planes__[sources__[Qind].mother_wall_ind].num].reflection_coeff;
                FiltMagR.clear();    
                
                for(int i=0; i<Nss; i++)
                {
                    FiltMagR.push_back( 1 * R[i] );
                }
                
                
                if(sources__[Qind].order>1)
                {   Qind_temp=Qind;
                    
                    for( ref_order=sources__[Qind].order; ref_order>1; ref_order--)
                        
                    {  
                        Ppos___temp=planes__[sources__[Qind_temp].mother_wall_ind].center;
                        Qind_temp=sources__[Qind_temp].mother_source_ind;
                        
                        if(Qind==0)
                        {break;}
                        
                        R=planes__[planes__[sources__[Qind_temp].mother_wall_ind].num].reflection_coeff;
                        
                        for(int i=0; i<Nss; i++)
                        {
                            FiltMagR[i]= 1 *  R[i]* FiltMagR[i];
                        }
                    }
                }
                
                
                //////////////////////////////////////////////
                //                                          //   
                //       Calculate the Phase Response       //
                //                                          //       
                //////////////////////////////////////////////
                
                dhtm(FiltMagR, N, ytrunc, df);//we dispose of the imaginary part which is very close to zero
                
                unsigned impulse_ind=0;
                
                for(int i=arrival_sample_index[EffSrcInd ]; i<N ; i++ )
                {   
                    ImpulseResponse[i]=ytrunc[impulse_ind]+ ImpulseResponse[i];                     
                    impulse_ind++;
                }
                
            }
        }
    }
    
    
    if(use_R_coeffs_and_Disk_Approx__)
    {    
        
        for (unsigned EffSrcInd=0; EffSrcInd<EffectiveSourceIndices.size(); EffSrcInd++)
        {
            Qind=EffectiveSourceIndices[EffSrcInd];
            
            if(Qind==0)
            {           
                ImpulseResponse[ arrival_sample_index[EffSrcInd] ]=1+ImpulseResponse[ arrival_sample_index[EffSrcInd] ]; 
            }
            
            else
            {
                
                R=planes__[planes__[sources__[Qind].mother_wall_ind].num].reflection_coeff;
                FiltMagR.clear();    
                
                for(int i=0; i<Nss; i++)
                {
                    FiltMagR.push_back( 1 * R[i] );
                    //    std::cout<<FiltMagR[i]<<std::endl;
                }
                
                
                if(sources__[Qind].order>1)
                {   Qind_temp=Qind;
                    
                    for( ref_order=sources__[Qind].order; ref_order>1; ref_order--)
                        
                    {  
                        Ppos___temp=planes__[sources__[Qind_temp].mother_wall_ind].center;
                        Qind_temp=sources__[Qind_temp].mother_source_ind;
                        
                        if(Qind==0)
                        {break;}
                        
                        R.clear();
                        R=planes__[planes__[sources__[Qind_temp].mother_wall_ind].num].reflection_coeff;
                        
                        for(int i=0; i<Nss; i++)
                        {
                            FiltMagR[i]= 1 *  R[i]* FiltMagR[i];
                            //std::cout<<FiltMagR[i]<<std::endl;
                        }
                    }
                }
                
                
                // Now... for disk approximation goodness
                //////////////////////////////////////////////
                fftw_complex * X_R = new fftw_complex[Nss];
                
                // Find the Magnitude Due to the Disk. 
                
               // if( sources__[Qind].order>1 ||  (sources__[Qind].order==1 && !planes__[Qind.mother_wall_ind].floorplane ))
               // {  
                    DiskApproxFinal_Generalized( EffectiveSourceIndices[EffSrcInd], 
                                                sources__ , 
                                                planes__ , 
                                                Ppos__ , /*receiver position*/
                                                s_, /*seconds of IR*/ 
                                                co__, /*soundspeed*/ 
                                                freqdom_single_sided, /*definition of frequency domain*/
                                                &X_R );
                    
                    for(int i=0; i<Nss; i++)
                    {
                        FiltMagR[i]=FiltMagR[i] * X_R[i][0];
                        std::cout<<FiltMagR[i]<<std::endl;
                    }
                //}
                
                delete[] X_R;
                //////////////////////////////////////////////
                
                
                dhtm(FiltMagR, N, ytrunc, df);//we dispose of the imaginary part which is very close to zero
                
                unsigned impulse_ind=0;
                
                for(int i=arrival_sample_index[EffSrcInd ]; i<N ; i++ )
                {   
                    ImpulseResponse[i]=ytrunc[impulse_ind]+ ImpulseResponse[i];                     
                    std::cout<<ytrunc[impulse_ind]<<std::endl;
                    impulse_ind++;
                }
                
            }
        }
    }
    
    
    //////////////////////////////////////////////////////    
    //                                                  //
    //   Make a note of how long this took to run       ////////////////////////////////////////////////////////   
    //                                                  //
    //////////////////////////////////////////////////////     
    //
    //    //    seconds = time (NULL);
    //    //    printf ("%ld seconds since January 1, 1970", seconds);
    //    //    
    //    //  //Plot Ouptut IR
    //    //        
    //    //    vtkSmartPointer<vtkContextView> view = vtkSmartPointer<vtkContextView>::New();
    //    //    view->GetRenderer()->SetBackground(1.0, 1.0, 1.0);
    //    //    view->GetRenderWindow()->SetSize(400, 300);
    //    //    
    //    //    vtkSmartPointer<vtkChartXY> chart =
    //    //    vtkSmartPointer<vtkChartXY>::New();
    //    //    view->GetScene()->AddItem(chart);
    //    //    chart->SetShowLegend(true);
    //    //    
    //    //    vtkAxis *Xaxis = vtkAxis::New();
    //    //    int axisindexX=1;
    //    //    Xaxis=chart->GetAxis (axisindexX);
    //    //    Xaxis->SetLogScale(false);                      //Log Scale 
    //    //    Xaxis->SetRange ((double)0,delays[delays.size()-1]*2);
    //    //    
    //    //    std::string tempX = "Time [s]";
    //    //    Xaxis->SetTitle(tempX.c_str());
    //    //    
    //    //    vtkAxis *YAxis = vtkAxis::New();
    //    //    int axisindexY=0;
    //    //    YAxis=chart->GetAxis (axisindexY);
    //    //    
    //    //    std::string tempY = "Amplitude";
    //    //    YAxis->SetTitle(tempY.c_str());
    //    //    
    //    //    vtkTextProperty * TitleProps;
    //    //    TitleProps=YAxis->GetLabelProperties();
    //    //    TitleProps->SetOrientation(90);
    //    //    
    //    //    
    //    //    // Create a table with some points in it...
    //    //    vtkSmartPointer<vtkTable> table =
    //    //    vtkSmartPointer<vtkTable>::New();
    //    //    
    //    //    vtkSmartPointer<vtkFloatArray> sampletimes =
    //    //    vtkSmartPointer<vtkFloatArray>::New();
    //    //    sampletimes->SetName("Time [s]");
    //    //    table->AddColumn(sampletimes);
    //    //    
    //    //    vtkSmartPointer<vtkFloatArray> amplitudes =
    //    //    vtkSmartPointer<vtkFloatArray>::New();
    //    //    amplitudes->SetName("Amplitude");
    //    //    table->AddColumn(amplitudes);
    //    //    
    //    //    int numPoints=N;
    //    //    
    //    //    table->SetNumberOfRows(numPoints);
    //    //    
    //    //    float tempfloat;
    //    //    
    //    //    for (int i = 0; i < numPoints; ++i)
    //    //    {
    //    //        
    //    //        
    //    //        table->SetValue(i, 0, i*dt);
    //    //        
    //    //        tempfloat=ImpulseResponse[i];
    //    //        table->SetValue(i, 1, tempfloat);
    //    //        
    //    //    }            
    //    //    
    //    //    
    //    //    // Add multiple scatter plots, setting the colors etc
    //    //    vtkPlot *points = chart->AddPlot(vtkChart::POINTS);
    //    //    points->SetInput(table, 0, 1);
    //    //    points->SetColor(0, 225, 0, 255);
    //    //    points->SetWidth(1.0);
    //    //    vtkPlotPoints::SafeDownCast(points)->SetMarkerStyle(vtkPlotPoints::CIRCLE);
    //    //    
    //    //    
    //    //    
    //    //    
    //    //    //Finally render the scene
    //    //    view->GetRenderWindow()->SetMultiSamples(0);
    //    //    view->GetInteractor()->Initialize();
    //    //    view->GetInteractor()->Start();
    //    //    
    //    //    // return EXIT_SUCCESS;
    //
    //
    //
    //////////////////////////////////////////////
    //                                          //   
    //           Write IR to a text File        //
    //                                          //       
    //////////////////////////////////////////////
    
    FILE * writeIR;
    
    
    
    
    
    
    //Write A file to hoLf the information of source position 
    char* whole_filename_IR = new char[500];
   // char * arrivalaz= new char[500];
   // char * arrivalel= new char[500];
   // char * sim_number= new char[500];
    char * ir_number= new char[500];
    
    char * Ppos__x= new char[500];
    char * Ppos__y= new char[500];
    char * Ppos__z= new char[500];
    
   // snprintf(arrivalaz, 79, "%f", phi__);
   // snprintf(arrivalel, 79, "%f", theta_i__);
    snprintf(ir_number, 79, "%i", Which_IR__);
  //  snprintf(sim_number, 79, "%i", Which_SIM__);
    
    snprintf(Ppos__x, 79, "%f", Ppos__.x);
    snprintf(Ppos__y, 79, "%f", Ppos__.y);
    snprintf(Ppos__z, 79, "%f", Ppos__.z);
    
    strcat(whole_filename_IR,directory);
    //strcat(whole_filename_IR,"_");
    strcat(whole_filename_IR,simulation_name);
    strcat(whole_filename_IR,sim_number);
    strcat(whole_filename_IR,"_");
    
    //lets append zeros to the simulation number
    
    int numdigets= strlen(ir_number);
    char* zeros=new char[10];
    
    zeros[0] = '\0';
    
    for(int addzeros=7-numdigets; addzeros>0; addzeros--)
    {
        strcat(zeros,"0");
    }
    strcat(zeros,ir_number);
    
    strcat(whole_filename_IR,zeros);
    strcat(whole_filename_IR,"_IR_");
    strcat(whole_filename_IR,arrivalaz);
    strcat(whole_filename_IR,"_az_");
    strcat(whole_filename_IR,arrivalel);
    strcat(whole_filename_IR,"_el_Ppos_"); 
    strcat(whole_filename_IR,Ppos__x);
    strcat(whole_filename_IR,"i_");
    strcat(whole_filename_IR,Ppos__y);
    strcat(whole_filename_IR,"j_");
    strcat(whole_filename_IR,Ppos__z);
    strcat(whole_filename_IR,"k.txt"); 
    std::cout<<whole_filename_IR<<std::endl;
    
    writeIR = fopen (whole_filename_IR,"w");
    
    
    
    if(writeIR)
    {
        //  fputs ("y=[",write);
        for(unsigned sample=0; sample<N; sample++)
        {
            fprintf(writeIR,"%f \n",ImpulseResponse[sample]);
        }
        // fprintf(write,"];");
        
        fclose(writeIR);
    }
    else
    {
        std::cout<<"Couldnt Open FIle"<<std::endl;
    }
    
    
    delete[] whole_filename_IR;
    delete[] Ppos__x;
    delete[] Ppos__y;
    delete[] Ppos__z;
    delete[] ir_number;
    delete[] sim_number;
    delete[] arrivalaz;
    delete[] arrivalel;   
    delete[] Xsinglesided;
    delete[] x;
    delete[] zeros;
    
    distance_from_Ppos__.clear();
    path_difference.clear();
    delays.clear();
    freqdom_single_sided.clear();
    freqdom_double_sided.clear();
    time_dom.clear();
    arrival_sample_index.clear();
    ImpulseResponse.clear();
    FiltMagR.clear();
    DiskResp.clear();
    ytrunc.clear();
    EffectiveSourceIndices.clear();
    
    for(int wallnum=0; wallnum< num_original_walls__; wallnum++)
    {
        planes__[wallnum].reflection_coeff.clear();
        
    }
//    whole_filename_IR = 0;
//    Ppos__x=0;
//    Ppos__y=0;
//    Ppos__z=0;
//    sim_number=0;
//    arrivalaz=0;
//    arrivalel=0;
//    writeIR=0;
    
    return true;
}
#endif
