#include <iostream>
#include <string>
#include <span>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
struct DoubleOsoba  //DoubleOsoba : Osoba == masa problemow
{
	std::string imie;
	std::string nazwisko;
	int wiek;
	DoubleOsoba* next = nullptr;
	DoubleOsoba* prev = nullptr;

	DoubleOsoba() = default;

	//konstruktor kopiujacy - nie koniecznie potrzebny
	DoubleOsoba(const DoubleOsoba& skopiowany)
		: imie(skopiowany.imie), nazwisko(skopiowany.nazwisko), wiek(skopiowany.wiek)
	{}
	DoubleOsoba(std::string imie, std::string nazwisko, int wiek)
		: imie(imie), nazwisko(nazwisko), wiek(wiek)
	{ }
};
class LinkedList
{
private:
	DoubleOsoba* head = nullptr;
	DoubleOsoba* tail = nullptr;
public:
	LinkedList()
	{
	}
	~LinkedList()
	{
		DoubleOsoba* temp = head;
		while (head != nullptr)
		{
			temp = head;
			head = temp->next;
			delete temp;
		}
	}
	void addycjaElementu(DoubleOsoba* nowaOsoba, int pozycja)
	{
		nowaOsoba = new DoubleOsoba(*nowaOsoba);
		if (pozycja == 1)
		{
			nowaOsoba->next = head;
			if (head != nullptr)
			{
				head->prev = nowaOsoba;
			}
			head = nowaOsoba;
			return;
		}
		else if (pozycja < 1)
		 {
			 std::cout << "Nie ma takiej pozycji";
			 delete nowaOsoba;
			 return;
		 }

		DoubleOsoba* temp = head;
		 for (size_t i = 1;i < pozycja && temp != nullptr;i++)
		 {
			 temp->prev = temp;
			 temp = temp->next;
		 }
		 //mo¿na dodaæ warunek czy temp to nullptr i zmienna liczba_elementow :)

		 nowaOsoba->prev = temp->prev;
		 nowaOsoba->next = temp;
		 temp->prev->next = nowaOsoba;//???
		 temp->prev = nowaOsoba;//????
		 
	}
	void zamianaElementu(DoubleOsoba* nowaOsoba, int pozycja)
	{
		DoubleOsoba* temp = head;
		for (size_t i = 1; i < pozycja && temp != nullptr;i++)
		{
			temp->prev = temp;
			temp = temp->next;
		}
		//tutaj tez mozna zrobic if i zmienna ilosc_elementow :)
		if (temp == nullptr)
		{
			std::cout << "Lista nie ma tylu elementow";
			delete nowaOsoba;
			return;
		}
		if (pozycja == 1)
		{
			nowaOsoba->prev = head->prev;
			nowaOsoba->next = head->next;
			/*head->prev->next = nowaOsoba;
			ZAPAMIETAJ: jesli head->next == nullptr && head->prev == nullptr to "head-prev->next" = crash*/
			if (head->next != nullptr)
				head->next->prev = nowaOsoba;
			delete head;
			head = nowaOsoba;
			return;
		}
		else if (pozycja < 1)
		{
			std::cout << "Nie ma takiej pozycji";
			delete nowaOsoba;
			return;
		}
		nowaOsoba->prev = temp->prev;
		nowaOsoba->next = temp->next;
		temp->prev->next = nowaOsoba;
		if(temp->next != nullptr)
			temp->next->prev = nowaOsoba;
		delete temp;
	}
	void usuwanieElementu(int pozycja)
	{
		DoubleOsoba* temp = head;
		for (int i = 1;i < pozycja && temp != nullptr;i++)
		{
			temp->prev = temp;
			temp = temp->next;
		}
		if (temp == nullptr)
		{
			std::cout << "Nie ma tylu elementow";
			return;
		}
		if (pozycja == 1)
		{
			if (head->next != nullptr)
				head->next->prev = head->prev;
			delete head;
			head = temp->next;
			return;
		}
		else if (pozycja < 1)
		{
			std::cout << "Nie ma takiej pozycji";
			return;
		}
		temp->prev->next = temp->next;
		if(temp->next != nullptr)
			temp->next->prev = temp->prev;
		delete temp;
	}

};

