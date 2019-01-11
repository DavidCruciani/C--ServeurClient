#include "TraitementPolygone.h"
#include "Polygone.h"

TraitementPolygone::TraitementPolygone(TraitementForme *suivant) : TraitementForme(suivant) {}

FormeGeometrique* TraitementPolygone::traiter1(const char *instruction) const {
	string couleur;
	if (sscanf_s(instruction, "Polygone (%s);", &couleur) != 0) {
		return new Polygone(couleur);
	}
	else
		return NULL;
}