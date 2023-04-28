#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 1000

typedef struct Edge
{
	int dest;
	int weight;
	struct Edge *next;
} Edge_t;

typedef struct Graph
{
	Edge_t *adjList[MAX_VERTICES];
	int numVertices;
} Graph_t;

typedef struct PriorityQueue
{
	int vertex;
	int priority;
} PriorityQueue_t;

int isEmpty(PriorityQueue_t *pq)
{
	return pq->vertex == -1;
}

void enqueue(PriorityQueue_t *pq, int vertex, int priority)
{
	if (pq->vertex == -1)
	{
		pq->vertex = vertex;
		pq->priority = priority;
		return;
	}

	int i = 0;
	while (i < MAX_VERTICES && pq->priority < priority)
	{
		i++;
	}
	if (i == MAX_VERTICES)
	{
		return;
	}

	for (int j = MAX_VERTICES - 1; j > i; j--)
	{
		pq[j] = pq[j - 1];
	}

	pq[i].vertex = vertex;
	pq[i].priority = priority;
}

void dequeue(PriorityQueue_t *pq)
{
	if (pq->vertex == -1)
	{
		return;
	}

	for (int i = 0; i < MAX_VERTICES - 1; i++)
	{
		pq[i] = pq[i + 1];
	}
	pq[MAX_VERTICES - 1].vertex = -1;
	pq[MAX_VERTICES - 1].priority = INT_MAX;
}

void init(Graph_t *graph)
{
	graph->numVertices = 0;
	for (int i = 0; i < MAX_VERTICES; i++)
	{
		graph->adjList[i] = NULL;
	}
}

void addEdge(Graph_t *graph, int src, int dest, int weight)
{
	Edge_t *edge = (Edge_t *)malloc(sizeof(Edge_t));
	edge->dest = dest;
	edge->weight = weight;
	edge->next = graph->adjList[src];
	graph->adjList[src] = edge;
}

void dijkstra(Graph_t *graph, int src, int *dist)
{
	PriorityQueue_t pq = {-1, INT_MAX};
	dist[src] = 0;
	enqueue(&pq, src, 0);
	while (!isEmpty(&pq))
	{
		int u = pq.vertex;
		dequeue(&pq);
		for (Edge_t *edge = graph->adjList[u]; edge != NULL; edge = edge->next)
		{
			int v = edge->dest;
			int w = edge->weight;
			if (dist[v] > dist[u] + w)
			{
				dist[v] = dist[u] + w;
				enqueue(&pq, v, dist[v]);
			}
		}
	}
}

int main()
{
	Graph_t graph;
	init(&graph);

	// Add edges to the graph
	addEdge(&graph, 0, 1, 4);
	addEdge(&graph, 0, 7, 8);
	addEdge(&graph, 1, 2, 8);
	addEdge(&graph, 1, 7, 11);
	addEdge(&graph, 2, 3, 7);
	addEdge(&graph, 2, 8, 2);
	addEdge(&graph, 2, 5, 4);
	addEdge(&graph, 3, 4, 9);
	addEdge(&graph, 3, 5, 14);
	addEdge(&graph, 4, 5, 10);
	addEdge(&graph, 5, 6, 2);
	addEdge(&graph, 6, 7, 1);
	addEdge(&graph, 6, 8, 6);
	addEdge(&graph, 7, 8, 7);

	// Run Dijkstra's algorithm on the graph
	int dist[MAX_VERTICES];
	for (int i = 0; i < MAX_VERTICES; i++)
	{
		dist[i] = INT_MAX;
	}
	dijkstra(&graph, 0, dist);

	// Print the shortest distances from the source vertex
	for (int i = 0; i < graph.numVertices; i++)
	{
		printf("Vertex %d: %d\n", i, dist[i]);
	}

	return 0;
}
