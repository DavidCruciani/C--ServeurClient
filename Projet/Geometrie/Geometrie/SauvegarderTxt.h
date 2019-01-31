#pragma once
#include "Sauvegarde.h"

/**
*\class SauvegarderTxt
* \brief Design Pattern Visitor qui sauvegarde dans un fichier texte
*/
class SauvegarderTxt :
	public Sauvegarde
{
private:
	static string path;
public:
	
	SauvegarderTxt();
	~SauvegarderTxt();

	static string getPath();

	virtual void sauvegarde(const FormeGeometrique * f) const;
};

