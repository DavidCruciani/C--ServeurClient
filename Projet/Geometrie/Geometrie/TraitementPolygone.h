#pragma once
#ifndef _TRAITEMENTPOLYGONE_
#define _TRAITEMENTPOLYGONE_

#include "TraitementForme.h"

/**
 * Créee un polygone a partir d'une instruction
 * Hérite de TraitementForme
 */
class TraitementPolygone : public TraitementForme
{
public:
	TraitementPolygone(TraitementForme*);
	virtual FormeGeometrique* traiter1(const char*) const;
};
#endif