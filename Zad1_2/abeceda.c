#include <stdio.h>
#include <string.h>
#include "helper.h"

void Abeceda (char* ABCsort){

	char temp;
	int pom = strlen(ABCsort);
	int i,j;

	for (i=0;i<pom-1;i++){
		for(j=i+1; j<pom;j++){
			if(ABCsort[i]>ABCsort[j]){
				temp = ABCsort[i];
				ABCsort[i] = ABCsort[j];
				ABCsort[j] = temp;
			}
		}
	}

	printf("\nRec poslagana po abecednom redu je: %s\n", ABCsort);
}
