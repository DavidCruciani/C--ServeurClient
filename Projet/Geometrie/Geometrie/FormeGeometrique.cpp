#include "FormeGeometrique.h"

FormeGeometrique::FormeGeometrique():couleur("Noir") {}

FormeGeometrique::FormeGeometrique(const string c):couleur("c") {}

FormeGeometrique::FormeGeometrique(const FormeGeometrique &f):couleur(f.couleur) {}

FormeGeometrique::~FormeGeometrique() {}

void FormeGeometrique::setCouleur(const string c) {
	if (couleur.compare(c) != 0)
		couleur = c;
}

string FormeGeometrique::getCouleur() const {
	return couleur;
}