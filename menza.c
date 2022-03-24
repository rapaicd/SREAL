#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void dodaj(){

    int line1,line2;
    FILE *file;
    int a=0;
    do{

        printf("Trenutno stanje ruckova i vecera je: \n");

        file = fopen("menza.txt","r");
        fscanf(file,"%d %d",&line1,&line2);
        fclose(file);
        printf("Ruckova: %d  Vecera: %d\n",line1,line2);

        printf("\n1. Dodaj rucak\n");
        printf("2. Dodaj veceru\n");
        printf("3. Dodaj 10 na oboje\n");
        printf("4. Vrati se u meni\n");

        printf("Izbor: ");
        scanf("%d",&a);

        switch(a){

        case 1:
            line1++;
            file=fopen("menza.txt","w");
            fprintf(file, "%d %d", line1, line2);
            fclose(file);
            break;
        case 2:
            line2++;
            file=fopen("menza.txt","w");
            fprintf(file, "%d %d", line1, line2);
            fclose(file);
            break;
        case 3:
            line1=line1+10;
            line2=line2+10;
            file=fopen("menza.txt","w");
            fprintf(file, "%d %d", line1, line2);
            fclose(file);
            break;
        case 4:
            main();
            break;
        default:
            printf("Nije unet broj od 1 do 4.");
            break;
        }
    }while(a > 0 && a < 5);
}


int main(){

    int a=0;
    int line1=0;
    int line2=0;

    FILE *file;

    if (file = fopen("menza.txt", "r")) {
        fclose(file);
    }
    else{
        file=fopen("menza.txt","w");
        fprintf(file, "%d %d", line1, line2);
        fclose(file);
    }

    do{

        printf("Trenutno stanje ruckova i vecera je: \n");
        file = fopen("menza.txt","r");
        fscanf(file,"%d %d",&line1,&line2);
        fclose(file);
        printf("Ruckova: %d  Vecera: %d\n",line1,line2);

        printf("\n1. Oduzmi rucak\n");
        printf("2. Oduzmi veceru\n");
        printf("3. Dodaj\n");
        printf("4. Izadji\n");

        printf("Izbor: ");
        scanf("%d",&a);

        switch(a){
        case 1:
            line1--;
            file=fopen("menza.txt","w");
            fprintf(file, "%d %d", line1, line2);
            fclose(file);
            break;
        case 2:
            line2--;
            file=fopen("menza.txt","w");
            fprintf(file, "%d %d", line1, line2);
            fclose(file);
            break;
        case 3:
            dodaj();
            break;
        case 4:
            exit(1);
            break;
        default:
            printf("Nije unet broj od 1 do 4.");
            break;
        }
    }while(a > 0 && a < 5 );
}
