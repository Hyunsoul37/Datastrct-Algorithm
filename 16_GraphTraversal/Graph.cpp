#include "Graph.h"

Graph* CreateGraph()
{
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph->Verices = NULL;
	graph->VertexCount = 0;

	return graph;
}

void DestroyGraph(Graph* G)
{
	while (G->Verices != NULL)
	{
		Vertex* Vertices = G->Verices->Next;
		DestroyVertex(G->Verices);
		G->Verices = Vertices;
	}

	free(G);
}

Vertex* CreateVertex(ElementType Data)
{
	Vertex* V = (Vertex*)malloc(sizeof(Vertex));

	V->Data = Data;
	V->Next = NULL;
	V->AdjacencyList = NULL;
	V->Visited = Notvisited;
	V->Index = -1;

	return V;
}

void DestroyVertex(Vertex* V)
{
	while (V->AdjacencyList != NULL)
	{
		Edge* Edge = V->AdjacencyList->Next;

		DestroyEdge(V->AdjacencyList);

		V->AdjacencyList = Edge;
	}

	free(V);
}

Edge* CreateEdge(Vertex* From, Vertex* Target, int Weight)
{
	Edge* E = (Edge*)malloc(sizeof(Edge));
	E->From = From;
	E->Target = Target;
	E->Next = NULL;
	E->Weight = Weight;

	return E;
}

void DestroyEdge(Edge* E)
{
	free(E);
}

void /*AddVertex*/(Graph* G, Vertex* V)
{
	Vertex* VertexList = G->Verices;

	if (VertexList == NULL)
	{
		G->Verices = V;
	}
	else
	{
		while (VertexList->Next != NULL)
			VertexList = VertexList->Next;

		VertexList->Next = V;
	}

	V->Index = G->VertexCount++;
}

void AddEdge(Vertex* V, Edge* E)
{
	if (V->AdjacencyList == NULL)
	{
		V->AdjacencyList = E;
	}
	else
	{
		Edge* AdjacenyList = V->AdjacencyList;

		while (AdjacenyList->Next != NULL)
			AdjacenyList = AdjacenyList->Next;

		AdjacenyList->Next = E;
	}
}
void PrintGraph(Graph* G)
{
	Vertex* V = NULL;
	Edge* E = NULL;

	if ((V = G->Verices) == NULL)
		return;

	while (V != NULL)
	{
		printf("%c : ", V->Data);

		if ((E = V->AdjacencyList) == NULL)
		{
			V = V->Next;
			printf("\n");
			continue;
		}

		while (E != NULL)
		{
			printf("%c[%d] ", E->Target->Data, E->Weight);
			E = E->Next;
		}

		printf("\n");

		V = V->Next;
	}
	printf("\n");

}