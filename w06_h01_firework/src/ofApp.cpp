#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    glm::vec2 pos = glm::vec2 (ofGetWidth() * 0.5,ofGetHeight() * 0.8);
    ParticleSystem particleSystem = ParticleSystem(pos);

    particleSystems.push_back(particleSystem);
    
    gravity = glm::vec2(0, .10);
    
}

//--------------------------------------------------------------
void ofApp::update(){

    for (int i = 0; i < particleSystems.size(); i++) {
        particleSystems[i].applyForce(gravity);
        
        particleSystems[i].update();
    }
        
        glm::vec2 target = glm::vec2(ofGetMouseX()*0.01, ofGetMouseY()*0.01);
        for (int i = 0; i < particleSystems.size(); i++){             // alternative syntax for looping through vector
            
            
            // add some noise to the target, unique for each arrow
            
            glm::vec3 noise;
            float frequency     = 0.1 ;   // noise frequency / speed based on arrow's speed
            float amplitude     = 1.;                // noise amplitude / range will be -400 to 400
            
            // signed noise has range -1 to 1
            
            noise.x = ofSignedNoise(ofGetElapsedTimef() * frequency) * amplitude;
            noise.y = ofSignedNoise((ofGetElapsedTimef()+1000) * frequency) * amplitude;
            
            glm::vec2 noisyTarget = target + noise;
            particleSystems[i].applyForce(noisyTarget);
            
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < particleSystems.size(); i++) {
        particleSystems[i].draw();
    }

}

//--------------------------------------------------------------


//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    particleSystems.push_back(ParticleSystem(glm::vec2(x, y)));
}

//--------------------------------------------------------------
