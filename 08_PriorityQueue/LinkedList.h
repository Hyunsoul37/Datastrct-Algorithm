#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <stdio.h>
#include <stdlib.h>

Node* SLL_CreateNode(ElementType NewData, int Priority);
void SLL_DestroyNode(Node* Node);
void SLL_AppendNode(Node** Head, Node* NewNode);
void SLL_InsertAfter(Node* Current, Node* NewNode);
void SLL_InsertNewHead(Node** Head, Node* NewHead);
void SLL_RemoveNode(Node** Head, Node* Remove);
Node* SLL_GetNodeAt(Node* Head, int Location);
int SLL_GetNodeCount(Node* Head);

#endif //헤더파일의 중복을 막기위해
