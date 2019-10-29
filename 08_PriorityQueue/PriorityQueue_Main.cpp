#include "LinkedList.h"
#include "PrioriytQueue.h"
using namespace std;

int main()
{
	int	i = 0;
	int Count = 0;
	int select, priority, data;
	Node* List = NULL;
	Node* Current = NULL;
	Node* NewNode = NULL;

	while (true)
	{
		printf("Enter command number : \n");
		printf("(1) Create a Node, (2) Remove a Node, (3) Search a Node\n");
		printf("(4) Display List, (5) quit\n");
		printf("command number : ");
		scanf("%d", &select);

		switch (select)
		{
		case 1:
			printf("Enter Node Data : ");
			scanf("%d", &data);
			printf("Enter Priority : ");
			scanf("%d", &priority);

			NewNode = SLL_CreateNode(data, priority);

			SLL_AppendNode(&List, NewNode);
			printf("\n");
			break;
		case 2:

		case 3:
		case 4:
			Current = List;

			while (Current != NULL)
			{
				printf("Priority : %d, Data : %d \n", Current->Priority, Current->Data);
				Current = Current->NextNode;
			}
			printf("\n");
			break;
		case 5:
			break;
		}
	}
	

	return 0;
}