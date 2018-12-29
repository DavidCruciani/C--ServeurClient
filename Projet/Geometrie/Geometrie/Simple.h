#pragma once
#ifndef _SIMPLE_
#define _SIMPLE_

#include"FormeGeometrique.h"

using namespace std;

class Simple : public FormeGeometrique
{
private:
	Simple(const Simple&);
public:
	Simple();
	Simple(const string);
	~Simple();

	// VOIR POUR SURCHARGES OPERATEUR ET AFFICHAGE
};
#endif