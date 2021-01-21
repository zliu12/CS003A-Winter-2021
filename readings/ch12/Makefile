all: dtime1

dtime1: dtime1.o dtime.o
	g++ -o $@ $^

dtime1.o: dtime1.cpp dtime.h
	g++ -c $<

dtime.o: dtime.cpp dtime.h
	g++ -c $<

clean:
	rm -f dtime? *.o