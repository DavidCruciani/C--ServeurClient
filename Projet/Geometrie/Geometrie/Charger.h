#pragma once
#ifndef _CHARGER_
#define _CHARGER_

#include <fstream>
#include <vector>
#include "TraitementForme.h"
#include "TraitementSegment.h"
#include "TraitementCercle.h"
#include "TraitementPolygone.h"
#include "TraitementTriangle.h"
#include "TraitementComposee.h"
#include "FormeGeometrique.h"

class Charger
{
private:
	Charger *suivant;
protected:
	Charger(Charger*);
public:
	void charge(const char*, vector<FormeGeometrique*>);
protected:
	virtual bool charge1(const char*, vector<FormeGeometrique*>) = 0;
};
#endif