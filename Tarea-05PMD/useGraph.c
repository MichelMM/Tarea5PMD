//Directivas al preprocesador
#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"
//Variables Globales y nuevos tipos de datos
//prototipos de funciones
int cmpInt(void *, void *);
void printInt(void *);
Type cloneInt(Type );

//Función principal
int main() {
	//Configurando el buffer de salida
	setvbuf(stderr, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	//Declaración de variables
	Graph s1;
	s1 = graph_create(cmpInt, printInt,cloneInt);

	int v = 10;
	int v2 =15;
	graph_addVertex(s1, &v);
	graph_addVertex(s1, &v2);


	printf("%p %p",&v,&v2);

	printf("Elementos del Grafo:\n ");
	graph_print(s1);

	v = 15;
	graph_destroy(s1);



	//Entrada de datos
	//Procesameinto de datos
	//Salida de información
	return 0;
}
//Desarrollo de funciones
int cmpInt(void *d1, void *d2) {
	int v1 = *(int *) d1;
	int v2 = *(int *) d2;
	return v1 - v2;
}

void printInt(void *d){
	printf(" %d \n",*(int*)d);
}

void * cloneInt(void *d){
	int v=*(int *)d;
	int *new=(int *)malloc(sizeof(int));
	*new=v;
	return new;
}