struct Osoba
{
	std::string imie;
	std::string nazwisko;
	int wiek;
	Osoba* next;
};
void menu_osob();
std::pair<Osoba*, int> dodaj_osobe()
{	
	Osoba* nowaOsoba = new Osoba;int position;
	std::cout << "Podaj imie: ";std::cin >> nowaOsoba->imie;
	std::cout << "Podaj nazwisko: ";std::cin >> nowaOsoba->nazwisko;
	std::cout << "Podaj wiek: ";std::cin >> nowaOsoba->wiek;
	std::cout << "Na jakiej pozycji (od 0): ";std::cin >> position;
	return{ nowaOsoba, position };
}
void new_atPosition(Osoba*& head,std::pair<Osoba*, int> element)
{
	Osoba* nowaOsoba = element.first;
	int position = element.second;
	Osoba* temp = head;
	if (position == 0)
	{
		nowaOsoba->next = head; //Next nowej osoby wskazuje na dotyczas pierwszy element
		head = nowaOsoba;      //Teraz wskaznik head wskazuje na nowa osobe(bo jest pierwsza)
		return;
	}
	for (int i = 0;i < position - 1 && temp != nullptr;i++)
	{
		temp = temp->next;
	}
	if (temp == nullptr)
	{
		std::cout << "Blad! Lista nie ma tylu elementow";
		delete nowaOsoba;
		return;
	}
	nowaOsoba->next = temp->next;  //koljn¹ rzecz¹ po naszej ustalonej pozycji bedzie to na co wskazywal do tej pory wskaznik po temp
	temp->next = nowaOsoba;  //musimy wiec przypisac czym jest ten temp->next(na co wskazuje). Teraz chcemy ze by po temp byl nowy element
}
void delete_list(Osoba*& head)
{
	Osoba* temp = head;
	while (head != nullptr)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
}
void swap_atPosition(Osoba*& head, std::pair<Osoba*, int> element)
{
	Osoba* nowaOsoba = element.first;
	int position = element.second;
	Osoba* temp = head, * previous = nullptr;
	if (head == nullptr)
	{
		std::cout << "Blad! Lista jest pusta. Najpierw dodaj element.";
		return;
	}
	if (position == 0)
	{
		nowaOsoba->next = head->next;
		head = nowaOsoba;
		delete temp;
		return;
	}
	for (int i = 0;i < position && temp != nullptr;i++)
	{
		previous = temp;
		temp = temp->next;
	}
	if (temp == nullptr)
	{
		std::cout << "Blad! Nie ma tylu elementow.";
		delete nowaOsoba;
		return;
	}
	nowaOsoba->next = temp->next;
	previous->next = nowaOsoba;
	delete temp;
}
void delete_atPosition(Osoba*& head, int position)
{
	Osoba* temp = head, * previous = nullptr;int elementy = 0;
	if (position == 0)
	{
		if (head == nullptr)
		{
			std::cout << "Blad! Lista jest pusta.";
			return;
		}
		head = head->next;
		delete temp;
		return;
	}
	for (int i = 0;i < position && temp != nullptr;i++)
	{
		previous = temp;
		temp = temp->next;
		elementy++;
	}
	if (temp == nullptr)
	{
		std::cout << "Blad! Tu juz nie ma elementu. Ilosc elementow listy: " << elementy;
		return;
	}
	previous->next = temp->next;
	delete temp;
}
void print_list(Osoba* head)
{
	if (head == nullptr)
	{
		std::cout << "nullptr";
		return;
	}
	Osoba* temp = head;;
	std::cout << "Lista po:\n";
	std::cout << "i - imionach\nn - nazwiskach\nw - wieku\n";
	char odp = _getch();
	do
	{
		odp = tolower(odp); //usowa capsl
		switch (odp)
		{
		case 'i':
			while (temp != nullptr)
			{
				std::cout << temp->imie << " -> ";
				temp = temp->next;
			}
			std::cout << "nullptr";
			break;
		case 'n':
			while (temp != nullptr)
			{
				std::cout << temp->nazwisko << " -> ";
				temp = temp->next;
			}
			std::cout << "nullptr";
			break;
		case 'w':
			while (temp != nullptr)
			{
				std::cout << temp->wiek << " -> ";
				temp = temp->next;
			}
			std::cout << "nullptr";
			return;
		default:
			std::cout << "\nNie rozumiem. Podaj literke jeszcze raz :)";
			odp = _getch();
			break;
		}
	} while ((odp != 'i' && odp != 'n' && odp != 'w'));

}
void menu_osob()
{
	Osoba* head = nullptr;
	int position;char odp;
	do
	{
		std::cout << "\033[2J\033[H"; //czysci cmd
		std::cout << "Witaj!Co chesz zrobic:";
		std::cout << "\n1. Dodaj osobe";
		std::cout << "\n2. Zamien osobe";
		std::cout << "\n3. Usun osobe";
		std::cout << "\n4. Wydrukuj liste osob";
		std::cout << "\nNacisnij 'ESC' aby wyjsc..";
		odp = _getch();

		switch (odp)
		{
		case '1':
			std::cout << "\033[2J\033[H"; //czysci cmd
			new_atPosition(head, dodaj_osobe());
			break;
		case '2':
			std::cout << "\033[2J\033[H";
			swap_atPosition(head, dodaj_osobe());
			break;
		case '3':
			std::cout << "\033[2J\033[H";
			std::cout << "Na jakiej pozycji usunac: ";std::cin >> position;
			delete_atPosition(head, position);
			break;
		case '4':
			std::cout << "\033[2J\033[H";
			print_list(head);
			break;
		default:
			break;
		}
		std::cout << "\nNacisnij 'ENTER' aby kontynuowac..";
		odp = _getch();
		while ((odp != 13 && odp != 27))
		{
			std::cout << "\033[2J";
			std::cout << "\033[15;0H" << "\nNacisnij 'ENTER' aby kontynuowac..";//ustawia kursor na 15 wierszu i 0 kolumnie - kod ANSI
			odp = _getch();
		}
		
	} while (odp != 27);
	delete_list(head);
}

