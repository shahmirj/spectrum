

OBJECTS=$(addprefix src/, Application.o Surface.o)

all: color

src/$(OBJECTS): %.o: %.cpp
	g++ -c $< -o $@

color: $(OBJECTS)
	g++ src/color.cpp $(OBJECTS) -o $@ -lSDL

clean:
	rm -f color
	find src/. -name "*.o" -delete
