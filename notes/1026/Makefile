all: queue1

queue1: queue1.o queue.o node.o
	g++ -o $@ $<

%.o: %.cpp queue.h node.h
	g++ -C $^

clean:
	rm -f queue? *.o