struct Ksiazka
{
	std::string tytul;
	std::string autor;
	int indeks;
	float cena;
	int liczba_stron;
	bool status_wypozyczenia;
};
void dodawanie_ksiazek(Ksiazka ksiazki[], int ilosc)
{
	int i = 1;
	for (int i = 0; i < ilosc;i++)
	{		
		std::cout << "\nKsiazka: " << i + 1 << "\nTytul: ";std::cin.ignore();
		std::getline(std::cin, ksiazki[i].tytul);
		std::cout << "Autor: "; std::getline(std::cin, ksiazki[i].autor);
		std::cout << "Indeks: "; std::cin >> ksiazki[i].indeks;
		std::cout << "Cena: "; std::cin >> ksiazki[i].cena;
		std::cout << "Ilosc stron: "; std::cin >> ksiazki[i].liczba_stron;
		std::cout << "Status wypozycznenia: "; std::cin >> ksiazki[i].status_wypozyczenia;
	}
	std::span<Ksiazka>span_ksiazki(ksiazki, ilosc);
	for (Ksiazka it : span_ksiazki)
	{
		std::cout << "\nTytul " << i << " ksiazki: " << it.tytul;
		i++;
	}
}
void tanie_ksiazki(std::span<Ksiazka>span_ksiazki)
{
	std::cout << "\nTanie ksiazki: ";
	for (Ksiazka it : span_ksiazki)
	{
		if (it.cena < 10)
			std::cout << it.tytul << ", ";
	}
}
void nie_wyporzyczone_dlugie(std::span<Ksiazka>span_ksiazki)
{
	std::cout << "\nNie wypozyczone ksiazki, ktore maja ponad 50 stron: ";
	for (std::span<Ksiazka>::iterator it = span_ksiazki.begin();it != span_ksiazki.end();it++)
	{
		if (((*it).status_wypozyczenia == false && (*it).liczba_stron > 50))
			std::cout << (*it).tytul << ", ";
	}
}
void cena_strony(std::span<Ksiazka>span_ksiazki)
{
	float jedna_strona;
	for (size_t i = 0;i < span_ksiazki.size();i++)
	{
		jedna_strona =  span_ksiazki[i].cena/ float(span_ksiazki[i].liczba_stron);
		std::cout << "\nCena za jedna storne " << span_ksiazki[i].tytul << " wynosi: " << jedna_strona;
	}
}
void na_K(std::span<Ksiazka>span_ksiazki)
{
	char pierwsza_litera;
	std::cout << "\nKsiazki na literke 'K': ";
	for (Ksiazka it : span_ksiazki)
	{
		pierwsza_litera = it.tytul[0];
		if (pierwsza_litera == 75 || 75+32)
			std::cout << it.tytul;
	}
}
void output_ksiazki(std::span<Ksiazka>span_ksiazki) //wczytywanie
{
	std::ofstream plik("ksiazki.txt");
	if (plik.is_open())
	{
		for (Ksiazka it : span_ksiazki)
		{
			plik << it.tytul << '\n';
			plik << it.autor << '\n';
			plik << it.indeks << '\n';
			plik << it.cena << '\n';
			plik << it.liczba_stron << '\n';
			plik << it.status_wypozyczenia << '\n';
		}
	}
	else
	{
		std::cout << "Plik nie chce sie odpalic";
	}
	plik.close();
}
void input_ksiazki(std::span<Ksiazka>span_ksiazki) //odczytywanie
{
	std::ifstream plik("ksiazki.txt");
	std::string linijka;
	if (plik.is_open())
	{
		while (std::getline(plik, linijka))
			std::cout << '\n' << linijka;
	}
	else
	{
		std::cout << "Plik nie chce sie odpalic";
	}
	plik.close();
}

