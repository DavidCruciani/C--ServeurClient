#include "Matrice.h"

Matrice::Matrice() :rang(1) {}

Matrice::Matrice(const int r):rang(r) {}

Matrice::Matrice(const Matrice &m) : rang(m.rang) {
	for (int i = 0; i < m.valeurs.size(); i++)
		valeurs = m.valeurs;
}

Matrice::~Matrice() {
	valeurs.erase(valeurs.begin(), valeurs.end());
}

void Matrice::setRang(const int r) {
	rang = r;
}

int Matrice::getRang() const {
	return rang;
}

void Matrice::addValeur(const double val, const int x, const int y) {

}