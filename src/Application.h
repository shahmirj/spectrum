#ifndef _APPLICATION_H_
#define _APPLICATION_H_
 
#include <iostream>
#include <vector>
#include <SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <Box2D.h>
//#include "LvlLoad/LvlLoader.h"
#include "Types/ColorDefinitions.h"
#include "Body.h"
 
class Application
{

private:
    
    // Width and height of the drawn screen
    int width;
    int height;

    // Prepare for simulation. Typically we use a time step of 1/60 of a
    // second (60Hz) and 10 iterations. This provides a high quality simulation
    // in most game scenarios.
    static const float32 timeStep;
    static const int32 velocityIterations;
    static const int32 positionIterations;

    bool running;

    SDL_Surface * screen;

    Body * character;
    std::vector<Body *> bodies;

    b2World * world;

    void initScreen();
    void initOpenGL();
    void initBox2D();
    void initBodies();

public:
    Application(int w, int h);
    ~Application();

    int run();
    void OnInit();
    void OnEvent(SDL_Event* Event);
    void OnLoop();
    void OnRender();
	void OnKeyEvent(SDL_KeyboardEvent * const key);
};
 
#endif
