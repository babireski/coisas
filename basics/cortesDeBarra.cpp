#include <iostream>
#include <stdlib.h>
#include <vector>
#define TAM 6
using namespace std;
vector<int> B;
vector <int> S;
vector<int> p = {0, 1, 3, 11, 16, 19, 10};

void imprimeCortes(int n)
{
	for (int i = n - 1; i >= 0; --i)
	{
        cout << S[i] << " ";
    }
    cout << '\n';
}
int cBRecTopDown(int n)
{
    int lucro = -1;
    int valor = 0;
    if (B[n] == -1 && n > 0)
    {
        for (int i = 1; i <= n; i += 1)
        {
            valor = p[i] + cBRecTopDown(n - i);
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
int cBTopdown(int n)
{
    B.resize(n + 1);
    S.resize(n + 1);
    B[0] = 0;
    for (int i = 1; i <= n; i += 1)
    {
        B[i] = -1;
    }
    return cBRecTopDown(n);
}
int cBBottomUp(int n)
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
            valor = p[i] + B1[k - i];
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
int main()
{
    cout << "Top Down: " << cBTopdown(TAM)<< '\n';
    cout << "Bottom up: " << cBBottomUp(TAM) << '\n';
    imprimeCortes(TAM);
    B.clear();
    S.clear();
    p.clear();
}
