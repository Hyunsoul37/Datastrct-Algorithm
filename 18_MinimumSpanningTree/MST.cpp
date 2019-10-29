//#include "MST.h"
//
//void Prim(Graph * G, Vertex * StartVertex, Graph * MST)
//{
//	int i = 0;
//
//	PQNode StartNode = { 0, StartVertex };
//	PriorityQueue* PQ = PQ_Create(10);
//
//	Vertex * CurrentVertex = NULL;
//	Edge * CurrrentEdge = NULL;
//
//	int * Weights = (int*)malloc(sizeof(int)*G->VertexCount);
//	Vertex** MSTVertices = (Vertex**)malloc(sizeof(Vertex*)*G->VertexCount);
//	Vertex** Fringes = (Vertex**)malloc(sizeof(Vertex*)*G->VertexCount);
//	Vertex** Precedences = (Vertex**)malloc(sizeof(Vertex*)*G->VertexCount);
//
//	CurrentVertex = G->Verices;
//	while (CurrentVertex != NULL)
//	{
//		Vertex* NewVertex = CreateVertex(CurrentVertex->Data);
//		AddVertex(MST, NewVertex);
//
//		Fringes[i] = NULL;
//		Precedences[i] = NULL;
//		MSTVertices[i] = NewVertex;
//		Weights[i] = MAX_WEIGHT;
//		CurrentVertex = CurrentVertex->Next;
//		i++;
//	}
//
//	PQ_Enqueue(PQ, StartNode);
//	Weights[StartVertex->Index] = 0;
//
//	while (!PQ_IsEmpty(PQ))
//	{
//		PQNode Popped;
//
//		PQ_Dequeue(PQ, &Popped);
//		CurrentVertex = (Vertex*)Popped.Data;
//
//		Fringes[CurrentVertex->Index] = CurrentVertex;
//
//		CurrrentEdge = CurrentVertex->AdjacencyList;
//		while (CurrrentEdge != NULL)
//		{
//			Vertex* TargetVertex = CurrrentEdge->Target;
//
//			if (Fringes[TargetVertex->Index] == NULL &&
//				CurrrentEdge->Weight < Weights[TargetVertex->Index])
//			{
//				PQNode NewNode = { CurrrentEdge->Weight, TargetVertex };
//				PQ_Enqueue(PQ, NewNode);
//
//				Precedences[TargetVertex->Index] = CurrrentEdge->From;
//				Weights[TargetVertex->Index] = CurrrentEdge->Weight;
//			}
//			CurrrentEdge = CurrrentEdge->Next;
//		}
//	}
//
//	for (i = 0; i < G->VertexCount; i++)
//	{
//		int FromIndex, ToIndex;
//
//		if (Precedences[i] == NULL)
//			continue;
//
//		FromIndex = Precedences[i]->Index;
//		ToIndex = i;
//
//		AddEdge(MSTVertices[FromIndex],
//			CreateEdge(MSTVertices[FromIndex], MSTVertices[ToIndex],
//				Weights[i]));
//	}
//
//	free(Fringes);
//	free(Precedences);
//	free(MSTVertices);
//	free(Weights);
//
//	PQ_Destroy(PQ);
//}
//
//void Kruskal(Graph * G, Graph * MST)
//{
//	int i;
//	Vertex* CurrentVertex = NULL;
//	Vertex** MSTVertices = (Vertex**)malloc(sizeof(Vertex*) * G->VertexCount);
//	DisjointSet** VertexSet = (DisjointSet**)malloc(sizeof(DisjointSet*) * G->VertexCount);
//	PriorityQueue* PQ = PQ_Create(10);
//	i = 0;
//	CurrentVertex = G->Verices;
//	while (CurrentVertex != NULL)
//	{
//		Edge* CurrentEdge;
//
//		VertexSet[i] = DS_MakeSet(CurrentVertex);
//		MSTVertices[i] = CreateVertex(CurrentVertex->Data);
//		AddVertex(MST, MSTVertices[i]);
//
//		CurrentEdge = CurrentVertex->AdjacencyList;
//		while (CurrentEdge != NULL)
//		{
//			PQNode NewNode = { CurrentEdge->Weight, CurrentEdge };
//			PQ_Enqueue(PQ, NewNode);
//
//			CurrentEdge = CurrentEdge->Next;
//		}
//
//		CurrentVertex = CurrentVertex->Next;
//		i++;
//	}
//
//	while (!PQ_IsEmpty(PQ))
//	{
//		Edge* CurrentEdge;
//		int FromIndex;
//		int ToIndex;
//		PQNode Popped;
//
//		PQ_Dequeue(PQ, &Popped);
//		CurrentEdge = (Edge*)Popped.Data;
//
//		FromIndex = CurrentEdge->From->Index;
//		ToIndex = CurrentEdge->Target->Index;
//
//		if (DS_FindSet(VertexSet[FromIndex]) != DS_FindSet(VertexSet[ToIndex]))
//		{
//			AddEdge(MSTVertices[FromIndex],
//				CreateEdge(MSTVertices[FromIndex], MSTVertices[ToIndex],
//					CurrentEdge->Weight));
//
//			AddEdge(MSTVertices[ToIndex],
//				CreateEdge(MSTVertices[ToIndex], MSTVertices[FromIndex],
//					CurrentEdge->Weight));
//		}
//	}
//
//	for (i = 0; i < G->VertexCount; i++)
//		DS_DestroySet(VertexSet[i]);
//
//	free(VertexSet);
//	free(MSTVertices);
//}

