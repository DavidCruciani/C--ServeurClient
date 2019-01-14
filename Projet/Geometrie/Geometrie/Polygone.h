#pragma once

#include <vector>
#include "Simple.h"
#include "Triangle.h"
using namespace std;

class Polygone : public Simple
{
private:
	vector<Vecteur2D*> listePoints;
	int nbPts=0;
public:
	Polygone();
	Polygone(const string);
	Polygone(const Polygone&);
	Polygone(Vecteur2D*, Vecteur2D*, Vecteur2D*, Vecteur2D*);
	~Polygone();

	vector<Vecteur2D*> getListe() const;
	int getPts() const;
	void setPts(int) ;

	void addPoint(Vecteur2D*);
	void delPoint(const Vecteur2D*);
	void delPoint(const int i);
	const Vecteur2D* operator[](const int i) const;

	operator string() const;

	virtual double getAire() const;
	virtual FormeGeometrique* cloner() const;
	virtual void dessiner(const Dessin&);

	//Transformations géométrique sur la forme
	virtual void homothetie(const Vecteur2D&, const double);
	virtual void rotation(const Vecteur2D&, const double);
	virtual void translation(const Vecteur2D&);
	//Transformations géométriques par copie
	virtual FormeGeometrique* homothetie2(const Vecteur2D&, const double);
	virtual FormeGeometrique* rotation2(const Vecteur2D&, const double);
	virtual FormeGeometrique* translation2(const Vecteur2D&);

	friend ostream & operator <<(ostream & os, const Polygone&);
};