#include "Composee.h"

Composee::Composee() :FormeGeometrique() {}

Composee::Composee(const string c) : FormeGeometrique(c) {}

Composee::~Composee() {
	groupeSimple.erase(groupeSimple.begin(), groupeSimple.end());
	groupeComposee.erase(groupeComposee.begin(), groupeComposee.end());
}

void Composee::addFormeSimple(const Simple*) {

}

void Composee::delFormeSimple(const Simple *s) {
	vector<Simple*>::iterator it = find(groupeSimple.begin(), groupeSimple.end(), s);
	groupeSimple.erase(it);
}

void Composee::delFormeSimple(const int pos) {
	groupeSimple.erase(groupeSimple.begin() + pos);
}

void Composee::addFormeComposee(const Composee*) {

}

void Composee::delFormeComposee(const Composee *s) {
	vector<Composee*>::iterator it = find(groupeComposee.begin(), groupeComposee.end(), s);
	groupeComposee.erase(it);
}

void Composee::delFormeComposee(const int pos) {
	groupeComposee.erase(groupeComposee.begin() + pos);
}

Composee* Composee::cloner() {
	return new Composee(*this);
}

void Composee::dessiner() {
	for (int i = 0; i < groupeSimple.size(); i++) {
		groupeSimple[i]->dessiner();
	}
	for (int i = 0; i < groupeComposee.size(); i++) {
		groupeComposee[i]->dessiner();
	}
}

void Composee::Homotetie(const Vecteur2D&, const double) {

}

void Composee::rotation(const Vecteur2D &centre, const double angle) {
	for (int i = 0; i < groupeSimple.size(); i++) {
		groupeSimple[i]->rotation(centre, angle);
	}
	for (int i = 0; i < groupeComposee.size(); i++) {
		groupeComposee[i]->rotation(centre, angle);
	}
}

void Composee::translation(const Vecteur2D &trans) {
	for (int i = 0; i < groupeSimple.size(); i++) {
		groupeSimple[i]->translation(trans);
	}
	for (int i = 0; i < groupeComposee.size(); i++) {
		groupeComposee[i]->translation(trans);
	}
}