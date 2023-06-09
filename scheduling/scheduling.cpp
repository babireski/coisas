#include <iostream>
#include "train.hpp"
#include <vector>

int main()
{
	// n -> nro de plataformas ; m -> nro de trens
	int n, m;
	std::vector<train> trains;
	std::cout << "Digite o numero de trens e de plataformas\n";
	std::cin >> n >> m;
	trains.resize(n);
	for(int i = 0; i < m; i++)
	{
		int h,m,p;
		std::cout << "Digite a plataforma do trem\n";
		std::cin >> p;
		tTime tim;
		if(p > 3 || p < 1)
		{
			i--;
			std::cout << "Erro, digite uma plataforma valida\n";
		}
		else
		{
			std::cout << "Digite a hora e o minuto de chegada do trem, separados por espaco\n";
			std::cin >> h >> m;
			if(tim.isValid(h,m))
			{
				tim.hour = h;
				tim.minutes = m;
				trains.at(i).arrival = tim;
			}
		}
	}

}
