#include "BinarySearchTree.h"
#include <Windows.h>

int main()
{
	//��� ����
	BSTNode * Tree = BST_CreateNode(123);
	BSTNode * Node = NULL;

	//Ʈ���� ��� �߰�
	BST_InsertNode(Tree, BST_CreateNode(12));
	BST_InsertNode(Tree, BST_CreateNode(9918));
	BST_InsertNode(Tree, BST_CreateNode(424));
	BST_InsertNode(Tree, BST_CreateNode(17));
	BST_InsertNode(Tree, BST_CreateNode(3));
	
	BST_InsertNode(Tree, BST_CreateNode(98));
	BST_InsertNode(Tree, BST_CreateNode(34));
	
	BST_InsertNode(Tree, BST_CreateNode(760));
	BST_InsertNode(Tree, BST_CreateNode(317));
	BST_InsertNode(Tree, BST_CreateNode(1));

	//Ʈ�� ���
	BST_InorderPrintTree(Tree);
	printf("\n");

	printf("Removeing 98 ... \n");

	Node = BST_RemoveNode(Tree, NULL, 98);
	BST_DestroyNode(Node);

	BST_InorderPrintTree(Tree);
	printf("\n");

	printf("Inserting 111 ...\n");

	BST_InsertNode(Tree, BST_CreateNode(111));
	BST_InorderPrintTree(Tree);
	printf("\n");

	BST_DestroyTree(Tree);

	system("pause");
	return 0;

}