#include "Przedmioty.h"
using namespace std;

void Przedmioty::wczytaj(string s)
{
	ifstream plik(s);
	string linie;
	while (getline(plik, linie))
	{
		stringstream wczytaj(linie);
		string nanzwa;
		wczytaj >> nazwa;
		przedmioty.push_back(Przedmioty(nazwa));
	}
	plik.close();
}

void Przedmioty::wyswietl()
{
	for (int i = 0; i < ilosc(); i++)
	{
		cout << przedmioty[i].nazwa << endl;
	}
}

int Przedmioty::ilosc()
{
	return przedmioty.size();
}