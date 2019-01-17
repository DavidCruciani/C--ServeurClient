#pragma once
#ifndef _CHARGERTXT_
#define _CHARGERTXT_

#include"Charger.h"

class ChargerTxt :public Charger
{
public:
	ChargerTxt(Charger *s): Charger(s) {}
	virtual vector<FormeGeometrique*> charge1(const char*, TraitementForme*);
};
#endif