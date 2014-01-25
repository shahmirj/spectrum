#ifndef _APPLICATION_H_
#define _APPLICATION_H_
 
#include <iostream>
#include <SDL.h>
#include "Surface/Rectangle.h"
 
class Application
{

private:
    bool running;

    SDL_Surface * screen;
    Surface * surface1;
    Surface * surface2;

    int x;

public:
    Application();
    ~Application();

    int run();
    bool OnInit();
    void OnEvent(SDL_Event* Event);
    void OnLoop();
    void OnRender();
};
 
#endif
