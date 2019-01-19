#pragma once
#ifndef _TRAITEMENTSEGMENT_
#define _TRAITEMENTSEGMENT_

#include "TraitementForme.h"

/**
 * Créee un segment a partir d'une instruction
 * Hérite de TraitementForme
 */
class TraitementSegment: public TraitementForme
{
public:
	TraitementSegment(TraitementForme*);
	virtual FormeGeometrique* traiter1(const char*) const;
};
#endif