#include <iostream>
#include <vector>

#include "Vecteur2D.h"
#include "Cercle.h"
#include "Segment.h"
#include "Triangle.h"
#include "Polygone.h"
#include "TraitementForme.h"
#include "TraitementSegment.h"
#include "TraitementCercle.h"
#include "TraitementPolygone.h"
#include "TraitementTriangle.h"
#include "TraitementComposee.h"
#include "Composee.h"
#include "ChargerTxt.h"
#include "DessinJava.h"
#include "SauvegarderTxt.h"

using namespace std;
int main()
{
	cout << "essai des vecteurs 2D \n";

	Vecteur2D u1(2, 3), u2(2, 3), w, v1(35, -63), u3(3, 4), u4(3, -4), v3;
	Vecteur2D* A = new Vecteur2D(-4.5, 3.5);
	Vecteur2D* B = new Vecteur2D(-1, -3); 
	Vecteur2D* C = new Vecteur2D(4, -1);
	Vecteur2D* D = new Vecteur2D(4.5, 1.5);
	Vecteur2D* E = new Vecteur2D(2, 4.5);
	Vecteur2D* F = new Vecteur2D(-1.5, 2);
	//FormeGeometrique *  c1=new Cercle(200, 100, 50);
	//FormeGeometrique *  c1=new Cercle(20, 10,20);
	FormeGeometrique *  c1 = new Cercle("blue",2, 1, 2);
	//FormeGeometrique * s1=new Segment(1,2,3,4);
	FormeGeometrique * s1=new Segment("red",1,2,3,2);
	Triangle t1(2, 2, 10, 2, 8, 8), t2(-3, 1, 4, 2, 2, 5), t3(0, 0, 0, 2, 2, 0), t4(1, 1, 3, 3, 5, 1);
	FormeGeometrique * t5 = new Triangle(2, 2, 10, 2, 8, 8);
	Polygone * p = new Polygone("green");
	Composee * comp = new Composee("green");

	vector<FormeGeometrique*> liste;

	Dessin *d=new DessinJava() ;

	cout << " u1 = " << u1 << endl;
	cout << " u2 = " << u2 << endl;
	cout << " u1 - u2 = " << u1 - u2 << endl;
	cout << " 5*u1 = " << u1 * 5 << "\n" << endl;
	
	cout << (string)*c1 << endl;
	cout << "aire du cerlce: " << c1->getAire() << "\n" << endl;
	
	cout << s1 << endl;
	cout << "aire du segment: " << s1->getAire() << "\n" << endl;
	
	//cout << t1 << endl;
	
	//cout << "determinant du triangle: " << t5.getV1().determinant(t1.getV2()) << endl;
	cout << "aire du triangle: " << t1.getAire() <<"\n"<< endl; //67.05

//	cout << t2 << endl;
	cout << "aire du triangle: " << t2.getAire() << "\n" << endl;

	cout << "aire du triangle: " << t3.getAire() << "\n" << endl;

	cout << "aire du triangle 4: " << t4.getAire() << "\n" << endl;

	cout <<"AB: "<< t2.getV1().norme(t1.getV2()) << endl;
	cout <<"AC: "<< t2.getV1().norme(t1.getV3()) << endl;
	cout <<"BC: "<< t2.getV2().norme(t1.getV3()) << endl;

	cout << "\n";
	//t5->dessiner(*d);
	//system("pause");
	t5=t5->rotation2(Vecteur2D(2, 2), 30);
	//t5->dessiner(*d);

	cout << "\n";
	//c1->dessiner(*d);
	//c1 = c1->homothetie2(Vecteur2D(2, 2), 2);
	//c1->dessiner(*d);
	//system("pause");

	cout << "\n";

	//s1->dessiner(*d);
	//s1 = s1->homothetie2(Vecteur2D(2, 2), 2);
	//s1->dessiner(*d);


	p->addPoint(A);
	p->addPoint(B);
	p->addPoint(C);
	p->addPoint(D);
	p->addPoint(E);
	p->addPoint(F);

	//cout << "aire du polygone : " << p->getAire() << "\n" << endl;

	p->dessiner(*d);
	//p = p->homothetie2(Vecteur2D(2, 2), 2);
	//p = p->rotation2(Vecteur2D(2, 2), 2);
	p = p->translation2(Vecteur2D(2, 2));
	p->dessiner(*d);

	/*comp->addForme(c1);
	comp->addForme(s1);
	comp->addForme(t5);
	comp->dessiner(*d);*/

	// TEST chaine de responsabilite
	/*const char* instruction;
	const char *fichier = "test.txt";
	TraitementForme *traitement, *segment, *cercle, *polygone, *triangle, *composee;
	segment = new TraitementSegment(NULL);
	cercle = new TraitementCercle(segment);
	polygone = new TraitementPolygone(cercle);
	triangle = new TraitementTriangle(polygone);
	composee = new TraitementComposee(triangle);
	traitement = composee;
	// Chaine responsabilite Chargement
	Charger *txt, *charger;
	txt = new ChargerTxt(NULL);
	charger = txt;
	liste = charger->charge(fichier, traitement);
	cout << " Affichage formes fichier\n\n";
	//for (int i = 0; i < liste.size(); i++)
		//cout << liste[i]<<"\n";
		//liste[i]->dessiner(*d);*/
	                                 
	//////// CREATION Segment //////////
	/*instruction = "Segment(10,15,20,26)";
	//const char *insSegment = "(5,6,7,8);";
	FormeGeometrique *s = traitement->traiter(instruction);
	cout << "Forme attendue : Segment (10,15,20,26)\n\n" << endl;
	cout << "Forme obtenue ==>     " << s << "\n\n\n" << endl;

	////////Sauvegarde//////////
	Sauvegarde *save = new SauvegarderTxt;
	save->sauvegarde(s1);*/

	//s->dessiner(*d);
	/*
	//////// CREATION CERCLE //////////
	instruction = "Cercle(11,20,30)=cyan";
	FormeGeometrique *c = traitement->traiter(instruction);
	cout << "Forme attendue : Cercle=orange(11,20,30)\n\n" << endl;
	cout << "Forme obtenue ==>     " << c << "\n\n\n" << endl;

	c->dessiner(*d);
	*/
	//////// CREATION Triangle //////////
	/*instruction = "Triangle(2,1,3,2,1,3)";
	FormeGeometrique *t = traitement->traiter(instruction);
	cout << "Forme attendue : Triangle(2,1,3,2,1,3)\n\n" << endl;
	cout << "Forme obtenue ==>     " << t << "\n\n\n" << endl;
	t->dessiner(*d);
	t = t->homothetie2(Vecteur2D(5, 6), 2);
	t->dessiner(*d);*/
	/*
	//////// CREATION POLYGONE //////////
	instruction = "Polygone{=green(5,1)(6,7)(7,8)(4,6)}";
	FormeGeometrique *poly = traitement->traiter(instruction);
	cout << "Forme attendue : Polygone{(5,1)(6,7)(7,8)(4,6)}\n\n" << endl;
	cout << "Forme obtenue ==>     " << poly << "\n\n\n" << endl;

	poly->dessiner(*d);

	
	//////// CREATION Composee //////////
	instruction = "Composee{=red;*Segment(5,4,3,6)**Cercle(5,9,10)*}";
	FormeGeometrique *compo = traitement->traiter(instruction);
	cout << "Forme attendue : Composee{ Segment(5,4,3,6), Cercle(5,9,10)}" << endl;
	cout << "Forme obtenue ==>     " << compo << "\n\n\n" << endl;

	compo->dessiner(*d);*/

	system("pause");
	return EXIT_SUCCESS;
}