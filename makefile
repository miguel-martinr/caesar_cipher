bin/main:	caesar.o 
	g++ -g source/main.cpp bin/caesar.o -o bin/main

caesar.o:
	g++ -g -c source/caesar.cpp -o bin/caesar.o

.PHONY:
clean:
	rm bin/*