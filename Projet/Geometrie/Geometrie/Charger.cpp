#include "Charger.h"
#include "Erreur.h"

Charger::Charger(Charger *s): suivant(s) {}

vector<FormeGeometrique*> Charger::charge(const char *fichier, TraitementForme *traitement) {
	//On essaye le premier maillon de la chaîne
	vector<FormeGeometrique*> liste = this->charge1(fichier, traitement);
	if (liste.size() != 0)	// vector non vide donc on a créé des formes
		return liste;
	else
	{
		Charger *aux = this;	//variable utilisée pour parcourrir la chaine de responsabilité
		while (this->suivant != NULL) {
			aux = aux->suivant;
			liste = aux->charge1(fichier, traitement);
			if (liste.size() > 0)	// on a créé des formes
				break;
		}
		throw Erreur("Fichier incorrect");
	}

}