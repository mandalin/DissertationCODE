//
//  plot_FieldAngle.h
//  ISM
//
//  Created by Amanda Lind on 7/7/11.
//  Copyright 2011 Pennsylvania State University. All rights reserved.
//



void AddLightActors(vtkRenderer *r); 

void  plot_FieldAngle(std::vector<wall> walls)

{   bool plot_corner_numbers=false;
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
    vtkPoints *GeometryVertices = vtkPoints::New();
    
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
    

    //Make the Polygons
    vtkUnstructuredGrid * ugridGeom= vtkUnstructuredGrid::New();
    ugridGeom->Allocate(totnumcnx+10);
    
    for(int wallind=0; wallind<NumWalls; wallind++)
    {   //if(wallind==9) //excludes ground planes
        //{
            for(int cornerind=0; cornerind<walls[wallind].corners.size(); cornerind++)
            {   ugridGeom->InsertNextCell(VTK_POLYGON, pointIDs[wallind]);
            }
        //}
    }
    
     ugridGeom->SetPoints(GeometryVertices);
    // Mappers and Actors for planes
    vtkDataSetMapper *ugridMapper = vtkDataSetMapper::New();
    ugridMapper->SetInput(ugridGeom);
    
    vtkActor *ugridActor = vtkActor::New();
    ugridActor->SetMapper(ugridMapper);
    ugridActor->GetProperty()->SetColor(.2,.8,.8);
    ugridActor->AddPosition(0,0,0);

    

    vtkVectorText **atexts;
    atexts= new vtkVectorText *[NumVertices];
    
    vtkPolyDataMapper **textMappers;
    textMappers= new vtkPolyDataMapper *[NumVertices];
    
    vtkFollower **textActors;
    textActors= new vtkFollower *[NumVertices];
    
    
    vtkVectorText **wtexts;
    wtexts= new vtkVectorText *[NumWalls];
    
    vtkPolyDataMapper **wtextMappers;
    wtextMappers= new vtkPolyDataMapper *[NumWalls];
    
    vtkFollower **wtextActors;
    wtextActors= new vtkFollower *[NumWalls];
    
   
        //Lets put a number on each of the corners  
    
    
        std::string ws;
        const char *wp = new char[10];
        if(plot_wall_numbers)
        {        
            for(int wallind=0; wallind<NumWalls; wallind++)
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
    

        std::string s;
        const char *p= new char[10];
        if(plot_corner_numbers)
        {         //NumVertices
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
            }
        }


        //Lets number each of the walls
       // Rendering    
            
    //create axes
    vtkSmartPointer<vtkAxesActor> axesActor = vtkSmartPointer<vtkAxesActor>::New();
    axesActor->AxisLabelsOn();
    int r=300;
    axesActor->SetTotalLength(r*1.1,r*1.1,r*1.1);//lengths of the legs of the axis
    axesActor->SetConeRadius(.2);
    
    vtkTextProperty* axisLabelTextProperty = vtkTextProperty::New(); 
    
    //axisLabelTextProperty->SetFontFamilyToArial(); 
    axisLabelTextProperty->SetColor( 0, 0, 0 );  //rgb color
    axisLabelTextProperty->SetFontSize( 18 );    //dont know why this line appears useless
    //is an Actor2D, and it honors its 
    //Position and Position2 coordinates, i.e. it will fit itself in the box 
    //described by those 2 points, like all Actor2D, and set the size of its text 
    //so that it fits inside this box.
    
    //axisLabelTextProperty->ShadowOn(); 
    axesActor->GetXAxisCaptionActor2D ()->GetTextActor()->SetTextScaleModeToNone();//keeps the font size specified from getting overwritten
    axesActor->GetYAxisCaptionActor2D ()->GetTextActor()->SetTextScaleModeToNone();//keeps the font size specified from getting overwritten
    axesActor->GetZAxisCaptionActor2D ()->GetTextActor()->SetTextScaleModeToNone();//keeps the font size specified from getting overwritten
    
    axesActor->GetYAxisCaptionActor2D()->SetCaptionTextProperty(axisLabelTextProperty); 
    axesActor->GetXAxisCaptionActor2D()->SetCaptionTextProperty(axisLabelTextProperty); 
    axesActor->GetZAxisCaptionActor2D()->SetCaptionTextProperty(axisLabelTextProperty ); 
    axisLabelTextProperty->Delete();     
    
    // The usual rendering stuff.
    vtkCamera *camera = vtkCamera::New();
    camera->SetPosition(.1,-.2,.3);
    camera->SetFocalPoint(0,0,0);
    

    //Graphics Pipeline
    vtkRenderer *renderer = vtkRenderer::New();
    vtkRenderWindow *renWin = vtkRenderWindow::New();
    renWin->AddRenderer(renderer);
    vtkRenderWindowInteractor *iren = vtkRenderWindowInteractor::New();
    iren->SetRenderWindow(renWin);
    
    renderer->AddActor(ugridActor);
    renderer ->AddActor (axesActor ) ;
   

    
  if(plot_corner_numbers)
  {     for(int vertind=0; vertind<NumVertices; vertind++)
      //for(int vertind=42; vertind<54; vertind++)
        {
            renderer->AddActor(textActors[vertind]);
        }
  }
    if(plot_wall_numbers) 
    {      for(int wallind=0; wallind<NumWalls; wallind++)
        //for(int wallind=10; wallind<20; wallind++)
        {
        //    renderer->AddActor(wtextActors[wallind]);
        }
}  

 
    
    renderer->SetBackground(1,1,1);
    
    renWin->SetSize(450,450);
    
    // interact with data
    renWin->Render();
    iren->Start();
    
    // Clean up
    renderer->Delete();
    renWin->Delete();
    iren->Delete();
    GeometryVertices->Delete();
    ugridGeom->Delete();
    ugridMapper->Delete();
    ugridActor->Delete();


    
    return; 
}