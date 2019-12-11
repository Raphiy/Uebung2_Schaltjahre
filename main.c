/*
 * main.c
 *
 *  Created on: 03.11.2019
 *      Author: Froemberg Raphael
 */

#include <stdio.h>
#include <time.h>

int ist_schaltjahr1();
int ist_schaltjahr2();

int main(){
	int anzahl1 = 0, anzahl2 = 0;
	time_t startzeit, endzeit;

	time(&startzeit);
	for(int i = 1; i<=1000000000; i++){
		anzahl1 += ist_schaltjahr1(i);
	}
	time(&endzeit);
	printf("%d Schaltjahre brechnet in einer Zeit von %fs\n", anzahl1, difftime(endzeit, startzeit));


	time(&startzeit);
	for(int i = 1; i<=1000000000; i++){
		anzahl2 += ist_schaltjahr2(i);
	}
	time(&endzeit);
	printf("%d Schaltjahre berechnet in einer Zeit von %fs\n", anzahl2, difftime(endzeit, startzeit));
}


int ist_schaltjahr1(int jahr){
	if(jahr % 4 == 0 && !(jahr%100 == 0 && jahr%400 !=0)){
		return 1;
	}
	else{
		return 0;
	}
}

int ist_schaltjahr2(int jahr){
	if((jahr % 400 == 0 || jahr%100 != 0) && jahr%4 == 0){
		return 1;
	}
	else{
		return 0;
	}
}
