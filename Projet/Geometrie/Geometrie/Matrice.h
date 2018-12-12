#pragma once
#ifndef _Matrice_
#define _Matrice_

#include <vector>
#include <ostream>
#include "Vecteur2D.h"

class Matrice
{
private:
	int rang;
	vector<double> valeurs;
public:
	Matrice();
	Matrice(const int);
	Matrice(const Matrice&);
	~Matrice();

	void setRang(const int);
	int getRang() const;

	void addValeur(const double, const int, const int);
	void delValeur(const double);
	void delValeur(const int);
	double getValeur(const int);

	double operator*(const Vecteur2D&);

	operator string() const;
	friend ostream& operator<<(ostream&, Matrice&);
};
#endif