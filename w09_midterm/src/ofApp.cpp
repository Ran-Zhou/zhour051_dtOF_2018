#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    serial.listDevices();
    serial.setup(0, 9600);
    
    ofSetFrameRate(40);
    
    ofBackground(0);
    gravity = glm::vec2(0, 0);
    
    //  int numCoins = 50;
    ////
    ////    int i = 0;
    ////    if(i < numCoins){
    ////    coins.setup();
    ////    i ++;
    ////    }
    //    coins.setup();
    for(int i = 0; i < numCoins; i++){
        coins[i].setup();
    }
    head.setup();
    isIntersect = false;
    //
    
}

//--------------------------------------------------------------
void ofApp::update(){
    //    int n = 0;
    
    char msg = readCharFromSerial();
    if (msg){
        // valid byte (arduino sent something)
        
        if (msg == 'A') {
            ofLog() << "got message A!";
            cout << "arduino sent A" << endl;
             head.shake();
        } else if (msg == 'B') {
            ofLog() << "got message B!";
            for(int i = 0; i < numCoins; i++){
                coins[i].fall();
               
            }
        } else {
            ofLogWarning() << "got unknown message: " << msg;
        }
    }
    
    gravity.x = 0;
    gravity.y = ofRandom(0.06, 0.2);
    for(int i = 0; i < numCoins; i++){
        coins[i].update(gravity);
        
        if (ofDist(head.pos.x,head.pos.y, coins[i].pos.x, coins[i].pos.y) < 60){
            isIntersect = true;
            n = n + 1;
            ofLog() << "true " << 10;
            coins[i].caught();
            n = n + 1;
        }
    }
    //    string caughtCoin = ofToString(n) + " Coins";
    //    ofDrawBitmapString(caughtCoin, 5, 5);
    //    ofSetColor(255);
    //    if(isIntersect){
    //        for(int i = 0; i < numCoins; i++){
    //        coins[i].caught();
    //    }
    //    }
    //    coins.update(gravity);
    head.update();
    //    if (ofDist(head.pos, coins[i].pos) < 116){
    //        isIntersect = true;
    //    }
    
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    head.draw();
    for(int i = 0; i < numCoins; i++){
        coins[i].draw();
    }
    
    //    coins.draw();
    ofSetColor(255,210,0);
    string caughtCoin = ofToString(n*0.5) + " Coins";
    ofDrawBitmapString(caughtCoin, 50, 50);
    
    //ofSetColor(255);
    
}

//--------------------------------------------------------------
char ofApp::readCharFromSerial(){
    
    // reads a single byte (as a "char" - an ASCII character)
    // from the serial connection and returns it
    // if no serial data available, returns empty char = '\0'
    
    char c      = '\0';  // what we'll return
    
    // check if serial is ready
    if (!serial.isInitialized()) {
        ofLogError() << "can't read from serial yet, use serial.setup(deviceIndex, baud) first...";
        return c;   // serial
    }
    
    // try read a byte (char) from serial
    char read   = serial.readByte();
    if ( read == OF_SERIAL_ERROR ) {
        ofLogError() << "serial read error!";
    }
    else if (read != OF_SERIAL_NO_DATA) {
        c = read;
        ofLog() << "serial read: " << c;
    }
    return c;
}
void ofApp::keyPressed(int key){
    //if(head.isShaking == false){
        if(key == OF_KEY_LEFT){
            head.pos.x = head.pos.x - 80;
        } else if (key == OF_KEY_RIGHT){
            head.pos.x = head.pos.x + 80;
        }
   // }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    if(key == ' '){
        head.shake();
    }
    else if (key == 'c'){
        for(int i = 0; i < numCoins; i++){
            coins[i].fall();
            //         coins.fall();
        }
    }
    
    //    if(head.isShaking == false){
    //        if(key == OF_KEY_LEFT){
    //            head.pos.x--;
    //        } else if (key == OF_KEY_RIGHT){
    //            head.pos.x ++;
    //        }
    //    }
    
}


//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
    //    if(head.isShaking == false){
    ////        head.pos = glm::vec2(x, y);
    //        head.pos.x = x;
    // }
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
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

