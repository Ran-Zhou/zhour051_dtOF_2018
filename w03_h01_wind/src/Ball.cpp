#include "Ball.h"

// setup
void Ball::setup(float size, float bounceFactor) {

	// initialize the object's variables

	// center on screen
	pos.x = ofRandom(ofGetWidth());
	pos.y = ofRandom(ofGetHeight());

	// no velocity to start
    vel = glm::vec2(ofRandom(3,4),ofRandom(2,4));
    
    // size
    radius = size;
    
    // bounce factor
    bounce = bounceFactor;
    
    // bounce = 0.0 would mean no bounce at all
    // bounce = 1.0 is perfect bounce, no loss of momentum
    
    
}

// update
void Ball::update() {
    
    pos += vel * bounce;
 

	// check left
	if (pos.x <= radius) {
        
		pos.x = radius;		    // set the position back to the edge of window
        
        vel.x *= -bounce;		// bounce is a float from 0.0 to 1.0
                                // if bounce < 1.0, it will slow momentum
                                // (-1 * bounce) flips direction
	}
	// check right
	else if (pos.x >= ofGetWidth() - radius) {
		pos.x = ofGetWidth() - radius;			// similar to above
		vel.x *= -bounce;
	}

	// check top and bottom
	if (pos.y <= radius) {
		pos.y = radius;
		vel.y *= -bounce;
	}
	else if (pos.y >= ofGetHeight() - radius) {
		pos.y = ofGetHeight() - radius;
		vel.y *= -bounce;
	}
    
    if (ofGetMousePressed()==1){
    glm::vec2 destination;                  // mouse is destination point
    destination.x   = ofGetMouseX();
    destination.y   = ofGetMouseY();
    
    float percent   = .007;
    
    glm::vec2 diff = destination - pos;
    pos -=diff  * percent;
    
    

        float dist = glm::distance(destination,pos);}
    
}


// draw the ball
void Ball::draw() {

    // set the color based on bounciness -
    // we'll interpolate between 2 colors:
    
    ofColor color1 = ofColor(50,0,255);     // purple-ish
    ofColor color2 = ofColor(255,100,220);  // pink-ish
    float percent  = bounce;        // 0 - 1
    
    ofColor color = color1.getLerped(color2, percent);
    
    ofSetColor(color);
    
	ofDrawCircle(pos, radius);		// draw
    ofSetColor(255);                // restore global white draw color
}
