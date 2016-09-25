
OBJECTS=$(addprefix src/, Application.o \
	LvlLoad/LvlLoader.o BasicShape.o Body.o \
)

CC=g++-5
CFLAGS=-L/usr/local/lib -I/opt/X11/include -L/opt/X11/lib -I/opt/X11/include -I/usr/local/include -Isrc -I/usr/local/include/SDL -I/usr/local/include/Box2D `sdl-config --cflags --libs`

all: color

$(OBJECTS): %.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

color: $(OBJECTS)
	$(CC) -framework GLUT -framework OpenGL $(CFLAGS) src/color.cpp $(OBJECTS) -o $@ -lSDL -lBox2D -lglut -lGL -lGLU

clean:
	rm -f color
	find src/. -name "*.o" -delete
