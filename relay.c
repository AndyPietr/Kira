#include <stdio.h>
#include <wiringPi.h>
#include <stdlib.h>

int onOffRelay(short oneOrZero, int PinRelay){

	if(wiringPiSetupGpio() == -1){
		puts("fail to start wiringPiSetup()");
		exit(1);
	}
	//do usuniecia
	else
	puts("wiringPiSteup oki ;)");
	//============

	pinMode (17, OUTPUT );
	digitalWrite (17, HIGH);
	delay(5000);
	digitalWrite (17, LOW);

	return 0;
}
