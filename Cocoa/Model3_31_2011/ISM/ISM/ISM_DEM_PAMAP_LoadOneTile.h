//
//  DEM_PAMAP_LoadOneTile.h
//  ISM
//
//  Created by Amanda Lind on 10/5/11.
//  Copyright 2011 Pennsylvania State University. All rights reserved.
//

#ifndef ISM_DEM_PAMAP_LoadOneTile_h
#define ISM_DEM_PAMAP_LoadOneTile_h



#endif

std::vector<wall> ISM_DEM_PAMAP_LoadOneTile(const char * Filename, std::vector<corner> & original_corners, double min_elevation, double max_elevation, position_vector center_pt)

{
   
    
    int decimation=50;   //This is the number of original samples for every sample that is kept. 
    int     nXOff=0;    //This is the number of samples east of the NW most corner which are discarded (before decimation)
    int     nYOff=0;    //This is the number of samples south of the NW most sample which are discarded (before decimation)
    int nXSubset=3125;    //This is how many samples are taken (before decimation)
    int nYSubset=3125;    //This is hochromw many samples are taken (before decimation)
    
    

  
    //All coppied from http://www.gdal.org/gdal_tutorial.html

    //GDAL STUFF - Open File

    GDALDataset  *poDataset;

    GDALAllRegister();
    //const char * Filename = "/Users/mandalin/Desktop/DissertationCODE/Cocoa/Model3_31_2011/ISM/ISM/41002080PAN_dem/41002080PAN_dem.tif"; 

    poDataset = (GDALDataset *) GDALOpen( Filename, GA_ReadOnly );
    if( poDataset == NULL )
    {
        std::cout << "Could not load ";
        }
        
        //GDAL Stuff - Getting Data From Open File
        std::cout << "\n~~~~~~Opening GEOTIFF FILE~~~~~\n";
        
        double        adfGeoTransform[6];
        
        printf( "Driver: %s/%s\n",
               poDataset->GetDriver()->GetDescription(), 
               poDataset->GetDriver()->GetMetadataItem( GDAL_DMD_LONGNAME ) );
        
        printf( "Size is %dx%dx%d\n", 
               poDataset->GetRasterXSize(), poDataset->GetRasterYSize(),
               poDataset->GetRasterCount() );
        
        if( poDataset->GetProjectionRef()  != NULL )
        printf( "Projection is `%s'\n", poDataset->GetProjectionRef() );
        
        if( poDataset->GetGeoTransform( adfGeoTransform ) == CE_None )
        {
            printf( "Origin = (%.6f,%.6f)\n",
                   adfGeoTransform[0], adfGeoTransform[3] );
            
            printf( "Pixel Size = (%.6f,%.6f)\n",
                   adfGeoTransform[1], adfGeoTransform[5] );
        }
        
        // Fetch Raster Band
        std::cout << "\n~~~~~~Fetching Raster Band~~~~~\n";
        
        
        
        GDALRasterBand  *poBand;
        int             nBlockXSize, nBlockYSize;
        int             bGotMin, bGotMax;
        double          adfMinMax[2];
        
        poBand = poDataset->GetRasterBand( 1 );
        poBand->GetBlockSize( &nBlockXSize, &nBlockYSize );
        printf( "Block=%dx%d Type=%s, ColorInterp=%s\n",
               nBlockXSize, nBlockYSize,
               GDALGetDataTypeName(poBand->GetRasterDataType()),
               GDALGetColorInterpretationName(
                                              poBand->GetColorInterpretation()) );
        
        adfMinMax[0] = poBand->GetMinimum( &bGotMin );
        adfMinMax[1] = poBand->GetMaximum( &bGotMax );
        if( ! (bGotMin && bGotMax) )
        GDALComputeRasterMinMax((GDALRasterBandH)poBand, TRUE, adfMinMax);
        
        printf( "Min=%.3f, Max=%.3f\n", adfMinMax[0], adfMinMax[1] );
        
        if( poBand->GetOverviewCount() > 0 )
        printf( "Band has %d overviews.\n", poBand->GetOverviewCount() );
        
        if( poBand->GetColorTable() != NULL )
        printf( "Band has a color table with %d entries.\n", 
               poBand->GetColorTable()->GetColorEntryCount() );
        
        // Reading a line of data
        std::cout << "\n~~~~~~Reading a Line of Data~~~~~\n";
        
        float *pafScanline;
        
        int   nXSize = poBand->GetXSize();
        int   nYSize = poBand->GetYSize();

        
        printf( "Xsize=%.3i\n",nXSize);     printf( "Ysize=%.3i\n",nYSize); 
        printf( "Xsimulated=%.3i\n",nXSubset);     printf( "Ysimulated=%.3i\n",nYSubset); 
    
        
        corner temp_elevation_pt(0,0,0);
        float tempelevation;
        
        //Now to assemble the corners into rectangular facets. 
        

        int num_terrain_corners=ceil(ceil(nXSubset/decimation)*ceil(nYSubset/decimation)*1.1);

        
        std::vector<corner> terrain_corners(num_terrain_corners); //THIS TAKES A LONG TIME <1min tho !!!

        double surveyfoot2meters=.3048006096012192;
        unsigned corner_number=0;  
        
        for(int line_index=0; line_index<nYSubset; line_index++ ) //reads one line of the raster into pafScanline
        //for(int line_index=0; line_index<4; line_index++ ) //reads one line of the raster into pafScanline
        {
            if(line_index % decimation ==0 )
            {
                pafScanline = (float *) CPLMalloc(sizeof(float)*nXSize);
                
                poBand->RasterIO( GF_Read, nXOff, line_index, nXSize, 1, 
                                 pafScanline, nXSize, 1, GDT_Float32, 
                                 0, 0 );
                
                
                
                //for(int i=0; i<nXSize; i++)
                for(int i=0; i<nXSubset; i++)
                {   if(i % decimation == 0)
                    {
                        tempelevation=pafScanline[i];
                        
                        if(line_index==0 && i==0)
                        {   max_elevation=tempelevation;
                            min_elevation=tempelevation;
                        }
                        else
                        {   if(tempelevation<min_elevation)
                                min_elevation=tempelevation;
                            if(tempelevation>max_elevation)
                                max_elevation=tempelevation;
                        }
                        
                        terrain_corners[corner_number].assign((float)3.2*surveyfoot2meters*i,(float) 3.2*surveyfoot2meters*line_index, (float)tempelevation );
                        //    printf("Elevation [%i][%i] = %f\n",line_index,i,tempelevation);
                        //    printf("Number of Terrain Corners So Far = %i\n", (int) terrain_corners.size());
                        corner_number++;
                    }
                }
                
                CPLFree(pafScanline);
            }
        }
        
 
        
        int num_terrain_facets= (ceil(nXSubset/decimation)-1)*(ceil(nYSubset/decimation)-1);
        
        
        std::vector<wall> faces;   //can't preallocate a structure containing types of variable length
        wall tempface;  
        
        
        unsigned top_left_corn, row_num, col_num;
        unsigned face_corn_inds[4];
        unsigned corner_index;
        corner tempcorn;
        int size_of_face;
        
        for(int  face_ind=0; face_ind<num_terrain_facets;  face_ind++)
        {
            
            row_num=std::ceil( ((float)face_ind+1) / ((float)ceil(nXSubset/decimation)-1));
            col_num=(face_ind % ((int)ceil(nXSubset/decimation)-1)) + 1;   //nXSize-1 is the number of faces in a row
            
            top_left_corn=col_num+(row_num-1)*(ceil(nXSubset/decimation))-1+row_num-1;
            
            face_corn_inds[0]=top_left_corn;
            face_corn_inds[1]=top_left_corn+ceil(nXSubset/decimation)+1;
            face_corn_inds[2]=top_left_corn+ceil(nXSubset/decimation)+1+1; 
            face_corn_inds[3]=top_left_corn+1;
            
            
            
            tempface= wall(face_corn_inds,4); 
            
            for(int ind=0; ind< 4; ind++)
            {   
                corner_index=tempface.corner_indices[ind];
                tempcorn=terrain_corners[corner_index];
                tempface.corners.push_back(tempcorn);
                
            }
            tempface.num=face_ind;
            tempface.setnorm();               
            tempface.mother_wall_numpointsperpoly.push_back(tempface.num_corners);//assumes each face is a single polygon
            
            
            faces.push_back(tempface);
            
            //size_of_face=sizeof(tempface);
            
        }
        
        
        //Now to plot the content of the nine faces to determine whether we are getting what we were after...
        
       /* for(int  face_ind=0; face_ind<num_terrain_facets;  face_ind++)
        {
            
            printf("\n  For face number %i, Corners are: \n",face_ind);
            print( faces[face_ind].corners[0]);
            print( faces[face_ind].corners[1]);
            print( faces[face_ind].corners[2]);
            print( faces[face_ind].corners[3]);
            std::cout<<std::endl;
        }
        */
    
    position_vector human_height(0,0,1.2);
    center_pt=add(terrain_corners[ceil(ceil((nXSubset/decimation)*ceil(nYSubset/decimation))/2)],human_height);
    
    original_corners=terrain_corners;

    
    return faces;
}