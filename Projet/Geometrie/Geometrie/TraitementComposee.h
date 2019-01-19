#pragma once
#ifndef _TRAITEMENTCOMPOSEE_
#define _TRAITEMENTCOMPOSEE_

#include "TraitementForme.h"

/**
 * Cr�ee une forme composee a partir d'une instruction
 * H�rite de TraitementForme
 */
class TraitementComposee :public TraitementForme
{
public:
	TraitementComposee(TraitementForme*);
	virtual FormeGeometrique* traiter1(const char*) const;
};
#endif