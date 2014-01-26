#ifndef BODY_H_
#define BODY_H_

#include <GL/gl.h>
#include <GL/glu.h>
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

    //void doActualDraw();

    Color color;

    bool dynamic;

    int x;
    int y;
    int w;
    int h;

    static const float P2M;
    static const float M2P;

public:
    Body(
	    b2World * world,
	    int x, 
	    int y, 
	    int w, 
	    int h, 
	    bool dynamic = true
	);
    virtual ~Body();

    void setVelocity(const b2Vec2 vector);
    b2Vec2 getVelocity() const;

    void setColor(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha = 255);

    virtual void draw();
};

#endif

