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

// Graph 입력 받고,  초기 시작 정점, 저장할 MST Graph

void Prim(Graph* G, Vertex* StartVertex, Graph* MST)

{

	int i = 0;



	PQNode         StartNode = { 0, StartVertex };	// 시작 정점

	PriorityQueue* PQ = PQ_Create(10);	// 우선순위 Queue 생성



	Vertex*  CurrentVertex = NULL;	// 현재 정점

	Edge*    CurrentEdge = NULL;	// 현재 간선



	int*     Weights = (int*)malloc(sizeof(int) * G->VertexCount);	// 가중치 저장용

	Vertex** MSTVertices = (Vertex**)malloc(sizeof(Vertex*) * G->VertexCount);	//  신장트리 정점 저장용

	Vertex** Fringes = (Vertex**)malloc(sizeof(Vertex*) * G->VertexCount);	// 처리된 정점저장용 

	Vertex** Precedences = (Vertex**)malloc(sizeof(Vertex*) * G->VertexCount);	// 해당 인덱스의 정점이 어느 정점에서 왔는지 기록 인덱스에서 저장된 정점으로





	// 최소 신장트리 MST와 MSTVertices, Weights, Fringes, Precedences 배열을 초기화 한다.

	// MST와 MSTVertices에 정점 추가

	// 작업을 위한 초기화



	CurrentVertex = G->Vertices;	// 그래프의 정점을 CurrentVertex에  연결 그래프의 정점 배열의 선두 번지 주소를 CurrentVertex에 저장

	while (CurrentVertex != NULL)	// 현재 정점이 있으면

	{

		Vertex* NewVertex = CreateVertex(CurrentVertex->Data);	// 현재 정점의 데이타 값(A, B, C, D, E, F..)으로 새로운 정점을 만든다.

		AddVertex(MST, NewVertex);	// 그래프에 있는 정점을 MST(최소신장트리)에 추가



		Fringes[i] = NULL;	// 처리된 정점 저장용 배열을 Null로 초기화

		Precedences[i] = NULL;	// 해당 정점이 어디와 연결 되었는지 저장용(각 정점의 연결 정보를 기록함)

		MSTVertices[i] = NewVertex;    // 신장트리 저장용 정점 배열에 추가    

		Weights[i] = MAX_WEIGHT;      // 가중치를 최대값으로 초기화하여 가중치 배열에 저장  우선순위 Queue에서 우선순위를 정하기 위해서 일단 최대 값으로 설정

		CurrentVertex = CurrentVertex->Next;	// 현재 정점의 다음 정점을 CurrentVertex에 저장.

		i++;

	}



	// 0: A, 1: B, 2: C, 3: D, 4: E, 5: F, 6: G, 7: H, 8: I



	// 우선순위 Queue에 노드 추가 StarNode(B)

	PQ_Enqueue(PQ, StartNode);	// 우선순위 Queue에 StartNode(StartVertex) 추가



	// 가중치 배열의 StartVertex->Index === 1, Weights[1] = 0 입력

	Weights[StartVertex->Index] = 0;	// 시작 정점의 index을 인덱스로 하여 가중치배열에 0을 기록





	while (!PQ_IsEmpty(PQ))		// 우선 순위 Queue가 비울때 까지

	{

		PQNode  Popped;	// 우선순위 Queue 노드변수



		PQ_Dequeue(PQ, &Popped);	// 우선순위 Queue에서 제일 낮은 값을 가진 노드를 가지고옴.(루트를 가지고 옴.



		CurrentVertex = (Vertex*)Popped.Data; // 우선 순위 Queue에서 불어온 노드를 CurrentVertex로 설정



		Fringes[CurrentVertex->Index] = CurrentVertex;	// CurrentVertex를 Fringes 배열에 기록 1:B



		for (int i = 0; i < G->VertexCount; i++) {

			if (Fringes[i] != NULL) {

				printf("Fringes[%d] = %c[%d]\n", i, Fringes[i]->Data, Fringes[i]->Data);

			}

		}

		printf("===================================================\n");



		CurrentEdge = CurrentVertex->AdjacencyList;		// CurrentVertex의 인접간선 리스트를 CurrentEdge에 기록



		// 입력된 정점의 간선리스트에 마지막에 도달이 안됐다면

		while (CurrentEdge != NULL)	// 인접간선이 NULL이 아니면

		{

			Vertex* TargetVertex = CurrentEdge->Target;	// 현재 간석의 목적지 정점을 얻는다.



			//Fringes 배열이 NULL 이란 이야기는 아직 방문하지 않은 정점

			// CurrentEdge->Weight < Weights[TargetVertex->Index] 이 부분은 아직 포함 되지 않은 간선이라는 의미

			if (Fringes[TargetVertex->Index] == NULL &&

				CurrentEdge->Weight < Weights[TargetVertex->Index])	// Fringes 배열에 기록이 안되어 있거나, 현재 간선의 가중치가 Weights 배열에 기록된 가중치보다 작다면

			{

				PQNode NewNode = { CurrentEdge->Weight, TargetVertex }; // 새로운 노드를 만든다. 현재의 정점 가중치와 목적지 Vertext

				PQ_Enqueue(PQ, NewNode);		// 우선순위 Queue에 삽입



				// 우선순위에 입력한 정점이 어디로 부터 왔는지 기록

				Precedences[TargetVertex->Index] = CurrentEdge->From; // Target 인덱스를 정점으로 보고 저장된 값은 어느 정점에서 왔는지 기록



				//  Test 코드

				for (int i = 0; i < G->VertexCount; i++) {

					if (Precedences[i] != NULL) {

						printf("Precedences[%d(%c)] = %c[%d] TargetVertex[%d] = %c\n", i, i + 65, Precedences[i]->Data, Precedences[i]->Data, i, TargetVertex->Data);

					}



				}



				printf("===================================================================================================\n");



				Weights[TargetVertex->Index] = CurrentEdge->Weight;    // 우선순위 Queue에 포함된 간선의 Weight값을 기록함.            

			}



			CurrentEdge = CurrentEdge->Next;

		}

	}



	// 그래프의 정점의 갯수 만큼 돌면서

	for (i = 0; i < G->VertexCount; i++)

	{

		int FromIndex, ToIndex;



		// 어디서 온 정점인지 기록이 안되어 있으면 

		if (Precedences[i] == NULL)

			continue;



		FromIndex = Precedences[i]->Index;

		ToIndex = i;



		// 최소 신장

		// 정점이 두개 입력됨. 무방향 그래프

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



// 크루스칼 알고리즘

void Kruskal(Graph* G, Graph* MST)

{

	int           i;

	Vertex*       CurrentVertex = NULL;	// 현재 정점 저장용

	Vertex**      MSTVertices = (Vertex**)malloc(sizeof(Vertex*) * G->VertexCount);	// 최소 신장 트리 정점 저장용

	DisjointSet** VertexSet = (DisjointSet**)malloc(sizeof(DisjointSet*) * G->VertexCount); // 분리집합 저장용



	PriorityQueue* PQ = PQ_Create(10);		// 우선 순위 Queue 간선 정렬용 가장 낮은 간선순으로 



	i = 0;

	CurrentVertex = G->Vertices;	// 그래프의 정점을 기록



	// 현재 정점이 NULL이 아니면

	while (CurrentVertex != NULL)

	{

		Edge* CurrentEdge;	// 간선 저장용



		VertexSet[i] = DS_MakeSet(CurrentVertex);	// 집합을 만든다. 처음에는 각각에 정점 별로 집합이 만들어 짐

		MSTVertices[i] = CreateVertex(CurrentVertex->Data);	// 각 정점을 최소 신장 크리 배열에 저장

		AddVertex(MST, MSTVertices[i]);	// 최소 신장트리에 각 정점을 추가.



		CurrentEdge = CurrentVertex->AdjacencyList;	// 현재 정점의 간선 리스트를 CurrentEdge에 기록



		// 현재 Edge(간선)이 NULL이 아니면 리스트에 끝에 도달할때 까지

		while (CurrentEdge != NULL)

		{

			PQNode NewNode = { CurrentEdge->Weight, CurrentEdge };	// 간선의 가중치와 

			PQ_Enqueue(PQ, NewNode); // 가중치를 정렬 값으로 간선을 우선순위 Queue에 기록



			CurrentEdge = CurrentEdge->Next;	// 간선을 기록

		}



		CurrentVertex = CurrentVertex->Next;        // 다음 정점으로 값을 변경하고 간선을 다 우선순위 Queue에 기록

		i++;

	}



	// 우선순위 Queue가 빌때까지

	while (!PQ_IsEmpty(PQ))

	{

		Edge*  CurrentEdge;	// 현재 간선 기록

		int    FromIndex;	// 어디로 부터

		int    ToIndex;	// 어디 까지

		PQNode Popped;		// 우선순위 Queue에서 가장 낮은 값을 저장할 변수를 기록



		PQ_Dequeue(PQ, &Popped);	// 가장 낮은 간선을 가져옴

		CurrentEdge = (Edge*)Popped.Data;	// 간선을 기록



		// 불러온 간선의 정보를 출력

		printf("%c - %c : %d\n",

			CurrentEdge->From->Data,

			CurrentEdge->Target->Data,

			CurrentEdge->Weight);



		// 간선의 연결 관계를 기록

		FromIndex = CurrentEdge->From->Index;

		ToIndex = CurrentEdge->Target->Index;



		// 각각의 정점으로 만들어진 분리집합

		// DS_FindeSet은 원소가 어떤 집합에 속해있는지 알려줍니다.

		// 두 정점이 다른 집합에 속해 있지 않으면

		// 두 정점이 같은 집핱에 속해 있으면 Cycle을 만들기 때문에 최소 신장트리에 포함하지 않습니다.

		if (DS_FindSet(VertexSet[FromIndex]) != DS_FindSet(VertexSet[ToIndex]))

		{

			// 최소 신장트리에 간선을 추가

			// 비방향성 트리

			AddEdge(MSTVertices[FromIndex],

				CreateEdge(MSTVertices[FromIndex],

					MSTVertices[ToIndex],

					CurrentEdge->Weight));



			AddEdge(MSTVertices[ToIndex],

				CreateEdge(MSTVertices[ToIndex],

					MSTVertices[FromIndex],

					CurrentEdge->Weight));



			// 간선의 정점을 같은 집합으로 합침.

			DS_UnionSet(VertexSet[FromIndex], VertexSet[ToIndex]);

		}

	}



	for (i = 0; i < G->VertexCount; i++)

		DS_DestroySet(VertexSet[i]);



	free(VertexSet);

	free(MSTVertices);

}