void podaj_liczby();
std::vector<int> odczyt_liczb();
std::pair<int, int> dzialania_na_liczby(std::vector<int>liczby);
int ile_linijek(std::string nazwa_pliku, int& puste_linie);
std::vector<char> odczyt_bajta();
void wynki(std::vector<char> znaki);

int main()
{
	/*int ilosc;
	std::cout << "Ilosc ksiazek: ";
	std::cin >> ilosc;
	Ksiazka* ksiazki = new Ksiazka[ilosc];
	dodawanie_ksiazek(ksiazki, ilosc);
	tanie_ksiazki(std::span<Ksiazka>(ksiazki, ilosc));
	nie_wyporzyczone_dlugie(std::span<Ksiazka>(ksiazki, ilosc));
	cena_strony(std::span<Ksiazka>(ksiazki, ilosc));
	na_K(std::span<Ksiazka>(ksiazki, ilosc));
	output_ksiazki(std::span<Ksiazka>(ksiazki, ilosc));
	input_ksiazki(std::span<Ksiazka>(ksiazki, ilosc));
	delete[]ksiazki;*/
	/*podaj_liczby();
	std::vector<int>liczby = odczyt_liczb();
	std::cout <<"Suma: " << dzialania_na_liczby(liczby).first << "\nSrednia artmetyczna: " << dzialania_na_liczby(liczby).second;*/
	/*std::string nazwa_pliku; int puste_linie = 0;
	std::cout << "Podaj nazwe pliku tekstowego: ";std::cin >> nazwa_pliku;
	std::cout << ile_linijek(nazwa_pliku, puste_linie) << "\nIlosc pustych linii: "<< puste_linie;*/
	//wynki(odczyt_bajta());
	//menu_osob();
	std::string imie, nazwisko; int wiek, pozycja;
	std::cout << "Podaj imie: ";std::cin >> imie;
	std::cout << "Podaj nazwisko: ";std::cin >> nazwisko;
	std::cout << "Podaj wiek: ";std::cin >> wiek;
	DoubleOsoba osoba1(imie, nazwisko, wiek);
	DoubleOsoba osoba2("Kacper", "Szczenka", 33);
	LinkedList lista;
	std::cout << "Podaj pozycje: ";std::cin >> pozycja;
	//lista.addycjaElementu(&osoba1, pozycja);
	lista.zamianaElementu(&osoba2, 1);

	return 0;
}

