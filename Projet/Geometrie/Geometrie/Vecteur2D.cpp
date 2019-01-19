#include "Vecteur2D.h"
#include <math.h>

//------------ implémentation des fonctions inline ----------------------

Vecteur2D::operator string() const
{
	ostringstream os;
	os << x << " " << y;
	return os.str();
}

Vecteur2D Vecteur2D::homothetie(const Vecteur2D & v, double scaleFactor) const
{
	double x1 = v.x + ((v.x-x) * scaleFactor);
	double y1 = v.y + ((v.y-y) * scaleFactor);

	return Vecteur2D(x1, y1);
}

ostream & operator <<(ostream & os, const Vecteur2D & u) {
	os << (string)u;
	return os;
}

double Vecteur2D::norme(const Vecteur2D& v)const {
	return sqrt( pow(v.x - x, 2) + pow(v.y - y, 2) );
}