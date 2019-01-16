#pragma once
#ifndef _CHARGERTXT_
#define _CHARGERTXT_

#include"Charger.h"

class ChargerTxt :public Charger
{
public:
	ChargerTxt(Charger *s): Charger(s) {}
	virtual bool charge1(const char*, vector<FormeGeometrique *>);
};
#endif