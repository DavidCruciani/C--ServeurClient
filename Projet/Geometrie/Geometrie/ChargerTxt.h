#pragma once
#ifndef _CHARGERTXT_
#define _CHARGERTXT_

#include"Charger.h"

/**
	 * Charge un fichier au format txt
	 * Herite de Charger
	 */
class ChargerTxt :public Charger
{
public:
	/**
	 * Constructeur
	 *
	 * @param Charger* traitement suivant
	 */
	ChargerTxt(Charger *s): Charger(s) {}
	/**
	 * Traitement du fichier donné
	 *
	 * @param char* Nom du fichier
	   @param TraitementForme* chaine de responsabilité de création de forme
	   @return vector de pointeurs de FormeGeometrique ou NULL si le fichier n'est pas au bon format
	 */
	virtual vector<FormeGeometrique*> charge1(const char*, TraitementForme*);
};
#endif