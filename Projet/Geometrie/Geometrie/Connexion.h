#pragma once
#pragma comment(lib, "ws2_32.lib") // spécifique à VISUAL C++

#include <iostream>
#include <string>
#include <winsock2.h>
#include <sstream>
#include "Erreur.h"

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

#define ADRESSE_IP "127.0.0.1"
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

};
