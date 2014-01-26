#include "Application.h"

// See header for details
const float32 Application::timeStep = 1.0f / 30.0f;
const int32 Application::velocityIterations = 6;
const int32 Application::positionIterations = 2;

Application::Application(int width, int height)
    : running(true), screen(NULL), width(width), height(height)
{
    this->initScreen();
    this->initOpenGL();
    this->initBox2D();
    this->initBodies();
}

/**
 * Initialize screen
 */
void Application::initScreen()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) 
        throw Exception("SDL_Init failed");
 
    SDL_WM_SetCaption("Spectrum", NULL);

    const SDL_VideoInfo * info = SDL_GetVideoInfo();

    SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 5 );
    SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 5 );
    SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 5 );
    SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 16 );
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

    screen = SDL_SetVideoMode(
		    this->width,
		    this->height, 
		    info->vfmt->BitsPerPixel, 
                    SDL_OPENGL
	    );
    if(screen == NULL)
        throw Exception("screen was null");
}

/**
 * Initialize openGL
 */
void Application::initOpenGL()
{
    // Enable alpha
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glMatrixMode(GL_PROJECTION);
    glOrtho(0, width, height, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(0,0,0,1);
}

/**
 * Initialize Box2D
 */ 
void Application::initBox2D()
{
    b2Vec2 gravity(0.0f, 3.8f);
    world = new b2World(gravity, false);
}

/**
 * Create our platforms and character
 */
void Application::initBodies()
{
    Body * body;

    character = new Body(world, 50, 10, 10, 10, 0.1, true);
    bodies.push_back(character);

    body = new Body(world, 50, 30, 100, 20, 1.0, false);
    body->setColor(255, 0, 0);
    bodies.push_back(body);

    body = new Body(world, 150, 200, 100, 20, 1.0, false);
    body->setColor(255, 0, 0);
    bodies.push_back(body);

}

/**
 * Start our execute loop
 */
int Application::run()
{
    SDL_Event Event;

    while(running) 
    {
        while(SDL_PollEvent(&Event)) 
        {
            OnEvent(&Event);
        }

        OnLoop();
        OnRender();

	SDL_Delay(15);
    }

    return 0;
}

/**
 * Check for events
 */
void Application::OnEvent(SDL_Event * event) 
{
	switch (event->type)                         
    {                                            
        case SDL_QUIT:                           
            running = false;                     
            break;                               
        case SDL_KEYUP:                          
            OnKeyEvent(&event->key);             
            break;                               
        default:                                 
            break;                               
    }  
}

/**
 * Game logic. 
 *
 * Simple test to expand the surface
 */ 
void Application::OnLoop()
{ 
    world->Step(timeStep, velocityIterations, positionIterations);
}

/**
 * Render our App
 */
void Application::OnRender()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    for (size_t x = 0; x < bodies.size(); x++)
        bodies[x]->draw();

    SDL_GL_SwapBuffers( );
}

/**
 * Keyboard events
 */
void Application::OnKeyEvent(SDL_KeyboardEvent * const key) 
{                            
    
    static int x = 0;
        
    if (key->type == SDL_KEYUP)                             
    {       
        /*        
        if (key->keysym.sym == SDLK_1)                      
        {                                                   
            surfaces[0].hide();                               
            surfaces[1].show();                               
        }                                                   
        else if(key->keysym.sym == SDLK_2)                  
        {
            surfaces[0].show();
            surfaces[1].hide();
        }
        */
        //surfaces[0].move(x++);
        //
        b2Vec2 vel = character->getVelocity();
        vel.x += 0.5;
        character->setVelocity( vel );
    }
    else if (key->type == SDL_KEYDOWN)
    {
    }
}

/**
 * Clean up our variables
 */
Application::~Application()
{
    // Remove bodies
    for (size_t x = 0; x < bodies.size(); x++)
        delete bodies[x];

    delete world;
    SDL_FreeSurface(screen);
    SDL_Quit();
}