#include "MST.h"



// Graph StartVertex MST

// Graph �Է� �ް�,  �ʱ� ���� ����, ������ MST Graph

void Prim(Graph* G, Vertex* StartVertex, Graph* MST)

{

	int i = 0;



	PQNode         StartNode = { 0, StartVertex };	// ���� ����

	PriorityQueue* PQ = PQ_Create(10);	// �켱���� Queue ����



	Vertex*  CurrentVertex = NULL;	// ���� ����

	Edge*    CurrentEdge = NULL;	// ���� ����



	int*     Weights = (int*)malloc(sizeof(int) * G->VertexCount);	// ����ġ �����

	Vertex** MSTVertices = (Vertex**)malloc(sizeof(Vertex*) * G->VertexCount);	//  ����Ʈ�� ���� �����

	Vertex** Fringes = (Vertex**)malloc(sizeof(Vertex*) * G->VertexCount);	// ó���� ��������� 

	Vertex** Precedences = (Vertex**)malloc(sizeof(Vertex*) * G->VertexCount);	// �ش� �ε����� ������ ��� �������� �Դ��� ��� �ε������� ����� ��������





	// �ּ� ����Ʈ�� MST�� MSTVertices, Weights, Fringes, Precedences �迭�� �ʱ�ȭ �Ѵ�.

	// MST�� MSTVertices�� ���� �߰�

	// �۾��� ���� �ʱ�ȭ



	CurrentVertex = G->Vertices;	// �׷����� ������ CurrentVertex��  ���� �׷����� ���� �迭�� ���� ���� �ּҸ� CurrentVertex�� ����

	while (CurrentVertex != NULL)	// ���� ������ ������

	{

		Vertex* NewVertex = CreateVertex(CurrentVertex->Data);	// ���� ������ ����Ÿ ��(A, B, C, D, E, F..)���� ���ο� ������ �����.

		AddVertex(MST, NewVertex);	// �׷����� �ִ� ������ MST(�ּҽ���Ʈ��)�� �߰�



		Fringes[i] = NULL;	// ó���� ���� ����� �迭�� Null�� �ʱ�ȭ

		Precedences[i] = NULL;	// �ش� ������ ���� ���� �Ǿ����� �����(�� ������ ���� ������ �����)

		MSTVertices[i] = NewVertex;    // ����Ʈ�� ����� ���� �迭�� �߰�    

		Weights[i] = MAX_WEIGHT;      // ����ġ�� �ִ밪���� �ʱ�ȭ�Ͽ� ����ġ �迭�� ����  �켱���� Queue���� �켱������ ���ϱ� ���ؼ� �ϴ� �ִ� ������ ����

		CurrentVertex = CurrentVertex->Next;	// ���� ������ ���� ������ CurrentVertex�� ����.

		i++;

	}



	// 0: A, 1: B, 2: C, 3: D, 4: E, 5: F, 6: G, 7: H, 8: I



	// �켱���� Queue�� ��� �߰� StarNode(B)

	PQ_Enqueue(PQ, StartNode);	// �켱���� Queue�� StartNode(StartVertex) �߰�



	// ����ġ �迭�� StartVertex->Index === 1, Weights[1] = 0 �Է�

	Weights[StartVertex->Index] = 0;	// ���� ������ index�� �ε����� �Ͽ� ����ġ�迭�� 0�� ���





	while (!PQ_IsEmpty(PQ))		// �켱 ���� Queue�� ��ﶧ ����

	{

		PQNode  Popped;	// �켱���� Queue ��庯��



		PQ_Dequeue(PQ, &Popped);	// �켱���� Queue���� ���� ���� ���� ���� ��带 �������.(��Ʈ�� ������ ��.



		CurrentVertex = (Vertex*)Popped.Data; // �켱 ���� Queue���� �Ҿ�� ��带 CurrentVertex�� ����



		Fringes[CurrentVertex->Index] = CurrentVertex;	// CurrentVertex�� Fringes �迭�� ��� 1:B



		for (int i = 0; i < G->VertexCount; i++) {

			if (Fringes[i] != NULL) {

				printf("Fringes[%d] = %c[%d]\n", i, Fringes[i]->Data, Fringes[i]->Data);

			}

		}

		printf("===================================================\n");



		CurrentEdge = CurrentVertex->AdjacencyList;		// CurrentVertex�� �������� ����Ʈ�� CurrentEdge�� ���



		// �Էµ� ������ ��������Ʈ�� �������� ������ �ȵƴٸ�

		while (CurrentEdge != NULL)	// ���������� NULL�� �ƴϸ�

		{

			Vertex* TargetVertex = CurrentEdge->Target;	// ���� ������ ������ ������ ��´�.



			//Fringes �迭�� NULL �̶� �̾߱�� ���� �湮���� ���� ����

			// CurrentEdge->Weight < Weights[TargetVertex->Index] �� �κ��� ���� ���� ���� ���� �����̶�� �ǹ�

			if (Fringes[TargetVertex->Index] == NULL &&

				CurrentEdge->Weight < Weights[TargetVertex->Index])	// Fringes �迭�� ����� �ȵǾ� �ְų�, ���� ������ ����ġ�� Weights �迭�� ��ϵ� ����ġ���� �۴ٸ�

			{

				PQNode NewNode = { CurrentEdge->Weight, TargetVertex }; // ���ο� ��带 �����. ������ ���� ����ġ�� ������ Vertext

				PQ_Enqueue(PQ, NewNode);		// �켱���� Queue�� ����



				// �켱������ �Է��� ������ ���� ���� �Դ��� ���

				Precedences[TargetVertex->Index] = CurrentEdge->From; // Target �ε����� �������� ���� ����� ���� ��� �������� �Դ��� ���



				//  Test �ڵ�

				for (int i = 0; i < G->VertexCount; i++) {

					if (Precedences[i] != NULL) {

						printf("Precedences[%d(%c)] = %c[%d] TargetVertex[%d] = %c\n", i, i + 65, Precedences[i]->Data, Precedences[i]->Data, i, TargetVertex->Data);

					}



				}



				printf("===================================================================================================\n");



				Weights[TargetVertex->Index] = CurrentEdge->Weight;    // �켱���� Queue�� ���Ե� ������ Weight���� �����.            

			}



			CurrentEdge = CurrentEdge->Next;

		}

	}



	// �׷����� ������ ���� ��ŭ ���鼭

	for (i = 0; i < G->VertexCount; i++)

	{

		int FromIndex, ToIndex;



		// ��� �� �������� ����� �ȵǾ� ������ 

		if (Precedences[i] == NULL)

			continue;



		FromIndex = Precedences[i]->Index;

		ToIndex = i;



		// �ּ� ����

		// ������ �ΰ� �Էµ�. ������ �׷���

		AddEdge(MSTVertices[FromIndex],

			CreateEdge(MSTVertices[FromIndex], MSTVertices[ToIndex], Weights[i]));



		AddEdge(MSTVertices[ToIndex],

			CreateEdge(MSTVertices[ToIndex], MSTVertices[FromIndex], Weights[i]));

	}



	free(Fringes);

	free(Precedences);

	free(MSTVertices);

	free(Weights);



	PQ_Destroy(PQ);

}



