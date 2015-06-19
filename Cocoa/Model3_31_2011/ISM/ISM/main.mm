//
//
//  main.m
//  ISM
//
//  Created by Amanda Lind on 12/29/10.
//  Copyright Pennsylvania State University 2010. All rights reserved.
//

#import <Cocoa/Cocoa.h>

/*
 *  Find_Images.cpp
 *  ISM
 *
 *  Created by Amanda Lind on 12/29/10.
 *  Copyright 2010 Pennsylvania State University. All rights reserved.
 *
 */


/////////// From standard library included by  Lind:


#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>

#include <cmath>
#include <complex> //does this conflict with Complex.h file associated with fftw++ ?
// answered on page 11 of fftw3manual.pdf
//
//If you have a C compiler, such as gcc, that supports the recent C99 standard, and
//you #include <complex.h> before <fftw3.h>, then fftw_complex is the native
//double-precision complex type and you can manipulate it with ordinary arithmetic.
//Otherwise, FFTW defines its own complex type, which is bit-compatible with the C99
//complex type.
#include <numeric>
#include <valarray>
#include <typeinfo>

/////////// From fftw++
#include"fftw3.h"

/////////// Modules from Thesis
// Module Appendix A.3
#include "pyth_sum.h"
#include "x_from_X.h"
#include "LinearSpectrum.h"
#include "hankel_2.h"



/////////// From TR1 for Special Functions

#include <boost/tr1/type_traits.hpp>
#include "boost/math/tr1.hpp"
#include <boost/tr1/array.hpp>
#include <boost/tr1/complex.hpp>
#include <boost/math/complex.hpp>
#include <boost/tr1/functional.hpp>
#include <boost/tr1/memory.hpp>
#include <boost/tr1/random.hpp>
#include <boost/tr1/regex.hpp>
#include <boost/tr1/tuple.hpp>
#include <boost/tr1/utility.hpp>
#include <boost/tr1/cmath.hpp>
#include <boost/math/special_functions/bessel.hpp>
//for matrix math
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/lu.hpp>
#include <boost/numeric/ublas/io.hpp>
//for polygon manipulation
#include <boost/array.hpp>
#include <boost/polygon/polygon.hpp>
//for converting ints to strings
#include <boost/lexical_cast.hpp>
//Writing Output
//#include <boost/filesystem.hpp>
//#include <boost/filesystem/fstream.hpp>
#include <boost/foreach.hpp>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

#include <limits> //for NAN
extern const double NaN =std::numeric_limits<double>::quiet_NaN();

/////////// Modules created for C++ convenience /classes
#include "position_vector_class.h"
#include "IsInfront.h"
#include "storage_adapters.hpp"
#include "INVERT_MATRIX.hpp"
#include "wall.h"
#include "source.h"
#include "Edge.h"
//More Modules From Thesis

#include "geometry_generalized.h"                     //geometries here
#include "geometry_generalized_box.h"
#include "generalized_geometry_52Blackbird.h"
#include "generalized_geometry_CSF.h"
#include "geometry_generalized_Albert.h"
#include "geometry_IsolatedWall.h"


#include "rotate2newFOR.h"
#include "inside.h"
#include "pointinpoly.h"
#include "pointinplane.h"
#include "pointvisible.h"
#include "ispolycw.h"									//needs testing
#include "flip.h"
#include "MakeMatrix.h"
#include "center.h"
#include "centerOgravity.h"
#include "shaded_center.h"

//Graphics
//OpenGL
#include <OpenGL/glext.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
//VTK
#include "vtkAxes.h"//for axes
#include "vtkActor.h"
#include <vtkAxesActor.h> //for axes, trying a second way
#include "vtkCallbackCommand.h"
#include "vtkCamera.h"
#include "vtkCellArray.h"
#include "vtkCaptionActor2D.h" //also for axes
#include "vtkCommand.h"
#include "vtkConnectivityFilter.h"
#include "vtkContourFilter.h"
#include "vtkDataSetMapper.h"
#include <vtkDataSetSurfaceFilter.h>
#include "vtkFloatArray.h"
#include "vtkGeometryFilter.h"
#include "vtkInteractorStyleImage.h"
#include "vtkImplicitBoolean.h"     //for plane union
#include "vtkImageActor.h"
#include "vtkJPEGReader.h"
#include "vtkLookupTable.h"
#include "vtkPointData.h"
#include <vtkPointSource.h>
#include "vtkPoints.h"
#include "vtkPolyData.h"
#include "vtkPointDataToCellData.h"
#include "vtkPolyDataMapper.h"
#include "vtkPolyDataNormals.h"
#include "vtkPolygon.h"             //for plane union
#include "vtkProperty.h"
#include "vtkTextActor.h"
#include "vtkTextProperty.h" //for axes
#include "vtkThreshold.h"
#include "vtkTubeFilter.h" //for axes
#include "vtkUnstructuredGridReader.h"
#include "vtkWarpVector.h"
#include "vtkRenderer.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkSmartPointer.h"
#include "vtkSphereSource.h"
#include "vtkBoundedPlanePointPlacer.h" //for plane union
#include "vtkImplicitFunction.h" //for plane union
#include "vtkPolyPlane.h" //for plane union
#include "vtkPolyLine.h"    //for plane union
#include "vtkExtractPolyDataGeometry.h"//for plane union
#include "vtkLight.h"//for lighting
#include "vtkUnstructuredGrid.h"//for general visualization
#include "vtkIdList.h"//for general visualization
#include "vtkTextActor.h"//for text labels
#include "vtkTextMapper.h"//for text labels
#include "vtkAxes.h"//for axis
#include "vtkPolyDataMapper.h"//for text and axis
#include "vtkFollower.h"
#include "vtkVectorText.h"
//for vtkGeometryFilter in order to convert vtkPolygons into vtkPolyData in TerrainMesh.h
#include <vtkXMLPolyDataWriter.h>
#include <vtkTriangleFilter.h>
//  for probing
#include <vtkProbeFilter.h>
//For Visualization
#include <vtkDelaunay2D.h>
#include <vtkDelaunay3D.h>
#include <vtkLookupTable.h>




