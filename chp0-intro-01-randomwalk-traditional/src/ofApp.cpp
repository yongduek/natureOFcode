#include "ofApp.h"

float frameRate = 30.; // default framerate
bool  frameRateChanged = false;
//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(255);
    ofSetBackgroundAuto(false);
    
    w = walker();
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (frameRateChanged) {
        ofSetFrameRate(frameRate);
        frameRateChanged = false;
    }
    
    w.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofScale(w.scale, w.scale);
    w.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){ }
//--------------------------------------------------------------
void ofApp::keyReleased(int key){ }
//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    frameRate = ofMap(x, 0, ofGetWidth(), 5, 120, true/*truncation*/);
    frameRateChanged = true;
    
    w.scale = ofMap(y, 0, ofGetHeight(), 1, 20, true/*truncation*/);
}
//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){ }
//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){ }
//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){ }
//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){ }
//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){ }
//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ }
