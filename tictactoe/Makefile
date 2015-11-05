.PHONY: all clean

T = game

all: ${T}

${T}: main.cpp
	$(CXX) -Wall -std=c++14 $^ -o $@

clean:
	rm -f ${T}
