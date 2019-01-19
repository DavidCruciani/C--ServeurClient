#pragma once
#include "Sauvegarde.h"

/**
*\class SauvegarderTxt
* \brief Design Pattern Visitor qui sauvegarde dans un fichier texte
*/
class SauvegarderTxt :
	public Sauvegarde
{
public:
	SauvegarderTxt();
	~SauvegarderTxt();

	virtual void sauvegarde(const FormeGeometrique * f) const;
};

