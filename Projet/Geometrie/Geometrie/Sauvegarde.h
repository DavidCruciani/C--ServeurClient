#pragma once

#include "FormeGeometrique.h"

/**
*\class Sauvegarde
*\brief classe de base du visteur pour sauvegarder les formes géométriques
*\author David Cruciani Ludovic Gillot
*/
class Sauvegarde
{
public:
	/**
	*\brief Sauvegarde la forme dansun fichier texte déjà definie
	*\param[in] f : forme que l'on veut sauvegarder au format texte
	*/
	virtual void sauvegarde(const FormeGeometrique *) const = 0;

};