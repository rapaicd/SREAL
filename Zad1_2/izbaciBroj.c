#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "helper.h"

void izbaciBroj(char* uzaludno){

	int pom = strlen(uzaludno);

	for (int i=0; i<pom;i++){
		if(isdigit(uzaludno[i])){
			memmove(&uzaludno[i],&uzaludno[i+1],pom-i);
		}
	}
	printf("\nRec bez brojeva je: %s\n",uzaludno);
}
