#include <stdio.h>
#include <string.h>
#include "helper.h"

void palindrom(char* opcija){

	int l = 0;
	int h = strlen(opcija)-1;

	while (h > 1){
		if (opcija[l++] != opcija[h--]){
			printf("\n%s nije palindrom!\n",opcija);
			return;
		}
	}
	printf("\n%s je palindrom!\n!",opcija);
}
