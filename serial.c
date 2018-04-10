#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	if(wiringPiSetupGpio()==-1)printf("rate setup gpio");
	
	int i;
	for(i=18;i<27;i++)
	{
		pinMode(i,INPUT);
	}
	int val=0,channel=0;
	int rx=12,tx=13,data1=16, data2=17;
	pinMode(rx,INPUT);
	pinMode(tx,OUTPUT);
	pinMode(data1,INPUT);
	pinMode(data2,INPUT);
	digitalWrite(tx,HIGH);
	while(digitalRead(rx)==LOW){}
	digitalWrite(tx,LOW);
	usleep(1000);
	digitalWrite(tx,HIGH);
	while(digitalRead(rx)==LOW){}
	int tmp=1;
	for(i=18;i<27;i++)
	{
		val+=digitalRead(i)*tmp;
		tmp*=2;
	}
	channel+=digitalRead(data1)*1;
	channel+=digitalRead(data2)*2;
	printf("channel = %d --- nombre = %d \n",channel,val);
	
}
	
	
	