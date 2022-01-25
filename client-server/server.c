#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int agents(int sock){

	char buffer[256];
	char *agenti[]={"DUSANPOPOVSRBIJA","OLIVERSAKACMADJARSKA","DANILORAPAICAUSTRIJA"
			,"MARKOMARKOVICIZRAEL","SIMOLAZAREVICNEMACKA","STEFANSIMICENGLESKA",
			"STEFANVRTIPRASKIMAKEDONIJA","DARKODIMICRUSIJA","LAZAMARKOVICAMERIKA",
			"SINISAVELEMIROVICSPANIJA"};
	char *alterEgo[]={"JAMESBOND","JANISJOPLIN","SLASH","FREDY","SAMUEL","OZZY","AXLROSE",
			"ANGUSYOUNG","BLACKMORE","BONSCOTT"};
	int n,i;
	bzero(buffer,256);
	n = read(sock,buffer,255);
	buffer[n]=0;
	int j, key=4;
	char ch;

	for(j=0;buffer[j] != '\0';++j){
		ch=buffer[j];
		if(ch >= 'A' && ch <= 'Z'){
			ch = ch-key;
			if(ch < 'A'){
				ch = ch + 'Z' - 'A' + 1;
			}
			buffer[j] = ch;
		}
	}


	for(i=0;i<10;i++){
		if(strcmp(buffer,alterEgo[i])==0){
			printf("%s\n",agenti[i]);
			return 0;
		}
	}
	printf("AlterEgo se ne poklapa, KOMUNIKACIJA SE PREKIDA!\n");
	return 5;
}
/*ovo je jezgro serverske funkcionalnosti-ova funkcija se poziva
nakon uspostavljanja veze sa klijentom kako bi klijentu bilo
omoguceno da komunicira sa serverom. */
void doprocessing (int sock)
{
    /*lokalne promenljive*/
    int n;
    char buffer[256];
    char sendBuf[256];
    char tempstr[256];
    bzero(buffer,256);
    int done = 0;
	char ch;
	int j,m, key=4;
    while (!done)
    {
    	n = read(sock,buffer,255);
	for(j=0;buffer[j] != '\0';++j){
		ch=buffer[j];
		if(ch >= 'A' && ch <= 'Z'){
			ch = ch-key;
			if(ch < 'A'){
				ch = ch + 'Z' - 'A' + 1;
			}
			buffer[j] = ch;
		}
	}

	buffer[n] = 0;

	if(strcmp(buffer,"NEEDINFO")==0){

		printf("YOUCANGETINFO\n");
		m = agents(sock);
		if(m==5){
			done=1;
		}
	}else if(strcmp(buffer,"ENDE")==0){

		done=1;
		printf("ENDE\n");
	}else{
		done=1;
		printf("KOMUNIKACIJA SE PREKIDA!\n");
	}
    }
}

/* glavni program serverske aplikacije */
int main( int argc, char *argv[] )
{
    int sockfd, newsockfd, portno, clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int  n;

    /* najpre se poziva uvek socket() funkcija da se registruje socket:
	AF_INET je neophodan kada se zahteva komunikacija bilo koja
	dva host-a na Internetu;
	Drugi argument definise tip socket-a i moze biti SOCK_STREAM ili SOCK_DGRAM:
	SOCK_STREAM odgovara npr. TCP komunikaciji, dok SOCK_DGRAM kreira npr. UDP kanal
	Treci argument je zapravo protokol koji se koristi: najcesce se stavlja 0 sto znaci da
	OS sam odabere podrazumevane protokole za dati tip socket-a (TCP za SOCK_STREAM
	ili UDP za SOCK_DGRAM)  */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Inicijalizacija strukture socket-a */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = 5001;
    serv_addr.sin_family = AF_INET; //mora biti AF_INET
    /* ip adresa host-a. INADDR_ANY vraca ip adresu masine na kojoj se startovao server */
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    /* broj porta-ne sme se staviti kao broj vec se mora konvertovati u
	tzv. network byte order funkcijom htons*/
    serv_addr.sin_port = htons(portno);
 


    /* Sada bind-ujemo adresu sa prethodno kreiranim socket-om */
    if (bind(sockfd, (struct sockaddr *) &serv_addr,
                          sizeof(serv_addr)) < 0)
    {
         perror("ERROR on binding");
         exit(1);
    }
    printf("Server started.. waiting for clients ...\n");

    /* postavi prethodno kreirani socket kao pasivan socket
	koji ce prihvatati zahteve za konekcijom od klijenata
	koriscenjem accept funkcije */
    listen(sockfd,5); //maksimalno 5 klijenata moze da koristi moje usluge
    clilen = sizeof(cli_addr);
	
    while (1)
    { 	
	/*ovde ce cekati sve dok ne stigne zahtev za konekcijom od prvog klijenta*/
        newsockfd = accept(sockfd,
                (struct sockaddr *) &cli_addr, &clilen);
	printf("Client connected...\n");
        if (newsockfd < 0)
        {
            perror("ERROR on accept");
            exit(1);
        }

        /* Kreiraj child proces sa ciljem da mozes istovremeno da
	komuniciras sa vise klijenata */
	int  pid = fork();
        if (pid < 0)
        {
            perror("ERROR on fork");
	    exit(1);
        }
        if (pid == 0)  
        {
            /* child proces ima pid 0 te tako mozemo znati da li
		se ovaj deo koda izvrsava u child ili parent procesu */
            close(sockfd);
            doprocessing(newsockfd);
            exit(0);
        }
        else
        {
		/*ovo je parent proces koji je samo zaduzen da
		delegira poslove child procesima-stoga ne moras
		da radis nista vec samo nastavi da osluskujes
		nove klijente koji salju zahtev za konekcijom*/		
            close(newsockfd);
        }
    } /* end of while */
}



