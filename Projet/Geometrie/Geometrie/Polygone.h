#pragma once

#include <vector>
#include "Simple.h"

using namespace std;

/**
 * Classe représentant un polygone
 * Hérite de Simple
 */
class Polygone : public Simple
{
private:
	vector<Vecteur2D*> listePoints;
	int nbPts=0;
public:
	/**
	 * Constructeur par défaut d'un polygone
	 * Met la couleur par défaut à noir
	 */
	Polygone();
	/**
	 * 2eme constructeur de polygone
	 * @param string couleur
	*/
	Polygone(const string);
	/**
	 * Constructeur par copie d'un polygone
	 * @param Polygone& polygone a copier
	*/
	Polygone(const Polygone&);
	/**
	 * 3ème constructeur de polygone
	 * @param Vecteur2D v1
	 * @param Vecteur2D v2
	 * @param Vecteur2D v3
	 * @param Vecteur2D v4
	 */
	Polygone(Vecteur2D*, Vecteur2D*, Vecteur2D*, Vecteur2D*);
	/**
	 * Destructeur de polygone
	 */
	~Polygone();
	/**
	 * Getter de la liste de points
	 * @return vector<Vecteur2D*> listePoints
	 */
	vector<Vecteur2D*> getListe() const;
	/**
	 * Getter du nombre de points du polygone
	 * @return int nombre de points
	 */
	int getPts() const;
	/**
	 * Setter de la liste de points
	 * @param int nombre de points
	 */
	void setPts(int) ;

	/**
	 * Ajoute un point a listePoints
	 * @param Vecteur2D* point a ajouter
	 */
	void addPoint(Vecteur2D*);
	/**
	 * Supprime un point de listePoints
	 * @param Vecteur2D* point a supprimer
	 */
	void delPoint(const Vecteur2D*);
	/**
	 * Supprime un point de listePoints a l'index donné
	 * @param int position du point a supprimer
	 */
	void delPoint(const int i);
	/**
	 * Surcharge de l'opérateur[] pour accéder à un point de listePoints
	 * @param int index du point a chercher
	 * @return Vecteur2D* point recherché
	 */
	const Vecteur2D* operator[](const int i) const;

	/**
	 * Surcharge de l'operateur string pour l'affichage du polygone
	 */
	operator string() const;

	/**
	 * Calcule l'aire du polygone
	 * @return double (aire du polygone)
	 */
	virtual double getAire() const;
	/**
	 * Clone le polygone actuel
	 * @return FormeGeometrique* (copie du polygone)
	 */
	virtual Polygone* cloner() const;
	/**
	 * Envoie une requête de dessin au serveur
	 * @param Dessin&
	 */
	virtual void dessiner(const Dessin&);

	//------TRANSFORMATIONS GEOMETRIQUES SUR LE POLYGONE---------
	/**
	 * Modifie les données du polygone en effectuant une homotéthie
	 * @param Vecteur2D& point de reference de l'homotetie
	 * @param double facteur de zoom
	 */
	virtual void homothetie(const Vecteur2D&, const double);

	/**
	 * Modifie les données du polygone en effectuant une rotation
	 * @param Vecteur2D& point de reference de la rotation
	 * @param double angle de rotation (en radians)
	 */
	virtual void rotation(const Vecteur2D&, const double);
	/**
	 * Modifie les données du polygone en effectuant une translation
	 * @param Vecteur2D& point vecteur de translation
	 */
	virtual void translation(const Vecteur2D&);
	//------------------------------------------


	//-----TRANSFORMATIONS GEOMETRIQUES PAR COPIE---------
	/**
	 * Creee un nouveau polygone a partir de l'homotetie du polygone actuel
	 * @param Vecteur2D& point de reference de l'homotetie
	 * @param double facteur de zoom
	 * @return FormeGeometrique* (polygone issu de l'homotetie)
	 */
	virtual Polygone* homothetie2(const Vecteur2D&, const double);
	/**
	 * Creee un nouveau polygone a partir de la rotation du polygone actuel
	 * @param Vecteur2D& point de reference de la rotation
	 * @param double angle de rotation (en radians)
	 * @return FormeGeometrique* (polygone issu de la rotation)
	 */
	virtual Polygone* rotation2(const Vecteur2D&, const double);
	/**
	 * Creee un nouveau polygone a partir de la translation du polygone actuel
	 * @param Vecteur2D& point vecteur de translation
	 * @return FormeGeometrique* (polygone issu de la translation)
	 */
	virtual Polygone* translation2(const Vecteur2D&);
};