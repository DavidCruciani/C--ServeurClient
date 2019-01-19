#include "Polygone.h"
#include "Dessin.h"

Polygone::Polygone():Simple("black") {}

Polygone::Polygone(const string c):Simple(c) {}

Polygone::Polygone(const Polygone &p):Simple(p.couleur) {}

Polygone::Polygone(Vecteur2D* v1, Vecteur2D* v2, Vecteur2D* v3, Vecteur2D* v4): Simple("black") {
	addPoint(v1); addPoint(v2); addPoint(v3); addPoint(v4);
}

Polygone::~Polygone() {
	for (int i = 0; i < listePoints.size(); i++) {

		delete listePoints[i];
	}
	listePoints.clear();
}

vector<Vecteur2D*> Polygone::getListe() const {
	return listePoints;
}

int Polygone::getPts()const {
	return nbPts;
}

void Polygone::setPts(int n) {
	nbPts = n;
}

void Polygone::addPoint(Vecteur2D *p) {
	bool trouvé = false;
	for (int i = 0; i < listePoints.size(); i++)
		if (listePoints[i] == p)
			trouvé = true;
	if (!false) {
		listePoints.push_back(p);
	}
	setPts(getPts() + 1);
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
	/*oss << "Polygone[couleur: " << couleur << endl;
	for (int i = 0; i < listePoints.size(); i++) 
		oss << "Point n°" << i + 1 << " " << listePoints[i] << endl;
	oss << "]" << endl;*/
	oss << "Polygone :" << couleur<< " "<< getPts() << " ";
	for (int i = 0; i < listePoints.size(); i++) {
		if (i == listePoints.size())
			oss << *listePoints[i];
		else
			oss << *listePoints[i] << " ";
	}
	return oss.str();
}

double Polygone::getAire() const {

	double somme = 0;
	for (int i = 0; i < listePoints.size()-1; i++) {

		somme += (listePoints[i]->x*listePoints[i + 1]->y) - (listePoints[i + 1]->x*listePoints[i]->y);
	}

	somme += (listePoints.back()->x * listePoints[0]->y) - (listePoints[0]->x*listePoints.back()->y);

	return somme/2;
}

Polygone* Polygone::cloner() const {
	return new Polygone(*this);
}

void Polygone::dessiner(const Dessin& d) {
	d.dessiner(*this);
}

void Polygone::homothetie(const Vecteur2D &p, const double zoom) {
	for (int i = 0; i < listePoints.size(); i++) {
		Vecteur2D *v = new Vecteur2D(listePoints[i]->homothetie(p, zoom));
		listePoints[i] = v;
	}
}

void Polygone::rotation(const Vecteur2D &centre, const double a) {
	for (int i = 0; i < listePoints.size(); i++) {
		listePoints[i] = &listePoints[i]->rotation(centre, a);
	}
}

void Polygone::translation(const Vecteur2D &pos) {
	for (int i = 0; i < listePoints.size(); i++) {
		listePoints[i] = &listePoints[i]->translation(pos);
	}
}

Polygone* Polygone::rotation2(const Vecteur2D &centre, const double a) {
	Polygone *p = this->cloner();
	for (int i = 0; i < p->listePoints.size(); i++) {
		p->listePoints[i] = &p->listePoints[i]->rotation(centre, a);
	}
	return p;
}

Polygone* Polygone::translation2(const Vecteur2D &pos) {
	Polygone *p = new Polygone(*this);
	for (int i = 0; i < p->listePoints.size(); i++) {
		p->listePoints[i] = &p->listePoints[i]->translation(pos);
	}
	return p;
}

Polygone* Polygone::homothetie2(const Vecteur2D &p, const double zoom) {
	Polygone *poly = this->cloner();
	for (int i = 0; i < listePoints.size(); i++) {
		Vecteur2D *v = new Vecteur2D(listePoints[i]->homothetie(p, zoom));
		poly->listePoints.push_back(v);
	}
	return poly;
 }

ostream& operator <<(ostream &os, const Polygone &p) {
	os << (string)p;
	return os;
}
