#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <wiringPi.h>
#include <unistd.h>

int pin[5]={};
int val[5]={};
void* servo(void *vargp)
{
	int pinServ = pin[*(int *)vargp];
	pinMode(pinServ,OUTPUT);
	int t;
		while(1)
		{
			t=val[*(int *)vargp];
			digitalWrite(pinServ,HIGH);
			delayMicroseconds(t);
			digitalWrite(pinServ,LOW);
			delayMicroseconds(20000-t);
		}
}
			

int main(int argc, char* argv[])
{
	if(argc != 6)printf("erreur dans le nombre d'arguments");
	if(wiringPiSetupGpio()==-1)printf("rate setup gpio");
	pthread_t id[5];
	int i;
	for(i=0;i<5;i++)
	{
		pin[i]=atoi(argv[i+1]);
		pthread_create(id+i,NULL,servo,(void*)i);
	}
}
	