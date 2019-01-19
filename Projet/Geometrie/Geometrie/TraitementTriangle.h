#pragma once
#ifndef _TRAITEMENTTRIANGLE_
#define _TRAITEMENTTRIANGLE_

#include "TraitementForme.h"

/**
 * Créee un triangle a partir d'une instruction
 * Hérite de TraitementForme
 */
class TraitementTriangle : public TraitementForme
{
public:
	TraitementTriangle(TraitementForme*);
	virtual FormeGeometrique* traiter1(const char*) const;
};
#endif