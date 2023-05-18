#include <stdio.h>
#include <stdlib.h>
#define TAM 6
int *B;
int *S;
int p[TAM+1] = {0,1, 3, 11, 16, 19, 10};
void imprimeCortes(int n)
{
    for(int i = n-1; i >= 0; --i)
    {
        printf("%d ",S[i]);
    }
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
                S[n-1] = i;
            }
        }
        B[n] = lucro;
    }
    return B[n];
}
int cBTopdown(int n)
{
    B = (int *)(malloc(sizeof(int) * (n)));
    S = (int *)(malloc(sizeof(int) * (n)));
    B[0] = 0;
    for (int i = 1; i <= n; i += 1)
    {
        B[i] = -1;
    }
    return cBRecTopDown(n);
}
int cBBottomUp(int n)
{
    int B1 = (int*)(malloc(sizeof(int)*n));
    int S1= (int*)(malloc(sizeof(int)*n));
    B1[0] = 0;
    for(int k = 1; k <= n; ++k)
    {
        int lucro
    }
}
int main()
{
    printf("%d\n", cBTopdown(TAM));
    imprimeCortes(TAM);
}
