#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
//	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context
//	ofRunApp(new ofApp());
    
    ofGLWindowSettings settings;
        settings.setGLVersion(3, 2);
        settings.setSize(1280, 720);
        ofCreateWindow(settings);
        ofRunApp(new ofApp());

}
