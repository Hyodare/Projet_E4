FLAGS=-Wall -I includes
LIBS=-lpthread -lWiringPi
all: main

main: main.c includes/main.h reader.o manager.o servo.o includes/structures.h
	gcc main.c reader.o manager.o servo.o -o test $(FLAGS) $(LIBS)
	
reader.o: reader.c includes/reader.h includes/structures.h
	gcc reader.c -c $(FLAGS)
	
manager.o: manager.c includes/manager.h includes/structures.h
	gcc manager.c -c $(FLAGS)
	
servo.o: servo.c includes/servo.h includes/structures.h
	gcc servo.c -c $(FLAGS)

clean: 
	rm *.o

reset: clean main
