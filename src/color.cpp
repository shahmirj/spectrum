#include <iostream>
#include "Application.h"
#include "Exception.h"

using namespace std;

int main(int argc, char *argv[])
{
    try
    {
        glutInit(&argc, argv);
        Application application(640, 480);
        return application.run();
    }
    catch (Exception &e)
    {
        std::cout << "Exception Error: " << e.what();
    }
}
