#include "Composee.h"

Composee::Composee() :FormeGeometrique() {}

Composee::Composee(const string c) : FormeGeometrique(c) {}

Composee::~Composee() {
	groupe.erase(groupe.begin(), groupe.end());
}

void Composee::addForme(const FormeGeometrique*) {

}

void Composee::delForme(const FormeGeometrique *f) {
	vector<FormeGeometrique*>::iterator it = find(groupe.begin(), groupe.end(), f);
	groupe.erase(it);
}

void Composee::delForme(const int pos) {
	groupe.erase(groupe.begin() + pos);
}

FormeGeometrique* Composee::cloner() const {
	return new Composee(*this);
}

void Composee::dessiner() {
	for (int i = 0; i < groupe.size(); i++) {
		groupe[i]->dessiner();
	}
}

double Composee::getAire() const {
	double aire = 0;
	for (int i = 0; i < groupe.size(); i++) {
		aire = aire + groupe[i]->getAire();
	}
	return aire;
}

void Composee::homothetie(const Vecteur2D &p, const double zoom) {
	for (int i = 0; i < groupe.size(); i++) {
		groupe[i]->homothetie(p, zoom);
	}
}

void Composee::rotation(const Vecteur2D &centre, const double angle) {
	for (int i = 0; i < groupe.size(); i++) {
		groupe[i]->rotation(centre, angle);
	}
}

void Composee::translation(const Vecteur2D &trans) {
	for (int i = 0; i < groupe.size(); i++) {
		groupe[i]->translation(trans);
	}
}