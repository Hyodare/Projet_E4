#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
//#include <wiringPi.h>
#include <unistd.h>

#include "structures.h"

#ifndef SERVO
#define SERVO
void* servo(void *vargp);

#endif

