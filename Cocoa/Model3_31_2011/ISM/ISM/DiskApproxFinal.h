//
//  DiskApproxFinal.h
//  ISM
//
//  Created by Amanda Lind on 7/1/11.
//  Copyright 2011 Pennsylvania State University. All rights reserved.
//

void DiskApproxFinal(   unsigned Qind, 
                     std::vector<source> sources, 
                     std::vector<wall> planes, 
                     position_vector Ppos, /*receiver position*/
                     double s /*seconds of IR*/, 
                     double co, /*soundspeed*/ 
                     std::vector<double> freqdom_single_sided, /*definition of frequency domain*/
                     fftw_complex * X_R
                     )
//
{   int Nss=freqdom_single_sided.size();
    position_vector src2plane=sub(Ppos,planes[sources[Qind].mother_wall_ind].center);
    
    double R=pyth_sum(src2plane.v);
    double a=25; //!ACHTUNG!
    double R_breve=20;
    
    //Disk filters 
    
    double r1, r2, r3;
    double R1, R2, R3;
    double fcutoff1, fcutoff2, fcutoff3;
    double diam=10;
    
    r1=2;
    r2=7.6569;
    r3=9.0711;
    
    
    // double r = 3.000000000369378e+11;
    
    //for non inf r
    //R1=1/((1/2)*(1/r1 + 1/r));
    //R2=1/((1/2)*(1/r2 + 1/r));
    //R3=1/((1/2)*(1/r3 + 1/r));
    
    //for plane wave incidence
    R1=2*r1;
    R2=2*r2;
    R3=2*r3;
    
    fcutoff1=(co)*(R1/(pow(4*10,2)));
    fcutoff2=(co)*(R2/(pow(4*10,2)));
    fcutoff3=(co)*(R3/(pow(4*10,2)));
    
    fftw_complex* FreqAtt1 = new fftw_complex[Nss];
    fftw_complex* FreqAtt2 = new fftw_complex[Nss];
    fftw_complex* FreqAtt3 = new fftw_complex[Nss];
    
    
    for(int i=0; i< Nss; i++)
    {   FreqAtt1[i][0]=(sin((freqdom_single_sided[i]*2*pi*(diam/2)*(diam/2))/(co*2*R1)));
        FreqAtt2[i][0]=(sin((freqdom_single_sided[i]*2*pi*(diam/2)*(diam/2))/(co*2*R2))); // From Kuttruff Pg 57, applying sqrt
        FreqAtt3[i][0]=(sin((freqdom_single_sided[i]*2*pi*(diam/2)*(diam/2))/(co*2*R3))); // p/pmaxs
        
        FreqAtt1[i][1]=0;
        FreqAtt2[i][1]=0;
        FreqAtt3[i][1]=0;
        
        //    std::cout<<FreqAtt1[i][0]<<"          "<<FreqAtt2[i][0]<<"          "<<FreqAtt3[i][0]<<std::endl;
    }
    
    
    
    
    //remove the nulls due to interference
    
    double last_val1=0;
    double last_val2=0;
    double last_val3=0;
    bool peaked_flag1=false;
    bool peaked_flag2=false;
    bool peaked_flag3=false;
    for(int i=0; i< Nss; i++)
    { 
        
        if((FreqAtt1[i][0]<last_val1)||(peaked_flag1))
        {   peaked_flag1=true;
            FreqAtt1[i][0]=1;
        }
        last_val1=FreqAtt1[i][0];
        
        if((FreqAtt2[i][0]<last_val2)||(peaked_flag2))
        {   peaked_flag2=true;
            FreqAtt2[i][0]=1;
        }
        last_val2=FreqAtt2[i][0];
        
        if((FreqAtt3[i][0]<last_val3)||(peaked_flag3))
        {   peaked_flag3=true;
            FreqAtt3[i][0]=1;
            
            
        }
        last_val3=FreqAtt3[i][0];
        
        std::cout<<freqdom_single_sided[i]<<" [Hz], "<<FreqAtt3[i][0]<<std::endl;
        
    }
    ///////
    
    vtkSmartPointer<vtkContextView> view = vtkSmartPointer<vtkContextView>::New();
    view->GetRenderer()->SetBackground(1.0, 1.0, 1.0);
    view->GetRenderWindow()->SetSize(400, 300);
    
    vtkSmartPointer<vtkChartXY> chart =
    vtkSmartPointer<vtkChartXY>::New();
    view->GetScene()->AddItem(chart);
    chart->SetShowLegend(true);
    
    vtkAxis *Xaxis = vtkAxis::New();
    int axisindexX=1;
    Xaxis=chart->GetAxis (axisindexX);
    Xaxis->SetLogScale(true);
    Xaxis->SetRange ((double)0,(double)150);
    
    std::string tempX = "Frequency [Hz]";
    Xaxis->SetTitle(tempX.c_str());
    
    vtkAxis *YAxis = vtkAxis::New();
    int axisindexY=0;
    YAxis=chart->GetAxis (axisindexY);
    
    vtkTextProperty * TitleProps;
    TitleProps=YAxis->GetLabelProperties();
    TitleProps->SetOrientation(90);
    
    
    
    std::string tempY = "|p/pmax|, ppos1";
    YAxis->SetTitle(tempY.c_str());
    
    
    // Create a table with some points in it...
    vtkSmartPointer<vtkTable> table =
    vtkSmartPointer<vtkTable>::New();
    
    vtkSmartPointer<vtkFloatArray> freqs =
    vtkSmartPointer<vtkFloatArray>::New();
    freqs->SetName("Frequency [Hz]");
    table->AddColumn(freqs);
    
    vtkSmartPointer<vtkFloatArray> Magnitudes1 =
    vtkSmartPointer<vtkFloatArray>::New();
    Magnitudes1->SetName("|p/pmax|, ppos1");
    table->AddColumn(Magnitudes1);
    
    vtkSmartPointer<vtkFloatArray> Magnitudes2 =
    vtkSmartPointer<vtkFloatArray>::New();
    Magnitudes2->SetName("|p/pmax|, ppos2");
    table->AddColumn(Magnitudes2);
    
    vtkSmartPointer<vtkFloatArray> Magnitudes3 =
    vtkSmartPointer<vtkFloatArray>::New();
    Magnitudes3->SetName("|p/pmax|, ppos3");
    table->AddColumn(Magnitudes3);
    
    int numPoints=Nss;
    
    table->SetNumberOfRows(numPoints);
    
    float tempfloat;
    
    float df= freqdom_single_sided[1]-freqdom_single_sided[0];
    
    for (int i = 0; i < numPoints; ++i)
    {
        
        
        table->SetValue(i, 0, i*df);
        
        tempfloat=FreqAtt1[i][0];
        table->SetValue(i, 1, tempfloat);
        
        tempfloat=FreqAtt2[i][0];
        table->SetValue(i, 2, tempfloat);
        
        tempfloat=FreqAtt2[i][0];
        table->SetValue(i, 3, tempfloat);
    }            
    
    
    // Add multiple scatter plots, setting the colors etc
    vtkPlot *points = chart->AddPlot(vtkChart::POINTS);
    points->SetInput(table, 0, 1);
    points->SetColor(0, 0, 225, 255);
    points->SetWidth(1.0);
    vtkPlotPoints::SafeDownCast(points)->SetMarkerStyle(vtkPlotPoints::CROSS);
    
    points = chart->AddPlot(vtkChart::POINTS);
    points->SetInput(table, 0, 2);
    points->SetColor(225, 0, 0, 255);
    points->SetWidth(1.0);
    vtkPlotPoints::SafeDownCast(points)->SetMarkerStyle(vtkPlotPoints::PLUS);
    
    points = chart->AddPlot(vtkChart::POINTS);
    points->SetInput(table, 0, 3);
    points->SetColor(0, 225, 0, 255);
    points->SetWidth(1.0);
    vtkPlotPoints::SafeDownCast(points)->SetMarkerStyle(vtkPlotPoints::CIRCLE);
    
    
    
    
    //Finally render the scene
    view->GetRenderWindow()->SetMultiSamples(0);
    view->GetInteractor()->Initialize();
    view->GetInteractor()->Start();
    
    // return EXIT_SUCCESS;
    
    
    return;
}
