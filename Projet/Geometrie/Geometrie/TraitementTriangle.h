#pragma once
#ifndef _TRAITEMENTTRIANGLE_
#define _TRAITEMENTTRIANGLE_

#include "TraitementForme.h"

class TraitementTriangle : public TraitementForme
{
public:
	TraitementTriangle(TraitementForme*);
	virtual FormeGeometrique* traiter1(const char*) const;
};
#endif