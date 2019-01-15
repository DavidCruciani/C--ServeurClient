#pragma once
#ifndef _TRAITEMENTPOLYGONE_
#define _TRAITEMENTPOLYGONE_

#include "TraitementForme.h"

class TraitementPolygone : public TraitementForme
{
public:
	TraitementPolygone(TraitementForme*);
	virtual FormeGeometrique* traiter1(const char*) const;
};
#endif