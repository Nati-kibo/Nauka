#include "plansza.h"
#include "zawodnik.h"

vector2d pola(std::vector<Gracz> zawodnicy)
{
	vector2d plansza(11, std::vector<char>(11, ' '));

	for (size_t w = 0; w < plansza.size();w++)
	{
		std::fill(plansza[w].begin() + 4, plansza[w].begin() + 7, 'O');
	}
	for (size_t w = 4; w <= 6;w++)
	{
		std::fill(plansza[w].begin(), plansza[w].end(), 'O');
	}
	plansza[5][5] = ' ';

	std::vector<Pionek> pionki_1gracza = zawodnicy[0].getPionki();
	plansza[0][0] = pionki_1gracza[0].numer;
	plansza[0][1] = pionki_1gracza[1].numer;
	plansza[1][0] = pionki_1gracza[2].numer;
	plansza[1][1] = pionki_1gracza[3].numer;

	std::vector<Pionek> pionki_2gracza = zawodnicy[1].getPionki();
	plansza[0][9] = pionki_2gracza[0].numer;
	plansza[0][10] = pionki_2gracza[1].numer;
	plansza[1][9] = pionki_2gracza[2].numer;
	plansza[1][10] = pionki_2gracza[3].numer;

	std::vector<Pionek> pionki_3gracza = zawodnicy[2].getPionki();
	plansza[9][0] = pionki_3gracza[0].numer;
	plansza[9][1] = pionki_3gracza[1].numer;
	plansza[10][0] = pionki_3gracza[2].numer;
	plansza[10][1] = pionki_3gracza[3].numer;

	std::vector<Pionek> pionki_4gracza = zawodnicy[3].getPionki();
	plansza[9][9] = pionki_4gracza[0].numer;
	plansza[9][10] = pionki_4gracza[1].numer;
	plansza[10][9] = pionki_4gracza[2].numer;
	plansza[10][10] = pionki_4gracza[3].numer;

	return plansza;
}
std::string kolorowanie(size_t wiersz, size_t kolumna, vector2d plansza)
{	
	//T£O
	const std::string czerwoneTlo = "[101;", niebieskieTlo = "[104;", zolteTlo = "[103;", zieloneTlo = "[102;", bialeTlo = "[107;", czarneTlo = "[100";

	//CZCIONKA
	const std::string czerwony = "91m", niebieski = "94m", zolty = "93m", zielony = "92m", bialy = "37m", czarny = "30m";
	const std::string czerwonyPionek = "31m", niebieskiPionek = "34m", zoltyPionek = "33m", zielonyPionek = "32m";

	switch (wiersz)
	{
	case 1:
		if (kolumna == 5) { return niebieskieTlo + niebieskiPionek; }
	case 0:
		if (kolumna == 0 || kolumna == 1) { return czerwoneTlo + czerwonyPionek; }
		if (kolumna == 9 || kolumna == 10) { return niebieskieTlo + niebieskiPionek; }
		break;

	case 2:
	case 3:
	case 4:
		if (kolumna == 5) { return niebieskieTlo + niebieskiPionek; }
		break;

	case 5:
		if (kolumna >= 1 && kolumna <= 4) { return czerwoneTlo + czerwonyPionek; }
		if (kolumna >= 6 && kolumna <= 9) { return zieloneTlo + zielonyPionek; }
		break;

	case 6:
	case 7:
	case 8:
		if (kolumna == 5) { return zolteTlo + zoltyPionek; }
		break;

	case 9:
		if (kolumna == 5) { return zolteTlo + zoltyPionek; }
	case 10:
		if (kolumna == 0 || kolumna == 1) { return zolteTlo + zoltyPionek; }
		//if (kolumna == 4) { return zolteTlo + bialy; }
		if (kolumna == 9 || kolumna == 10) { return zieloneTlo + zielonyPionek; }
		break;
	}
	if (plansza[wiersz][kolumna] == ' ')	{ return czarneTlo + czarny; }
	//if (plansza[wiersz][kolumna] != 'O')    { return bialeTlo + zoltyPionek; }
	return bialeTlo + bialy;
}
std::ostream& operator<<(std::ostream& wyjscie, const vector2d& plansza)
{
	for (size_t w = 0; w < plansza.size();w++)
	{
		for (size_t k = 0; k < plansza[w].size();k++)
		{
			wyjscie << "\33" << kolorowanie(w, k, plansza) << plansza[w][k] << "\033[0m";
		}
		wyjscie << '\n';
	}
	return wyjscie;
}

bool koniec_gry(vector2d plansza)
{
	//wygrana czerwonego 
	return true;
}