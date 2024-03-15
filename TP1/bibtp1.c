#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#include"bibtp1.h"
#include <windows.h>
//*********************************************************************************************************************************
//*********************************************************************************************************************************
alpha* suivant(alpha* p)
{
    return p->suivant;
}
//***************************************************************************************************************
//**************************************************************************************************************
void aff_adr(alpha* p, alpha* q)
{
(*p).suivant = q;
}
//**********************************************************************************************************
//***********************************************************************************************************
void liberer(alpha* p)
{
    free(p);
}
//*************************************************************allocation********************************************
//******************************************************************************************************************

void allouer(alpha** p){
*p=(alpha*)malloc(sizeof(alpha));//allocation memoire
}
//***********************************************detecter suf et prefix*********************************************************
//*****************************************************************************************************************************
int suffprefix(char*mot1,char*mot2)
{ char mot3[28];
mot3[0]='\0';
int i,j,k=0,cpt=0,trouve=0;
if (strlen(mot1)==strlen(mot2))
{
for (i=0,j=0;i<strlen(mot1);i++,j++)
{ if (mot1[i]==mot2[j])
{
    trouve=0;
    mot3[k]=mot1[i];
    mot3[k+1]='\0';
    k++;
    continue;
}
  else
  {
      if(trouve==0){cpt++;}
    trouve=1;
  }
}
}

else
{
  for (i=0,j=0;j<strlen(mot2)&&i<strlen(mot1);i++)
{ if (mot1[i]==mot2[j])
{
    trouve=0;
    mot3[k]=mot1[i];
    mot3[k+1]='\0';
    k++;
    j++;
    continue;}
    else{
           if(trouve==0){cpt++;}
    trouve=1;
            };
}
}

if ((strcmp(mot3,mot2)!=0)||(cpt>1))
{
    return 0;
}
else
{
    return 1;
}
}

