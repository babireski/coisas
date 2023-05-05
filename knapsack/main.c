#include "main.h"

int main()
{
	a();
	printf("\n");
	b();

	return 0;
}

void a()
{
	item a = {a.v = 40, a.w = 840};
	item b = {b.v = 30, b.w = 600};
	item c = {c.v = 20, c.w = 400};
	item d = {d.v = 10, d.w = 100};
	item e = {e.v = 20, e.w = 300};

	int n = 5, W = 50;
	item items[] = {a, b, c, d};

	mergesort(items, n, sizeof(item), compare);
	float* S = knapsack(items, n, W);

	print(S, n);
}

void b()
{
	item a = {a.v = 10, a.w = 100};
	item b = {b.v = 20, b.w = 300};
	item c = {c.v = 30, c.w = 600};
	item d = {d.v = 20, d.w = 400};
	item e = {e.v = 40, e.w = 840};

	int n = 5, W = 50;
	item items[] = {a, b, c, d};

	float* S = knapsack(items, n, W);

	print(S, n);
}

void print(float* array, int n)
{
	printf("[");
	for(int i = 0; i < n; i++)
	{
		if(i)
			printf(", ");
		printf("%.2f", array[i]);
	}
	printf("]");
}