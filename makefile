

OBJECTS=$(addprefix src/, Application.o Surface.o Surface/Rectangle.o \
	LvlLoad/LvlLoader.o BasicShape.o \
)

CC=g++
CFLAGS=-Isrc -I/usr/include/SDL

all: color

$(OBJECTS): %.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

color: $(OBJECTS)
	$(CC) $(CFLAGS) src/color.cpp $(OBJECTS) -o $@ -lSDL -lbox2d

clean:
	rm -f color
	find src/. -name "*.o" -delete