//*****************************************************************suite de la 1ere question*************************************
//****************************************************************************************************************************
void  verfsuff(alpha* temp,tableau* t)
{
   int i,k;
   alpha* temp2;//curseur de la liste qui commence avec a ou b ect
   suffix* queue=NULL; //la liste des suffix pour les mettre en ordre c une file
   suffix* temp3=NULL; //la var qu'on va creer avec le maillon de la liste
   for (i=0;i<26;i++)
   {
      temp2=t[i].tete;
       while (temp2!=NULL)

       {  if (strcmp(temp2->mot,temp->mot)!=0)//mot n'est pas egal au mot qu'on cherche avc
        {


           k=suffprefix(temp2->mot,temp->mot);
         if (k==1)
         {
            if (temp->tetedesuf==NULL)
            { temp3=(suffix*)malloc(sizeof(suffix));
              strcpy(temp3->mot,temp2->mot);//on chaine temp3 avec temp2 mot de base de liste ex eating
              temp3->suivant=NULL;
              queue=temp3;
              temp->tetedesuf=temp3;
            }
            else //la file n'est pas vide
            {
              temp3=(suffix*)malloc(sizeof(suffix));
            strcpy(temp3->mot,temp2->mot);
              temp3->suivant=NULL;
              queue->suivant=temp3;
              queue=temp3;
            }
         }
        }
         temp2=temp2->suivant;
       }
   }
}
//****************************************************************************************************************************
//******************************* procedure pour regler un  problem dans la lecture des fichiers:*******************************
void rmvchr(char *str, char charToRemmove)
{
  int i, j;
  int len = strlen(str);
  for (i = 0; i < len; i++)
  {
    if (str[i] == charToRemmove)
    {
      for (j = i; j < len; j++)
      {
        str[j] = str[j + 1];
      }
      len--;
      i--;
    }
  }
}
//*********************************************procedure qui compare de chaines de char*****************************************
//****************************************************************************************************************************
int compare(char mot1[28],char mot2[28])
{
   int i,j=0;
   int k=strlen(mot1)-strlen(mot2);
   int cpt=0;
   if (k>2)
   {
       return 0;
   }
   else
 {


     if (k==1)
     {


     for (i=0;i<strlen(mot1);i++)
     {
         if (mot1[i]!=mot2[j])
         {
             cpt++;
            if (cpt>2)
            {
                break;
            }
         }
         else{
            j++;
         }
     }
     }
     else
     {

     for (i=0;i<strlen(mot1);i++)
     {
         if (mot1[i]!=mot2[j])
         {
             cpt++;
            if (cpt>2)//si on trouve deux char de diff rences  on sort de la boucle
            {
                break;
            }
         }
        j++;
     }
     }
     if (cpt>=2)
     {
         return 0;
     }
     else
     {
         return 1;
     }

   }
}
//************************************************************************************************************
//********************************procedure permettant de faire l'ajout graduel****************************************
void finding2(alpha* temp,tableau* t)//ajout graduelle (version serie A)
{
    int i,k,j;
    grad* milan;
    alpha* temp2;
    grad* queue=NULL;
    alpha* uv;
    char inter[28];
    temp->tetedegrad==NULL;
    strcpy(inter,temp->mot);//le mot intermediaire
    for (i=0;i<26;i++)
    {
        temp2=t[i].tete;
        while (temp2!=NULL)
        { j=strlen(temp2->mot)-strlen(inter);
          if ((j==1)&&(strcmp(temp2->mot,inter)!=0))//car on prend lettre par lettre
          {
          k=compare(temp2->mot,inter);
          if (k!=0) {
             if (temp->tetedegrad==NULL)
             {
                 milan=(grad*)malloc(sizeof(grad));//milan c le nv maillon
                 strcpy(milan->mot,temp2->mot);
                 milan->suivant=NULL;
                 temp->tetedegrad=milan;//le maillon de basede la liste on le chaine avec tete de milan
                 queue=milan;
                 uv=temp2;//prend le mot apr s ajout du caract re exemle pin et ping
                 temp->bolanna=1;// pour verifier si le mot on l'a pas mis dans une liste d'ajout graduel d ja
             }
             else
             {
                 milan=(grad*)malloc(sizeof(grad));
                 strcpy(milan->mot,temp2->mot);
                 milan->suivant=NULL;
                 queue->suivant=milan;
                 queue=milan;
                 uv->tetedegrad=milan;
                 uv->bolanna=1;//maillon pin on l'a mis avc ping donc on va pas lui creer une liste
                 uv=temp2;//prend le dernier mot au debut on a in on trouve pin uv va le prendre

             }
             strcpy(inter,temp2->mot);
             i=-1;//qd on a in puis on trouve pin on peut trouver aussi abpin donc on doit recommencer le parcours du debut qd on fait break on retorne i a -1 on ajoute 1 on est a 0
             break;
          }
          }
          temp2=temp2->suivant;
        }
    }

}
//*****************************************************procedure qui permet de verifier les mots prochees lexicalement*************
//****************************************************************************************************************************
void  finding(alpha* temp,tableau* t) // fonction de recherche de mot proche lexicalement
{
    int i;
    int j;
    int trouve=0;
    alpha* temp2;
    motppl* temp3;
    temp->tetedeppl=NULL;
    for (i=0;i<26;i++)
    { temp2=t[i].tete;

      while (temp2!=NULL)
      {
           j=strlen(temp->mot)-strlen(temp2->mot);


            if (strcmp(temp->mot,temp2->mot)!=0)
            {


            if (j>0)
            {
              trouve=compare(temp->mot,temp2->mot);
            }
            else
            {
               trouve=compare(temp2->mot,temp->mot);
            }

           if (trouve==1)
           {
               temp3=(motppl*)malloc(sizeof(motppl)); //creation du maillon
               temp3->suivant=temp->tetedeppl;
               strcpy(temp3->mot,temp2->mot);
               temp->tetedeppl=temp3;
           }
            }
            temp2=temp2->suivant;

      }

    }
}
//********************************************definir les mots qui se terminent par "ed" et "ing"***************************
//*********************************************************************************************************************
void veref (alpha* temp)
{


  char inter[4];
{ if (strlen(temp->mot)<=2)
{
    strcpy(temp->veref1,"non");
}
  else
  { inter[0]=temp->mot[strlen(temp->mot)-2];
    inter[1]=temp->mot[strlen(temp->mot)-1];
    inter[2]='\0';
    if (strcmp(inter,"ed")==0)
    {
        strcpy(temp->veref1,"oui");
    }
    else
    {
        strcpy(temp->veref1,"non");
    }

  }
}
strcpy(inter,"");
{ if (strlen(temp->mot)<=3)
{
    strcpy(temp->veref2,"non");
}
  else

  {
    inter[0]=temp->mot[strlen(temp->mot)-3];
    inter[1]=temp->mot[strlen(temp->mot)-2];
    inter[2]=temp->mot[strlen(temp->mot)-1];
    inter[3]='\0';
    if (strcmp(inter,"ing")==0)
    {
        strcpy(temp->veref2,"oui");
    }
    else
    {
        strcpy(temp->veref2,"non");
    }

  }


}
}
//*********************************************************les annagrammes***************************************
//*****************************************************************************************************************
void findanagram(alpha* temp,tableau* t)
{ int i;
  alpha* temp2;
  anagramme* ana;
  temp->tetedeana=NULL;
  temp->nbdeanna=0;
   for (i=0;i<26;i++)
   {
       temp2=t[i].tete;
       while (temp2!=NULL)
       {
           if ((strcmp(temp2->mot,temp->mot)!=0))
           {
               if (strcmp(temp2->ord,temp->ord)==0)
               {
                  ana=(anagramme*)malloc(sizeof(anagramme));
                  strcpy(ana->mot,temp2->mot);
                  ana->suivant= temp->tetedeana;
                   temp->tetedeana=ana;
                   temp->nbdeanna++;

               }
           }
           temp2=temp2->suivant;

       }
   }
}
//*****************************************************ordonner un mot********************************************
//*****************************************************************************************************
void ordre(alpha*temp)//ordonner le mot
{
int i,j;
char inter;
strcpy(temp->ord,temp->mot);
if (temp->bol!=1)
{


for (i=0;i<strlen(temp->ord);i++)
{ inter=temp->ord[i];
    for(j=i;j<strlen(temp->ord);j++)
    {
        if (toupper(temp->ord[j])<toupper(inter))
        {   inter=temp->ord[j];
            temp->ord[j]=temp->ord[i];
            temp->ord[i]=inter;
        }
    }

}


}
}
//*************************************************ordre alphabetique*******************************************************
//***************************************************************************************************************************
void ordrealpha(alpha*temp) //programme qui permet de voir si le mot est ordonn  alphabetiquement
{
  int trouve=1;
  int i;
  temp->bol=1;
  char inter=toupper(temp->mot[0]);
  for (i=1;i<strlen(temp->mot);i++)
  {
    if (inter>toupper(temp->mot[i]))
    { trouve=0;
      break;
    }
    else
    {
       inter=toupper(temp->mot[i]);
    }
  }
  temp->bol=trouve;

}
//*******************************************************proprietes du mot*********************************************
//**********************************************************************************************************************
void counterofvoyandconschar(alpha* temp,char*t){ //programme qui permet de compter le nombre de voyelle et de consonne
int i,j;
temp->nbvoy=0;
temp->nbcons=0;
temp->nbc=0;
bool trouve=false;// on utilise une variable booleenne pour voir si on a trouver une voyelle
for (j=0;j<strlen(temp->mot);j++){
trouve=false;
for (i=0;i<6;i++)
{


   if (toupper(temp->mot[j])==toupper(t[i])) // on verifie si c'est une voyelle en parcourant le tableau si on trouve que c'est une voyelle alors on incremente le nb de voyelle et on met trouve a vrai pour dire qu eon a trouver une voyelle et on quitte directement la boucle
   {  temp->nbvoy++;
      trouve=true;
      break ;
   }
}

if (trouve==false) // ici on verifie si bool est a faux si c'est le cas alors on a pas trouver de voyelle qui est egale a mot[j] alors donc c'est une consonne dans ce cas on incremente le nb de consonne par 1
{
   temp->nbcons++;
}

}
temp->nbc=temp->nbcons+temp->nbvoy;
}
//*************************************************IMPLEMENTATION*********************************************************
//*********************************************************************************************************************
void implementation(char mot[28],alpha*temp){ //l'implementation des maillons avec leur sous listes
int i,m=0;

temp->nbsyll=0;
char resu[28];//le mot sans les slashs
strcpy(temp->mot,"");//on initialise le mot a une chaine vide
temp->tetedesyll=NULL;
syllabus* temp2=NULL;
syllabus* temp3=NULL;

for (i=0;i<strlen(mot);i++){
 if ((mot[i]!='\\')&&(isalpha(mot[i])!=0)) //verifier si ce n'est pas un / isalpha pour verif si le mot est form  d'alphabets
 {
     resu[m]=mot[i];// on va mettre le charact re trouv  dans un string afin de pouvoir concat ner successivement le mot qui se trouve dans le maillon cr
     resu[m+1]='\0';
     m++;
 }
 else //on va ins rer les syllabes dans des sous listes
 {
   allouer(&temp2);
   strcpy(temp2->mot,resu);//copie la syllabe 1 dans maillon cr
   strcat(temp->mot,resu);
   strcpy(resu,"");
   m=0;
   temp2->suivant=NULL;
   temp->nbsyll++;
   if (temp->tetedesyll==NULL)
   {
      temp->tetedesyll=temp2;
      temp3=temp2;//temp3 c comme la queu
   }
   else
   {
     temp3->suivant=temp2;
     temp3=temp2;
   }
 }

}

   allouer(&temp2);   //derniere impelmentation de la sous liste //quand on arrive a la derniere syllabe
   strcpy(temp2->mot,resu);
   strcat(temp->mot,resu);
   temp2->suivant=NULL;
   temp->nbsyll++;
    if (temp->tetedesyll==NULL)
   {
      temp->tetedesyll=temp2;
   }
   else
   {
     temp3->suivant=temp2;
}
}
//------------------------------------------------------------------------------------------------------------------------------------//
void inserer(alpha* tep,tableau t[26] )
{   int i,j;
    char mot[28];
    int trouve;
    int fin=1,lol;//pour le test
    int shki;
    syllabus* temp3;
    alpha* tete=NULL;
    alpha*  queue=NULL;
    alpha* temp2=NULL;
    syllabus* brr=NULL;
    scanf("%s",mot);
    //(*nbdemot)++;
char voyelle[6]={'a','o','u','e','i','y'};//tableau de voyelle qui nous permetera de reconnaitre les voyelles et les consonnes
implementation(mot,tep);
if (tep->tetedesyll!=NULL){
       // (*nbdesyll)++;
}
counterofvoyandconschar(tep,voyelle);

ordrealpha(tep);
ordre(tep);
tep->suivant=NULL;
tep->precedent=NULL;
tep->bolanna=0;//concerne la liste de l'ajout graduel
tep->tetedesuf=NULL;
tep->tetedegrad=NULL;
strcpy(tep->flicha," ");

for (shki=0;shki<26;shki++)
{
    if (toupper(t[shki].alphabet)==toupper(tep->mot[0]))
         {
             break;
         }
}
trouve=0;//on ordonne chaque sous liste selon la taille du mot
if (t[shki].tete==NULL)
{
    t[shki].tete=tep;
    queue=tep;
}
else
{
    temp2=t[shki].tete;
    while(temp2!=NULL)
    {
      if (strlen(temp2->mot)>strlen(tep->mot))
          {
              trouve=1;
              if (temp2->precedent!=NULL)
              {
              temp2->precedent->suivant=tep;
              tep->precedent=temp2->precedent;
              tep->suivant=temp2;
              temp2->precedent=tep;

              }
              else
              {
                 t[shki].tete=tep;
                 tep->suivant=temp2;
                 tep->precedent=NULL;
                 temp2->precedent=tep;
              }
                break;
          }
          else
            { queue=temp2;
              temp2=temp2->suivant;
            }
    }
    if (trouve==0)
    {
              queue->suivant=tep;
              tep->precedent=queue;
              tep->suivant=NULL;
              queue=tep;

    }
}


}
//***********************************************************************************//
//**********************************************************************************//
void supp_mot(tableau* t,char word[28]) {
alpha* temp=NULL;
alpha* q=NULL;
int i;

for (i=0;i<26;i++)
{   q=NULL;
    temp=t[i].tete;
    while (temp!=NULL)
    {
    // Si le mot   supprimer est en t te de liste
    if (strcmp((temp)->mot, word) == 0) {

        if(q==NULL)
        {
            t[i].tete=suivant(temp);
            if( t[i].tete!=NULL)
            {

            suivant(temp)->precedent=NULL;
            }
            liberer(temp);
        }
        else
        {
           q->suivant=suivant(temp);
           if( q->suivant!=NULL)
           {
           suivant(temp)->precedent=q;
           }
           liberer(temp);

        }
        return;

    }
        else{
            q=temp;
            temp=temp->suivant;
        }


}
}
}
//**************************************************************************************//
void RechED(char* ptr)        //Fonction qui cherche le participe pass s d'un mot
{

    // Creation du participe pass  pour le compare avec les mots
    int len1 = strlen(ptr);
    bool lastcase = false;
    char mot[28];
    char mot2[28];
    strcpy(mot,ptr);
    strcpy(mot2,ptr); // Pour traiter le cas de derniere syllabe stresser donc en double la derniere consonne
    if (2 <= len1) {
        mot2[len1] = mot2[len1 - 1];
        mot2[len1 + 1] = 'e';
        mot2[len1 + 2] = 'd';
        mot2[len1 + 3] = '\0';
    }


    if (mot[len1 - 1] == 'e') { // Premier cas (close --> closed)
        mot[len1] = 'd';
        mot[len1 + 1] = '\0';

    } else if (2 <= len1 && mot[len1 - 1] == 'y' && mot[len1 - 2] != 'a' && mot[len1 - 2] != 'e' && mot[len1 - 2] != 'y' && mot[len1 - 2] != 'u' && mot[len1 - 2] != 'i' && mot[len1 - 2] != 'o' )
    { // Dexieme cas (try --> tried)
        mot[len1 - 1] = 'i';
        mot[len1] = 'e';
        mot[len1 + 1] = 'd';
        mot[len1 + 2] = '\0';

    } else if (2 <= len1 && mot[len1 - 1] == 'y' && (mot[len1 - 2] == 'a' || mot[len1 - 2] == 'e' || mot[len1 - 2] == 'y' || mot[len1 - 2] == 'u' || mot[len1 - 2] == 'i' || mot[len1 - 2] == 'o') )
    { // Troixieme cas (play --> played)
        mot[len1] = 'e';
        mot[len1 + 1] = 'd';
        mot[len1 + 2] = '\0';

    } else if (2 <= len1 && mot[len1 - 1] == 'c' && mot[len1 - 2] == 'i')
    { // Quatrieme cas (panic --> panicked)
        mot[len1] = 'k';
        mot[len1 + 1] = 'e';
        mot[len1 + 2] = 'd';
        mot[len1 + 3] = '\0';

    } else { // le dernier cas
        lastcase = true; // pour verifier les deux cas (sans doubler la derniere consone ou avec doubler)
        mot[len1] = 'e';
        mot[len1 + 1] = 'd';
        mot[len1 + 2] = '\0';
    }
     if (lastcase == false)

     {printf(" || le forme ed : %s\n",mot);
}
else{printf(" || le forme ed : %s\n",mot2);}
}
//-----------------------------------------------//-----------------------------------------------//

