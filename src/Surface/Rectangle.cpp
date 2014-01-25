#include "Surface/Rectangle.h"

SurfaceRectangle::SurfaceRectangle(
	SDL_Surface * screen, 
	int x, 
	int y, 
	int w, 
	int h
    )
    : Surface(screen)
{

    SDL_Rect rect = { x, y, w, h };
    Surface::setRectangle(&rect);
}

void SurfaceRectangle::draw()
{
    Uint32 blue = SDL_MapRGB(screen->format, 100, 100, 200);
    SDL_FillRect(screen, &this->rect, blue);
}

SurfaceRectangle::~SurfaceRectangle()
{

}
