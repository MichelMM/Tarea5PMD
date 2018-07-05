//Directivas al preprocesador
#include <stdio.h>
#include <stdlib.h>

typedef struct strNode
{
    int id;
    Type data;
    struct strNode *peek;
};

typedef struct strNode Node;

struct strGraph
{
    Node *first;
    int num_vertices;
    int num_edges;
}strGraph;

//unsigned long graph_vertexCount(Graph g)
//{
//    return g->Nvertex;
//}
//unsigned long graph_edgeCount(Graph g)
//{
//    return g->Nedge;
//}

Graph *graph_create(CMP comparator){
    Graph *new = (Graph*)malloc(sizeof(struct strGraph));
    (*new).first = NULL;
    (*new).num_edges = 0;
    (*new).num_vertex =0;
    return new;
}
boolean graph_addVertex(Graph graph, Type data){
    Node *new = (Node*)malloc(sizeof(struct strNode));
    if((*graph).num_vertices==0){
        (*new).data = data;
        (*new).id =
    }
}
