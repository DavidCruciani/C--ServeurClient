#include "ChargerTxt.h"
#include "Erreur.h"

vector<FormeGeometrique*> ChargerTxt::charge1(const char *fichier, TraitementForme *traitement) {
	vector<FormeGeometrique*> liste;
	if (strstr(fichier, ".txt") != NULL) { // on v�rifie que le nom du fichier � pour extension ".txt"
		ifstream fichier1(fichier, ios::in);
		if (fichier1)  // si l'ouverture a fonctionn�
		{
			string ligne;
			while (getline(fichier1, ligne))  // on lit toutes les lignes du fichier ( 1 ligne = 1 forme g�ometrique )
			{
				const string forme = ligne;
				liste.push_back(traitement->traiter(ligne.c_str()));  // on cr�ee une forme g�om�trique avec la cha�ne de responsabilit� et on la stocke dans le vector
			}

			fichier1.close(); // on a fini de lire le fichier donc on le ferme
			return liste;
		}
		//else
		throw Erreur("lecture echou�");//ENVOI D'EXCEPTION ===> L'ouverture du fichier � �chou�
		
	}
	else 
		return liste; // format diff�rent de ".txt" donc on retourne un vector vide
}