#pragma once
#include <iostream>
#include <vector>

using vector2d = std::vector<std::vector<char>>;

struct Pionek
{
	char numer;
	int wiersz, kolumna;
	Pionek();
	Pionek(char numer);
	friend bool operator==(const Pionek pionek1, const Pionek pionek2);
};

class Gracz
{
private:
	int vNumer;
	std::vector<Pionek> pionki;
	std::vector<Pionek> pionki_na_planszy;
	int ilosc_pionkow_plansza;
public:
	Gracz();
	std::vector<Pionek> getPionki();
	int getIloscPionkowPlansza();
	void dodajDoIloscPionkowPlansza();
	void odejmijOdIloscPionkowPlansza();
	void setVnumer(int numer);
	int rzut_kostka();
	bool ruch_pionkiem(int liczba_oczek, std::vector<char>& plansza, Pionek pionek);
	void ruch_gracza(std::vector<char>& plansza);
	std::vector<Pionek> da_sie_poruszyc(int liczba_oczek);
	friend std::vector<char> operator+(std::vector<char> plansza, std::vector<char> pola_koncowe);
};