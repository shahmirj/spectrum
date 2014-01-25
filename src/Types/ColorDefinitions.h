#ifndef COLOR_DEFINITIONS_H
#define COLOR_DEFINITIONS_H

#include "SDL.h"
#include <map>

using namespace std;

class ColorDefinitions
{
public:
	class MyColor
	{
	public:
		int r, g, b;

		MyColor() { }

		MyColor(int r, int g, int b)
		{
			this->r = r;
			this->g = g;
			this->b = b;
		}
	};

	std::map<char, MyColor> map;

	ColorDefinitions()
	{
		/* ----- CHANGE COLORS HERE ----- */
		map['1'] = *(new MyColor(255, 0, 0));
		map['2'] = *(new MyColor(150, 0, 150));
		map['3'] = *(new MyColor(55, 140, 150));
		map['4'] = *(new MyColor(15, 10, 233));
		map['5'] = *(new MyColor(198, 0, 67));
	}
};

#endif