 #include <wiringPi.h>
 #include <stdio.h>
 #include <unistd.h>
 
 int main()
 {
	 if(wiringPiSetup()==-1) printf("rate1");
	 if(wiringPiSetupGpio()==-1)printf("rate2");
	 
	 int pinServo=12;
	 
	 pinMode(pinServo,OUTPUT);
	 
	 int i=0;
	 int t=0;
	 while(i<50)
	 {
		 digitalWrite(pinServo,HIGH);
		 
		 delayMicroseconds(t);
		 
		 digitalWrite(pinServo,LOW);
		 
		 delayMicroseconds(20000-t);
		 
		 i++;
	 }
	 i=0;
	 t=2500;
	 while(i<50)
	 {
		 digitalWrite(pinServo,HIGH);
		 
		 delayMicroseconds(t);
		 
		 digitalWrite(pinServo,LOW);
		 
		 delayMicroseconds(20000-t);
		 
		 i++;
	 }
	 return 1;
 }