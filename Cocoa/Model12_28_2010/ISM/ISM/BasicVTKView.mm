//
//  BasicVTKView.mm
//  ISM
//
//  Created by Amanda Lind on 3/29/11.
//  Copyright 2011 Pennsylvania State University. All rights reserved.
//

#import "BasicVTKView.h"

#define id Id
#import "vtkRenderer.h"
#import "vtkRenderWindow.h"
#import "vtkRenderWindowInteractor.h"
#import "vtkCocoaRenderWindowInteractor.h"
#import "vtkCocoaRenderWindow.h"
#undef id

@implementation BasicVTKView

-(id)initWithFrame:(NSRect)frame {
    self = [super initWithFrame:frame];
    if (self) {
        vtkRenderer *ren = vtkRenderer::New();
        vtkRenderWindow *renWin = vtkRenderWindow::New();
        vtkRenderWindowInteractor *renWinInt = vtkRenderWindowInteractor::New();
        
        renWin->SetWindowId([self window]);
        renWin->SetDisplayId(self);
        renWin->AddRenderer(ren);
        renWinInt->SetRenderWindow(renWin);
        
        [self setVTKRenderWindow:(vtkCocoaRenderWindow *)renWin];
        [self setRenderer:ren];
        
        if ( !renWinInt->GetInitialized() ) renWinInt->Initialize();
    }
    return self;
}

-(void)dealloc {
    vtkRenderer *ren = [self getRenderer];
    vtkRenderWindow *renWin = [self getVTKRenderWindow];
    vtkRenderWindowInteractor *renWinInt = [self getInteractor];
    
    if (ren) ren->Delete();
    if (renWin) renWin->Delete();
    if (renWinInt) renWinInt->Delete();
    
    [self setRenderer:NULL];
    [self setVTKRenderWindow:NULL];
    
    [super dealloc];
}

-(vtkRenderer*)getRenderer {
    return renderer;
}

-(void)setRenderer:(vtkRenderer*)theRenderer {
    renderer = theRenderer;
}


@end