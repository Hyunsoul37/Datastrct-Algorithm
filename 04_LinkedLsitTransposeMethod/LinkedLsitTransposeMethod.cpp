#include "LinkedLsitTransposeMethod.h"

void InsertData(Node * Head)
{
	Node * NewNode = Head;
	int i = 1;
	while (NewNode != NULL)
	{
		NewNode->Data = i;
		NewNode = NewNode->NextNode;
		i++;
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
Node * FindData(Node * Head, int Data)
{
	Node * FindNode = Head;
	int i = 1;

	while (FindNode->NextNode != NULL)
	{
		if (FindNode->Data == Data)
		{
			break;
		}
		FindNode = FindNode->NextNode;
	}

	return FindNode;
}
void MoveTranspose(Node* Head, Node * FindNode)
{
	Node * PrevNode = Head;
	tagNode * Address18;
	tagNode * Address19;
	tagNode * Address20;

	while (PrevNode->NextNode != NULL)
	{
		if (PrevNode->NextNode->NextNode == FindNode)
		{
			break;
		}
		PrevNode = PrevNode->NextNode;
	}

	Address18 = PrevNode->NextNode;
	Address19 = PrevNode->NextNode->NextNode;
	Address20 = FindNode->NextNode;

	PrevNode->NextNode->NextNode = Address20;
	PrevNode->NextNode = Address19;
	FindNode->NextNode = Address18;

}
