#include "BinarySearchTree.h"
#include "NodePriorityQueue.h"
#include <Windows.h>

int main()
{
	//노드 생성
	BSTNode * Tree = CreateNode(123, 1);
	BSTNode * Node = NULL;

	//트리에 노드 추가
	BST_InsertNode(Tree, CreateNode(12, 2));
	BST_InsertNode(Tree, CreateNode(9918, 3));
	BST_InsertNode(Tree, CreateNode(424, 5));
	BST_InsertNode(Tree, CreateNode(17, 7));
	BST_InsertNode(Tree, CreateNode(3, 9));

	BST_InsertNode(Tree, CreateNode(98, 4));
	BST_InsertNode(Tree, CreateNode(34, 8));

	BST_InsertNode(Tree, CreateNode(760, 6));
	BST_InsertNode(Tree, CreateNode(317, 11));
	BST_InsertNode(Tree, CreateNode(1, 12));

	//트리 출력
	InorderPrintTree(Tree);
	printf("\n");

	printf("Removeing Priority 1 ... \n");

	Node = RemoveNode(Tree, NULL, 1);
	DestroyNode(Node);

	InorderPrintTree(Tree);
	printf("\n");

	printf("Inserting 111 ...\n");

	InsertNode(Tree, CreateNode(111, 111));
	InorderPrintTree(Tree);
	printf("\n");

	DestroyTree(Tree);

	system("pause");
	return 0;

}