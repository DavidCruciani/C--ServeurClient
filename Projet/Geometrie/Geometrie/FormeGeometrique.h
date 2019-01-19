#pragma once
#ifndef _FORMEGEOMETRIQUE_
#define _FORMEGEOMETRIQUE_

#include "Vecteur2D.h"
#include <string>
using namespace std;
class Dessin;

    /**
	 * Classe représentant une Forme Geométrique
	 */
class FormeGeometrique
{
protected:
	string couleur;
public:
	/**
	 * Constructeur par défaut d'une forme
	 * Met la couleur par défaut à noir
	 */
	FormeGeometrique();
	/**
	 * 2ème constructeur de forme	 
	 * @param string couleur de la forme
	 */
	FormeGeometrique(const string);
	/**
	 * Constructeur par copie d'une forme
	 * @param FormeGeometrique& forme à copier
	 */
	FormeGeometrique(const FormeGeometrique&);
	/**
	 * Destructeur d'une forme
	 */
	~FormeGeometrique();

	/**
	 * Setter de la couleur
	 * @param string couleur a attribuer
	 */
	void setCouleur(const string);
	/**
	 * Getter de la couleur
	 * @return couleur
	 */
	string getCouleur() const;

	/**
	 * Envoie une requête de dessin au serveur
	 * @param Dessin& 
	 */
	virtual void dessiner(const Dessin&) = 0;
	/**
	 * Calcule l'aire de la forme
	 * @return double (aire de la forme)
	 */
	virtual double getAire() const = 0;
	/**
	 * Clone la forme actuelle
	 * @return FormeGeometrique* (copie de la forme)
	 */
	virtual FormeGeometrique* cloner() const = 0;
	/**
	 * Surcharge de l'operateur string pour l'affichage de la forme 
	 */
	virtual operator string()const = 0;

	//------TRANSFORMATIONS GEOMETRIQUES SUR LA FORME---------
	/**
	 * Modifie les données de la forme en effectuant une homotéthie
	 * @param Vecteur2D& point de reference de l'homotetie
	 * @param double facteur de zoom
	 */
	virtual void homothetie(const Vecteur2D&, const double) = 0;
	/**
	 * Modifie les données de la forme en effectuant une rotation
	 * @param Vecteur2D& point de reference de la rotation
	 * @param double angle de rotation (en radians)
	 */
	virtual void rotation(const Vecteur2D&, const double) = 0;
	 /**
	  * Modifie les données de la forme en effectuant une translation
	  * @param Vecteur2D& point vecteur de translation
      */
	virtual void translation(const Vecteur2D&) = 0;
	//------------------------------------------


	//-----TRANSFORMATIONS GEOMETRIQUES PAR COPIE---------
	/**
	 * Creee une nouvelle forme a partir de l'homotetie de la forme actuelle 
	 * @param Vecteur2D& point de reference de l'homotetie
	 * @param double facteur de zoom
	 * @return FormeGeometrique* (forme issue de l'homotetie)
	 */
	virtual FormeGeometrique* homothetie2(const Vecteur2D&, const double) = 0;
	/**
	 * Creee une nouvelle forme a partir de la rotation de la forme actuelle
	 * @param Vecteur2D& point de reference de la rotation
	 * @param double angle de rotation (en radians)
	 * @return FormeGeometrique* (forme issue de la rotation)
	 */
	virtual FormeGeometrique* rotation2(const Vecteur2D&, const double) = 0;
	/**
	 * Creee une nouvelle forme a partir de la translation de la forme actuelle 
	 * @param Vecteur2D& point vecteur de translation
	 * @return FormeGeometrique* (forme issue de la translation)
	 */
	virtual FormeGeometrique* translation2(const Vecteur2D&) = 0;
	//------------------------------------------------------------

	/**
	 * Surcharge de l'operateur << pour l'affichage
	 * @param ostream&
	 * @param FormeGeometrique* la forme que l'on veut afficher
	 * @return ostream&
	 */
	friend ostream& operator<<(ostream&, const FormeGeometrique*);
};
#endif