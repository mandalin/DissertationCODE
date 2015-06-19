//
//  plot_ISM1stOrd3.h
//  ISM
//
//  Created by Amanda Lind on 4/13/11.
//  Copyright 2011 Pennsylvania State University. All rights reserved.
//
//
//  plot_ISM1stOrd.h
//  ISM
//
//  Created by Amanda Lind on 4/5/11.
//  Copyright 2011 Pennsylvania State University. All rights reserved.
//


void  plot_ISM1stOrd3(std::vector<source> sources)

{   //PUT IN THE Building/Terrain INFORMATION
    const int num_points=16;
    const int num_faces=11;
    
    double wall_height=10*.3048;
    double wall_length=15*.3048;
    double wall_width=12*.3048;
    double wall_thickness=4*.3048;
    double radius=40;
    
    static float x[num_points][3]=
    {{0,0,0},           //1
        {0,0,wall_height},  //2
        {wall_width,0,wall_height},  //3
        {wall_width,0,0},            //4
        {0,wall_length,0},            //5
        {0,wall_length,wall_height}, //6
        {wall_thickness,wall_length,0},            //7
        {wall_thickness,wall_length,wall_height},  //8
        {wall_thickness, wall_thickness,0},                          //9
        {wall_thickness, wall_thickness, wall_height},                           //10
        {wall_width,wall_thickness,0},                              //11
        {wall_width,wall_thickness,wall_height},//12
        {-radius, -radius, 0},//13
        {-radius, radius, 0},//14
        {radius,radius,0},//15
        {radius,-radius,0}
    };      //16                     
    
    static vtkIdType pts[num_faces][4]=
    {   {4,3,2,1},
        {5,6,8,7},
        {9,10,12,11},
        {7,8,10,9},
        {11,12,3,4},
        {1,2,6,5}, 
        {3,12,10,8}, // missin 6, 2
        {16,13,4,1},
        {15,16,1,5},
        {14,15,5,7},
        {13,14,7,5,}};//missing 4,11
    
    
    // We'll create the building blocks of polydata including data attributes.
    vtkPolyData *face = vtkPolyData::New();
    vtkPoints *points = vtkPoints::New();
    vtkCellArray *polys = vtkCellArray::New();
    vtkFloatArray *scalars = vtkFloatArray::New();
    
    // Load the point, cell, and data attributes.
    for (int i=0; i<num_points; i++) points->InsertPoint(i,x[i]);    
    for (int i=0; i<num_faces; i++) polys->InsertNextCell(4,pts[i]);
    for (int i=0; i<num_points; i++) scalars->InsertTuple1(i,4); //this line clors the plan
    
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
    faceMapper->SetScalarRange(0,7);
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
        sphere[i]->SetRadius(.6);
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
        SphereActor[i]->GetProperty()->SetColor(0,0,1); //sphere color blue
    }
    
    
    
    
    
    //create axes
    vtkSmartPointer<vtkAxesActor> axesActor = vtkSmartPointer<vtkAxesActor>::New();
    axesActor->AxisLabelsOn();
    axesActor->SetTotalLength(radius*1.1,radius*1.1,radius*1.1);//lengths of the legs of the axis
    
    
    
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
    
    axesActor->GetYAxisCaptionActor2D()->SetCaptionTextProperty(axisLabelTextProperty ); 
    axesActor->GetXAxisCaptionActor2D()->SetCaptionTextProperty(axisLabelTextProperty ); 
    axesActor->GetZAxisCaptionActor2D()->SetCaptionTextProperty(axisLabelTextProperty ); 
    axisLabelTextProperty->Delete(); 
    
    
    
    
    // The usual rendering stuff.
    vtkCamera *camera = vtkCamera::New();
    camera->SetPosition(1,1,1);
    camera->SetFocalPoint(0,0,0);
    
    vtkRenderer *renderer = vtkRenderer::New();
    vtkRenderWindow *renWin = vtkRenderWindow::New();
    renWin->AddRenderer(renderer);
    
    vtkRenderWindowInteractor *iren = vtkRenderWindowInteractor::New();
    iren->SetRenderWindow(renWin);
    
    renderer->AddActor(faceActor);
    
//    for(int i=0; i< num_generated_sources; i++)
//    {
//        renderer->AddActor(SphereActor[i]);
//    }
//    
//    renderer ->AddActor (axesActor ) ;
    renderer->SetActiveCamera(camera);
    renderer->ResetCamera();
    renderer->SetBackground(1,1,1);
    
    renWin->SetSize(300,300);
    
    // interact with data
    renWin->Render();
    iren->Start();
    
    // Clean up
    
    face->Delete();
    for(int i=0; num_generated_sources ; i++)
    {
        SphereActor[i]->Delete();
    }
    faceMapper->Delete();
    faceActor->Delete();
    camera->Delete();
    renderer->Delete();
    renWin->Delete();
    iren->Delete();
    return; 
}