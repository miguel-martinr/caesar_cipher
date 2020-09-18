bin/caesar:	bin/caesar.o source/main.cpp
	g++ -g source/main.cpp bin/caesar.o -o bin/caesar

bin/caesar.o: include/caesar.hpp source/caesar.cpp
	g++ -g -c source/caesar.cpp -o bin/caesar.o

.PHONY:
clean:
	rm bin/*