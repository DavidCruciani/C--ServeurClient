#include <iostream>
#include <chrono>
#include <thread>


#include "Vecteur2D.h"
#include "Cercle.h"
#include "Segment.h"
#include "Triangle.h"
#include "Polygone.h"

using namespace std;
int main()
{
	cout << "essai des vecteurs 2D \n";

	//Vecteur2D u1(2, 3), u2(2, 3), w, v1(35, -63), u3(3, 4), u4(3, -4), v3;
	Vecteur2D* A = new Vecteur2D(-9, 7);
	Vecteur2D* B = new Vecteur2D(-2, -6); 
	Vecteur2D* C = new Vecteur2D(8, -2);
	Vecteur2D* D = new Vecteur2D(9, 3);
	Vecteur2D* E = new Vecteur2D(4, 9);
	Vecteur2D* F = new Vecteur2D(-3, 4);
	//FormeGeometrique *  c1=new Cercle(200, 100, 50);
	FormeGeometrique *  c1=new Cercle(20, 10,20);
	FormeGeometrique * s1=new Segment(1,2,3,4);
	//Triangle t1(2, 2, 10, 2, 8, 8), t2(-3, 1, 4, 2, 2, 5), t3(0, 0, 0, 2, 2, 0), t4(1, 1, 3, 3, 5, 1);
	FormeGeometrique * t5 = new Triangle(2, 2, 10, 2, 8, 8);
	Polygone * p = new Polygone(A,B,C,D);
	Dessin *d=new Dessin() ;

	/*cout << " u1 = " << u1 << endl;
	cout << " u2 = " << u2 << endl;
	cout << " u1 - u2 = " << u1 - u2 << endl;
	cout << " 5*u1 = " << u1 * 5 << "\n" << endl;

	cout << c1 << endl;
	cout << "aire du cerlce: " << c1.getAire() << "\n" << endl;

	cout << s1 << endl;
	cout << "aire du segment: " << s1.getAire() << "\n" << endl;

	cout << t1 << endl;
	
	cout << "determinant du triangle: " << t1.getV1().determinant(t1.getV2()) << endl;
	cout << "aire du triangle: " << t1.getAire() <<"\n"<< endl; //67.05

	cout << t2 << endl;
	cout << "aire du triangle: " << t2.getAire() << "\n" << endl;

	cout << "aire du triangle: " << t3.getAire() << "\n" << endl;

	cout << "aire du triangle 4: " << t4.getAire() << "\n" << endl;

	cout <<"AB: "<< t2.getV1().norme(t1.getV2()) << endl;
	cout <<"AC: "<< t2.getV1().norme(t1.getV3()) << endl;
	cout <<"BC: "<< t2.getV2().norme(t1.getV3()) << endl;*/

	cout << "\n";
	//t5->dessiner(*d);
	//system("pause");

	cout << "\n";
	//c1->dessiner(*d);
	//system("pause");
	//this_thread::sleep_for(std::chrono::milliseconds(1500));
	cout << "\n";

	//s1->dessiner(*d);

	
	p->addPoint(E);
	p->addPoint(F);

	p->dessiner(*d);

	system("pause");
	return EXIT_SUCCESS;
}