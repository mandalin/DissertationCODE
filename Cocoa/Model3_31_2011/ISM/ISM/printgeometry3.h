//
//  printgeometry3.h
//  ISM
//
//  Created by Amanda Lind on 4/13/11.
//  Copyright 2011 Pennsylvania State University. All rights reserved.
//


void printgeometry3()
{

double l,w,h,t;
l=250*.3048; w=125*.3048; h=30*.3048; t=40*.3048;
int radius=300;

// double wall_height=1;
// wall_length=1;
// double wall_width=1;
// radius=5;

const int num_points=16;
const int num_faces=9;

static float x[num_points][3]=
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
{-radius/2,-radius/2,0},
{-radius/2,radius/2,0},
{radius/2,radius/2,0},
{radius/2,-radius/2,0},//16
}; 

static vtkIdType pts[num_faces][4]=
{{3,2,1,0},{0,1,5,4},{4,5,6,7},{7,6,9,8},{8,9,10,11},{11,10,2,3},{10,9,1,3},{1,9,6,5}, {12,13,14,15}};


// We'll create the building blocks of polydata including data attributes.
vtkPolyData *face = vtkPolyData::New();
vtkPoints *points = vtkPoints::New();
vtkCellArray *polys = vtkCellArray::New();
vtkFloatArray *scalars = vtkFloatArray::New();

// Load the point, cell, and data attributes.
for (int i=0; i<num_points; i++) points->InsertPoint(i,x[i]);    
for (int i=0; i<num_faces; i++) polys->InsertNextCell(4,pts[i]);
for (int i=0; i<num_points; i++) scalars->InsertTuple1(i,4); //this line clors the plan
}
