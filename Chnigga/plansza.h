#pragma once
#include <iostream>
#include <vector>
#include "zawodnik.h"

using vector2d = std::vector<std::vector<char>>;

std::ostream& operator<<(std::ostream & wyjscie, const vector2d&plansza);

vector2d pola(std::vector<Gracz> zawodnicy);
std::string kolorowanie(size_t wiersz, size_t kolumna, vector2d plansza);
//void poruszanie_pionka(vector2d plansza, std::vector<int> nowa_pozycja);
bool koniec_gry(vector2d plansza);