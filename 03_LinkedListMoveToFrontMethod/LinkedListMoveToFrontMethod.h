#pragma once
#include "Node.h"
#include <iostream>
#include <cstdlib>
using namespace std;

void SearchNodeToHead(Node * Head);
void InsertData(Node * Head);
void PrintList(Node * Head);
Node * FindData(Node * Head, int FindData);
void MoveToFront(Node * Head, Node * Find);