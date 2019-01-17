#include "ChargerTxt.h"

vector<FormeGeometrique*> ChargerTxt::charge1(const char *fichier, TraitementForme *traitement) {
	vector<FormeGeometrique*> liste;
	if (strstr(fichier, ".txt") != NULL) {
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
			return liste;
		}
		//else
			//ENVOI D'EXCEPTION ===> L'ouverture du fichier à échoué
		
	}
	else 
		return liste;
}