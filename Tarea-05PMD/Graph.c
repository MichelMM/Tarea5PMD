#include <stdio.h>
#include <stdlib.h>
#include "set.h"

struct strNode {
	Type data;
	struct strNode *left, *right;
};

typedef struct strNode Node;

struct strSet {
	Node *root;
	int size;
	Comparador cmpFunction;
	Clone cloneFunction;
	MyFree freeFunction;
	Print printFunction;
};

Set setCreate(Comparador cmp, Clone clone, MyFree myFree) {
	Set newSet = (Set) malloc(sizeof(struct strSet));
	if (newSet != NULL) {
		newSet->root = NULL;
		newSet->size = 0;
		newSet->cmpFunction = cmp;
		newSet->cloneFunction = clone;
		newSet->freeFunction = myFree;
	}
	return newSet;
}

int setSize(Set who){
	if(who!=NULL)
		return who->size;
	return -1;
}

Node * newNode(Type data){
	Node * new=(Node *)malloc(sizeof(Node));
	if(new!=NULL){
		new->left=NULL;
		new->right=NULL;
		new->data=data;
	}
	return new;
}

bool setAdd(Set who,Type data){
	//Node *new = newNode(data);
	//Type temp=who->cloneFunction(data);
	Node *new=newNode(who->cloneFunction(data));
	bool found=false,added=false;
	int status;
	if(who->root==NULL){
		who->root=new;
		who->size++;
	}else{
		//El árbol ya tiene elementos
		Node *current;
		current=who->root;
		while((!found) && (!added)){
			status=who-> cmpFunction(new->data,current->data);
			if(status==0){
				return false;
			}

		}
	}
}

void setPrint(Set who){
	if(who!=NULL)
		printData(who,who->root);
}

void printData(Set who,Node *Current){
	if(Current!=NULL){
		who->printFunction(Current->data);
		printData(who,Current->left);
		printData(who,Current->right);
	}
}

void set_print(Set who,Type data){
	Node * current;
	if(who != NULL){
		while(current!=NULL){
			if(who->cmpFunction(data,current->data)<0)
				return current;
			else{
				if(who->cmpFunction(data,current->data)<0){
					current=current->left;

				}else{
					current=current->right;
				}
			}
		}
	}
	return NULL;
}

bool removeNode(Set who, Node *current){
	//Caso: es una hoja
	if(current->left==NULL && current->right==NULL){
		who->freeFunction(current);
	}else{
	}


}

Node * searchNode(Set who, Type data){
	Node preious;
	previous = current;

}


bool setRemove(Set s,Type data){
	Node * current;
	current=SearchNode(s,data);
	if(current==NULL)
		return false;
	else{

	}

}
