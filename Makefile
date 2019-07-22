CC 			= g++
CFLAGS 		= 
SFML_FLAGS 	= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

SOURCES 	= main.cpp background_func.cpp physics_engine.cpp
GAMEOBJ 	= game_obj.cpp asteroids.cpp

OBJECTS 	= $(SOURCES: .cpp = .o) $(GAMEOBJ: .cpp = .o)

EXECUTABLE 	= go

all: first second clean

first:
	$(CC) -c $(CFLAGS) $(SOURCES) $(GAMEOBJ)

second:
	$(CC) $(OBJECTS) -o $(EXECUTABLE) $(SFML_FLAGS)

clean:
	rm -rf *.o