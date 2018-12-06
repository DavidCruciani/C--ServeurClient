#include "Triangle.h"

Triangle::Triangle():Simple(), v1(0,0), v2(0,0), v3(0,0) {}

Triangle::Triangle(const string c, const double x1, const double y1, const double x2, const double y2, const double x3, const double y3)
	:Simple(c), v1(x1,y1), v2(x2,y2), v3(x3,y3) {}

Triangle::Triangle(const double x1, const double y1, const double x2, const double y2, const double x3, const double y3)
	: Simple("Noir"), v1(x1, y1), v2(x2, y2), v3(x3, y3) {}

Triangle::~Triangle() {}

void Triangle::setV1(const double x1, const double y1) {
	v1.x = x1;
	v1.y = y1;
}

void Triangle::setV2(const double x2, const double y2) {
	v2.x = x2;
	v2.y = y2;
}

void Triangle::setV3(const double x3, const double y3) {
	v3.x = x3;
	v3.y = y3;
}

Vecteur2D Triangle::getV1() const {
	return v1;
}

Vecteur2D Triangle::getV2() const {
	return v2;
}

Vecteur2D Triangle::getV3() const {
	return v3;
}

double Triangle::getAire() const {
	return 0;
}

Simple* Triangle::cloner() const {
	return new Triangle(*this);
}

void Triangle::dessiner() {

}

void Triangle::homothetie(const Vecteur2D &p, const double zoom) {}

void Triangle::rotation(const Vecteur2D &centre, const double a) {}

void Triangle::translation(const Vecteur2D &pos) {
	v1 = v1 + pos;
	v2 = v2 + pos;
	v3 = v3 + pos;
}