//Directivas al preprocesador
#include <stdio.h>
#include <stdlib.h>


struct node
{
    int id;
    Type data;
}strNode;

typedef struct strNode Node;

struct graph
{
    int* arry=0;
    int Nvertex;
    int Nedge;
}strGraph;

unsigned long graph_vertexCount(Graph g)
{
    return g->Nvertex;
}
unsigned long graph_edgeCount(Graph g)
{
    return g->Nedge;
}
