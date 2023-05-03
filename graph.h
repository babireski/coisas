#ifndef _graph_h_
	#define _graph_h_

	#include <stdlib.h>

	typedef struct edge
	{
		int node;
		int weight;
		edge* next;
	}
	edge;

	typedef struct node
	{
		edge* first;
		void* data;
		int degree;
	}
	node;
	
	typedef struct graph
	{
		node* nodes;
		int order;
	}
	graph;

	graph* create();
	void addNode(graph *descriptor, void* data);
	void addEdge(graph *descriptor, int weight, int head, int tail);
	void destroy(graph *descriptor);
#endif