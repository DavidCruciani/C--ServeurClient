#include "DessinJava.h"
#include "FormeGeometrique.h"

#include "Connexion.h"


DessinJava::DessinJava(){}


DessinJava::~DessinJava(){}

void DessinJava::dessiner(const FormeGeometrique& f)const {
	string message = string(f);
	message.append("\n");
	cout << message;
	Connexion::getSinglCo()->envoyer(message.c_str());

	message.assign(Connexion::getSinglCo()->recevoir());
	cout << message;
}