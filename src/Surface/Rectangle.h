#ifndef SURFACE_RECTANGLE_H_
#define SURFACE_RECTANGLE_H_

#include "Surface.h"

/**
 * Simple class to hold our surface values
 */
class SurfaceRectangle : public Surface
{

private:
public:
    SurfaceRectangle(SDL_Surface * screen, int x, int y, int w, int h);
    virtual ~SurfaceRectangle();

    void draw();
};

#endif
