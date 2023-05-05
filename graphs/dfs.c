#include "dfs.h"

void dfs(struct graph* graph, int source, int* visited)
{
	edge* adjList = graph -> nodes[source].first;
	edge* temp = adjList;

	visited[source] = 1;
	printf("Visited %s \n", (char*) graph -> nodes[source].data);

	while(temp != NULL)
	{
		int connectedVertex = temp->node;
		if(visited[connectedVertex] == 0)
			dfs(graph, connectedVertex, visited);
		temp = temp -> next;
  }
}