#include "Connexion.h"

#pragma comment(lib, "ws2_32.lib") // sp�cifique � VISUAL C++


Connexion* Connexion::singlCo = NULL;

Connexion * Connexion::getSinglCo() {

	if (singlCo == NULL) {
		string adresse="";
		short port;
		cout << "Adresse: "<< endl;
		cin >> adresse;
		cout << "\n";

		cout << "Port: " << endl;
		cin >> port;
		cout << "\n";

		singlCo= new Connexion(adresse.c_str(), port);
		//singlCo = new Connexion(ADRESSE_IP, PORT_SERVEUR);
	}
		

	return singlCo;
}

Connexion::Connexion(const char* adresseIP, short portServeur)
{
	try {
		if (!active)	this->init(); // Pour ouvrir les dll qu'une fois

		//---------------------- cr�ation socket -------------------------------------------------

		int familleAdresses = AF_INET;         // IPv4
		int typeSocket = SOCK_STREAM;           // mode connect� TCP
		int protocole = IPPROTO_TCP;            // protocole. On peut aussi mettre 0 et la fct choisit le protocole en fct des 2 1ers param�tres
												// pour les valeurs des param�tres : cf. fct socket dans la doc sur winsock

		sock = socket(familleAdresses, typeSocket, protocole);

		if (sock == INVALID_SOCKET)
		{
			ostringstream oss;
			oss << "la cr�ation du socket a �chou� : code d'erreur = " << WSAGetLastError() << endl;	// pour les valeurs renvoy�es par WSAGetLastError() : cf. doc r�f winsock
			throw Erreur(oss.str().c_str());
		}

		SOCKADDR_IN sockaddr; // informations concernant le serveur avec lequel on va communiquer

		sockaddr.sin_family = AF_INET;
		sockaddr.sin_addr.s_addr = inet_addr(adresseIP);   // inet_addr() convertit de l'ASCII en entier
		sockaddr.sin_port = htons(portServeur);                 //htons() assure que le port est bien inscrit dans le format du r�seau (little-endian ou big-endian)

		//-------------- connexion du client au serveur ---------------------------------------

		int r = connect(sock, (SOCKADDR *)&sockaddr, sizeof(sockaddr));     // renvoie une valeur non nulle en cas d'�chec.
																		// Le code d'erreur peut �tre obtenu par un appel � WSAGetLastError()

		if (r == SOCKET_ERROR)
			throw Erreur("La connexion a �chou�");
	}
	catch (Erreur erreur) {
		cerr << erreur << endl;
	}
}

Connexion::~Connexion(){}


void Connexion::init() const {
	try {
		//-------------- initialisation ressources librairie winsock -------------------------------
#ifdef WIN32

		WSADATA wsaData; //TODO structure contenant les donn�es de la librairie winsock � initialiser
		int r;

		r = WSAStartup(MAKEWORD(2, 0), &wsaData);       // MAKEWORD(2,0) sert � indiquer la version de la librairie � utiliser : 1 pour winsock et 2 pour winsock2

		// en cas de succ�s, wsaData a �t� initialis�e et l'appel a renvoy� la valeur 0 

		if (r) throw Erreur("L'initialisation a �chou�");

		active = 1;
	}
	catch (Erreur erreur) {
		cerr << erreur << endl;
	}

#endif
}


void Connexion::close() const {

	try {
		int r = shutdown(sock, SD_BOTH);							// on coupe la connexion pour l'envoi et la r�ception
																// renvoie une valeur non nulle en cas d'�chec. Le code d'erreur peut �tre obtenu par un appel � WSAGetLastError()
		if (r == SOCKET_ERROR)
			throw Erreur("la coupure de connexion a �chou�");


		r = closesocket(sock);                          // renvoie une valeur non nulle en cas d'�chec. Le code d'erreur peut �tre obtenu par un appel � WSAGetLastError()
		if (r) throw Erreur("La fermeture du socket a �chou�");

#ifdef WIN32
		WSACleanup();
#endif

		active = 0;
	}
	catch (Erreur erreur) {
		cerr << erreur << endl;
	}
}


void Connexion::envoyer(const char* message) const {

	try {

		int l = strlen(message);
		int r = send(sock, message, l, 0);             //------------------ envoi de la requ�te au serveur -------------------------------
														// envoie au plus  l octets
		if (r == SOCKET_ERROR)
			throw Erreur("�chec de l'envoi de la requ�te");
	}
	catch (Erreur erreur) {
		cerr << erreur << endl;
	}
}


string Connexion::recevoir() const {
	char reponse[L];

	try {

		int r = recv(sock, reponse, L, 0);             //----------- r�ception de la r�ponse du serveur -----------------------------
													// re�oit au plus L octets
													// en cas de succ�s, r contient le nombre d'octets re�us
		if (r == SOCKET_ERROR)
			throw Erreur("La r�ception de la r�ponse a �chou�");

		char * p = strchr(reponse, '\n');
		*(p + 1) = '\0';
	}
	catch (Erreur erreur) {
		cerr << erreur << endl;
		system("pause");
		exit(1);
	}
	string msg(reponse);
	return msg;
}