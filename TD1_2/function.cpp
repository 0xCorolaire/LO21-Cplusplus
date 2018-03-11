#include "function.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>

using namespace std;

//Exo 2-4
void bonjour() {
cout<<"Entrez votre prenom :";
string prenom;
cin>>prenom;
cout<<"Bonjour "<<prenom<< endl;
}

//Exo5
void exerciceA(){
  const int PI = 3.14159;
  int r;
  double p,s;
  cout << "donnez le rayon entier d’un cercle:" << endl;
  cin >> r;
  p = 2*PI*r;
  s = PI*r*r;
  cout << "le cercle de rayon " << r << " a un perimetre de " << p << " et une surface de " << s << endl;
}

//Exo8
void BonjourC::bonjour(){
  cout << "Nichao"<< endl;
}
void BonjourE::bonjour(){
  cout << "Hello" << endl;
}

//Exo 9
 void exercice_surcharge(){
     int i=3,j=15;
     float x=3.14159,y=1.414;
     char c='A';
     double z=3.14159265;
     fct(i); //appel 1
     fct(x); //appel 2
     fct(i,y); //appel 3
     fct(x,j); //appel 4
     fct(c); //appel 5
     fct(i,(float)j); //appel 6
     fct((float)i,c); //appel 7
     fct(i,z); //appel 8
     fct((float)z,z); //appel 9
 }

//Exo12
void inverse(int *a, int *b){
  int change;
  change = *a;
  *a = *b;
  *b = change;
}
void inverse(int& a, int&b){
  int change;
  change = a;
  a = b;
  b = change;
}

//Exo 13
void razadr(essai* e){
  (*e).n=0;
  (e->x)=0;
}
void razref(essai& e){
  e.n = 5;
  e.x = 3.2;
}

//Exo 15
void troisD::init(point* pt, int _x, int _y, int _z){
  pt->x=_x;
  pt->y=_y;
  pt->z=_z;
}
void deuxD::init(point* pt, int _x, int _y) {
  pt->x=_x;
  pt->y=_y;
  pt->z=0;
}
void unD::init(point* pt, int _x) {
  pt->x=_x;
  pt->y=0;
  pt->z=0;
}
void vnul::init(point* pt) {
  pt->x=0;
  pt->y=0;
  pt->z=0;
}

void essai_init(){
  point punto;
  vnul::init(&punto);
  unD::init(&punto,1);
  deuxD::init(&punto,1,2);
  troisD::init(&punto,1,2,3);
}

//Exo16
void essai_alloc(){
  int* pt_int;
  double* pt_double;
  pt_int= new int;
  pt_double=new double[100];
  cout << pt_int << endl << pt_double << endl;
  delete pt_int;
  delete[] pt_double;
  cout << pt_int << endl << pt_double << endl;
}

//Exo 17
void razz(personne* p){
  (*p).nom[0] = '\0';
  (*p).age=0;
}
void affiche_struct(const personne* p){
  cout << "La personne s'appelle " << (*p).nom << " et a " << p->age << " ans" << endl;
}
void affiche_tab(personne* tabpers, int nb){
  for(int i=0; i<nb; i++){
    affiche_struct(&tabpers[i]);
  }
}
void init_struct(personne* p,const char* n, int age)
{
    (*p).age=age;
    int i=0;
    while (n[i]!='\0' && i<30){
      p->nom[i]=n[i];
      i++;
    }
    (*p).nom[i]='\0';
}
void copy_struct(personne& p, const personne& source)
{
    p=source;
}
void copy_tab(personne* tab, const personne* tabsource, int nsource)
{
     for(int i=0;i<nsource;i++)
     {
     copy_struct(tab[i], tabsource[i]);
     }
}
void finall(personne* p1, const personne& source,  const char* n, int age){
  razz(p1);
  init_struct(p1,n,age);
  personne& p1b = *p1;
  //copy_struct(p1b,source);
  //personne* p2b = const& source;
  affiche_struct(p1);
}

//Exo 18
void essai_comptes(){
  compte tab[4]={ {"courant", 0},{"codevi", 1500 },
  {"epargne", 200 }, { "cel", 300 } };

  operation(tab,"courant")=100;
  operation(tab,"codevi")+=100;
  operation(tab,"cel")-=50;

  for(int i=0; i<4; i++) cout<<tab[i].id<<" : "<<tab[i].solde<<"\n";
}

int& operation(compte* c,const char* id){
  for(int i=0; i<4; i++) {
      if(strcmp(c[i].id, id)==0) return c[i].solde;
  }
  throw "Error";

}
