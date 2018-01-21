#ifndef Przedmioty_h
#define Przedmioty_h
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>

class Przedmioty
{
public:
	std::vector<Przedmioty> przedmioty;
	std::string nazwa;
	Przedmioty() {};
	Przedmioty(std::string _nazwa) { nazwa = _nazwa; }
	void wczytaj(std::string s);
	int ilosc();
	void wyswietl();
};
#endif // !Przedmioty_h