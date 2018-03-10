LO21 - C++
===
###### tags: `C++` `Programmation`
[TOC]

Include
===
```c++=
#include <iostream>    // utilisation cin, cout etc..
#include <string>      // Utilisation des strings
#include <cmath>       // Utilisation des fonctions mathématiques ( cos, pow, sqrt..)
#include <cstdlib>     // Utilisation des fonctions rand()%x, srand()
#include <ctime>       // Utilisation de la fonction time(0) [à mettre dans le srand]
#include <cstdio>      // Utilisation des fonctions remove(".."), rename(), fclose(), 
#include <cctype>      // utilisation des fonctions check ( isdigit(a), isalpha(a), isspace(), isupper()...
#include <fstream>     // Utilisation des fichiers	
```

Opérateurs
===
Liste opérateurs : 
+ ==	Equal to
+ !=	Not equal to
+ <	    Less than
+ \>	Greater than
+ <=	Less than or equal to
+ \>=	Greater than or equal to
+ &&      AND   (TRUE/FALSE) et   &   AND et retourne valeur
+ ||      OR	"" 		|   OR ""


Boucles
===
Boucle for : 
```c++=
for(int i=0; i<n; i++){
}
```

Boucle while : 
```c++=
while (a<10){
}
```

Boucle do..while :
```c++=
do{
}while();
```

Switch  :
```c++=
switch(x){
    case 1 :
    break;
    default : 
    break;
}
```

Pointeurs
===

### Syntaxe : 
```c++=
Type const *p; : p est un pointeur const qui pointe vers une constante de
                 type T => l'objet pointé est non modifiable
const Type *p; : pareil
Type* const p; : p est un pointeur constant vers un objet de type T => 
                 p est non modifiable
```

### Exemple :
```c++=
int a=3; a int NON constant
const int *p =&a; : interdit de modifier la valeur pointé par p (var a) 
                    même si a n'est pas constant à la base
                    On rajoute des contraintes : Autorisé !
                    *p=6; => INTERDIT
```

### Règle : 

On peut ajouter des restrictions sans problèmes, pour en supprimer, il faut utiliser des conversions de type explicites.
Un pointeur de T peut être converti (implicitement) en pointeur de void :
```c++=
int a=3;
void *p=&a;
```
Acces classe avec pointeur : Il faut pointeur->fonction(); //Le -> remplace le .

### Passage par Référence : 

T &p : lvalue de type T
lvalue : locator value : objet qui occupe emplacement mémoire au délà d'une expression unique
rvalue : exp. qui n'est pas une lvalue
Doit toujours être initialisée
Pas de vue direct sur l'implémentation "bas niveau"
Une référence après initialisation s'utilise directement comme si c'était la donnée référencée
La référence ne peut pas être modifiée pour référencer un autre objet. <=> ~=pointeur constant
 
Exemple : 
```c++=
int a=3;
int &b=a; // => Référence à une variable de type int
b=27; // modification par référence
```
const T &p=... : l'objet référence non modifiable <=> pointeur "const"
T &p : initialisation avec lvalue de type T : obligatoire
const T &p : Référence const : Conversion implicite réalisée si nécessaire, variable temporaire de type T créee si nécessaire
const int &p=32; : pas forcément d'initialisation avec lvalue : rvalue possible

### Allocation dynamique : 

En C : T *p=(T*)malloc(sizeof(T));
T *pArray=(T*)malloc(taille*sizeof(T));
T *p= new T; 
1) Alloue un espace mémoire de type T
2) Fais pointer p sur l'espace mémoire alloué

T *pArray= new T[taille];*
Libération mémoire :
delete et delete[];
delete p;
delete[] pArray;    // en C : free(pArray);

Exemple : 

```c++=
int* array = new int[42];
delete[] array;
A* obj = new A("blabla", true, 'a');
delete obj;
```

