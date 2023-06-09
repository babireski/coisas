#include <iostream>
#include "train.hpp"
#include <vector>
using namespace std;
int main()
{
	// n -> nro de plataformas ; m -> nro de trens
	int n, m;
	vector<train> trains;
	cout << "Digite o numero de plataformas\n";
	cin >> n;
	cout << "Digite o numero de trens\n";
	cin >> m;
	trains.resize(m);
	// initialize the trains
	for (int i = 0; i < m; i++)
	{
		int h, m, p;
		cout << "Digite a plataforma do trem\n";
		cin >> p;
		tTime tim;
		trains[i].platform = p;
		if (p > 3 || p < 1)
		{
			i--;
			cout << "Erro, digite uma plataforma valida\n";
		}
		else
		{
			cout << "Digite a hora e o minuto de chegada do trem, separados por espaco\n";
			cin >> h >> m;
			if (tim.isValid(h, m))
			{
				tim.hour = h;
				tim.minutes = m;
				trains[i].arrival = tim;
			}
			cout << "Digite a hora e o minuto de partida do trem, separados por espaco\n";
			cin >> h >> m;
			if (tim.isValid(h, m))
			{
				tim.hour = h;
				tim.minutes = m;
				trains[i].departure = tim;
			}
		
		}
	}
	trains.clear();
	return 0;
}
