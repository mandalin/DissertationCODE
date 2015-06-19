//
//  TerrainMesh.h
//  ISM
//
//  Created by Amanda Lind on 11/10/11.
//  Copyright 2011 Pennsylvania State University. All rights reserved.
//

#ifndef ISM_TerrainMesh_h
#define ISM_TerrainMesh_h


void  TerrainMesh(std::vector<wall> walls, std::vector<position_vector> Ppos_vector, bool plot_receivers)

// void TerrainMesh() takes as an input the walls structure, creates a vtkUnstructuredGrid (the same as exists when we plot in plot_SGR_Orientation() and converts it into vtkPolyData);

{
    bool plot_floor_plane=false;
    bool plot_corner_numbers=false;
    bool plot_wall_numbers=false;
    //Plotting Geometry
    // Identifying all the points in the geometry
    
    if(walls.size()==0)
    {   std::cout<<"Error: walls sturcture is empty !"<<std::endl;
    }
    
    int NumVertices=walls[0].unique_corners.size();
    int NumWalls=walls.size();
    std::vector<corner> unique_corners=walls[0].unique_corners;
    
    //which wall has the maximum number of points per polygon
    int maxnumpts=0;
    int totnumcnx=0;
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
        if(!walls[wallind].floorplane || plot_floor_plane)
        {PolygonCellArray -> InsertNextCell(polygons[wallind]);}
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
    
    int maxvert=NumVertices;
    int minvert=0;
    
    minvert=146;
    maxvert=149;
    
    if(plot_corner_numbers)
    {
        for(int vertind=minvert; vertind<maxvert; vertind++)
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
    
    int maxwall=NumWalls;
    int minwall=0;
    
    // minwall=28;
    // maxwall=30;
    
    if(plot_wall_numbers)
    {
        
        for(int wallind=minwall; wallind<maxwall; wallind++)
            //     for(int wallind=minwall; wallind<maxwall; wallind++)
        {
            wtexts[wallind]= vtkVectorText::New();
            wtextMappers[wallind]= vtkPolyDataMapper::New();
            wtextActors[wallind]= vtkFollower::New();
            ws = boost::lexical_cast<std::string>( wallind );
            wp=&ws[0];
            wtexts[wallind]->SetText(wp);
            wtextMappers[wallind]->SetInputConnection(wtexts[wallind]->GetOutputPort());
            wtextActors[wallind]->SetMapper(wtextMappers[wallind]);
            wtextActors[wallind]->SetScale(4,4,4);
            wtextActors[wallind]->AddPosition(walls[wallind].center.x+2*walls[wallind].normal.x,walls[wallind].center.y+2*walls[wallind].normal.y,walls[wallind].center.z+2*walls[wallind].normal.z);
            wtextActors[wallind]->GetProperty()->SetColor(1,.1,.1);
            
        }
    }
    
    // NOW let's Subsample
    
    // Add some points to interpolate
    //    vtkSmartPointer<vtkPoints> probePoints =
    //    vtkSmartPointer<vtkPoints>::New();
    //    probePoints->InsertNextPoint(100, 100, 0);
    //    probePoints->InsertNextPoint(1, 1, 0);
    //
    //    vtkSmartPointer<vtkPolyData> probePolyData =
    //    vtkSmartPointer<vtkPolyData>::New();
    //    probePolyData->SetPoints(probePoints);
    //
    //    vtkSmartPointer<vtkProbeFilter> probe =
    //    vtkSmartPointer<vtkProbeFilter>::New();
    //    probe->SetSource(PolygonPolyData);
    //    probe->SetInput(probePolyData);
    //    probe->Update();
    //
    //
    //
    
    
    // Create a mapper and actor
    vtkSmartPointer<vtkPolyDataMapper> mapper =
    vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInput(CutTriangles->GetOutput());
    
    vtkSmartPointer<vtkActor> actor =
    vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);
    
    
    // Visualize
    vtkSmartPointer<vtkRenderer> renderer =
    vtkSmartPointer<vtkRenderer>::New();
    vtkSmartPointer<vtkRenderWindow> renderWindow =
    vtkSmartPointer<vtkRenderWindow>::New();
    renderWindow->AddRenderer(renderer);
    vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
    vtkSmartPointer<vtkRenderWindowInteractor>::New();
    renderWindowInteractor->SetRenderWindow(renderWindow);
    
    
    if(plot_corner_numbers)
    {
        for(int vertind=minvert; vertind<maxvert; vertind++)
        {
            renderer->AddActor(textActors[vertind]);
        }
    }
    
    if(plot_wall_numbers)
    {
        for(int wallind=minwall; wallind<maxwall; wallind++)
        {
            renderer->AddActor(wtextActors[wallind]);
        }
    }
    
    
    
    
    
    
    int NumPoints=Ppos_vector.size();
    
    if(plot_receivers)
    {
        //Add a sphere at the point
        vtkSphereSource ** sphere;
        sphere= new vtkSphereSource *[NumPoints];
        
        vtkPolyDataMapper ** SphereMap;
        SphereMap= new vtkPolyDataMapper *[NumPoints];
        
        vtkActor ** SphereActor;
        SphereActor= new vtkActor *[NumPoints];
        
        for(int i=0; i<Ppos_vector.size(); i++) //itterates through receivers
        {
            sphere[i]= vtkSphereSource::New();
            sphere[i]->SetRadius(1);
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
    
    renderer->AddActor(actor);
    
    renderWindow->Render();
    renderWindowInteractor->Start();
    
    //  for(int i=0; i<NumWalls; i++)
    //{
    //delete[] wtexts[i];
    //delete[] wtextMappers[i];
    //delete[] wtextActors[i];
    delete[] pointIDs;
    //delete[] polygons[i];
    // }
    
    //    for(int i=0; i<NumPoints; i++)
    //    {
    //        delete[] sphere[i];
    //        delete[] SphereMap[i];
    //        delete[] SphereActor[i];
    //    }
    //
    return;
}
#endif