#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include "Erreur.h"

#ifdef  __unix__

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>


#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define WSAGetLastError() errno
#define SD_BOTH 2
#define closesocket(s) close(s)
typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;

#else

#include <winsock2.h>

#if (_MSC_VER == 1800)
	#define strdup _strdup
#endif

#endif

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

//#define ADRESSE_IP "10.10.210.102"
//#define ADRESSE_IP "192.168.56.1"
//#define PORT_SERVEUR 9111

const static int L = 200;
static int active = 0;

/*! \class Connexion
*\brief Classe Connexion
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
