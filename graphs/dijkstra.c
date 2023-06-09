#include <stdio.h>
#include <stdlib.h>

#include <limits.h>
#include "dijkstra.h"

#define true 1
#define false 0

struct MinHeapNode
{
	int v;
	int dist;
};

struct MinHeap
{

	int size;
	int capacity;
	int *pos;
	struct MinHeapNode **array;
};

struct MinHeapNode *newMinHeapNode(int v, int dist)
{
	struct MinHeapNode *minHeapNode = (struct MinHeapNode *)malloc(sizeof(struct MinHeapNode));
	minHeapNode->v = v;
	minHeapNode->dist = dist;
	return minHeapNode;
}

struct MinHeap *createMinHeap(int capacity)
{
	struct MinHeap *minHeap = (struct MinHeap *)malloc(sizeof(struct MinHeap));
	minHeap->pos = (int *)malloc(capacity * sizeof(int));
	minHeap->size = 0;
	minHeap->capacity = capacity;
	minHeap->array = (struct MinHeapNode **)malloc(capacity * sizeof(struct MinHeapNode *));
	return minHeap;
}

void swapMinHeapNode(struct MinHeapNode **a, struct MinHeapNode **b)
{
	struct MinHeapNode *t = *a;
	*a = *b;
	*b = t;
}

void minHeapify(struct MinHeap *minHeap, int idx)
{
	int smallest, left, right;
	smallest = idx;
	left = 2 * idx + 1;
	right = 2 * idx + 2;

	if (left < minHeap->size && minHeap->array[left]->dist < minHeap->array[smallest]->dist)
		smallest = left;

	if (right < minHeap->size && minHeap->array[right]->dist < minHeap->array[smallest]->dist)
		smallest = right;

	if (smallest != idx)
	{
		struct MinHeapNode *smallestNode = minHeap->array[smallest];
		struct MinHeapNode *idxNode = minHeap->array[idx];

		minHeap->pos[smallestNode->v] = idx;
		minHeap->pos[idxNode->v] = smallest;

		swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);

		minHeapify(minHeap, smallest);
	}
}

int isEmpty(struct MinHeap *minHeap)
{
	return minHeap->size == 0;
}

struct MinHeapNode *extractMin(struct MinHeap *minHeap)
{
	if (isEmpty(minHeap))
		return NULL;

	struct MinHeapNode *root =
		minHeap->array[0];

	struct MinHeapNode *lastNode =
		minHeap->array[minHeap->size - 1];
	minHeap->array[0] = lastNode;

	minHeap->pos[root->v] = minHeap->size - 1;
	minHeap->pos[lastNode->v] = 0;

	--minHeap->size;
	minHeapify(minHeap, 0);

	return root;
}

void decreaseKey(struct MinHeap *minHeap,
				 int v, int dist)
{

	int i = minHeap->pos[v];

	minHeap->array[i]->dist = dist;

	while (i && minHeap->array[i]->dist <
					minHeap->array[(i - 1) / 2]->dist)
	{
		minHeap->pos[minHeap->array[i]->v] =
			(i - 1) / 2;
		minHeap->pos[minHeap->array[(i - 1) / 2]->v] = i;
		swapMinHeapNode(&minHeap->array[i],
						&minHeap->array[(i - 1) / 2]);

		i = (i - 1) / 2;
	}
}

int isInMinHeap(struct MinHeap *minHeap, int v)
{
	if (minHeap->pos[v] < minHeap->size)
		return true;
	return false;
}

void printArr(graph *g, int dist[], int n)
{
	for (int i = 0; i < n; ++i)
		printf("%s \t\t %d\n", (char*)g->nodes[i].data, dist[i]);
}

void dijkstra(struct graph *graph, int src)
{

	int V = graph->order; // O(1)
	int dist[V];		  // O(1)

	struct MinHeap *minHeap = createMinHeap(V); // O(1)

	for (int v = 0; v < V; ++v)
	{
		dist[v] = INT_MAX;
		minHeap->array[v] = newMinHeapNode(v,
										   dist[v]);
		minHeap->pos[v] = v;
	} // O(V)
	minHeap->array[src] =
		newMinHeapNode(src, dist[src]);
	minHeap->pos[src] = src;
	dist[src] = 0;
	decreaseKey(minHeap, src, dist[src]);
	minHeap->size = V;

	while (!isEmpty(minHeap))
	{

		struct MinHeapNode *minHeapNode =
			extractMin(minHeap);

		int u = minHeapNode->v;

		struct edge *pCrawl =
			graph->nodes[u].first;
		while (pCrawl != NULL)
		{
			int v = pCrawl->node;
			if (isInMinHeap(minHeap, v) &&
				dist[u] != INT_MAX &&
				pCrawl->weight + dist[u] < dist[v])
			{
				dist[v] = dist[u] + pCrawl->weight;

				decreaseKey(minHeap, v, dist[v]);
			}
			pCrawl = pCrawl->next;
		}
	}

	printArr(graph, dist, V);
}