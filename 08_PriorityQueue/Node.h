#pragma once

typedef int ElementType; //ElementType == int

typedef struct tagNode
{
	ElementType Data;
	struct tagNode* NextNode;
	ElementType Priority;
} Node;
