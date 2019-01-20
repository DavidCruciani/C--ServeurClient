#include "TraitementPolygone.h"
#include "Polygone.h"

TraitementPolygone::TraitementPolygone(TraitementForme *suivant) : TraitementForme(suivant) {}

FormeGeometrique* TraitementPolygone::traiter1(const char *instruction) const {
	// * Une instruction correcte est de la forme suivante:
	// * "Polygone{=couleur;(x1,y1)(x2,y2) ... (xn,yn)}" 
	// * La couleur est optionnelle
	if (strstr(instruction, "Polygone") != NULL) {
		string ins, donnee;
		size_t posDeb, posPoint, posFin;
		ins = instruction;
		posDeb = ins.find("{");
		donnee = ins.substr(0, posDeb+1);
		if (donnee == "Polygone{") {
			Polygone *p = new Polygone();
			if (strchr(instruction, '=') != NULL) {
				// Si la couleur est précisée
				string couleur = strchr(instruction, '=');
				posFin = couleur.find(";");
				couleur = couleur.substr(1, posFin-1);
				p->setCouleur(couleur);
			}							
			posDeb = 0;
			posFin = ins.find("}");
			posPoint = 0;
			while (posPoint + 1 != posFin) {
				// On parcourt l'instruction de "{" à "}"
				// Un point est entre parenthèse
				posDeb = ins.find("(", posDeb + 1);
				posPoint = ins.find(")", posPoint + 1);
				donnee = ins.substr(posDeb, posPoint);
				p->addPoint(new Vecteur2D(donnee));
			}
			return p;
		}
	}
	else // La forme demandée n'est pas un polygone
		return NULL;
}