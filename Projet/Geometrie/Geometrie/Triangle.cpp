#include "Triangle.h"
#include "Dessin.h"

Triangle::Triangle():Simple(), v1(0,0), v2(0,0), v3(0,0) {}

Triangle::Triangle(const Triangle &t):Simple(t.couleur), v1(t.v1.x, t.v1.y), v2(t.v2.x, t.v2.y), v3(t.v3.x,t.v3.y) {}

Triangle::Triangle(const string c, const double x1, const double y1, const double x2, const double y2, const double x3, const double y3)
	:Simple(c), v1(x1,y1), v2(x2,y2), v3(x3,y3) {}

Triangle::Triangle(const double x1, const double y1, const double x2, const double y2, const double x3, const double y3)
	: Simple("black"), v1(x1, y1), v2(x2, y2), v3(x3, y3) {}

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

Triangle::operator string() const {
	ostringstream oss;
	oss << "Triangle :" << couleur << " " << v1 << " " << v2 << " " << v3;
	return oss.str();
}

string Triangle::toString() const {
	ostringstream oss;
	oss << "Triangle(" << v1.toString() << "," << v2.toString() << "," << v3.toString() << ")" << "=" << couleur;
	return oss.str();
}


double Triangle::getAire() const {

	return 0.5 * abs(((v2.x - v1.x)*(v3.y - v1.y) - (v3.x - v1.x)*(v2.y - v1.y)));

}

FormeGeometrique* Triangle::cloner() const {
	return new Triangle(*this);
}

void Triangle::dessiner(const Dessin& d) {
	d.dessiner(*this);
}

void Triangle::homothetie(const Vecteur2D &p, const double zoom) {
	v1 = v1.homothetie(p, zoom);
	v2 = v2.homothetie(p, zoom);
	v3 = v3.homothetie(p, zoom);
}

void Triangle::rotation(const Vecteur2D &centre, const double a) {
	//Rotation V1
	v1 = v1.rotation(centre, a);
	//Rotation V2
	v2 = v2.rotation(centre, a);
	//Rotation V3
	v3 = v3.rotation(centre, a);
}

void Triangle::translation(const Vecteur2D &pos) {
	v1 = v1.translation(pos);
	v2 = v2.translation(pos);
	v3 = v3.translation(pos);
}

FormeGeometrique* Triangle::homothetie2(const Vecteur2D &p, const double zoom) { 
	Vecteur2D _v1 = v1.homothetie(p, zoom);
	Vecteur2D _v2 = v2.homothetie(p, zoom);
	Vecteur2D _v3 = v3.homothetie(p, zoom);
	return new Triangle(couleur, _v1.x, _v1.y, _v2.x, _v2.y, _v3.x, _v3.y);
}

FormeGeometrique* Triangle::rotation2(const Vecteur2D &centre, const double a) {
	//Rotation V1
	Vecteur2D p1 = v1.rotation(centre, a);
	//Rotation V2
	Vecteur2D p2 = v2.rotation(centre, a);
	//Rotation V3
	Vecteur2D p3 = v3.rotation(centre, a);
	return new Triangle(couleur, p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);
}

FormeGeometrique* Triangle::translation2(const Vecteur2D &pos) {
	Vecteur2D p1 = v1.translation(pos);
	Vecteur2D p2 = v2.translation(pos);
	Vecteur2D p3 = v3.translation(pos);
	return new Triangle(couleur, p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);
}