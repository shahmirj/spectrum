#include "Body.h"

// Thanks you
//
// http://pastebin.com/wSQcuwVQ

// Constants for our world, I believe the values here are
//
// Meters to Pixels = M2P
// Pixels to Meter = P2M
const float Body::M2P = 20;
const float Body::P2M = 1/Body::M2P;

Body::Body(
	b2World * world,
	int x, 
	int y,
	int w,
	int h,
	float friction,
	bool dynamic
    ) 
    : body(NULL), x(x), y(y), w(w), h(h), dynamic(dynamic), hidden(false)
{
    // Make sure world is not dead
    if (world == NULL)
	throw Exception("World was NULL to Body!");
	
    // Create a body definition
    b2BodyDef bodydef;
    bodydef.position.Set(x*P2M,y*P2M);
    if(dynamic) 
	bodydef.type = b2_dynamicBody;
    body = world->CreateBody(&bodydef);
   
    // Set the width and height
    //
    // Really not sure what this does?
    shape.SetAsBox(P2M*w/2, P2M*h/2);
   
    // The shape fixture properties
    b2FixtureDef definition;
    definition.shape = &shape;
    definition.density = 1.0;
    definition.friction = friction;
    body->CreateFixture(&definition);
}

void Body::draw()
{
    b2Vec2 center = body->GetWorldCenter();
    float angle = body->GetAngle();

    b2Vec2 points[4] = {
	shape.GetVertex(0),
	shape.GetVertex(1),
	shape.GetVertex(2),
	shape.GetVertex(3)
    };

    // If Hidden alpha the object
    if (hidden)
	glColor4ub(color.red,color.green,color.blue,50);
    else
	glColor4ub(color.red,color.green,color.blue,color.alpha);

    glPushMatrix();
    glTranslatef(center.x*M2P,center.y*M2P,0);
    glRotatef(angle*180.0/3.14,0,0,1);
    glBegin(GL_QUADS);

	glVertex2f(points[0].x*M2P,points[0].y*M2P);
	glVertex2f(points[1].x*M2P,points[1].y*M2P);
	glVertex2f(points[2].x*M2P,points[2].y*M2P);
	glVertex2f(points[3].x*M2P,points[3].y*M2P);

    glEnd();
    glPopMatrix();
}

void Body::setVelocity(const b2Vec2 vector)
{
    this->body->SetLinearVelocity(vector);
}

void Body::setAngleVelocity(float angleVelocity)
{
   this->body->SetAngularVelocity(angleVelocity);
}

b2Vec2 Body::getVelocity() const
{
    return this->body->GetLinearVelocity();
}

void Body::moveTo(int x, int y)
{
    this->body->SetTransform(b2Vec2(x*P2M, y*P2M), 0);
}

b2Vec2 Body::getPosition() const
{
    b2Vec2 temp = this->body->GetPosition();
    temp.x = temp.x * M2P;
    temp.y = temp.y * M2P;

    return temp;
}

void Body::setAngle(float angle)
{
    this->body->SetTransform(body->GetPosition(), angle);
}

void Body::hide()
{
    this->body->SetActive(false);
    hidden = true;
}

void Body::show()
{
    this->body->SetActive(true);
    hidden = false;
}

void Body::setColor(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha)
{
    color.red=red;
    color.green=green;
    color.blue=blue;
    color.alpha=alpha;
}

Color Body::getColor() const
{
    return this->color;    
}

Body::~Body()
{
    //delete body;
}
