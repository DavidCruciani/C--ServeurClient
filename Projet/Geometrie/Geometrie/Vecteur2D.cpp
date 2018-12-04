#include "Vecteur2D.h"

//------------ impl�mentation des fonctions inline ----------------------



Vecteur2D::operator string() const
{
	ostringstream os;
	os << "( " << x << ", " << y << ")";
	return os.str();
}

ostream & operator <<(ostream & os, const Vecteur2D & u) {
	os << (string)u;
	return os;
}
