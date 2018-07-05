/*
 * Graph.h
 *
 *  Created on: 05/07/2018
 *      Author: Michel
 */

#ifndef GRAPH_H_
#define GRAPH_H_

typedef void* Type;
typedef struct strGraph Graph;
typedef enum {true, false}boolean;
typedef void (*CMP)(void*);
typedef void (*Print)(void*);

Graph *graph_create(CMP comparator);




void graph_destroy(Graph graph);
boolean graph_addVertex(Graph graph, Type data);
boolean graph_addEdge(Graph graph, unsigned long source, unsigned long sink);
unsigned long graph_vertexCount(Graph graph);
unsigned long graph_edgeCount(Graph graph);
unsigned long graph_outDegree(Graph graph, unsigned long source);
boolean graph_hasEdge(Graph graph, unsigned long source, unsigned long sink);
boolean graph_print(Graph graph, Print p);


#endif /* GRAPH_H_ */
