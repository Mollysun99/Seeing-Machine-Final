#include "ofApp.h"
 
//--------------------------------------------------------------
void ofApp::setup() {
 
//    ofSetFrameRate(60);
    ofSetWindowTitle("SM Final RuoxiaoSun");
//    ofBackground(255);
    
    grabber.setup(1280,720);
    
    mask.load("mask.png");
    eye.load("eye.png");
    nose.load("nose.png");
    mouth.load("mouth.png");
    eye_left.load("eye1.png");
    eye_right.load("eye2.png");
    ear.load("ear.png");
    ear1.load("ear2.png");
    
    mouth_side.load("mouth2.png");
    eye_left_side.load("eye3.png");
    nose_side.load("nose2.png");
   

    ofSetVerticalSync(true);
    ofEnableAlphaBlending();

    ofSetDataPathRoot(ofFile(__BASE_FILE__).getEnclosingDirectory()+"../../model/");

    tracker.setup();
}
 
//--------------------------------------------------------------
void ofApp::update() {
    
    grabber.update();


    if(grabber.isFrameNew()){
        tracker.update(grabber);
    
    }
 
 
}
 
//--------------------------------------------------------------
void ofApp::draw() {
    
    grabber.draw(0,0);

    tracker.drawDebug();

    ofPushStyle();

    for(auto face : tracker.getInstances()){
        ofPushView();
        face.loadPoseMatrix();
        
//        ofPushMatrix();
//        ofRotate(-180, 0, 0, 0);
//        mask.draw(-100, -110, 200, 250);
//        ofPopMatrix();
        
//        ofPushMatrix();
//        eye.draw(-70, -10, 50, 15);
//        ofPopMatrix();
        
        //side eye right
        ofPushMatrix();
        ofRotate(-180, -180, 1, 0);
        eye_left_side.draw(20, -20, 50, 30);
        ofPopMatrix();
        
        //side eye left
        ofPushMatrix();
        ofRotate(-180, 180, 1, 0);
        eye_left_side.draw(-60, -20, 50, 30);
        ofPopMatrix();
        
        //ear_left
        ofPushMatrix();
        ofRotate(180, 180, 1, 0);
        ear.draw(90, 0, 40, 60);
        ofPopMatrix();
        
        //ear_right
        ofPushMatrix();
        ofRotate(180, 180, 1, 0);
        ear1.draw(-100, 0, 40, 60);
        ofPopMatrix();
        
        //eye_right
        ofPushMatrix();
        ofRotate(90, 0, -180, 0);
        eye_left.draw(70, 0, 50, 30);
        ofPopMatrix();
        
        //eye_right
        ofPushMatrix();
        ofRotate(90, 0, -180, 0);
        eye_left.draw(-70, 0, 50, 30);
        ofPopMatrix();
        
        
        //side nose
        ofPushMatrix();
        ofRotate(-180, 90, 1, 0);
        nose_side.draw(-30, 0, 50, 50);
        ofPopMatrix();
        
        //nose
        ofPushMatrix();
        ofRotate(180, 0, 0, 0);
        nose.draw(0, 0, 80, 50);
        ofPopMatrix();
        
        //side mouth
        ofPushMatrix();
        ofRotate(-180, 50, 1, 0);
        mouth_side.draw(-50, 60, 80, 50);
        ofPopMatrix();
        
        //mouth
        ofPushMatrix();
        ofRotate(90, 0, 1, 0);
        mouth.draw(-50, -120, 80, 50);
        ofPopMatrix();
        
        ofPushMatrix();
        ofSetColor(0,0,255,50);
        ofRotate(90, 0, 45, 0);
        ofDrawRectangle(0, 0, 200, 200);
        ofPopMatrix();
        
        ofPopView();
    }
    ofPopStyle();

    ofDrawBitmapStringHighlight("Framerate : "+ofToString(ofGetFrameRate()), 10, 20);
    ofDrawBitmapStringHighlight("Tracker fps: "+ofToString(tracker.getThreadFps()), 10, 20);
}
