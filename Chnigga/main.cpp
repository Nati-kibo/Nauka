#include <iostream>
#include <vector>
#include "zawodnik.h"
#include "plansza.h"

using vector2d = std::vector<std::vector<char>>;

std::vector<Gracz> zawodnicy(4);

std::vector<char> plansza (40, 'O');

int main()
{
	//std::cout << planszaXXX pola();
	for(size_t i = 0; i < zawodnicy.size();i++)
		zawodnicy[i].setVnumer(i);

	zawodnicy[0].ruch_gracza(plansza);
}