.PHOMY: all clean

EXAMPLES=01-basic 02-shapes 03-slicing 04-collections

all: ${EXAMPLES}

%: %.cpp
	$(CXX) -Wall -std=c++14 $^ -o $@

clean:
	rm -f ${EXAMPLES}
