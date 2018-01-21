#include"Wyswietl.h"
using namespace std;

void Mechatronika::wyswietl(string a, Plan *x)
{
	x->wczytajPlan(a);
	cout << x->plan[0].kierunek << endl << x->plan[0].dzien << endl << x->plan[0].godzina << " " << x->plan[0].przedmiot << " " << x->plan[0].wykladowca << " " << x->plan[0].sala << endl;
	for (int i = 1; i <x->ilosc()/2; i++)
	{
		if (x->plan[i].kierunek == "Mechatronika")
		{
				if (x->plan[i].kierunek != x->plan[i - 1].kierunek)	cout << x->plan[i].kierunek << endl;
				if (x->plan[i].dzien != x->plan[i - 1].dzien)	cout << x->plan[i].dzien << endl;
				cout << x->plan[i].godzina << " " << x->plan[i].przedmiot << " " << x->plan[i].wykladowca << " " << x->plan[i].sala << endl;
		}
	}
}
void Automatyka::wyswietl(string a, Plan *x)
{
	x->wczytajPlan(a);
	for (int i = x->ilosc() / 2+1; i <x->ilosc(); i++)
	{
		if (x->plan[i].kierunek == "Automatyka")
		{
			if (x->plan[i].kierunek != x->plan[i - 1].kierunek)	cout << x->plan[i].kierunek << endl;
			if (x->plan[i].dzien != x->plan[i - 1].dzien)	cout << x->plan[i].dzien << endl;
			cout << x->plan[i].godzina << " " << x->plan[i].przedmiot << " " << x->plan[i].wykladowca << " " << x->plan[i].sala << endl;
		}
	}
}