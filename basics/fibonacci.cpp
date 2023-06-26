/* Dupla: Elian Babireski & Pedro Vargas */

#include <iostream>
#include <vector>

using namespace std;

double calls;

/*
	Naive recursive fibonacci:

	T(n) ∈ Ω(φⁿ), conforme visto em aula.
*/

double fibonaive(double n)
{
	calls++;

	if(n <= 2)
		return 1;
	return fibonaive(n - 1) + fibonaive(n - 2);
}

/*
	Top-down recursive fibonacci:

	Observe que cada posição do vetor será calculada exatamente uma vez.
	Como o cálculo de uma posição toma tempo constante caso as duas posições anteriores sejam dadas, temos que:
	T(n) ∈ Θ(n).
*/

double topdownfibonaccirec(int n, double *vec)
{
	calls++;
	if(vec[n - 1] == 0)
		vec[n - 1] = topdownfibonaccirec(n - 1, vec) + topdownfibonaccirec(n - 2, vec);
	return vec[n - 1];
}

double topdownfibonacci(int n)
{
	calls++;
	double vec[n] = {};
	vec[0] = vec[1] = 1;
	return topdownfibonaccirec(n, vec);
}

/*
	Bottom-up recursive fibonacci:

	T(n) = (n - 2) + 2 ∈ Θ(n), conforme custos anotados abaixo.
*/

double bottomupfibonacci(int n)
{
	double array[n];
	array[1] = array[0] = 1; // 2
	
	for(int i = 2; i < n; i += 1) // n - 2
	{
		calls++;
		array[i] = array[i - 1] + array[i - 2]; // 1
	}

	return array[n - 1];
}

/*
	Vantagens:

		Top-down: evita que os subproblemas sejam calculados mais de uma vez.
		Bottom-up: evita que os subproblemas sejam calculados mais de uma vez e evita criar uma pilha de chamadas recursivas como o algoritmo top-down faz.
*/

int main()
{
	calls = 0;
	double ret = topdownfibonacci(45);
	printf("Top-down: %.0lf\tCalls: %.0lf\n", ret, calls);
	
	calls = 0;
	ret = bottomupfibonacci(45);
	printf("Bottom-up: %.0lf\tCalls: %.0lf\n", ret, calls);
	
	calls = 0;
	ret = fibonaive(45);
	printf("Naive: %.0lf\tCalls: %.0lf\n", ret, calls);
	
	return 0;
}
