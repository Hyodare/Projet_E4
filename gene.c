 #include <stdio.h>
 #include <stdlib.h>
 
 int main(int argc, char* argv[])
{

	int mvt[5*2000]={0};//(int*)calloc(5*2000,sizeof(int));
	FILE *fptr;
	int is[5]={0};
	int doigt, angle, tps;
	int i=0;
	for(i=0;i<5*2000;i++)
	{
		mvt[i]=0;
	}
	for(i=0;i<5;i++)
	{
		is[i]=0;
	}
	if((fptr=fopen(argv[1],"r")) ==NULL)
	{
		printf("erreur dans le nom du fichier");
		return 0;
	}
	float cran;
	i=0;i=0;i=0;i=0;i=0;i=0;i=0;i=0;i=0;i=0;i=0;
	while( fscanf(fptr,"%d;%d;%d;\n",&doigt,&angle,&tps)>0)
	{
		i=0;
		 printf("%d;%d;%d;\n",doigt,angle,tps);
			printf("i=%d --- precedent :%d --- isdgt :%d;\n",i,5 *is[doigt]+5*i +doigt,is[doigt]);
		 cran=((  angle  -  mvt[5*(is[doigt]+i)+doigt]  )  )/ (tps -is[doigt]);
		 printf("cran: %lf;\n",cran);
		for (i=is[doigt];i<=tps;i++)
		{
			if(i!=is[doigt])
			mvt[5*(is[doigt]+i)+doigt]=   mvt[5*(is[doigt])+doigt]    +  i*cran;
		 printf("cran: %lf;\n",i*cran);
			printf("ecrit : %d  sur  doigt :%d\n", mvt[5*(is[doigt]+i)+doigt],doigt);
		}
		
		is[doigt]=tps;
		
		for(i=tps;i<2000;i++)
		{
			mvt[5*(i)+doigt]=angle;
		}
	}
	
	fclose(fptr);
	
	
	int max =0;
	for(i=0;i<5;i++)
	{
		if( is[i]>max)
		{
			max=is[i];
		}
	}
	char nom[50];
	sprintf(nom,"%s.mvt",argv[1]);
	if((fptr=fopen(nom,"w")) ==NULL)
	{
		printf("erreur ecriture du fichier");
		return 0;
	}
	
	fprintf(fptr,"%d;\n",max);
	
	for(i=0;i<max;i++)
	{
		
		fprintf(fptr,"%d;%d;%d;%d;%d;\n",mvt[5*i+0],mvt[5*i+1],mvt[5*i+2],mvt[5*i+3],mvt[5*i+4]);
	}
	fclose(fptr);
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	