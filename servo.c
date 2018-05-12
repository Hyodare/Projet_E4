#include "servo.h"


void* servo(void *vargp)
{
	int t=0;
	Motor mot=*(Motor *)vargp;
	int pinServ=pin[mot.num];
	//pinMode(pinServ,OUTPUT);
	
		while(1)
		{
			sem_wait(mot.synch);
			t=*((*(mot.val))+mot.num);
			//digitalWrite(pinServ,HIGH);
			usleep(t);
			//digitalWrite(pinServ,LOW);
		}
}