all: main
main: main.o VelikaSlova.o abeceda.o izbaciBroj.o palindrom.o
	gcc -o main main.o VelikaSlova.o abeceda.o izbaciBroj.o palindrom.o
main.o: main.c helper.h
	gcc -c main.c
VelikaSlova.o: VelikaSlova.c helper.h
	gcc -c VelikaSlova.c
abeceda.o: abeceda.c helper.h
	gcc -c abeceda.c
izbaciBroj.o: izbaciBroj.c helper.h
	gcc -c izbaciBroj.c
palindrom.o: palindrom.c helper.h
	gcc -c palindrom.c
