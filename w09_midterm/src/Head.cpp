//
//  Head.cpp
//  space_trigger_example
//
//  Created by Tyler Henry on 10/21/18.
//

#include "Head.hpp"

void Head::setup(){
    ofSetCircleResolution(100);
    isShaking = false;
    pos.y = 650;
    pos.x = ofGetWidth() * 0.5;
    
}


void Head::shake(){
    
    isShaking = true;
    timeStartedShaking = ofGetElapsedTimef();
    vel.y = 0;
    vel.x = 20.0;
    
}

void Head::update(){
    
    pos += vel;
    
    if (isShaking){
        float time = ofGetElapsedTimef();
        if (time - timeStartedShaking > 4){
            isShaking = false;
            vel *= 0;
        }
        
        if (pos.x > ofGetWidth()){
            pos.x = ofGetWidth();
            vel.x *= -1;
        }
        else if (pos.x < 0){
            pos.x = 0;
            vel.x *= -1;
        }
    }
    
}

void Head::draw(){
    
    ofPushStyle();
    
    ofSetColor(30,144,255);
    ofDrawEllipse(pos, 120, 115);
    
    ofSetColor(255);
    ofDrawEllipse(pos + glm::vec2(0,10),100, 90);
    
    //    ofSetColor(0);
    //    ofNoFill();
    //    ofSetLineWidth(2);
    //    ofDrawEllipse(pos + glm::vec2(0,10),100, 90);
    ofPopStyle();
    
    ofPushStyle;
    ofSetColor(0);
    ofDrawRectangle(pos + glm::vec2(-40,47),80, 30);
    
    
    ofPopStyle();
    ofPushStyle;
    ofSetColor(238,0,0);
    ofDrawRectangle(pos + glm::vec2(-37.5,47),75, 10);
    ofPopStyle();
    
    ofPushStyle();
    ofSetColor(255);
    ofDrawEllipse(pos + glm::vec2(-15,-30),29, 37);
    ofPushStyle();
    ofSetColor(255);
    ofDrawEllipse(pos + glm::vec2(15,-30),29, 37);
    
    ofSetColor(0);
    ofNoFill();
    ofSetLineWidth(2);
    ofDrawEllipse(pos + glm::vec2(15,-30),29, 37);
    ofDrawEllipse(pos + glm::vec2(-15,-30),29, 37);
    ofDrawEllipse(pos + glm::vec2(0, 32), 12,14);
    ofPopStyle();
    
    ofPushStyle();
    ofSetColor(0);
    ofDrawEllipse(pos + glm::vec2(-9,-26),11, 16);
    ofPushStyle();
    ofSetColor(0);
    ofDrawEllipse(pos + glm::vec2(9,-26),11, 16);
    
    ofSetColor(255);
    ofDrawEllipse(pos + glm::vec2(6.5, -26),4,4);
    ofDrawEllipse(pos + glm::vec2(-6.5, -26),4,4);
    ofPopStyle();
    
    ofPushStyle();
    ofSetColor(238,0,0);
    ofDrawEllipse(pos + glm::vec2(0, -12),17,17);
    ofSetColor(255);
    ofDrawEllipse(pos + glm::vec2(-2, -15),5,5);
    ofPopStyle();
    
    ofPushStyle();
    ofSetColor(0);
    ofSetLineWidth(2);
    ofDrawLine(pos + glm::vec2(0, -4),pos + glm::vec2(0, 26));
    ofDrawLine(pos + glm::vec2(-42, -10),pos + glm::vec2(-10, -2));
    ofDrawLine(pos + glm::vec2(-44, 5),pos + glm::vec2(-12, 5));
    ofDrawLine(pos + glm::vec2(-40, 20),pos + glm::vec2(-10, 10));
    
    ofDrawLine(pos + glm::vec2(42, -10),pos + glm::vec2(10, -2));
    ofDrawLine(pos + glm::vec2(44, 5),pos + glm::vec2(12, 5));
    ofDrawLine(pos + glm::vec2(40, 20),pos + glm::vec2(10, 10));
    //    ofDrawEllipse(pos + glm::vec2(0, 25), 15,15);
    ofPopStyle();
    //
    //    ofPath path;
    //    ofSetColor(255,0,0);
    //   // path.moveTo(300 + 200, 300);
    //    path.moveTo(pos.x + 30, pos.y+5);
    //    path.arc(pos + glm::vec2(0, 5), 30, 30, 0, 180);
    //    //path.arc(300, 300, 200, 200, 0, 180);
    //    path.setFilled(false);
    //    path.setStrokeWidth(1);
    //    path.draw();
}


