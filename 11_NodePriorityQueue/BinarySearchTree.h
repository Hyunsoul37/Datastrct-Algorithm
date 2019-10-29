#pragma once
#include "Node.h"
#include <stdio.h>
#include <stdlib.h>


BSTNode* BST_CreateNode(ElementType NewData);
void BST_DestroyNode(BSTNode * Node);
void BST_DestroyTree(BSTNode * Tree);

BSTNode * BST_SearchNode(BSTNode * Tree, ElementType Target);
BSTNode * BST_SearchMinNode(BSTNode * Tree);
void BST_InsertNode(BSTNode * Tree, BSTNode * Child);
BSTNode * BST_RemoveNode(BSTNode * Tree, BSTNode * Parent, ElementType Target);
void BST_InorderPrintTree(BSTNode * Node);