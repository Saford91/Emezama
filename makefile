CXX      = g++
CXXFLAGS = -Wall
CXXLIBS  = -lncurses
DEPS     = Cell.h Maze.h debug.h Player.h Emezama.h Window.h makefile
OBJS     = Maze.o Cell.o Player.o main.o Emezama.o Window.o
PROGNAME = Emezama

all: $(PROGNAME)

debug: CXXFLAGS += -g -D_DEBUG
debug: $(PROGNAME)

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(PROGNAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(CXXLIBS) -o $@ $^

clean:
	rm -f $(PROGNAME) $(OBJS)
