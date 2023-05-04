#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "dijkstra.h"
#include "graph.h"
#include "dfs.h"
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

int main()
{
	graph *capitals = create();

	addNode(capitals, "AC");
	addNode(capitals, "AL");
	addNode(capitals, "AP");
	addNode(capitals, "AM");
	addNode(capitals, "BA");
	addNode(capitals, "CE");
	addNode(capitals, "DF");
	addNode(capitals, "ES");
	addNode(capitals, "GO");
	addNode(capitals, "MA");
	addNode(capitals, "MT");
	addNode(capitals, "MS");
	addNode(capitals, "MG");
	addNode(capitals, "PA");
	addNode(capitals, "PB");
	addNode(capitals, "PR");
	addNode(capitals, "PE");
	addNode(capitals, "PI");
	addNode(capitals, "RJ");
	addNode(capitals, "RN");
	addNode(capitals, "RS");
	addNode(capitals, "RO");
	addNode(capitals, "RR");
	addNode(capitals, "SC");
	addNode(capitals, "SP");
	addNode(capitals, "SE");
	addNode(capitals, "TO");

	/* https://www.areaseg.com/distancias.html */

	addEdge(capitals, 1415, AC, AM);
	addEdge(capitals, 515, AC, RO);
	addEdge(capitals, 593, AL, BA);
	addEdge(capitals, 251, AL, PE);
	addEdge(capitals, 291, AL, SE);
	addEdge(capitals, 539, AP, PA);
	addEdge(capitals, 1415, AM, AC);
	addEdge(capitals, 2357, AM, MT);
	addEdge(capitals, 3073, AM, PA);
	addEdge(capitals, 901, AM, RO);
	addEdge(capitals, 773, AM, RR);
	addEdge(capitals, 593, BA, AL);
	addEdge(capitals, 1056, BA, ES);
	addEdge(capitals, 1651, BA, GO);
	addEdge(capitals, 1373, BA, MG);
	addEdge(capitals, 809, BA, PE);
	addEdge(capitals, 1232, BA, PI);
	addEdge(capitals, 336, BA, SE);
	addEdge(capitals, 1437, BA, TO);
	addEdge(capitals, 668, CE, PB);
	addEdge(capitals, 773, CE, PE);
	addEdge(capitals, 592, CE, PI);
	addEdge(capitals, 515, CE, RN);
	addEdge(capitals, 639, DF, GO);
	addEdge(capitals, 1334, DF, MG);
	addEdge(capitals, 1056, ES, BA);
	addEdge(capitals, 521, ES, MG);
	addEdge(capitals, 564, ES, RJ);
	addEdge(capitals, 1651, GO, BA);
	addEdge(capitals, 639, GO, DF);
	addEdge(capitals, 877, GO, MG);
	addEdge(capitals, 841, GO, MS);
	addEdge(capitals, 929, GO, MT);
	addEdge(capitals, 821, GO, TO);
	addEdge(capitals, 578, MA, PA);
	addEdge(capitals, 439, MA, PI);
	addEdge(capitals, 1272, MA, TO);
	addEdge(capitals, 2357, MT, AM);
	addEdge(capitals, 932, MT, GO);
	addEdge(capitals, 713, MT, MS);
	addEdge(capitals, 2512, MT, PA);
	addEdge(capitals, 1456, MT, RO);
	addEdge(capitals, 1501, MT, TO);
	addEdge(capitals, 841, MS, GO);
	addEdge(capitals, 1553, MS, MG);
	addEdge(capitals, 713, MS, MT);
	addEdge(capitals, 1023, MS, PR);
	addEdge(capitals, 981, MS, SP);
	addEdge(capitals, 1373, MG, BA);
	addEdge(capitals, 1334, MG, DF);
	addEdge(capitals, 521, MG, ES);
	addEdge(capitals, 877, MG, GO);
	addEdge(capitals, 1553, MG, MS);
	addEdge(capitals, 459, MG, RJ);
	addEdge(capitals, 589, MG, SP);
	addEdge(capitals, 539, PA, AP);
	addEdge(capitals, 3073, PA, AM);
	addEdge(capitals, 578, PA, MA);
	addEdge(capitals, 2512, PA, MT);
	addEdge(capitals, 3842, PA, RR);
	addEdge(capitals, 1236, PA, TO);
	addEdge(capitals, 668, PB, CE);
	addEdge(capitals, 117, PB, PE);
	addEdge(capitals, 182, PB, RN);
	addEdge(capitals, 1023, PR, MS);
	addEdge(capitals, 304, PR, SC);
	addEdge(capitals, 404, PR, SP);
	addEdge(capitals, 251, PE, AL);
	addEdge(capitals, 809, PE, BA);
	addEdge(capitals, 773, PE, CE);
	addEdge(capitals, 117, PE, PB);
	addEdge(capitals, 1127, PE, PI);
	addEdge(capitals, 1232, PI, BA);
	addEdge(capitals, 592, PI, CE);
	addEdge(capitals, 439, PI, MA);
	addEdge(capitals, 1127, PI, PE);
	addEdge(capitals, 1128, PI, TO);
	addEdge(capitals, 564, RJ, ES);
	addEdge(capitals, 459, RJ, MG);
	addEdge(capitals, 405, RJ, SP);
	addEdge(capitals, 515, RN, CE);
	addEdge(capitals, 182, RN, PB);
	addEdge(capitals, 467, RS, SC);
	addEdge(capitals, 901, RO, AM);
	addEdge(capitals, 1456, RO, MT);
	addEdge(capitals, 2573, RO, PA);
	addEdge(capitals, 773, RR, AM);
	addEdge(capitals, 3842, RR, PA);
	addEdge(capitals, 304, SC, PR);
	addEdge(capitals, 467, SC, RS);
	addEdge(capitals, 981, SP, MG);
	addEdge(capitals, 589, SP, MS);
	addEdge(capitals, 404, SP, PR);
	addEdge(capitals, 405, SP, RJ);
	addEdge(capitals, 291, SE, AL);
	addEdge(capitals, 336, SE, BA);
	addEdge(capitals, 1437, TO, BA);
	addEdge(capitals, 821, TO, GO);
	addEdge(capitals, 1272, TO, MA);
	addEdge(capitals, 1501, TO, MT);
	addEdge(capitals, 1236, TO, PA);
	addEdge(capitals, 1128, TO, PI);
	int* visited = calloc(capitals->order, sizeof(int));
	DFS(capitals,SC,visited);
	dijkstra(capitals, SC);
}