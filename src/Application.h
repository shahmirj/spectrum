#ifndef APPLICATION_H_
#define APPLICATION_H_
 
#include <iostream>
#include <SDL.h>
#include "Surface/Rectangle.h"
#include "Color.h"

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
    
    void OnKeyEvent(SDL_KeyboardEvent * const key);
};
 
#endif
