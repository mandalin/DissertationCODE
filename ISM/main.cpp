//  main.cpp
//  ISM
//
//  Created by Amanda Lind on 12/7/10.
//  Copyright Pennsylvania State University 2010. All rights reserved.

/////////// Stuff included by default : 
#include <Carbon/Carbon.h>
#include "TApplication.h"
#include "TWindow.h"

/////////// From standard library included by Lind:
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>

#include <cmath>
#include <complex>
#include <numeric>
#include <valarray>

/////////// Modules from Thesis
// Module Appendix A.3
#include "pyth_sum.h"


///////// Stuff that makes it a Carbon Application
// Our custom application class
class CarbonApp : public TApplication
{
    public:
							
                            CarbonApp() {}
        virtual             ~CarbonApp() {}
        
    protected:
        virtual Boolean     HandleCommand( const HICommandExtended& inCommand );
};

// Our main window class
class MainWindow : public TWindow
{
    public:
                            MainWindow() : TWindow( CFSTR("MainWindow") ) {}
        virtual             ~MainWindow() {}
        
        static void         Create();
        
    protected:
        virtual Boolean     HandleCommand( const HICommandExtended& inCommand );
};

//-----THE ACTUAL CODE ---------------------------------------------------------------------------------------
//-----THE ACTUAL CODE ---------------------------------------------------------------------------------------
//-----THE ACTUAL CODE ---------------------------------------------------------------------------------------
//-----THE ACTUAL CODE ---------------------------------------------------------------------------------------

int main (int argc, char * const argv[]) 
{  // CarbonApp app;
	// Create a new window. A full-fledged application would do this from an AppleEvent handler
	// for kAEOpenApplication.
	//MainWindow::Create();
	    
	//app.Run();

    std::cout << "Hello, World!\n";
    return 0;
}

//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------

Boolean
CarbonApp::HandleCommand( const HICommandExtended& inCommand )
{
    switch ( inCommand.commandID )
    {
        case kHICommandNew:
            MainWindow::Create();
            return true;
            
        // Add your own command-handling cases here
        
        default:
            return false;
    }
}

//--------------------------------------------------------------------------------------------
void
MainWindow::Create()
{
    MainWindow* wind = new MainWindow();

    // Position new windows in a staggered arrangement on the main screen
    RepositionWindow( *wind, NULL, kWindowCascadeOnMainScreen );
    
    // The window was created hidden, so show it
    wind->Show();
}

//--------------------------------------------------------------------------------------------
Boolean
MainWindow::HandleCommand( const HICommandExtended& inCommand )
{
    switch ( inCommand.commandID )
    {
        // Add your own command-handling cases here
        
        default:
            return false;
    }
}
