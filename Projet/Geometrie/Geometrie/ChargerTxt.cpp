#include "ChargerTxt.h"
#include "Erreur.h"

vector<FormeGeometrique*> ChargerTxt::charge1(const char *fichier, TraitementForme *traitement) {
	vector<FormeGeometrique*> liste;
	if (strstr(fichier, ".txt") != NULL) { // on vérifie que le nom du fichier à pour extension ".txt"
		ifstream fichier1(fichier, ios::in);
		if (fichier1)  // si l'ouverture a fonctionné
		{
			string ligne;
			while (getline(fichier1, ligne))  // on lit toutes les lignes du fichier ( 1 ligne = 1 forme géometrique )
			{
				const string forme = ligne;
				liste.push_back(traitement->traiter(ligne.c_str()));  // on créee une forme géométrique avec la chaîne de responsabilité et on la stocke dans le vector
			}

			fichier1.close(); // on a fini de lire le fichier donc on le ferme
			return liste;
		}
		//else
		throw Erreur("lecture echoué");//ENVOI D'EXCEPTION ===> L'ouverture du fichier à échoué
		
	}
	else 
		return liste; // format différent de ".txt" donc on retourne un vector vide
}