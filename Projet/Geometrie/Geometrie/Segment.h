#pragma once
#ifndef _SEGMENT_
#define _SEGMENT_

#include"Simple.h"
using namespace std;

class Segment : public Simple
{
private:
	Vecteur2D v1, v2;
public:
	Segment();
	Segment(const Segment&);
	Segment(const string, const double, const double, const double, const double);
	Segment(const double, const double, const double, const double);
	~Segment();

	void setV1(const double, const double);
	void setV2(const double, const double);
	Vecteur2D getV1() const;
	Vecteur2D getV2() const;

	operator string()const;

	virtual double getAire() const;
	virtual FormeGeometrique* cloner() const;
	virtual void dessiner();
	virtual void homothetie(const Vecteur2D&, const double);
	virtual void rotation(const Vecteur2D&, const double);
	virtual void translation(const Vecteur2D&);

	friend ostream & operator <<(ostream & os, const Segment &);
};
#endif