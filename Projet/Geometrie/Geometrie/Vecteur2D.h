#pragma once
#ifndef _VECTEUR2D_
#define _VECTEUR2D_

#include<sstream>
#include <ostream>
#include <string>
#include <cmath>

#define SIN(x) sin(x * 3.141592653589/180) 
#define COS(x) cos(x * 3.141592653589/180)

using namespace std;

template <class T>
inline const T operator - (const T & u, const T & v)
{
	return u + -v;
}

class Vecteur2D
{
public:
	double x=0, y=0;

	inline  Vecteur2D(const double & x, const double & y) : x(x), y(y) {}
	inline Vecteur2D() : x(0), y(0) {}

	/**
	 * DONNEES : s respectant le format "(  nombre réel, nombre réel)"
	 *
	 * */
	inline Vecteur2D(const string s) 
	{
		double _x, _y;
		if (sscanf_s(s.c_str(), "(%lf,%lf)", &_x, &_y) != 0) {
			x = _x;
			y = _y;
		}
	}

	inline const Vecteur2D operator + (const Vecteur2D & u) const
	{
		return Vecteur2D(x + u.x, y + u.y);
	}

	inline const bool operator == (const Vecteur2D v) {
		return x == v.x && y == v.y;
	}

	inline const bool operator != (const Vecteur2D &v) {
		return !(this == &v);
	}

	inline const Vecteur2D operator = (const Vecteur2D &v) const {
		return Vecteur2D(v.x, v.y);
	}

	inline const Vecteur2D operator * (const double & a) const {
		return Vecteur2D(x*a, y*a);
	}

	Vecteur2D homothetie(const Vecteur2D & v, double scaleFactor) const;

	inline Vecteur2D rotation(const Vecteur2D &centre, const double a) {
		Vecteur2D origine = Vecteur2D(this->x - centre.x, this->y - centre.y);
		double x1 = centre.x + (origine.x * COS(a) - origine.y * SIN(a));
		double y1 = centre.y + (origine.x * SIN(a) + origine.y * COS(a));
		return Vecteur2D(x1, y1);
	}

	inline Vecteur2D translation(const Vecteur2D &pos) {
		return *this + pos;
	}

	/**
	 * - unaire (c'est-à- dire opposé d'un vecteur)
	 * */
	inline const Vecteur2D operator - () const {
		return Vecteur2D(-x, -y);
	}
	
	double norme(const Vecteur2D&)const;

	operator string() const;

	friend ostream & operator <<(ostream & os, const Vecteur2D & u);


}; // classe Vecteur2D


#endif