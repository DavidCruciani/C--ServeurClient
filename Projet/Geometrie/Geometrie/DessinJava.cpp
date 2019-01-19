#include "DessinJava.h"

#include "Connexion.h"


DessinJava::DessinJava(){}


DessinJava::~DessinJava(){}

void DessinJava::dessiner(const FormeGeometrique& f)const {
	string message = string(f);
	message.append("\n");  //fin du message
	cout << message; //Affichage du message qui va etre envoyé

	Connexion::getSinglCo()->envoyer(message.c_str()); //envoi de la forme

	message.assign(Connexion::getSinglCo()->recevoir());  //reception du message du serveur
	cout << message;  //Affichage du message recu
}