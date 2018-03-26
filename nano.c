#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <wiringPi.h>

int main(int argc, char* argv[])
{
	if(wiringPiSetup()==-1)printf("rate setup");
	if(wiringPiSetupGpio()==-1)printf("rate setupGpio");
	
	int i;
	char* arg[]={"./test3","",NULL};
	for (i=1;i<argc;i++)
	{	arg[1]=argv[i];
		if (fork()==0)	
		{
			execv("./test3",arg);
			perror("execv");
		}
	}
}