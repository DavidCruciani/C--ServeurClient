#pragma once
#ifndef _VECTEUR2D_
#define _VECTEUR2D_

#include<sstream>
#include <ostream>
#include <string>

using namespace std;

template <class T>
inline const T operator - (const T & u, const T & v)
{
	return u + -v;
}

class Vecteur2D
{
public:
	double x, y;

	inline  Vecteur2D(const double & x, const double & y) : x(x), y(y) {}
	inline Vecteur2D() : x(0), y(0) {}

	/**
	 * DONNEES : s respectant le format "(  nombre réel, nombre réel)"
	 *
	 * */
	inline Vecteur2D(const char * s);
	inline const Vecteur2D operator + (const Vecteur2D & u) const
	{
		return Vecteur2D(x + u.x, y + u.y);
	}

	inline const Vecteur2D operator = (const Vecteur2D &v) const {
		return Vecteur2D(v.x, v.y);
	}

	inline const Vecteur2D operator * (const double & a) const {
		return Vecteur2D(x*a, y*a);
	}

	/**
	 * - unaire (c'est-à- dire opposé d'un vecteur)
	 * */
	inline const Vecteur2D operator - () const {
		return Vecteur2D(-x, -y);
	}
	
	operator string() const;

	friend ostream & operator <<(ostream & os, const Vecteur2D & u);


}; // classe Vecteur2D


#endif