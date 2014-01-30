Spectrum
========

Color based platform game, which allows you to navigate by changing the world's colors.

### Iulia's weird abstract dream (???!!!)

How does your state of mind change the way you perceive the world around you? In the dichromatic world of Spectrum, you can only interact with objects that match your own colour. Sometimes this helps, sometimes it does not, sometimes you might want to change your colour altogether! Switch from red to blue and back to make your way to the white square.

### Instructions
Use the Arrow keys to move right and left. Your objective is to get the coloured square to touch the white square.

### Installing Linux
Download:

 - OpenGL and GLUT
 - SDL v1.2
 - Box2D v2.2.1 (https://code.google.com/p/box2d/downloads/detail?name=Box2D_v2.2.1.zip&can=2&q=)

Inside the root folder run:

    make clean all && ./color
    
*Note in some cases if you installed Box2d manualy you need to include the `/usr/local/lib` path before running the game, try the following:*

    export LD_LIBRARY_PATH=/usr/local/lib
    ./color

### Installing Windows

Main approximate steps:

Get Box2D v2.2.1 and build it with cmake (run cmake . in Box2D's directory).
Get SDL v1.2.
Get (GLUT and) OpenGlut.

Add all sources to a VS C++ project. For the above libraries: Add the headers to C++ additional include directories and the .libs to additional directories for the linker. Use the 32bit version of SDL even if running on an x64 system. Also add the .lib names to linker dependencies.

### Credits
 - Iulia Comsa - Cheif designer, head honcho and Math nut.
 - Shahmir Javaid - Software Hostage
