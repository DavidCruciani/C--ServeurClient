#pragma once

#include <vector>
#include "Simple.h"
#include "Triangle.h"
using namespace std;

class Polygone : public Simple
{
private:
	vector<Vecteur2D*> listePoints;
public:
	Polygone();
	Polygone(const string);
	Polygone(const Polygone&);
	~Polygone();

	void addPoint(Vecteur2D*);
	void delPoint(const Vecteur2D*);
	void delPoint(const int i);
	const Vecteur2D* operator[](const int i) const;

	operator string() const;

	virtual double getAire() const;
	virtual FormeGeometrique* cloner() const;
	virtual void dessiner();
	virtual void homothetie(const Vecteur2D&, const double);
	virtual void rotation(const Vecteur2D&, const double);
	virtual void translation(const Vecteur2D&);

	friend ostream & operator <<(ostream & os, const Polygone&);
};