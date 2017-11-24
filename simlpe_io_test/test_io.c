#include <stdio.h>
#include <wiringPi.h>
#include <stdlib.h>

int main(){
	puts("tests io raspberry");

	if(wiringPiSetupGpio() == -1){
		puts("fail to start wiringPiSetup()");
	}
	else
	puts("wiringPiSteup oki ;)");

	pinMode (17, OUTPUT );
	digitalWrite (17, HIGH);
	delay(5000);
	digitalWrite (17, LOW);

	return 0;
}
