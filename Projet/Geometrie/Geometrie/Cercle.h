#pragma once
#include "Simple.h"
#include "Dessin.h"

using namespace std; 

class Cercle :public Simple
{
private:
	Vecteur2D vCentre;
	double rayon;
	void operator=(const Cercle&) ;
public:
	Cercle();
	Cercle(const Cercle&);
	Cercle(const double, const double, const double);
	Cercle(const string, const double, const double, const double);
	virtual ~Cercle();

	void setCentre(const double, const double);
	void setRayon(const double);
	Vecteur2D getCentre() const;
	double getRayon() const;

	virtual FormeGeometrique* cloner() const; 
	operator string()const;
	bool operator ==(const Cercle&)const;
	bool operator != (const Cercle & c)const { return !(*this == c); };

	virtual double getAire()const;

	virtual void dessiner(const Dessin&);

	//Transformations géométrique sur la forme
	virtual void homothetie(const Vecteur2D&, const double);
	virtual void rotation(const Vecteur2D&, const double);
	virtual void translation(const Vecteur2D&);
	//Transformations géométriques par copie
	virtual FormeGeometrique* homothetie2(const Vecteur2D&, const double);
	virtual FormeGeometrique* rotation2(const Vecteur2D&, const double);
	virtual FormeGeometrique* translation2(const Vecteur2D&);
};

