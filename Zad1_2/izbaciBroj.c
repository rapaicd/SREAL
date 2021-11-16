#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "helper.h"

void izbaciBroj(char* uzaludno){

	int pom = strlen(uzaludno);
	char novi[100];
	int j=0;

	for (int i=0; i<pom;i++){
		if(!isdigit(uzaludno[i])){
//			memmove(&uzaludno[i],&uzaludno[i+1],pom-i);
			novi[j]=uzaludno[i];
			j++;
		}
		novi[j]='\0';
	}
	printf("\nRec bez brojeva je: %s\n",novi);
}
