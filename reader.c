#include "reader.h"

void* reader(void* vargp)
{
	Fich file=*(Fich*)vargp;
	FILE *fptr;
	char nomcp[60];
	//int* data;
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
				
				//printf("i=%d --- %d;%d;%d;%d;%d;\n",i,*((*(file.mov))+5*i),*((*(file.mov))+5*i+1),*((*(file.mov))+5*i+2),*((*(file.mov))+5*i+3),*((*(file.mov))+5*i+4));
				i++;
			}
			
		sem_post(file.change2);
		sem_wait(file.change);
		}
		
	}
}
