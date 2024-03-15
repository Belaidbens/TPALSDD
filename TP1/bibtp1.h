#ifndef bibtp1
#define bibtp1

typedef struct elemm{
char mot[10];
struct elemm* suivant;
}syllabus;

typedef struct suff{
char mot[28];
struct suff* suivant;
}suffix;

typedef struct ajoutgrad{
char mot[28];
struct ajoutgrad* suivant;
}grad;

typedef struct motppl{
char mot[28];
struct motppl* suivant;
}motppl;

typedef struct anagramme{
char mot[28];
struct anagramme* suivant;
}anagramme;
typedef struct elems{
char flicha[4];
char mot[28];//le plus long mot est de 28 lettres ce qui explique le choix de la taille
int nbc;
int nbcons;
int nbvoy;
int nbsyll;
int bol;
char ord[28];
char veref1[4];
char veref2[4];
syllabus* tetedesyll;
anagramme* tetedeana;
motppl* tetedeppl;
suffix* tetedesuf;
grad* tetedegrad;
int bolanna;
int nbdeanna;
struct elems* suivant;
struct elems* precedent;

}alpha;

typedef struct tab{
char alphabet ;
alpha* tete;
}tableau;

int suffprefix(char*mot1,char*mot2);
void  verfsuff(alpha* temp,tableau* t);
void rmvchr(char *str, char charToRemmove);
int compare(char mot1[28],char mot2[28]);
void finding2(alpha* temp,tableau* t);
void  finding(alpha* temp,tableau* t);
void veref (alpha *temp);
void findanagram(alpha* temp,tableau* t);
void ordre(alpha*temp);
void ordrealpha(alpha*temp);
void counterofvoyandconschar(alpha* temp,char*t);
void allouer(alpha** p);
void implementation(char mot[28],alpha*temp);
void supp_mot(tableau* t,char word[28]);
void inserer(alpha* tep,tableau t[26]);
void RechED(char* ptr);
void RechING(char* ptr) ;
void veref (alpha* temp);
void Textecolor(int ForgC);
void mise_a_jour(tableau* t,int*nbdemot,int*nbdeppl,int*nbdeana,int*trouved,int*trouving,int*nbdegrad,int*nbdesuff);
void gotoxy(int x, int y);
void tp_01();
void Barrechargement();
void esi();
void fin_programme();
void Barrechargement2();

#endif // bibtp1
