//
//  plot_ISM1stOrd.h
//  ISM
//
//  Created by Amanda Lind on 4/5/11.
//  Copyright 2011 Pennsylvania State University. All rights reserved.
//

void AddLightActors(vtkRenderer *r);




void  plot_ISM1stOrd(std::vector<source> sources)

{   //PUT IN THE Building/Terrain INFORMATION
    
    double l,w,h,t;
    l=250*.3048; w=125*.3048; h=30*.3048; t=40*.3048;
    double r=300;
    
    // double wall_height=1;
    // wall_length=1;
    // double wall_width=1;
    // radius=5;
    
    const int num_points=16;
    const int num_faces=9;
    
    float x[num_points][3]=
    {   {0,0,0},//0
        {0,0,h},//1
        {w,0,h},//2
        {w,0,0},//3
        {0,l,0},//4
        {0,l,h},//5
        {t,l,h},//6
        {t,l,0},//7
        {t,t,0},//8
        {t,t,h},//9
        {w,t,h},
        {w,t,0},
        {-r/2,-r/2,0},
        {-r/2,r/2,0},
        {r/2,r/2,0},
        {r/2,-r/2,0},//16
    }; 
    
    static vtkIdType pts[num_faces][4]=
    {{3,2,1,0}/*south*/,{0,1,5,4}/*west*/,{4,5,6,7}/*north1*/,{7,6,9,8}/*east1*/,{8,9,10,11}/*north2*/,{11,10,2,3}/*east2*/,{10,9,1,2}/*roof1*/,{1,9,6,5}/*roof2*/, {12,13,14,15/*ground*/}};
    //still need to !fix! this to handle faces with arbitrary number of points
    
    
    // We'll create the building blocks of polydata including data attributes.
    vtkPolyData *face = vtkPolyData::New();
    vtkPoints *points = vtkPoints::New();
    vtkCellArray *polys = vtkCellArray::New();
    vtkFloatArray *scalars = vtkFloatArray::New();
    
    // Load the point, cell, and data attributes.
    for (int i=0; i<num_points; i++) points->InsertPoint(i,x[i]);    
    for (int i=0; i<num_faces; i++) polys->InsertNextCell(4,pts[i]);
    for (int i=0; i<num_points; i++) scalars->InsertTuple1(i,2); //this line clors the plan
    
    // We now assign the pieces to the vtkPolyData.
    face->SetPoints(points);
    points->Delete();
    face->SetPolys(polys);
    polys->Delete();
    face->GetPointData()->SetScalars(scalars);
    scalars->Delete();
    
    // Set Mappers/Actors for the Geometry
    vtkPolyDataMapper *faceMapper = vtkPolyDataMapper::New();
    faceMapper->SetInput(face);
    faceMapper->SetScalarRange(0,4);
    vtkActor *faceActor = vtkActor::New();
    faceActor->SetMapper(faceMapper);
    
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
                                            
                                        {SphereActor[i]->GetProperty()->SetColor(179/255, 141/255, 236/255);} //sphere color purple
                                        else
                                        {SphereActor[i]->GetProperty()->SetColor(0,0,1);} //sphere color blue
                                    }
    
    
    
    
    
    //create axes
    vtkSmartPointer<vtkAxesActor> axesActor = vtkSmartPointer<vtkAxesActor>::New();
    axesActor->AxisLabelsOn();
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
    
    vtkRenderer *renderer = vtkRenderer::New();
    vtkRenderWindow *renWin = vtkRenderWindow::New();
    renWin->AddRenderer(renderer);
    vtkRenderWindowInteractor *iren = vtkRenderWindowInteractor::New();
    iren->SetRenderWindow(renWin);
    
    

    
    faceActor->GetProperty()->SetAmbient(0.0);
    faceActor->GetProperty()->SetDiffuse(0.0);
    faceActor->GetProperty()->SetSpecular(0.5);
    renderer->AddActor(faceActor);
    
                                                    for(int i=0; i< num_generated_sources; i++)
                                                    {   if (sources[i].legal)
                                                    {   SphereActor[i]->GetProperty()->SetAmbient(0.0);
                                                        SphereActor[i]->GetProperty()->SetDiffuse(0.0);
                                                        SphereActor[i]->GetProperty()->SetSpecular(0.5);
                                                        renderer->AddActor(SphereActor[i]);
                                                            
                                                        }
                                                        else
                                                        {}
                                                    }
    
    renderer ->AddActor (axesActor ) ;
    renderer->SetActiveCamera(camera);
    renderer->ResetCamera();
    
    
    renderer->SetBackground(0.66,0.66,0.66);
    renderer->SetBackground2(157.0/255.0*0.66,186/255.0*0.66,192.0/255.0*0.66);
    renderer->SetGradientBackground(true);
    
    renWin->SetSize(300,300);
    
    
    
    //After adding the render window and actors
    //Define how you want the lighting to look Let's use vtkLightKit
    vtkLight * light = vtkLight::New();
    light->SetFocalPoint(0,0,0);
    light->SetPosition(0,300,300);
      
    
    // interact with data
    renWin->Render();
    iren->Start();
    
    // Clean up
    
   // face->Delete();
   // for(int i=0; num_generated_sources ; i++)
   // {
   //     SphereActor[i]->Delete();
   //}
    
   // faceMapper->Delete();
   // faceActor->Delete();
   // camera->Delete();
   // renderer->Delete();
   // renWin->Delete();
   // iren->Delete();

    return; 
}

