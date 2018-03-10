#include <iostream>
#include "function.cpp"

using namespace std;

int main(){

  //exo2-4
  bonjour();

  //exo 5
  exerciceA();

  //exo 6-7
  double x = 3.14;
  cout << x << endl;
  double y;
  cout << y << endl; // Initialise tout seul à une valeur.
  y=3.14;
  cout << y << endl;
  const double pi = 3.14;
  cout << pi << endl;
  /*pi=3;
  cout << pi << endl;   Impossible car const*/

  //exo8
  BonjourE::bonjour();

  //Exo9
  exercice_surcharge();

  //Exo10-11
  double e = 4060;
  double *pt1 = &e; // On ne peut pas affecter directement une valeur sans variable
  //double* pt2 = (double*)4036; //Non
  double* pt3=pt1; // void ne marche pas
  pt1=pt3;
  pt1=(double*)pt3;
  double d1=36;
  const double d2=36;
  double* pt4=&d1;
  const double* pt5=&d1; // objet non modifiable
  *pt4=2.1;
  //*pt5=2.1; Objet pointé est non modifiable
  //pt4=&d2; non car pt4 n'est pas const
  pt5=&d2;
  double* const pt6=&d1;
  //pt6=&d1; Pt non modifiable
  *pt6=2.78; //On peut modifier l'objet pointé
  //double* const pt6b=&d2; impossible d'affecter un objet const.
  const double* const pt7=&d1; // On ne peut ni modifier l'objet ni le pointeur
  //pt7=&d1;
  //*pt7=2.78;
  double const* pt8=&d1; // On peut modifier seulement le pointeur.
  pt8=&d2;
  pt8=&d1;
  //*pt8=3.14;  Objet non modifiable
  //double& d1= 36; // Non car pas de variable
  double d0=36;
  double& ref=d0;
  ref=4;
  const double d3=36;
  const double& d4=36; // On ne peut pas modifier l'objet
  const double& d5=d0; // pareil
  //d5=21;
  const double& d6=d3;
  //double& ref2=d6; // Non car reference un const
  int i=4;
  //double& d7=i; // non car i n'est pas un double
  const int& d8=i;
  int& d9 = i;
  d9=3;
  cout << i << endl << endl;

  //Exo12
  int a1=5,a2=10;
  cout << a1 << "  " << a2 << endl << endl;
  inverse(&a1,&a2);
  cout << a1 << "  " << a2 << endl << endl;
  inverse(a1,a2);
  cout << a1 << "  " << a2 << endl << endl;

  //Exo13
  essai e1;
  e1.n=5;
  e1.x=2.0;
  cout << "Les valeurs de la structure : " << e1.n << " et " << e1.x << endl;
  razadr(&e1);
  cout << "Les valeurs apres le razadr : " << e1.n << " et " << e1.x << endl;
  razref(e1);
  cout << "Les valeurs apres le razref : " << e1.n << " et " << e1.x << endl;

  //Exo14
  int tt = 3;
  truc3(tt);

  //Exo 15-16
  essai_init();
  essai_alloc();

  //Exo17
  personne pers1,pers2;
  const char nn[30]={'H','u','g','o'};
  finall(&pers1,pers2,nn,20);
  cout << pers2.nom;
  essai_comptes();

  return 0;
}

//Exo 18