void podaj_liczby()
{
	std::string liczby;
	std::ofstream plik("liczby.txt");
	if (plik.is_open())
	{
		std::cout << "Podaj liczby po spacji: ";
		std::getline(std::cin, liczby);
		plik << liczby;
	}
	else
		std::cout << "Plik nie chce sie odpalic..";

	plik.close();
}
std::vector<int> odczyt_liczb()
{
	int liczba;
	std::vector <int> liczby;
	std::ifstream plik("liczby.txt");
	if (plik.is_open())
	{
		while (plik >> liczba)
		{
			liczby.push_back(liczba);
		}
	}
	else
		std::cout << "Plik nie chce sie otworzyc..";

	plik.close();
	return liczby;
}
std::pair<int, int> dzialania_na_liczby(std::vector<int>liczby)
{
	int suma = 0, sr_artmetyczna;
	for (size_t it : liczby)
	{
		suma += it;
	}
	sr_artmetyczna = suma / liczby.size();
	return { suma, sr_artmetyczna };
}
int ile_linijek(std::string nazwa_pliku, int& puste_linie)
{
	std::string linie, test_nazwa;
	int liczba_linii = 0;
	std::ifstream plik(nazwa_pliku + ".txt");
	if (plik.is_open())
	{
		std::cout << "Ilosc linii: ";
		while (std::getline(plik, linie))
		{
			liczba_linii++;
			if (linie.empty())
				puste_linie++;
		}
		return liczba_linii;
	}
	else
	{
		std::cout << "Plik nie che sie otworzyc / pewnie nie stnieje.\nPodaj nazwe jeszcze raz: ";std::cin >> test_nazwa;
	}
	return ile_linijek(test_nazwa, puste_linie);
}
std::vector<char> odczyt_bajta()
{
	std::vector<char> znaki;
	std::ifstream plik("bajty.txt", std::ios::binary);
	if (plik.is_open())
	{
		plik.seekg(0, std::ios::end);              // PrzejdŸ na koniec pliku
		std::streamsize rozmiar = plik.tellg();    // Pobierz pozycjê wskaŸnika (rozmiar)
		znaki.resize(rozmiar);
		plik.seekg(0, std::ios::beg);              // Wróæ na pocz¹tek pliku
		plik.read(znaki.data(), rozmiar);
	}
	else
		std::cout << "Plik nie che sie wczytac";
	return znaki;
}
void wynki(std::vector<char> znaki)
{
	int linijka = 0, znak = 0;
	std::sort(znaki.begin(), znaki.end());
	std::ofstream plik("wyniki.txt");
	if (plik.is_open())
	{
		for (size_t i = 0;i < znaki.size(); i++)
		{
			for (int j = linijka;j < znaki[i] - 1;j++)
			{
				plik << std::endl;
			}
			linijka = znaki[i];
			plik << "Ilosc " << znaki[i] << ": " << "+1 ";
		}
	}
}
