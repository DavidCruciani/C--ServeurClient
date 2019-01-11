#include "TraitementCercle.h"
#include "Cercle.h"

TraitementCercle::TraitementCercle(TraitementForme *suivant): TraitementForme(suivant) {}

FormeGeometrique* TraitementCercle::traiter1(const char *instruction) const{
	string couleur;
	double x, y, r;
	if (sscanf_s(instruction, "Cercle (%s,%lf,%lf,%lf);", &couleur, &x, &y, &r) != 0) {
		return new Cercle(couleur, x, y, r);
	}
	else if (sscanf_s(instruction, "Cercle (%lf,%lf,%lf);", &x, &y, &r) != 0) {
		return new Cercle(x, y, r);
	}
	else
		return NULL;
}