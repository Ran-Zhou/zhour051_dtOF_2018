//
//  Coin.hpp
//  midterm
//
//  Created by 周然 on 10/22/18.
//

#pragma once
#include "ofMain.h"

class Coin {
public:
    
    void setup();
    void fall();
    void update(glm::vec2 force);
    void draw();
    void caught();
    glm::vec2 pos;
    glm::vec2 vel;
    
    float radius;
    bool isFall;
    float timeStartedFalling;
    
};


