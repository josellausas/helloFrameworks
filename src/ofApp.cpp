#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    setupImages();
    setupShaders();
    setupWebcam();
    setupPs3Cam();
}

void ofApp::setupImages()
{
    // Loads an image
    // Este archivo debe de estar adentro de el folder ./bin/data
    testJPGImage.loadImage("image.jpg");
    img01x = 0;
    img02y = 0;
    
    testPNGImage.loadImage("image.png");
    img02x = testJPGImage.width;
    img02y = 0;
}


/**
 *  Sets up them shaders
 */
void ofApp::setupShaders()
{
    if(ofIsGLProgrammableRenderer())
    {
        shader.load("shaders/testShader");
    }
    else
    {
        // Not able lo load OpenGL3 shader!!!!
        std::cout << "Not able lo load OpenGL3 shader!!!!" << std::endl;
        shader.load("shaders/testShader");
    }
    
}

void ofApp::setupWebcam()
{
    // Sets up the webcam
    webcam.initGrabber(320,240);
}

//--------------------------------------------------------------
void ofApp::update()
{
    webcam.update();
    updatePs3Cam();
}

//--------------------------------------------------------------
void ofApp::draw()
{

    drawShaders();
    drawImages();
    drawWebcam();
    drawPs3Cam();
}

void ofApp::drawWebcam()
{
    webcam.draw(mouseX, mouseY);
}

void ofApp::drawImages()
{
    testJPGImage.draw(img01x,img01y);
    testPNGImage.draw(img02x, img02y);
    
   
}

void ofApp::drawShaders()
{
    shader.begin();
    ofRect(0,0, ofGetWidth(), ofGetHeight());
    shader.end();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
    

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::setupPs3Cam()
{
    camWidth = 640;
    camHeight = 480;
    
    ps3eye.listDevices();
    
    ps3eye.setDesiredFrameRate(60);
    ps3eye.initGrabber(camWidth,camHeight);
    
    ps3eye.setAutoGainAndShutter(false); // otherwise we can't set gain or shutter
    ps3eye.setGain(1.0);
    ps3eye.setShutter(1.0);
    ps3eye.setGamma(0.4);
    ps3eye.setBrightness(0.6);
    ps3eye.setContrast(1.0);
    ps3eye.setHue(0.5);
    
    ps3eye.setFlicker(1);
    
}


void ofApp::drawPs3Cam()
{
    ps3eye.draw(20,20);
    
    ofDrawBitmapString("Ps3Eye FPS: "+ ofToString(ps3eye.getRealFrameRate()), 20,15);
}


void ofApp::updatePs3Cam()
{
    ps3eye.update();
    
    // Blink the led everytime there is a new frame
//    if(ps3eye.isFrameNew()){
//        ps3eye.setLed(true);
//    }
//    else ps3eye.setLed(false);
}


