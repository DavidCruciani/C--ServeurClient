#include "Charger.h"

Charger::Charger(Charger *s): suivant(s) {}

void Charger::charge(const char *fichier, vector<FormeGeometrique*> liste) {
	bool res = this->charge1(fichier, liste);
	if (!res) {
		Charger *aux = this;
		while (this->suivant != NULL && !res) {
			aux = aux->suivant;
			res = aux->charge1(fichier, liste);
		}
	}

}