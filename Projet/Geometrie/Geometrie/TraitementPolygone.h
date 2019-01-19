#pragma once
#ifndef _TRAITEMENTPOLYGONE_
#define _TRAITEMENTPOLYGONE_

#include "TraitementForme.h"

/**
 * Cr�ee un polygone a partir d'une instruction
 * H�rite de TraitementForme
 */
class TraitementPolygone : public TraitementForme
{
public:
	TraitementPolygone(TraitementForme*);
	virtual FormeGeometrique* traiter1(const char*) const;
};
#endif