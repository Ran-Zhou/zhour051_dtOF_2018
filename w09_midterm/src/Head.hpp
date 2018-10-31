//
//  Head.hpp
//  midterm
//
//  Created by 周然 on 10/22/18.
//

#pragma once
#include "ofMain.h"

class Head {
public:
    void setup();
    void shake();
    
    void update();
    void draw();
    
    glm::vec2 pos, vel;
    ofImage image;
    
    bool isShaking;
    float timeStartedShaking;
};

