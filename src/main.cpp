#include "ofMain.h"
#include "ofApp.h"
#include "ofGLProgrammableRenderer.h"

/**
 *  main.cpp
 *
 *  @param  None
 *
 *  @return App's exit code.
 */

//========================================================================
int main( )
{

    ofSetCurrentRenderer(ofGLProgrammableRenderer::TYPE);    // Turn on programmable render pipeline

    // Setup and run OpenFrameworks app
    ofSetupOpenGL(1024,768,OF_WINDOW);
	ofRunApp(new ofApp());

}
