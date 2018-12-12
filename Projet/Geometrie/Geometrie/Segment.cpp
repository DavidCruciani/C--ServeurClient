#include "Segment.h"

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
void Segment::dessiner() {
	//A  VOIR COMMENT FAIRE
}

void Segment::homothetie(const Vecteur2D &p, const double zoom) {
	//A  VOIR COMMENT FAIRE
}

void Segment::rotation(const Vecteur2D &centre, const double a) {
	//Rotation V1
	Vecteur2D origine = Vecteur2D(v1.x - centre.x, v1.y - centre.y);
	v1.x = centre.x + (origine.x * COS(a) - origine.y * SIN(a));
	v1.y = centre.y + (origine.x * SIN(a) - origine.y * COS(a));
	//Rotation V2
	origine = Vecteur2D(v2.x - centre.x, v2.y - centre.y);
	v2.x = centre.x + (origine.x * COS(a) - origine.y * SIN(a));
	v2.y = centre.y + (origine.x * SIN(a) - origine.y * COS(a));
}

void Segment::translation(const Vecteur2D &pos) {
	v1 = v1 + pos;
	v2 = v2 + pos;	
}

FormeGeometrique* Segment::homothetie2(const Vecteur2D &p, const double zoom) {
	//A VOIR COMMENT FAIRE
}

FormeGeometrique* Segment::rotation2(const Vecteur2D &centre, const double a) {
	Vecteur2D origine = Vecteur2D(v1.x - centre.x, v1.y - centre.y);
	double x1 = centre.x + (origine.x * COS(a) - origine.y * SIN(a));
	double y1 = centre.y + (origine.x * SIN(a) - origine.y * COS(a));
	//Rotation V2
	origine = Vecteur2D(v2.x - centre.x, v2.y - centre.y);
	double x2 = centre.x + (origine.x * COS(a) - origine.y * SIN(a));
	double y2 = centre.y + (origine.x * SIN(a) - origine.y * COS(a));
	return new Segment(couleur, x1, y1, x2, y2);
}

FormeGeometrique* Segment::translation2(const Vecteur2D &pos) {
	Vecteur2D p1 = v1 + pos;
	Vecteur2D p2 = v2 + pos;
	return new Segment(couleur, p1.x, p1.y, p2.x, p2.y);
}