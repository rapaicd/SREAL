#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "helper.h"

void VelikaSlova(char* NestoVeliko){

	unsigned int pom = strlen(NestoVeliko);
	unsigned int i;

	for(i=0;i<pom;i++){

		NestoVeliko[i]=toupper(NestoVeliko[i]);
	}

	printf("\nVelika slova: %s\n",NestoVeliko);
}
