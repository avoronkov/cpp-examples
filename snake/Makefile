.PHONY: all clean clean-all

CXXFLAGS += -std=c++14 -Wall
LDFLAGS += -lncurses
all: snake

SRCS = Game.cpp main.cpp Point.cpp Snake.cpp Timer.cpp View.cpp
OBJS = $(SRCS:.cpp=.o)

snake: $(OBJS)
	$(CXX) $(LDFLAGS) $^ -o $@

clean:
	rm -f $(OBJS)

clean-all: clean
	rm -f snake
