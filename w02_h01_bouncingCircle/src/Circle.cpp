#include"Circle.h"

void Circle::setup(float posX, float posY, float diameter){
    x = posX;
    y = posY;
    d = diameter;
    
    dirX = 0;
    dirY = 0;
    
    
}

void Circle::update(){
    x += dirX;
    y += dirY;
    d = (x+y)/10;
    
    if(x > ofGetWidth()){
        
        x = ofGetWidth();
        dirX = dirX * -1.5;
        
    }
    else if (x < 0){
        x = 0;
        dirX = dirX * -0.7;
        
    }
    
    if(y > ofGetHeight()){
        y = ofGetHeight();
        dirY = dirY * -1.5;
    }else if (y < 0) {
        y = 0;
        dirY = dirY * -0.7;
    }
    r = ofMap(x, 0, ofGetWidth(), 0, 255);
    g = ofMap(y, 0, ofGetHeight(), 0, 255);
    b = 0;
}

void Circle::draw(){
    ofDrawCircle(x, y, d);
    
    ofSetColor(r, g, b);
}


