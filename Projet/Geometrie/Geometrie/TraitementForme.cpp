#include "TraitementForme.h"

TraitementForme::TraitementForme(TraitementForme *f):suivant(f){}

FormeGeometrique* TraitementForme::traiter(const char *traitement) {
	FormeGeometrique *forme = this->traiter1(traitement);
	if (forme != NULL)
		return forme;
	else {
		TraitementForme *aux = this;
		while (aux->suivant != NULL) {
			aux = aux->suivant;
			forme = aux->traiter1(traitement);
			if (forme != NULL)
				return forme;
		}
		return NULL;
	}
}