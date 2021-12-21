#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct klub
{
    char ime[50];
    int brojBodova;
    int datiGolovi;
    int primljeniGolovi;
    int odigrano;
}klub;


void ispisXmanjih(int a,int b){

    struct klub ispis[30];
    FILE *file;

    char ime[]="IME";
    char bodovi[]="BODOVI";
    char dati[]="DG";
    char prim[]="PG";
    char odigrano[]="ODIGRANO";

    printf("%4s%14s%4s:%2s%13s\n", ime,bodovi, dati, prim, odigrano);

    file = fopen("tabela.txt","r");
    fread(&ispis,sizeof(klub),30,file);
    for(int i=0;i<b;i++){
            if(ispis[i].brojBodova<=a){

               printf("%-10s%5d%7d:%2d%9d\n", ispis[i].ime, ispis[i].brojBodova, ispis[i].datiGolovi, ispis[i].primljeniGolovi, ispis[i].odigrano);
            }
    }
}
void ispisXvecih(int a,int b){

    struct klub ispis[30];
    FILE *file;

    char ime[]="IME";
    char bodovi[]="BODOVI";
    char dati[]="DG";
    char prim[]="PG";
    char odigrano[]="ODIGRANO";

    printf("%4s%14s%4s:%2s%13s\n", ime,bodovi, dati, prim, odigrano);

    file = fopen("tabela.txt","r");
     fread(&ispis,sizeof(klub),30,file);
    for(int i=0;i<b;i++){
            if(ispis[i].brojBodova>=a){

                printf("%-10s%5d%7d:%2d%9d\n", ispis[i].ime, ispis[i].brojBodova, ispis[i].datiGolovi, ispis[i].primljeniGolovi, ispis[i].odigrano);
            }
    }
}
void sortiranje(int a){

    FILE *file;
    struct klub sort[30];
    struct klub temp;
    struct klub sortZamena[30];

    file=fopen("tabela.txt","r");
    fread(&sort,sizeof(klub),30,file);

    for(int i=0;i<a;i++){

        sortZamena[i]=sort[i];
    }
    
    fclose(file);

    int i,j;


    for (i = 0; i < a-1; i++){
        for (j = 0; j < (a-1-i); j++){
            if (sortZamena[j].brojBodova < sortZamena[j + 1].brojBodova){
                temp = sortZamena[j];
                sortZamena[j] = sortZamena[j + 1];
                sortZamena[j + 1] = temp;
            } 
        }
    }
    for (i = 0; i < a-1; i++){
        for (j = 0; j < (a-1-i); j++){
            if(sortZamena[j].brojBodova == sortZamena[j+1].brojBodova){
                if (sortZamena[j].datiGolovi < sortZamena[j + 1].datiGolovi){
                    temp = sortZamena[j];
                    sortZamena[j] = sortZamena[j + 1];
                    sortZamena[j + 1] = temp;
                }
            }
        }
    }

//sorting write
    file=fopen("tabela.txt","w");
    for(int k=0;k<a;k++){

        sort[k]=sortZamena[k];
    }
    fwrite(&sort,sizeof(klub),30,file);
    fclose(file);    
}

void noviTim(int i){

    FILE *file;
    char ime1[30];
    struct klub tabela[30];

    file=fopen("tabela.txt","r");

    fread(&tabela,sizeof(klub),30,file);
    fclose(file);
    
    file= fopen("tabela.txt", "w");

    printf("Upisi ime kluba: ");
    scanf("%s",ime1);

    strcpy(tabela[i].ime,ime1);
    tabela[i].brojBodova=0;
    tabela[i].datiGolovi=0;
    tabela[i].primljeniGolovi=0;
    tabela[i].odigrano=0;

    fwrite(&tabela, sizeof(klub), 30, file);
    fclose(file);
}

void pretraziTabelu(int i){

    char x[5];
    char x1='<';
    char x2='>';

    printf("\n*Napomena: unesi x,< ili x,> za ispis svih klubova sa manjim i\njednakim ili vecim i jednakim brojem bodova u odnosu na paramtera x.*\n");
    printf("\nUnesi string: \n");
    scanf("%s",x);

    int a = x[0]-'0';
    char x123=x[2];

    if (x123==x1){

        printf("Ispis svih klubova sa brojem bodova manjim od parametra x: \n");
        ispisXmanjih(a,i);

    }
    else if(x123==x2){

        printf("Ispis svih klubova sa brojem bodova vecim od parametra x: \n");
        ispisXvecih(a,i);

    }
    else{
        printf("Netacno unet string!\n");
    }
}

void ispisiTrenutno(int i){

    sortiranje(i);

    FILE *file;
    struct klub tabela[30];
    char poredak[]="Poredak";
    char ime[]="IME";
    char bodovi[]="BODOVI";
    char dati[]="DG";
    char prim[]="PG";
    char odigrano[]="ODIGRANO";

    printf("%-10s%10s%14s%4s:%2s%13s\n",poredak, ime,bodovi, dati, prim, odigrano);
    
    file = fopen("tabela.txt", "r");
    fread(&tabela, sizeof(klub), 30, file);
    for(int j=0;j<i;j++){
            
            printf("%4d.%16s%10d%7d:%2d%9d\n",j+1 ,tabela[j].ime, tabela[j].brojBodova, tabela[j].datiGolovi, tabela[j].primljeniGolovi, tabela[j].odigrano);
    }
    fclose(file);

}

