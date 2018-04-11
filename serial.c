#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define NBPOINT 100
#define NBCAPTEUR 3

#include <wiringPi.h>

int main()
{
	if(wiringPiSetupGpio()==-1)printf("rate setup gpio");
	
	int i;
	for(i=18;i<=26;i++)
	{
		pinMode(i,INPUT);
	}
	int val=0,channel=0;
	int rx=12,tx=13,data1=16, data2=17;
	pinMode(rx,INPUT);
	pinMode(tx,OUTPUT);
	pinMode(data1,INPUT);
	pinMode(data2,INPUT);
	digitalWrite(tx,LOW);
	scanf("/n");
	digitalWrite(tx,HIGH);
	while(digitalRead(rx)==LOW){printf("bloque low 1");
	}
	digitalWrite(tx,LOW);
	while(digitalRead(rx)==HIGH){printf("bloque low 2");
	}
	scanf("/n");
	usleep(100000);
	printf("fin init\n");

	int tmp=1;
	//begin init values management
	int minimum=0, seuil1=100;

	int values[NBCAPTEUR][NBPOINT] = {0};
	int average[NBCAPTEUR][NBPOINT] = {0};
	int hist[NBCAPTEUR][2] = {0};

	int histoInitialise[NBCAPTEUR]={0};//variable qui permet de ne pas avoir hist<0
	//end init values management
	while(1)
	{	val=0;
		channel=0;
		printf("debut --- ");

		digitalWrite(tx,HIGH);
		while(digitalRead(rx)==LOW){//printf("bloque low 2");
		}
		tmp=1;
		for(i=18;i<26;i++)
		{
			val+=digitalRead(i)*tmp;
			tmp*=2;
		}
		channel+=digitalRead(data1)*1;
		channel+=digitalRead(data2)*2;
		printf("channel = %d --- nombre = %d --- ",channel,val);
		///////////////////////////////////////////////////////////////////begin values management
		//maj moyenne
		average[channel][iManagement]=(average[channel][iManagement]*NBPOINT-values[channel][iManagement]+val-minimum)/NBPOINT;
		//ajout dans l'histogramme
		if (val-minimum>seuil1)
		{
		hist[channel][1]++;
		}
		else
		{
		hist[channel][0]++;
		}

		//supression de l'ancienne valeur
		if (histoInitialise[channel]!=0)
		{
			if (values[channel][iManagement]>seuil1)
			{
			hist[channel][1]--;
			}
			else
			{
			hist[channel][0]--;
			}
		}
		//maj tableau de valeur
		values[channel][iManagement]=val-minimum;
		//i=i+1
		if (i+1>=NBPOINT)
		{
			histoInitialise[channel]=1;
		}
		i=(i++)%NBPOINT;
		///////////////////////////////////////////////////////////////////end values management
		digitalWrite(tx,LOW);
		printf("fin \n");
		while(digitalRead(rx)==HIGH){//printf("bloque low 1");
		}
	}
	
}

