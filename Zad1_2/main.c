#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "helper.h"

void main(int argc, char** argv){

	char* opcija = argv[argc-1];
	char opc = opcija[0];

	switch(opc){

		case '1':
			for(int i=1;i<argc-1;i++){
				VelikaSlova(argv[i]);
			}
			break;
		case '2':
			for(int i=1;i<argc-1;i++){
				Abeceda(argv[i]);
			}
			break;
		case '3':
			for(int i=1; i<argc-1;i++){
				izbaciBroj(argv[i]);
			}
			break;
		case '4':
			for(int i=1; i<argc-1;i++){
				palindrom(argv[i]);
			}
			break;
		default:
			printf("Uneli ste broj veci od 4 ili manji od 1!\n");
			break;
			}
}
