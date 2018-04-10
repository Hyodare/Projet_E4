#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	if(wiringPiSetupGpio()==-1)printf("rate setup gpio");
	
	int i;
	for(i=18;i<26;i++)
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
	while(digitalRead(rx)==LOW){printf("bloque low 1");}
	digitalWrite(tx,LOW);
	usleep(10000);
	digitalWrite(tx,HIGH);
	while(digitalRead(rx)==LOW){printf("bloque low 2");}
	int tmp=1;
	for(i=18;i<26;i++)
	{
		val+=digitalRead(i)*tmp;
		tmp*=2;
	}
	channel+=digitalRead(data1)*1;
	channel+=digitalRead(data2)*2;
	printf("channel = %d --- nombre = %d \n",channel,val);
	digitalWrite(tx,LOW);
	
}
	
	
	