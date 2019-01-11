#pragma once
#ifndef _TRAITEMENTCERCLE_
#define _TRAITEMENTCERCLE_

#include "TraitementForme.h"
#include "Cercle.h"

class TraitementCercle : public TraitementForme
{
	TraitementCercle(TraitementForme*);
	virtual FormeGeometrique* traiter1(const char*) const;
};
#endif
