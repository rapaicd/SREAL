#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "helper.h"

void main(int argc, char** argv){

	char* nestoVeliko = argv[1];
	char* ABCsort = argv[2];
	char* uzaludno = argv[3];
	char* opcija = argv[4];

	VelikaSlova(nestoVeliko);
	Abeceda(ABCsort);
	izbaciBroj (uzaludno);
	palindrom(opcija);

}
