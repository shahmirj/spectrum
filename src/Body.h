#ifndef BODY_H_
#define BODY_H_

#define GL_DO_NOT_WARN_IF_MULTI_GL_VERSION_HEADERS_INCLUDED

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <Box2D.h>
#include "Exception.h"
#include "Color.h"

/**
 * Simple class to hold our surface values
 */
class Body
{

private:

    b2Body * body;
    b2PolygonShape shape;
 //   b2FixtureDef definition;

    //void doActualDraw();

    Color color;

    // Does the body move to other collisions?
    bool dynamic;

    // Is the body hidden
    bool hidden;

    static const float P2M;
    static const float M2P;

public:

    int x;
    int y;
    int w;
    int h;

    Body(
	    b2World * world,
	    int x, 
	    int y, 
	    int w, 
	    int h,
	    float friction = 0.0,
	    bool dynamic = true
	);
    virtual ~Body();

    void setFriction(const float friction);

    b2Vec2 getPosition() const;

    void setVelocity(const b2Vec2 vector);
    b2Vec2 getVelocity() const;

    void setAngleVelocity(float angle);

    void moveTo(int x, int y);
    void setAngle(float angle);

    void hide();
    void show();

    void setColor(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha = 255);
    Color getColor() const;

    virtual void draw();
};

#endif

