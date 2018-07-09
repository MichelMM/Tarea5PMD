//Directivas al preprocesador
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Graph.h"

struct strNodeL {
	Type Data;
	struct strNodeL *next;
	struct strNodeL *prior;
};

typedef struct strNodeL NodeL;

struct strList {
	NodeL *first, *last;
	unsigned int size;
};


struct strNodeG {
	int id;
	Type data;
	List vertex_list;
};


typedef struct strNodeG NodeG;

struct strGraph {
	NodeG *array;
	int num_vertex;
	int num_edges;
};





/*--------------------------------------*/
/*              List                    */
/*--------------------------------------*/

List list_create(){
	List l;
	l=(List)malloc(sizeof(struct strList));
	l->size=0;
	l->last=NULL;
	l->first=NULL;
	return l;
}

int list_size(List l){
	if(l!=NULL)
		return l->size;
	else
		return -1;
}

NodeL * createNode(Type data){
	NodeL *new;
	new=(NodeL *)malloc(sizeof(NodeL));
	new->Data=(void *)malloc(sizeof(*data));
	//memcpy(new->Data, data, sizeof(*data));
	new->next=NULL;
	new->prior=NULL;
	return new;
}

void list_add(List l, Type data){
	//Agrega un elemento al final de la lista
	//e incrementa el size
	if(l!=NULL){
		NodeL *new;
		new=createNode(data);
		if(l->size==0)
		{
			l->first=new;
			l->last=new;
		}
		else{
			l->last->next=new;
			new->prior=l->last;
			l->last=new;
		}
		l->size++;
	}
}

Type list_get(List l, int p){
	Type value=NULL;
	NodeL *current=NULL;
	int i=0;
	int s=l->size;
	if(l!=NULL){
		if ((p>=0) && (p<s)){
			current=l->first;
			while(i<p){
				current=current->next;
				i++;
			}
			value=current->Data;
		}
	}
	return value;
}

void list_set(List l, Type data, int p){
	NodeL *current=NULL;
	int i=0;
	int s=l->size;
	if(l!=NULL){
		if ((p>=0) && (p<s)){
			current=l->first;
			while(i<p){
				current=current->next;
				i++;
			}
			current->Data=data;
		}
	}
}

Type list_remove(List l, int p){
	NodeL *current=NULL;
	Type tmp;
	int i=0;
	int s=l->size;
	if(l!=NULL){
		//Buscar el nodo a remover
		if ((p>=0) && (p<s)){
			current=l->first;
			while(i<p){
				current=current->next;
				i++;
			}
		}
		if((p==0)&&(s==1)){
			tmp=current->Data;
			l->first=NULL;
			l->last=NULL;
			l->size=0;
			free(current);
			return tmp;
		}else{
			if(p==0) //Se va a eliminar el nodo inicial
			{
				tmp=current->Data;
				l->first=current->next;
				l->first->prior=NULL;
				l->size--;
				free(current);
				return tmp;
			}
			else{
				if(p==(s-1))//Se va a eliminar el nodo final
				{
					tmp=current->Data;
					l->last=current->prior;
					l->last->next=NULL;
					l->size--;
					free(current);
					return tmp;
				}
				else
				{//El elemento a remover esta en medio
					tmp=current->Data;
					current->prior->next=current->next;
					current->next->prior=current->prior;
					free(current);
					return tmp;
				}
			}
		}

	}
	return NULL;
}

void list_destroy(List l){
	while(list_size(l)>0)
		list_remove(l, 0);
	free(l);
}

/*--------------------------------------*/
/*              Graph                   */
/*--------------------------------------*/

Graph graph_create(CMP comparator) {
	Graph new = (Graph) malloc(sizeof(struct strGraph));
	new->array = NULL;
	new->num_edges = 0;
	new->num_vertex = 0;
	return new;
}

boolean graph_addVertex(Graph graph, Type data) {
	NodeG *new = (NodeG*) malloc(sizeof(struct strNodeG));
	graph->num_vertex++;
	int size =graph->num_vertex;
	graph->array = (NodeG*)realloc(graph->array,sizeof(struct strNodeG)*size);
	new->data = data;
	(*new).id = size;
	List newL;
	newL= list_create();
	new->vertex_list = newL;
//	graph->array[graph->num_vertex]=new;
	((*graph).array[size])=*new;
	return true;
}

boolean graph_addEdge(Graph graph, Type source, Type sink){

	NodeG Source = graph->array[source];
	NodeG Sink = graph->array[sink];
	if(graph->array[source]==NULL || graph->array[sink]==NULL){

	}

	list_add(graph->array[source]->vertex_list,graph->array[sink]);
	return true;
}


void graph_destroy(Graph graph){
	int i=0;
	while(graph->num_vertex != 0)
	{
		list_destroy(graph->array[i].vertex_list);
		free(graph->array[i]);
		graph->num_vertex--;
		i++;
	}
	free(graph);
}
