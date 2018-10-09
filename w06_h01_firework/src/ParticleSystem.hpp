//
//  ParticleSystem.hpp
//  particle
//
//  Created by 周然 on 10/8/18.
//

#pragma once
#include "ofMain.h"
#include "Particle.hpp"

class ParticleSystem {
public:
    ParticleSystem();
    ParticleSystem(glm::vec2 _pos);
    void applyForce(glm::vec2 force);
    
    void update(int numNewParticles = 10, int maxParticles = 1000);
    
    void draw();
    
    glm::vec2 pos;
    vector<Particle> particles;
};