void RechING(char ptr[28])            //Fonction qui cherche la forme ING d'un mot
{
    int len1 = strlen(ptr);
    bool lastcase = false;
    char mot[28];
    char mot2[28];
    strcpy(mot,ptr);
    strcpy(mot2,ptr); // Pour traiter le cas de derniere syllabe stresser donc en double la derniere consonne
    if (2 <= len1) {
        mot2[len1] = mot2[len1 - 1];
        mot2[len1 + 1] = 'i';
        mot2[len1 + 2] = 'n';
        mot2[len1 + 3] = 'g';
        mot2[len1 + 4] = '\0';
    }

    if (2 <= len1 && mot[len1 - 1] == 'e' && mot[len1 - 2] == 'i')
    {   // premier cas (tie --> tying)
        mot[len1 - 2] = 'y';
        mot[len1 - 1] = 'i';
        mot[len1] = 'n';
        mot[len1 + 1] = 'g';
        mot[len1 + 2] = '\0';
    } else if (2 <= len1 && mot[len1 - 1] == 'e' && mot[len1 - 2] != 'e')
    { // (take --> taking)
        mot[len1 - 1] = 'i';
        mot[len1] = 'n';
        mot[len1 + 1] = 'g';
        mot[len1 + 2] = '\0';
    } else if (2 <= len1 && mot[len1 - 1] == 'c' && mot[len1 - 2] == 'i')
    { // (panic --> panicking)
        mot[len1] = 'k';
        mot[len1 + 1] = 'i';
        mot[len1 + 2] = 'n';
        mot[len1 + 3] = 'g';
        mot[len1 + 4] = '\0';
    } else if (2 <= len1 && mot[len1 - 1] == 'e' && mot[len1 - 2] == 'e')
    { // (see --> seeing)
        mot[len1] = 'i';
        mot[len1 + 1] = 'n';
        mot[len1 + 2] = 'g';
        mot[len1 + 3] = '\0';
    } else { // cas generale
        lastcase = true; // pour verifier les deux cas (sans doubler la derniere consone ou avec doubler)
        mot[len1] = 'i';
        mot[len1 + 1] = 'n';
        mot[len1 + 2] = 'g';
        mot[len1 + 3] = '\0';
    }
    if ( lastcase == false)
    {


   printf(" || la forme ing :%s",mot);
    }
    else
    {
         printf(" || la forme ing :%s",mot2);
    }
}
//*************************************************************************************************************************
//*************************************************************************************************************************

