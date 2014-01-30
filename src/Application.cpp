#include "Application.h"

// See header for details
const float32 Application::timeStep = 1.0f / 30.0f;
const int32 Application::velocityIterations = 6;
const int32 Application::positionIterations = 2;

Application::Application(int width, int height)
    : 
        running(true), 
        screen(NULL), 
        width(width), 
        height(height), 
        currentColor(Red),
        gameHasEnded(false)
{
    memset(keysHeld, false, 323);
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
                    //SDL_OPENGL
                     SDL_OPENGL | SDL_SWSURFACE | SDL_DOUBLEBUF
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
    world = new b2World(gravity);
}

/**
 * Create our platforms and character
 */
void Application::initBodies()
{
    Body * body;

    character = new Body(world, 50, 10, 10, 10, 0.3, true);
    character->setColor(255, 0, 0);
    bodies.push_back(character);

    // 1 Red
    body = new Body(world, 50, 30, 100, 10, 0.5, false);
    body->setColor(255, 0, 0);
    bodies.push_back(body);
    redBodies.push_back(body);
    
    // 2 Blue
    body = new Body(world, 150, 200, 500, 10, 0.5, false);
    body->setColor(0, 0, 255);
    body->hide();
    bodies.push_back(body);
    blueBodies.push_back(body);

    // 3 Blue
    body = new Body(world, 200, 110, 1000, 10, 0.5, false);
    body->setColor(0, 0, 255);
    body->hide();
    body->setAngle(2.0);
    bodies.push_back(body);
    blueBodies.push_back(body);
    
    // 4 Red
    body = new Body(world, 180, 100, 1000, 10, 0.5, false);
    body->setColor(255, 0, 0);
    body->setAngle(2.5);
    bodies.push_back(body);
    redBodies.push_back(body);
 
    // 5 Red   
    body = new Body(world, 300, 410, 400, 10, 0.5, false);
    body->setColor(255, 0, 0);
    body->setAngle(2.0);
    bodies.push_back(body);
    redBodies.push_back(body);
    
    // 6 Blue
    body = new Body(world, 470, 450, 200, 10, 0.5, false);
    body->setColor(0, 0, 255);
    body->setAngle(2.0);
    body->hide();
    bodies.push_back(body);
    blueBodies.push_back(body);
 
    // 7 Blue
    body = new Body(world, 442, 100, 280, 10, 0.5, false);
    body->setColor(0, 0, 255);
    body->setAngle(2.0);
    body->hide();
    bodies.push_back(body);
    blueBodies.push_back(body);
    
    // 8 Red
    body = new Body(world, 586, 200, 350, 10, 0.5, false);
    body->setColor(255, 0, 0);
    body->setAngle(2.0);
    bodies.push_back(body);
    redBodies.push_back(body);
 
    // Create the walls
    createWalls();

    goal = new Body(world, 590, 435, 30, 30, 0.5, false);
    //goal = new Body(world, 100, 100, 30, 30, 0.5, false);
    goal->setAngleVelocity(1.5);
    bodies.push_back(goal);
}

void Application::createWalls()
{
    Body * body = NULL;

    body = new Body(world, 641, 0, 1000, 1, 0, false);
    body->setColor(255, 255, 255);
    body->setAngle(1.5707);
    bodies.push_back(body);
    body = new Body(world, 0, 481, 1300, 1, 0, false);
    body->setColor(255, 255, 255);
    bodies.push_back(body);
    body = new Body(world, -1, 0, 1000, 1, 0, false);
    body->setColor(255, 255, 255);
    body->setAngle(1.5707);
    bodies.push_back(body);
}

/**
 * Start our execute loop
 */
int Application::run()
{
    SDL_Delay(100);
    SDL_Event Event;

    while(running) 
    {
        while(SDL_PollEvent(&Event)) 
        {
            OnEvent(&Event);
        }

        OnLoop();
        OnRender();
        doKeyEvent();

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
            keysHeld[event->key.keysym.sym] = false;

            // Change color
            if (event->key.keysym.sym == SDLK_SPACE)
                toggleColor();

            // Reset our system
            if (event->key.keysym.sym == SDLK_r)
                resetGameLevel();

            break;
        case SDL_KEYDOWN:
            keysHeld[event->key.keysym.sym] = true;
            break;                               
        default:
            break;                               
    }  
}

/**
 * Reset the game level
 */
