//
//  Particle.cpp
//  particle
//
//  Created by 周然 on 10/8/18.
//

#include "Particle.hpp"

Particle::Particle()
{
    pos = glm::vec2(0,0);
    vel = glm::vec2(0,0);
    acc = glm::vec2(0,0);
    
}

Particle::Particle(glm::vec2 _pos, glm::vec2 _vel, float _mass)
{
    pos = _pos;
    vel = _vel;
    mass = _mass;
    
}

void Particle::applyForce(glm::vec2 force)
{
    acc += force / mass;
    
}

void Particle::update()
{
    vel += acc;
    pos += vel;
    acc *= 0;
}

void Particle::draw()
{
    ofPushStyle();
    float hue = ofMap(mass, 0.01, 3, 0, 255);
    ofSetColor(ofColor::fromHsb(hue, 100, 255,180));
    ofDrawCircle(pos, mass * 2.0);
    ofPopStyle();
    
}
