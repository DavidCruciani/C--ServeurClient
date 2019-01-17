#pragma once
#include "FormeGeometrique.h"

class Dessin
{
public:
	virtual void dessiner(const FormeGeometrique&)const=0;
};
