#ifndef _APPLICATION_H_
#define _APPLICATION_H_
 
#include <iostream>
#include <SDL.h>
#include <Surface\Rectangle.h>
#include <LvlLoad\LvlLoader.h>
 
class Application
{

private:
    bool running;

    SDL_Surface * screen;
    vector<SurfaceRectangle> surfaces;

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
