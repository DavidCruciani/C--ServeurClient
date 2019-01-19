#pragma once
#ifndef _SIMPLE_
#define _SIMPLE_

#include"FormeGeometrique.h"

using namespace std;

/**
 * Classe repr�sentant une forme simple
 * H�rite de FormeGeometrique
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
	 * Constructeur par d�faut d'une forme simple
	 * Met la couleur par d�faut � noir
	 */
	Simple();
	/**
	 * 2�me constructeur de forme simple
	 * @param string couleur de la forme
	 */
	Simple(const string);
	/**
	 * Destructeur d'une forme simple
	 */
	~Simple();
};
#endif