Tableau
===
:::danger
Pas de transmission de tableau par valeur en argument d'une fonction MAIS ADRESSE 1er élément (tab ou &tab[0]) = OK
Un Tableau peut être initialisé mais PAS affecté directement (tab1=tab2 interdit)
string : tab de char : char str[10] : taille_max de la string : 9+'\0' = 10 char
:::

#### Exemple : 
```c++=
int tab[]={2,3,4,5};
char str[10]="arbre" // arbre = lvalue <=> const char[6]
```

#### Utilisation fonctions : 
```c++=
void fonction(char srt[], int size);
char chaine[3]={a,b};
fonction(chaine, 3);
```

#### Tableau multidimensionnel : 
```c++=
int test[2][3] = {{3,4,6},{5,5,5}};
[nblignes][nbcolonnes]
```

Classe
===
**classe.h**
```c++=
class maClasse : public ClasseMere         //Prends tous les elements public de ClasseMere
{
 		public:
 			maClasse();                //Constructeur1
 			maCLasse(int x, int y);    //Constructeur 2
 			~maClasse();               //Deconstructeur
 			void fonction();
 			void fonctionc() const;
 		protected:			   //Mixte entre public et Private ( utilisable dans classe fille)
 		private:
 		int a;
 		const int b;
 	};
```

**classe.cpp**
```c++=
void maClasse::fonction()
    {
 	}
 
void maClasse::fonctionc() const
    {
 	}
	
maClasse::maClasse()        //Se fait dès que l'on créer un objet de cette classe dans le main.cpp
    {		            //Plusieurs Constructeurs possible.
 	}
 
maClasse::maClasse(int x, int y)
: a(x), b(y)
    {
        }
 
maClasse::~maClasse()	    // Se fait dès que l'on delete un objet de cette classe, 1 seul possible !
    {				delete automatiquement à la fin du programme.
        }
```

**main.cpp**
Pour un objet constant de cette classe : 
```c++=
const maClasse constobjet;
 ```
 **-------------**
 Friends : 
 
 Dans le .h : friend void fonction(maClasse &classe);
 Dans un .cpp : 
 ```c++=
 void fonction(maClasse &classe)
 {
 maClasse.variable=..;
 }
 *
 	This :
 ```
this est un pointeur qui pointe vers l'objet en question à un moment précis.
 
#### Héritage : 
```c++=
class A {
protected:
    int a;
/*
 a est protected donc les enfants de A auront accès directement à cet attribut.
 Si l'héritage de la première fille B de A est:
 - public: B et ses filles ont accès à a
 - protected: idem
 - private: B seulement a accès à a, les filles ne pourront plus
 */
};

class B : protected A {
public:
    void printB() { cout<<a<<endl; }
};

class C : public B {
public:
    void printC() { cout<<a<<endl; }    // accès à a car B hérite en protected de A
                                        // si B hérite en private de A, C n'a pas accès à a
};

int main(int argc, const char * argv[]) {
    return 0;
}
```
 
Structure : 
===
 ```c++=
struct maStructure
{
    int a;
    string b;
}
```

Accès : 

```c++=
 maStructure.a;
```

Passage structure en fonction : 
```c++=
void fonction(maStructure* a);
void fonction(maStructure* a){
    (maStructure->a)=5; //On remplace le . par des -> 
}
```

Surcharge de fonction : 
===

#### Principe : 

Création de deux fonctions du même nom dans lesquels on peut utiliser plusieurs types différents.

#### Syntaxe : 
```c++=
void fonction(int a);
void fonction(double a);
```

Qt
===
#### Base : 
```c++=
#include <QApplication>
#include <QWidget>		
#include <QPushButton>		//boutton
#include <QSlider>		// Slider
#include <QMessageBox>		// popup
#include <QInputDialog>		
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QGridLayout>
#include <QLineEdit>
#include <QGroupBox>
#include <QDateEdit>
#include <QTextEdit>
#include <QFormLayout>
#include <QString>




 
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);


	CODE

 
    return app.exec();
}
```



:::danger 
QT += widgets     //à Ajouter au .pro.
:::
