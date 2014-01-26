
OBJECTS=$(addprefix src/, Application.o \
	LvlLoad/LvlLoader.o BasicShape.o Body.o \
)

CC=g++
CFLAGS=-L/usr/local/lib -Isrc -I/usr/include/SDL -I/usr/local/include/Box2D

all: color

$(OBJECTS): %.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

color: $(OBJECTS)
	$(CC) $(CFLAGS) src/color.cpp $(OBJECTS) -o $@ -lSDL -lBox2D -lglut -lGL -lGLU

clean:
	rm -f color
	find src/. -name "*.o" -delete
