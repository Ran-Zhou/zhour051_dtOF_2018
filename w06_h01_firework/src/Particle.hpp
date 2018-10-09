//
//  Particle.hpp
//  particle
//
//  Created by 周然 on 10/8/18.
//

#pragma once
#include "ofMain.h"

class Particle {
    
public:
    
    Particle();
    Particle(glm::vec2 _pos, glm::vec2 _vel, float _mass);
    void applyForce(glm::vec2 force);
    void update();
    void draw();
    
    glm::vec2 pos, vel, acc;
    float mass;
};
