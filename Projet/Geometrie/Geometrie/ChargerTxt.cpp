#include "ChargerTxt.h"

bool ChargerTxt::charge1(const char *fichier, vector<FormeGeometrique*> liste) {
	if (strstr(fichier, ".txt") != NULL) {
		//---------------------- CREATION CHAINE RESPONSABILITE ----------
		TraitementForme *traitement, *segment, *cercle, *polygone, *triangle, *composee;
		segment = new TraitementSegment(NULL);
		cercle = new TraitementCercle(segment);
		polygone = new TraitementPolygone(cercle);
		triangle = new TraitementTriangle(polygone);
		composee = new TraitementComposee(triangle);
		traitement = composee;
		//-----------------------------------------------------------------
		ifstream fichier1(fichier, ios::in);
		if (fichier1)  // si l'ouverture a fonctionné
		{
			string ligne;
			while (getline(fichier1, ligne))  // tant que l'on peut mettre la ligne dans "contenu"
			{
				const string forme = ligne;
				liste.push_back(traitement->traiter(ligne.c_str()));  // on l'affiche
			}

			fichier1.close();
		}
		//else
			//ENVOI D'EXCEPTION ===> L'ouverture du fichier à échoué
		return true;
	}
	else
		return false;
}