#ifndef SURFACE_H_
#define SURFACE_H_

#include <SDL/SDL.h>
#include "Exception.h"

/**
 * Simple class to hold our surface values
 */
class Surface
{

private:
    SDL_Surface * surface;

protected:
    SDL_Surface * screen;
    SDL_Rect rect;

    void setScreen(SDL_Surface * screen);
    void setRectangle(const SDL_Rect * const rect);

public:
    Surface(SDL_Surface * screen);
    virtual ~Surface();

    void deltaMoveX(int x);
    void deltaMoveY(int y);
    void deltaStretchWidth(int w);
    void deltaStretchHeight(int h);

    virtual void draw() = 0;
};

#endif
