#include "LinkedList.h"

Node* SLL_CreateNode(ElementType NewData, int Priority)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = NewData;
	NewNode->Priority = Priority;
	NewNode->NextNode = NULL;

	return NewNode;
}

void SLL_DestroyNode(Node* Node)
{
	free(Node);
}

void SLL_AppendNode(Node** Head, Node* NewNode)
{
	Node * Prev;
	if (*(Head) == NULL)
	{
		*Head = NewNode;
	}
	else {
		Node* Current = (*Head);
		Prev = *Head;
		if (Current == *Head)
		{
			if (Current->Priority > NewNode->Priority)
			{
				SLL_InsertNewHead(Head, NewNode);
				return;
			}
		}
		
		while (Current->NextNode != NULL)
		{
			if (Current->Priority > NewNode->Priority)
			{
				SLL_InsertAfter(Current, NewNode);
				return;
			}
			else if (Current->Priority <= NewNode->Priority)
			{
				SLL_InsertAfter(Prev, NewNode);
			}
			Prev = Current;
			Current = Current->NextNode;
			
		}
		Current->NextNode = NewNode;
	}
}

void SLL_InsertAfter(Node * Current, Node* NewNode)
{
	NewNode->NextNode = Current->NextNode;
	Current->NextNode = NewNode;
}

void SLL_InsertNewHead(Node** Head, Node* NewHead)
{
	if (*Head == NULL)
	{
		(*Head) = NewHead;
	}
	else {
		NewHead->NextNode = (*Head);
		(*Head) = NewHead;
	}
}

void SLL_RemoveNode(Node** Head, Node* Remove)
{
	if (*Head == Remove)
	{
		*Head = Remove->NextNode;
	}
	else {
		Node* Current = *Head;
		while (Current != NULL && Current->NextNode != Remove)
		{
			Current = Current->NextNode;
		}

		if (Current != NULL)
			Current->NextNode = Remove->NextNode;
	}
}

Node* SLL_GetNodeAt(Node* Head, int Location)
{
	Node* Current = Head;

	while (Current != NULL && (--Location) >= 0)
	{
		Current = Current->NextNode;
	}

	return Current;
}
int SLL_GetNodeCount(Node* Head)
{
	int Count = 0;
	Node* Current = Head;

	while (Current != NULL)
	{
		Current = Current->NextNode;
		Count++;
	}

	return Count;
}