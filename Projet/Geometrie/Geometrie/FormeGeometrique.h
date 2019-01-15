#pragma once
#ifndef _FORMEGEOMETRIQUE_
#define _FORMEGEOMETRIQUE_

#include "Vecteur2D.h"
#include <string>
using namespace std;
class Dessin;

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

	virtual void dessiner(const Dessin&) = 0;
	virtual double getAire() const = 0;
	virtual FormeGeometrique* cloner() const = 0;
	virtual operator string()const = 0;
	//Transformations géométrique sur la forme
	virtual void homothetie(const Vecteur2D&, const double) = 0;
	virtual void rotation(const Vecteur2D&, const double) = 0;
	virtual void translation(const Vecteur2D&) = 0;
	//Transformations géométriques par copie
	virtual FormeGeometrique* homothetie2(const Vecteur2D&, const double) = 0;
	virtual FormeGeometrique* rotation2(const Vecteur2D&, const double) = 0;
	virtual FormeGeometrique* translation2(const Vecteur2D&) = 0;
	// VOIR POUR SURCHARGES OPERATEUR ET AFFICHAGE
	friend ostream& operator<<(ostream&, const FormeGeometrique*);
};
#endif