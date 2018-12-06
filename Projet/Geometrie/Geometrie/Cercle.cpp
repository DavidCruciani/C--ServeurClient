#include "Cercle.h"


Cercle::Cercle():Simple("Noir"),vCentre(0,0),rayon(0){}

Cercle::Cercle(const Cercle &c):Simple(c.couleur), vCentre(c.vCentre.x, c.vCentre.y) {}

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

ostream & operator <<(ostream & os, const Cercle & u) {
	os << (string)u;
	return os;
}

Simple* Cercle::cloner() const { 
	return new Cercle(*this); 
}

Cercle::operator string() const{
	ostringstream oss;
	oss << "cercle: " << couleur << ", " << vCentre << ", " << rayon;
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
	return 0;
	//A FAIRE
}

void Cercle::dessiner() {
	//A  VOIR COMMENT FAIRE
}

void Cercle::homothetie(const Vecteur2D&, const double zoom) {

}

void Cercle::rotation(const Vecteur2D &centre, const double a) {
	//A  VOIR COMMENT FAIRE
}

void Cercle::translation(const Vecteur2D &pos) {
	vCentre = vCentre + pos;
}