#include "Composee.h"
#include "Dessin.h"

Composee::Composee() :FormeGeometrique() {}

Composee::Composee(const string c) : FormeGeometrique(c) {}

Composee::~Composee() {
	groupe.erase(groupe.begin(), groupe.end());
}

void Composee::addForme(FormeGeometrique *f) {
	//on attribue la couleur de this a f
	f->setCouleur(this->getCouleur());
	groupe.push_back(f->cloner());
}

void Composee::delForme(const FormeGeometrique *f) {
	vector<FormeGeometrique*>::iterator it = find(groupe.begin(), groupe.end(), f);
	groupe.erase(it);
}

void Composee::delForme(const int pos) {
	groupe.erase(groupe.begin() + pos);
}

FormeGeometrique* Composee::getForme(const int pos) {
	return groupe[pos];
}

FormeGeometrique* Composee::cloner() const {
	return new Composee(*this);
}

void Composee::dessiner(const Dessin& d) {
	d.dessiner(*this);
}

double Composee::getAire() const {
	double aire = 0;
	for (int i = 0; i < groupe.size(); i++) {
		// on calcule la somme des aires des formes qui composent la forme composée
		aire = aire + groupe[i]->getAire();
	}
	return aire;
}

Composee::operator string() const {
	ostringstream oss;
	oss << "Compose [";
	for (int i = 0; i < groupe.size(); i++) {
		if(i== groupe.size()-1)
			oss << groupe[i];
		else
			oss <<groupe[i] << ";";
	}
	oss << "]";
	return oss.str();

}

string Composee::toString() const {
	ostringstream oss;
	oss << "Composee{=" << couleur << ";";
	for (int i = 0; i < groupe.size(); i++) {
		if (i == groupe.size() - 1)
			oss << "*" << groupe[i]->toString() << "*";
		else
			oss << "*" << groupe[i]->toString() << "*";
	}
	oss << "}";
	return oss.str();

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

FormeGeometrique* Composee::homothetie2(const Vecteur2D& p, const double zoom) {
	Composee *compo = new Composee(couleur);
	for (int i = 0; i < groupe.size(); i++) {
		compo->groupe.push_back(groupe[i]->homothetie2(p, zoom));
	}
	return compo;
}

FormeGeometrique* Composee::rotation2(const Vecteur2D& v, const double r) {
	Composee *compo = new Composee(couleur);
	for (int i = 0; i < groupe.size(); i++) {
		compo->groupe.push_back(groupe[i]->rotation2(v, r));
	}
	return compo;
}

FormeGeometrique* Composee::translation2(const Vecteur2D& v) {
	Composee *compo = new Composee(couleur);
	for (int i = 0; i < groupe.size(); i++) {
		compo->groupe.push_back(groupe[i]->translation2(v));
	}
	return compo;
}