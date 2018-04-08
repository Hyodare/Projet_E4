#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
//#include <wiringPi.h>
#include <unistd.h>

const int pin[5]={21,22,23,24,25};
typedef struct{
	
	int num;
	int** val;
	sem_t* synch;
}Data;

typedef struct{	
	char* nom;
	int change;
}fich;

void* servo(void *vargp)
{
	int t;
	Data data=*(Data *)vargp;
	int pinServ=pin[data.num];
	int i;
	printf("val ptr zero=%p\n",*(data.val));
	//pinMode(pinServ,OUTPUT);
	
		while(1)
		{
			sem_wait(data.synch);
			t=(*(data.val))[data.num];
			//digitalWrite(pinServ,HIGH);
			usleep(t);
			//digitalWrite(pinServ,LOW);
			sem_getvalue(data.synch,&i);
			printf("num=%d --- id =%d --- val= %d --- sem=%d\n",data.num,pinServ,t,i);
			fflush(0);
			
		}
}

void* manager(void* vargp)
{
	Data data=*(Data*)vargp;
	pthread_t id[5];
	data.synch=(sem_t*)malloc(sizeof(sem_t));
	sem_init(data.synch,0,0);
	data.val=(int**)malloc(sizeof(int*));
	int* zero=(int*)calloc(5,sizeof(int));
	int* pzero=(int*)calloc(5,sizeof(int));
	*(data.val)=zero;
	int i;
	printf("val ptr zero=%p ---- val ptr pzero=%p\n",zero,pzero);
	for(i=0;i<5;++i)
	{
		pzero[i]=2000;
	}
	for(i=0;i<5;++i)
	{
		data.num=i;
		if(pthread_create(id+i,NULL,servo,(void*)&data)==0)
			printf("initialisation du pin %d --- i=%d\n",pin[i],i);
		//usleep(10000);
	}
	
	for(i=0;i<5;i++){
	sem_post(data.synch);
	sem_post(data.synch);
	sem_post(data.synch);
	sem_post(data.synch);
	sem_post(data.synch);
	usleep(20000);
	printf("\n");
	*(data.val)=zero;
	sem_post(data.synch);
	sem_post(data.synch);
	sem_post(data.synch);
	sem_post(data.synch);
	sem_post(data.synch);
	usleep(20000);
	printf("\n");
	*(data.val)=pzero;
	}
	
	
	

	
	pthread_join(*id,NULL);
	//printf("data val=%d\n",data.val);
}
	

int main(int argc, char* argv[])
{
	if(argc != 6)printf("erreur dans le nombre d'arguments");
	//if(wiringPiSetupGpio()==-1)printf("rate setup gpio");
	int i;
	pthread_t id;
	Data data;
	
	if(pthread_create(&id,NULL,manager,(void*)&data)!=0)
			printf("erreur a la creation de %d\n",i);
	
	pthread_join(id,NULL);
}
	