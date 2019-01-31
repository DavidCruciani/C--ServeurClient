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
#include "Erreur.h"

using namespace std;
int main()
{
	cout << "Bienvenue \n" << endl;
	Vecteur2D* A = new Vecteur2D(-4.5, 3.5);
	Vecteur2D* B = new Vecteur2D(-1, -3); 
	Vecteur2D* C = new Vecteur2D(4, -1);
	Vecteur2D* D = new Vecteur2D(4.5, 1.5);
	Vecteur2D* E = new Vecteur2D(2, 4.5);
	Vecteur2D* F = new Vecteur2D(-1.5, 2);
	FormeGeometrique *  c;

	try {
		c = new Cercle("blue",2, 1, -2);
	}
	catch (Erreur erreur) {
		cerr << erreur << endl;
	}
	FormeGeometrique *  c1;

	FormeGeometrique * s = new Segment("red",1,2,3,2);
	FormeGeometrique * s1;

	FormeGeometrique * t = new Triangle(2, 2, 10, 2, 8, 8);
	FormeGeometrique * t1;

	Polygone * p = new Polygone("green");
	Polygone * p1;

	Composee * comp = new Composee("green");
	Composee * comp1;

	vector<FormeGeometrique*> liste;

	Sauvegarde *save = new SauvegarderTxt;

	Dessin *d=new DessinJava() ;

	
	//////// CREATION Cercle //////////
	cout << "Voici un cercle: \n" << endl;
	cout << c << endl;
	system("pause");

	cout << "\nAire du cerlce: " << c->getAire() << "\n" << endl;
	system("pause");

	cout << "Maintenant un magnifique dessin:\n" << endl;
	d->dessiner(*c);
	//c->dessiner(*d);
	system("pause");

	cout << "Une translation\n" << endl;
	c1 = c->translation2(Vecteur2D(5, 5));
	d->dessiner(*c1);
	system("pause");

	cout << "Une homotethie\n" << endl;
	c1 = c->homothetie2(Vecteur2D(7, 5), 2);
	d->dessiner(*c1);
	system("pause");

	cout << "Sauvegarde du cercle dans Formes.txt qui sera cree sur le bureau\n" << endl;
	save->sauvegarde(c);
	system("pause");
	

	//////// CREATION Segment //////////
	cout << "\nVoici un Segment:" << endl;
	cout << s << endl;
	system("pause");

	cout << "\nAire du segment: " << s->getAire() << "\n" << endl;
	system("pause");

	cout << "Maintenant un magnifique dessin:\n" << endl;
	d->dessiner(*s);
	system("pause");

	cout << "Une translation\n" << endl;
	s1 = s->translation2(Vecteur2D(5, 5));
	d->dessiner(*s1);
	system("pause");

	cout << "Une rotation\n" << endl;
	s1 = s->rotation2(Vecteur2D(2, 2), 30);
	d->dessiner(*s1);
	system("pause");

	cout << "Une homotethie\n" << endl;
	s1 = s->homothetie2(Vecteur2D(7, 5), 2);
	d->dessiner(*s1);
	system("pause");

	cout << "Sauvegarde du segment dans Formes.txt qui sera cree sur le bureau\n" << endl;
	save->sauvegarde(s);
	system("pause");

	
	//////// CREATION Triangle //////////
	cout << "\nVoici un Triangle" << endl;
	cout << t << endl;
	system("pause");

	cout << "\nAire du triangle: " << t->getAire() << "\n" << endl;
	system("pause");

	cout << "Maintenant un magnifique dessin:\n" << endl;
	d->dessiner(*t);
	system("pause");

	cout << "Une translation\n" << endl;
	t1 = t->translation2(Vecteur2D(5, 5));
	d->dessiner(*t1);
	system("pause");

	cout << "Une rotation\n" << endl;
	t1 = t->rotation2(Vecteur2D(2, 2), 30);
	d->dessiner(*t1);
	system("pause");

	cout << "Une homotethie\n" << endl;
	t1 = t->homothetie2(Vecteur2D(7, 5), 2);
	d->dessiner(*t1);
	system("pause");

	cout << "Sauvegarde du triangle dans Formes.txt qui sera cree sur le bureau\n" << endl;
	save->sauvegarde(t);
	system("pause");
	

	//////// CREATION Polygone //////////
	cout << "\nVoici un Polygone" << endl;
	p->addPoint(A);
	p->addPoint(B);
	p->addPoint(C);
	p->addPoint(D);
	p->addPoint(E);
	p->addPoint(F);

	cout << p << endl;
	system("pause");

	cout << "\nAire du polygone : " << p->getAire() << "\n" << endl;
	system("pause");

	cout << "Maintenant un magnifique dessin:\n" << endl;
	d->dessiner(*p);
	system("pause");

	cout << "Une homotethie\n" << endl;
	p1 = p->homothetie2(Vecteur2D(7, 5), 2);
	d->dessiner(*p1);
	system("pause");

	cout << "Une rotation\n" << endl;
	p1 = p->rotation2(Vecteur2D(2, 2), 30);
	d->dessiner(*p1);
	system("pause");

	cout << "Une translation\n" << endl;
	p1 = p->translation2(Vecteur2D(5, 5));
	d->dessiner(*p1);
	system("pause");

	cout << "Sauvegarde du polygone dans Formes.txt qui sera cree sur le bureau\n" << endl;
	save->sauvegarde(p);
	system("pause");
	

	//////// CREATION Composee //////////
	cout << "\nVoici une Forme composee \n" << endl;
	comp->addForme(c);
	comp->addForme(s);
	comp->addForme(t);

	cout << comp << endl;
	system("pause");

	cout << "\nAire de la forme composee : " << comp->getAire() << "\n" << endl;
	system("pause");

	cout << "Maintenant un magnifique dessin:\n" << endl;
	d->dessiner(*comp);
	system("pause");

	cout << "Une homotethie\n" << endl;
	comp1 = comp->homothetie2(Vecteur2D(7, 5), 2);
	d->dessiner(*comp1);
	system("pause");

	cout << "Une rotation\n" << endl;
	comp1 = comp->rotation2(Vecteur2D(2, 2), 30);
	d->dessiner(*comp1);
	system("pause");

	cout << "Une translation\n" << endl;
	comp1 = comp->translation2(Vecteur2D(5, 5));
	d->dessiner(*comp1);
	system("pause");

	cout << "Sauvegarde de la Forme composee dans Formes.txt qui sera cree sur le bureau\n" << endl;
	save->sauvegarde(comp);
	system("pause");


	//////// Chargement //////////
	const char *fichier = "C:/Users/Ludovic GILLOT/Documents/Formes.txt";

	TraitementForme *traitement, *segment, *cercle, *polygone, *triangle, *composee;
	
	//Chaine responsabilité pour chargement
	//faire dans main permet de la creer qu une fois
	segment = new TraitementSegment(NULL);
	cercle = new TraitementCercle(segment);
	polygone = new TraitementPolygone(cercle);
	triangle = new TraitementTriangle(polygone);
	composee = new TraitementComposee(triangle);
	traitement = composee;

	// Chaine responsabilite Chargement
	Charger *charger;
	charger = new ChargerTxt(NULL);
	liste = charger->charge(fichier, traitement);

	cout << " Affichage formes fichier\n\n";

	for (int i = 0; i < liste.size(); i++)
		d->dessiner(*liste[i]);
	                                 
	system("pause");
	return EXIT_SUCCESS;
}