// Menu.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include <iostream>
#include <conio.h>
#include <tuple>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
void peselCheck2(std::vector<int>liczby)
{
    int suma=0;
    int cyfra_ostatnia_suma;
    int wynik;
    int wspolczynniki[10] = { 1,3,7,9,1,3,7,9,1,3 };
    for (int i = 0;i < 10;i++) {
        suma += liczby[i] * wspolczynniki[i];
    }
    cyfra_ostatnia_suma = suma % 10;
    wynik = (10 - cyfra_ostatnia_suma) % 10;
    if (wynik == liczby[10])
        std::cout << "Poprawny\n";
    else {
        std::cout << "Nie poprawny\n";
        std::cout << "Ostatnia cyfra to: " << cyfra_ostatnia_suma << std::endl << "A wynik to: " << wynik<<std::endl;
    }
}
void Pesel()
{
    int number = 0, inted_str = 0;
    std::string pesel;
    std::vector <int>inted_vect;//(pesel.begin(),pesel.end());
    std::vector <std::string>pesel_container;
    std::cout << "Podaj swoj pesel: ";
    std::cin >> pesel;
    for (std::string::iterator it = pesel.begin(); it != pesel.end(); ++it) {
        int converted = ((int)*it) - '0';
        inted_vect.push_back(converted);
    }
    peselCheck2(inted_vect);
}

int getArrowKeysMovement()
{
    int arrow;
    do
    {
        arrow = _getch();
        if (arrow == 224)
            arrow = _getch();
    } while (!(arrow == 72 || arrow == 80 || arrow == 13 || arrow == 27));
    return arrow;
}
void forTreeNumbers()
{   
    std::cout << "Podaj 3 cyfrowa liczba: ";
    int liczba;
    std::cin >> liczba;
    int biggestNum = 0, smallestNum = 9, mediana = 0;
    std::vector<int> cyfry = { 0, 0, 0 };
    for (int i = 0;i < 3;i++)
    {   
        cyfry[i] = liczba % 10;
        liczba /= 10;
        
        if (cyfry[i] > biggestNum)
        {
            biggestNum = cyfry[i];
        }
        if (cyfry[i] < smallestNum)
        {
            smallestNum = cyfry[i];
        }
    }
    std::sort(cyfry.begin(), cyfry.end());
    mediana = cyfry[1];
    std::cout << "\nNajwieksza cyfra to: " << biggestNum << "\nNajmniejsza cyftra to: "<< smallestNum<<"\nMediana to: "<< mediana<< "\nCyfry ustawione rosnaco: ";
    for (std::vector<int>::iterator it = cyfry.begin(); it != cyfry.end(); ++it)
            std::cout<< *it<< ' ';
    for (int j = 0;j < 2;j++)
    {
        if (cyfry[j] == cyfry[j + 1])
        {
            std::cout << "\nPowtorka: " << cyfry[j];
        }
    }
    std::cout << '\n';
}

void promien()
{
    double r, obwod, pole;
    std::cout << "Dla kola o promieniu: ";std::cin >> r;
    const double pi = 3.141592;
    obwod = 2 * pi * r;
    pole = pi * (r * r);
    std::cout<<"\nObwod: " << obwod << "\nPole: " << pole;
}
void trojkat()
{
    double a, b, c, suma;
    std::cout << "Podaj dlugosci bokow trojkata\n";
    std::cout << "a = ";std::cin >> a;
    std::cout << "b = ";std::cin >> b;
    std::cout << "c = ";std::cin >> c;
    suma = a + b + c;
    std::vector <double> boki = { a, b, c };
    std::sort(boki.begin(), boki.end());
    if (boki.back() < suma - boki.back())
        std::cout << "Poprawny trojkat";
    else
        std::cout << "Nie poprawny trojkat";
}

void binary(int deciNumber)
{
    std::vector <int> binaryNumbers;
    for (int i = 256;i > 0;i /= 2) {
        if (deciNumber >= i) {
            binaryNumbers.push_back(1);
            deciNumber -= i;
        }
        else
            binaryNumbers.push_back(0);
    }
    for (std::vector<int>::iterator it = binaryNumbers.begin(); it != binaryNumbers.end(); ++it)
        std::cout << *it;

}
void hexadecimal(int deciNumber)
{   
    int iloraz;
    char test;
    std::vector <int> hexNumbers;
    for (int i = 65536;i > 0;i /= 16) {
        if (deciNumber >= i) {
            iloraz = deciNumber / i;
            hexNumbers.push_back(iloraz);
            deciNumber -= iloraz * i;
        }
        else
            hexNumbers.push_back(0);
    }
    std::map<int, char> definicje;
    definicje[10] = 'A';
    definicje[11] = 'B';
    definicje[12] = 'C';
    definicje[13] = 'D';
    definicje[14] = 'E';
    definicje[15] = 'F';
    for (std::vector<int>::iterator it = hexNumbers.begin(); it != hexNumbers.end(); ++it)
        if (*it > 9)
            std::cout << definicje[*it];
        else
            std::cout << *it;
}
void BinaryAndHexConvert()
{
    int deciNumber;
    std::cout << "Podaj numer: ";std::cin >> deciNumber;
    std::cout << "W systemie binarnym: "; binary(deciNumber);
    std::cout << "\nW systemie szesnastkowym: ";hexadecimal(deciNumber);

}
std::string colouring(std::string text, std::tuple<uint8_t, uint8_t, uint8_t> fgRGB, std::tuple<uint8_t, uint8_t, uint8_t> bgRGB)
{
    std::string out = "";
    out.append("\033[38;2");
    out.append(";");
    out.append(std::to_string(std::get<0>(fgRGB)));
    out.append(";");
    out.append(std::to_string(std::get<1>(fgRGB)));
    out.append(";");
    out.append(std::to_string(std::get<2>(fgRGB)));
    out.append(";48;2");
    out.append(";");
    out.append(std::to_string(std::get<0>(bgRGB)));
    out.append(";");
    out.append(std::to_string(std::get<1>(bgRGB)));
    out.append(";");
    out.append(std::to_string(std::get<2>(bgRGB)));
    out.append("m");
    out.append(text);
    out.append("\033[0m");
    return out;
}
int main() {
    std::tuple<uint8_t, uint8_t, uint8_t> kolorTla, kolorTekst, defaultKolorTla, defaultKolorTekst;
    kolorTekst = { 255, 255, 255 };
    kolorTla = { 0, 34, 206 };
    defaultKolorTekst = { 255, 255, 255 };
    defaultKolorTla = { 0, 0, 0 };
    int znak = 0;
    int ilosc;
    int nrLini = 0;
    std::vector<void (*)()> funkcje = { Pesel, forTreeNumbers, promien, trojkat, BinaryAndHexConvert};
    std::vector<std::string> menu = { "1.Pesel", "2.Dla 3 liczb", "3.Znajac Promien", "4.Trojkat","5.NumberInBinaryand16"};
    ilosc = menu.size();

    do {
        std::cout << "\nWybierz" << std::endl;
        for (int i = 0; i < ilosc; i++) {
            std::cout << colouring(menu[i], i == nrLini ? kolorTekst : defaultKolorTekst, i == nrLini ? kolorTla : defaultKolorTla) << std::endl;
        }
        znak = getArrowKeysMovement();
        system("cls");   //upgarding menu
        if (znak == 72)
            nrLini--;
        if (znak == 80)
            nrLini++;
        if (nrLini >= ilosc)
            nrLini = ilosc - 1;
        if (nrLini < 0)
            nrLini = 0;
        if (znak == 13) {
            funkcje[nrLini]();
        }

    } while (znak != 27);

}


// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
