#include "Charger.h"

Charger::Charger(Charger *s): suivant(s) {}

vector<FormeGeometrique*> Charger::charge(const char *fichier, TraitementForme *traitement) {
	vector<FormeGeometrique*> liste = this->charge1(fichier, traitement);
	if (liste.size() != 0)
		return liste;
	else
	{
		Charger *aux = this;
		while (this->suivant != NULL) {
			aux = aux->suivant;
			liste = aux->charge1(fichier, traitement);
			if (liste.size() > 0)
				break;
		}
		return liste;
	}

}