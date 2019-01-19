#pragma once
#ifndef _TRIANGLE_
#define _TRIANGLE_

#include "Simple.h"

using namespace std;

/**
 * Classe représentant un triangle
 * Hérite de Simple
 */
class Triangle : public Simple
{
private:
	Vecteur2D v1, v2, v3;
public:
	/**
	 * Constructeur par défaut d'un triangle
	 * Met la couleur par défaut à noir
	 */
	Triangle();
	/**
	 * Constructeur par copie d'un triangle
	 * @param Triangle& triangle a copier
	*/
	 Triangle(const Triangle&);
	 /**
	  * 2ème constructeur de triangle
	  * @param string couleur
	  * @param double x1
	  * @param double y1
	  * @param double x2
	  * @param double y2
	  * @param double x3
	  * @param double y3
	  */
	Triangle(const string, const double, const double, const double, const double, const double, const double);
	/**
	 * 2ème constructeur de triangle
	 * @param string couleur
	 * @param double x1
	 * @param double y1
	 * @param double x2
	 * @param double y2
	 * @param double x3
	 * @param double y3
	 */
	Triangle(const double, const double, const double, const double, const double, const double);
	/**
	 * Destructeur de triangle
	 */
	~Triangle();

	/**
	 * Setter du point v1 du triangle
	 * @param double x
	 * @param double y
	 */
	void setV1(const double, const double);
	/**
	 * Setter du point v2 du triangle
	 * @param double x
	 * @param double y
	 */
	void setV2(const double, const double);
	/**
	 * Setter du point v3 du triangle
	 * @param double x
	 * @param double y
	 */
	void setV3(const double, const double);
	/**
	 * Getter du point v1 du triangle
	 * @return Vecteur2D v1
	 */
	Vecteur2D getV1() const;
	/**
	 * Getter du point v2 du triangle
	 * @return Vecteur2D v2
	 */
	Vecteur2D getV2() const;
	/**
	 * Getter du point v3 du triangle
	 * @return Vecteur2D v3
	 */
	Vecteur2D getV3() const;

	/**
	 * Surcharge de l'operateur string pour l'affichage du triangle
	 */
	operator string()const;

	/**
	 * Calcule l'aire du triangle
	 * @return double (aire du triangle)
	 */
	virtual double getAire() const;
	/**
	 * Clone le triangle actuel
	 * @return FormeGeometrique* (copie du triangle)
	 */
	virtual FormeGeometrique* cloner() const;
	/**
	 * Envoie une requête de dessin au serveur
	 * @param Dessin&
	 */
	virtual void dessiner(const Dessin&);

	//------TRANSFORMATIONS GEOMETRIQUES SUR LE TRIANGLE---------
	/**
	 * Modifie les données du triangle en effectuant une homotéthie
	 * @param Vecteur2D& point de reference de l'homotetie
	 * @param double facteur de zoom
	 */
	virtual void homothetie(const Vecteur2D&, const double);
	/**
	 * Modifie les données du triangle en effectuant une rotation
	 * @param Vecteur2D& point de reference de la rotation
	 * @param double angle de rotation (en radians)
	 */
	virtual void rotation(const Vecteur2D&, const double);
	/**
	 * Modifie les données du triangle en effectuant une translation
	 * @param Vecteur2D& point vecteur de translation
	 */
	virtual void translation(const Vecteur2D&);
	//------------------------------------------


	//-----TRANSFORMATIONS GEOMETRIQUES PAR COPIE---------
	/**
	 * Creee un nouveau triangle a partir de l'homotetie du triangle actuel
	 * @param Vecteur2D& point de reference de l'homotetie
	 * @param double facteur de zoom
	 * @return FormeGeometrique* (triangle issu de l'homotetie)
	 */
	virtual FormeGeometrique* homothetie2(const Vecteur2D&, const double);
	/**
	 * Creee un nouveau triangle a partir de la rotation du triangle actuel
	 * @param Vecteur2D& point de reference de la rotation
	 * @param double angle de rotation (en radians)
	 * @return FormeGeometrique* (triangle issu de la rotation)
	 */
	virtual FormeGeometrique* rotation2(const Vecteur2D&, const double);
	/**
	 * Creee un nouveau triangle a partir de la translation du triangle actuel
	 * @param Vecteur2D& point vecteur de translation
	 * @return FormeGeometrique* (triangle issu de la translation)
	 */
	virtual FormeGeometrique* translation2(const Vecteur2D&);
};
#endif