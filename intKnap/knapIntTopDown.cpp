#include <iostream>
#include <array>
using namespace std;
const int n = 4;
const int W = 7;

int w[n] = {1, 3, 4, 5};
int v[n] = {10, 40, 50, 70};
int knapIntTopDownRec(array<array<int, W + 1>, n + 1> &m, int j, int x)
{
    if (m[j][x] == -1)
    {
        if (w[j - 1] > x)
        {
            m[j][x] = knapIntTopDownRec(m, j - 1, x);
        }
        else
        {
            int doesntUse = knapIntTopDownRec(m, j - 1, x);
            int uses = v[j - 1] + knapIntTopDownRec(m, j - 1, x - w[j - 1]);
            m[j][x] = uses > doesntUse ? uses : doesntUse;
        }
    }
    return m[j][x];
}
int knapIntBottomUp(array<array<int, W + 1>, n + 1> &m)
{
    for (int x = 0; x < W + 1; ++x)
    {
        m[0][x] = 0;
    }
    for (int j = 1; j < n + 1; ++j)
    {
        m[j][0] = 0;
    }
    for(int j = 1; j < n+1 ; ++j)
    {
        for(int x = 0; x < W+1; ++x)
        {
            if(w[j-1] > x)
            {
                m[j][x] = m[j-1] [x];
            }
            else
            {
                int usa = v[j-1] + m[j-1][x-w[j-1]];
                int naoUsa = m[j-1][x];
                m[j][x] = usa > naoUsa ? usa : naoUsa;
            }
        }
    }
    return m[n][W];
}

int knapIntTopDown(array<array<int, W + 1>, n + 1> &m)
{
    for (int x = 0; x < W + 1; ++x)
    {
        m[0][x] = 0;
        for (int j = 1; j < n + 1; ++j)
        {
            m[j][x] = -1;
            m[j][0] = 0;
        }
    }
    return knapIntTopDownRec(m, n, W);
}

int main()
{
    array<array<int, W + 1>, n + 1> m;
    cout << knapIntTopDown(m) << "\n";
    cout << knapIntBottomUp(m) << '\n';
    for (int i = 0; i < n + 1; i++)
    {
        cout << "\n";
        for (int j = 0; j < W + 1; j++)
        {
            cout << m[i][j] << " ";
        }
    }
    return 0;
}