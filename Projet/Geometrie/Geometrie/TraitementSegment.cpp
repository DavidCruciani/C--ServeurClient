#include "TraitementSegment.h"
#include "Segment.h"

TraitementSegment::TraitementSegment(TraitementForme *suivant):TraitementForme(suivant) {}

FormeGeometrique* TraitementSegment::traiter1(const char *instruction) const {
	// * Une instruction correcte est de la forme suivante:
	// * "Segment(x1,y1,x2,y2,r)=couleur" 
	// * La couleur est optionnelle
	if (strstr(instruction, "Segment") != NULL) {
	double x1, x2, y1, y2;if (sscanf_s(instruction, "Segment(%lf,%lf,%lf,%lf)", &x1, &y1, &x2, &y2) != 0) {
		if (strchr(instruction, '=') != NULL) {
			// Si la couleur est précisée
			string couleur = strchr(instruction, '=');
			couleur = couleur.substr(1, couleur.size());
			FormeGeometrique *s = new Segment(couleur, x1, y1, x2, y2);
			return s;
		}
		else {
			FormeGeometrique *s = new Segment(x1, y1, x2, y2);
			return s;
		}
		}
	}
	else //La forme demandée n'est pas un segment
		return NULL;
}