#include "Sale.h"

using namespace std;

void Sale::wczytaj(string s)
{
	ifstream plik(s);
	string linie;
	while (getline(plik, linie))
	{
		stringstream wczytaj(linie);
		string przedmiot, prowadzacy, numerSali;
		char numerS;
		wczytaj >> numerSali;
		wczytaj.ignore();
		wczytaj >> typSali;
		sale.push_back(Sale(numerSali, typSali));
	}
	plik.close();
}

void Sale::zapisz(string s)
{
	ofstream plik(s);
	for (int i = 0; i < ilosc(); i++)
	{
		plik << numerSali << " " << typSali << endl;
	}
	plik.close();
}

int Sale::ilosc()
{
	return sale.size();
}

void Sale::wyswietl(string wyb)
{
	for (int i = 0; i < ilosc(); i++)
	{
		if (sale[i].typSali == wyb) cout << sale[i].numerSali << " ";
	}
	cout << endl;
}