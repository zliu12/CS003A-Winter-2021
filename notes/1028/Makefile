all: pali1 class1 class2

pali1: pali1.cpp
	g++ -o $@ $<

class1: class1.o cat.o dog.o animal.o
	g++ -o $@ $^

class2: class2.o cat.o dog.o animal.o util.o
	g++ -o $@ $^

class1.o: class1.cpp cat.h dog.h animal.h
	g++ -c $<
	
class2.o: class2.cpp cat.h dog.h animal.h  util.h
	g++ -c $<

cat.o: cat.cpp cat.h animal.h
	g++ -c $<

dog.o: dog.cpp dog.h animal.h
	g++ -c $<

animal.o: animal.cpp animal.h
	g++ -c $<

util.o: util.cpp util.h animal.h
	g++ -c $<

clean:
	rm -f pali? class1?