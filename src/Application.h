#ifndef _APPLICATION_H_
#define _APPLICATION_H_
 
#include <iostream>
#include <SDL/SDL.h>
#include "Surface.h"
 
class Application
{

private:
    bool running;

    SDL_Surface * display;
    Surface * surface;

public:
    Application();

    int OnExecute();

public:

    bool OnInit();
    void OnEvent(SDL_Event* Event);
    void OnLoop();
    void OnRender();
    void OnCleanup();
};
 
#endif
