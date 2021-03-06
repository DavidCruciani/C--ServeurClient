#include "TraitementTriangle.h"
#include "Triangle.h"

TraitementTriangle::TraitementTriangle(TraitementForme *suivant): TraitementForme(suivant) {}

FormeGeometrique* TraitementTriangle::traiter1(const char *instruction) const {
	// * Une instruction correcte est de la forme suivante:
	// * "Triangle(x1,y1,x2,y2,x3,y3,r)=couleur" 
	// * La couleur est optionnelle
	if (strstr(instruction, "Triangle") != NULL) {
		double x1, x2, x3, y1, y2, y3;		
		if (sscanf_s(instruction, "Triangle(%lf,%lf,%lf,%lf,%lf,%lf)", &x1, &y1, &x2, &y2, &x3, &y3) != 0) {
			if (strchr(instruction, '=') != NULL) {
				// Si la couleur est pr�cis�e
				string couleur = strchr(instruction, '=');
				couleur = couleur.substr(1, couleur.size());
				return new Triangle(couleur, x1, y1, x2, y2, x3, y3);
			}
			else
				return new Triangle(x1, y1, x2, y2, x3, y3);
		}
	}
	else // La forme demand�e n'est pas un triangle
		return NULL;
}