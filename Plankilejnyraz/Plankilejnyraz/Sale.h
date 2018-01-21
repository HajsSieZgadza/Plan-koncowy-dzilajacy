#ifndef Sale_h
#define Sale_h
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>

class Sale
{
public:
	std::vector<Sale> sale;
	std::string numerSali, typSali;

	Sale() {};
	Sale(std::string _numerSali, std::string _typSali)
	{
		numerSali = _numerSali;
		typSali = _typSali;
	}

	void wczytaj(std::string s);
	void zapisz(std::string s);
	int ilosc();
	void wyswietl(std::string wyb);
};

#endif // !Plan_h
#pragma once
