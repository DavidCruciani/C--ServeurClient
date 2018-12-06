#include "Triangle.h"

Triangle::Triangle():Simple(), v1(0,0), v2(0,0), v3(0,0) {}

Triangle::Triangle(const Triangle &t):Simple(t.couleur), v1(t.v1.x, t.v1.y), v2(t.v2.x, t.v2.y), v3(t.v3.x,t.v3.y) {}

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

ostream & operator <<(ostream & os, const Triangle & t) {
	os << (string)t;
	return os;
}

Triangle::operator string() const {
	ostringstream oss;
	oss << "Triangle[couleur: " << couleur << ", Point 1: " << v1 << ", Point 2: " << v2 << ", Point 3: " << v3 << "]";
	return oss.str();
}

double Triangle::getAire() const {
	double norme12,norme,norme13,norme23;

	norme12 = v1.norme(v2);
	norme13 = v1.norme(v3);
	norme23 = v2.norme(v3);
	
	norme = (norme12 + norme13 + norme23) / 2;

	return sqrt(norme*(norme - norme12)*(norme - norme13)*(norme - norme23));
	//return 0.5 * (v2.x - v1.x)*(v3.y - v1.y) - (v3.x - v1.x)*(v2.y - v1.y);

	//return 0.5 * (v1.y*(v3.x-v2.x)+v3.y*(v2.x-v1.x)+v2.y*(v1.x-v3.x));
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