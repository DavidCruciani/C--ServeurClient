#pragma once
#ifndef _COMPOSEE_
#define _COMPOSEE_

#include "FormeGeometrique.h"
#include "Simple.h"
#include <string>
#include <vector>
#include "Dessin.h"
using namespace std;

class Composee : public FormeGeometrique
{
private:
	vector<FormeGeometrique*> groupe; 
public:
	Composee();
	Composee(const string);
	~Composee();

	void addForme(FormeGeometrique*);
	void delForme(const FormeGeometrique*);
	void delForme(const int);
	FormeGeometrique* getForme(const int);

	virtual double getAire() const;
	
	virtual FormeGeometrique* cloner() const;
	virtual void dessiner(const Dessin&);
	operator string()const;
	
	//Transformations géométrique sur la forme
	virtual void homothetie(const Vecteur2D&, const double);
	virtual void rotation(const Vecteur2D&, const double);
	virtual void translation(const Vecteur2D&);
	//Transformations géométriques par copie
	virtual FormeGeometrique* homothetie2(const Vecteur2D&, const double);
	virtual FormeGeometrique* rotation2(const Vecteur2D&, const double);
	virtual FormeGeometrique* translation2(const Vecteur2D&);

	// VOIR POUR SURCHARGES OPERATEUR ET AFFICHAGE
};
#endif