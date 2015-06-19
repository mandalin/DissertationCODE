//
//  StoreSimulation.h
//  ISM
//
//  Created by Amanda Lind on 12/4/11.
//  Copyright 2011 Pennsylvania State University. All rights reserved.
//

#ifndef ISM_StoreSimulation_h
#define ISM_StoreSimulation_h


bool StoreSimulation(unsigned sim_num, unsigned num_original_walls, std::vector<wall> planes, std::vector<source> sources, std::vector<unsigned> legal_sources, double elevation_angle, double azimuth_angle, double tempC, char* simulation_name,const char* directory)
{

    FILE * write;
    
   // const char* directory = "/Users/mandalin/Desktop/Xcode Output/";
    
    const char* sources_ = "sources_";
    const char* walls_ = "walls_";
    
    
    //Write A file to hoLf the information of source position 
    char* whole_filename_src = (char *) malloc(sizeof(char)*400);
    char * arrivalaz= (char*)malloc(200*sizeof(char));
    char * arrivalel= (char*)malloc(200*sizeof(char));
    char * sim_number= (char*)malloc(10*sizeof(char));
    
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

    write = fopen (whole_filename_src,"w");
    
    if(write)
    {
        fprintf(write, "Arrival Angles: %f azimuth , %f elevation \n", azimuth_angle, elevation_angle);
        fprintf(write, "Temperature: %f\n\n", tempC);
        
        unsigned source_ind;
        for(int legal_ind=0; legal_ind<legal_sources.size(); legal_ind++)
        {  
            source_ind=legal_sources[legal_ind];
            fprintf(write, "SrcNumber: %i \n", sources[source_ind].source_number);
            fprintf(write, "SrcPosition: %f , %f , %f \n", sources[source_ind].position.x, sources[source_ind].position.y, sources[source_ind].position.z);
            fprintf(write, "Order: %i \n", sources[source_ind].order);
          //  fprintf(write, "Strength: %f \n", sources[source_ind].strength);
            fprintf(write, "MotherSource: %i \n", sources[source_ind].mother_source_ind);
            fprintf(write, "MotherWall: %i \n\n", sources[source_ind].mother_wall_ind);
    
        }
        
        fclose(write);
        
    }
    else
    {
        std::cout<<"CouLfnt Open File"<<std::endl;
    }
    
    
    
    //Write A file to hold the information of walls  
    
    char* whole_filename_wall = (char *) malloc(sizeof(char)*400);
    strcat(whole_filename_wall,directory);
    strcat(whole_filename_wall,simulation_name);
    strcat(whole_filename_wall,"_");
    strcat(whole_filename_wall,sim_number);
    strcat(whole_filename_wall,"_");
    strcat(whole_filename_wall,walls_);
    strcat(whole_filename_wall,arrivalaz);
    strcat(whole_filename_wall," az_");
    strcat(whole_filename_wall,arrivalel);
    strcat(whole_filename_wall," el.txt");    
    
    FILE * write2;
    
    write2 = fopen (whole_filename_wall,"w");
    
    if(write2)
    {
//        unsigned num;
//        bool floorplane;
//        unsigned num_corners;
//        position_vector normal;
//        position_vector center;
//        std::vector<double> reflection_coeff; 
//        std::vector<corner> corners;
//        std::vector<int> mother_wall_numpointsperpoly; 
//        std::vector<unsigned> corner_indices;
//        static std::vector<corner> unique_corners;   
        
        
        
        fprintf(write2, "~~~~~~~~~~~~AllUniqueCorners: \n" );
        
        for(unsigned corner_ind=0; corner_ind<planes[0].unique_corners.size(); corner_ind++)
        {   fprintf(write2,"CornerNum[0]=( %f , %f , %f)\n", planes[0].unique_corners[corner_ind].x,  planes[0].unique_corners[corner_ind].y,  planes[0].unique_corners[corner_ind].z);
        }
        
        
        
        
        fprintf(write2, "\n~~~~~~~~~~~~AllWalls:\n" );
        for(unsigned wall_ind=0; wall_ind<planes.size(); wall_ind++)    //this couLf be rewritten to only make note of the planes that are actually used. 
        {                                                               //how do we handle multiple polygons... 
             

    

            fprintf(write2, "WallNumber: %i \n", planes[wall_ind].num);
            fprintf(write2, "FloorPlane: %i \n", planes[wall_ind].floorplane);
            fprintf(write2, "NumberCorners: %i \n", planes[wall_ind].mother_wall_numpointsperpoly[0]);  //only works for single oplygons
            fprintf(write2, "WallCenter: ( %f, %f, %f)\n", planes[wall_ind].center.x, planes[wall_ind].center.y, planes[wall_ind].center.z);
            fprintf(write2, "WallNormal: ( %f, %f, %f)\n", planes[wall_ind].normal.x, planes[wall_ind].normal.y, planes[wall_ind].normal.z);
            
            
            fprintf(write2, "Corners:\n");
            unsigned index_of_corner=0;
            std::cout<<std::endl<<"NextWall"<<std::endl;
            
            if(wall_ind== num_original_walls)
            {   
                fprintf(write2,  "         Moving On to Projected Walls \n");
            }
            
            for(unsigned which_corn=0; which_corn<planes[wall_ind].corners.size(); which_corn++ )
            {    
                if(wall_ind< num_original_walls)
                {   index_of_corner=planes[wall_ind].corner_indices[which_corn];
                    std::cout<<std::endl<<index_of_corner<<std::endl;
                
                fprintf(write2,  "         CornerInd[%i]=( %f, %f, %f)\n",index_of_corner, planes[wall_ind].corners[which_corn].x, planes[wall_ind].corners[which_corn].y, planes[wall_ind].corners[which_corn].z);
                }
                

                if(wall_ind>= num_original_walls)
                {  
                    
                    fprintf(write2,  "         CornerInd[%i]=( %f, %f, %f)\n",which_corn, planes[wall_ind].corners[which_corn].x, planes[wall_ind].corners[which_corn].y, planes[wall_ind].corners[which_corn].z);
                }
            }
            
            
            
            fprintf(write2, "ReflectionCoeff:  \n");
            for(unsigned which_bin=0; which_bin<planes[wall_ind].reflection_coeff.size(); which_bin++) {
                fprintf(write2, "%f\t",planes[wall_ind].reflection_coeff_frequencies[which_bin]);
            }
            for(unsigned which_bin=0; which_bin<planes[wall_ind].reflection_coeff.size(); which_bin++) {
                fprintf(write2, "%f\t",planes[wall_ind].reflection_coeff[which_bin]);
            }

        }
        
        fclose(write2);
        
    }
    else
    {
        std::cout<<"CouLfnt Open File"<<std::endl;
    }
    
    
    printf("The Azimuth is: %s, The Elevation is: %s\n", arrivalaz, arrivalel);
    return 0;
    
    
    
}

#endif
