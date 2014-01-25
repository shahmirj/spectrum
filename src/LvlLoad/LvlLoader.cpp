#include "LvlLoad/LvlLoader.h"

vector<BasicShape> LvlLoader::Load(string filename)
{
	ifstream f(filename.c_str());

	char s[255];
	int h, w;
	char a[512][512];
		
	// skip first line (comment)
	f.get(s, 1024);

	// get width and height
	f>>h>>w;
		
	// get world matrix
	for(int i = 0; i < h; ++i)
		for(int j = 0; j < w; ++j)
		{
			f>>a[i][j];
		}
		
	return MatrixToShapes(a, h, w);
}

vector<BasicShape> LvlLoader::MatrixToShapes(char a[][512], int h, int w)
{
	vector<BasicShape> shapes;

	for(int i = 0; i < h; ++i)
		for(int j = 0; j < w; ++j)
		{
			if(a[i][j] != '0')
			{
				shapes.push_back(ExtractShape(a, h, w, i, j));
			}
		}

	return shapes;
}

BasicShape& LvlLoader::ExtractShape(char a[][512], int ah, int aw, int y, int x)
{
	int width = 0, height = 0;
	while( (x + width < aw) && (a[y][x + width] == a[y][x]) ) ++width;
	while( (y + height < ah) && (a[y + height][x] == a[y][x]) ) ++height;

	int color = a[y][x];

	for(int i = 0; i < height; ++i)
		for(int j = 0; j < width; ++j)
		{
			a[y + i][x + j] = '0';
		}

	const int RESIZE_FACTOR = 10;
	return *(new BasicShape(x * RESIZE_FACTOR, y * RESIZE_FACTOR, height * RESIZE_FACTOR, width * RESIZE_FACTOR, color));
}


	
