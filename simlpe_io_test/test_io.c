#include <stdio.h>
#include <wiringPi.h>

int main(){
	puts("tests io raspberry");

	if(wiringPiSetup() == -1){
		puts("fail to start wiringPiSetup()");
	}
	else
	puts("wiringPiSteup oki ;)");
}
