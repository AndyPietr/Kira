#include<stdio.h>
#include<stdlib.h>


float readData() {
	FILE *fp;
	if((fp = fopen("/sys/bus/w1/devices/28-000008d6b7f8/w1_slave", "r")) == NULL){
		printf("file error\n");
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

short onOffRelay(short oneOrZero){


}

int main(){

		readData();
	/*	while(1){
				
		}
*/
	return 0;		
}

