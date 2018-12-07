#pragma once
#ifndef _COMPOSEE_
#define _COMPOSEE_

#include "FormeGeometrique.h"
#include "Simple.h"
#include <string>
#include <vector>
using namespace std;

class Composee : public FormeGeometrique
{
private:
	vector<FormeGeometrique*> groupe; 
public:
	Composee();
	Composee(const string);
	~Composee();

	void addForme(const FormeGeometrique*);
	void delForme(const FormeGeometrique*);
	void delForme(const int);

	virtual double getAire() const;
	
	virtual FormeGeometrique* cloner() const;
	virtual void dessiner();
	virtual void homothetie(const Vecteur2D&, const double);
	virtual void rotation(const Vecteur2D&, const double);
	virtual void translation(const Vecteur2D&);

	// VOIR POUR SURCHARGES OPERATEUR ET AFFICHAGE
};
#endif