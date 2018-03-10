#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

using namespace std;

//Exo5
void exerciceA();

//Exo8
namespace BonjourC{
  void bonjour();
}
namespace BonjourE{
  void bonjour();
}

//Exo 9
inline int fct(int x){
  cout<<"1:"<< x <<endl;
  return 0;
}
inline int fct(float y){
   cout<<"2:" << y << endl;
   return 0;
 }
inline int fct(int x, float y){
   cout<<"3:" << x << y << endl;
   return 0;
 }
inline float fct(float x, int y){
   cout<<"4:"<< x << y << endl;
   return 3.14;
 }
void exercice_surcharge();

//Exo12
void inverse(int *a, int *b);
void inverse(int& a, int& b);

//Exo13
struct essai{
  int n;
  float x;
};
void razadr(essai* e);
void razref(essai& e);

//Exo 14
void truc1(int& x){
  cout<< x << endl;
  x++;
  cout<< x << endl;
}
void truc2(int& x){
x++;
truc1(x);
x++;
}
void truc3(int& x){
truc2(x);
const double& y=x;
const double& z=x;
const double& u=y;
const double& t=y-3;
cout << t;
}

//Exo 15
struct point {
int x;
int y;
int z;
};
namespace troisD{
  void init(point* pt, int _x, int _y, int _z);
}
namespace deuxD{
  void init(point* pt, int _x, int _y);
}
namespace unD{
  void init(point* pt, int _x);
}
namespace vnul{
  void init(point* pt);
}
void essai_init();

//Exo 16
void essai_alloc();

//Exo17
struct personne {
char nom[30];
unsigned int age;
};
void razz(personne* p);
void affiche_struct(const personne* p);
void affiche_tab(personne* tabpers,int nb);
void init_struct(personne* p, const char* n, int age);
void copy_struct(personne& p, const personne& source);
void copy_tab(personne* tab, const personne* tabsource, int nsource);
void finall(personne* p1, const personne& source,  const char* n, int age);

//Exo 18
struct compte {
  char id[20];
  int solde;
};
void essai_comptes();
int& operation(compte* c,const char* nm);








#endif
