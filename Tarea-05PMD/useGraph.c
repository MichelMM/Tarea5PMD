#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Graph.h"

typedef struct {
	char titulo[500];
	char anio[500];
	char tagline[500];
	char Nombre[500];
	char Fecha[500];
	char Categoria[500];
	long int Movie;
	long int Person;
} Pelicula;

Pelicula Movies[1000];
Pelicula Persons[1000];
Pelicula MovPer[1000];

int cmpPelicula(void * str1, void * str2);
void printPelicula(void *data);

int main() {
	setvbuf(stderr, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	FILE *M, *P, *PM;
	M = fopen("vertex_movies.csv", "r");
	if (M == NULL) {
		printf("Couldn't open the file for reading.\n");
	}
	P = fopen("vertex_person.csv", "r");
	if (P == NULL) {
		printf("Couldn't open the file for reading.\n");
	}
	PM = fopen("edges_PersonMovies.csv", "r");
	if (PM == NULL) {
		printf("Couldn't open the file for reading.\n");
	}

	char buffM[500], buffP[500], buffPM[500];
	int x = 0, i = 0;
	char tempM, tempP, tempPM;
	int new_movie = 0, new_person = 0, new_PM = 0;

	//---------------------------------
	//              MOVIES
	//---------------------------------
	while (tempM != EOF) {
		Movies[new_movie].Person = 0;
		tempM = fgetc(M);
		//printf("%c\n",temp);
		if (tempM != ',') {
			buffM[i] = tempM;
		}
		i++;
		if (tempM == '\n' || tempM == ',' || tempM == EOF) {
			switch (x) {
			case 0:
				//printf("%s", buff);
				strcpy(Movies[new_movie].titulo, buffM);
				x++;
				break;
			case 1:
				// printf("%s", buff);
				strcpy(Movies[new_movie].anio, buffM);
				x++;
				break;
			case 2:
				//printf("%s\n", buff);
				strcpy(Movies[new_movie].tagline, buffM);
				Movies[new_movie].Movie = new_movie + 1;
				new_movie++;
				x = 0;
				break;
			}
			memset(buffM, 0, sizeof(buffM));
			i = 0;
		}
	}
	fclose(M);

	//-------------------------
	//		  PERSONS
	//-------------------------
	while (tempP != EOF) {
		Persons[new_person].Movie = 0;
		tempP = fgetc(P);
		//printf("%c\n",temp);
		if (tempP != ',') {
			buffP[i] = tempP;
		}
		i++;
		if (tempP == '\n' || tempP == ',' || tempP == EOF) {
			switch (x) {
			case 0:
				//printf("%s", buff);
				strcpy(Persons[new_person].Nombre, buffP);
				x++;
				break;
			case 1:
				// printf("%s", buff);
				strcpy(Persons[new_person].Fecha, buffP);
				x++;
				break;
			case 2:
				//printf("%s\n", buff);
				strcpy(Persons[new_person].Categoria, buffP);
				Persons[new_person].Person = new_person + 1;
				new_person++;
				x = 0;
				break;
			}
			memset(buffP, 0, sizeof(buffP));
			i = 0;
		}
	}
	fclose(P);

	//---------------------------------
	//          PERSON EDGES
	//---------------------------------
	while (tempPM != EOF) {
		tempPM = fgetc(PM);
		//printf("%c\n",temp);
		if (tempPM != ',') {
			buffPM[i] = tempPM;
		}
		i++;
		if (tempPM == '\n' || tempPM == ',' || tempPM == EOF) {
			switch (x) {
			case 0:
				//printf("%s", buff);
				strcpy(MovPer[new_PM].Nombre, buffPM);
				x++;
				break;
			case 1:
				// printf("%s", buff);
				strcpy(MovPer[new_PM].titulo, buffPM);
				new_PM++;
				x = 0;
				break;
			}
			memset(buffPM, 0, sizeof(buffPM));
			i = 0;
		}
	}
	fclose(PM);

	for(int j=0;j<new_PM;j++){
		printf("%s, %s",MovPer[j].Nombre, MovPer[j].titulo);
	}
	Graph PERMOV;
	PERMOV = graph_create(cmpPelicula, printPelicula);
	for (int j = 0; j < new_movie; j++) {
		graph_addVertex(PERMOV, &Movies[j]);
	}

//	for (int j = 0; j < new_person; j++) {
//		graph_addVertex(PERMOV, &Persons[j]);
//	}

	graph_print(PERMOV);
//	printf("\nVertices: %lu\n", graph_vertexCount(PERMOV));
	unsigned long SP=0,SM=0;
	for (int j = 0; j < new_PM; j++) {
		for (int a = 0; a < new_person; a++) {
			if (MovPer[j].Nombre == Persons[a].Nombre) {
				SP = a;
			}
		}
		for (int b = 0; b < new_movie; b++) {
			if (MovPer[j].titulo == Movies[b].titulo) {
				SM = b;
			}
		}

		printf("Funciona %lu,%lu\n",SP,SM);
		if(SP<=new_person || SM<=new_movie){
			graph_addEdge(PERMOV, &Persons[SP], &Movies[SM]);
		}


	}

	return 0;
}

int cmpPelicula(void * str1, void * str2) {
	Pelicula *string1 = (Pelicula*) str1;
	Pelicula *string2 = (Pelicula*) str2;
	if ((strcmp(string1->titulo, string2->titulo) == 0
			&& strcmp(string1->anio, string2->anio) == 0
			&& strcmp(string1->tagline, string2->tagline) == 0)) {
		return true;
	} else if ((strcmp(string1->Nombre, string2->Nombre) == 0
			&& strcmp(string1->Fecha, string2->Fecha) == 0
			&& strcmp(string1->Categoria, string2->Categoria) == 0)) {
		return true;
	}
	return false;
}

void printPelicula(void *data) {
	Pelicula *Data = (Pelicula*) data;
	if (Data->Movie > 0) {
		printf("%s, %s, %s", Data->titulo, Data->anio, Data->tagline);
	} else if (Data->Person > 0) {
		printf("%s, %s, %s", Data->Nombre, Data->Fecha, Data->Categoria);
	}
}
