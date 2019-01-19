#pragma once
#ifndef _SIMPLE_
#define _SIMPLE_

#include"FormeGeometrique.h"

using namespace std;

/**
 * Classe représentant une forme simple
 * Hérite de FormeGeometrique
 */
class Simple : public FormeGeometrique
{
private:
	/**
	* Constructeur par copie d'une forme simple
	* private car la copie est interdite
	* @param Simple& forme a copier
	*/
	Simple(const Simple&);
public:
	/**
	 * Constructeur par défaut d'une forme simple
	 * Met la couleur par défaut à noir
	 */
	Simple();
	/**
	 * 2ème constructeur de forme simple
	 * @param string couleur de la forme
	 */
	Simple(const string);
	/**
	 * Destructeur d'une forme simple
	 */
	~Simple();
};
#endif