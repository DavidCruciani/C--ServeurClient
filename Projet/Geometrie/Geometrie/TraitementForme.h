#pragma once
#ifndef _TRAITEMENTFORME_
#define _TRAITEMENTFORME_

#include <vector>
#include "FormeGeometrique.h"

class TraitementForme
{
private:
	TraitementForme *suivant;
protected:
	TraitementForme(TraitementForme*);
public:
	FormeGeometrique* traiter(const char*);
protected:
	virtual FormeGeometrique* traiter1(const char*) const = 0;
};
#endif