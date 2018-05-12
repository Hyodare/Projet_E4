#include "manager.h"
 
void* manager(void* vargp)
{
	Fich file=*(Fich*)vargp;
	Motor* mot=(Motor*)malloc(5*sizeof(Motor));
	pthread_t id[5];
	
	int** val=(int**)malloc(sizeof(int*));
	file.mov=(int**)malloc(sizeof(int*));
	file.nbr=(int*)malloc(sizeof(int));
	
	pthread_t read;
	if(pthread_create(&read,NULL,reader,(void*)&file)==0)
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
			//printf("je change de fichier");
			//printf("i=%d --- %d;%d;%d;%d;%d;\n",i,((*(data))),((*(data))+1),((*(data))+2),((*(data))+3),((*(data))+4));
			
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
		//printf("-------------------------%p---------------------------\n",*(val));
		//*(mot.val)=pzero;
	}

	pthread_join(*id,NULL);
	//printf("mot val=%d\n",mot.val);
}