//*************************************************************************************************************************
//******************************************************************************************************************************
void Textecolor(int ForgC)
{
  WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

  // We use csbi for the wAttributes word.
  if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
  {
    // Mask out all but the background attribute, and add in the forgournd color
    wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
    SetConsoleTextAttribute(hStdOut, wColor);
  }
  return;
}
//************************************************************************************************************************************
//***********************************************************************************************************************************
void mise_a_jour(tableau* t,int*nbdemot,int*nbdeppl,int*nbdeana,int*trouved,int*trouving,int*nbdegrad,int*nbdesuff)
{ alpha* temp=NULL;
int shki;
    for (shki=0;shki<26;shki++)
{
     temp=t[shki].tete;
    while (temp!=NULL)
    {
temp->bolanna=0;//concerne la liste de l'ajout graduel
temp->tetedesuf=NULL;
temp->tetedegrad=NULL;
temp->tetedeppl=NULL;
temp->tetedeana=NULL;
temp=temp->suivant;
    }
}
temp=NULL;
*nbdemot=0;
*nbdeppl=0;
*nbdeana=0;
*trouved=0;
*trouving=0;
*nbdegrad=0;
*nbdesuff=0;
for (shki=0;shki<26;shki++)
{
    temp=t[shki].tete;
    while (temp!=NULL)

    {   (*nbdemot)++;
        finding(temp,t);
        if (temp->tetedeppl!=NULL)
        {
           (*nbdeppl)++;
        }
        findanagram(temp,t);
        if (temp->tetedeana!=NULL)
        {
            (*nbdeana)++;
        }
         if (!strcmp(temp->veref1,"oui"))
         {
             (*trouved)=1;
         }
         if (!strcmp(temp->veref2,"oui"))
         {
             (*trouving)=1;
         }
        verfsuff(temp,t);
         if (temp->tetedesuf!=NULL)
         {
             (*nbdesuff)++;
         }
        if (temp->bolanna!=1)
        {
          finding2(temp,t);
        }
        if (temp->tetedegrad!=NULL)
        {
            (*nbdegrad)++;
        }
        temp=temp->suivant;
}
}

}
//_____________________________________________________________________________________________________________
//______________________________________________________________________________________________________________________
void gotoxy(int x, int y)
{
  COORD c;
  c.X = x;
  c.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
//________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________

void tp_01() {
    system("cls");
    Textecolor(3);
    printf("            ,----,                 \n"); Sleep(200);
    printf("          ,/   .`|   ,-.----.      \n"); Sleep(200);
    printf("        ,`   .'  :   \\    /  \\     \n"); Sleep(200);
    printf("      ;    ;     /   |   :    \\    \n"); Sleep(200);
    printf("    .'___,/    ,'    |   |  .\\ :   \n"); Sleep(200);
    printf("    |    :     |     .   :  |: |   \n"); Sleep(200);
    printf("    ;    |.';  ;     |   |   \\ :   \n"); Sleep(200);
    printf("    `----'  |  |     |   : .   /   \n"); Sleep(200);
    printf("        '   :  ;     ;   | |`-'    \n"); Sleep(200);
    printf("        |   |  '     |   | ;       \n"); Sleep(200);
    printf("        '   :  |     :   ' |       \n"); Sleep(200);
    printf("        ;   |.'      :   : :       \n"); Sleep(200);
    printf("        '---'        |   | :       \n"); Sleep(200);
    printf("                     `---'.|       \n"); Sleep(200);
    printf("                       `---`       \n"); Sleep(200);
    printf("                                  \n"); Sleep(200);
    Textecolor(3);
    printf("            ,----..         ,---, \n"); Sleep(200);
    printf("           /   /   \\     ,`--.' | \n"); Sleep(200);
    printf("          /   .     :   /    /  : \n"); Sleep(200);
    printf("         .   /   ;.  \\ :    |.' ' \n"); Sleep(200);
    printf("        .   ;   /  ` ; `----':  | \n"); Sleep(200);
    printf("        ;   |  ; \\ ; |    '   ' ; \n"); Sleep(200);
    printf("        |   :  | ; | '    |   | | \n"); Sleep(200);
    printf("        .   |  ' ' ' :    '   : ; \n"); Sleep(200);
    printf("        '   ;  \\; /  |    |   | ' \n"); Sleep(200);
    printf("         \\   \\  ',  /     '   : | \n"); Sleep(200);
    printf("          ;   :    /      ;   |.' \n"); Sleep(200);
    printf("           \\   \\ .'       '---'   \n"); Sleep(200);
    printf("            `---`                 \n"); Sleep(200);
      printf("                                  \n"); Sleep(200);
    Textecolor(3);
  printf("                     ,--,                                                   \n");
  Sleep(200);
  printf("                  ,---.'|                                                   \n");
  Sleep(200);
  printf("   ,---,          |   | :        .--.--.          ,---,           ,---,      \n");
  Sleep(200);
  printf("  '  .' \\         :   : |       /  /    '.      .'  .' `\\       .'  .' `\\    \n");
  Sleep(200);
  printf(" /  ;    '.       |   ' :      |  :  /`. /    ,---.'     \\    ,---.'     \\   \n");
  Sleep(200);
  printf(":  :       \\      ;   ; '      ;  |  |--`     |   |  .`\\  |   |   |  .`\\  |  \n");
  Sleep(200);
  printf(":  |   /\\   \\     '   | |__    |  :  ;_       :   : |  '  |   :   : |  '  |  \n");
  Sleep(200);
  printf("|  :  ' ;.   :    |   | :.'|    \\  \\    `.    |   ' '  ;  :   |   ' '  ;  :  \n");
  Sleep(200);
  printf("|  |  ;/  \\   \\   '   :    ;     `----.   \\   '   | ;  .  |   '   | ;  .  | \n");
  Sleep(200);
  printf("'  :  | \\  \\ ,'   |   |  ./      __ \\  \\  |   |   | :  |  '   |   | :  |  ' \n");
  Sleep(200);
  printf("|  |  '  '--'     ;   : ;       /  /`--'  /   '   : | /  ;    '   : | /  ;  \n");
  Sleep(200);
  printf("|  :  :           |   ,/       '--'.     /    |   | '` ,/     |   | '` ,/   \n");
  Sleep(200);
  printf("|  | ,'           '---'          `--'---'     ;   :  .'       ;   :  .'     \n");
  Sleep(200);
  printf("`--''                                         |   ,.'         |   ,.'       \n");
  Sleep(200);
  printf("                                              '---'           '---'         \n");
   printf("                                  \n"); Sleep(1000);
}
//_____________________________________________________________________________________________________________________________________
//______________________________________________________________________________________________________________________________________
void fin_programme() {
  Textecolor(2);
  system("cls");
    printf("####### ### #     #       ######  #     #    \n");
    Sleep(200);
    printf("#        #  ##    #       #     # #     #    \n");
    Sleep(200);
    printf("#        #  # #   #       #     # #     #    \n");
    Sleep(200);
    printf("#####    #  #  #  #       #     # #     #    \n");
    Sleep(200);
    printf("#        #  #   # #       #     # #     #    \n");
    Sleep(200);
    printf("#        #  #    ##       #     # #     #    \n");
    Sleep(200);
    printf("#       ### #     #       ######   #####     \n");
    Sleep(200);
    printf("                                             \n");
    Sleep(200);
    printf("######  ######  #######  #####  ######     #    #     # #     # ####### \n");
    Sleep(200);
    printf("#     # #     # #     # #     # #     #   # #   ##   ## ##   ## #       \n");
    Sleep(200);
    printf("#     # #     # #     # #       #     #  #   #  # # # # # # # # #       \n");
    Sleep(200);
    printf("######  ######  #     # #  #### ######  #     # #  #  # #  #  # #####   \n");
    Sleep(200);
    printf("#       #   #   #     # #     # #   #   ####### #     # #     # #       \n");
    Sleep(200);
    printf("#       #    #  #     # #     # #    #  #     # #     # #     # #       \n");
    Sleep(200);
    printf("#       #     # #######  #####  #     # #     # #     # #     # ####### \n");
    Sleep(100);

}
//------------------------------------------------------------------
void esi() {
  int k;
  for (k = 0; k < 20; k++)
  {
    if (k % 2 == 0)
      Textecolor(0);
    if (k % 2 == 1)
      Textecolor(3);
    printf("        ................                 ................          ..............         \n");
    printf("    `]vB$$$$$$$$$$$$$$$$@*1;.        \"1*@$$$$$$$$$$$$$$$$Bc[`     \"______________<.       \n");
    printf("   \\$$$$$$$$$$$$$$$$$$$$$$$$B;     \"%%$$$$$$$$$$$$$$$$$$$$$$$$f.   ,+______________.       \n");
    printf("  -$$$$$$$$$$$$xtW$$$$$$$$$$$@`   .B$$$$$$$$$$$Bjf%%$$$$$$$$$$$}   ,+______________.       \n");
    printf("  *$$$$$$$$$$$j  `$$$$$$$$$$$$>   \"$$$$$$$$$$$$l  <$$$$$$$$$$$B   \"+______________.       \n");
    printf("  &$$$$$$$$$$$f  `$$$$$$$$$$$$<   ,$$$$$$$$$$$$;  >$$$$$$$$$$$$   \"_______________.       \n");
    printf("  &$$$$$$$$$$$f  '$$$$$$$$$$$$>   ,$$$$$$$$$$$$;  i$$$$$$$$$$$$   ^_________++~>I^        \n");
    printf("  W$$$$$$$$$$$t  '$$$$$$$$$$$$>   ,$$$$$$$$$$$$;  i$$$$$$$$$$$$    ''''......''''``'.     \n");
    printf("  W$$$$$$$$$$$f  '$$$$$$$$$$$$>   ,$$$$$$$$$$$$;  i$$$$$$$$$$$$     `,>+____________~!\"'  \n");
    printf("  W$$$$$$$$$$$f  '$$$$$$$$$$$$>   ,$$$$$$$$$$$$;  i$$$$$$$$$$$$        '^\"\"^``'..         \n");
    printf("  W$$$$$$$$$$$f  '$$$$$$$$$$$$>   ,$$$$$$$$$$$$;  >$$$$$$$$$$$$    '````````````          \n");
    printf("  W$$$$$$$$$$$f  '$$$$$$$$$$$$>   ,$$$$$$$$$$$$;  >$$$$$$$$$$$$    |$$$$$$$$$$$z          \n");
    printf("  W$$$$$$$$$$$f  '$$$$$$$$$$$$>   ,$$$$$$$$$$$$;  >$$$$$$$$$$$$    |$$$$$$$$$$$z          \n");
    printf("  W$$$$$$$$$$$f  '$$$$$$$$$$$$>   ,$$$$$$$$$$$$;  >$$$$$$$$$$$$.   |$$$$$$$$$$$z          \n");
    printf("  W$$$$$$$$$$$j  `$$$$$$$$$$$$>   ,$$$$$$$$$$$$;  >$$$$$$$$$$$$.   |$$$$$$$$$$$c          \n");
    printf("  &$$$$$$$$$$$j  `$$$$$$$$$$$$>   ,$$$$$$$$$$$$;  '\"\"\"\"\"\"\"\"\"\"\"\"    |$$$$$$$$$$$c          \n");
    printf("  &$$$$$$$$$$$z'.I$$$$$$$$$$$$<   ,$$$$$$$$$$$${...............    |$$$$$$$$$$$c          \n");
    printf(" &$$$$$$$$$$$$$$$$$$$$$$$$$$$<   :$$$$$$$$$$$$$$$$$$$$$$$$$$$$    |$$$$$$$$$$$c          \n");
    printf("  &$$$$$$$$$$$$$$$$$$$$$$$$$$$<   :$$$$$$$$$$$$$$$$$$$$$$$$$$$$    |$$$$$$$$$$$c          \n");
    printf("  &$$$$$$$$$$$$$$$$$$$$$$$$$$$<   :$$$$$$$$$$$$$$$$$$$$$$$$$$$$    |$$$$$$$$$$$c          \n");
    printf("  &$$$$$$$$$$$W;::::::::::::::'   .\"\"\"\"\"\"\"\"\"\"\"\"\"\"j$$$$$$$$$$$$    |$$$$$$$$$$$c          \n");
    printf("  &$$$$$$$$$$$j   ............     ............   <$$$$$$$$$$$$    ($$$$$$$$$$$c          \n");
    printf("  &$$$$$$$$$$$j  `$$$$$$$$$$$$<   :$$$$$$$$$$$$;  >$$$$$$$$$$$$    ($$$$$$$$$$$c          \n");
    printf("  &$$$$$$$$$$$j  `$$$$$$$$$$$$<   :$$$$$$$$$$$$I  >$$$$$$$$$$$$    ($$$$$$$$$$$c          \n");
    printf("  &$$$$$$$$$$$j  `$$$$$$$$$$$$<   :$$$$$$$$$$$$;  >$$$$$$$$$$$$    ($$$$$$$$$$$c          \n");
    printf("  &$$$$$$$$$$$f  `$$$$$$$$$$$$<   :$$$$$$$$$$$$;  >$$$$$$$$$$$$    ($$$$$$$$$$$c          \n");
    printf("  &$$$$$$$$$$$j  `$$$$$$$$$$$$<   :$$$$$$$$$$$$;  >$$$$$$$$$$$$    ($$$$$$$$$$$c          \n");
    printf("  &$$$$$$$$$$$j  `$$$$$$$$$$$$<   :$$$$$$$$$$$$;  >$$$$$$$$$$$$    ($$$$$$$$$$$c          \n");
    printf("  W$$$$$$$$$$$j  `$$$$$$$$$$$$<   ,$$$$$$$$$$$$;  <$$$$$$$$$$$$    ($$$$$$$$$$$c          \n");
    printf("  r$$$$$$$$$$$u. ,$$$$$$$$$$$$:   `$$$$$$$$$$$$-  ]$$$$$$$$$$$n    |$$$$$$$$$$$c          \n");
    printf("  `B$$$$$$$$$$$@B$$$$$$$$$$$$r     \\$$$$$$$$$$$$@@$$$$$$$$$$$%%`    |$$$$$$$$$$$z          \n");
    printf("   'n$$$$$$$$$$$$$$$$$$$$$$B[.      iM$$$$$$$$$$$$$$$$$$$$$$v`     |$$$$$$$$$$$z          \n");
    printf("     ':_)\\fffffffffffff|]I^           `I?(tfffffffffffft(-;`       <fffffffffff{         \n");
    Sleep(300);
    system("cls");
  }

//************************************************************************************************************//
}
void Barrechargement()
{
  system("cls");
  Textecolor(3);
  gotoxy(10, 15);
  printf("\t\t\t|||                                                 10%%  ");
  Sleep(300);
  system(";cls");
  gotoxy(10, 15);
  printf("\t\t\t|||||                                               20%%  ");
  Sleep(300);
  system(";cls");
  gotoxy(10, 15);
  printf("\t\t\t||||||||||||||||                                    30%%  ");
  Sleep(300);
  system(";cls");
  gotoxy(10, 15);
  printf("\t\t\t|||||||||||||||||||||||||                           40%%  ");
  Sleep(300);
  system(";cls");
  gotoxy(10, 15);
  printf("\t\t\t|||||||||||||||||||||||||||||||                     60%%  ");
  Sleep(300);
  system(";cls");
  gotoxy(10, 15);
  printf("\t\t\t||||||||||||||||||||||||||||||||||||||||            80%%  ");
  Sleep(300);
  system(";cls");
  gotoxy(10, 15);
  printf("\t\t\t||||||||||||||||||||||||||||||||||||||||||||||||||  100%% ");
  system("cls");
}
void Barrechargement2()
{
  system("cls");
  Textecolor(3);
  gotoxy(10, 15);
  printf("\t\t\t|||                                                 10%%  ");
  Sleep(300);
  system(";cls");
  gotoxy(10, 15);
  printf("\t\t\t||||||||||||||||||||||||||||||                     50%%  ");
  Sleep(300);
  system(";cls");
  gotoxy(10, 15);
  printf("\t\t\t||||||||||||||||||||||||||||||||||||||||||||||||||  100%% ");
  system("cls");
}
