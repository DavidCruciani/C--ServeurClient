#include "Composee.h"

using namespace std;

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
	/*for (int i = 0; i < groupeSimple.size(); i++) {
		//(groupeSimple.begin() + i).dessiner();
	}
	for (int i = 0; i < groupeComposee.size(); i++) {
		//(groupeComposee.begin() + i).dessiner();
	}*/
}

void Composee::rotation(const double angle) {
	/*for (int i = 0; i < groupeSimple.size(); i++) {
		//(groupeSimple.begin() + i).rotation(angle);
	}
	for (int i = 0; i < groupeComposee.size(); i++) {
		//(groupeComposee.begin() + i).rotation(angle);
	}*/
}

void Composee::translation(const Vecteur2D &trans) {
	/*for (int i = 0; i < groupeSimple.size(); i++) {
		//(groupeSimple.begin() + i).translation(trans);
	}
	for (int i = 0; i < groupeComposee.size(); i++) {
		//(groupeComposee.begin() + i).translation(trans);
	}*/
}