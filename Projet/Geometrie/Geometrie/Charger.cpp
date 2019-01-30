#include "Charger.h"
#include "Erreur.h"

Charger::Charger(Charger *s): suivant(s) {}

vector<FormeGeometrique*> Charger::charge(const char *fichier, TraitementForme *traitement) {
	//On essaye le premier maillon de la cha�ne
	vector<FormeGeometrique*> liste = this->charge1(fichier, traitement);
	if (liste.size() != 0)	// vector non vide donc on a cr�� des formes
		return liste;
	else
	{
		Charger *aux = this;	//variable utilis�e pour parcourrir la chaine de responsabilit�
		while (this->suivant != NULL) {
			aux = aux->suivant;
			liste = aux->charge1(fichier, traitement);
			if (liste.size() > 0)	// on a cr�� des formes
				break;
		}
		throw Erreur("Fichier incorrect");
	}

}