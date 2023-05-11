#include <stdio.h>
#include <stdlib.h>
#define TAM 6
int *B;
int *S;
int p[TAM] = {1, 3, 11, 16, 19, 10};
void imprimeCortes(int n)
{
    while (n > 0)
    {
        printf("%d ", S[n]);
        n += -1;
    }
}
int cBRecTopDown(int n)
{
    int lucro = -1;
    int valor = 0;
    if (B[n] == -1)
    {
        for (int i = 1; i <= n; i += 1)
        {
            valor = p[i] + cBRecTopDown(n - 1);
            if (valor > lucro)
            {
                lucro = valor;
                S[n] = i;
            }
        }
        B[n] = lucro;
    }
    return B[n];
}
int cBTopdown(int n)
{
    B = (int *)(malloc(sizeof(int) * (n + 1)));
    S = (int *)(malloc(sizeof(int) * (n + 1)));
    B[0] = 0;
    for (int i = 1; i <= n; i += 1)
    {
        B[i] = -1;
    }
    return cBRecTopDown(n);
}
int main()
{
    printf("%d\n", cBTopdown(7));
    imprimeCortes(7);
}
