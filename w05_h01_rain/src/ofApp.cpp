#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(30);
    ofBackground(0);
    ofSetCircleResolution(100);
    
    gravity = glm::vec2(0, 0);
   
    
    for(int i = 0; i < numRains; i++){
//        float x = ofRandom(ofGetWidth());
//        float y = ofRandom(ofGetHeight());
         rains[i].setup();
        //rains.push_back(rain);
       
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    gravity.x = 0;
    gravity.y = ofRandom(0.02, 0.3);
    
    
    //glm::vec2 target = glm::vec2(ofGetMouseX(), ofGetMouseY());
    
    for(int i = 0; i < numRains; i++){
        rains[i].update(gravity);
        gravity.x += ofSignedNoise(i/10);
//        glm::vec3 noise;
//        float frequency = 20;
//        float amplitude = 400.;
//
//        noise.x = ofSignedNoise(ofGetElapsedTimef() * frequency) * amplitude;
//        noise.x = ofSignedNoise((ofGetElapsedTimef()+1000) * frequency) * amplitude;
//
//        gravity = gravity + noise;
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    for(int i = 0; i < numRains; i++){
        
        rains[i].draw();
        
    }

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
void ofApp::mousePressed(int x, int y, int button){

//    if(x >= 0 && x <= ofGetWidth()) {
//        if(y >= 0 && y <= ofGetHeight()){
//            Rain Rains;
//            glm::vec2 pos = glm::vec2(x, y);
//            glm::vec2 vel =
//            glm::vec2(ofRandom(-1, 1), ofRandom(-1, 1));
//
//            rains.setup();
////            rains.push_back(rain);
//        }
//    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
