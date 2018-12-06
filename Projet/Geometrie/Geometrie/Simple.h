#pragma once
#ifndef _SIMPLE_
#define _SIMPLE_

#include"FormeGeometrique.h"
using namespace std;

class Simple : public FormeGeometrique
{
private:
	Simple(const Simple&);
public:
	Simple();
	Simple(const string);
	~Simple();

	virtual double getAire() const = 0;
	virtual Simple* cloner() const = 0;
	virtual void dessiner() = 0;
	virtual void homothetie(const Vecteur2D&, const double) = 0;
	virtual void rotation(const Vecteur2D&, const double) = 0;
	virtual void translation(const Vecteur2D&) = 0;

	// VOIR POUR SURCHARGES OPERATEUR ET AFFICHAGE
};
#endif