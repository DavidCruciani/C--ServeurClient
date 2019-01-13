#include "Vecteur2D.h"
#include <math.h>

//------------ implémentation des fonctions inline ----------------------

Vecteur2D::operator string() const
{
	ostringstream os;
	os << x << " " << y;
	return os.str();
}

ostream & operator <<(ostream & os, const Vecteur2D & u) {
	os << (string)u;
	return os;
}

double Vecteur2D::norme(const Vecteur2D& v)const {
	return sqrt( pow(v.x - x, 2) + pow(v.y - y, 2) );
}