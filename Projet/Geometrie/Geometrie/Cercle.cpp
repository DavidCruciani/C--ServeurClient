#include "Cercle.h"
#include "Dessin.h"
#include "Erreur.h"


Cercle::Cercle():Simple("black"),vCentre(0,0),rayon(0){} // on définit par défaut la couleur sur noir

Cercle::Cercle(const Cercle &c):Simple(c.couleur), vCentre(c.vCentre.x, c.vCentre.y),rayon(c.rayon) {}

Cercle::~Cercle(){}

Cercle::Cercle(const double x, const double y, const double r) : Simple("black"), vCentre(x,y), rayon(r) {
	setRayon(r);
}

Cercle::Cercle(const string couleur, const double x, const double y, const double r) : Simple(couleur), vCentre(x, y), rayon(r) {
	setRayon(r);
}

void Cercle::setCentre(const double x1, const double y1) {
	vCentre.x = x1;
	vCentre.y = y1;
}

void Cercle::setRayon(const double r) {
	rayon = r;
}

Vecteur2D Cercle::getCentre() const{
	return vCentre;
}

double Cercle::getRayon() const {
	return rayon;
}

FormeGeometrique* Cercle::cloner() const { 
	return new Cercle(*this); 
}

Cercle::operator string() const{
	ostringstream oss;
	oss << "Cercle :" <<couleur<<" "<< vCentre << " " << rayon ;
	return oss.str();
}

string Cercle::toString() const {
	ostringstream oss;
	oss << "Cercle(" << vCentre.toString() << "," << rayon << ")" << "=" << couleur;
	return oss.str();
}

bool Cercle::operator==(const Cercle& c) const{
	return couleur==c.getCouleur() && this->getCentre() == c.getCentre() && rayon == c.getRayon();
}

void Cercle::operator=(const Cercle& c) {
	vCentre = c.getCentre();
	rayon = c.rayon;
	couleur = c.getCouleur();
}

double Cercle::getAire() const{
	return rayon * rayon* 3.141592653589;
}

void Cercle::dessiner(const Dessin& d) {
	d.dessiner(*this);
}

void Cercle::homothetie(const Vecteur2D &p, const double zoom) {
	vCentre = vCentre.homothetie(p, zoom);
	rayon = rayon * zoom;
}

void Cercle::rotation(const Vecteur2D &centre, const double a) {
	//Aucune rotation sur un cercle 
}

void Cercle::translation(const Vecteur2D &pos) {
	vCentre = vCentre.translation(pos);
}

FormeGeometrique* Cercle::homothetie2(const Vecteur2D &p, const double zoom) {
	Vecteur2D _vCentre = vCentre.homothetie(p, zoom);
	return new Cercle(couleur, _vCentre.x, _vCentre.y, rayon * zoom);
}

FormeGeometrique * Cercle::rotation2(const Vecteur2D &centre, const double angle) {
	//Aucune rotation sur un cercle, donc création d'un nouveau cercle avec les mêmes données
	return cloner();
}

FormeGeometrique * Cercle::translation2(const Vecteur2D &pos) {
	Vecteur2D centre = vCentre.translation(pos);
	return new Cercle(couleur, centre.x, centre.y, rayon);
}

