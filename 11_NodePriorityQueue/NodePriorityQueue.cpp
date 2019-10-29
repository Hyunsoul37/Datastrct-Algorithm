#include "NodePriorityQueue.h"

BSTNode * CreateNode(ElementType NewData, ElementType Priority)
{
	BSTNode * NewNode = (BSTNode*)malloc(sizeof(BSTNode));
	NewNode->Left = NULL;
	NewNode->Right = NULL;
	NewNode->Parent = NULL;

	NewNode->Data = NewData;
	NewNode->Priority = Priority;

	return NewNode;
}

void DestroyNode(BSTNode * Node)
{
	free(Node);
}

void DestroyTree(BSTNode * Tree)
{
	if (Tree->Right != NULL)
		DestroyTree(Tree->Right);

	if (Tree->Left != NULL)
		DestroyTree(Tree->Left);

	Tree->Left = NULL;
	Tree->Right = NULL;

	DestroyNode(Tree);
}


void InsertNode(BSTNode * Tree, BSTNode * Child)
{
	if (Tree->Priority < Child->Priority)
	{
		if (Tree->Right == NULL)
		{
			Tree->Right = Child;
			Child->Parent = Tree;
		}
			
		else
			InsertNode(Tree->Right, Child);
	}
	else if (Tree->Priority > Child->Priority)
	{
		if (Tree->Left == NULL)
		{
			Tree->Left = Child;
			Child->Parent = Tree;
		}
		else
			InsertNode(Tree->Left, Child);
	}
}

BSTNode * SearchNode(BSTNode * Tree, ElementType Priority)
{
	if (Tree == NULL)
		return NULL;

	if (Tree->Priority == Priority)
		return Tree;
	else if (Tree->Priority > Priority)
		return SearchNode(Tree->Left, Priority);
	else
		return SearchNode(Tree->Right, Priority);
}

BSTNode * SearchMinNode(BSTNode * Tree)
{
	if (Tree == NULL)
		return NULL;

	if (Tree->Left == NULL)
		return Tree;
	else
		return SearchMinNode(Tree->Left);
}

BSTNode * RemoveNode(BSTNode * Tree, BSTNode * Parent, ElementType Priority)
{
	BSTNode * Removed = NULL;

	if (Tree == NULL)
		return NULL;

	if (Tree->Priority > Priority)
		Removed = RemoveNode(Tree->Left, Tree, Priority);
	else if (Tree->Data < Priority)
		Removed = RemoveNode(Tree->Right, Tree, Priority);
	else
	{
		Removed = Tree;

		if (Tree->Left == NULL && Tree->Right == NULL)
		{
			if (Parent->Left == Tree)
				Parent->Left = NULL;
			else
				Parent->Right = NULL;
		}
		else
		{
			if (Tree->Left != NULL && Tree->Right != NULL)
			{
				BSTNode* MinNode = SearchMinNode(Tree->Right);
				MinNode = RemoveNode(Tree, NULL, MinNode->Priority);
				Tree->Priority = MinNode->Priority;
			}
			else
			{
				BSTNode * Temp = NULL;

				if (Tree->Left != NULL)
					Temp = Tree->Left;
				else
					Temp = Tree->Right;

				if (Parent->Left == Tree)
					Parent->Left = Temp;
				else
					Parent->Right = Temp;
			}

		}
	}
	return Removed;
}
void InorderPrintTree(BSTNode * Node)
{
	if (Node == NULL)
		return;

	InorderPrintTree(Node->Left);

	printf("priority : %d  Data : %d \n", Node->Priority, Node->Data);

	InorderPrintTree(Node->Right);
}