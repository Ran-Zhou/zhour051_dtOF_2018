#pragma once
#include "ofMain.h"

class Circle {
public:
    void setup(float posX, float posY, float diameter);
    void update();
    void draw();
    
    float x, y, d;
    float dirX, dirY;
    float r, g, b;
};

