 /*=========================================================================
       00002 
       00003   Program:   Visualization Toolkit
       00004   Module:    vtkPolyPlane.h
       00005 
       00006   Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
       00007   All rights reserved.
       00008   See Copyright.txt or http://www.kitware.com/Copyright.htm for details.
       00009 
       00010      This software is distributed WITHOUT ANY WARRANTY; without even
       00011      the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
       00012      PURPOSE.  See the above copyright notice for more information.
       00013 
       00014 =========================================================================*/
 #ifndef __vtkPolyPlane_h
 #define __vtkPolyPlane_h
 
 #include "vtkImplicitFunction.h"
 
 class vtkPolyLine;
 class vtkDoubleArray;
 
 class VTK_FILTERING_EXPORT vtkPolyPlane : public vtkImplicitFunction
 {
     public:
       static vtkPolyPlane *New();
     
       vtkTypeMacro(vtkPolyPlane,vtkImplicitFunction);
       void PrintSelf(ostream& os, vtkIndent indent);
     
     
       double EvaluateFunction(double x[3]);
       double EvaluateFunction(double x, double y, double z)
         {return this->vtkImplicitFunction::EvaluateFunction(x, y, z); } ;
     
       void EvaluateGradient(double x[3], double g[3]);
     
     
       virtual void SetPolyLine( vtkPolyLine * );
       vtkGetObjectMacro( PolyLine, vtkPolyLine );
     
       virtual unsigned long GetMTime();
     
     protected:
       vtkPolyPlane();
       ~vtkPolyPlane();
     
       void ComputeNormals();
     
       double           ExtrusionDirection[3];
       vtkPolyLine    * PolyLine;
       vtkTimeStamp     NormalComputeTime;
       vtkDoubleArray * Normals;
       vtkIdType        ClosestPlaneIdx;
     
     private:
       vtkPolyPlane(const vtkPolyPlane&);  // Not implemented.
       void operator=(const vtkPolyPlane&);  // Not implemented.
     };
 
 #endif