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

	// VOIR POUR SURCHARGES OPERATEUR ET AFFICHAGE
};
#endif