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

void SurfaceRectangle::doActualDraw()
{
    SDL_FillRect(screen, &this->rect, this->color);
}

SurfaceRectangle::~SurfaceRectangle()
{

}
