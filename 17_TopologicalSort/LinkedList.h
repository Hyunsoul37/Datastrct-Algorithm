#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Graph.h"
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType; //ElementType == int

typedef struct tagNode
{
	Vertex Data;
	struct tagNode* NextNode;
} Node;

Node* SLL_CreateNode(Vertex* NewData);
void SLL_DestroyNode(Node* Node);
void SLL_AppendNode(Node** Head, Node* NewNode);
void SLL_InsertAfter(Node* Current, Node* NewNode);
void SLL_InsertNewHead(Node ** Head, Node * NewHead);
void SLL_RemoveNode(Node** Head, Node* Remove);
Node* SLL_GetNodeAt(Node* Head, int Location);
int SLL_GetNodeCount(Node* Head);

#endif //헤더파일의 중복을 막기위해
