#ifndef BASICSHAPE_H
#define BASICSHAPE_H

/*
Describes a rectangle by its left upper corner, height, width and color.
*/
class BasicShape
{
public:
	int x;
	int y;
	int height;
	int width;
	int color;

	BasicShape(int x, int y, int height, int width, int color);
};

#endif