#ifndef GRAPH_H_
#define GRAPH_H_

typedef void* Type;
typedef struct strGraph *Graph;
typedef struct	 strList *List;
typedef enum {true, false}boolean;
typedef int (*CMP)(Type, Type);
typedef void (*Print)(void*);

Graph graph_create(CMP comparator, Print print);//Crea una nueva instancia del contenedor Graph y retorna su dirección de memoria.
void graph_destroy(Graph graph);//Destruye la instancia del contenedor Graph.
boolean graph_addVertex(Graph graph, Type data);//Agrega un nuevo vértice al grafo de manera ordenada
boolean graph_addEdge(Graph graph, Type source, Type sink);//Agrega una nueva arista al grafo
unsigned long graph_vertexCount(Graph graph);//Retorna el número de vértices que existen en el grafo
unsigned long graph_edgeCount(Graph graph);//Retorna el número de aristas que existen en el grafo.
unsigned long graph_outDegree(Graph graph,Type source);//Retorna el número de vértices sucesores que tiene en su lista el vértice
boolean graph_hasEdge(Graph graph, Type source, Type sink);//Retorna True si el vértice del grafo que contiene source tiene en su lista de sucesores un vértice que contiene sink.
void graph_print(Graph graph);//Imprime todos los datos almacenados en el grafo.

List list_create();//Crea un ejemplar List con memoria dinámica y asigna NULL, NULL y 0 a sus elementos.
int list_size(List l);//Elimina a todos los nodos y a la lista.
void list_add(List l, Type data);//Extrae el tamaño de la lista.
Type list_get(List l, int p);//Devuelve el elemento en la posición p.
void list_set(List l, Type data, int p);//Reemplaza el elemento en la posición p por el valor recibido.
Type list_remove(List l, int p);//Elimina y devuelve el elemento en la posición p. Decrementa el tamaño en uno.
void list_destroy(List l);//Inserta un nuevo elemento en la posición p. Incrementa el tamaño en uno.




#endif /* GRAPH_H_ */
