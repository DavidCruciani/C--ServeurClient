#include <iostream>
#include <Windows.h> // Pour les accents dans la console sous Windows
#include "Vecteur2D.h"

using namespace std;
int main()
{
	cout << "essai des vecteurs 2D \n";

	Vecteur2D u1(2, 3), u2(2, 3), w, v1(35, -63), u3(3, 4), u4(3, -4), v3;

	cout << " u1 = " << u1 << endl;
	cout << " u2 = " << u2 << endl;
	cout << " u1 - u2 = " << u1 - u2 << endl;
	cout << " 5*u1 = " << u1 * 5 << endl;
	system("pause");
	return EXIT_SUCCESS;
}