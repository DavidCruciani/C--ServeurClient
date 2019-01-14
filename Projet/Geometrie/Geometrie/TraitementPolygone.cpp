#include "TraitementPolygone.h"
#include "Polygone.h"

TraitementPolygone::TraitementPolygone(TraitementForme *suivant) : TraitementForme(suivant) {}

FormeGeometrique* TraitementPolygone::traiter1(const char *instruction) const {
	string couleur, ins, donnee;
	int posDeb, posPoint, posFin ;
	ins = instruction;
	posDeb = ins.find("{");
	posFin = ins.find("}");
	donnee = ins.substr(0, posDeb);
	if (sscanf_s(donnee.c_str(), "Polygone (%s) {", &couleur) != 0) {
		Polygone *p = new Polygone(couleur);
		posDeb = ins.find("(");
		posPoint = ins.find(")");
		while (posPoint + 1 != posFin) {
			donnee = ins.substr(posDeb, posPoint);
			p->addPoint(new Vecteur2D(donnee));
			posDeb = ins.find("(", posDeb + 1);
			posPoint = ins.find(")", posPoint + 1);
		}
		return p;
	}
	else if (donnee == "Polygone {") {
		Polygone *p = new Polygone();
		posDeb = ins.find("(");
		posPoint = ins.find(")");
		while (posPoint + 1 != posFin) {
			donnee = ins.substr(posDeb, posPoint);
			p->addPoint(new Vecteur2D(donnee));
			posDeb = ins.find("(", posDeb + 1);
			posPoint = ins.find(")", posPoint + 1);
		}
		return p;
	}
	else
		return NULL;
}