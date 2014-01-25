#include <iostream>
#include "Application.h"
#include "Exception.h"

using namespace std;

int main()
{
    try
    {
        Application application;
        return application.run();
    }
    catch (Exception &e)
    {
        std::cout << "Exception Error: " << e.what();
    }
}