//More Modules From Thesis
#include "plot_ISM1stOrd.h"
#include "TwodPolygonAnd.h"
#include "planeunion.h"
#include "in_field_ang_corners.h"						//needs testing
#include "source_output.h"                              //holds source_output class
#include "ConsolidateLegalSources.h"							// needs testing
#include "IsSourceEffective.h"
#include "printgeometry3.h"
#include "CplxDiv.h"
#include "CplxMult.h"
#include "vectorOps.h"
#include "dhtm.h"
#include "plot_FieldAngle.h"
#include "plot_GeometryGeneral.h"
#include "plot_SingleSource.h"
#include "SubsamplePlane.h"
#include "TerrainMesh.h"
#include "StoreSimulation.h"
#include "DiskApproxFinal_Generalized.h"
#include "IRsFromSources.h"
#include "IRsFromSources_1file.h"


//For XY Plotting:
#include <vtkChartXY.h>
#include <vtkPlotPoints.h>
#include <vtkPlot.h>
#include <vtkTable.h>
#include <vtkFloatArray.h>
#include <vtkContextView.h>
#include <vtkContextScene.h>
#include <vtkAxis.h>
#include <vtkTextProperty.h>

//Wrapping up IR
#include <stdio.h>
#include <time.h>

//GDAL
//#include "GDAL/gdal_priv.h"
//#include "GDAL/cpl_conv.h" // for CPLMalloc()
//#include "GDAL/gdal.h"
//#include "plot_SGR_Orientation.h"
//#include "ISM_DEM_PAMAP_LoadOneTile.h"                      //DEM geometries here.

//For Making Contours
#include "vtkScalarBarActor.h"  //for a colorbar
#include "vtkWindowToImageFilter.h"
#include "vtkTIFFWriter.h"
#include "vtkPNGWriter.h"
#include <vtkDiscretizableColorTransferFunction.h>
#include <vtkColorTransferFunction.h>
#include "TerrainMesh_Contour.h"
#include "TerrainMesh_NumRefs.h"

#include "Fresnel.h"
#include "Fresnel_code.h"
#include "TransitionFunction.h"
#include "UTDDiffractionCoeff.h"
#include "BTMDiffraction.h"
#include "OneEdgeBTM.h"
#include "OneEdgeUTD.h"

#include <string.h>
#include "ReadInSourceFile.h"
#include "OneSourcePos.h"
#include "RenderFacetedSphere.h"

//For Large Dataset
//#include "stxxl.h"
//#include <stxxl/vector>
//#include <stxxl/priority_queue>
//#include <stxxl/sort>
//#include <stxxl/scan>
//#include <stxxl/stream>



//---- MAIN ---------------------------------------------------------------------------------------
//---- MAIN ---------------------------------------------------------------------------------------
//---- MAIN ---------------------------------------------------------------------------------------
//---- MAIN ---------------------------------------------------------------------------------------
std::vector<corner> wall::unique_corners;                               //declare static member in filescope


int main()
{
    
    
    
    std::cout << "Hello, World!\n";
    std::cout << "Hello, World!\n";
    std::cout << "Hello, World!\n";
    std::cout << "Hello, World!\n";
    std::cout << "Hello, World!\n";
    std::cout << "Hello, World!\n";
    std::cout << "Hello, World!\n";
    std::cout << "Hello, World!\n";
    std::cout << "Hello, World!\n";
    std::cout << "Hello, World!\n";
    
    
    
    //    For Testing the Transition Function
    //    fftw_complex * result  =new fftw_complex[1];;
    //    double resultmag;
    //    double resultphs;
    //    TransitionFunction(.002,result);
    //    resultmag=std::sqrt(result[0][0]*result[0][0]+result[0][1]*result[0][1]);
    //    TransitionFunction(0.01,result);
    //    resultmag=std::sqrt(result[0][0]*result[0][0]+result[0][1]*result[0][1]);
    //    TransitionFunction(.1,result);
    //    resultmag=std::sqrt(result[0][0]*result[0][0]+result[0][1]*result[0][1]);
    //    TransitionFunction(.2,result);
    //    resultmag=std::sqrt(result[0][0]*result[0][0]+result[0][1]*result[0][1]);
    //    TransitionFunction(1,result);
    //    resultmag=std::sqrt(result[0][0]*result[0][0]+result[0][1]*result[0][1]);
    //    TransitionFunction(1.2,result);
    //    resultmag=std::sqrt(result[0][0]*result[0][0]+result[0][1]*result[0][1]);
    //    TransitionFunction(10,result);
    //    resultmag=std::sqrt(result[0][0]*result[0][0]+result[0][1]*result[0][1]);
    //    This passed the test
    
    //    For testing UTD diffaction Coeffecient
    //    fftw_complex * Ed_over_Ei  =new fftw_complex[1];;
    //    double Phi;
    //    double Phi_prime;
    //    double alpha;
    //    double Beta_o;
    //    double s;
    //    double k;
    //    double kappa;
    //    bool valid;
    //    UTDDiffractionCoeff(Phi, Phi_prime, alpha, Beta_o, s, k, Ed_over_Ei, kappa, valid);
    //
    //
    
    for(unsigned simnum_=1; simnum_<=1; simnum_++)
    {
        OneSourcePos(simnum_);
    }
    return 0;
}

//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------


