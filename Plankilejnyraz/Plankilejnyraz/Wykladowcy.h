#ifndef Wykladowcy_h
#define Wykladowcy_h

#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<fstream>

class Wykladowcy
{
public:
	std::vector<Wykladowcy> prowadzacy;
	std::string nazwisko, przedmiot;
	Wykladowcy() {};
	Wykladowcy(std::string _nazwisko, std::string _przedmiot);
	void wczytajProwadzacych(std::string s);
	void wyswietlProwadzacych(std::string s);
	int ilosc();
};




#endif#pragma once
