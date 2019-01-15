#pragma once
#ifndef _TRAITEMENTCOMPOSEE_
#define _TRAITEMENTCOMPOSEE_

#include "TraitementForme.h"

class TraitementComposee :public TraitementForme
{
public:
	TraitementComposee(TraitementForme*);
	virtual FormeGeometrique* traiter1(const char*) const;
};
#endif