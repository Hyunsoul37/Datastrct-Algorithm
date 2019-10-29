#include "LinkedQueue.h"

int main()
{
	Node* Popped;
	LinkedQueue* Queue;

	LQ_CreateQueue(&Queue);

	LQ_Enqueue(Queue, LQ_CreateNode((char*)"abc"));
	LQ_Enqueue(Queue, LQ_CreateNode((char*)"def"));
	LQ_Enqueue(Queue, LQ_CreateNode((char*)"efg"));
	LQ_Enqueue(Queue, LQ_CreateNode((char*)"hij"));

	printf("Queue Size : %d\n", Queue->Count);

	while (LQ_IsEmpty(Queue) == 0)
	{
		Popped = LQ_Dequeue(Queue);

		printf("Dequeue : %s \n", Popped->Data);

		LQ_DestroyNode(Popped);
	}

	LQ_DestroyQueue(Queue);

	return 0;
}