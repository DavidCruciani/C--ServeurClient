#include "Segment.h"

Segment::Segment():Simple("Noir"), v1(0, 0), v2(0, 0) {}

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

double Segment::getAire() const {
	return 0;
}

Simple* Segment::cloner() const {
	return new Segment(*this);
}
void Segment::dessiner() {
	//A  VOIR COMMENT FAIRE
}

void Segment::homothetie(const Vecteur2D &p, const double zoom) {
	//A  VOIR COMMENT FAIRE
}

void Segment::rotation(const Vecteur2D &centre, const double a) {
	//A  VOIR COMMENT FAIRE
}

void Segment::translation(const Vecteur2D &pos) {
	v1 = v1 + pos;
	v2 = v2 + pos;	
}