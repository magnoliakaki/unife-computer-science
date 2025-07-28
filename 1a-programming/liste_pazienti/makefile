prog: main.o myLib.o
	gcc -Wall -g -o paz main.o myLib.o

main.o: main.c myLib.h
	gcc -Wall -g -c -o main.o main.c 

myLib.o: myLib.c myLib.h
	gcc -Wall -g -c -o myLib.o myLib.c 