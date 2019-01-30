#pragma once
#ifndef _SEGMENT_
#define _SEGMENT_

#include"Simple.h"
using namespace std;

/**
 * Classe représentant un segment
 * Hérite de Simple
 */
class Segment : public Simple
{
private:
	Vecteur2D v1, v2;
public:
    /**
	 * Constructeur par défaut d'un segment
	 * Met la couleur par défaut à noir
	 */
	Segment();
    /**
	 * Constructeur par copie d'un segment
	 * @param Segment& segment a copier
	 */
	Segment(const Segment&);
	/**
	 * 2ème constructeur de segment
	 * @param string couleur
	 * @param double x1
	 * @param double y1
	 * @param double x2
	 * @param double y2
	 */
	Segment(const string, const double, const double, const double, const double);
	/**
	 * 3ème constructeur de segment
	 * @param double x1
	 * @param double y1
	 * @param double x2
	 * @param double x2
	 */
	Segment(const double, const double, const double, const double);
	/**
	 * Destructeur de segment
	 */
	~Segment();

	/**
	 * Setter du point v1 du segment
	 * @param double x
	 * @param double y
	 */
	void setV1(const double, const double);
	/**
	 * Setter du point v2 du segment
	 * @param double x
	 * @param double y
	 */
	void setV2(const double, const double);
	/**
	 * Getter du point v1 du segment
	 * @return Vecteur2D v1
	 */
	Vecteur2D getV1() const;
	/**
	 * Getter du point v2 du segment
	 * @return Vecteur2D v2
	 */
	Vecteur2D getV2() const;

	/**
	 * Surcharge de l'operateur string pour l'affichage du segment
	 */
	operator string()const;

	string toString()const;

	/**
	 * Calcule l'aire du segment
	 * @return double (aire du segment)
	 */
	virtual double getAire() const;
	/**
	 * Clone le segment actuel
	 * @return FormeGeometrique* (copie du segment)
	 */
	virtual FormeGeometrique* cloner() const;


	/**
	 * Envoie une requête de dessin au serveur
	 * @param Dessin&
	 */
	//virtual void dessiner(const Dessin&);


	//------TRANSFORMATIONS GEOMETRIQUES SUR LE SEGMENT---------
	/**
	 * Modifie les données du segment en effectuant une homotéthie
	 * @param Vecteur2D& point de reference de l'homotetie
	 * @param double facteur de zoom
	 */
	virtual void homothetie(const Vecteur2D&, const double);
	/**
	 * Modifie les données du segment en effectuant une rotation
	 * @param Vecteur2D& point de reference de la rotation
	 * @param double angle de rotation (en radians)
	 */
	virtual void rotation(const Vecteur2D&, const double);
	/**
	 * Modifie les données du segment en effectuant une translation
	 * @param Vecteur2D& point vecteur de translation
	 */
	virtual void translation(const Vecteur2D&);
	//------------------------------------------


	//-----TRANSFORMATIONS GEOMETRIQUES PAR COPIE---------
	/**
	 * Creee un nouveau segment a partir de l'homotetie du segment actuel
	 * @param Vecteur2D& point de reference de l'homotetie
	 * @param double facteur de zoom
	 * @return FormeGeometrique* (segment issu de l'homotetie)
	 */
	virtual FormeGeometrique* homothetie2(const Vecteur2D&, const double);
	/**
	 * Creee un nouveau segment a partir de la rotation du segment actuel
	 * @param Vecteur2D& point de reference de la rotation
	 * @param double angle de rotation (en radians)
	 * @return FormeGeometrique* (segment issu de la rotation)
	 */
	virtual FormeGeometrique* rotation2(const Vecteur2D&, const double);
	/**
	 * Creee un nouveau segment a partir de la translation du segment actuel
	 * @param Vecteur2D& point vecteur de translation
	 * @return FormeGeometrique* (segment issu de la translation)
	 */
	virtual FormeGeometrique* translation2(const Vecteur2D&);
};
#endif