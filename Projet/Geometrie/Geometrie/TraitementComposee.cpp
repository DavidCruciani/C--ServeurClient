#include"TraitementComposee.h"
#include "TraitementCercle.h"
#include "TraitementPolygone.h"
#include "TraitementSegment.h"
#include "TraitementTriangle.h"
#include "Composee.h"

TraitementComposee::TraitementComposee(TraitementForme *suivant): TraitementForme(suivant) {}

FormeGeometrique* TraitementComposee::traiter1(const char *instruction) const {
	if (strstr(instruction, "Composee") != NULL) {
		//---------------------- CREATION CHAINE RESPONSABILITE ----------
		TraitementForme *traitement, *segment, *cercle, *polygone, *triangle, *composee;
		segment = new TraitementSegment(NULL);
		cercle = new TraitementCercle(segment);
		polygone = new TraitementPolygone(cercle);
		triangle = new TraitementTriangle(polygone);
		composee = new TraitementComposee(triangle);
		traitement = composee;
		//-----------------------------------------------------------------
		int posDeb, posForme, posFin, i;
		string couleur, ins, donnee;
		Composee *c = new Composee();
		if (strchr(instruction, '=') != NULL) {
			couleur = strchr(instruction, '=');
			posFin = couleur.find(";");
			couleur = couleur.substr(1, posFin - 1);
			c->setCouleur(couleur);
		}
		ins = instruction;
		posDeb = 0;
		posForme = 0;
		i = 0;
		posFin = ins.find("}");
		while (posForme + 1 != posFin) {
			posDeb = ins.find("*", posForme + 1);
			posForme = ins.find("*", posDeb + 1);
			donnee = ins.substr(posDeb+1, posForme-posDeb-1);
			c->addForme(traitement->traiter(donnee.c_str()));
			c->getForme(i)->setCouleur(couleur);
			i++;
		}
		return c;
	}
	else
		return NULL;
}