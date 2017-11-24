#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <time.h>


#define ON  1
#define OFF 0
#define PIN_RELAY 17 
#define TEMPERATURE_REQUESTED 25
#define DELAY 60000*5-19

char * pathToSensorFile = "/sys/bus/w1/devices/28-000008d6b7f8/w1_slave" ;
char * pathToLogFile = "/media/pi/KINGSTON/log.txt";


float readData() {
	FILE *fp;
	
	if((fp = fopen(pathToSensorFile, "r")) == NULL){
		printf("ERROR in readData function, file error, check connection to sensor \n");
		exit(1);
	}
	int i;
	for( i=0; i<69;i++){	//scan and reject early data
		char a;
		fscanf(fp, "%*c", &a);
	}

	char numberString[5];	//scan necceseary data
	for(i=0; i<5 ; i++) {
		fscanf(fp, "%c", &numberString[i] );
	}
	fclose(fp);
	return atof(numberString) /1000 ;
}


int onOffRelay(int PinRelay, int onOff){

	if(wiringPiSetupGpio() == -1){
		puts("fail to start wiringPiSetup()");
		exit(1);
	}

	pinMode (PinRelay, OUTPUT );	//sets pin to out
	if (onOff == ON)
		digitalWrite (PinRelay, HIGH );		//sets pin high
	else if (onOff == OFF)
		digitalWrite (PinRelay, LOW);		//sets pin low
	else{
		puts ("ERROR in onOfffRelay, onOff must be ON or OFF equals 1 or 0");
		exit(1);
	}	

	return 0;
}

void WriteDataToFile(float data){
	FILE *fpointer;
	if((fpointer = fopen(pathToLogFile, "a")) == NULL){
		printf("ERROR in writeData function, file error, check if Pendrive connected \n");
	}
	time_t nowTime;
	time( & nowTime);
	fprintf(fpointer, "%.1f  [st. C], date:  %s", data, ctime( & nowTime));
	fclose(fpointer);
}
	

int main(){

	float actualTemp;
	
	while(1){
	clock_t start = clock();
		actualTemp = readData();
		if( actualTemp < TEMPERATURE_REQUESTED ){
			onOffRelay(PIN_RELAY, ON);
		}
		else{
			onOffRelay(PIN_RELAY, OFF);
		}
		WriteDataToFile(actualTemp);	
		delay(DELAY);
	

	}	
	return 0;		
	
}

