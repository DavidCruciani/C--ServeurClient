#include "Vecteur2D.h"

//------------ implémentation des fonctions inline ----------------------



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
