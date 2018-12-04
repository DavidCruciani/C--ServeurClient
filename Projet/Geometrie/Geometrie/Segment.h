#pragma once
#ifndef _SEGMENT_
#define _SEGMENT_

#include"Simple.h"
using namespace std;

class Segment : public Simple
{
private:
	Vecteur2D v1, v2;
	Segment(const Segment&);
public:
	Segment();
	Segment(const string, const Vecteur2D&, const Vecteur2D&);
	Segment(const Vecteur2D&, const Vecteur2D&);
	~Segment();

	void setV1(const double, const double);
	void setV1(const double, const double);
	Vecteur2D* getV1() const;
	Vecteur2D* getV2() const;

	virtual void dessiner();
	virtual void rotation(const double);
	virtual void translation(const Vecteur2D&);
};
#endif