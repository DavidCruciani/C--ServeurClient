#include "Cercle.h"

Cercle::Cercle():Simple("Noir"),vCentre(0,0),rayon(0){}

Cercle::Cercle(const Cercle &c):Simple(c.couleur), vCentre(c.vCentre.x, c.vCentre.y),rayon(c.rayon) {}

Cercle::~Cercle(){}

Cercle::Cercle(const double x, const double y, const double r) : Simple("Noir"), vCentre(x,y), rayon(r){}

Cercle::Cercle(const string couleur, const double x, const double y, const double r) : Simple(couleur), vCentre(x, y), rayon(r) {}

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

ostream & operator <<(ostream & os, const Cercle & c) {
	os << (string)c;
	return os;
}

FormeGeometrique* Cercle::cloner() const { 
	return new Cercle(*this); 
}

Cercle::operator string() const{
	ostringstream oss;
	oss << "Cercle[couleur: " << couleur << ", centre: " << vCentre << ", rayon: " << rayon << "]";
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

void Cercle::homothetie(const Vecteur2D&, const double zoom) {

}

void Cercle::rotation(const Vecteur2D &centre, const double a) {
	//Aucune rotation sur un cercle 
}

void Cercle::translation(const Vecteur2D &pos) {
	vCentre = vCentre.translation(pos);
}

/*FormeGeometrique* Cercle::homothetie2(const Vecteur2D &p, const double zoom) {
	//A VOIR COMMENT FAIRE
}*/

FormeGeometrique * Cercle::rotation2(const Vecteur2D &centre, const double angle) {
	//Aucune rotation sur un cercle, donc création d'un nouveau cercle avec les mêmes données
	return new Cercle(couleur, vCentre.x, vCentre.y, rayon);
}

FormeGeometrique * Cercle::translation2(const Vecteur2D &pos) {
	Vecteur2D centre = vCentre.translation(pos);
	return new Cercle(couleur, centre.x, centre.y, rayon);
}

