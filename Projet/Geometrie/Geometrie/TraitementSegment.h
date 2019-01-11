#pragma once
#ifndef _TRAITEMENTSEGMENT_
#define _TRAITEMENTSEGMENT_

#include "TraitementForme.h"

class TraitementSegment: public TraitementForme
{
public:
	TraitementSegment(TraitementForme*);
	virtual FormeGeometrique* traiter1(const char*) const;
};
#endif