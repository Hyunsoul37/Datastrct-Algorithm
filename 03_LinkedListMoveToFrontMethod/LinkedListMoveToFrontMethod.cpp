#include "LinkedListMoveToFrontMethod.h"


void SearchNodeToHead(Node * Head)
{
	return;
}

void InsertData(Node * Head)
{
	int i = 0;
	Node * Current = Head;

	while (Current != NULL)
	{
		Current->Data = i + 1;
		Current = Current->NextNode;
		
		++i;
	}
}

void PrintList(Node * Head)
{
	Node * Current = Head;

	while (Current != NULL)
	{
		cout << Current->Data << " ";
		Current = Current->NextNode;
	}
}

Node * FindData(Node * Head, int FindData)
{
	int i = 0;
	Node * Find = Head;

	while (Find->NextNode != NULL)
	{
		if (Find->Data == FindData)
		{
			break;
		}
		Find = Find->NextNode;
	}

	//cout << Find->Data << endl;

	return Find;
}

void MoveToFront(Node * Head, Node * Find)
{
	Node * Prev = Head;
	Node * FindNode = Find;
	tagNode * Address;

	if (Head->Data == Find->Data)
		return;

	while (Prev->NextNode != FindNode)
	{
		Prev = Prev->NextNode;
	}

	Address = FindNode->NextNode;
	FindNode->NextNode = NULL;
	Prev->NextNode = Address;
}