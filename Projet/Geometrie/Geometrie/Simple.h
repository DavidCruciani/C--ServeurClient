#pragma once
#ifndef _SIMPLE_
#define _SIMPLE_

#include"FormeGeometrique.h"
#include <cmath>
#include <math.h>

#define SIN(x) sin(x * 3.141592653589/180) 
#define COS(x) cos(x * 3.141592653589/180) 

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