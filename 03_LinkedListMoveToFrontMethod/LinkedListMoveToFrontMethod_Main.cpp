#include "LinkedListMoveToFrontMethod.h"
#include "LinkedList.h"
#include <iostream>
using namespace std;

int main()
{
	int	i = 0;
	int Count = 0;
	int CreateNodeNum;
	int FindNum;
	Node* List = NULL;
	Node* FindNode = NULL;
	Node* NewNode = NULL;

	cin >> CreateNodeNum;

	for (i = 0; i < CreateNodeNum; i++)
	{
		NewNode = SLL_CreateNode(i);
		SLL_AppendNode(&List, NewNode);
	}

	
	InsertData(List);
	
	PrintList(List);

	cout << endl;

	while (1)
	{
		cin >> FindNum;
		FindNode = FindData(List, FindNum);

		//����� �� ���� �Է¼��ڰ� ũ�� break
		if (FindNum > SLL_GetNodeCount(List))
			break;
		
		MoveToFront(List, FindNode);	//�O�� ����� �����ּҸ� �̾��ִ� �Լ�
		SLL_InsertNewHead(&List, FindNode);
		PrintList(List);
		cout << endl;

	}

	SLL_DestroyNode(List);

}
