/* Dupla: Elian Babireski & Pedro Vargas */

#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

vector<int> B;
vector<int> S;
vector<int> P = {0, 1, 3, 11, 16, 19, 10};

/*

*/

int topdowncutrecursive(int n)
{
	int lucro = -1;
	int valor = 0;

	if (B[n] == -1 && n > 0)
	{
		for (int i = 1; i <= n; i += 1)
		{
			valor = P[i] + topdowncutrecursive(n - i);
			if (valor > lucro)
			{
				lucro = valor;
				S[n - 1] = i;
			}
		}

		B[n] = lucro;
	}

	return B[n];
}

int topdowncut(int n)
{
	B.resize(n + 1);
	S.resize(n + 1);

	B[0] = 0;
	
	for (int i = 1; i <= n; i++)
		B[i] = -1;
	
	return topdowncutrecursive(n);
}

/*

*/

int bottomupcut(int n)
{
	vector<int> B1;
	vector<int> S1;

	B1.resize(n + 1);
	S1. resize(n + 1);
	
	int lucro;
	int valor;
	
	B1[0] = 0;

	for (int k = 1; k <= n; ++k)
	{
		lucro = -1;
	
		for (int i = 1; i <= k; ++i)
		{
			valor = P[i] + B1[k - i];
	
			if (valor > lucro)
			{
				lucro = valor;
				S1[k] = i;
			}

			B1[k] = lucro;
		}
	}

	return B1[n];
}

/*
	Vantagens:
		Top-down:
		Bottom-up:
*/

int main()
{
	int n = 6;

	cout << "Top-down: " << topdowncut(n)<< '\n';
	cout << "Bottom-up: " << bottomupcut(n) << '\n';
	
	for(int s: S) cout << s << " ";
	
	B.clear();
	S.clear();
	P.clear();
}
