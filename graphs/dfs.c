#include "dfs.h"
void DFS(struct graph* graph, int vertex, int* visited) {
  struct edge* adjList = graph->nodes[vertex].first;
  struct edge* temp = adjList;

  visited[vertex] = 1;
  printf("Visited %s \n", (char*) graph->nodes[vertex].data);

  while (temp != NULL) {
    int connectedVertex = temp->node;

    if (visited[connectedVertex] == 0) {
      DFS(graph, connectedVertex, visited);
    }
    temp = temp->next;
  }
}
