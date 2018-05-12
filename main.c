#include "main.h"

const int pin[5]={4,5,6,26,27};

int main(int argc, char* argv[])
{	
	if(argc != 6)printf("erreur dans le nombre d'arguments");
	if(wiringPiSetupGpio()==-1)printf("rate setup gpio");
	pthread_t id;
	
	Fich fichier;
	fichier.nom=(char*)malloc(50*sizeof(char));
	sprintf(fichier.nom,"ferme");
	fichier.change=(sem_t*)malloc(sizeof(sem_t));
	sem_init(fichier.change,0,0);
	fichier.change2=(sem_t*)malloc(sizeof(sem_t));
	sem_init(fichier.change2,0,0);
	
	if(pthread_create(&id,NULL,manager,(void*)&fichier)!=0)
			printf("erreur a la creation du manager");
	
	/*while(1)
	{
		scanf("%s",fichier.nom);
		sem_post(fichier.change);
	}*/
	while(1)
	{
		usleep(1500000);
		sprintf(fichier.nom,"test.txt");
		sem_post(fichier.change);
		usleep(1500000);
		sprintf(fichier.nom,"ouvre");
		sem_post(fichier.change);
			
	}	
	
	pthread_join(id,NULL);
}
	