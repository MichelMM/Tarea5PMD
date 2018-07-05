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
typedef enum {true, flase}boolean;
typedef void (*CMP)(void*);
typedef void (*Print)(void*);

Graph graph_create(CMP comparator);
void graph_destroy(Graph g);
boolean graph_addVertex(Graph g, Type data);
boolean graph_addEdge(Graph g, unsigned long source, unsigned long sink);
unsigned long graph_vertexCount(Graph g);
unsigned long graph_edgeCount(Graph g);
unsigned long graph_outDegree(Graph g, unsigned long source);
boolean graph_hasEdge(Graph g, unsigned long source, unsigned long sink);
boolean graph_print(Graph g, Print p);
#endif /* GRAPH_H_ */
