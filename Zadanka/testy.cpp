#include <iostream>
#include <thread>
#include <conio.h>
#include <vector>
#include <cmath>
#include <array>
#include <string>
#include <algorithm>
#include <set>
#include <map>
void timer()
{
	int sekundy;
	std::cout << "Na ile sekund usatwic timer: ";std::cin >> sekundy;
	while (sekundy != -1) {
		std::cout << "Zostalo: " << sekundy;
		sekundy -= 1;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		system("cls");
	}
	std::cout << "Koniec!";
	_getch();
}
void stopper()
{
	int sekundy=0, q=0;
	do
	{
		std::cout << "Sekund: " << sekundy;
		sekundy++;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		if (_kbhit())
			q = _getch();
		else
			system("cls");
	} while (!(q==113 || q==81));
	std::cout << "\nStoper skonczyl odliczac czas na " << sekundy << "s.";

}
void isNumerFirst()
{
	int number, reszta;
	std::cin >> number;if (number >= 1)std::cout << "Liczba nie jest pierwsza";
	for (int i = 2;i != number;i++) {
		reszta = number% i;
		if (reszta == 0) {
			std::cout << "Liczba nie jest pierwsza";break;
		}
	}
}
void sitoEratostenesa()
{	
	int zakres, start = 1;
	std::cin >> zakres;
	std::vector <int> przedzial;
	for (int i = 0;i <= zakres;i++) {
		przedzial.push_back(i);
	}
	for (int j = 2;j < zakres;j++) { 
		for (int s = j+j;s <= zakres;s += j) {//?????
				przedzial[s] = 0;
		}
	}
	std::cout << "Liczby pierwsze z przedzialu 1-" << zakres << ": ";
	for (int i = 0;i <= zakres;i++) {
		if(przedzial[i]>0)
			std::cout << przedzial[i] << " ";
	}
}
void dvividedBy13()
{
	int dzielnik = 13, dzielone;
	for (int i = 1;i <= 1000;i++) {
		dzielone = i % dzielnik;
		if (dzielone == 0)
			std::cout << i << ", ";
	}
}
void lowPairs() {
	int x, y;
	std::cout << "Pary: ";
	for (x = 1;x <= 100;x++) {
		for (y = 1;y <= 100;y++) {
			if (pow(2, x) + pow(2, y) < 1000) {
				std::cout << x<<" i " << y << "   ";
			}
			
		}
	}
}
void wspolnyDzielnik()
{	
	int a, b, dzielnikA, dzielnikB;
	std::cout << "Podaj liczbe:";std::cin >> a;
	std::cout << "Podaj liczbe:";std::cin >> b;
	std::cout << "Wspolne dzielniki: ";
	for (int i = 1;i <= a;i++) {
		dzielnikA = a % i;
		dzielnikB = b % i;	
		if ((dzielnikA == 0 && dzielnikB == 0)) {
			std::cout << i <<", ";
		}
	}
}
void fibbonachi()
{	
	int n;
	std::cout << "Ile liczb (note: > 1): ";std::cin >> n;
	std::vector <int> F (n);
	F[0] = 0;
	F[1] = 1;
	std::cout << F[0] << ' ' << F[1];
	for (int i = 2;i < n;i++) {
		F[i] = F[i - 1] + F[i - 2];
		std::cout << ' ' << F[i];
	}
}
int definicje(std::vector <int> cyfry, int i)
{
	int wartosc;
	switch (cyfry.at(i))
	{
	case 0:
		wartosc = 0;break;
	case 1:
		wartosc = 1;break;
	case 2:
	case 3:
	case 4:
		wartosc = 2;break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		wartosc = 3;break;
	}
	return wartosc;
}
void cyfrySlownie()
{
	unsigned int liczba;
	int cyfra;
	std::vector <int> cyfry;
	std::cout << "Podaj liczbe z zakresu 0 do 4 294 967 295: ";std::cin >> liczba;
	std::array <std::string, 10> pojedyncze = { "", "jeden", "dwa", "trzy", "cztery", "piec", "szesc", "siedem", "osiem", "dziewiec" };
	std::array <std::string, 10> dziesiatki = { "", "dziesiec", "dwadziescia", "trzydziesci", "czterdziesci", "piecdziesiat", "szescdziesiat", "siedemdziesiat", "osiemdziesiat", "dziewiecdziesiat" };
	std::array <std::string, 10> setki = { "", "sto", "dwiescie", "trzysta", "czterysta", "piecset", "szescset", "siedemset", "osiemset", "dzieiecset" };
	std::array <std::string, 4> tysiace = { "", "tysiac", "tysiace", "tysiecy" };
	std::array <std::string, 4> miliony = { "", "milion", "miliony", "milionow" };
	std::array <std::string, 4> miliardy = { "" , "miliard", "miliardy", "miliardow" };
	while (liczba > 0)
	{
		cyfra = liczba % 10;
		cyfry.push_back(cyfra);
		liczba /= 10;
	}
	std::reverse(cyfry.begin(), cyfry.end());
		switch(cyfry.size()){
		case 10:
			std::cout << pojedyncze[cyfry[0]]<<' ';
			std::cout<<miliardy[definicje(cyfry, 0)] << ' ';
			cyfry.erase(cyfry.begin());
		case 9:
			std::cout << setki[cyfry[0]] << ' ';
			cyfry.erase(cyfry.begin());
		case 8:
			std::cout << dziesiatki[cyfry[0]] << ' ';
			cyfry.erase(cyfry.begin());
		case 7:
			std::cout << pojedyncze[cyfry[0]] << ' ';
			std::cout << miliony[definicje(cyfry, 0)] << ' ';
			cyfry.erase(cyfry.begin());
		case 6:
			std::cout << setki[cyfry[0]] << ' ';
			cyfry.erase(cyfry.begin());
		case 5:
			std::cout << dziesiatki[cyfry[0]] << ' ';
			cyfry.erase(cyfry.begin());
		case 4:
			std::cout << pojedyncze[cyfry[0]] << ' ';
			std::cout << tysiace[definicje(cyfry, 0)] << ' ';
			cyfry.erase(cyfry.begin());
		case 3:
			std::cout << setki[cyfry[0]] << ' ';
			cyfry.erase(cyfry.begin());
		case 2:
			std::cout << dziesiatki[cyfry[0]] << ' ';
			cyfry.erase(cyfry.begin());
		case 1:
			std::cout << pojedyncze[cyfry[0]] << ' ';
			cyfry.erase(cyfry.begin());break;
		case 0:
			std::cout << "zero";
		}
	}