// ũ�罺Į �˰���

void Kruskal(Graph* G, Graph* MST)

{

	int           i;

	Vertex*       CurrentVertex = NULL;	// ���� ���� �����

	Vertex**      MSTVertices = (Vertex**)malloc(sizeof(Vertex*) * G->VertexCount);	// �ּ� ���� Ʈ�� ���� �����

	DisjointSet** VertexSet = (DisjointSet**)malloc(sizeof(DisjointSet*) * G->VertexCount); // �и����� �����



	PriorityQueue* PQ = PQ_Create(10);		// �켱 ���� Queue ���� ���Ŀ� ���� ���� ���������� 



	i = 0;

	CurrentVertex = G->Vertices;	// �׷����� ������ ���



	// ���� ������ NULL�� �ƴϸ�

	while (CurrentVertex != NULL)

	{

		Edge* CurrentEdge;	// ���� �����



		VertexSet[i] = DS_MakeSet(CurrentVertex);	// ������ �����. ó������ ������ ���� ���� ������ ����� ��

		MSTVertices[i] = CreateVertex(CurrentVertex->Data);	// �� ������ �ּ� ���� ũ�� �迭�� ����

		AddVertex(MST, MSTVertices[i]);	// �ּ� ����Ʈ���� �� ������ �߰�.



		CurrentEdge = CurrentVertex->AdjacencyList;	// ���� ������ ���� ����Ʈ�� CurrentEdge�� ���



		// ���� Edge(����)�� NULL�� �ƴϸ� ����Ʈ�� ���� �����Ҷ� ����

		while (CurrentEdge != NULL)

		{

			PQNode NewNode = { CurrentEdge->Weight, CurrentEdge };	// ������ ����ġ�� 

			PQ_Enqueue(PQ, NewNode); // ����ġ�� ���� ������ ������ �켱���� Queue�� ���



			CurrentEdge = CurrentEdge->Next;	// ������ ���

		}



		CurrentVertex = CurrentVertex->Next;        // ���� �������� ���� �����ϰ� ������ �� �켱���� Queue�� ���

		i++;

	}



	// �켱���� Queue�� ��������

	while (!PQ_IsEmpty(PQ))

	{

		Edge*  CurrentEdge;	// ���� ���� ���

		int    FromIndex;	// ���� ����

		int    ToIndex;	// ��� ����

		PQNode Popped;		// �켱���� Queue���� ���� ���� ���� ������ ������ ���



		PQ_Dequeue(PQ, &Popped);	// ���� ���� ������ ������

		CurrentEdge = (Edge*)Popped.Data;	// ������ ���



		// �ҷ��� ������ ������ ���

		printf("%c - %c : %d\n",

			CurrentEdge->From->Data,

			CurrentEdge->Target->Data,

			CurrentEdge->Weight);



		// ������ ���� ���踦 ���

		FromIndex = CurrentEdge->From->Index;

		ToIndex = CurrentEdge->Target->Index;



		// ������ �������� ������� �и�����

		// DS_FindeSet�� ���Ұ� � ���տ� �����ִ��� �˷��ݴϴ�.

		// �� ������ �ٸ� ���տ� ���� ���� ������

		// �� ������ ���� ���I�� ���� ������ Cycle�� ����� ������ �ּ� ����Ʈ���� �������� �ʽ��ϴ�.

		if (DS_FindSet(VertexSet[FromIndex]) != DS_FindSet(VertexSet[ToIndex]))

		{

			// �ּ� ����Ʈ���� ������ �߰�

			// ����⼺ Ʈ��

			AddEdge(MSTVertices[FromIndex],

				CreateEdge(MSTVertices[FromIndex],

					MSTVertices[ToIndex],

					CurrentEdge->Weight));



			AddEdge(MSTVertices[ToIndex],

				CreateEdge(MSTVertices[ToIndex],

					MSTVertices[FromIndex],

					CurrentEdge->Weight));



			// ������ ������ ���� �������� ��ħ.

			DS_UnionSet(VertexSet[FromIndex], VertexSet[ToIndex]);

		}

	}



	for (i = 0; i < G->VertexCount; i++)

		DS_DestroySet(VertexSet[i]);



	free(VertexSet);

	free(MSTVertices);

}