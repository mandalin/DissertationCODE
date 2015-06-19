//
//  plot_GeometryGeneral.h
//  ISM
//
//  Created by Amanda Lind on 7/7/11.
//  Copyright 2011 Pennsylvania State University. All rights reserved.
//



void AddLightActors(vtkRenderer *r); 

void  plot_GeometryGeneral(std::vector<wall> walls, std::vector<source> sources)// ,unsigned srcindex

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
                std::cout<<"Corners in this wall "<<cornersperwall<<std::endl;
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

    
        //Lets put a number on each of the corners  
        
            vtkVectorText **atexts;
            atexts= new vtkVectorText *[NumVertices];
            
            vtkPolyDataMapper **textMappers;
            textMappers= new vtkPolyDataMapper *[NumVertices];
            
            vtkFollower **textActors;
            textActors= new vtkFollower *[NumVertices];
            
            std::string s;
            const char *p;
            
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
        
    //create axes
        vtkSmartPointer<vtkAxesActor> axesActor = vtkSmartPointer<vtkAxesActor>::New();
        axesActor->AxisLabelsOn();
        int r=300;
        axesActor->SetTotalLength(r*1.1,r*1.1,r*1.1);//lengths of the legs of the axis
        axesActor->SetConeRadius(.2);
        
        vtkTextProperty* axisLabelTextProperty = vtkTextProperty::New(); 
       
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
        
    // Create a Camera
        vtkCamera *camera = vtkCamera::New();
        camera->SetPosition(.1,-.2,.3);
        camera->SetFocalPoint(0,0,0);
    
    //Set Mappers and Actors for the Sources
        int num_generated_sources=sources.size();
        
        std::cout<<"number of generated sources "<<num_generated_sources<<std::endl;
        vtkSphereSource *sphere[num_generated_sources];
        vtkPolyDataMapper *SphereMap[num_generated_sources];
        vtkActor *SphereActor[num_generated_sources];
        for(int i=0; i< num_generated_sources; i++)
        {
            
            sphere[i] = vtkSphereSource::New();
            sphere[i]->SetRadius(10);
            sphere[i]->SetThetaResolution(20);
            sphere[i]->SetPhiResolution(20);
            sphere[i]->SetCenter(sources[i].position.x , sources[i].position.y, sources[i].position.z);    
            std::cout<<"Source # "<<i<<": located at "<<sources[i].position.x <<" "<<sources[i].position.y<<" "<<sources[i].position.z<<std::endl;
            //map to graphics library
            SphereMap[i] = vtkPolyDataMapper::New();
            SphereMap[i]->SetInput(sphere[i]->GetOutput());
            
            //actor coordinates geometry, properties, transformation
            SphereActor[i] = vtkActor::New();
            SphereActor[i]->SetMapper(SphereMap[i]);
            
            if(i==0)
                
            {SphereActor[i]->GetProperty()->SetColor(1, 0, 0);} //sphere color purple
            else
            {SphereActor[i]->GetProperty()->SetColor(0,0,1);} //sphere color blue
        }

    //Lets Plot the field angle for source 1
//    
//    int sourcenumber=1;
//    bool is_in_angle=false;
//    int mother_w_i /*mother_wall_index*/;
//    int new_mother_w_i/*new_mother_wall_index*/;
//    std::vector<corner> new_corners;
//    std::vector<int> numpointsperpoly;
//    
//    is_in_angle in_field_angle_corners(sources /*sources*/, 
//                                walls /*planes*/, 
//                                sourcenumber /*mother_source_index*/, 
//                                 mother_w_i /*mother_wall_index*/,
//                                new_mother_w_i/*new_mother_wall_index*/, 
//                                 new_corners, 
//                                numpointsperpoly)
//    
        

    //Graphics Pipeline Setup
    vtkRenderer *renderer = vtkRenderer::New();
    vtkRenderWindow *renWin = vtkRenderWindow::New();
    renWin->AddRenderer(renderer);
    vtkRenderWindowInteractor *iren = vtkRenderWindowInteractor::New();
    iren->SetRenderWindow(renWin);
    
    //Add Actors
    
        renderer->AddActor(ugridActor);     //planes
        renderer ->AddActor (axesActor ) ;  //axis
        
        for(int vertind=0; vertind<NumVertices; vertind++)
        {
            renderer->AddActor(textActors[vertind]);    //vertex lables
        }
        
        for(int wallind=0; wallind<NumWalls; wallind++)
        {
            renderer->AddActor(wtextActors[wallind]);   //wall lables
        }
    
        for(int i=0; i< num_generated_sources; i++)     //legal sources
        {   if (sources[i].legal)
            {   SphereActor[i]->GetProperty()->SetAmbient(0.0);
                SphereActor[i]->GetProperty()->SetDiffuse(0.0);
                SphereActor[i]->GetProperty()->SetSpecular(0.5);
                renderer->AddActor(SphereActor[i]);
            }
            else
            {}
        }
    
    
    
    //Render window settings
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