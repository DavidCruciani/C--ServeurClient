#include "Segment.h"
#include "Dessin.h"

Segment::Segment():Simple("Noir"), v1(0, 0), v2(0, 0) {}

Segment::Segment(const Segment &s):Simple(s.couleur), v1(s.v1.x, s.v1.y), v2(s.v2.x, s.v2.y) {}

Segment::Segment(const string c, const double x1, const double y1, const double x2, const double y2):Simple(c), v1(x1, y1), v2(x2, y2) {}

Segment::Segment(const double x1, const double y1, const double x2, const double y2) : Simple("Noir"), v1(x1, y1), v2(x2, y2) {}

Segment::~Segment() {}

void Segment::setV1(const double x1, const double y1) {
	v1.x = x1;
	v1.y = y1;
}

void Segment::setV2(const double x2, const double y2) {
	v2.x = x2;
	v2.y = y2;
}

Vecteur2D Segment::getV1() const {
	return v1;
}

Vecteur2D Segment::getV2() const {
	return v2;
}

ostream & operator <<(ostream & os, const Segment & s) {
	os << (string)s;
	return os;
}

Segment::operator string() const {
	ostringstream oss;
	oss << "Segment[couleur: " << couleur << ", Point 1: " << v1 << ", Point 2: " << v2 << "]";
	return oss.str();
}


double Segment::getAire() const {
	return 0;
}

FormeGeometrique* Segment::cloner() const {
	return new Segment(*this);
}
void Segment::dessiner(const Dessin& d) {
	d.dessiner(*this);
}

void Segment::homothetie(const Vecteur2D &p, const double zoom) {
	//A  VOIR COMMENT FAIRE
}

void Segment::rotation(const Vecteur2D &centre, const double a) {
	//Rotation V1
	v1 = v1.rotation(centre, a);
	//Rotation V2
	v2 = v2.rotation(centre, a);
}

void Segment::translation(const Vecteur2D &pos) {
	v1 = v1.translation(pos);
	v2 = v2.translation(pos);
}

/*FormeGeometrique* Segment::homothetie2(const Vecteur2D &p, const double zoom) {
	//A VOIR COMMENT FAIRE
}*/

FormeGeometrique* Segment::rotation2(const Vecteur2D &centre, const double a) {
	//Rotation V1
	Vecteur2D p1 = v1.rotation(centre, a);
	//Rotation V2
	Vecteur2D p2 = v2.rotation(centre, a);
	return new Segment(couleur, p1.x, p1.y, p2.x, p2.y);
}

FormeGeometrique* Segment::translation2(const Vecteur2D &pos) {
	Vecteur2D p1 = v1.translation(pos);
	Vecteur2D p2 = v2.translation(pos);
	return new Segment(couleur, p1.x, p1.y, p2.x, p2.y);
}