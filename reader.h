#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#include "structures.h"

#ifndef READER
#define READER
void* reader(void* vargp);

#endif

