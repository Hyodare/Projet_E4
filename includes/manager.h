#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#include "structures.h"
#include "reader.h"
#include "servo.h"

#ifndef MANAGE
#define MANAGE
void* manager(void* vargp);

#endif

