//
//  OneSourcePos.h
//  ISM
//
//  Created by Amanda Lind on 5/2/12.
//  Copyright (c) 2012 Pennsylvania State University. All rights reserved.
//

#ifndef ISM_OneSourcePos_h
#define ISM_OneSourcePos_h

#define FLT_EVAL_METHOD 2/* implementation defined */

void OneSourcePos(unsigned simnum_)
{
    int   Which_Simulation=simnum_;
    
    
    time_t seconds;
    seconds = time (NULL);
    printf ("%ld seconds since January 1, 1970", seconds);
    
    time_t seconds_start;
    seconds_start = time (NULL);
    
    std::vector<wall> planes;
    std::vector<corner> unique_corners_output;
    
    //*1.-------Constants-----------------------------------------------------*
    
    std::cout.precision(15);
    double co=345.0;
    double s=5;                 //%seconds of reflections/post boom noise
    double	radius=350;         //radius of simulation domain
    
    // Where to Store Outputs
    //const char* directory = "/Users/mandalin/Desktop/BulkXcodeSims/ImpulseResponses/";
    //const char* directory = "/Volumes/WORKSPACE/InProgress/";
    //const char* directory = "/Volumes/G-DRIVE/InProgress/";
    //const char* directory = "/Volumes/PSU-WORKSPACE/InProgress2/"
    
    char * directory= new char[1000];
    //strcat(directory,"/Volumes/WORKSPACE-TWO/MontrealWork/SimB_Mic106/");
    strcat(directory,"/Volumes/WORKSPACE-ONE/InProgress/");
    
    //    bool dont_use_filtering=false;
    //    bool use_R_coeffs=false;
    //    bool use_R_coeffs_and_Disk_Approx=true;
    
    //strcat(directory,"/Users/mandalin/Desktop/Xcode Output/CompleteRoof -Unfiltered-rooffix/");
    //    bool dont_use_filtering=true;
    //    bool use_R_coeffs=false;
    //    bool use_R_coeffs_and_Disk_Approx=false;
    
    
    
    //    FILE * write;
    //
    //
    //    write = fopen ("/Users/mandalin/Desktop/Xcode Output/CompleteRoof -Filtered-rooffix/testfile","w");
    //
    //    if(write)
    //    {
    //        fprintf(write, "Test");
    //    }
    
    //    bool LoadSimulation=true;
    //    const char * SimulationFilename="Blackbird_sim__2_sources_62.209000 az_10.060000 el.txt";
    //
    //    std::vector <source> SourcesLoaded;
    //    double az_loaded, el_loaded, Temperature_loaded;
    //
    //
    //    if(LoadSimulation)
    //    {
    //        SourcesLoaded = ReadInSourceFile(directory, SimulationFilename,az_loaded, el_loaded, Temperature_loaded);
    //    }
    //
    //
    //
    //
    //
    
    
    
    
    
    char * Which_Simulation_ = new char[20];
    snprintf(Which_Simulation_, 20, "%i",  Which_Simulation);
    strcat(directory,Which_Simulation_);
    strcat(directory,"/");
    
    
    
    // Order of Simulation
    int max_order=10;
    // Receiver Positions
    bool SubSampleSurface=false; //must be true for plotting a contour
    bool AddEdgesToSubsample=false;
    bool OnlyGroundPlanesSubsampled=true; //must add ground plane list to this. If SubSampleSurface=false, this var is of no consequence, no subsampling occurs.
    
    // Filtering
    bool dont_use_filtering=true;
    bool use_R_coeffs=false;
    bool use_R_coeffs_and_Disk_Approx=false;
    
    // GeometrySimple
    bool Box=false;
    bool L_shaped=false;
    bool Blackbird=false;
    bool CSF=false;
    bool Albert=false;
    bool Canyon=false;
    bool Isolated_Wall=true;
    
    //Plotting of Geometry and Receivers
    bool plot_geom=false;
    bool Plot_RecPos=false; //dont use with subsampled receiver surfaces !
    
    //Plotting of Contours
    bool Plot_Contour=false;
    bool Save_Contour=false;
    bool PldB_Plot=false;
    bool Pmax_Plot=false;
    bool NumRefs_Plot=true;
    
    double Temperature;
    
    //
    //
    //////////////END PRESETS//////////////
    
    ///////////CHOSE GEOMETRY///////////
    //
    //
    double mPERft=.3048;
    double mPERin=.0245;
    position_vector Ppos1;
    position_vector Ppos2;
    position_vector Ppos3;
    position_vector Ppos4;
    position_vector Ppos5;
    position_vector Ppos6;
    position_vector Ppos7;
    position_vector Ppos8;
    std::vector<position_vector> Ppos_vector;
    
    position_vector PposFinal;
    std::vector<unsigned> ground_planes;
    double radius_of_subsampling;
    //************L Shaped
    if(L_shaped)
    {   planes=geometry_generalized(unique_corners_output);
        
        //L Listener Positions
        
        position_vector PposFinal;
        
        Ppos1.assign(12.2,12.21,.01);                        //simulation 1 L shaped building -> very close to corner
        Ppos2.assign(13,15,1.2);                           //simulation 2 L shaped building
        Ppos3.assign(40*.3048+.3,40*.3048+.31,1.2);           //simulation 3 L shaped building (just outside of corner
        Ppos4.assign(40*.3048+.001,40*.3048+.003,.001);     //simulation exactically in corner.
        
        Ppos_vector.push_back(Ppos1);
        Ppos_vector.push_back(Ppos2);
        Ppos_vector.push_back(Ppos3);
        Ppos_vector.push_back(Ppos4);
        
        
        ground_planes.push_back(7);
        ground_planes.push_back(8);
        ground_planes.push_back(9);
        ground_planes.push_back(10);
        
        for(int ground_inds=0; ground_inds<ground_planes.size(); ground_inds++ )
        {
            planes[ground_planes[ground_inds]].floorplane=true;
        }
        
        radius_of_subsampling=170*.3048;
    }
    
    //************BOX
    if(Box)
    {   planes=geometry_generalized_box(unique_corners_output);
        
        double wall_length=20;
        Ppos1.assign(0, -wall_length/2-2, 1.2);
        Ppos2.assign(-5*sin(45*(pi/180)),-5*sin(45*(pi/180)),0 );
        Ppos2=add(Ppos1,Ppos2);
        Ppos3.assign(-10*sin(45*(pi/180)),-10*sin(45*(pi/180)),0);
        Ppos3=add(Ppos1,Ppos3);
        
        Ppos_vector.push_back(Ppos1);
        Ppos_vector.push_back(Ppos2);
        Ppos_vector.push_back(Ppos3);
    }
    
    //************DEM
    double max_elevation;
    double min_elevation;
    position_vector center_pt;
    if(Canyon)
    {    const char * Filename = "/Users/mandalin/Desktop/DissertationCODE/Cocoa/Model3_31_2011/ISM/ISM/41002080PAN_dem/41002080PAN_dem.tif";
        
        //      planes=ISM_DEM_PAMAP_LoadOneTile(Filename, unique_corners_output, min_elevation, max_elevation, center_pt);
        Ppos1=center_pt;
        
        Ppos_vector.push_back(Ppos1);
    }
    
    
    //************Blackbird
    corner wrtW;
    corner datumW;
    
    position_vector Ppos91, Ppos92, Ppos93, Ppos94, Ppos104, Ppos105, Ppos106, Ppos107;
    if(Blackbird)
    {   double berrings_az=(90-12.2953)*(pi/180);
        planes=generalized_geometry_52Blackbird(unique_corners_output, berrings_az );
        
        position_vector datumW;
        
        
        datumW.assign(20*mPERft+8*mPERin,0,0); //before rotation
        
        double wall_length=20;
        double mPERin=0.0254;
        
        wrtW.assign( 53*mPERin,    396*mPERin, 60.5*mPERin);          Ppos91=add(datumW,wrtW);
        wrtW.assign( 53*mPERin,    297*mPERin, 51*mPERin);            Ppos92=add(datumW,wrtW);
        wrtW.assign( 0,             251*mPERin,  0.007);                   Ppos93=add(datumW,wrtW);
        wrtW.assign( 203.5*mPERin, 420*mPERin, 0.007);                    Ppos94=add(datumW,wrtW);
        wrtW.assign( 106*mPERin,    -84.5*mPERin,0.007);                     Ppos106=add(datumW,wrtW);
        
        //corner c217t planes[0].unique_corners[198];
        //corner c214e planes[0].unique_corners[190];
        
        //
        //my x = jake's -y
        //my y = jakes x
        
        Ppos_vector.push_back(Ppos91);
        Ppos_vector.push_back(Ppos92);
        Ppos_vector.push_back(Ppos93);
        Ppos_vector.push_back(Ppos94);
        //Ppos104 is the far field mic.
        Ppos_vector.push_back(Ppos106);
        
        //  Rotate Corners so that microphone receiver positions, and arrival angles are kosher
        
        position_vector i(1,0,0);
        position_vector j(0,1,0);
        position_vector k(0,0,1);
        
        std::vector<position_vector> d;
        d.push_back(i); d.push_back(j); d.push_back(k); //d is just the diagonal identity matrix
        
        double  theta=  -berrings_az;
        double  a11=    cos(theta);
        double  a12=    -sin(theta);
        double  a13=    0;
        double  a21=    sin(theta);
        double  a22=    cos(theta);
        double  a23=    0;
        double  a31=    0;
        double  a32=    0;
        double  a33=    1;
        
        double initialValues[3][3] = {
            a11, a12, a13,
            a21, a22, a23,
            a31, a32, a33
        };
        
        boost::numeric::ublas::matrix<double> Transfb;
        Transfb = boost::numeric::ublas::make_matrix_from_pointer(initialValues); //in storage_adapters.hpp
        
        boost::numeric::ublas::matrix<double>  CornerRotated(Ppos_vector.size(),3), CornerTempRotated(1,3), CornerTemp(1,3);
        
        for(int i=0; i<Ppos_vector.size(); i++)
        {
            initialValues[0][0]=Ppos_vector[i].v[0];
            initialValues[0][1]=Ppos_vector[i].v[1];
            initialValues[0][2]=Ppos_vector[i].v[2];
            CornerTemp = boost::numeric::ublas::make_matrix_from_pointer(initialValues); //in storage_adapters.hpp
            //std::cout<<"-------------"<<std::endl;
            //std::cout<<CornerTemp<<std::endl<<std::endl;
            CornerTempRotated=boost::numeric::ublas::prod(CornerTemp,Transfb);
            //std::cout<<CornerTempRotated<<std::endl<<std::endl;
            CornerRotated(i,0)=CornerTempRotated(0,0);
            CornerRotated(i,1)=CornerTempRotated(0,1);
            CornerRotated(i,2)=CornerTempRotated(0,2);
            //std::cout<<CornerRotated<<std::endl<<std::endl;
            
            Ppos_vector[i].assign(CornerRotated(i,0),CornerRotated(i,1),CornerRotated(i,2));
        }
        
        datumW = unique_corners_output[13]; //after rotation
        std::cout<<std::endl<<unique_corners_output[13].x<<" "<<unique_corners_output[13].y<<" "<<unique_corners_output[13].z<<std::endl;
        
        double tempx=unique_corners_output[196].x;
        double tempy=unique_corners_output[196].y;
        double tempz=unique_corners_output[196].z+.007;
        
        Ppos104.assign( -116.1649,   30.4756, .007 );
        Ppos105.assign(tempx,tempy,tempz);
        
        tempx=unique_corners_output[188].x;
        tempy=unique_corners_output[188].y;
        tempz=unique_corners_output[188].z;
        
        corner tempcorn(tempx,tempy,tempz);
        
        wrtW.assign(  (Ppos105.x-tempx)/2, (Ppos105.y - tempy)/2, (Ppos105.z - tempz)/2+.007);
        Ppos107=add(tempcorn,wrtW);
        
        Ppos_vector.push_back(Ppos105);
        Ppos_vector.push_back(Ppos107);
        Ppos_vector.push_back(Ppos104);
        
        //        ground_planes.push_back(32);
        //        ground_planes.push_back(33);
        //        ground_planes.push_back(34);
        //        ground_planes.push_back(35);
        
        
        Ppos91.assign(Ppos_vector[0]);
        Ppos92.assign(Ppos_vector[1 ]);
        Ppos93.assign(Ppos_vector[2] );
        Ppos94.assign(Ppos_vector[3] );
        Ppos106.assign(Ppos_vector[4 ]);
        
        for (int i=0; i<Ppos_vector.size(); i++)
        {   std::cout<<std::endl<<Ppos_vector[i].x;
        }
        
        Ppos_vector.clear();
        
        Ppos_vector.push_back(Ppos91);
        Ppos_vector.push_back(Ppos92);
        Ppos_vector.push_back(Ppos93);
        Ppos_vector.push_back(Ppos94);
        Ppos_vector.push_back(Ppos104);
        Ppos_vector.push_back(Ppos105);
        Ppos_vector.push_back(Ppos106);
        Ppos_vector.push_back(Ppos107);
        
        for (int i=0; i<Ppos_vector.size(); i++)
        {   std::cout<<std::endl<<Ppos_vector[i].x;
        }
        
        
        
        
        
        radius_of_subsampling=200*.3048;
        
        //        for(int ground_inds=0; ground_inds<ground_planes.size(); ground_inds++ )
        //        {
        //            planes[ground_planes[ground_inds]].floorplane=true;
        //        }
    }
    
    //************CSF
    if(CSF)
    {   planes= generalized_geometry_CSF(unique_corners_output );
        Ppos1.assign(12.24+1.05, 0, 1.2);
        
        Ppos_vector.push_back(Ppos1);
        
        ground_planes.push_back(24);
        ground_planes.push_back(25);
        ground_planes.push_back(26);
        ground_planes.push_back(27);
        
        radius_of_subsampling=200*3048;
        
        for(int ground_inds=0; ground_inds<ground_planes.size(); ground_inds++ )
        {
            planes[ground_planes[ground_inds]].floorplane=true;
        }
        
    }
    
    //************Albert
    if(Albert)
    {   planes=geometry_generalized_Albert(unique_corners_output);
        Ppos1.assign(12.24+1.05, 0, 1.2); //microphone 8
        
        Ppos_vector.push_back(Ppos1);
        
    }
    //
    
    //************+Isolated Wall
    if(Isolated_Wall)
    {
        Temperature=85;//This Temperature is in F. convert to C
        Temperature=(Temperature-32)* (5.0/9.0);
        co=331.3*sqrt(1+((Temperature)/273.15));
        position_vector Ppos190, Ppos189, Ppos188, Ppos204, Ppos202, Ppos203, Ppos201; // Ppos202
        
        //Load the Geometry
        planes=geometry_generalized_IsolatedWall(unique_corners_output);
        
        //Add the Virtual Microphone Positions

        //Each virtual microphone is 1/8" off the surface it rests on.
        Ppos190.assign(266*.3048, 0, .125*0.0254); //microphone A 266' from house wall
        Ppos204.assign((195+8/12)*.3048, 0, .125*0.0254); //microphone D 195'8"
        Ppos188.assign((155+5/12)*.3048, 0, .125*0.0254); //microphone C 155'5"
        Ppos189.assign((115+10/12)*.3048, 0, .125*0.0254); //microphone B 115'10"
        
        Ppos202.assign(3*.3048, 0, .125*0.0254);                    //microphone 1,        3' before the wall, in meters
        Ppos203.assign(-2.5*0.0254, 0, 36.125*0.0254);            //microphone 2,        on the wall
        Ppos201.assign(-3*.3048, 0, .125*0.0254);          //microphone 3,        3' behind the wall
        
        
        Ppos_vector.push_back(Ppos190);
        Ppos_vector.push_back(Ppos204);
        Ppos_vector.push_back(Ppos188);
        Ppos_vector.push_back(Ppos189);
        Ppos_vector.push_back(Ppos202);
        Ppos_vector.push_back(Ppos203);
        Ppos_vector.push_back(Ppos201);
        
        //  Rotate so that microphone receiver positions, and arrival angles are kosher
        position_vector i(1,0,0);
        position_vector j(0,1,0);
        position_vector k(0,0,1);
        
        std::vector<position_vector> d;
        d.push_back(i); d.push_back(j); d.push_back(k); //d is just the diagonal identity matrix
        
        double berrings_az=-0.03490658504;  //radians of rotation clockwise from an aerial perspective.
        double  theta=  -berrings_az;
        double  a11=    cos(theta);
        double  a12=    -sin(theta);
        double  a13=    0;
        double  a21=    sin(theta);
        double  a22=    cos(theta);
        double  a23=    0;
        double  a31=    0;
        double  a32=    0;
        double  a33=    1;
        
        double initialValues[3][3] = {
            a11, a12, a13,
            a21, a22, a23,
            a31, a32, a33
        };
        
        boost::numeric::ublas::matrix<double> Transfb;
        Transfb = boost::numeric::ublas::make_matrix_from_pointer(initialValues); //in storage_adapters.hpp
        
        boost::numeric::ublas::matrix<double>  CornerRotated(Ppos_vector.size(),3), CornerTempRotated(1,3), CornerTemp(1,3);
        
        for(int i=0; i<Ppos_vector.size(); i++)
        {
            initialValues[0][0]=Ppos_vector[i].v[0];
            initialValues[0][1]=Ppos_vector[i].v[1];
            initialValues[0][2]=Ppos_vector[i].v[2];
            CornerTemp = boost::numeric::ublas::make_matrix_from_pointer(initialValues); //in storage_adapters.hpp
            //std::cout<<"-------------"<<std::endl;
            //std::cout<<CornerTemp<<std::endl<<std::endl;
            CornerTempRotated=boost::numeric::ublas::prod(CornerTemp,Transfb);
            //std::cout<<CornerTempRotated<<std::endl<<std::endl;
            CornerRotated(i,0)=CornerTempRotated(0,0);
            CornerRotated(i,1)=CornerTempRotated(0,1);
            CornerRotated(i,2)=CornerTempRotated(0,2);
            //std::cout<<CornerRotated<<std::endl<<std::endl;
            
            Ppos_vector[i].assign(CornerRotated(i,0),CornerRotated(i,1),CornerRotated(i,2));
        }

        // Creates a list of the ground plane indices for subsampling
        radius_of_subsampling=20;
        for(int plane_ind=0; plane_ind<planes.size(); plane_ind++ )
        {
            if (planes[plane_ind].floorplane)
            {
                ground_planes.push_back(plane_ind);
            }
        }
        
       
    }
    
    
    //
    ///////////END CHOSE GEOMETRY///////////
    
    //push unique corners into static member of planes structure
    planes[0].unique_corners=unique_corners_output;
    
    //calculate the center of gravity for each of the planes
    for(int i=0; i<planes.size(); i++)
    {   planes[i].center=centerOgravity(planes[i]);
    }
    
    int num_original_walls=planes.size();
    
    
    ////////CHOSE Receiver Position(s)/////////
    //
    //
    
    ///SET Subsample Surface, number of points per meter squared
    std::vector<position_vector> temp_sample_points;
    //double resolution=2; //BlackBird_sim_37_noHPFing, All L shape Sims
    //double resolution=1; //Blackbird_sim_0_noHPFing
     double resolution=10;//Isolated Wall
    
    
    std::vector<unsigned> num_points_in_plane_mapping;
    unsigned plane_indices;
    unsigned numplanessubsampled=0;
    unsigned initial_microphone_positions=Ppos_vector.size();
    unsigned plane_ind;
    
    
   //double height_above_plane=1.2;      //1.2 meters listener height
    double height_above_plane=.003175; // 1/8" above the plane
    
    if(SubSampleSurface)
    {
        if(OnlyGroundPlanesSubsampled)
        {
            
            for(plane_ind=0; plane_ind<ground_planes.size(); plane_ind++)
            {
                numplanessubsampled++;
                plane_indices=ground_planes[plane_ind];                                     //this only samples the ground planes
                temp_sample_points=SubsamplePlane(planes[plane_indices], resolution, height_above_plane, AddEdgesToSubsample,radius_of_subsampling);  //last number, is how far away from the plane, in the direction of the normal, the point should be.
                num_points_in_plane_mapping.push_back(temp_sample_points.size());
                
                Ppos_vector.reserve(Ppos_vector.size()+temp_sample_points.size());
                Ppos_vector.insert(Ppos_vector.end(), temp_sample_points.begin(), temp_sample_points.end());
                temp_sample_points.clear();
                
                
                std::cout<<"Wall information:"<<std::endl<<"     Wall# "<<plane_indices<<std::endl<<"     Corners:: "<<std::endl;
                
                //for(int i =0; i<planes[plane_indices].corners.size(); i++)
                //{
                    //                        print(planes[plane_indices].corners[i]);
                    //                        std::cout<<std::endl;
                //}
                
                std::cout<<"Subsampled Points"<<std::endl;
                //for(int i =0; i<Ppos_vector.size(); i++)
                //{
                    //                        print(Ppos_vector[i]);
                    //                        std::cout<<std::endl;
                //}
            }
        }
        else
        {   for(unsigned plane_indices=0; plane_indices<num_original_walls; plane_indices++)
        {   numplanessubsampled++;
            
            temp_sample_points=SubsamplePlane(planes[plane_indices], resolution,0, AddEdgesToSubsample, radius_of_subsampling);
            num_points_in_plane_mapping.push_back(temp_sample_points.size());
            
            Ppos_vector.reserve(Ppos_vector.size()+temp_sample_points.size());
            Ppos_vector.insert(Ppos_vector.end(), temp_sample_points.begin(), temp_sample_points.end());
            temp_sample_points.clear();
            
            
            std::cout<<"Wall information:"<<std::endl<<"     Wall# "<<plane_indices<<std::endl<<"     Corners:: "<<std::endl;
            for(int i =0; i<planes[plane_indices].corners.size(); i++)
            {
                print(planes[plane_indices].corners[i]);
                std::cout<<std::endl;
            }
            
            std::cout<<"Subsampled Points"<<std::endl;
            for(int i =0; i<Ppos_vector.size(); i++)
            {
                print(Ppos_vector[i]);
                std::cout<<std::endl;
            }
        }
        }
    }
    
    std::cout<<"Number of Initial Mic Positions: "<<initial_microphone_positions<<std::endl;
    for(unsigned plane_indices=0; plane_indices<numplanessubsampled; plane_indices++)
    {
        std::cout<<"Number of Points in Plane "<<ground_planes[plane_indices]<<": "<<num_points_in_plane_mapping[plane_indices]<<std::endl;
    }
    
    //
    ////
    ////x
    ////////END CHOSE Receiver Position(s)/////////
    
    
    
    ////////CHOSE SOURCE POSITIONS/////////
    
    //double M=1.4;
    //double mu=asin(1/M)*(180/pi);  //%downstream mach angle, in degrees
    //	double theta_i=90-mu;
    
    double theta_i,az, el,phi, theta, azimuth, elevation;  //theta_i should be replaced with theta everywhere
    
    unsigned simnum;
    position_vector Qpos;
    position_vector Qpos1;
    position_vector Qpos2;
    position_vector Qpos3;
    position_vector Qpos4;
    position_vector Qpos5;
    position_vector temp;
    
    if(L_shaped)
    {
        if(Which_Simulation==1 )
        {az=-45; el=7; //First L simulation  //Remember that Az is counter clockwise from N
        }
        
        if(Which_Simulation==2 )
        {az=-30; el=7; //Second L simulation
        }
        
        theta_i=az+90;     phi=90-el;
        
        radius=30;
        //long double r=radius*10000000000;	//this throws error
        long double r=radius*1.0E10;	//%Using trial and error to see how large r has to be
        Qpos.assign(r*cos(theta_i*(pi/180))*sin(phi*(pi/180)),r*sin(theta_i*(pi/180))*sin(phi*(pi/180)),r*cos(phi*(pi/180)));
        std::cout<<"Qpos "<<Qpos.x<<" "<<Qpos.y<<" "<<Qpos.z;
    }
    
    //************BOX
    if(Box)
    {     az=-45; //this is counter clockwise from north
        el=45;
        
        theta_i=az+90;     phi=90-el;
        radius=30;
        //long double r=radius*10000000000;	//this throws error
        long double r=radius*1.0E10;	//%Using trial and error to see how large r has to be
        Qpos.assign(r*cos(theta_i*(pi/180))*sin(phi*(pi/180)),r*sin(theta_i*(pi/180))*sin(phi*(pi/180)),r*cos(phi*(pi/180)));
        
    }
    
    //************DEM
    if(Canyon)
    {    az=-45; //this is counter clockwise from north
        el=45;
        
        theta_i=az+90;     phi=90-el;
        radius=30;
        //long double r=radius*10000000000;	//this throws error
        long double r=radius*1.0E10;	//%Using trial and error to see how large r has to be
        Qpos.assign(r*cos(theta_i*(pi/180))*sin(phi*(pi/180)),r*sin(theta_i*(pi/180))*sin(phi*(pi/180)),r*cos(phi*(pi/180)));
    }
    
    //************Blackbird
    if(Blackbird)
    {
        //Taken from 2007 BADS Azimuth
        switch(Which_Simulation)
        {
            case 1: azimuth=	80.116	; elevation=	12.133	; Temperature=	81.7	; simnum=	1   ; az=azimuth; el=elevation; break;//elevation was neg
            case 2: azimuth=	62.209	; elevation=	10.06	; Temperature=	82.1	; simnum=	2	; az=azimuth; el=elevation; break;
            case 3: azimuth=	62.822	; elevation=	4.764	; Temperature=	82.2	; simnum=	3	; az=azimuth; el=elevation; break;
            case 4: azimuth=	90.816	; elevation=	29.176	; Temperature=	82.8	; simnum=	4	; az=azimuth; el=elevation; break;
            case 5: azimuth=	90.77	; elevation=	28.204	; Temperature=	84      ; simnum=	5	; az=azimuth; el=elevation; break;
            case 6: azimuth=	67.33	; elevation=	1.961	; Temperature=	75.9	; simnum=	6	; az=azimuth; el=elevation; break;//elevation was neg
            case 7: azimuth=	58.014	; elevation=	6.376	; Temperature=	76.5	; simnum=	7	; az=azimuth; el=elevation; break;
            case 8: azimuth=	58.101	; elevation=	10.488	; Temperature=	76.8	; simnum=	8	; az=azimuth; el=elevation; break;
            case 9: azimuth=	98.856	; elevation=	14.767	; Temperature=	77.1	; simnum=	9	; az=azimuth; el=elevation; break;
            case 10: azimuth=	102.695	; elevation=	15.47	; Temperature=	77.7	; simnum=	10	; az=azimuth; el=elevation; break;
            case 11: azimuth=	102.414	; elevation=	18.432	; Temperature=	77.5	; simnum=	11	; az=azimuth; el=elevation; break;
            case 12: azimuth=	70.702	; elevation=	1.889	; Temperature=	87.8	; simnum=	12	; az=azimuth; el=elevation; break;
                
            case 13: azimuth=	67.876	; elevation=	3.864	; Temperature=	88.2	; simnum=	13	; az=azimuth; el=elevation; break;
            case 14: azimuth=	55.963	; elevation=	1.082	; Temperature=	88.5	; simnum=	14	; az=azimuth; el=elevation; break;
            case 15: azimuth=	55.637	; elevation=	1.01	; Temperature=	89      ; simnum=	15	; az=azimuth; el=elevation; break;//elevation was neg
            case 16: azimuth=	88.669	; elevation=	27.193	; Temperature=	89.5	; simnum=	16	; az=azimuth; el=elevation; break;
            case 17: azimuth=	89.306	; elevation=	29.976	; Temperature=	90.1	; simnum=	17	; az=azimuth; el=elevation; break;
            case 18: azimuth=	104.208	; elevation=	7.589	; Temperature=	89.8	; simnum=	18	; az=azimuth; el=elevation; break;
            case 19: azimuth=	107.129	; elevation=	6.589	; Temperature=	90.3	; simnum=	19	; az=azimuth; el=elevation; break;
            case 20: azimuth=	102.058	; elevation=	0.928	; Temperature=	90.3	; simnum=	20	; az=azimuth; el=elevation; break;
            case 21: azimuth=	107.972	; elevation=	11.363	; Temperature=	89.8	; simnum=	21	; az=azimuth; el=elevation; break;
            case 22: azimuth=	75.601	; elevation=	19.393	; Temperature=	90.7	; simnum=	22	; az=azimuth; el=elevation; break;
            case 23: azimuth=	77.499	; elevation=	18.166	; Temperature=	92      ; simnum=	23	; az=azimuth; el=elevation; break;
                
            case 24: azimuth=	80.35	; elevation=	16.764	; Temperature=	92.5	; simnum=	24	; az=azimuth; el=elevation; break;
            case 25: azimuth=	80.903	; elevation=	15.749	; Temperature=	93.2	; simnum=	25	; az=azimuth; el=elevation; break;
            case 26: azimuth=	111.84	; elevation=	17.686	; Temperature=	94      ; simnum=	26	; az=azimuth; el=elevation; break;
            case 27: azimuth=	289.03	; elevation=	18.548	; Temperature=	94.3	; simnum=	27	; az=azimuth; el=elevation; break;
            case 28: azimuth=	62.464	; elevation=	1.326	; Temperature=	80.6	; simnum=	28	; az=azimuth; el=elevation; break;
            case 29: azimuth=	51.415	; elevation=	4.155	; Temperature=	81.4	; simnum=	29	; az=azimuth; el=elevation; break;
            case 30: azimuth=	95.217	; elevation=	19.005	; Temperature=	83.5	; simnum=	30	; az=azimuth; el=elevation; break;
            case 31: azimuth=	98.246	; elevation=	15.41	; Temperature=	83.8	; simnum=	31	; az=azimuth; el=elevation; break;
            case 32: azimuth=	74.993	; elevation=	21.349	; Temperature=	77.9	; simnum=	32	; az=azimuth; el=elevation; break;
            case 33: azimuth=	77.766	; elevation=	18.88	; Temperature=	79      ; simnum=	33	; az=azimuth; el=elevation; break;
                
            case 34: azimuth=	76.654	; elevation=	18.824	; Temperature=	80      ; simnum=	34	; az=azimuth; el=elevation; break;
            case 35: azimuth=	74.189	; elevation=	16.846	; Temperature=	80      ; simnum=	35	; az=azimuth; el=elevation; break;
            case 36: azimuth=	107.529	; elevation=	13.83	; Temperature=	82.4	; simnum=	36	; az=azimuth; el=elevation; break;
            case 37: azimuth=	288.918	; elevation=	21.5	; Temperature=	82.2	; simnum=	37	; az=azimuth; el=elevation; break;
            case 38: azimuth=	0       ; elevation=	0       ; Temperature=	82.2	; simnum=	38	; az=azimuth; el=elevation; break;
                
            default:
                cout << "The Source Position for this Simulation has not been specified!\n";
                break;
                
                
                
        }
        
        //Temperature appears to be in F. convert to C
        
        Temperature=(Temperature-32)* (5.0/9.0);
        co=331.3*sqrt(1+((Temperature)/273.15));
        
        //Bag Pop Positions;
        wrtW.assign(0, -260*.0254, 0);              Qpos1=add(datumW,wrtW);
        wrtW.assign(-240*.0254, -262*.0254, 0);     Qpos2=add(datumW,wrtW);
        wrtW.assign(-391*.0254, -150*.0254, 0);     Qpos3=add(datumW,wrtW);
        wrtW.assign(-634*.0254, 145*.0254, 0);      Qpos4=add(datumW,wrtW);
        wrtW.assign(-474*.0254, 471*.0254, 0);      Qpos5=add(datumW,wrtW);
        
        radius=30;
        //long double r=radius*10000000000;	//this throws error
        long double r=radius*1.0E10;	//%Using trial and error to see how large r has to be
        
        phi=90-azimuth;
        theta=90-elevation;
        
        Qpos.assign(r*cos(phi*(pi/180))*sin(theta*(pi/180)),r*sin(theta*(pi/180))*sin(phi*(pi/180)),r*cos(phi*(pi/180)));
        std::cout<<std::endl<<Qpos.x<<" "<<Qpos.y<<" "<<Qpos.z<<std::endl;
    }
    //************CSF
    double speed;
    if(CSF)
    {
        switch(Which_Simulation)
        {
            case	1:  phi=	111.1390	; theta_i=	7.8660	;speed=	81.7	; simnum=	1	; break; //	1
            case	2:  phi=	109.7980	; theta_i=	12.3620	;speed=	82.1	; simnum=	2	; break; //	2
            case	3:  phi=	109.3100	; theta_i=	8.6060	;speed=	82.2	; simnum=	3	; break; //	3
            case	4:  phi=	109.4760	; theta_i=	11.8120	;speed=	82.8	; simnum=	4	; break; //	4
            case	5:  phi=	110.1950	; theta_i=	11.7570	;speed=	84      ; simnum=	5	; break; //	5
            case	6:  phi=	87.1500     ; theta_i=	22.4300	;speed=	75.9	; simnum=	6	; break; //	6
            case	7:  phi=	108.7920	; theta_i=	9.9390	;speed=	76.5	; simnum=	7	; break; //	7
            case	8:  phi=	72.1300     ; theta_i=	31.6060	;speed=	76.8	; simnum=	8	; break; //	8
            case	9:  phi=	87.7850     ; theta_i=	24.3580	;speed=	77.1	; simnum=	9	; break; //	9
            case	10: phi=	74.9620     ; theta_i=	42.2200	;speed=	77.7	; simnum=	10	; break; //	10
            case	11: phi=	74.0710     ; theta_i=	42.1090	;speed=	77.5	; simnum=	11	; break; //	11
            case	12: phi=	83.5880     ; theta_i=	23.7340	;speed=	87.8	; simnum=	12	; break; //	12
            case	13: phi=	71.2920     ; theta_i=	32.4750	;speed=	88.2	; simnum=	13	; break; //	13
            case	14: phi=	109.0990	; theta_i=	8.6160	;speed=	88.5	; simnum=	14	; break; //	14
            case	15: phi=	110.8780	; theta_i=	4.7720	;speed=	89      ; simnum=	15	; break; //	15
            case	16: phi=	109.6860	; theta_i=	6.0690	;speed=	89.5	; simnum=	16	; break; //	16
            case	17: phi=	110.1400	; theta_i=	8.0040	;speed=	90.1	; simnum=	17	; break; //	17
            case	18: phi=	108.9460	; theta_i=	6.8320	;speed=	89.8	; simnum=	18	; break; //	18
            case	19: phi=	110.3360	; theta_i=	9.2700	;speed=	90.3	; simnum=	19	; break; //	19
            case	20: phi=	108.8420	; theta_i=	9.9790	;speed=	90.3	; simnum=	20	; break; //	20
            case	21: phi=	87.6850     ; theta_i=	21.9040	;speed=	89.8	; simnum=	21	; break; //	21
            case	22: phi=	86.1610     ; theta_i=	19.5960	;speed=	90.7	; simnum=	22	; break; //	22
            case	23: phi=	70.5940     ; theta_i=	31.9650	;speed=	92      ; simnum=	23	; break; //	23
            case	24: phi=	72.6240     ; theta_i=	31.9650	;speed=	92.5	; simnum=	24	; break; //	24
            case	25: phi=	76.4920     ; theta_i=	42.2300	;speed=	93.2	; simnum=	25	; break; //	25
            case	26: phi=	71.5080     ; theta_i=	28.5650	;speed=	94      ; simnum=	26	; break; //	26
            case	27: phi=	110.8070	; theta_i=	7.3830	;speed=	94.3	; simnum=	27	; break; //	27
            case	28: phi=	109.8180	; theta_i=	5.4820	;speed=	80.6	; simnum=	28	; break; //	28
            default:
                cout << "The Source Position for this Simulation has not been specified!\n";
                break;
                
        }
        az=-phi; //this is counter clockwise from north
        el=theta_i;
        
        theta_i=az+90;     phi=90-el;
        co=speed;
        
        radius=30;
        //long double r=radius*10000000000;	//this throws error
        long double r=radius*1.0E10;	//%Using trial and error to see how large r has to be
        
        Qpos.assign(r*cos(theta_i*(pi/180))*sin(phi*(pi/180)),r*sin(theta_i*(pi/180))*sin(phi*(pi/180)),r*cos(phi*(pi/180)));
        
    }
    
    //************Albert
    if(Albert)
    {      // sample_points.push_back(Ppos1); //microphone 8
        
    }
    
    //************+Isolated Wall
    if(Isolated_Wall)
    {
        //Drawing from Table 5.1 of My 2015 Dissertation
        double AZ_table=257.193-180; //table values are given, clockwise from North, and require a 180 shift.
        double EL_table=20.264; //from grazing
        
        phi=AZ_table;
        theta_i=EL_table;
        
        az=-phi; //this is counter clockwise from north
        el=theta_i;
        
        theta_i=az+90;     phi=90-el;
        //co=speed;
        
        //radius=30;
        //long double r=radius*10000000000;	//this throws error
        //long double r=radius*1.0E10;	//%Using trial and error to see how large r has to be
        //radius=92000*.3048;  //This is a fairly arbitrary number, and is based upon the elevation of the aircraft: 31,550ft, and the arrival azimuth of 20 degrees. This propogation distance assumes no thermal gradient.
        //radius=118232*.3048;//This is a fairly arbitrary number, and is based upon the elevation of the aircraft: 31,550ft, and the arrival azimuth of 20 degrees. This propogation distance assumes an extreme thermal gradient.
        
        double r=((118232+92000)/2)*.3048;//This is a fairly arbitrary number, and is based upon the elevation of the aircraft: 31,550ft, and the arrival azimuth of 20 degrees. This propogation distance assumes an extreme thermal gradient.
        
        Qpos.assign(r*cos(theta_i*(pi/180))*sin(phi*(pi/180)),r*sin(theta_i*(pi/180))*sin(phi*(pi/180)),r*cos(phi*(pi/180)));
    }
        
    
        
        
    
    ////////Make Filename stuff
    unsigned Which_Receiver = 1;
    
    char* fullsimulation_name = new char[500];
    
    char* simulation_name;
    //    char * arrivalaz;
    //    char * arrivalel;
    //
    //    snprintf(arrivalaz, 79, "%f", az);
    //    snprintf(arrivalel, 79, "%f", el);
    //
    //    printf("The Azimuth is: %s, The Elevation is: %s\n", az, el);
    //    return 0;
    //
    
    if(Box)
    {  simulation_name=(char *)"Box_sim_";}
    if(L_shaped)
    {   simulation_name=(char *)"Lshaped_sim_";}
    if(Blackbird)
    {
        simulation_name=(char *)"Blackbird_sim_";
    }
    if(CSF)
    {   simulation_name=(char *)"CSF_sim_";}
    if(Albert)
    {   simulation_name=(char *)"Albert_sim_";}
    if(Canyon)
    {  simulation_name=(char *)"Canyon_sim_";}
    if(Isolated_Wall)
    {   simulation_name=(char *)"Isolated_Wall_sim_";}
    
    //delete me
    //    double az=40;
    //    double el=10;
    ////////////
    
    char * arrivalaz= new char[200];
    char * arrivalel= new char[200];
    char * sim_number= new char[200];
    char * rec_number= new char[200];
    
    snprintf(arrivalaz, 200, "%f", az);
    snprintf(arrivalel, 200, "%f", el);
    snprintf(sim_number, 200, "%i", Which_Simulation);
    snprintf(rec_number, 200, "%i", Which_Receiver);
    
    strcat(fullsimulation_name,simulation_name);
    strcat(fullsimulation_name,"_");
    strcat(fullsimulation_name,sim_number);
    strcat(fullsimulation_name,"_");
    strcat(fullsimulation_name,rec_number);
    strcat(fullsimulation_name,"_");
    strcat(fullsimulation_name,arrivalaz);
    strcat(fullsimulation_name,"_az_");
    strcat(fullsimulation_name,arrivalel);
    strcat(fullsimulation_name,"_el_");
    
    
    ////////END CHOSE SOURCE POSITIONS/////////
    
    ///Let's have a look
       const char * contourFileName="/Users/mandalin/Desktop/Sort Me Now/Dissertation_PLdB_PostProcessing/Contours/Wall_sim_0_noHPFing/NumRefs_Contour_Wall_1.txt";
    
    //PLdB CONTOURS
    
    //const char * contourFileName="/Users/mandalin/Desktop/Dissertation_PLdB_PostProcessing/PLdB Contours/Blackbird_sim_0_noHPFing/PLdB_Contour_Output3.txt";
    //const char * contourFileName="/Users/mandalin/Desktop/Dissertation_PLdB_PostProcessing/PLdB Contours/Blackbird_sim_37_noHPFing/PLdB_Contour_Output3.txt";
    //const char * contourFileName="/Users/mandalin/Desktop/Dissertation_PLdB_PostProcessing/PLdB Contours/L_Shape_sim_1_noHPFing/PLdB_Contour_Output3.txt";
    //const char * contourFileName="/Users/mandalin/Desktop/Dissertation_PLdB_PostProcessing/PLdB Contours/L_Shape_sim_2_noHPFing/PLdB_Contour_Output3.txt";
    
    //Pmax Contours
    //const char * contourFileName="/Users/mandalin/Desktop/Dissertation_PLdB_PostProcessing/PLdB Contours/Blackbird_sim_0_noHPFing/Pmax_Contour_Output3.txt";
    //const char * contourFileName="/Users/mandalin/Desktop/Dissertation_PLdB_PostProcessing/PLdB Contours/BlackBird_sim_37_noHPFing/Pmax_Contour_Output3.txt";
    //const char * contourFileName="/Users/mandalin/Desktop/Dissertation_PLdB_PostProcessing/PLdB Contours/L_Shape_sim_1_noHPFing/Pmax_Contour_Output3.txt";
    //const char * contourFileName="/Users/mandalin/Desktop/Dissertation_PLdB_PostProcessing/PLdB Contours/L_Shape_sim_2_noHPFing/Pmax_Contour_Output3.txt";
    //
                if(Plot_Contour)
                {     TerrainMesh_Contour(planes,initial_microphone_positions,num_points_in_plane_mapping,resolution,contourFileName, fullsimulation_name,Save_Contour, NumRefs_Plot, Pmax_Plot, PldB_Plot );
                }
    
    //    //TerrainMesh_Contour(planes,initial_microphone_positions,num_points_in_plane_mapping,resolution,contourPmaxFileName,0);
    //    //TerrainMesh_Contour(planes,initial_microphone_positions,num_points_in_plane_mapping,resolution,contourPLDBFileName,1);
    //
    
    
    
    
    
    
    
    
    
    
    
    //////////////////////////////////////////////////////
    //          Select which receiver position          //
    //////////////////////////////////////////////////////
    
    
    position_vector Ppos;
    Ppos.assign(Ppos_vector[Which_Receiver]);
    
    //////////////////////////////////////////////////////
    //          Prepare to Write File                   //
    //////////////////////////////////////////////////////
    
    int Which_IR__=Which_Receiver;
    //Write A file to hoLf the information of source position
    char* whole_diff_filename_IR = new char[500];
    // char * arrivalaz= new char[500];
    // char * arrivalel= new char[500];
    // char * sim_number= new char[500];
    char * ir_number= new char[500];
    
    char * Ppos_x= new char[500];
    char * Ppos_y= new char[500];
    char * Ppos_z= new char[500];
    
    // snprintf(arrivalaz, 79, "%f", phi__);
    // snprintf(arrivalel, 79, "%f", theta_i__);
    snprintf(ir_number, 79, "%i", Which_IR__);
    //  snprintf(sim_number, 79, "%i", Which_SIM__);
    
    snprintf(Ppos_x, 79, "%f", Ppos.x);
    snprintf(Ppos_y, 79, "%f", Ppos.y);
    snprintf(Ppos_z, 79, "%f", Ppos.z);
    
    strcat(whole_diff_filename_IR,directory);
    //strcat(whole_filename_IR,"_");
    strcat(whole_diff_filename_IR,simulation_name);
    strcat(whole_diff_filename_IR,"_BTM_");               ///FOR BTM
    //strcat(whole_diff_filename_IR,"_UTD_");                 ///FOR UTD
    strcat(whole_diff_filename_IR,sim_number);
    strcat(whole_diff_filename_IR,"_");
    
    //lets append zeros to the simulation number
    
    int numdigets= strlen(ir_number);
    char* zeros=new char[10];
    
    zeros[0] = '\0';
    
    for(int addzeros=7-numdigets; addzeros>0; addzeros--)
    {
        strcat(zeros,"0");
    }
    strcat(zeros,ir_number);
    
    strcat(whole_diff_filename_IR,zeros);
    strcat(whole_diff_filename_IR,"_IR_");
    strcat(whole_diff_filename_IR,arrivalaz);
    strcat(whole_diff_filename_IR,"_az_");
    strcat(whole_diff_filename_IR,arrivalel);
    strcat(whole_diff_filename_IR,"_el_Ppos_");
    strcat(whole_diff_filename_IR,Ppos_x);
    strcat(whole_diff_filename_IR,"i_");
    strcat(whole_diff_filename_IR,Ppos_y);
    strcat(whole_diff_filename_IR,"j_");
    strcat(whole_diff_filename_IR,Ppos_z);
    strcat(whole_diff_filename_IR,"k.txt");
    std::cout<<whole_diff_filename_IR<<std::endl;
    
    //////////////////////////////////////////////////////
    //   Amass A collection of edges from all planes    //
    //////////////////////////////////////////////////////
    
  
    //int num_original_walls=planes.size(); //happens above
    int num_corners_in_plane;
    double solidangle=NaN;
    Edge * SingleEdge;
    int tempcorn1,tempcorn2;
    
    //Define the pointer
    Edge * EdgeHead=NULL;

    
    
    for(int i=0; i<num_original_walls; i++)
    {
        num_corners_in_plane=planes[i].corners.size();
        
        for(int edgeind=0; edgeind<num_corners_in_plane; edgeind++)
        {
            //Corners 27 and 148 Two are equivalent
            // if wall1 is unknown, make it a negative 1, wall 29 is the front of the garag
            
            tempcorn1=planes[i].corner_indices[edgeind];
            tempcorn2=planes[i].corner_indices[(edgeind+1) % num_corners_in_plane];
            
            SingleEdge = new Edge();
            SingleEdge->assign(tempcorn1, tempcorn2, i, solidangle, unique_corners_output, planes);
            
            //Find the Norm of One Wedge Face
            position_vector surface1_norm;
            surface1_norm=SingleEdge->walls_along_edge[0]->normal;
            
            Edge * Ptr_To_Edge2Add;
            Ptr_To_Edge2Add = SingleEdge;
            
            EdgeHead=SingleEdge->AddEdge(unique_corners_output, EdgeHead, Ptr_To_Edge2Add, planes);
            
            
        }
    }
    
    

    /////////////////////////////////////
    ////      For Single Edge BTM      //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    //clock_t t;
    //t = clock();

    //            //Corners 27 and 148 Two are equivalent
    //            // if wall1 is unknown, make it a negative 1, wall 29 is the front of the garage
    //            Edge TempSingleEdge;
    //            TempSingleEdge.assign(13,148,29, solidangle, unique_corners_output,planes); //first two corners are in Right Hand Order
    //            
    //            //void  assign(int corn1, int corn2, int wall1, double solid_angle, std::vector<corner> all_unique_corners, std::vector<wall> planes)
    //            TempSingleEdge.wall2ind=6;
    //            TempSingleEdge.walls_along_edge.push_back(& planes[6]);
    //            TempSingleEdge.Calculate_Solid_Angle();
    //            
    //            //Find the Norm of One Wedge Face
    //            position_vector surface1_norm;
    //            surface1_norm=TempSingleEdge.walls_along_edge[0]->normal;
    //            
    //            Edge * Ptr_To_Edge2Add;
    //            Ptr_To_Edge2Add = &TempSingleEdge;
    //            //Edge * EdgeHead;
    //            EdgeHead=NULL;
    //            
    //            TempSingleEdge.AddEdge(unique_corners_output, EdgeHead, Ptr_To_Edge2Add);
    //            
    //            double fsdiff=48000;
    //            //
    //            //    std::vector<int> viableplanes;
    //            //    for(int planeInd=0;planeInd<121;planeInd++)
    //            //    {
    //            //        for(int cornInd=0; cornInd<planes[planeInd].corner_indices.size() ;cornInd++)
    //            //        {  if(planes[planeInd].corner_indices[cornInd]==13)
    //            //            {   viableplanes.push_back(planeInd);
    //            //            }
    //            //        }
    //            //    }
    //            //
    //            OneEdgeBTM(TempSingleEdge, surface1_norm, Qpos, Ppos ,  co /*soundspeed*/,  fsdiff, simnum_,  Which_Receiver, whole_diff_filename_IR, directory, unique_corners_output);   //
    
    //t = clock() - t;
    //printf ("It took me %d clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
    
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    /////////////////////////////////////
    ////      For Single Edge BTM      //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    clock_t t;
    t = clock();
    
    //            //Corners 27 and 148 Two are equivalent
    //            // if wall1 is unknown, make it a negative 1, wall 29 is the front of the garage
                Edge * TempSingleEdge;
                TempSingleEdge = EdgeHead->next;
                TempSingleEdge->Calculate_Solid_Angle();
    //            TempSingleEdge.assign(13,148,29, solidangle, unique_corners_output,planes); //first two corners are in Right Hand Order
    //
    //            //void  assign(int corn1, int corn2, int wall1, double solid_angle, std::vector<corner> all_unique_corners, std::vector<wall> planes)
    //            TempSingleEdge.wall2ind=6;
    //            TempSingleEdge.walls_along_edge.push_back(& planes[6]);
    //            TempSingleEdge->Calculate_Solid_Angle();
    //
                //Find the Norm of One Wedge Face
                position_vector surface1_norm;
                surface1_norm=TempSingleEdge->walls_along_edge[0]->normal;
    //
    //            Edge * Ptr_To_Edge2Add;
    //            Ptr_To_Edge2Add = &TempSingleEdge;
    //            //Edge * EdgeHead;
    //            EdgeHead=NULL;
    //
    //            TempSingleEdge.AddEdge(unique_corners_output, EdgeHead, Ptr_To_Edge2Add);
    //
                double fsdiff=48000;
    //            //
    //            //    std::vector<int> viableplanes;
    //            //    for(int planeInd=0;planeInd<121;planeInd++)
    //            //    {
    //            //        for(int cornInd=0; cornInd<planes[planeInd].corner_indices.size() ;cornInd++)
    //            //        {  if(planes[planeInd].corner_indices[cornInd]==13)
    //            //            {   viableplanes.push_back(planeInd);
    //            //            }
    //            //        }
    //            //    }
    //            //
    
                Which_Receiver=4;
                Ppos.assign(Ppos_vector[Which_Receiver]);
                TempSingleEdge->alpha_w=2*pi;
    
                OneEdgeBTM(*TempSingleEdge, surface1_norm, Qpos, Ppos ,  co /*soundspeed*/,  fsdiff, simnum_,  Which_Receiver, whole_diff_filename_IR, directory, unique_corners_output);   //
    
    t = clock() - t;
    printf ("It took me %d clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
    
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ///////////////////////////////////
    //      For Single Edge UTD      //
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    //    clock_t t;
    //    t = clock();
    
    //    double solidangle=pi/2.0;
    //    Edge SingleEdge;
    //    SingleEdge.assign(13,27, solidangle, unique_corners_output);
    //
    //
    //    //Find the Norm of One Wedge Face
    //
    //    //this bottom edge was sort of a brute force way to get the proper norm, we can't use this method
    //    position_vector bottom_edge(unique_corners_output[0].x-unique_corners_output[13].x, unique_corners_output[0].y-unique_corners_output[13].y, unique_corners_output[0].z-unique_corners_output[13].z );
    //    bottom_edge.assign(bottom_edge.x/magnitude(bottom_edge),bottom_edge.y/magnitude(bottom_edge),bottom_edge.z/magnitude(bottom_edge));
    //    position_vector surface1_norm;
    //    surface1_norm=cross(SingleEdge.edge_vector_normalized,bottom_edge);
    //    double fsdiff=48000;
    //
    //    //Qpos.assign(200,-200,200);
    //    OneEdgeUTD(SingleEdge, surface1_norm, Qpos, Ppos ,  co /*soundspeed*/,  fsdiff, simnum_,  Which_Receiver, whole_diff_filename_IR, directory);   //
    //
    
    //    t = clock() - t;
    //    printf ("It took me %d clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    
    
    
    
    /////////////////////////////////////
    ////    Here We Plot the Geom      //
    /////////////////////////////////////
    Plot_RecPos=true;
    
    if(plot_geom)
    {
    TerrainMesh(planes, Ppos_vector, Plot_RecPos);
    plot_FieldAngle(planes);
    }
    
    
    
    
    //	//*2.---------Frequency Bands--------------*
    
    int num_bands=43;
    int nb[num_bands-1];
    int f_bands[num_bands-1];
    
    for(int i=1; i<=43; i++)
    {	nb[i]=i;
        f_bands[i]=pow(10,(nb[i]/10));
    }
    
    
    //	//% *4c.------Plot the Original Source Orientation---------------------------------*
    
    
    //Canyon DEM
    if(Canyon)
    {
        //                plot_SGR_Orientation(Qpos,planes, min_elevation, max_elevation, center_pt ,Ppos);
    }
    //Box and L and Blackbird
    if(Box || L_shaped || Blackbird)
    {
        //               plot_FieldAngle(planes);
    }
    
    //	//%*-5.------Definition of First Order Mirrored sources
    //	//%          Generalize Sources into A structure----------------------------*
    
    int num_planes=planes.size() ;
    int num_sources;
    num_sources= pow((num_planes-1),max_order);
    printf("\nWith %i planes and a max order of %i, we have a max of %i sources\n", num_planes, max_order, num_sources);
    //*-5a Add Mother Sources
    std::vector<source> sources;
    sources.clear(); 
    
    source qtemp(Qpos.x, Qpos.y, Qpos.z, 0/*order*/, NaN/*mothersourceind*/, NaN/*motherwallind*/, 1,0/*audible*/,1/*legal*/);
    sources.push_back(qtemp);
    
    //   std::cout<<"Number of sources now = "<<    sources.size()<<"  This is the Original Source"<<std::endl;
    
    //%*-5b Add First Order Image Sources
    
    bool is_shaded;
    position_vector n;
    position_vector mother_source_pos;
    position_vector new_source_pos;
    position_vector temp1;
    corner onecorner;
    double d, horizontal_r,elevation_confirm,azimuth_confirm;
    
    std::cout<<"There are "<<num_planes<<" planes"<<std::endl;
    for(int i=0; i<num_planes; i++)
    {	mother_source_pos=sources[0].position;
        
        
        //confirm that source position is as intended
        horizontal_r=std::sqrt(mother_source_pos.x*mother_source_pos.x + mother_source_pos.y*mother_source_pos.y);
        elevation_confirm=atan(mother_source_pos.z/horizontal_r)*(180/pi);
        azimuth_confirm=atan(mother_source_pos.x/mother_source_pos.y)*(180/pi); //this is only useful for confirming the wall case. 
        
        
        
        
        
        n=planes[i].normal ;
        //std::cout<<"Source # "<<i+1<<": n= "<<n.x <<" "<<n.y<<" "<<n.z<<std::endl;
        onecorner=planes[i].corners[1];
        //std::cout<<"Source # "<<i+1<<": mother= "<<mother_source_pos.x <<" "<<mother_source_pos.y<<" "<<mother_source_pos.z<<std::endl;
        //std::cout<<"Source # "<<i+1<<": corner= "<<onecorner.x <<" "<<onecorner.y<<" "<<onecorner.z<<std::endl;
        temp1=sub(mother_source_pos,onecorner);
        //std::cout<<"Source # "<<i+1<<": sub= "<<temp1.x <<" "<<temp1.y<<" "<<temp1.z<<std::endl;
        d=dot(temp1,n);
        //std::cout<<"Source # "<<i+1<<": d= "<<d<<std::endl;
        new_source_pos.assign(mother_source_pos.x-d*2*n.x,mother_source_pos.y-d*2*n.y,mother_source_pos.z-d*2*n.z);
        //std::cout<<"Source # "<<i+1<<": at "<<new_source_pos.x <<" "<<new_source_pos.y<<" "<<new_source_pos.z<<std::endl;
        
        
        if(d>0.0)
        {is_shaded=shaded_center(planes,i,mother_source_pos,sources[0],num_original_walls);}
        
        
        
        /*
         for(int i=0; i<planes.size(); i++)
         {
         std::cout<<"Plane["<<i<<"].normal= ";;
         print(planes[i].normal);
         std::cout<<std::endl;
         }
         */
        
        
        
        
        if( (d>0)&&(not(is_shaded))) //mother source must be inside for image
            //to be created, and the  path to the mother
            //plane must not be blocked by other planes
            
        {   qtemp.assign(new_source_pos.x,new_source_pos.y,new_source_pos.z,1/*order*/,0/*mothersource*/,i,1/*strength*/,0/*audible*/,1/*legal*/);
            qtemp.source_number=i+1;
            sources.push_back(qtemp);
            std::cout<<"Number of sources now = "<<    sources.size()<<std::endl;
            // std::cout<<"Source # "<<i+1<<": located at "<<qtemp.position.x <<" "<<qtemp.position.y<<" "<<qtemp.position.z<<std::endl;
            //std::cout<<"Source # "<<i+1<<": located at "<<sources[i].position.x <<" "<<sources[i].position.y<<" "<<sources[i].position.z<<std::endl;
        }
        
        if((d<=0)||(is_shaded))
        {
            qtemp.assign(0,0,0,1/*order*/,0/*mothersource*/,i/*motherwallind*/,0/*strength*/,0/*audible*/,0/*legal*/);
            qtemp.source_number=i+1;
            sources.push_back(qtemp);
            std::cout<<"Number of sources now = "<<    sources.size();
            //std::cout<<"Source # "<<i+1<<": located at "<<qtemp.position.x <<" "<<qtemp.position.y<<" "<<qtemp.position.z<<std::endl;
            //std::cout<<"Source # "<<i+1<<": located at "<<sources[i].position.x <<" "<<sources[i].position.y<<" "<<sources[i].position.z<<std::endl;
            
            if ((d<=0)&&(is_shaded))
                std::cout<<"   Invalid -> Is not inside & Is Shaded, MthrWall "<<qtemp.mother_wall_ind<<std::endl;
            else
            {   if(d<=0)
                std::cout<<"   Invalid -> Is Outside, MthrWall "<<qtemp.mother_wall_ind<<std::endl;
            else
                std::cout<<"   Invalid -> Is Shaded, MthrWall "<<qtemp.mother_wall_ind<<std::endl;
            }
        }
        
    }
    
    
    //Plot the First Order ISM
    std::cout<<"~~~~~~~~~~~~~~Plotting First Order Sources~~~~~~~~~~~~~~"<<std::endl;
    //plot_ISM1stOrd(sources); //this is just for L shaped
    //plot_FieldAngle(sources);
    //plot_GeometryGeneral(planes,sources);
    ////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout<<"           Moving On to 2nd Order Sources"<<std::endl;
    
    ////%*-5.------Definition of Higher Order Mirrored sources
    ////%          Generalize Sources into A structure----------------------------*
    //
    
    //============things declared for calculation of first order==========//
    //int num_planes=planes.size() ;
    //int num_sources=pow((num_planes-1),max_order);
    //*-5a Add Mother Source
    //std::vector<source> sources;
    //source qtemp(Qpos.x,Qpos.y,Qpos.z,0/*order*/,NAN/*mothersource*/,NAN/*motherwall*/,1,0/*audible*/,1/*legal*/);
    //bool is_shaded;
    //position_vector n;
    //position_vector mother_source_pos;
    //position_vector new_source_pos;
    //position_vector temp1;
    //double d;
    //^^^^^^^^^^things declared for calculation of first order^^^^^^^^^^^//
    
    bool is_in_field_angle;
    bool all_illegal_last_order=false;
    
    int first_source_of_order[max_order];  //this maps source index to source order
    int mother_index_first;
    int mother_index_last;
    first_source_of_order[0]=0;
    first_source_of_order[1]=1;
    
    wall tempwall;
    // std::vector<wall> partioned_walls;
    // partioned_walls.clear();
    
    for (int order=2; order<=max_order; order++)            //LOOPS OVER ORDER
    {
        first_source_of_order[order]=sources.size();
        
        
        if(order==3)
        {     std::cout<<"~~~~~~~~~~~~~~Moving on to 3rd Order Sources~~~~~~~~~~~~~~"<<std::endl;
        }
        
        if(order>3)
        {     std::cout<<"~~~~~~~~~~~~~~Moving on to "<<order<<"th Order Sources~~~~~~~~~~~~~~"<<std::endl;
            
        }
        
        
        mother_index_first=first_source_of_order[order-1];
        mother_index_last=first_source_of_order[order]-1;
        all_illegal_last_order=true;
        
        for(int mother_index=mother_index_first; mother_index<=mother_index_last; mother_index++)           //LOOPS OVER MOTHER_INDEX
        {
            
            if(sources[mother_index].legal)                                                                 //IF MOTHER AT INDEX IS LEGAL
            {
                all_illegal_last_order=false;
                
                for(int plane_index=0; plane_index<num_original_walls; plane_index++)                       //LOOPS OVER PLANES
                {
                    //Calcuates where the new source would be
                    mother_source_pos.assign(sources[mother_index].position);
                    n=planes[plane_index].normal;
                    onecorner=planes[plane_index].corners[1];
                    //std::cout<<"Source # "<<i+1<<": mother= "<<mother_source_pos.x <<" "<<mother_source_pos.y<<" "<<mother_source_pos.z<<std::endl;
                    //std::cout<<"Source # "<<i+1<<": corner= "<<onecorner.x <<" "<<onecorner.y<<" "<<onecorner.z<<std::endl;
                    temp1=sub(mother_source_pos,onecorner);
                    //std::cout<<"Source # "<<i+1<<": sub= "<<temp1.x <<" "<<temp1.y<<" "<<temp1.z<<std::endl;
                    d=dot(temp1,n);
                    //std::cout<<"Source # "<<i+1<<": d= "<<d<<std::endl;
                    new_source_pos.assign(mother_source_pos.x-d*2*n.x,mother_source_pos.y-d*2*n.y,mother_source_pos.z-d*2*n.z);
                    //std::cout<<"Source # "<<i+1<<": at "<<temp1.x <<" "<<temp1.y<<" "<<temp1.z<<std::endl;
                    
                    
                    
                    //Inside Test is d>0.0
                    //Shaded Test identifies reflecting plane is in line of sight of mother source
                    
                    if(d>0.0)
                        // is_shaded=shaded_center(planes,plane_index,mother_source_pos,sources[mother_index],num_original_walls);
                        is_shaded=false;
                    else
                        is_shaded=true; //% this forgoes calculating whether the source is
                    //% shaded when already illegal (behind reflector)
                    
                    if( (d>0)&&(not(is_shaded)))
                    {
                        
                        std::vector<corner> new_corners;
                        std::vector<int> numpointsperpoly; //this is a vector, because there may be many polygons.
                        
                        is_in_field_angle=
                        in_field_angle_corners(
                                               sources /*sources*/,
                                               planes /*planes*/,
                                               mother_index /*mother_source_index*/,
                                               sources[mother_index].mother_wall_ind /*mother_wall_index*/,
                                               plane_index /*new_mother_wall_index*/,
                                               new_corners /*vector of corners defining the illuminated spot*/,
                                               numpointsperpoly /*number of points for each polygon*/);
                        
                        
                        //unlike first order sources, we need to include the in field angle test here.
                        
                        
                        //!ACHTUNG3! if you want to save memory. put in an if statement here that only creates a partiton plane
                        //if the entire new mother plane is not within the field angle. Here it duplicates the plane.
                        bool final_test_is_shaded=false;
                        if(is_in_field_angle)
                        {   //we gain a new partition wall and a new source
                            tempwall.corners=new_corners;
                            tempwall.normal=planes[plane_index].normal;
                            tempwall.mother_wall_numpointsperpoly=numpointsperpoly;
                            tempwall.num=plane_index;
                            tempwall.num_corners=new_corners.size();
                            tempwall.center=centerOgravity(tempwall);
                            tempwall.reorder_corners();
                            
                            
                            /*new wall struct*/
                            
                            //stop here and check if path to this new plane is shaded
                            
                            position_vector center3dplane=tempwall.center;
                            
                            //Find where line from source to line from source to new mother wall intersects old mother wall
                            //this is where the source should originate
                            
                            mother_source_pos.v[0]=mother_source_pos.x;
                            mother_source_pos.v[1]=mother_source_pos.y;
                            mother_source_pos.v[2]=mother_source_pos.z;
                            
                            position_vector n;
                            n.assign(planes[sources[mother_index].mother_wall_ind].normal);
                            double d=dot(planes[sources[mother_index].mother_wall_ind].corners[0],n);
                            double temp0;
                            temp0=dot(mother_source_pos,n);
                            position_vector diff=sub(center3dplane,mother_source_pos);
                            double temp1;
                            temp1=dot(diff,n);
                            double t=(d-temp0)/temp1;
                            position_vector intersection(mother_source_pos.v[0]+diff.v[0]*t,mother_source_pos.v[1]+diff.v[1]*t,mother_source_pos.v[2]+diff.v[2]*t);
                            
                            for (int i=0; i<num_original_walls;i++ )
                            {
                                
                                if((i!=plane_index)&&(i!=planes[sources[mother_index].mother_wall_ind].num))
                                {
                                    
                                    if(not(pointvisible(intersection, center3dplane, planes[i])))
                                    {
                                        final_test_is_shaded=true;
                                        
                                    }
                                }
                                else{}
                            }
                            
                            if(!final_test_is_shaded)
                            {    qtemp.assign(new_source_pos.x,new_source_pos.y,new_source_pos.z,order,mother_index,plane_index,1/*strength*/,0/*audible*/,1/*legal*/);
                                
                                
                                qtemp.mother_wall_ind=planes.size();
                                planes.push_back(tempwall);
                                qtemp.source_number=sources.size();
                                
                                
                                
                                sources.push_back(qtemp);
                                std::cout<<"Source # : "<<    sources.size()-1<<std::endl;
                            }
                            else
                            {   //pushes back empty source
                                qtemp.assign(0,0,0,order/*order*/,mother_index,plane_index,0/*strength*/,0/*audible*/,0/*legal*/);
                                qtemp.source_number=sources.size();
                                sources.push_back(qtemp);
                                std::cout<<"Source Number : "<<    sources.size()-1;
                                std::cout<<"   Invalid -> Field Angle Path_Obscured, MthrWall "<<plane_index<<", MthrSrc "<<mother_index<<std::endl;
                            }
                        }
                        
                        else
                        {   //pushes back empty source
                            qtemp.assign(0,0,0,order/*order*/,mother_index,plane_index,0/*strength*/,0/*audible*/,0/*legal*/);
                            qtemp.source_number=sources.size();
                            sources.push_back(qtemp);
                            std::cout<<"Source Number : "<<    sources.size()-1;
                            std::cout<<"   Invalid -> Out of Field Angle, MthrWall "<<plane_index<<", MthrSrc "<<mother_index<<std::endl;
                        }
                    }
                    
                    if((d<=0)||(is_shaded))
                    {   //push back empty, illegal source.
                        
                        qtemp.assign(0,0,0,order/*order*/,mother_index,plane_index,0/*strength*/,0/*audible*/,0/*legal*/);
                        qtemp.source_number=sources.size();
                        sources.push_back(qtemp);
                        
                        std::cout<<"Source Number : "<<    sources.size()-1;
                        
                        if ((d<=0)&&(is_shaded))
                            std::cout<<"   Invalid -> Is not inside & Is Shaded, MthrWall "<<plane_index<<", MthrSrc "<<mother_index<<std::endl;
                        else
                        {   if(d<=0)
                            std::cout<<"   Invalid -> Is Outside, MthrWall "<<plane_index<<", MthrSrc "<<mother_index<<std::endl;
                        else
                            std::cout<<"   Invalid -> Is Shaded, MthrWall "<<plane_index<<", MthrSrc "<<mother_index<<std::endl;
                        }
                        
                    }
                    
                }
            }
        }
        
        if(all_illegal_last_order)
        {
            std::cout<<"We stopped looking for new sources because every source in the last order was illegal and wont propagate new sources"<<std::endl;
            break;
        }
    }
    
    //////% *-7.------Consolidate Legal Sources-------------------------------------*
    //////% Legality check actually happens above and is recorded
    std::cout<<"~~~~~~~~~~~~~~Consolidating Legal Sources~~~~~~~~~~~~~~"<<std::endl;
    
    
    std::vector<unsigned> LegalSourceIndices;
    LegalSourceIndices.clear();
    ConsolidateLegalSources(sources,LegalSourceIndices);
    
    int last_source=LegalSourceIndices.size();
    
    for(int legal_ind=0 ; legal_ind < last_source ; legal_ind++)
    {   sources[LegalSourceIndices[legal_ind]].print(sources,planes,num_original_walls);
        
    }
    
    
    //////% *-7.------StoreSimulation-------------------------------------*
    
    bool successfully_stored=false;
    
    elevation=elevation_confirm;
    azimuth=azimuth_confirm;
    successfully_stored = StoreSimulation(Which_Simulation,num_original_walls, planes, sources, LegalSourceIndices, elevation /*elevation*/, azimuth /*azimuth*/, Temperature, simulation_name, directory);
    
    
    
    //////% *-8.------Edge Diffraction------------------------------------*
    
    //Edges are defined by pairs of corners.
    
    
    
    
    
    
    ////////% *-8a.------Consolidate Effective Sources-------------------------------------*
    ////////% Check which sources are effective and make a vector of pointers pointing to them
    
    std::cout<<"Testing Valid Sources for Audibility and Writing Output IR"<<std::endl;
    
    bool write_many_files=true;
    
    if(write_many_files)
    {    bool successful=false;
        
        char * temp_simulation_name= (char *) malloc(sizeof(char)*500);
        
        char * sim_number_= (char *) malloc(sizeof(char)*500);
        snprintf(sim_number_, 200, "%i", Which_Simulation);
        
        
        //for(unsigned simulation_iter=0; simulation_iter<Ppos_vector.size(); simulation_iter++)// to do specular IRS for all receiver positions
        for(unsigned simulation_iter=0; simulation_iter<Ppos_vector.size(); simulation_iter++)
        {  PposFinal=Ppos_vector[simulation_iter];
            
            printf("------------Simulation %i------------",simulation_iter);
            std::strcpy(temp_simulation_name,simulation_name);
            //std::cout<<temp_simulation_name<<endl;
            successful=IRsFromSources( PposFinal, LegalSourceIndices, sources,  planes, num_original_walls,  azimuth,  elevation,Which_Simulation,  simulation_iter,  co,  s,  dont_use_filtering,  use_R_coeffs,  use_R_coeffs_and_Disk_Approx,temp_simulation_name, directory);
            
            std::cout<<temp_simulation_name<<" Position "<<simulation_iter<<" was successful"<<std::endl;
            temp_simulation_name[0]='\0';
        }
    }
    
    //////% *-8b.------Consolidate Effective Sources-------------------------------------*
    ///////% Check which sources are effective and make a vector of pointers pointing to them
if(!write_many_files)
{
    FILE * writeIR;

    bool successful=false;
    char * temp_simulation_name= (char *) malloc(sizeof(char)*100);
    std::strcpy(temp_simulation_name,simulation_name);

    //Write A file to hoLf the information of source position
    char* whole_filename_IR = new char[200];
    char * arrivalaz_= new char[200];
    char * arrivalel_= new char[200];
    char * sim_number_= new char[200];
    char * ir_number= new char[200];

    char * Ppos__x= new char[200];
    char * Ppos__y= new char[200];
    char * Ppos__z= new char[200];

    snprintf(arrivalaz_, 79, "%f", az);
    snprintf(arrivalel_, 79, "%f", el);
    snprintf(sim_number_, 79, "%i", Which_Simulation);

    snprintf(Ppos__x, 79, "%f", PposFinal.x);
    snprintf(Ppos__y, 79, "%f", PposFinal.y);
    snprintf(Ppos__z, 79, "%f", PposFinal.z);

    strcat(whole_filename_IR,directory);
    strcat(whole_filename_IR,"_");
    strcat(whole_filename_IR,simulation_name);
    strcat(whole_filename_IR,sim_number_);
    strcat(whole_filename_IR,"_");

    //lets append zeros to the simulation number



    strcat(whole_filename_IR,"_IR_");
    strcat(whole_filename_IR,arrivalaz_);
    strcat(whole_filename_IR,"_az_");
    strcat(whole_filename_IR,arrivalel_);
    strcat(whole_filename_IR,"_el");
    strcat(whole_filename_IR,".txt");
    
    std::cout<<whole_filename_IR<<std::endl;

    writeIR = fopen (whole_filename_IR,"w");

    bool fileopen=writeIR;


    char* zeros=new char[10];
    for(unsigned simulation_iter=0; simulation_iter<Ppos_vector.size(); simulation_iter++)
    {
                PposFinal=Ppos_vector[simulation_iter];


                snprintf(ir_number, 79, "%i", simulation_iter);
                int numdigets= strlen(ir_number);

                zeros[0] = '\0';

                for(int addzeros=7-numdigets; addzeros>0; addzeros--)
                {
                    strcat(zeros,"0");
                }
                strcat(zeros,ir_number);


        fprintf(writeIR,"%s\t%f\t%f\t%f\n",zeros,PposFinal.x, PposFinal.y, PposFinal.z);

        successful=IRsFromSources_1file(writeIR, PposFinal, LegalSourceIndices, sources,  planes, num_original_walls,  az,  el,Which_Simulation,  simulation_iter,  co,  s,  dont_use_filtering,  use_R_coeffs,  use_R_coeffs_and_Disk_Approx,temp_simulation_name, directory);

        std::cout<<temp_simulation_name<<" Position "<<simulation_iter<<" was successful"<<std::endl;
    }


    fclose(writeIR);
}

    
    //zeros holds the number of the itteration.
    
    //////////////////////////////////////////////
    //                                          //
    //            Perform Convolution           //
    //                                          //
    //////////////////////////////////////////////
    
    //create ideal N wave with 150ms Period
    //
    //    double Period=.15;
    //    std::vector<long double> Nwave;
    // //    std::vector<long double> Nwave_buffer[N];
    //    long double value;
    //
    //    Nwave.clear();
    //    int period_in_samps=Period/dt;
    //
    //
    //    for(int samp=0; samp<period_in_samps; samp++)
    //    {
    //        value=1-(2*( ((float)samp) /period_in_samps));
    //        Nwave.push_back(value);
    //    }
    //
    //    std::vector<float> Output(period_in_samps+N-1);
    //    float tempsum=0;
    //
    //    Output.clear();
    //    for(int n=0; n<(Nwave.size()+N-1); n++)
    //    {
    //        tempsum=0;
    //
    //        for(int m=0; m<N; m++)
    //        {
    //            if((n-m>=0)&&(n-m<Nwave.size()))
    //            {
    //                tempsum=tempsum+ImpulseResponse[m] * Nwave[n-m];
    //            }
    //            if(n-m<0)
    //            { break;
    //            }
    //        }
    //
    //        Output.push_back(tempsum);
    //
    //    }
    
    //    Nwave_buffer.clear();
    //    for(int samp=0; samp<N; samp++)
    //    {
    //        if(samp<fs)
    //        {   Nwave_buffer.push_back(0);
    //        }
    //        else if(samp-fs<period_in_samps)
    //        {   value= 48*Nwave[samp-fs];
    //            Nwave_buffer.push_back(value);
    //        }
    //        else
    //        { Nwave_buffer.push_back(0);}
    //    }
    //
    
    // So... now weve got an N wave and also an impulse response. Now to perform time domain convolution
    
    
    //      for(int i=0; i<N; i++)
    //    {   NWaves_double[i][0]=NWaves_double[i][0];
    //        NWaves_double[i][1]=NWaves_double[i][1];
    //
    //
    //                    //  std::cout<< NWaves_double[i][0]<<" + "<< NWaves_double[i][1]<< " i"<<std::endl;
    //    }
    
    
    //
    //
    //    // Find FFT of Complete IR
    //    fftw_complex* H = new fftw_complex[N];
    //    fftw_complex* h = new fftw_complex[N];
    //
    //    fftw_plan p4;			//declare the plan (optimized way to calculate the FFT)
    //    p4=fftw_plan_dft_1d(N, h, H , FFTW_FORWARD, FFTW_ESTIMATE);   //This overwrites in and out... so do this before initializing
    //
    //    for(int i=0; i< N; i++)
    //    {   h[i][0]=ImpulseResponse[i]*dt;
    //        h[i][1]=0;
    //
    //   //     std::cout<<h[i][0]<<" + "<<h[i][1]<<" i "<<std::endl;
    //    }
    //
    //    //initialize a plan for the FFT /FFTW_ESTIMATE is the fastest one
    //    fftw_execute(p4);		//execute the fft
    //    fftw_destroy_plan(p4);	//deconstruct
    //
    ////    for(int i=0; i<N; i++)
    ////    {   H[i][1]=H[i][1];
    ////        H[i][0]=H[i][0];
    ////
    ////      //  std::cout<<H[i][0]<<" + "<<H[i][1]<<" i "<<std::endl;
    ////    }
    //
    //    fftw_complex* Youtput = new fftw_complex[N];
    //    fftw_complex* youtput = new fftw_complex[N];
    //    double tempmag_H,tempphi_H, tempmag_N, tempphi_N, tempmag_Y, tempphi_Y;
    //
    //    fftw_plan p5;			//declare the plan (optimized way to calculate the FFT)
    //    p5=fftw_plan_dft_1d(N, Youtput, youtput , FFTW_BACKWARD, FFTW_ESTIMATE);   //This overwrites in and out... so do this before initializing
    //
    //    double tempreal, tempimag;
    //    for(int i=0; i< N; i++)
    //    {
    //        tempreal=H[i][0];
    //        tempimag=H[i][1];
    //
    //        tempmag_H=std::sqrt((tempreal*tempreal)+(tempimag*tempimag));
    //        tempphi_H=atan(tempimag / tempreal);
    //
    //        tempreal=NWaves_double[i][0];
    //        tempimag= NWaves_double[i][1];
    //
    //        tempmag_N=std::sqrt((tempreal*tempreal)+(tempimag*tempimag));
    //        tempphi_N=atan(tempimag/tempreal);
    //
    //        tempmag_Y=tempmag_N*tempmag_H;
    //        tempphi_Y=tempphi_N+tempphi_H;
    //        Youtput[i][0]=tempmag_Y*cos(tempphi_Y)*df;
    //        Youtput[i][1]=tempmag_Y*sin(tempphi_Y)*df;
    //
    //      //  std::cout<<Youtput[i][0]<<" + "<<Youtput[i][1]<<" i "<<std::endl;
    //    }
    //    //initialize a plan for the FFT /FFTW_ESTIMATE is the fastest one
    //    fftw_execute(p5);		//execute the fft
    //    fftw_destroy_plan(p5);	//deconstruct
    //
    //
    //    for(int samp=0; samp<N; samp++)
    //    {   youtput[samp][0]=youtput[samp][0];
    //        youtput[samp][1]=youtput[samp][1];
    //
    //      //  std::cout<<youtput[samp][0]<<" + "<<youtput[samp][1]<<" i "<<std::endl;
    //    }
    //
    //////////////////////////////////////////////
    //                                          //
    //       Write Output to a text File        //
    //                                          //
    //////////////////////////////////////////////
    
    time_t seconds_end;
    seconds_end = time (NULL);
    printf ("%ld seconds since January 1, 1970 when it started", seconds_start);
    printf ("%ld seconds since January 1, 1970 when it ended", seconds_end);
    
    return;
}
#endif