#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H

#include <cstdio>
#include <cstdlib>

typedef int ElementType;

typedef struct tagNode
{
	ElementType Data;
} Node;

typedef struct tagCircularQueue
{
	int Capacity;
	int Front;
	int Rear;

	Node* Nodes;
} CircularQueue;

void CQ_CreateQueue(CircularQueue** Queue, int Capacity);
void CQ_DestoryQueue(CircularQueue* Queue);
void CQ_Enqueue(CircularQueue* Queue, ElementType Data);
ElementType CQ_Dequeue(CircularQueue* Queue);
int CQ_GetSize(CircularQueue* Queue);
int CQ_IsEmpty(CircularQueue* Queue);
int CQ_IsFull(CircularQueue* Queue);
#endif // !CIRCULARQUEUE_H
