#pragma once

#include "ofMain.h"
#include "Head.hpp"
#include "Coin.hpp"

const int numCoins = 30;

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    char readCharFromSerial();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofSerial serial;
    
    Head head;
    Coin coins[numCoins];
    //    Coin coins;
    glm::vec2 gravity;
    bool isIntersect;
    int n = 0;
};

