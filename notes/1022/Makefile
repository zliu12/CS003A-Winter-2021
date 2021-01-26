all: list1 list2 list3

list1: list1.o list.o node.o
	g++ -o $@ $^

list2: list2.o list.o node.o
	g++ -o $@ $^

list3: list3.o list.o node.o
	g++ -o $@ $^

%.o: %.cpp %.h
	g++ -c $<

clean:
	rm -f pointers? list? *.o