all: namespace1 namespace2 namespace3

namespace1: namespace1.cpp
	g++ -o $@ $<

namespace2: namespace2.cpp
	g++ -o $@ $<

namespace3: namespace3.cpp sum.cpp
	g++ -o $@ $^

clean:
	rm -f namespace?