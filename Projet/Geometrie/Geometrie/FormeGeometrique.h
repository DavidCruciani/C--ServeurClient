#pragma once
#ifndef _FORMEGEOMETRIQUE_
#define _FORMEGEOMETRIQUE_

#include "Vecteur2D.h"
#include <string>
using namespace std;

class FormeGeometrique
{
protected:
	string couleur; // TEMPORAIRE
public:
	FormeGeometrique(); //Met la couleur par défaut à noir
	FormeGeometrique(const string);
	FormeGeometrique(const FormeGeometrique&);
	~FormeGeometrique();

	void setCouleur(const string);
	string getCouleur() const;

	virtual void dessiner() = 0;
	virtual double getAire() const = 0;
	virtual FormeGeometrique* cloner() const = 0;
	virtual void homothetie(const Vecteur2D&, const double) = 0;
	virtual void rotation(const Vecteur2D&, const double) = 0;
	virtual void translation(const Vecteur2D&) = 0;

	// VOIR POUR SURCHARGES OPERATEUR ET AFFICHAGE
};
#endif