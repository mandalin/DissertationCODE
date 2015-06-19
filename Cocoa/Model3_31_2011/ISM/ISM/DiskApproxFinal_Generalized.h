//
//  DiskApproxFinal_Generalized.h
//  ISM
//
//  Created by Amanda Lind on 8/23/11.
//  Copyright 2011 Pennsylvania State University. All rights reserved.
//


void DiskApproxFinal_Generalized(   unsigned Qind, 
                     std::vector<source> sources, 
                     std::vector<wall> planes, 
                     position_vector Ppos, /*receiver position*/
                     double s /*seconds of IR*/, 
                     double co, /*soundspeed*/ 
                     std::vector<double> freqdom_single_sided, /*definition of frequency domain*/
                     fftw_complex ** X_R
                     )
//
{   int Nss=freqdom_single_sided.size();
    position_vector tempcenter;
    //tempcenter.assign(center(planes[planes[sources[Qind].mother_wall_ind].num]));
    //planes[sources[Qind].mother_wall_ind].center=tempcenter;
    int mother_wall_index_of_Qind=sources[Qind].mother_wall_ind;
    position_vector src2plane=sub(Ppos,planes[planes[mother_wall_index_of_Qind].num].center);
    
 


    double fcutoff1;
//    double diam=10;//!ACHTUNG! 10 for box, but we need something more general for L shape
    

    // double r = 3.000000000369378e+11;
    
    //for non inf r
    //R1=1/((1/2)*(1/r1 + 1/r)); 
    
    //for plane wave incidence
    double r1=pyth_sum(src2plane.v);
    double R1=2*r1;
     R1=40;
    double diam=5;//!ACHTUNG! 20 for L shape, but we need something more general

    double denom=(R1/(4*(10*10)));
    fcutoff1=(co)*denom;
//    std::cout<<"The cutoff frequency for the disk filter magnitude aproximation is "<<fcutoff1<<std::endl;

    
    fftw_complex * FreqAtt1 = new fftw_complex[Nss];
    
    double last_val1=0;
    bool peaked_flag1=false; 
    for(int i=0; i< Nss; i++)
    {   
        if(!peaked_flag1)
        {   FreqAtt1[i][0]=sin(    (freqdom_single_sided[i]*2*pi*(diam/2)*(diam/2))  /  (co*2*R1)  );// From Kuttruff Pg 57, applying sqrt,  p/pmaxs
        }
        
        
        if((FreqAtt1[i][0]<last_val1)||(peaked_flag1))      //remove the nulls due to interference
        {   peaked_flag1=true;
            FreqAtt1[i][0]=1;
        }
        
        FreqAtt1[i][1]=0;
        last_val1=FreqAtt1[i][0];

        
        std::cout<<FreqAtt1[i][0]<<std::endl;
    }
    
    *X_R=FreqAtt1;
    
    

    ///////
//    
//    vtkSmartPointer<vtkContextView> view = vtkSmartPointer<vtkContextView>::New();
//    view->GetRenderer()->SetBackground(1.0, 1.0, 1.0);
//    view->GetRenderWindow()->SetSize(400, 300);
//    
//    vtkSmartPointer<vtkChartXY> chart =
//    vtkSmartPointer<vtkChartXY>::New();
//    view->GetScene()->AddItem(chart);
//    chart->SetShowLegend(true);
//    
//    vtkAxis *Xaxis = vtkAxis::New();
//    int axisindexX=1;
//    Xaxis=chart->GetAxis (axisindexX);
//    Xaxis->SetLogScale(true);
//    Xaxis->SetRange ((double)0,(double)150);
//    
//    std::string tempX = "Frequency [Hz]";
//    Xaxis->SetTitle(tempX.c_str());
//    
//    vtkAxis *YAxis = vtkAxis::New();
//    int axisindexY=0;
//    YAxis=chart->GetAxis (axisindexY);
//    
//    vtkTextProperty * TitleProps;
//    TitleProps=YAxis->GetLabelProperties();
//    TitleProps->SetOrientation(90);
//    
//    
//    
//    std::string tempY = "|p/pmax|, ppos1";
//    YAxis->SetTitle(tempY.c_str());
//    
//    
//    // Create a table with some points in it...
//    vtkSmartPointer<vtkTable> table =
//    vtkSmartPointer<vtkTable>::New();
//    
//    vtkSmartPointer<vtkFloatArray> freqs =
//    vtkSmartPointer<vtkFloatArray>::New();
//    freqs->SetName("Frequency [Hz]");
//    table->AddColumn(freqs);
//    
//    vtkSmartPointer<vtkFloatArray> Magnitudes1 =
//    vtkSmartPointer<vtkFloatArray>::New();
//    Magnitudes1->SetName("|p/pmax|, ppos1");
//    table->AddColumn(Magnitudes1);
//    
//    int numPoints=Nss;
//    
//    table->SetNumberOfRows(numPoints);
//    
//    float tempfloat;
//    
//    float df= freqdom_single_sided[1]-freqdom_single_sided[0];
//    
//    for (int i = 0; i < numPoints; ++i)
//    {
//        
//        
//        table->SetValue(i, 0, i*df);
//        
//        tempfloat=FreqAtt1[i][0];
//        X_R[i][0]=FreqAtt1[i][0];
//        X_R[i][1]=FreqAtt1[i][1];
//        table->SetValue(i, 1, tempfloat);
//
//    }            
//    
//    
//    // Add multiple scatter plots, setting the colors etc
//    vtkPlot *points = chart->AddPlot(vtkChart::POINTS);
//    points->SetInput(table, 0, 1);
//    points->SetColor(0, 225, 0, 255);
//    points->SetWidth(1.0);
//    vtkPlotPoints::SafeDownCast(points)->SetMarkerStyle(vtkPlotPoints::CIRCLE);
//    
//    
//    
//    
//    //Finally render the scene
//    view->GetRenderWindow()->SetMultiSamples(0);
//    view->GetInteractor()->Initialize();
//    view->GetInteractor()->Start();
//    
//    // return EXIT_SUCCESS;
//    


    
    
    
    return;
}
