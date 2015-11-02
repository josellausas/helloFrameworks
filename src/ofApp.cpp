#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    
    setupImages();
    setupShaders();
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
    
    // Starts with no selected image;
    pSelectedImage = NULL;
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

//--------------------------------------------------------------
void ofApp::update()
{

}

//--------------------------------------------------------------
void ofApp::draw()
{

    drawShaders();
    drawImages();
}

void ofApp::drawImages()
{
    testJPGImage.draw(img01x,img01y);
    testPNGImage.draw(img02x, img02y);
    
    if(pSelectedImage != NULL)
    {
        pSelectedImage->draw(mouseX, mouseY);
    }
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

    pSelectedImage = &testPNGImage;
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
