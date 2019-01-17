#pragma once

#include "FormeGeometrique.h"

/**
*\class Sauvegarde
*\brief classe de base du visteur pour sauvegarder les formes géométriques
*/
class Sauvegarde
{
public:

	virtual void sauvegarde(const FormeGeometrique *) const = 0;

};