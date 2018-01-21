#ifndef Plan_H
#define Plan_H
#include<vector>
#include<sstream>
#include<fstream>
#include<iostream>
#include<string>
#include"Przedmioty.h"
#include"Wykladowcy.h"
#include"Sale.h"
#include<Windows.h>
class Plan
{
public:
	std::string kierunek, dzien, przedmiot, wykladowca, sala;
	int godzina;
	std::vector<Plan> plan;
	Plan();
	Plan(std::string _kierunek, std::string _dzien, int _godzina, std::string _przedmiot, std::string _wykladowca, std::string _sala);

	void stworzPlan(Przedmioty *x,Wykladowcy *y,Sale *z);
	void zapiszPlan(Plan& dane, std::string s);
	int ilosc();
	void wyswietlPlan();
	void wczytajPlan(std::string s);
};

#endif // Plan_H
