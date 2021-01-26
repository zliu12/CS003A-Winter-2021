all: stack1

stack1: stack1.o stack.o node.o
	g++ -o $@ $^

%.o: %.cpp stack.h node.h
	g++ -c $<


clean:
	rm -f stack? *.o