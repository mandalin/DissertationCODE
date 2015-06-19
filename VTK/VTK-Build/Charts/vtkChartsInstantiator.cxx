#include "vtkChartsInstantiator.h"
  
extern vtkObject* vtkInstantiatorvtkAxisNew();
extern vtkObject* vtkInstantiatorvtkBlockItemNew();
extern vtkObject* vtkInstantiatorvtkBrushNew();
extern vtkObject* vtkInstantiatorvtkChartLegendNew();
extern vtkObject* vtkInstantiatorvtkChartParallelCoordinatesNew();
extern vtkObject* vtkInstantiatorvtkChartXYNew();
extern vtkObject* vtkInstantiatorvtkColorSeriesNew();
extern vtkObject* vtkInstantiatorvtkContext2DNew();
extern vtkObject* vtkInstantiatorvtkContextActorNew();
extern vtkObject* vtkInstantiatorvtkContextSceneNew();
extern vtkObject* vtkInstantiatorvtkContextViewNew();
extern vtkObject* vtkInstantiatorvtkImageItemNew();
extern vtkObject* vtkInstantiatorvtkOpenGLContextDevice2DNew();
extern vtkObject* vtkInstantiatorvtkPenNew();
extern vtkObject* vtkInstantiatorvtkPlotBarNew();
extern vtkObject* vtkInstantiatorvtkPlotGridNew();
extern vtkObject* vtkInstantiatorvtkPlotLineNew();
extern vtkObject* vtkInstantiatorvtkPlotParallelCoordinatesNew();
extern vtkObject* vtkInstantiatorvtkPlotPointsNew();
extern vtkObject* vtkInstantiatorvtkTooltipItemNew();


  
void vtkChartsInstantiator::ClassInitialize()
{
  
  vtkInstantiator::RegisterInstantiator("vtkAxis", vtkInstantiatorvtkAxisNew);
  vtkInstantiator::RegisterInstantiator("vtkBlockItem", vtkInstantiatorvtkBlockItemNew);
  vtkInstantiator::RegisterInstantiator("vtkBrush", vtkInstantiatorvtkBrushNew);
  vtkInstantiator::RegisterInstantiator("vtkChartLegend", vtkInstantiatorvtkChartLegendNew);
  vtkInstantiator::RegisterInstantiator("vtkChartParallelCoordinates", vtkInstantiatorvtkChartParallelCoordinatesNew);
  vtkInstantiator::RegisterInstantiator("vtkChartXY", vtkInstantiatorvtkChartXYNew);
  vtkInstantiator::RegisterInstantiator("vtkColorSeries", vtkInstantiatorvtkColorSeriesNew);
  vtkInstantiator::RegisterInstantiator("vtkContext2D", vtkInstantiatorvtkContext2DNew);
  vtkInstantiator::RegisterInstantiator("vtkContextActor", vtkInstantiatorvtkContextActorNew);
  vtkInstantiator::RegisterInstantiator("vtkContextScene", vtkInstantiatorvtkContextSceneNew);
  vtkInstantiator::RegisterInstantiator("vtkContextView", vtkInstantiatorvtkContextViewNew);
  vtkInstantiator::RegisterInstantiator("vtkImageItem", vtkInstantiatorvtkImageItemNew);
  vtkInstantiator::RegisterInstantiator("vtkOpenGLContextDevice2D", vtkInstantiatorvtkOpenGLContextDevice2DNew);
  vtkInstantiator::RegisterInstantiator("vtkPen", vtkInstantiatorvtkPenNew);
  vtkInstantiator::RegisterInstantiator("vtkPlotBar", vtkInstantiatorvtkPlotBarNew);
  vtkInstantiator::RegisterInstantiator("vtkPlotGrid", vtkInstantiatorvtkPlotGridNew);
  vtkInstantiator::RegisterInstantiator("vtkPlotLine", vtkInstantiatorvtkPlotLineNew);
  vtkInstantiator::RegisterInstantiator("vtkPlotParallelCoordinates", vtkInstantiatorvtkPlotParallelCoordinatesNew);
  vtkInstantiator::RegisterInstantiator("vtkPlotPoints", vtkInstantiatorvtkPlotPointsNew);
  vtkInstantiator::RegisterInstantiator("vtkTooltipItem", vtkInstantiatorvtkTooltipItemNew);

  
}
          
void vtkChartsInstantiator::ClassFinalize()
{ 

  vtkInstantiator::UnRegisterInstantiator("vtkAxis", vtkInstantiatorvtkAxisNew);
  vtkInstantiator::UnRegisterInstantiator("vtkBlockItem", vtkInstantiatorvtkBlockItemNew);
  vtkInstantiator::UnRegisterInstantiator("vtkBrush", vtkInstantiatorvtkBrushNew);
  vtkInstantiator::UnRegisterInstantiator("vtkChartLegend", vtkInstantiatorvtkChartLegendNew);
  vtkInstantiator::UnRegisterInstantiator("vtkChartParallelCoordinates", vtkInstantiatorvtkChartParallelCoordinatesNew);
  vtkInstantiator::UnRegisterInstantiator("vtkChartXY", vtkInstantiatorvtkChartXYNew);
  vtkInstantiator::UnRegisterInstantiator("vtkColorSeries", vtkInstantiatorvtkColorSeriesNew);
  vtkInstantiator::UnRegisterInstantiator("vtkContext2D", vtkInstantiatorvtkContext2DNew);
  vtkInstantiator::UnRegisterInstantiator("vtkContextActor", vtkInstantiatorvtkContextActorNew);
  vtkInstantiator::UnRegisterInstantiator("vtkContextScene", vtkInstantiatorvtkContextSceneNew);
  vtkInstantiator::UnRegisterInstantiator("vtkContextView", vtkInstantiatorvtkContextViewNew);
  vtkInstantiator::UnRegisterInstantiator("vtkImageItem", vtkInstantiatorvtkImageItemNew);
  vtkInstantiator::UnRegisterInstantiator("vtkOpenGLContextDevice2D", vtkInstantiatorvtkOpenGLContextDevice2DNew);
  vtkInstantiator::UnRegisterInstantiator("vtkPen", vtkInstantiatorvtkPenNew);
  vtkInstantiator::UnRegisterInstantiator("vtkPlotBar", vtkInstantiatorvtkPlotBarNew);
  vtkInstantiator::UnRegisterInstantiator("vtkPlotGrid", vtkInstantiatorvtkPlotGridNew);
  vtkInstantiator::UnRegisterInstantiator("vtkPlotLine", vtkInstantiatorvtkPlotLineNew);
  vtkInstantiator::UnRegisterInstantiator("vtkPlotParallelCoordinates", vtkInstantiatorvtkPlotParallelCoordinatesNew);
  vtkInstantiator::UnRegisterInstantiator("vtkPlotPoints", vtkInstantiatorvtkPlotPointsNew);
  vtkInstantiator::UnRegisterInstantiator("vtkTooltipItem", vtkInstantiatorvtkTooltipItemNew);

  
}

vtkChartsInstantiator::vtkChartsInstantiator()
{
  if(++vtkChartsInstantiator::Count == 1)
    { 
    vtkChartsInstantiator::ClassInitialize(); 
    }
}

vtkChartsInstantiator::~vtkChartsInstantiator()
{
  if(--vtkChartsInstantiator::Count == 0)
    { 
    vtkChartsInstantiator::ClassFinalize(); 
    }
}

// Number of translation units that include this class's header.
// Purposely not initialized.  Default is static initialization to 0.
unsigned int vtkChartsInstantiator::Count;
