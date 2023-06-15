#include <iostream>
#include "train.hpp"
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int contaMaxTremDisponivel(int m, int n)
{
	vector<vector<train>> trains(3);
	// initialize the trains
	for (int i = 0; i < m; i++) //O(m)
	{
		int h, m, p;
		cout << "Digite a plataforma do trem\n";
		cin >> p;
		train tt;
		tTime tim;
		cout << "Digite a hora e o minuto de chegada do trem, separados por espaco\n";
		cin >> h >> m;
		if (tim.isValid(h, m))
		{
			tim.hour = h;
			tim.minutes = m;
			tt.arrival = tim;
		}
		cout << "Digite a hora e o minuto de partida do trem, separados por espaco\n";
		cin >> h >> m;
		if (tim.isValid(h, m))
		{
			tim.hour = h;
			tim.minutes = m;
			tt.departure = tim;
		}
		trains[p-1].push_back(tt);
	}
	int ret = 0;
	for (int i = 0; i < n; ++i) //O(n)
	{
		ret += 1;
		sort(trains[i].begin(), trains[i].end(), compareTimes); //O(m * log m)
		int k = 0;
		for (int j = 1; j < trains[i].size(); ++j) //O(m)
		{
			if (trains[i][k].departure.isLess(trains[i][j].arrival))
			{
				ret += 1;
			}
		}
	}
	trains.clear();
	return ret;
}
//Encadeando o custos, temos O(n * m * (1 + log m))
int main()
{
	// n -> nro de plataformas ; m -> nro de trens
	int n, m;
	cout << "Digite o numero de plataformas\n";
	cin >> n;
	cout << "Digite o numero de trens\n";
	cin >> m;
	cout << contaMaxTremDisponivel(m, n) << '\n';
	return 0;
}
