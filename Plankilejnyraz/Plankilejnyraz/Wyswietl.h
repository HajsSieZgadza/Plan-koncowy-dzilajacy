#ifndef Wyswietl_h
#define Wyswietl_h
#include <iostream>
#include "Plan.h"

class Wyswietl
{
public:
	virtual void wyswietl(std::string a, Plan *x) = 0;
};

class Mechatronika : public Wyswietl
{
public:
	virtual void wyswietl(std::string a, Plan *x);
};

class Automatyka : public Wyswietl
{
public:
	virtual void wyswietl(std::string a, Plan *x);
};

#endif // !Wysiwtl_h

