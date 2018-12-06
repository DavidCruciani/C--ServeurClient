#pragma once
#ifndef _TRIANGLE_
#define _TRIANGLE_

#include "Simple.h"
using namespace std;

class Triangle : public Simple
{
private:
	Vecteur2D v1, v2, v3;
	Triangle(const Triangle&);
public:
	Triangle();
	Triangle(const string, const double, const double, const double, const double, const double, const double);
	Triangle(const double, const double, const double, const double, const double, const double);
	~Triangle();

	void setV1(const double, const double);
	void setV2(const double, const double);
	void setV3(const double, const double);
	Vecteur2D getV1() const;
	Vecteur2D getV2() const;
	Vecteur2D getV3() const;

	virtual double getAire() const;
	virtual Simple* cloner() const;
	virtual void dessiner();
	virtual void homothetie(const Vecteur2D&, const double);
	virtual void rotation(const Vecteur2D&, const double);
	virtual void translation(const Vecteur2D&);
};
#endif