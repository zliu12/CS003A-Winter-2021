all: types control struct

types: types.cpp
	g++ -o $@ $<


control: control.cpp
	g++ -o $@ $<


struct: struct.cpp
	g++ -o $@ $<


clean:
	rm -f types control struct