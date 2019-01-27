#pragma once
#include "Simple.h"

using namespace std; 

/**
 * Classe représentant un cerle
 * Hérite de Simple
 */
class Cercle :public Simple
{
private:
	Vecteur2D vCentre;
	double rayon;
	void operator=(const Cercle&) ;
public:
	/**
	* Constructeur par défaut d'un cercle
	* Met la couleur par défaut à noir
	*/
	Cercle();
	/**
	* Constructeur par copie d'un cercle
	* @param Cercle& cercle a copier
	*/
	Cercle(const Cercle&);
	/**
	 * 2ème constructeur de cercle
	 * @param double x
	 * @param double y
	 * @param double rayon
	 */
	Cercle(const double, const double, const double);
	/**
	 * 3ème constructeur de cercle
	 * @param string couleur
	 * @param double x
	 * @param double y
	 * @param double rayon
	 */
	Cercle(const string, const double, const double, const double);
	/**
	 * Destructeur de cercle
	 */
	virtual ~Cercle();

	/**
	 * Setter du centre
	 * @param double x
	 * @param double y
	 */
	void setCentre(const double, const double);
	/**
	 * Setter du rayon
	 * @param double rayon
	 */
	void setRayon(const double);
	/**
	 * Getter du centre
	 * @return Vecteur2D centre du cercle
	 */
	Vecteur2D getCentre() const;
	/**
	 * Getter du rayon
	 * @return double rayon du cercle
	 */
	double getRayon() const;

	/**
	 * Clone le cercle actuel
	 * @return FormeGeometrique* (copie du cercle)
	 */
	virtual FormeGeometrique* cloner() const; 
	/**
	 * Surcharge de l'operateur string pour l'affichage du cercle
	 */
	operator string()const;

	string toString()const;
	/**
	 * Surcharge de l'operateur == pour l'egalité entre cercles
	 * @param Cercle& cercle a comparer avec this
	 * @return bool 
	 */
	bool operator ==(const Cercle&)const;
	/**
	 * Surcharge de l'operateur != pour la différence entre cercles
	 * @param Cercle &c cercle a comparer avec this
	 * @return bool
	 */
	bool operator != (const Cercle & c)const { return !(*this == c); };

	/**
	 * Calcule l'aire du cercle
	 * @return double (aire du cercle)
	 */
	virtual double getAire()const;


	/**
	 * Envoie une requête de dessin au serveur
	 * @param Dessin&
	 */
	//virtual void dessiner(const Dessin&);


	//------TRANSFORMATIONS GEOMETRIQUES SUR LE CERCLE---------
	/**
	 * Modifie les données du cercle en effectuant une homotéthie
	 * @param Vecteur2D& point de reference de l'homotetie
	 * @param double facteur de zoom
	 */
	virtual void homothetie(const Vecteur2D&, const double);
	/**
	 * Modifie les données du cercle en effectuant une rotation
	 * @param Vecteur2D& point de reference de la rotation
	 * @param double angle de rotation (en radians)
	 */
	virtual void rotation(const Vecteur2D&, const double);
	/**
	 * Modifie les données du cercle en effectuant une translation
	 * @param Vecteur2D& point vecteur de translation
	 */
	virtual void translation(const Vecteur2D&);
	//------------------------------------------


	//-----TRANSFORMATIONS GEOMETRIQUES PAR COPIE---------
	/**
	 * Creee un nouveau cercle a partir de l'homotetie du cercle actuel
	 * @param Vecteur2D& point de reference de l'homotetie
	 * @param double facteur de zoom
	 * @return FormeGeometrique* (cercle issu de l'homotetie)
	 */
	virtual FormeGeometrique* homothetie2(const Vecteur2D&, const double);
	/**
	 * Creee un nouveau cercle a partir de la rotation du cercle actuel
	 * @param Vecteur2D& point de reference de la rotation
	 * @param double angle de rotation (en radians)
	 * @return FormeGeometrique* (cercle issu de la rotation)
	 */
	virtual FormeGeometrique* rotation2(const Vecteur2D&, const double);
	/**
	 * Creee un nouveau cercle a partir de la translation du cercle actuel
	 * @param Vecteur2D& point vecteur de translation
	 * @return FormeGeometrique* (cercle issu de la translation)
	 */
	virtual FormeGeometrique* translation2(const Vecteur2D&);
};

