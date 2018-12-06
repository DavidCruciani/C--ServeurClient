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
	vector<Simple*> groupeSimple; 
	vector<Composee*> groupeComposee;
public:
	Composee();
	Composee(const string);
	~Composee();

	void addFormeSimple(const Simple*);
	void delFormeSimple(const Simple*);
	void delFormeSimple(const int);
	void addFormeComposee(const Composee*);
	void delFormeComposee(const Composee*);
	void delFormeComposee(const int);

	Composee* cloner();
	void dessiner();
	void Homotetie(const Vecteur2D&, const double);
	void rotation(const Vecteur2D&, const double);
	void translation(const Vecteur2D&);

	// VOIR POUR SURCHARGES OPERATEUR ET AFFICHAGE
};
#endif