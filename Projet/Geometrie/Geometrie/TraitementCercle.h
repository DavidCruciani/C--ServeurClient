#pragma once
#ifndef _TRAITEMENTCERCLE_
#define _TRAITEMENTCERCLE_

#include "TraitementForme.h"
#include "Cercle.h"

/**
 * Créee un cercle a partir d'une instruction
 * Hérite de TraitementForme
 */
class TraitementCercle : public TraitementForme
{
public:
	TraitementCercle(TraitementForme*);
	virtual FormeGeometrique* traiter1(const char*) const;
};
#endif
