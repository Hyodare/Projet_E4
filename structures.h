#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#ifndef STRUCT
#define STRUCT 
extern const int pin[5];

 typedef struct{
	
	int num;
	int** val;
	sem_t* synch;
}Motor;

typedef struct{	
	char* nom;
	sem_t* change;
	sem_t* change2;
	int** mov;
	int* nbr;
}Fich;

#endif 


