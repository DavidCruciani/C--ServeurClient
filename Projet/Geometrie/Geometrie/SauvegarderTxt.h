#pragma once
#include "Sauvegarde.h"

class SauvegarderTxt :
	public Sauvegarde
{
public:
	SauvegarderTxt();
	~SauvegarderTxt();

	virtual void sauvegarde(const FormeGeometrique * f) const;
};

