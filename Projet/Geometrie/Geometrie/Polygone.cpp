#include "Polygone.h"

Polygone::Polygone():Simple("noir") {}

Polygone::Polygone(const string c):Simple(c) {}

Polygone::Polygone(const Polygone &p):Simple(p.couleur) {}

Polygone::~Polygone() {
	listePoints.erase(listePoints.begin(), listePoints.end());
}

void Polygone::addPoint(Vecteur2D *p) {
	bool trouv� = false;
	for (int i = 0; i < listePoints.size(); i++)
		if (listePoints[i] == p)
			trouv� = true;
	if (!false) {
		listePoints.push_back(p);
	}
}

void Polygone::delPoint(const Vecteur2D *p) {
	vector<Vecteur2D*>::iterator it = find(listePoints.begin(), listePoints.end(), p);
	listePoints.erase(it);
}

void Polygone::delPoint(const int pos) {
	listePoints.erase(listePoints.begin() + pos);
}

const Vecteur2D* Polygone::operator[](const int index) const {
	if (index < listePoints.size() && index >= 0)
		return listePoints[index];
	else
		throw - 1;
}

Polygone::operator string() const {
	ostringstream oss;
	oss << "Polygone[couleur: " << couleur << endl;
	for (int i = 0; i < listePoints.size(); i++) 
		oss << "Point n�" << i + 1 << " " << listePoints[i] << endl;
	oss << "]" << endl;
	return oss.str();
}

double Polygone::getAire() const {
	// A FAIRE
	return 0;
}

FormeGeometrique* Polygone::cloner() const {
	return new Polygone(*this);
}

void Polygone::dessiner() {

}

void Polygone::homothetie(const Vecteur2D &p, const double zoom) {}

void Polygone::rotation(const Vecteur2D &centre, const double angle) {}

void Polygone::translation(const Vecteur2D &p) {}

ostream& operator <<(ostream &os, const Polygone &p) {
	os << (string)p;
	return os;
}