void koriguj(int a){

  char domacin[30];
  char gost[30];
  char rezultat[5];
  int rezDomacin=0;
  int rezGost=0;

  printf("Unesi domaci tim: ");
  scanf("%s",domacin);
  printf("Unesi gostujuci tim: ");
  scanf("%s",gost);
  
  printf("\nRezultat utakmice je: ");
  scanf("%s",rezultat);

  char s=rezultat[0];
  char b=rezultat[2];

    rezDomacin = s-'0';

    rezGost = b-'0';
    
    int c=0;
    if(s<b){

        c=3;//gost pobedio
    }else if(b<s){

        c=1;//domacin pobedio
    }else if(b==s){

        c=2;//nereseno
    }

    FILE *file;
    struct klub tabela[30];

    int primljeniGolovi;
    int datiGolovi;
    int bodovi;
    int odigrano=0;

    file=fopen("tabela.txt","r");

    fread(&tabela, sizeof(klub), 30, file);
    for(int i=0;i<a;i++){
        
       int t = strcmp(domacin,tabela[i].ime);
        if(t==0){

            odigrano = tabela[i].odigrano;
            bodovi = tabela[i].brojBodova;
            datiGolovi = tabela[i].datiGolovi;
            primljeniGolovi = tabela[i].primljeniGolovi;
        }
    }
    fclose(file);

    file=fopen("tabela.txt","w");

        for(int i=0;i<a;i++){

        int t = strcmp(domacin,tabela[i].ime);

        if(t==0){
            if(c==1){
                tabela[i].brojBodova=bodovi+3;
            }else if(c==2){
                tabela[i].brojBodova=bodovi+1;
            }
            tabela[i].odigrano=odigrano+1;
            tabela[i].datiGolovi=datiGolovi+rezDomacin;
            tabela[i].primljeniGolovi=primljeniGolovi+rezGost;
        }
    }
    fwrite(&tabela,sizeof(klub),30,file);
    fclose(file);
    
    // --GOST-- 
    
    int bodovi1;
    int datiGolovi1;
    int primljeniGolovi1;
    int odigrano1=0;
    file=fopen("tabela.txt","r");
    fread(&tabela,sizeof(klub),30,file);
    for(int i=0;i<a;i++){

        
        int t = strcmp(gost,tabela[i].ime);

        if(t==0){

            odigrano1 = tabela[i].odigrano;
            bodovi1 = tabela[i].brojBodova;
            datiGolovi1 = tabela[i].datiGolovi;
            primljeniGolovi1 = tabela[i].primljeniGolovi;
        }
    }
    fclose(file);

    file=fopen("tabela.txt","w");

        for(int i=0;i<a;i++){

        int t = strcmp(gost,tabela[i].ime);
        if(t==0){
            if(c==3){
                tabela[i].brojBodova=bodovi1+3;
            }else if(c==2){
                tabela[i].brojBodova=bodovi1+1;
            }
            tabela[i].odigrano = odigrano1+1;
            tabela[i].datiGolovi=datiGolovi1+rezGost;
            tabela[i].primljeniGolovi=primljeniGolovi1+rezDomacin;
        }
    }
fwrite(&tabela,sizeof(klub),30,file);
fclose(file);
}

void main(){


    FILE *file;
    int a=0;
    if (file = fopen("brojac.txt", "r")) 
    {
        fclose(file);
    }
    else
    {
        file=fopen("brojac.txt","w");
        fprintf(file, "%d", a); 
        fclose(file);
    }


    int i=0;
    file=fopen("brojac.txt","r");
    fscanf(file,"%d",&i);
    fclose(file);
    printf("BROJAC %d\n",i);
     int izbor;

     do{

         printf("    ***MENI***\n");
         printf("1. Unesi novi tim\n");
         printf("2. Pretrazi tabelu\n");
         printf("3. Ispis tabele\n");
         printf("4. Koriguj parametre kluba\n");
         printf("5. Izadji i sacuvaj promene u tabeli\n");

         printf("Tvoj izbor je: ");
         scanf("%d",&izbor);

         switch (izbor)
         {
         case 1:
            noviTim(i);
            i++;
             break;
         case 2:
            pretraziTabelu(i);
             break;
         case 3:
            ispisiTrenutno(i);
             break;
         case 4:
           koriguj(i);
             break;
         case 5:
            file=fopen("brojac.txt","w");
            fprintf(file, "%d", i); 
            fclose(file);
            printf("Kraj programa!\n");
            exit(1);
              break;
         default:
            printf("\nNije unet broj od 1 do 6!");
             break;
         }
     }while(izbor > 0 && izbor < 7);
}

