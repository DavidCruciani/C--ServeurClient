#pragma once
#ifndef _CHARGER_
#define _CHARGER_

#include <fstream>
#include <vector>
#include "TraitementForme.h"
#include "TraitementSegment.h"
#include "TraitementCercle.h"
#include "TraitementPolygone.h"
#include "TraitementTriangle.h"
#include "TraitementComposee.h"
#include "FormeGeometrique.h"

	/**
	 * Chaine de responsabilité pour le chargement d'un fichier
	 */
class Charger
{
private:
	Charger *suivant;
protected:
	Charger(Charger*);
public:
	/**
	 * Traitement principal de la chaine de responsabilité
	 *
	 * @param char* Nom du fichier
	   @param TraitementForme* chaine de responsabilité de création de forme
	   @return vector de pointeurs de FormeGeometrique
	 */
	vector<FormeGeometrique*> charge(const char*, TraitementForme*);
protected:
	/**
	 * Traitement d'un cas de la chaine de responsabilite
	 *
	 * @param char* Nom du fichier
	   @param TraitementForme* chaine de responsabilité de création de forme
	   @return vector de pointeurs de FormeGeometrique
	 */
	virtual vector<FormeGeometrique*> charge1(const char*, TraitementForme*) = 0;
};
#endif