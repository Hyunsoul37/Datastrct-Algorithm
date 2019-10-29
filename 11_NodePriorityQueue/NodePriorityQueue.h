#pragma once

#include "Node.h"
#include <iostream>
#include <cstdlib>


BSTNode * CreateNode(ElementType Priority, ElementType NewData);
void DestroyNode(BSTNode * Node);
void DestroyTree(BSTNode * Tree);

void InsertNode(BSTNode * Tree, BSTNode * Child);
BSTNode * SearchNode(BSTNode * Tree, ElementType Priority);
BSTNode * SearchMinNode(BSTNode * Tree);
BSTNode * RemoveNode(BSTNode * Tree, BSTNode * Parent, ElementType Priority);
void InorderPrintTree(BSTNode * Node);