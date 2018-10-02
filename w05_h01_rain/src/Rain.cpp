//
//  Rain.cpp
//  rainning
//
//  Created by 周然 on 10/2/18.
//

#include "Rain.hpp"
void Rain::setup(){
//    x = posX;
//    y = posY;
//
    pos.x = ofRandom(ofGetWidth());
    pos.y = ofRandom(ofGetHeight());
    vel.x = ofRandom(-1, 1);
    vel.y = ofRandom(-1, 1);
    
}

void Rain::update(glm::vec2 force){
    
    vel += force;
    pos += vel;
    
}

void Rain::draw() {
    
    ofSetColor(137, 207, 220, 150);
    
    for(int i = 2; i < 8; i++){
        ofDrawCircle(pos.x, pos.y + i*2, i, i);
    }
}
