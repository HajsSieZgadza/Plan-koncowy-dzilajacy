#include "Plan.h"

using namespace std;

Plan::Plan() {};

Plan::Plan(std::string _kierunek, std::string _dzien, int _godzina, std::string _przedmiot, std::string _wykladowca, std::string _sala)
{
	kierunek = _kierunek;
	dzien = _dzien;
	godzina = _godzina;
	przedmiot = _przedmiot;
	wykladowca = _wykladowca;
	sala = _sala;
}

void Plan::stworzPlan(Przedmioty *x, Wykladowcy *y, Sale *z)
{
	string newKierunek, newDzien, newPrzedmiot, newWykladowca, typs,newNumer;
	for (int i = 0; i < 2; i++)			//i < od ilosci kierunkow
	{
		if (i == 0)
		{
			newKierunek = "Mechatronika";
			cout << "Mechatronika\n";
		}
		else
		{
			newKierunek = "Automatyka";
			cout << "Automatyka\n";
		}
		for (int j = 0; j < 5; j++)
		{
			switch (j)
			{
			case 0:
			{
				cout << "Poniedzialek\n";
				newDzien = "Poniedzialek";
			}
			break;
			case 1:
			{
				cout << "Wtorek\n";
				newDzien = "Wtorek";
			}
			break;
			case 2:
			{
				cout << "Sroda\n";
				newDzien = "Sroda";
			}
			break;
			case 3:
			{
				cout << "Czwartek\n";
				newDzien = "Czwartek";
			}
			break;
			case 4:
			{
				cout << "Piatek\n";
				newDzien = "Piatek";
			}
			break;
			}

			for (int k = 0; k < 6; k++)
			{
				cout << "Wybierz przedmiot\n";
				x->wyswietl();
				cin >> newPrzedmiot;
				cout << "Wybierz wykladowca\n";
				y->wyswietlProwadzacych(newPrzedmiot);
				cin >> newWykladowca;
				////
				if(i==1)
				{
					while (plan[j].dzien == plan[j].dzien && plan[k].godzina == plan[k].godzina && newWykladowca == plan[k].wykladowca)
					{
						cout << "Wykladowca zajety wybierz innego!!";
						Sleep(1000);
						system("cls");
						cout << "Wybierz wykladowca\n";
						y->wyswietlProwadzacych(newPrzedmiot);
						cin >> newWykladowca;
						break;
					}
				}
				////
				cout << "Wybierz typ sali : Aula, Komputerowa, Laboratorium\n";
				cin >> typs;
				cout << "Wybierz numer sali\n";
				z->wyswietl(typs);
				cin >> newNumer;
				////
				if (i == 1)
				{
					while (plan[j].dzien == plan[j].dzien && plan[k].godzina == plan[k].godzina && plan[k].sala == plan[k].sala)
					{
						cout << "Sala zajeta wybierz inna";
						Sleep(1000);
						system("cls");
						cout << "Wybierz numer sali\n";
						z->wyswietl(typs);
						cin >> newNumer;
						break;
					}
				}
				////
				////
				plan.push_back(Plan(newKierunek, newDzien, k+1, newPrzedmiot, newWykladowca, newNumer));
			}

		}
	}
}

int Plan::ilosc()
{
	return plan.size();
}

void Plan::zapiszPlan(Plan& dane, std::string s)
{
	ofstream zapis(s);
	for (int i = 0; i<ilosc(); i++)
	{
		zapis << plan[i].kierunek << " " << plan[i].dzien << " " << plan[i].godzina << " " << plan[i].przedmiot << " " << plan[i].wykladowca << " " << plan[i].sala << endl;
	}
	zapis.close();
}

void Plan::wyswietlPlan()
{
	cout << plan[0].kierunek << endl << plan[0].dzien << endl << plan[0].godzina << " " << plan[0].przedmiot << " " << plan[0].wykladowca << " " << plan[0].sala << endl;
	for (int i = 1; i < ilosc(); i++)
	{
		if (plan[i].kierunek != plan[i - 1].kierunek)	cout << plan[i].kierunek<<endl;
		if (plan[i].dzien != plan[i - 1].dzien)	cout << plan[i].dzien << endl;
		cout << plan[i].godzina << " " << plan[i].przedmiot << " " << plan[i].wykladowca << " " << plan[i].sala << endl;

	}
}

void Plan::wczytajPlan(string s)
{
	ifstream plik(s);
	string linie,kierunek,dzien,przedmiot,wykladowca,sala;
	int godzina;
	while (getline(plik, linie))
	{
		stringstream wczyt(linie);
		wczyt >> kierunek;
		wczyt.ignore();
		wczyt >> dzien;
		wczyt.ignore();
		wczyt >> godzina;
		wczyt.ignore();
		wczyt >> przedmiot;
		wczyt.ignore();
		wczyt >> wykladowca;
		wczyt.ignore();
		wczyt >> sala;
		wczyt.ignore();
		plan.push_back(Plan(kierunek, dzien, godzina, przedmiot, wykladowca, sala));
	}
	plik.close();
}