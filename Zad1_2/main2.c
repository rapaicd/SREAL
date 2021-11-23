#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main(int argc, char **argv){

	char* opcija=argv[argc-1];
	char opc =opcija[0];
//	int opc = atoi (argv[argc-1]);


	printf("\n%d\n",argc);
	printf("%d\n",argc-1);
	printf("%c\n",opc);
//	printf("%s\n",opcija);

	switch(opc){
	case '1':
		printf("kurac");
		break;
	default:
	printf("Ne valja");
}

}
