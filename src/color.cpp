#include <iostream>
#include "Application.h"

using namespace std;

int main()
{

    SDL_Surface * surface = SDL_CreateRGBSurface(0, 20, 20, 32, 0x000000ff, 0x000000ff, 0x000000ff, 0x000000ff);

    Application application;
    return application.OnExecute();
}
