.PHONY: all debug
all: prog
 
my_math.o: my_math.h my_math.cpp
	g++ -c my_math.cpp
point.o: point.h my_math.h point.cpp
	g++ -c point.cpp
l_exception.o: l_exception.h l_exception.cpp
	g++ -c l_exception.cpp
lsa.o: lsa.h my_math.h point.h l_exception.h lsa.cpp
	g++ -c lsa.cpp
test.o: lsa.h my_math.h point.h l_exception.h test.cpp
	g++ -c test.cpp
prog: lsa.o my_math.o point.o l_exception.o test.o
	g++ -o prog lsa.o my_math.o point.o l_exception.o test.o -lm
clear:
	rm -f *.o ./prog
test: prog
	./prog