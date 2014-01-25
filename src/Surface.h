#ifndef SURFACE_H_
#define SURFACE_H_

#include <SDL.h>
#include "Exception.h"

/**
 * Simple class to hold our surface values
 */
class Surface
{

private:
    SDL_Surface * surface;

    virtual void doActualDraw() = 0;

    bool hidden;

protected:
    SDL_Surface * screen;
    SDL_Rect rect;
    Uint32 color;

    void setScreen(SDL_Surface * screen);
    void setRectangle(const SDL_Rect * const rect);

public:
    Surface(SDL_Surface * screen);
    virtual ~Surface();

    void setColor(short int r, short int g, short int b);

    void hide();
    void show();
    
    void deltaMoveX(int x);
    void deltaMoveY(int y);
    void deltaStretchWidth(int w);
    void deltaStretchHeight(int h);

    virtual void draw();
};

#endif
