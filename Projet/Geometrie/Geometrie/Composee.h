#pragma once
#ifndef _COMPOSEE_
#define _COMPOSEE_

#include "FormeGeometrique.h"
#include "Simple.h"
#include <string>
#include <vector>

using namespace std;

/**
 * Classe repr�sentant une forme composee
 * H�rite de FormeGeometrique
 */
class Composee : public FormeGeometrique
{
private:
	vector<FormeGeometrique*> groupe; 
public:
	/**
	 * Constructeur par d�faut d'une forme composee
	 * Met la couleur par d�faut � noir
	 */
	Composee();
	/**
	 * 2�me constructeur de forme composee
	 * @param string couleur de la forme
	 */
	Composee(const string);
	/**
	 * Destructeur d'une forme composee
	 */
	~Composee();

	/**
	 * Ajoute une forme a groupe
	 * @param FormeGeometrique* forme a ajouter
	 */
	void addForme(FormeGeometrique*);
	/**
	 * Supprime une forme de groupe
	 * @param FormeGeometrique* forme a supprimer
	 */
	void delForme(const FormeGeometrique*);
	/**
	 * Supprime une forme de groupe a partir de son index
	 * @param int position de la forme a supprimer
	 */
	void delForme(const int);
	/**
	 * getter d'une forme de froupe
	 * @param int position de la forme a chercher
	 * @return FormeGeometrique* forme recherch�e
	 */
	FormeGeometrique* getForme(const int);

	/**
	 * Calcule l'aire de la forme composee
	 * @return double (aire de la forme composee)
	 */
	virtual double getAire() const;

	/**
	 * Clone le triangle actuel
	 * @return FormeGeometrique* (copie de la forme composee)
	 */
	virtual FormeGeometrique* cloner() const;


	/**
	 * Envoie une requ�te de dessin au serveur
	 * @param Dessin&
	 */
	//virtual void dessiner(const Dessin&);


	/**
	 * Surcharge de l'operateur string pour l'affichage de la forme composee
	 */
	operator string()const;

	string toString()const;
	
	//------TRANSFORMATIONS GEOMETRIQUES SUR LE TRIANGLE---------
	/**
	 * Modifie les donn�es de la forme composee en effectuant une homot�thie
	 * @param Vecteur2D& point de reference de l'homotetie
	 * @param double facteur de zoom
	 */
	virtual void homothetie(const Vecteur2D&, const double);
	/**
	 * Modifie les donn�es de la forme composee en effectuant une rotation
	 * @param Vecteur2D& point de reference de la rotation
	 * @param double angle de rotation (en radians)
	 */
	virtual void rotation(const Vecteur2D&, const double);
	/**
	 * Modifie les donn�es de la forme composee en effectuant une translation
	 * @param Vecteur2D& point vecteur de translation
	 */
	virtual void translation(const Vecteur2D&);
	//------------------------------------------


	//-----TRANSFORMATIONS GEOMETRIQUES PAR COPIE---------
	/**
	 * Creee une nouvelle forme composee a partir de l'homotetie de la forme composee actuel
	 * @param Vecteur2D& point de reference de l'homotetie
	 * @param double facteur de zoom
	 * @return FormeGeometrique* (forme composee issu de l'homotetie)
	 */
	virtual Composee* homothetie2(const Vecteur2D&, const double);
	/**
	 * Creee une nouvelle forme composee a partir de la rotation de la forme composee actuel
	 * @param Vecteur2D& point de reference de la rotation
	 * @param double angle de rotation (en radians)
	 * @return FormeGeometrique* (forme composee issu de la rotation)
	 */
	virtual Composee* rotation2(const Vecteur2D&, const double);
	/**
	 * Creee une nouvelle forme composee a partir de la translation de la forme composee actuel
	 * @param Vecteur2D& point vecteur de translation
	 * @return FormeGeometrique* (forme composee issu de la translation)
	 */
	virtual Composee* translation2(const Vecteur2D&);
};
#endif