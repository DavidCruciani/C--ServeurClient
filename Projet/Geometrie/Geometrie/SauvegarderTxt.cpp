#include "SauvegarderTxt.h"

#include <iostream>
#include <sstream>
#include <fstream>

SauvegarderTxt::SauvegarderTxt(){}


SauvegarderTxt::~SauvegarderTxt(){}

void SauvegarderTxt::sauvegarde(const FormeGeometrique * f) const
{
	ofstream fichier("C:/Users/Ludovic GILLOT/Documents/Formes.txt", ios::out | ios::app);
	//Test d'ouverture
	if (fichier.is_open())
		cout << "Fichier ouvert \n";

	if (!fichier) {
		cerr << "Problème d'ouverture de fichier" << endl;
		exit(1);
	}
	fichier << f->toString() << "\n";
	cout << "Message ecrit \n";
	// fermeture du fichier
	fichier.close();
}