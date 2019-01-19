#pragma once
#ifndef _TRAITEMENTTRIANGLE_
#define _TRAITEMENTTRIANGLE_

#include "TraitementForme.h"

/**
 * Cr�ee un triangle a partir d'une instruction
 * H�rite de TraitementForme
 */
class TraitementTriangle : public TraitementForme
{
public:
	TraitementTriangle(TraitementForme*);
	virtual FormeGeometrique* traiter1(const char*) const;
};
#endif