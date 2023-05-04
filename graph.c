#include "graph.h"

graph* create()
{
	graph *descriptor = (graph *) malloc(sizeof(graph));
	
	descriptor -> nodes = calloc(1, sizeof(node));
	descriptor -> order = 0;

	return descriptor;
}

void addNode(graph *descriptor, void* data)
{
	descriptor -> order += 1;
	descriptor -> nodes = (node *) realloc(descriptor -> nodes, descriptor -> order * sizeof(node));
	descriptor -> nodes[descriptor -> order - 1].data = data;
	descriptor -> nodes[descriptor -> order - 1].degree = 0;
	descriptor -> nodes[descriptor -> order - 1].first = NULL;
}

void addEdge(graph *descriptor, int weight, int head, int tail)
{
	edge *newEdge = (edge *) calloc(1,sizeof(edge));
	newEdge -> weight = weight;
	newEdge -> node = tail;
	newEdge -> next = NULL;

	edge *last = descriptor -> nodes[head].first;

	if(last)
	{
		for(; last -> next != NULL; last = last -> next);
		last -> next = newEdge;
	}

	else
	{
		descriptor -> nodes[head].first = newEdge;
	}
}

void destroy(graph *descriptor)
{
	if(descriptor -> nodes)
	{
		for(int i = 0; i < descriptor -> order; i++)
		{
			edge *navigator = descriptor -> nodes[i].first;

			while(navigator)
			{
				edge *previous = navigator;
				navigator = navigator -> next;
				free(previous);
			}
		}

		free(descriptor -> nodes);
	}

	free(descriptor);
}