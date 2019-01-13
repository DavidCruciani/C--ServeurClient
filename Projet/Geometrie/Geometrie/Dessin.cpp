#include "Dessin.h"
#include "Cercle.h"
#include "Triangle.h"
#include "Segment.h"
#include "Polygone.h"
#include "FormeGeometrique.h"


Dessin::Dessin(){}


Dessin::~Dessin(){}

/*void Dessin::dessinerCercle(const Cercle& c) const{
	string message = (string)c;
	cout << message;
	Connexion::getSinglCo()->envoyer(message.c_str());

	message.assign(Connexion::getSinglCo()->recevoir());
}

void Dessin::dessinerSegment(const Segment& s)const {
	string message = (string)s;
	cout << message;
	connexion->envoyer(message.c_str());

	message.assign(connexion->recevoir());
}

void Dessin::dessinerTriangle(const Triangle& t)const {
	string message = (string)t;
	cout << message;
	connexion->envoyer(message.c_str());

	message.assign(connexion->recevoir());
}

void Dessin::dessinerPolygone(const Polygone& p)const {
	string message = (string)p;
	cout << message;
	connexion->envoyer(message.c_str());

	message.assign(connexion->recevoir());
}*/

void Dessin::dessiner(const FormeGeometrique& f)const {
	string message = string(f);
	cout << message;
	Connexion::getSinglCo()->envoyer(message.c_str());

	message.assign(Connexion::getSinglCo()->recevoir());
	cout << message;
}