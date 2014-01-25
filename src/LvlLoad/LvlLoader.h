#ifndef LVLLOADER_H
#define LVLLOADER_H

#include <string>
#include <vector>
#include <fstream>
#include "BasicShape.h"

using namespace std;

/*
Class for loading a level from a file.
*/
class LvlLoader
{
public:

    /* Gets a vector of basic shapes. */
    vector<BasicShape> Load(const string filename);

    /* Gets a vector of basic shapes. */
    vector<BasicShape> MatrixToShapes(char a[][512], int h, int w);

    /* Creates a shape using the info in the matrix a and zeroes it in a. */
    BasicShape& ExtractShape(char a[][512], int ah, int aw, int y, int x);
};

#endif
