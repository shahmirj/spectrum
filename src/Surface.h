#ifndef SURFACE_H_
#define SURFACE_H_

#include <SDL.h>
#include "Exception.h"
#include "Color.h"
#include <iostream>

/**
 * Simple class to hold our surface values
 */
class Surface
{

private:
    SDL_Surface * surface;

    virtual void doActualDraw(Uint32 color) = 0;

    Color color;

    bool hidden;

protected:
    SDL_Surface * screen;
    SDL_Rect rect;

    void setScreen(SDL_Surface * screen);
    void setRectangle(const SDL_Rect * const rect);

public:
    Surface(SDL_Surface * screen);
    virtual ~Surface();

    void setColor(short int r, short int g, short int b);

    void hide();
    void show();
    
    virtual void draw();
};

#endif
