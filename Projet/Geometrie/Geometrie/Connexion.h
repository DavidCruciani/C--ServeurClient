#pragma once

#include <iostream>
#include <string>
#include <winsock2.h>
#include <sstream>
#include "Erreur.h"

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

//#define ADRESSE_IP "10.10.210.102"
#define ADRESSE_IP "192.168.56.1"
#define PORT_SERVEUR 9111

const static int L = 200;
static int active = 0;

/*! \class EnvoyeurReceveur
*\brief Classe EnvoyeurReceveur
*
*\La classe permet la connection à un socket distant à partir
* de ses champs
*/
class Connexion {
private:
	SOCKET sock;
	static Connexion *singlCo;

public:

	Connexion(const char* adresseIP, short portServeur);
	~Connexion();

	void init() const;

	void close() const;

	/*!
	*\brief permet d'envoyer une chaine de caractère
	*au serveur java
	*
	*/
	void envoyer(const char* message) const;

	/*!
	*\brief permet de récuperer le message du serveur java
	*
	*\return string : message du serveur java
	*/
	string recevoir() const;

	static Connexion* getSinglCo();
};
