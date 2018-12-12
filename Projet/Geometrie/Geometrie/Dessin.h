#pragma once

#include "Connexion.h"

class Cercle;
class Polygone;
class Segment;
class Triangle;
class FormeGeometrique;

class Dessin
{
private:
	Connexion* connexion;
public:
	Dessin(Connexion *);
	virtual ~Dessin();

	void dessinerCercle(const Cercle &)const;
	void dessinerTriangle(const Triangle &)const;
	void dessinerSegment(const Segment &)const;
	void dessinerPolygone(const Polygone &)const;

	void dessiner(const FormeGeometrique& )const;
};

