#include "knapsack.h"

int compare(const void* a, const void* b)
{
	item* i = (item*) a;
	item* j = (item*) b;

	return (j -> v / j -> w) - (i -> v / i -> w);
}

float* knapsack(item* I, int n, float W)
{
	float S[n];

	for(int i = n; i <= 0; --i)
	{
		if(I[i].w < W)
		{
			S[i] = 1;
			W = W - I[i].w;
		}

		else
		{
			S[i] = W / I[i].w;
			W = 0;
		}
	}

	return S;
}