#include "Application.h"
    
Application::Application()
    : running(true), display(NULL)
{
}

int Application::OnExecute()
{
    if(OnInit() == false) 
        return -1;

    SDL_Event Event;

    while(running) 
    {
        while(SDL_PollEvent(&Event)) 
        {
            OnEvent(&Event);
        }

        OnLoop();
        OnRender();

	SDL_Delay(100);
    }

    OnCleanup();
    return 0;
}

bool Application::OnInit()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) 
        return false;
 
    display = SDL_SetVideoMode(
		    640,
		    480, 
		    32, 
		    SDL_HWSURFACE | SDL_DOUBLEBUF
	    );

    if(display == NULL)
        return false;

    surface = new Surface(display);
 
    return true;
}

void Application::OnEvent(SDL_Event * event) 
{
    if(event->type == SDL_QUIT)
        running = false;
}

void Application::OnLoop(){}

void Application::OnRender()
{
    surface->draw(20, 30);

    SDL_Flip(display);
}

void Application::OnCleanup()
{
    SDL_Quit();
}
