#ifndef _APPLICATION_H_
#define _APPLICATION_H_
 
#include <iostream>
#include <vector>
#include <SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <Box2D.h>
//#include "LvlLoad/LvlLoader.h"
#include "Types/ColorDefinitions.h"
#include "Body.h"
 
class Application
{

private:
    
    
    SDL_Surface * image;

    bool gameHasEnded;

    // Key's that are held down
    bool keysHeld[323];

    // Hold the color state
    enum Colors { Red, Blue };
    Colors currentColor;

    // Width and height of the drawn screen
    int width;
    int height;

    // Prepare for simulation. Typically we use a time step of 1/60 of a
    // second (60Hz) and 10 iterations. This provides a high quality simulation
    // in most game scenarios.
    static const float32 timeStep;
    static const int32 velocityIterations;
    static const int32 positionIterations;

    // While the app is running
    bool running;

    // Our box2D world
    b2World * world;

    // The screen handler
    SDL_Surface * screen;

    // The character body
    Body * character;

    Body * goal;

    // All bodies, so the can be used to draw consecutively
    std::vector<Body *> bodies;
    std::vector<Body *> redBodies;
    std::vector<Body *> blueBodies;

    // Initialize function
    void initScreen();
    void initOpenGL();
    void initBox2D();
    void initBodies();
    
    void OnInit();
    void OnEvent(SDL_Event* Event);
    void OnLoop();
    void OnRender();

public:
    Application(int w, int h);
    ~Application();

    int run();

    void doKeyEvent();
    void toggleColor();
};
 
#endif
