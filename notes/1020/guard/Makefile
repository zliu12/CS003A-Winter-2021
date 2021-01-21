all: color1

color1: color1.o color.o
	# $^ refers to ALL the files above (color1.o, color.o)
	g++ -o $@ $^

# This builds an "object" file from the "source" file
color1.o: color1.cpp color.h
	g++ -c $<

color.o: color.cpp color.h
	# $< refers only to the first argument above (color.cpp)
	g++ -c $<

clean:
	rm -f color? *.o