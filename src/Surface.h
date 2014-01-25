#ifndef SURFACE_H_
#define SURFACE_H_

#include <SDL/SDL.h>
#include "Exception.h"

#include <iostream>

/**
 * Simple class to hold our surface values
 */
class Surface
{

private:
    SDL_Surface * surface;
    SDL_Surface * display;

protected:
   void setDisplay(SDL_Surface * display);

public:
    Surface(SDL_Surface * display);
    ~Surface();

    void draw(int x, int y);
};

#endif