void Application::resetGameLevel()
{
    // Stop the character accelerating from reload
    character->setVelocity(b2Vec2(0.0f, 0.0f));
    character->moveTo(50, 15);
    character->setColor(255, 0, 0);
    goal->setColor(255, 255, 255);

    for (size_t x = 0; x < redBodies.size(); x++)
    {
        redBodies[x]->show();
        redBodies[x]->setColor(255,0,0);
    }
    for (size_t x = 0; x < blueBodies.size(); x++)
    {
        blueBodies[x]->hide();
        blueBodies[x]->setColor(0,0,255);
    }

    currentColor = Red;
    gameHasEnded = false;
}

/**
 * Game logic. 
 *
 * Simple test to expand the surface
 */ 
void Application::OnLoop()
{ 
    world->Step(timeStep, velocityIterations, positionIterations);

    b2Vec2 cp = character->getPosition();
    b2Vec2 gp = goal->getPosition();

    cp.x = cp.x - character->w/2;
    cp.y = cp.y - character->h/2;
    gp.x = gp.x - goal->w/2;
    gp.y = gp.y - goal->h/2;
    //std::cout << cp.x << "," << cp.y << std::endl;

    if(
        cp.y + character->h > gp.y - 2 && 
        cp.y < gp.y + 2 + goal->h && 
        cp.x + character->w > gp.x - 2 &&
        cp.x < gp.x + 2 + goal->w
    )
    {
        gameHasEnded = true;
    }
}

/**
 * Render our App
 */
void Application::OnRender()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    
    // TODO ALLOW RESET
    if (gameHasEnded)
    {
        for (size_t x = 0; x < bodies.size(); x++)
        {
            Color c = bodies[x]->getColor();
            if (c.red > 10) bodies[x]->setColor(c.red-10, c.green, c.blue);
            if (c.green > 10) bodies[x]->setColor(c.red, c.green-10, c.blue);
            if (c.blue > 10) bodies[x]->setColor(c.red, c.green, c.blue-10);
        }
    }
    
    for (size_t x = 0; x < bodies.size(); x++)
        bodies[x]->draw();

    printText();

    SDL_GL_SwapBuffers( );
}

/**
 * All the text to print
 */
void Application::printText()
{

    glColor4ub(255,255,255,255);
    glPushMatrix();

    glRasterPos2i(8,457);
    if (currentColor == Red)
        glutBitmapString(
                GLUT_BITMAP_9_BY_15, 
                (const unsigned char *)"Feeling blue? Try <space>."
            );
    else
        glutBitmapString(
                GLUT_BITMAP_9_BY_15, 
                (const unsigned char *)"Feeling red? Try <space>."
            );

    glRasterPos2i(8,471);
    glutBitmapString(
            GLUT_BITMAP_9_BY_15, 
            (const unsigned char *)"Got lost? Press <R>."
        );
    glPopMatrix();
}

/**
 * Keyboard events
 */
void Application::doKeyEvent() 
{
    Uint8 *keyState = SDL_GetKeyState(NULL);

    if (keyState[SDLK_ESCAPE])
    {
        running = false;
    }    
    if (keyState[SDLK_LEFT])
    {
        b2Vec2 vel = character->getVelocity();
        vel.x -= 0.1;
        character->setVelocity( vel );
    }
    else if (keyState[SDLK_RIGHT])
    {
        b2Vec2 vel = character->getVelocity();
        vel.x += 0.1;
        character->setVelocity( vel );
    }
    else
    {
        b2Vec2 vel = character->getVelocity();

        if (vel.x > 0) vel.x -= 0.1;
        else vel.x += 0.1;
        character->setVelocity( vel );
    }
}

/**
 * Change the color
 */
void Application::toggleColor()
{
    if (currentColor == Red)
    {
        character->setColor(0, 0, 255);

        for (size_t x = 0; x < redBodies.size(); ++x)
            redBodies[x]->hide();
        for (size_t x = 0; x < blueBodies.size(); ++x)
            blueBodies[x]->show();

        currentColor = Blue;
    }
    else
    {
        character->setColor(255, 0, 0);

        for (size_t x = 0; x < redBodies.size(); ++x)
            redBodies[x]->show();
        for (size_t x = 0; x < blueBodies.size(); ++x)
            blueBodies[x]->hide();
        
        currentColor = Red;
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
