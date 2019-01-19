#pragma once

#include "Dessin.h"

/**
*\class DessinJava
* \brief Design Pattern Visitor qui communique avec un serveur JAVA
*/

class DessinJava: public Dessin 
{
public:
	DessinJava();
	virtual ~DessinJava();

	virtual void dessiner(const FormeGeometrique& )const;
};

