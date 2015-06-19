//
//  BasicVTKView.h
//  ISM
//
//  Created by Amanda Lind on 3/29/11.
//  Copyright 2011 Pennsylvania State University. All rights reserved.
//

#import <Cocoa/Cocoa.h>

#import "vtkCocoaGLView.h"

#define id Id
#import "vtkRenderer.h"
#undef id

@interface BasicVTKView : vtkCocoaGLView 
{
    vtkRenderer *renderer;
}

- (vtkRenderer *)getRenderer;
- (void)setRenderer:(vtkRenderer *)theRenderer;

@end