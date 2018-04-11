#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <wiringPi.h>
#include <unistd.h>

const int pin[5]={4,5,6,26,27};
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
			t=*((*(mot.val))+mot.num);
			printf("ptr=%p --- id =%d --- val= %d\n",(*(mot.val)),pinServ,t);
			fflush(0);
			digitalWrite(pinServ,HIGH);
			usleep(t);
			digitalWrite(pinServ,LOW);
		}
}

void* reader(void* vargp)
{
	Fich file=*(Fich*)vargp;
	FILE *fptr;
	char nomcp[60];
	int* data;
	int i;
	while(1)
	{
		//openfile(nom)
		//lit file
		sprintf(nomcp,"mvt/%s.mvt",file.nom);
		if((fptr=fopen(nomcp,"r")) !=NULL)
		{
			fscanf(fptr,"%d;\n",file.nbr);
			printf("je vois %d elements\n",*(file.nbr));
			*(file.mov)=(int*)malloc((*(file.nbr))*5*sizeof(int));
			i=0;
			while(i<*(file.nbr))
			{
				fscanf(fptr,"--%d;%d;%d;%d;%d;\n",(*(file.mov))+5*i,(*(file.mov))+5*i+1,(*(file.mov))+5*i+2,(*(file.mov))+5*i+3,(*(file.mov))+5*i+4);
				
				printf("i=%d --- %d;%d;%d;%d;%d;\n",i,*((*(file.mov))+5*i),*((*(file.mov))+5*i+1),*((*(file.mov))+5*i+2),*((*(file.mov))+5*i+3),*((*(file.mov))+5*i+4));
				fflush(0);
				i++;
			}
			
		sem_post(file.change2);
		sem_wait(file.change);
		}
		
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
	*(val)=data+tmp;
	while(1)
	{
		if(!sem_trywait(file.change2))
		{	tmp=0;
			free(data);
			max=*(file.nbr);
			data=*(file.mov);
			printf("je change de fichier");
				printf("i=%d --- %d;%d;%d;%d;%d;\n",i,((*(data))),((*(data))+1),((*(data))+2),((*(data))+3),((*(data))+4));
			
		}
		for(i=0;i<5;++i)
			sem_post(mot[i].synch);
		
		if(tmp<max)
			tmp+=5;
		for(i=0;i<5;++i)
		{
			*(mot[i].val)=data+tmp;
		}
		usleep(40000);
		printf("-------------------------%p---------------------------\n",*(val));
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
	sprintf(fichier.nom,"ferme");
	fichier.change=(sem_t*)malloc(sizeof(sem_t));
	sem_init(fichier.change,0,0);
	fichier.change2=(sem_t*)malloc(sizeof(sem_t));
	sem_init(fichier.change2,0,0);
	
	if(pthread_create(&id,NULL,manager,(void*)&fichier)!=0)
			printf("erreur a la creation de %d\n",i);
	
	/*while(1)
	{
		scanf("%s",fichier.nom);
		sem_post(fichier.change);
	}*/
	char c;
	while(1)
	{
		/*usleep(5000000);
		sprintf(fichier.nom,"ouvre");
		sem_post(fichier.change);
		usleep(5000000);
		sprintf(fichier.nom,"spiderman");
		sem_post(fichier.change);
		usleep(5000000);
		sprintf(fichier.nom,"ouvre");
		sem_post(fichier.change);
		usleep(5000000);
		sprintf(fichier.nom,"fuck");
		sem_post(fichier.change);
		usleep(5000000);
		sprintf(fichier.nom,"ouvre");
		sem_post(fichier.change);
		usleep(5000000);
		sprintf(fichier.nom,"peace");
		sem_post(fichier.change);
		usleep(5000000);
		sprintf(fichier.nom,"ouvre");
		sem_post(fichier.change);
		usleep(5000000);
		sprintf(fichier.nom,"pouce");
		sem_post(fichier.change);*/
		i=-1;
		do{
			i++;
			(*(fichier.nom+i))=getchar();
		}while((*(fichier.nom+i))!='\n')
		sem_post(fichier.change);
	
	}
	usleep(5000000);
	sprintf(fichier.nom,"ouvre");
	sem_post(fichier.change);
	usleep(5000000);
	sprintf(fichier.nom,"ferme");
	sem_post(fichier.change);
	usleep(5000000);
	sprintf(fichier.nom,"ouvre");
	sem_post(fichier.change);
	usleep(5000000);
	sprintf(fichier.nom,"ferme");
	sem_post(fichier.change);
	usleep(5000000);
	sprintf(fichier.nom,"ouvre");
	sem_post(fichier.change);
	usleep(5000000);
	sprintf(fichier.nom,"ferme");
	sem_post(fichier.change);
	usleep(5000000);
	sprintf(fichier.nom,"ouvre");
	sem_post(fichier.change);
	usleep(5000000);
	sprintf(fichier.nom,"ferme");
	sem_post(fichier.change);
	usleep(5000000);
	sprintf(fichier.nom,"ouvre");
	sem_post(fichier.change);
	usleep(5000000);
	sprintf(fichier.nom,"ferme");
	sem_post(fichier.change);
	
	
	pthread_join(id,NULL);
}
	