#include "TraitementCercle.h"
#include "Cercle.h"

TraitementCercle::TraitementCercle(TraitementForme *suivant): TraitementForme(suivant) {}

FormeGeometrique* TraitementCercle::traiter1(const char *instruction) const{
	// * Une instruction correcte est de la forme suivante:
	// * "Cercle(x,y,r)=couleur" 
	// * La couleur est optionnelle
	if (strstr(instruction, "Cercle") != NULL) {
		double x, y, r;
		if (sscanf_s(instruction, "Cercle(%lf,%lf,%lf);", &x, &y, &r) != 0) {
			if (strchr(instruction, '=') != NULL) {
				// Si on pr�scise la couleur de la forme
				string couleur = strchr(instruction, '=');
				couleur = couleur.substr(1, couleur.size());
				FormeGeometrique *c = new Cercle(couleur, x, y, r);
				return c;
			}
			else {
				FormeGeometrique *c = new Cercle(x, y, r);
				return c;
			}
		}
	}
	else // La forme demand�e ne correspond pas � un cercle
		return NULL;
}