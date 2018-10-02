//
//  Rain.hpp
//  rainning
//
//  Created by 周然 on 10/2/18.
//

#pragma once
#include "ofMain.h"

class Rain {
public:
    
    void setup();
    void update(glm::vec2 force);
    void draw();
    
    glm::vec2 pos;
    glm::vec2 vel;
    
    float radius;
//    float x;
//    float y;
};
