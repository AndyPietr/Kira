#include<stdio.h>
#include<stdlib.h>
#include <wiringPi.h>

#define ON  1
#define OFF 0
#define PIN_RELAY 17 


float readData() {
	FILE *fp;
	if((fp = fopen("/sys/bus/w1/devices/28-000008d6b7f8/w1_slave", "r")) == NULL){
		printf("ERROR in readData function, file error, check connection to sensor \n");
		exit(1);
	}
	int i;
	for( i=0; i<69;i++){
		char a;
		fscanf(fp, "%*c", &a);
//		printf("%c", a);
	}
	char numberString[5];
	for(i=0; i<5 ; i++) {
		fscanf(fp, "%c", &numberString[i] );
		printf("%c", numberString[i]);
	}
	fclose(fp);

	float liczba = atof(numberString) /1000 ;
	printf("\n%f", liczba);
	return liczba;
}


int onOffRelay(int PinRelay, int onOff){

	if(wiringPiSetupGpio() == -1){
		puts("fail to start wiringPiSetup()");
		exit(1);
	}
	//do usuniecia
	else
		puts("wiringPiSteup oki ;)");
	//============
	
	pinMode (PinRelay, OUTPUT );
	if (onOff == ON)
		digitalWrite (PinRelay, HIGH );
	else if (onOff == OFF)
		digitalWrite (PinRelay, LOW);
	else{
		puts ("ERROR in onOfffRelay");
		exit(1);
	}	

	return 0;
}
	

int main(){

		readData();
		onOffRelay(PIN_RELAY, OFF);
		delay(10000);
	/*	while(1){
				
		}
*/
	return 0;		
}

