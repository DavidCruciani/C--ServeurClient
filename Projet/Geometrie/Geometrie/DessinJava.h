#pragma once

#include "Dessin.h"

class FormeGeometrique;

class DessinJava: public Dessin 
{
public:
	DessinJava();
	virtual ~DessinJava();

	virtual void dessiner(const FormeGeometrique& )const;
};

