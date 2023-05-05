#ifndef _knapsack_h_
	#define _knapsack_h_

	typedef struct item item;
	
	struct item
	{
		float w;
		float v;
	};

	int compare(const void* a, const void* b);
	float* knapsack(item* I, int n, float W);
#endif