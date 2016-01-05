//////
//////  TerrainMesh_NumRefs.h
//////  ISM
//////
//////  Created by Amanda Lind on 2/22/12.
//////  Copyright 2012 Pennsylvania State University. All rights reserved.
//////
////
////#ifndef ISM_TerrainMesh_NumRefs_h
////#define ISM_TerrainMesh_NumRefs_h
////
//#include <stdio.h>
//#include <strings.h>
//#include <dirent.h> 
//
//void  TerrainMesh_NumRefs(std::vector<wall> walls, std::vector<unsigned> points_per_wall, double resolution, const char * IRDirectory)
//
//{   
//    //Read in IRs
//    
//    //What are the IRs In the Directory 
//    DIR * dir;
//    struct dirent *ent;
//    dir = opendir (IRDirectory);
//    
//    
//    std::vector <string> IRFilenames;
//    if (dir != NULL) {
//        
//        /* print all the files and directories within directory */
//        while ((ent = readdir (dir)) != NULL) {
//            printf ("%s\n", ent->d_name);
//            IRFilenames.push_back(ent->d_name);
//        }
//        closedir (dir);
//    } else {
//        /* could not open directory */
//        perror ("could not open directory");
//        return ;
//    }
//    ///////////////////////////////////////////////////////////////////
//
//    //Parse Filename to obtain xpos, ypos, zpos and sample number
//    
//
//    //Open One File and Calculate the number of reflections there
//    std::string line;
//    std::ifstream myfile (IR_text_file_name);
//    std::vector<double> PLdBs;
//
//
//    
//    
//    
//            unsigned linenum=0;
//            vtkSmartPointer<vtkPoints> PLdBpoints = vtkSmartPointer<vtkPoints>::New();
//            typedef std::vector <std::string> split_vector_type;
//            double sum=0;
//            double sample;
//            
//            if (myfile.is_open())
//            {
//                while ( myfile.good() )
//                {   linenum++;
//                    std::getline (myfile,line);
//                    std::cout << line << std::endl;
//                        
//                        split_vector_type SplitVec; // #2: Search for tokens
//                        boost::split( SplitVec, line, boost::is_any_of(" \n") ); // SplitVec == { "hello abc","ABC","aBc goodbye" }
//                        
//                        
//                        std::cout << SplitVec[0] << std::endl;
//                        sample =   boost::lexical_cast<double>(SplitVec[0]);
//                        sum=sum+sample
//                }
//                    
//                }
//                myfile.close();
//            }
//    
//    vtkSmartPointer<vtkPolyData> PLdBpolydata = vtkSmartPointer<vtkPolyData>::New();
//    PLdBpolydata->SetPoints(PLdBpoints);
//    
//    //Triangulate Polydata
//    //Triangulate the grid points
//    vtkSmartPointer<vtkDelaunay2D> delaunay = 
//    vtkSmartPointer<vtkDelaunay2D>::New();
//#if VTK_MAJOR_VERSION <= 5
//    delaunay->SetInput(PLdBpolydata);
//#else
//    delaunay->SetInputData(PLdBpolydata);
//#endif
//    delaunay->Update();
//    vtkPolyData* PLdBPolyData = delaunay->GetOutput();
//    
//    
//    //Organize thePLdB Scalars
//    //Get PLdB Bounds
//    double maxPL,minPL;
//    maxPL=PLdBs[0];
//    minPL=PLdBs[0];
//    for(int ind=1; ind< PLdBs.size(); ind++)
//    {   if(PLdBs[ind]>maxPL)
//    {maxPL=PLdBs[ind];}
//        if(PLdBs[ind]<minPL)
//        {minPL=PLdBs[ind];}
//    }
//    std::cout << "min PLdB " << minPL << std::endl;
//    std::cout << "max PLdB " << maxPL << std::endl;
//    
//    // Create the color map
//    vtkSmartPointer<vtkLookupTable> colorLookupTable = vtkSmartPointer<vtkLookupTable>::New();
//    colorLookupTable->SetTableRange(minPL, maxPL);
//    //colorLookupTable->SetScaleToLog10 ();
//    colorLookupTable->Build();    
//    
//    // Assign color Values to Each Point
//    // Generate the colors for each point based on the color map
//    vtkSmartPointer<vtkUnsignedCharArray> colors = 
//    vtkSmartPointer<vtkUnsignedCharArray>::New();
//    colors->SetNumberOfComponents(3);
//    colors->SetName("Colors");
//    
//    std::cout << "There are " << PLdBPolyData->GetNumberOfPoints()
//    << " points." << std::endl;
//    
//    for(int i = 0; i < PLdBPolyData->GetNumberOfPoints(); i++)
//    {
//        double p[3];
//        PLdBPolyData->GetPoint(i,p);
//        
//        double dcolor[3];
//        colorLookupTable->GetColor(PLdBs[i], dcolor);
//        std::cout << "dcolor: "
//        << dcolor[0] << " "
//        << dcolor[1] << " "
//        << dcolor[2] << std::endl;
//        unsigned char color[3];
//        for(unsigned int j = 0; j < 3; j++)
//        {
//            color[j] = static_cast<unsigned char>(255.0 * dcolor[j]);
//        }
//        std::cout << "color: "
//        << (int)color[0] << " "
//        << (int)color[1] << " "
//        << (int)color[2] << std::endl;
//        
//        colors->InsertNextTupleValue(color);
//    }
//    
//    PLdBPolyData->GetPointData()->SetScalars(colors);
//    
//    ////////////////////////////////////////////////////////////////////////////
//    
//    
//    
//    bool plot_corner_numbers=false;
//    bool plot_wall_numbers=false;
//    //Plotting Geometry
//    // Identifying all the points in the geometry
//    
//    if(walls.size()==0)
//    {   std::cout<<"Error: walls sturcture is empty !"<<std::endl;
//    }
//    
//    int NumVertices=walls[0].unique_corners.size();
//    int NumWalls=walls.size();
//    std::vector<corner> unique_corners=walls[0].unique_corners;
//    
//    //which wall has the maximum number of points per polygon
//    int maxnumpts=0;
//    int totnumcnx=0;
//    for(int i=0; i<NumWalls; i++)
//    {   
//        totnumcnx=totnumcnx+walls[i].corners.size();
//        
//        if(walls[i].corners.size()>maxnumpts)
//        {
//            maxnumpts=walls[i].corners.size();
//        }
//    }
//    
//    //Store the positions of the vertices
//    
//    vtkSmartPointer<vtkPoints> GeometryVertices = vtkSmartPointer<vtkPoints>::New();
//    
//    GeometryVertices->Allocate(NumVertices);
//    
//    for(int i=0; i<NumVertices; i++)
//    { 
//        GeometryVertices->InsertPoint(i, unique_corners[i].x, unique_corners[i].y, unique_corners[i].z);
//    }
//    
//    //Makeing an array of ID's for each polygon
//    vtkIdList** pointIDs;
//    pointIDs= new vtkIdList *[NumWalls];
//    
//    int cornersperwall;
//    
//    for(int wallind=0; wallind<NumWalls; wallind++)
//    {   cornersperwall=walls[wallind].corners.size();
//        // std::cout<<"Corners in this wall "<<cornersperwall<<std::endl;
//        pointIDs[wallind]= vtkIdList::New();
//        
//        for(int cornerind=0; cornerind<walls[wallind].corners.size(); cornerind++)
//        {  
//            pointIDs[wallind]->InsertNextId(walls[wallind].corner_indices[cornerind]);
//        }
//    }
//    
//    
//    std::vector<unsigned> polygons2triangularize; 
//    
//    //Make the Polygons
//    vtkPolygon** polygons;
//    polygons=new vtkPolygon *[NumWalls];      
//    
//    for(int wallind=0; wallind<NumWalls; wallind++)
//    {   
//        
//        polygons[wallind]= vtkPolygon::New();
//        polygons[wallind]->GetPointIds()->SetNumberOfIds( walls[wallind].corners.size() ); //make a quad
//        
//        
//        for(int cornerind=0; cornerind<walls[wallind].corners.size(); cornerind++)
//        {   
//            polygons[wallind]->GetPointIds()->SetId(cornerind, walls[wallind].corner_indices[cornerind]);
//            
//        }
//        
//        if(walls[wallind].corners.size()>4)   //flag for triangularization
//        {   polygons2triangularize.push_back(wallind);
//        }
//        
//    }
//    
//    
//    // Create a PolyData
//    vtkSmartPointer<vtkCellArray> PolygonCellArray = vtkSmartPointer<vtkCellArray>::New();
//    vtkSmartPointer<vtkPolyData> PolygonPolyData = vtkSmartPointer<vtkPolyData>::New();
//    
//    for(int wallind=0; wallind<NumWalls; wallind++)
//    {   
//        if(!walls[wallind].floorplane)
//        {PolygonCellArray -> InsertNextCell(polygons[wallind]);}
//    }
//    
//    PolygonPolyData->SetPoints(GeometryVertices);
//    PolygonPolyData->SetPolys(PolygonCellArray);
//    
//    
//    // Triangularize potentially concave large polygons   
//    vtkTriangleFilter * CutTriangles;
//    CutTriangles= vtkTriangleFilter::New();
//    CutTriangles->SetInput(PolygonPolyData);
//    CutTriangles->Update();
//    
//    
//    // Create Unstructured Grid for PLdB Visualization 
//    
//    
//    
//    //    //Lets put a number on each of the corners  
//    //    
//    //    vtkVectorText **atexts;
//    //    atexts= new vtkVectorText *[NumVertices];
//    //    
//    //    vtkPolyDataMapper **textMappers;
//    //    textMappers= new vtkPolyDataMapper *[NumVertices];
//    //    
//    //    vtkFollower **textActors;
//    //    textActors= new vtkFollower *[NumVertices];
//    //    
//    //    std::string s;
//    //    const char *p;
//    //    
//    //    if(plot_corner_numbers)
//    //    {
//    //        for(int vertind=0; vertind<NumVertices; vertind++)
//    //        {
//    //            atexts[vertind]= vtkVectorText::New();
//    //            textMappers[vertind]= vtkPolyDataMapper::New();
//    //            textActors[vertind]= vtkFollower::New();
//    //            s = boost::lexical_cast<std::string>( vertind );
//    //            p=&s[0];
//    //            atexts[vertind]->SetText(p);
//    //            textMappers[vertind]->SetInputConnection(atexts[vertind]->GetOutputPort());
//    //            textActors[vertind]->SetMapper(textMappers[vertind]);
//    //            textActors[vertind]->SetScale(2,2,2);
//    //            textActors[vertind]->AddPosition(unique_corners[vertind].x,unique_corners[vertind].y,unique_corners[vertind].z);
//    //            textActors[vertind]->GetProperty()->SetColor(.1,.1,1);
//    //        }
//    //        
//    //        
//    //    }
//    //    
//    
//    //    
//    //    //Lets number each of the walls
//    //    // Rendering    
//    //    vtkVectorText **wtexts;
//    //    wtexts= new vtkVectorText *[NumWalls];
//    //    
//    //    vtkPolyDataMapper **wtextMappers;
//    //    wtextMappers= new vtkPolyDataMapper *[NumWalls];
//    //    
//    //    vtkFollower **wtextActors;
//    //    wtextActors= new vtkFollower *[NumWalls];
//    //    
//    //    std::string ws;
//    //    const char *wp;
//    //    
//    //    if(plot_wall_numbers)
//    //    {
//    //        for(int wallind=0; wallind<NumWalls; wallind++)
//    //        {
//    //            wtexts[wallind]= vtkVectorText::New();
//    //            wtextMappers[wallind]= vtkPolyDataMapper::New();
//    //            wtextActors[wallind]= vtkFollower::New();
//    //            ws = boost::lexical_cast<std::string>( wallind );
//    //            wp=&ws[0];
//    //            wtexts[wallind]->SetText(p);
//    //            wtextMappers[wallind]->SetInputConnection(atexts[wallind]->GetOutputPort());
//    //            wtextActors[wallind]->SetMapper(textMappers[wallind]);
//    //            wtextActors[wallind]->SetScale(4,4,4);
//    //            wtextActors[wallind]->AddPosition(walls[wallind].center.x+2*walls[wallind].normal.x,walls[wallind].center.y+2*walls[wallind].normal.y,walls[wallind].center.z+2*walls[wallind].normal.z);
//    //            wtextActors[wallind]->GetProperty()->SetColor(1,.1,.1);
//    //            
//    //        }
//    //    }
//    
//    
//    
//    // Create a mapper and actor For Geometry
//    vtkSmartPointer<vtkPolyDataMapper> mapper =
//    vtkSmartPointer<vtkPolyDataMapper>::New();
//    mapper->SetInput(CutTriangles->GetOutput());
//    
//    vtkSmartPointer<vtkActor> actor =
//    vtkSmartPointer<vtkActor>::New();
//    actor->SetMapper(mapper);
//    
//    
//    //Create A Mapper and Actor for PLdB
//    vtkSmartPointer<vtkPolyDataMapper> PLdBmapper =
//    vtkSmartPointer<vtkPolyDataMapper>::New();
//    PLdBmapper->SetInput(PLdBPolyData);
//    
//    vtkSmartPointer<vtkActor> PLdBactor =
//    vtkSmartPointer<vtkActor>::New();
//    PLdBactor->SetMapper(PLdBmapper);
//    
//    
//    
//    // Visualize
//    vtkSmartPointer<vtkRenderer> renderer =
//    vtkSmartPointer<vtkRenderer>::New();
//    vtkSmartPointer<vtkRenderWindow> renderWindow =
//    vtkSmartPointer<vtkRenderWindow>::New();
//    renderWindow->AddRenderer(renderer);
//    vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
//    vtkSmartPointer<vtkRenderWindowInteractor>::New();
//    renderWindowInteractor->SetRenderWindow(renderWindow);
//    
//    
//    //    if(plot_corner_numbers)
//    //    { 
//    //        for(int vertind=0; vertind<NumVertices; vertind++)
//    //        {
//    //            renderer->AddActor(textActors[vertind]);
//    //        }
//    //    }
//    //    
//    //    if(plot_wall_numbers)
//    //    {
//    //        for(int wallind=0; wallind<NumWalls; wallind++)
//    //        {
//    //            renderer->AddActor(wtextActors[wallind]);
//    //        }
//    //    }
//    
//    //renderer->AddActor(actor);
//    renderer->AddActor(PLdBactor);
//    
//    renderWindow->Render();
//    renderWindowInteractor->Start();
//    
//    
//    return;
//}
//
//
//
//#endif
