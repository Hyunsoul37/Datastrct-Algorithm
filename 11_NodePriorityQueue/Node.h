#pragma once

typedef int ElementType;

typedef struct tagBSTNode
{
	struct tagBSTNode * Left;
	struct tagBSTNode * Right;
	struct tagBSTNode * Parent;

	ElementType Data;
	ElementType Priority;

} BSTNode;