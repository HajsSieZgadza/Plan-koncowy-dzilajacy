#include "Wykladowcy.h"
using namespace std;

Wykladowcy::Wykladowcy(string _nazwisko, string _przedmiot)
{
	nazwisko = _nazwisko;
	przedmiot = _przedmiot;
}

void Wykladowcy::wczytajProwadzacych(string s)
{
	ifstream plik(s);
	string linie, _nazwisko, _przedmiot;
	while (getline(plik, linie))
	{
		stringstream rasputin(linie);

		rasputin >> _nazwisko;
		rasputin.ignore();
		rasputin >> _przedmiot;
		prowadzacy.push_back(Wykladowcy(_nazwisko, _przedmiot));
	}
	plik.close();
}

void Wykladowcy::wyswietlProwadzacych(string s)
{
	for (int i = 0; i < ilosc(); i++)
	{
		if (s == prowadzacy[i].przedmiot)
			cout << prowadzacy[i].nazwisko << endl;
	}
}

int Wykladowcy::ilosc()
{
	return prowadzacy.size();
}