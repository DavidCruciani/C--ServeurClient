#pragma once
#ifndef _TRAITEMENTFORME_
#define _TRAITEMENTFORME_

#include <vector>
#include "FormeGeometrique.h"

/**
 * Chaine de responsabilite pour creer des formes geometriques a partir d'une chaine de caracteres
 */
class TraitementForme
{
private:
	TraitementForme *suivant;
protected:
	/**
	 * Constructeur
	 *
	 * @param TraitementForme* traitement suivant
	 */
	TraitementForme(TraitementForme*);
public:
	/**
	 * Traitement principal de la chaine de responsabilité
	 *
	 * @param char* Instruction de creation de  la forme
	 * @return FormeGeometrique* forme creee
	 */
	FormeGeometrique* traiter(const char*);
protected:
	/**
	 * Traitement d'un cas de la chaine de responsabilite
	 * @param char* Instruction de creation de  la forme
	 * @return FormeGeometrique* forme creee
	 */
	virtual FormeGeometrique* traiter1(const char*) const = 0;
};
#endif