all: pointers1 list1

pointers1: pointers1.o
	g++ -o $@ $<

list1: list1.o list.o node.o
	g++ -o $@ $^

%.o: %.cpp %.h
	g++ -c $<

clean:
	rm -f pointers? list? *.o