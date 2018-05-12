
all: main

main: main.c main.h reader.o manager.o servo.o structures.h
	gcc main.c reader.o manager.o servo.o -o test -Wall -lpthread -lwirigPi
	
reader.o: reader.c reader.h structures.h
	gcc reader.c -c -Wall
	
manager.o: manager.c manager.h structures.h
	gcc manager.c -c -Wall
	
servo.o: servo.c servo.h structures.h
	gcc servo.c -c -Wall 

clean: 
	rm *.o

reset: clean main