void randOdN()
{
	std::vector <int> tablica;
	int size, radnom_liczba;
	std::cin >> size;
	for (int i = 0;i < size;i++)
	{
		radnom_liczba = rand() % 45 - 15;
		tablica.push_back(radnom_liczba);
	}
}
void cyfry()
{
	unsigned int liczba;
	int cyfra;
	float sredniaArt, suma = 0;
	std::array<int,10> cyfry;
	std::cout << "Podaj 10 kolejnych liczb: \n";
	for (int i = 0;i < cyfry.size();i++)
	{
		std::cout << "Cyfra " << i + 1 << ": "; std::cin >> cyfry[i];
		suma += cyfry[i];
	}
	sredniaArt = suma / 10;
	std::cout << "Suma: " << suma << "\nSrednia Artmetyczna: " << sredniaArt;
	if (cyfry[0] < cyfry[9])
		std::cout << "\nLiczby usatwione sa rosnaco.";
	else if (cyfry[0] > cyfry[9])
		std::cout << "\nLiczby usatwione sa malejaco.";
	else
		std::cout << "\nNie rosna ani nie maleja.";
	std::set<int> powtorka(cyfry.begin(), cyfry.begin() + 10);;
		
	if (powtorka.size() < 10)
		std::cout << "Jest powtorka\n";
	else
		std::cout << "Nie ma powtorki\n";

	std::cout << "Obrocona kolejnosc: ";
	for (auto rit = cyfry.rbegin(); rit < cyfry.rend(); ++rit)
		std::cout << ' ' << *rit;
	for (int i = 0;i < cyfry.size();i++) {
		for (int j = 0;j < cyfry.size() - i - 1;j++) {
			if (cyfry[j] > cyfry[j + 1]) {
				int box = cyfry[j];
				cyfry[j] = cyfry[j + 1];
				cyfry[j + 1] = box;
			}

		}
	}
	std::cout << '\n'<<"Bubble sort: " ;
	for(auto it =cyfry.begin();it != cyfry.end(); ++it)
		std::cout<< ' ' << *it;
}
void histogram()
{
	std::array <int, 26> ilosc = { 0 };
	std::string napis;
	std::getline(std::cin, napis);
	char litera = 65;
	int indeks;
	/*for (char i = 65;i<123;++i)
	{
		std::size_t found = napis.find(i);
		if (found != std::string::npos)
			std::cout << "Znaleziono:  " << i << '\n';
		else
			std::cout << "Nie znaleziono: " << i << '\n';
	}*/
	for (auto it = napis.begin();it != napis.end();it++)
	{
		indeks = 0;
		for (int i = litera;i <= 90;i++) {
			if ((*it == i || *it == i + 32)) {
				ilosc[indeks]++;
				break;
			}
			else if (*it == 8)
				break;
			else
				indeks++;
		}
	}
	std::cout << "Ilosc literek alfabetycznie: [";
	for (int i = 0;i < ilosc.size();i++) {
		if (ilosc[i] > 0) {
			std::cout <<char(65+i)<<": " << ilosc[i] << ", ";
		}
	}
	std::cout << ']';
}
void macierzTransportowana()
{
	std::vector <std::vector <int>> macierz;
	int ilosc_wiersze, ilosc_kolumny, random, zero = 0;
	std::cout << "Ilosc wierszy: ";std::cin >> ilosc_wiersze;
	std::cout << "Ilosc kolumn: ";std::cin >> ilosc_kolumny;
	std::vector<int> kolumny(ilosc_kolumny, zero);
	std::vector<std::vector<int>> wiersze(ilosc_wiersze, kolumny);
	for (int w = 0;w < ilosc_wiersze;w++) {
		for (int k = 0;k < ilosc_kolumny;k++) {
			wiersze[w][k] = rand() % 10;
			std::cout << wiersze[w][k];
		}
		std::cout << '\n';
	}
	for (int i = 0;i < ilosc_wiersze;i++) {
		if(ilosc_wiersze>ilosc_kolumny)
			wiersze[i].resize(ilosc_wiersze,kolumny[i]);//
		else if(ilosc_wiersze < ilosc_kolumny)
			kolumny.resize(ilosc_wiersze);
	}
	std::cout << "Transporowany macierz:\n";
	for (int w = 0;w < ilosc_wiersze;w++) {
		for (int k = 0;k < ilosc_kolumny;k++) {
			std::cout << wiersze[k][w];
		}
		std::cout << '\n';
	}

}
void potega()
{
	unsigned int liczba;
	int cyfra;
	std::vector <int> cyfry;
	std::cin >> liczba;
	while (liczba > 0)
	{
		cyfra = liczba % 10;
		cyfry.push_back(cyfra);
		liczba /= 10;
	}
	std::cout << '\n';
	for (auto it = cyfry.rbegin();it != cyfry.rend();it++)
		std::cout<<pow(*it, 2)<<' ';
}
void wspoliniowe()
{
	float punkty[3][2];
	float a, b;
	for (int i = 0;i < 3;i++) {
		std::cout << "Podaj " << i + 1 << " punkt:\n";
		for (int j = 0;j < 2;j++) {
			if (j == 0)
				std::cout << "x = ";
			else
				std::cout << "y = ";
			std::cin >> punkty[i][j];
		}
	}

	a = (punkty[0][1] - punkty[1][1]) / (punkty[0][0] - punkty[1][0]);
	b = punkty[0][1] - a * punkty[0][0];
	std::cout << a << ' ' << b;
	if (punkty[2][1] == (a * punkty[2][0] + b))
		std::cout << "Punkty maja ten sam wspolczynnik liniowy :)";
	else
		std::cout << "Punkty nie maja tego samego wspolczynnika liniowego :(";
}
int dyktando()
{
	std::string nauczyciel, uczen;
	std::cin >> nauczyciel >> uczen;
	int bledy = 0;
	for (int i = 0;i < nauczyciel.size();i++)
	{
		if (nauczyciel[i] != uczen[i])
			bledy++;
	}
	return bledy;
}
void ¿ymianin()
{
	int arabska;
	std::map <int, char> slownik;
	slownik[1] = 'I';
	slownik[5] = 'V';
	slownik[10] = 'X';
	slownik[50] = 'L';
	slownik[100] = 'C';
	slownik[500] = 'D';
	slownik[1000] = 'M';

	std::cin >> arabska;
	while(arabska>0)
	{
		if ((arabska >= 1000 && arabska < 4000)) {
			std::cout << slownik[1000];
			arabska -= 1000;
		}
		//900
		if ((arabska >= 500 && arabska < 1000)) {
			std::cout << slownik[500];
			arabska -= 500;
		}
		//400
		if ((arabska >= 100 && arabska < 500)) {
			std::cout << slownik[100];
			arabska -= 100;
		}
		//90
		if ((arabska >= 50 && arabska < 100)) {
			std::cout << slownik[50];
			arabska -= 50;
		}
		//40
		if ((arabska >= 10 && arabska < 50)) {
			std::cout << slownik[10];
			arabska -= 10;
		}
		//9
		if ((arabska >= 5 && arabska < 10)) {
			std::cout << slownik[5];
			arabska -= 5;
		}
		//4
		if ((arabska >= 1 && arabska < 5)) {
			std::cout << slownik[1];
			arabska -= 1;
		}
	}
}
void bezSpacji()
{
	std::string tekst;
	std::getline(std::cin, tekst);
	for (int i = 0;i < tekst.size();i++) {
		if (tekst.at(i) == 32) {
			tekst.erase(tekst.begin() + i);
			// chyba tak
			i--;
		}
	}
	std::cout << tekst;
}
void palindrom()
{
	std::string napis;
	std::cin >> napis;
	char odwrotnosc = napis.size() - 1;
	for (auto it = napis.begin(); it != napis.end();it++){
		if (*it == napis[odwrotnosc])
			odwrotnosc--;
		else {
			std::cout << "Napis nie jest palindromem";
			return;
		}		
	}
	std::cout << "Napis jest palindromem";
}
void szyfrCezara() 
{
	int przeuniecie;
	char litera;
	std::string napis, szyfr = "";
	std::cout << "O ile przesunac: ";
	std::cin >> przeuniecie;
	std::cout << "Podaj napis do zaszyfrowania: ";
	std::cin >> napis;
	for (auto it = napis.begin(); it != napis.end();it++)
	{
		litera = *it + przeuniecie;
		szyfr += litera;
	}
	std::cout << szyfr;
}
void wskazniki()
{
	std::vector <int> tablica(5,0);
	int min, max;
	long zmienna = 5;
	long* wskaznik_do_zmiennej = &zmienna;
	for (auto it = tablica.begin(); it != tablica.end();it++)
	{
		std::cout << "Podaj liczbe: ";
		std::cin >> *it;
	}
	std::cout << "Tablica zawiera: ";
	for (auto it = tablica.begin(); it != tablica.end();it++)
	{
		std::cout << *it<< ", ";
	}
}
void ZerujWieksze(int*ptr_liczba_1, int &adres_liczba_2, int max)
{
	std::cout << ptr_liczba_1 << ' ' << &adres_liczba_2;
	for (auto it = ptr_liczba_1; it != &adres_liczba_2;it += 4)
	{
		if (*it > max)
			*it = 0;
		std::cout << *it<<' ';
	}
}
int main()
{
	//timer();
	//stopper();
	//isNumerFirst();
	//sitoEratostenesa();
	//dvividedBy13();
	//lowPairs();
	//wspolnyDzielnik();
	//fibbonachi();
	//cyfrySlownie();
	//randOdN();
	//cyfry();
	//histogram();
	//macierzTransportowana();
	//potega();
	//wspoliniowe()
	//std::cout << dyktando();
	//¿ymianin();
	//bezSpacji();
	//palindrom();
	//szyfrCezara();
	//wskazniki();
	std::vector<int> tablica = { 2, 5, 8, 10, 15 };
	int liczba_1 = tablica.front(), liczba_2 = tablica.back(), max = 10;
	ZerujWieksze(&liczba_1, liczba_2, max);
	for (auto it = tablica.begin(); it != tablica.end();it++) {
		std::cout << &*it << ", ";
	}
	return 0;
}