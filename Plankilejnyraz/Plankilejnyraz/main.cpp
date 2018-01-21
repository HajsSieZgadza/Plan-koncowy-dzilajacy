#include"Plan.h"
#include"Przedmioty.h"
#include"Sale.h"
#include"Wyswietl.h"

using namespace std;

int main()
{
	Plan pl;
	Przedmioty prz;
	Wykladowcy wyk;
	Sale sal;
	Mechatronika mech;
	Automatyka aut;
	Wyswietl *wsk;
	wsk = &mech;
	string a = "Przedmioty.txt", b = "Plan.txt", c = "Wykladowcy.txt", d = "Sale.txt";

	prz.wczytaj(a);
	wyk.wczytajProwadzacych(c);
	sal.wczytaj(d);
	pl.wczytajPlan(b);

	cout << "~~Menu~~\n1) Generuj plan\n2) Wyswietl caly plan\n3) Wyswietl plan dla kierunku";
	char wybor1;
	cin >> wybor1;
	switch (wybor1)
	{
	case '1':
	{
		pl.stworzPlan(&prz, &wyk, &sal);
		pl.zapiszPlan(pl, b);
	}
	break;
	case '2':
	{
		pl.wyswietlPlan();
	}
	break;
	case '3':
	{
		char wybor2;
		cout << "Wybierz kierunek 1)Mechatronika  2)Atomatyka\n";
		cin >> wybor2;
		if (wybor2 == '1')
		{
			wsk = &mech;
		}
		if (wybor2 == '2')
		{
			wsk = &aut;
		}
		wsk->wyswietl(b,&pl);
	}
	break;
	default:
		break;
	}





	system("pause");
	return 0;
}