//
//  Coin.cpp
//  midterm
//
//  Created by 周然 on 10/22/18.
//

#include "Coin.hpp"
void Coin::setup(){
    isFall = false;
    //    r = 16;
    
    //    pos.x = ofRandom(ofGetWidth());
    //    pos.y = ofRandom(ofGetHeight());
    //    vel.x = ofRandom(-1, 1);
    //    vel.y = ofRandom(-1, 1);
    
}
void Coin::fall() {
    isFall = true;
    timeStartedFalling = ofGetElapsedTimef();
    
    pos.x = ofRandom(0, ofGetWidth());
    pos.y = ofRandom(-ofGetWidth(), 0);
    vel.x = ofRandom(-1, 1);
    //    vel.y = ofRandom(-1, 1);
    vel.y = ofRandom(-1, 1);
    //        int i =0;
    //        int numCoins;
    //        if(i < numCoins){
    //            pos.x = ofRandom(0, ofGetWidth());
    //            pos.y = 0;
    //
    //            i ++;
    //        }
    
}

void Coin::update(glm::vec2 force){
    
    //    int i =0;
    //    int numCoins;
    //    if(i < numCoins){
    //        pos.x = ofRandom(0, ofGetWidth());
    //        pos.y = 0;
    //        vel += force;
    //        pos += vel;
    //        i ++;
    //    }
    //    vel += force;
    //    pos += vel;
    //    int i =0;
    //    int numCoins;
    //
    //    vel += force;
    //    pos += vel;
    vel += force;
    pos += vel;
    if(isFall){
        //        vel += force;
        //        pos += vel;
        float time = ofGetElapsedTimef();
        if (time - timeStartedFalling > 10){
            isFall = false;
        }
        
        //        if(i < numCoins){
        //            pos.x = ofRandom(0, ofGetWidth());
        //            pos.y = 0;
        //            vel += force;
        //            pos += vel;
        //            i ++;
        //        }
        if (pos.y > ofGetHeight()){
            pos.y = ofRandom(-ofGetHeight(),0);
            vel.y = ofRandom(-1,1);
            pos.x = ofRandom(ofGetWidth());
        }
    }
}



void Coin::draw() {
    ofSetColor(255,210,0);
    ofDrawCircle(pos.x, pos.y, 16);
    
    ofSetColor(0);
    ofDrawRectangle(pos.x-7, pos.y-7, 14, 14);
    
    
}
void Coin::caught(){
    
    pos.y = -ofRandom(ofGetWidth());
    pos.x = ofRandom(ofGetWidth());
    
}

