#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <wiringPi.h>
#include <unistd.h>

const int pin[5]={21,22,23,24,25};
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

void* servo(void *vargp)
{
	int t=0;
	Motor mot=*(Motor *)vargp;
	int pinServ=pin[mot.num];
	int i;
	pinMode(pinServ,OUTPUT);
	
		while(1)
		{
			sem_wait(mot.synch);
			t=(*(mot.val))[mot.num];
			sem_post(mot.synch);
			digitalWrite(pinServ,HIGH);
			usleep(t);
			digitalWrite(pinServ,LOW);
			printf("num=%d --- id =%d --- val= %d\n",mot.num,pinServ,t);			
		}
}

void* reader(void* vargp)
{
	Fich file=*(Fich*)vargp;
	while(1)
	{
		//openfile(nom)
		//lit file
		*(file.mov)=(int*)calloc(5,sizeof(int));
		(*(file.mov))[0]=0;
		(*(file.mov))[1]=0;
		(*(file.mov))[2]=0;
		(*(file.mov))[3]=0;
		(*(file.mov))[4]=0;
		
		sem_post(file.change2);
		sem_wait(file.change);
		
	}
}

void* manager(void* vargp)
{
	Fich file=*(Fich*)vargp;
	Motor* mot=(Motor*)malloc(5*sizeof(Motor));
	pthread_t id[5];
	
	int** val=(int**)malloc(sizeof(int*));
	file.mov=(int**)malloc(sizeof(int*));
	file.nbr=(int*)malloc(sizeof(int));
	
	pthread_t read;
	if(pthread_create(id,NULL,reader,(void*)&file)==0)
		printf("initialisation du lecteur\n");
	
	int i;
	for(i=0;i<5;++i)
	{
		mot[i].num=i;
		mot[i].synch=(sem_t*)malloc(sizeof(sem_t));
		sem_init(mot[i].synch,0,0);
		mot[i].val=val;
		if(pthread_create(id+i,NULL,servo,(void*)(mot+i))==0)
			printf("initialisation du pin %d --- i=%d\n",pin[i],i);
		//usleep(10000);
	}
	
	int tmp,max;
	int* data;
	sem_wait(file.change2);
	tmp=0;
	max=*(file.nbr);
	data=*(file.mov);
	
	while(1)
	{
		for(i=0;i<5;++i)
			sem_post(mot[i].synch);
		
		for(i=0;i<5;++i)
			sem_wait(mot[i].synch);
		
		if(tmp<max)
			tmp++;
		*(val)=data+tmp;
		usleep(40000);
		printf("\n");
		//*(mot.val)=pzero;
	}

	pthread_join(*id,NULL);
	//printf("mot val=%d\n",mot.val);
}


int main(int argc, char* argv[])
{
	if(argc != 6)printf("erreur dans le nombre d'arguments");
	if(wiringPiSetupGpio()==-1)printf("rate setup gpio");
	int i;
	pthread_t id;
	
	Fich fichier;
	fichier.nom=(char*)malloc(50*sizeof(char));
	sprintf(fichier.nom,"init.mvmt");
	fichier.change=(sem_t*)malloc(sizeof(sem_t));
	sem_init(fichier.change,0,0);
	fichier.change2=(sem_t*)malloc(sizeof(sem_t));
	sem_init(fichier.change2,0,0);
	
	if(pthread_create(&id,NULL,manager,(void*)&fichier)!=0)
			printf("erreur a la creation de %d\n",i);
	
	pthread_join(id,NULL);
}
	