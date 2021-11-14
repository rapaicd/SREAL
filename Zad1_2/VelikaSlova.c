#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "helper.h"

void VelikaSlova(char* nestoVeliko){

	unsigned int pom = strlen(nestoVeliko);
	unsigned int i;

	for(i=0;i<pom;i++){

		nestoVeliko[i]=toupper(nestoVeliko[i]);
	}

	printf("\nVelika slova: %s\n", nestoVeliko);
}
