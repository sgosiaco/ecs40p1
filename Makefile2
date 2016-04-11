CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cpp flight.cpp plane.cpp utilities.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=airline.out

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o airline.out
