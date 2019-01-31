#include "TraitementCercle.h"
#include "Cercle.h"
#include "Erreur.h"

TraitementCercle::TraitementCercle(TraitementForme *suivant): TraitementForme(suivant) {}

FormeGeometrique* TraitementCercle::traiter1(const char *instruction) const{
	// * Une instruction correcte est de la forme suivante:
	// * "Cercle(x,y,r)=couleur" 
	// * La couleur est optionnelle
	if (strstr(instruction, "Cercle") != NULL) {
		double x, y, r;
		FormeGeometrique *c;
		if (sscanf_s(instruction, "Cercle(%lf,%lf,%lf);", &x, &y, &r) != 0) {
			if (strchr(instruction, '=') != NULL) {
				// Si on préscise la couleur de la forme
				string couleur = strchr(instruction, '=');
				couleur = couleur.substr(1, couleur.size());
				try {
					c = new Cercle(couleur, x, y, r);
				}
				catch (Erreur erreur) {
					cerr << erreur << endl;
				}
				return c;
			}
			else {
				try {
					c = new Cercle(x, y, r);
				}
				catch (Erreur erreur) {
					cerr << erreur << endl;
				}
				return c;
			}
		}
	}
	else // La forme demandée ne correspond pas à un cercle
		return NULL;
}