//
//  TerrainMesh_Contour.h
//  ISM
//
//  Created by Amanda Lind on 2/18/12.
//  Copyright 2012 Pennsylvania State University. All rights reserved.
//

#ifndef ISM_TerrainMesh_Contour_h
#define ISM_TerrainMesh_Contour_h
#include <stdio.h>
#include <strings.h>


void  TerrainMesh_Contour(std::vector<wall> walls, int initial_microphone_positions, std::vector<unsigned> points_per_wall, double resolution, const char * contour_text_file_name, char * simulation_name_full, bool save_contour, bool NumRefs_Plot, bool Pmax_Plot, bool PLdB_Plot, std::vector<position_vector>  Ppos_vector ,bool plot_microphones)

// void TerrainMesh() takes as an input the walls structure, creates a vtkUnstructuredGrid (the same as exists when we plot in plot_SGR_Orientation() and converts it into vtkPolyData);

{   
    bool withgeometry=true; 
    
    //Read in Text File
    
    ///////////////////////////////////////////////////////////////////
    
    
    std::string line;
    std::ifstream myfile (contour_text_file_name);
    double dubx,duby,dubz,dubPLdB;
    std::vector<double> PLdBs;
    
    
    
    unsigned linenum=0;
    unsigned IRnum_=0;
    
    
    
    
    unsigned headerlines=3;
    unsigned triangulation_set=1; //START AFTER THE HEADER. 
    double last_line;
    
    std::vector<int> start_points;
    
    //Divide the lines into sets
    start_points.push_back(0); //where header lines start
    start_points.push_back(headerlines); //where first scalar is, after the headerlines, where microphones start
    start_points.push_back(headerlines+initial_microphone_positions);
    for(int ind=0; ind< points_per_wall.size(); ind++)
    {   last_line=start_points.back();
        start_points.push_back(last_line+points_per_wall[ind]);
    }
    
    bool good;
    int number_of_sets= start_points.size()-1 ;
    
    std::vector< vtkSmartPointer<vtkPoints> > AllPLdBpoints(number_of_sets);   
    
    if (myfile.is_open())
    {   
        
        AllPLdBpoints[0]=vtkPoints::New();
        AllPLdBpoints[1]=vtkPoints::New();
        
        //  AllPLdBpoints.push_back(new vtkPoints);
        while ( myfile.good() && triangulation_set < number_of_sets )
        {  
            
            std::getline (myfile,line);
           // std::cout << line << std::endl;
            
            if(!myfile.good())
            {break;}
            
            if( linenum >= start_points[triangulation_set] )
            {
                
                ///Tokenize
                typedef std::vector <std::string> split_vector_type;
                
                split_vector_type SplitVec; // #2: Search for tokens
                boost::split( SplitVec, line, boost::is_any_of(" \t") ); // SplitVec == { "hello abc","ABC","aBc goodbye" }
                
                //                
                //                std::cout << SplitVec[0] << std::endl;
                //                std::cout << SplitVec[1] << std::endl;
                //                std::cout << SplitVec[2] << std::endl;
                //                std::cout << SplitVec[3] << std::endl;
                //                std::cout << SplitVec[4] << std::endl;
                
                //Insert these into vtk pointsc
                dubx =   boost::lexical_cast<double>(SplitVec[1]);
                duby =   boost::lexical_cast<double>(SplitVec[2]);
                dubz =   boost::lexical_cast<double>(SplitVec[3]);
                dubPLdB= boost::lexical_cast<double>(SplitVec[4]);
                
                
                
                
                // AllPLdBpoints[triangulation_set]->InsertNextPoint( dubx,duby,dubz);
                if(linenum < start_points[triangulation_set+1]) 
                {   AllPLdBpoints[triangulation_set]->InsertNextPoint( dubx,duby,dubz);
                    PLdBs.push_back(dubPLdB);
                    std::cout << line << std::endl;
                }
                
                if(linenum == start_points[triangulation_set+1]) 
                {
                    while(linenum == start_points[triangulation_set+1]) //this handles the case of empty triangulation sets.
                    {   triangulation_set++;
                            if(triangulation_set < number_of_sets)
                            {
                                AllPLdBpoints[triangulation_set]=vtkPoints::New();
                            }
                        
                        std::cout<<triangulation_set<<std::endl;
                    }
                    AllPLdBpoints[triangulation_set]->InsertNextPoint( dubx,duby,dubz);
                    PLdBs.push_back(dubPLdB);
                    std::cout << line << std::endl;
                }
                
            }
            linenum++;
        }
        myfile.close();
        
    }
    else
    {
        std::cout<<"Error Opening Contour File"<<std::endl;
    }
    
    
    
    
    
    
    std::vector< vtkSmartPointer<vtkPolyData> >     AllPLdBpolydata(number_of_sets);   
    std::vector< vtkSmartPointer<vtkDelaunay2D> >   Alldelaunay(number_of_sets);   
    std::vector< vtkSmartPointer<vtkPolyData> >     AllPLdBPolydata(number_of_sets);   
    
    for(int i =1; i<number_of_sets; i++) //Puts into a struct the way the points are organized.
    {    std::cout<<AllPLdBpoints[i]->GetNumberOfPoints()<<std::endl;
        AllPLdBPolydata[i]=vtkPolyData::New();
        AllPLdBPolydata[i]->SetPoints(AllPLdBpoints[i]);
    }
    
    
    //The color should be uniform across all sets.  
    
    //Organize thePLdB Scalars
    //Get PLdB Bounds
    double maxPL,minPL;
    
    if(NumRefs_Plot)
    {   maxPL=-999; //hardcoded for isolated wall simulation
        minPL=999; //hardcoded for isolated wall simulation
        for(int ind=0; ind< PLdBs.size(); ind++)
        {
            if(PLdBs[ind]>maxPL)
            {maxPL=PLdBs[ind];}
            if(PLdBs[ind]<minPL)
            {minPL=PLdBs[ind];}
            
        }
         minPL=0;
    }
    if(Pmax_Plot)
    {   // maxPL=140.7781;//hardcoded for isolated wall simulation
        maxPL=-999; //hardcoded for isolated wall simulation

        for(int ind=1; ind< PLdBs.size(); ind++)
        {   //PLdBs[ind]=PLdBs[ind]-0.7435;                  //this is hardcoded Pmax scale value for gac3 doubled
            //PLdBs[ind]=PLdBs[ind]-77.3308;                  //this is hardcoded scale value for gac3 doubled PLdB
            //PLdBs[ind]=PLdBs[ind]-84.13361;  //this is hardcoded PLdB of ground waveform @104 (not halved)
            PLdBs[ind]=PLdBs[ind]/47.88;     //This converts to PSF
            if(PLdBs[ind]>maxPL)
            {maxPL=PLdBs[ind];}
            
        }
                minPL=0; //hardcoded for isolated wall simulation
        
    }
    if(PLdB_Plot)
    {
        maxPL=-999; //hardcoded for isolated wall simulation
        minPL=999; //hardcoded for isolated wall simulation
        for(int ind=1; ind< PLdBs.size(); ind++)
        {
            
             //PLdBs[ind]=PLdBs[ind]-92.6044;     //Wall Input this subtracts the PLdB of the input waveform 92.6044
             PLdBs[ind]=PLdBs[ind]-99.2916;     //Wall Input this subtracts the PLdB of the input waveform x2 92.6044
            
            if(PLdBs[ind]>maxPL)
            {maxPL=PLdBs[ind];}
            if(PLdBs[ind]<minPL)
            {minPL=PLdBs[ind];}
            
        }
    }
    

    
    //                    for(int ind=0; ind< PLdBs.size(); ind++)
    //                    {   if((PLdBs[ind]<minPL))
    //                        {minPL=PLdBs[ind];}
    //                    }
    
    
    
    
    std::cout << "min PLdB " << minPL << std::endl;
    std::cout << "max PLdB " << maxPL << std::endl;
    
    
    
    
    
    // Create the color map
    
    //Fire&Ice
    double fire3,fire2,fire1, ice3, ice2, ice1;
    
    vtkColorTransferFunction * ctf = vtkColorTransferFunction::New();
    bool fireNice=PLdB_Plot;
    
    if (fireNice) {
        
        fire3=maxPL;
        ice3=minPL;
        if(PLdB_Plot)
        {   fire2=maxPL/10;
            fire1=maxPL/100;
            ice2=minPL/100;
            ice1=minPL/10;
        }else
        {   fire2=maxPL*2/3;
            fire1=maxPL/3;
            ice2=minPL*2/3;
            ice1=minPL/3;
        }
        
        
        // ctf->AddRGBPoint(fire3,         255.0/255.0,    255.0/255.0,  191.0/255.0);
        ctf->AddRGBPoint(fire3,     255.0/255.0,    255.0/255.0,  0);
        ctf->AddRGBPoint(fire1,       255.0/255.0,    0,  0);
        
        ctf->AddRGBPoint(0,1,1,1);  //change this to black if you like
        
        ctf->AddRGBPoint(ice1,       0,              0,  255.0/255.0);
        ctf->AddRGBPoint(ice3,     0,              255.0/255.0,   255.0/255.0);
        // ctf->AddRGBPoint(ice3,         191.0/255.0,   255.0/255.0,   255.0/255.0);
    }
    
    
    
    
    vtkSmartPointer<vtkLookupTable> colorLookupTable = vtkSmartPointer<vtkLookupTable>::New();
    if (!fireNice) {
        colorLookupTable->SetTableRange(minPL, maxPL);
        //colorLookupTable->SetScaleToLog10 ();
        colorLookupTable->SetHueRange(237.0/360,237.0/360);
        //colorLookupTable->SetHueRange(0,1);
        colorLookupTable->SetSaturationRange(0.3,.90);
        colorLookupTable->SetValueRange(1.0,0.4);
        colorLookupTable->SetAlphaRange(1.0,1.0);
        
        
        //                    //GreyScale
        //                    colorLookupTable->SetHueRange(0,0);
        //                    colorLookupTable->SetSaturationRange(0,0);
        //                    colorLookupTable->SetValueRange(1.0,.01);
        
        //                    //HeatMap3
        //                    colorLookupTable->SetHueRange(60.0/360,0.0/360); //yellow to red
        //                    colorLookupTable->SetSaturationRange(0.3,1.0); //0 is white
        //                    colorLookupTable->SetValueRange(1.0,.6); //0 is black
        
        if(PLdB_Plot)
        {   colorLookupTable->SetScaleToLog10();
        }
        else
        {   colorLookupTable->SetScaleToLinear();
        }
        colorLookupTable->Build();
    }
    
    
    
    
    
    for(triangulation_set=1; triangulation_set<number_of_sets; triangulation_set++)
    {
        std::cout << "There are " << AllPLdBPolydata[triangulation_set] ->GetNumberOfPoints()
        << " points." << std::endl;
    }
    
    
    //Assign a Color to each point
    // Assign color Values to Each Point
    // Generate the colors for each point based on the color map
    std::vector <vtkSmartPointer<vtkUnsignedCharArray> > colors(number_of_sets);
    
    
    double p[3];
    double dcolor[3];
    unsigned char color[3];
    
    double affirmpoint[3];
    double scalar;
    unsigned scalarindex;
    
    for(triangulation_set=2; triangulation_set<number_of_sets; triangulation_set++)
    {
        colors[triangulation_set]=vtkUnsignedCharArray::New();
        colors[triangulation_set]->SetNumberOfComponents(3);
        colors[triangulation_set]->SetName("Colors");
        
        for(int i = 0; i < AllPLdBPolydata[triangulation_set]->GetNumberOfPoints(); i++)
        {
            
            AllPLdBPolydata[triangulation_set]->GetPoint(i,p);
            
            
            AllPLdBPolydata[triangulation_set]->GetPoint(i,affirmpoint);
            
            scalarindex=i+start_points[triangulation_set]-headerlines;
            scalar=PLdBs[scalarindex];
            
            
            std::cout<< scalarindex<<" "<<affirmpoint[0]<<" "<<affirmpoint[1]<<" "<<affirmpoint[2]<<" "<<scalar<<std::endl;
            
            //            if( PLdBs[scalarindex]<0)
            //            {  //grey for area lower than scale
            //               // dcolor[0]=.8; dcolor[1]=.8; dcolor[2]=.8;
            //            
            //                //white for area lower than scale
            //                dcolor[0]=1.0; dcolor[1]=1.0; dcolor[2]=1.0;
            //            }
            //            else
            //            {colorLookupTable->GetColor(scalar, dcolor);}
            
            if(fireNice)
            {   ctf->GetColor (scalar, dcolor);}
            else
            {    colorLookupTable->GetColor(scalar, dcolor);}
            
            for(unsigned int j = 0; j < 3; j++)
            {
                color[j] = static_cast<unsigned char>( 255*dcolor[j]);
            }
            //            std::cout << "color: "
            //            << (int)color[0] << " "
            //            << (int)color[1] << " "
            //            << (int)color[2] << std::endl;
            
            colors[triangulation_set]->InsertNextTupleValue(color);
            
            //clear the arrays
            color[0]='\0';
        }
        
        AllPLdBPolydata[triangulation_set]->GetPointData()->SetScalars(colors[triangulation_set]);
        
    }
    
    
    
    
    vtkTriangleFilter * CutTriangles;
    for(triangulation_set=2; triangulation_set<number_of_sets; triangulation_set++)
    {
        AllPLdBpolydata[triangulation_set] = vtkPolyData::New();
        
        //Triangulate Polydata
        //Triangulate the grid points
        
        
        Alldelaunay[triangulation_set]= vtkDelaunay2D::New();
        
#if VTK_MAJOR_VERSION <= 5
        Alldelaunay[triangulation_set]->SetInput( AllPLdBPolydata[triangulation_set]);
#else
        Alldelaunay[triangulation_set]->SetInputData( AllPLdBPolydata[triangulation_set]);
#endif
        Alldelaunay[triangulation_set]->Update();
        
        AllPLdBpolydata[triangulation_set] = Alldelaunay[triangulation_set]->GetOutput();
        
        
        CutTriangles= vtkTriangleFilter::New();
        CutTriangles->SetInput( AllPLdBpolydata[triangulation_set] );
        CutTriangles->Update();
    }
    
    
    
    
    //Create A Mapper and Actor for each triangulation set of the PLdB
    std::vector< vtkSmartPointer<vtkPolyDataMapper> >     AllPLdBmapper(number_of_sets);
    std::vector< vtkSmartPointer<vtkActor> >  AllPLdBactor(number_of_sets);
    
    
    for(triangulation_set=2; triangulation_set<number_of_sets; triangulation_set++)
    {
        
        AllPLdBmapper[triangulation_set] =                  vtkSmartPointer<vtkPolyDataMapper>::New();
        AllPLdBmapper[triangulation_set]->                  SetInput(AllPLdBpolydata[triangulation_set]);
        
        AllPLdBactor[triangulation_set] =       vtkSmartPointer<vtkActor>::New();
        AllPLdBactor[triangulation_set]->       SetMapper( AllPLdBmapper[triangulation_set]);
        
    }    
    
    // Visualize
    vtkSmartPointer<vtkRenderer> renderer =
    vtkSmartPointer<vtkRenderer>::New();
    vtkSmartPointer<vtkRenderWindow> renderWindow =
    vtkSmartPointer<vtkRenderWindow>::New();
    renderWindow->AddRenderer(renderer);
    vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
    vtkSmartPointer<vtkRenderWindowInteractor>::New();
    renderWindowInteractor->SetRenderWindow(renderWindow);
    
    
    for(triangulation_set=2; triangulation_set<number_of_sets; triangulation_set++)   //As it should be for all the planes
        // for(triangulation_set=4; triangulation_set<5; triangulation_set++)                                                        //For Plotting Just a Single Plane
    {
        renderer->AddActor( AllPLdBactor[triangulation_set]);
    }
    
    //Scalar Bar
    vtkSmartPointer<vtkScalarBarActor> scalarBar = 
    vtkSmartPointer<vtkScalarBarActor>::New();
    
    if(fireNice)
    {scalarBar->SetLookupTable( ctf );}
    else
    {scalarBar->SetLookupTable( colorLookupTable ); }
    
    if(NumRefs_Plot)
    {   scalarBar->SetTitle("# Of Audible Sources");
        scalarBar->SetNumberOfLabels(maxPL+1);
    }
    if(Pmax_Plot)
    {   scalarBar->SetTitle("Pmax [psf]");
        scalarBar->SetNumberOfLabels(9);}
    if(PLdB_Plot)
    {   scalarBar->SetTitle("Δ PLdB");
        scalarBar->SetNumberOfLabels(9);}
    

    
    vtkSmartPointer<vtkTextProperty> scalarbartextprops =
    vtkSmartPointer<vtkTextProperty>::New() ;
    scalarbartextprops->SetColor (0, 0, 0);
    scalarBar->SetLabelTextProperty(scalarbartextprops);
    scalarBar->SetTitleTextProperty(scalarbartextprops);
    
    renderer->AddActor2D(scalarBar);
    
    
    
    ////////////////////////////
    
    bool plot_corner_numbers=false;
    bool plot_wall_numbers=false;
    int maxnumpts=0;
    int totnumcnx=0;
    
    
    // withgeometry=false;
    if(withgeometry)
    {
        
        //Plotting Geometry
        // Identifying all the points in the geometry
        
        if(walls.size()==0)
        {   std::cout<<"Error: walls sturcture is empty !"<<std::endl;
        }
        
        int NumVertices=walls[0].unique_corners.size();
        int NumWalls=walls.size();
        std::vector<corner> unique_corners=walls[0].unique_corners;
        
        //which wall has the maximum number of points per polygon
        
        for(int i=0; i<NumWalls; i++)
            
        {   
            totnumcnx=totnumcnx+walls[i].corners.size();
            
            if(walls[i].corners.size()>maxnumpts)
            {
                maxnumpts=walls[i].corners.size();
            }
        }
        
        //Store the positions of the vertices
        
        vtkSmartPointer<vtkPoints> GeometryVertices = vtkSmartPointer<vtkPoints>::New();
        
        GeometryVertices->Allocate(NumVertices);
        
        for(int i=0; i<NumVertices; i++)
        { 
            GeometryVertices->InsertPoint(i, unique_corners[i].x, unique_corners[i].y, unique_corners[i].z);
        }
        
        //Makeing an array of ID's for each polygon
        vtkIdList** pointIDs;
        pointIDs= new vtkIdList *[NumWalls];
        
        int cornersperwall;
        
        for(int wallind=0; wallind<NumWalls; wallind++)
        {   cornersperwall=walls[wallind].corners.size();
            // std::cout<<"Corners in this wall "<<cornersperwall<<std::endl;
            pointIDs[wallind]= vtkIdList::New();
            
            for(int cornerind=0; cornerind<walls[wallind].corners.size(); cornerind++)
            {  
                pointIDs[wallind]->InsertNextId(walls[wallind].corner_indices[cornerind]);
            }
        }
        
        
        std::vector<unsigned> polygons2triangularize; 
        
        //Make the Polygons
        vtkPolygon** polygons;
        polygons=new vtkPolygon *[NumWalls];      
        
        for(int wallind=0; wallind<NumWalls; wallind++)
        {   
            
            polygons[wallind]= vtkPolygon::New();
            polygons[wallind]->GetPointIds()->SetNumberOfIds( walls[wallind].corners.size() ); //make a quad
            
            
            for(int cornerind=0; cornerind<walls[wallind].corners.size(); cornerind++)
            {   
                polygons[wallind]->GetPointIds()->SetId(cornerind, walls[wallind].corner_indices[cornerind]);
                
            }
            
            if(walls[wallind].corners.size()>4)   //flag for triangularization
            {   polygons2triangularize.push_back(wallind);
            }
            
        }
        
        
        // Create a PolyData
        vtkSmartPointer<vtkCellArray> PolygonCellArray = vtkSmartPointer<vtkCellArray>::New();
        vtkSmartPointer<vtkPolyData> PolygonPolyData = vtkSmartPointer<vtkPolyData>::New();
        
        for(int wallind=0; wallind<NumWalls; wallind++)
        {   
            if(!walls[wallind].floorplane)
            {
                PolygonCellArray -> InsertNextCell(polygons[wallind]);
            }
        }
        
        PolygonPolyData->SetPoints(GeometryVertices);
        PolygonPolyData->SetPolys(PolygonCellArray);
        
        
        // Triangularize potentially concave large polygons   
        vtkTriangleFilter * CutTriangles;
        CutTriangles= vtkTriangleFilter::New();
        CutTriangles->SetInput(PolygonPolyData);
        CutTriangles->Update();
        
        
        
        //Lets put a number on each of the corners  
        
        vtkVectorText **atexts;
        atexts= new vtkVectorText *[NumVertices];
        
        vtkPolyDataMapper **textMappers;
        textMappers= new vtkPolyDataMapper *[NumVertices];
        
        vtkFollower **textActors;
        textActors= new vtkFollower *[NumVertices];
        
        std::string s;
        const char *p;
        
        if(plot_corner_numbers)
        {
            for(int vertind=0; vertind<NumVertices; vertind++)
            {
                atexts[vertind]= vtkVectorText::New();
                textMappers[vertind]= vtkPolyDataMapper::New();
                textActors[vertind]= vtkFollower::New();
                s = boost::lexical_cast<std::string>( vertind );
                p=&s[0];
                atexts[vertind]->SetText(p);
                textMappers[vertind]->SetInputConnection(atexts[vertind]->GetOutputPort());
                textActors[vertind]->SetMapper(textMappers[vertind]);
                textActors[vertind]->SetScale(2,2,2);
                textActors[vertind]->AddPosition(unique_corners[vertind].x,unique_corners[vertind].y,unique_corners[vertind].z);
                textActors[vertind]->GetProperty()->SetColor(.1,.1,1);
            }
            
            
        }
        
        
        
        //Lets number each of the walls
        // Rendering    
        vtkVectorText **wtexts;
        wtexts= new vtkVectorText *[NumWalls];
        
        vtkPolyDataMapper **wtextMappers;
        wtextMappers= new vtkPolyDataMapper *[NumWalls];
        
        vtkFollower **wtextActors;
        wtextActors= new vtkFollower *[NumWalls];
        
        std::string ws;
        const char *wp;
        
        if(plot_wall_numbers)
        {
            for(int wallind=0; wallind<NumWalls; wallind++)
            {
                wtexts[wallind]= vtkVectorText::New();
                wtextMappers[wallind]= vtkPolyDataMapper::New();
                wtextActors[wallind]= vtkFollower::New();
                ws = boost::lexical_cast<std::string>( wallind );
                wp=&ws[0];
                wtexts[wallind]->SetText(p);
                wtextMappers[wallind]->SetInputConnection(atexts[wallind]->GetOutputPort());
                wtextActors[wallind]->SetMapper(textMappers[wallind]);
                wtextActors[wallind]->SetScale(4,4,4);
                wtextActors[wallind]->AddPosition(walls[wallind].center.x+2*walls[wallind].normal.x,walls[wallind].center.y+2*walls[wallind].normal.y,walls[wallind].center.z+2*walls[wallind].normal.z);
                wtextActors[wallind]->GetProperty()->SetColor(1,.1,.1);
                
            }
        }
        
        
        
        // Create a mapper and actor
        vtkSmartPointer<vtkPolyDataMapper> mapper =
        vtkSmartPointer<vtkPolyDataMapper>::New();
        mapper->SetInput(CutTriangles->GetOutput());
        
        vtkSmartPointer<vtkActor> actor =
        vtkSmartPointer<vtkActor>::New();
        actor->SetMapper(mapper);
        
        
        
        if(plot_corner_numbers)
        { 
            for(int vertind=0; vertind<NumVertices; vertind++)
            {
                renderer->AddActor(textActors[vertind]);
            }
        }
        
        if(plot_wall_numbers)
        {
            for(int wallind=0; wallind<NumWalls; wallind++)
            {
                renderer->AddActor(wtextActors[wallind]);
            }
        }
        
        //  actor->GetProperty()->SetColor(255.0/255.0,204.0/255.0,204.0/255.0);  //r,g,b  pinkish
        actor->GetProperty()->SetColor(245.0/255.0,117.0/255.0,92.0/255.0);  //r,g,b  coral
        // actor->GetProperty()->SetColor(189.0/255.0,90.0/255.0,80.0/255.0);  //r,g,b  brick
        //actor->GetProperty()->SetColor(30/255.0,  30/255.0, 30/255.0);  //r,g,b  brick
        
        renderer->AddActor(actor);
        
    }
    
    
    int NumPoints=initial_microphone_positions;
    
    if(plot_microphones)
    {
        //Add a sphere at the point
        vtkSphereSource ** sphere;
        sphere= new vtkSphereSource *[NumPoints];
        
        vtkPolyDataMapper ** SphereMap;
        SphereMap= new vtkPolyDataMapper *[NumPoints];
        
        vtkActor ** SphereActor;
        SphereActor= new vtkActor *[NumPoints];
        
        for(int i=0; i<initial_microphone_positions; i++) //itterates through receivers
        {
            sphere[i]= vtkSphereSource::New();
            sphere[i]->SetRadius(1); //this used to be 1
            sphere[i]->SetThetaResolution(20);
            sphere[i]->SetPhiResolution(20);
            sphere[i]->SetCenter( Ppos_vector[i].x, Ppos_vector[i].y,   Ppos_vector[i].z );
            //sphere->SetCenter(36.45,26.17,1.2);
            SphereMap[i] = vtkPolyDataMapper::New();
            SphereMap[i]->SetInput(sphere[i]->GetOutput());
            //actor coordinates geometry, properties, transformation
            SphereActor[i] = vtkActor::New();
            SphereActor[i]->GetProperty()->SetColor(1,0,0);
            SphereActor[i]->SetMapper(SphereMap[i]);
            
            renderer->AddActor(SphereActor[i]);
        }
    }
    
    ////////////////////////////
    //    
    //    //Add a number where the point we are following is. 
    //    
    //
    //            vtkSmartPointer <vtkVectorText>   pointlabel= vtkVectorText::New();
    //            vtkSmartPointer< vtkPolyDataMapper>   pointlabelMappers= vtkPolyDataMapper::New();
    //            vtkSmartPointer<vtkFollower> pointlabelActors= vtkFollower::New();
    //    
    //            char * label ="3147";//weird triangle
    //           // char* label="7260";
    //        
    //            pointlabel->SetText(label);
    //            pointlabelMappers->SetInputConnection(pointlabel->GetOutputPort());
    //            pointlabelActors->SetMapper(pointlabelMappers);
    //            pointlabelActors->SetScale(4,4,4);
    //            pointlabelActors->AddPosition(36.47,-11.6,2); //weird triangle
    //           // pointlabelActors->AddPosition(36.45,26.17,2);
    //            
    //            pointlabelActors->GetProperty()->SetColor(1,.1,.1);
    //    
    //            renderer->AddActor(pointlabelActors);
    //
    //    /////////////////////////////
    //            
    //            //Add a sphere at the point
    //            vtkSphereSource *sphere;
    //            vtkPolyDataMapper *SphereMap;
    //            vtkActor *SphereActor;
    //
    //            sphere= vtkSphereSource::New();
    //            sphere->SetRadius(1);
    //            sphere->SetThetaResolution(20);
    //            sphere->SetPhiResolution(20);
    //            sphere->SetCenter( 36.47,-11.6,1.2 );   // weird triangle
    //    //sphere->SetCenter(36.45,26.17,1.2);
    //             SphereMap = vtkPolyDataMapper::New();
    //            SphereMap->SetInput(sphere->GetOutput());
    //            
    //    //actor coordinates geometry, properties, transformation
    //            SphereActor = vtkActor::New();
    //            SphereActor->SetMapper(SphereMap);
    //            renderer->AddActor(SphereActor);
    //    
    
    renderer->SetBackground(1,1,1); // Background color white
    renderWindow->SetSize(930,800); //(width, height)
    renderWindow->Render();
    
    if(save_contour)
    {
        // Screenshot  
        vtkSmartPointer<vtkWindowToImageFilter> w2i = vtkSmartPointer<vtkWindowToImageFilter>::New();
        w2i->SetInput(renderWindow);
        w2i->SetMagnification(3); //set the resolution of the output image (3 times the current resolution of vtk render window)
        w2i->SetInputBufferTypeToRGBA(); //also record the alpha (transparency) channel
        w2i->Update();
        
        vtkSmartPointer<vtkTIFFWriter> writer = 
        vtkSmartPointer<vtkTIFFWriter>::New();
        writer->SetInputConnection(w2i->GetOutputPort());
        
        char * figurename= new char[300];
        char * figure_output_directory="/Users/mandalin/Desktop/OutputImages/";
        char * figure_suffix=".tif";
        
        strcat(figurename,figure_output_directory);
        strcat(figurename,simulation_name_full);
        strcat(figurename,figure_suffix);
        
        writer->SetFileName(figurename);
        writer->Write();
    }
    renderWindow->Render();  
    renderer->ResetCamera();
    renderWindow->Render();
    renderWindowInteractor->Start();
    
    
    
    
    return;
}


#endif
