#include "zawodnik.h"
#include "plansza.h"
#include <vector>
#include <random>
#include <conio.h>

std::vector<char> operator+(std::vector<char> plansza, std::vector<char> pola_koncowe)
{
	std::vector<char> rezult(plansza.size() + pola_koncowe.size());
	for (size_t i = 0; i < plansza.size(); i++) { rezult[i] = plansza[i]; }
	for(size_t i = plansza.size(); i < rezult.size(); i++) { rezult[i] = pola_koncowe[i]; }
	return rezult;
}

bool operator==(const Pionek pionek1, const Pionek pionek2)
{
	if (pionek1.numer == pionek2.numer) { return true; }
	else { return false; }
}

Pionek::Pionek(char numer)
{
	this->numer = numer;
}

Gracz::Gracz()
{
	Pionek pionek(0);
	pionki = { pionek, pionek, pionek, pionek };
	pionki[0].numer = '1';
	pionki[1].numer = '2';
	pionki[2].numer = '3';
	pionki[3].numer = '4';
}
int Gracz::getIloscPionkowPlansza() { return ilosc_pionkow_plansza; }

void Gracz::dodajDoIloscPionkowPlansza() { ilosc_pionkow_plansza++; }
void Gracz::odejmijOdIloscPionkowPlansza() { ilosc_pionkow_plansza--; }

void Gracz::setVnumer(int numer)
{
	vNumer = numer;
}
std::vector<Pionek> Gracz::getPionki() 
{ 
	return pionki; 
}
int Gracz::rzut_kostka()
{
	std::random_device rd;
	std::mt19937 gen(rd());       
	std::uniform_int_distribution<> dist(1, 6); 

	int liczba_oczek = dist(gen);
	return liczba_oczek;
}

std::vector<Pionek> Gracz::da_sie_poruszyc(int liczba_oczek)
{
	std::vector<Pionek> result;
	for(size_t i = 0; i < pionki.size(); i++)
	{
		
	}
	return result;
}

bool Gracz::ruch_pionkiem(int liczba_oczek, std::vector<char>& plansza, Pionek pionek)
{
	bool na_planszy;
	//czy pionek jest na planszy
	na_planszy = std::find(pionki_na_planszy.begin(), pionki_na_planszy.end(), pionek.numer) != pionki_na_planszy.end();

	if (na_planszy)
	{

	}
	return true;
}

void Gracz::ruch_gracza(std::vector<char>& plansza)
{
	char odp;
	int liczba_oczek = rzut_kostka();
	std::vector<Pionek> wybor = da_sie_poruszyc(liczba_oczek);
	std::cout << "Ktorym pionkiem chcesz sie poruszyc: ";
	for (Pionek x : wybor)
	{
		std::cout << x.numer <<'\n';
	}

	odp = _getch();

	ruch_pionkiem(rzut_kostka(), plansza, pionki[odp-1]);
	system("cls");
	//std::cout << plansza;
}