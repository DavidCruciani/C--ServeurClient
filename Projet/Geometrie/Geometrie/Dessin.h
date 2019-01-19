#pragma once
#include "FormeGeometrique.h"


/**
*\class Dessin
*\brief classe de base du visitor pour dessiner les formes g�om�triques
*\author David Cruciani Ludovic Gillot
*/
class Dessin
{
public:

	/**
	*\brief envoie la forme sous forme d'une chaine de caract�re au serveur JAVA
	*Affiche le message de retour du serveur ou une erreur si le dessin a �chou�
	*\param[in] f : forme g�ometrique que l'on souhaite dessiner
	*/
	virtual void dessiner(const FormeGeometrique&)const = 0;
};
