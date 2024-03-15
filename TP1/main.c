#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include"bibtp1.h"

typedef struct elements{
char message[130];
char flicha[4];
}message;


int main(){
     Barrechargement();
    esi();
   tp_01();
    system("cls");
      Textecolor(1);
  printf("\t\t\t\t%ccole nationale sup%rieur d'informatique \n",130,130);
 Textecolor(5);
    printf("\t\t\t  .----------------.  .----------------.  .----------------.\n");
    printf("\t\t\t | .--------------. || .--------------. || .--------------. |\n");
    printf("\t\t\t | |  _________   | || |    _______   | || |     _____    | |\n");
    printf("\t\t\t | | |_   ___  |  | || |   /  ___  |  | || |    |_   _|   | |\n");
    printf("\t\t\t | |   | |_  \\_|  | || |  |  (__ \\_|  | || |      | |     | |\n");
    printf("\t\t\t | |   |  _|  _   | || |   \'.___`-.   | || |      | |     | |\n");
    printf("\t\t\t | |  _| |___/ |  | || |  |`\\____) |  | || |     _| |_    | |\n");
    printf("\t\t\t | | |_________|  | || |  |_______.\'  | || |    |_____|   | |\n");
    printf("\t\t\t | |              | || |              | || |              | |\n");
    printf("\t\t\t | \'--------------\' || \'--------------\' || \'--------------\' |\n");
    printf("\t\t\t  \'----------------\'  \'----------------\'  \'----------------\'\n");
     Sleep(200);
  Textecolor(10);
  printf("\t\t\t\tCPI - 1%cre Ann%ce - Ann%ce Universitaire 2022/2023 \n", 138, 130, 130);
  printf("\t\t\t ___________________________________________________________________\n");
  printf("\t\t\t|                                                                   |\n");
  printf("\t\t\t| REALISE PAR : BENSAADA MOHAND OUBELAID                            |\n");
  printf("\t\t\t|                              &                                    |\n");
  printf("\t\t\t|                          ABERKANE MOHAMED RAYANE                  |\n");
  printf("\t\t\t|                                                                   |\n");
  printf("\t\t\t|                                                                   |\n");
  printf("\t\t\t|         \tSECTION : A           GROUPE: 03                    |\n");
  printf("\t\t\t|                                                                   |\n");
  printf("\t\t\t|         \tTP1 : Les listes lin%caires chain%ces                 |\n", 130, 130);
  printf("\t\t\t|                                                                   |\n");
  printf("\t\t\t|           \t      < MANIPULATION DES LISTES >                   |\n");
  printf("\t\t\t|                                                                   |\n");
  printf("\t\t\t|                                                                   |\n");
  printf("\t\t\t| ENCADRE PAR :Mme ARTABAZ SALIHA                                   |\n");
  printf("\t\t\t|___________________________________________________________________|\n\n\n");
  Textecolor(20);
  printf("\t\t\t _______________________________________________________________________________________    \n");
      printf("\t\t\t| Remarque !! cliquez sur la touche 'ENTRER' pour acceder au menu                       |\n");
      printf("\t\t\t| pour choisir votre choix cliquez dans le clavier sur le numero correspondant          |\n");
      printf("\t\t\t| vous pouvez egalement switcher entre les choix avec les fleches 'haut,bat' du clavier |\n");
      printf("\t\t\t|_______________________________________________________________________________________|\n");

    int i,c,j,nbdemot=0,nbdeana=0,trouved=0,trouving=0,nbdeppl=0,nbdesuff=0,nbdegrad=0,nbdesyll=0;
    int fin=1,ok=1,lol;//pour le test
    int shki;
    char mot[28];
    syllabus* temp3;
    alpha* tete=NULL;
    alpha* temp=NULL;
    alpha*  queue=NULL;
    alpha* temp2=NULL;
    syllabus* brr=NULL;
    tableau t[26];
    int trouve;


for (shki=0;shki<26;shki++)
{
    t[shki].alphabet=65+shki;
    t[shki].tete=NULL;
}
char voyelle[6]={'a','o','u','e','i','y'};//tableau de voyelle qui nous permetera de reconnaitre les voyelles et les consonnes
FILE* file = fopen("words.txt", "r");
ici:
 ok=fgets(mot,28,file);
if (ok)
{
    rmvchr(mot,'\n');
}

while (ok) {
nbdemot++;
allouer(&temp);//on fait rentrer le mot avec les slash

implementation(mot,temp);
if (temp->tetedesyll!=NULL)
{
    nbdesyll++;
}
counterofvoyandconschar(temp,voyelle);
ordrealpha(temp);
ordre(temp);
temp->suivant=NULL;
temp->precedent=NULL;
temp->bolanna=0;//concerne la liste de l'ajout graduel
temp->tetedesuf=NULL;
temp->tetedegrad=NULL;
strcpy(temp->flicha," ");
for (shki=0;shki<26;shki++)
{
    if (toupper(t[shki].alphabet)==toupper(temp->mot[0]))
         {
             break;
         }
}
trouve=0;//on ordonne chaque sous liste selon la taille du mot
if (t[shki].tete==NULL)
{
    t[shki].tete=temp;
    queue=temp;
}
else
{
    temp2=t[shki].tete;
    while(temp2!=NULL)
    {
      if (strlen(temp2->mot)>strlen(temp->mot))
          {
              trouve=1;
              if (temp2->precedent!=NULL)
              {
              temp2->precedent->suivant=temp;
              temp->precedent=temp2->precedent;
              temp->suivant=temp2;
              temp2->precedent=temp;

              }
              else
              {
                 t[shki].tete=temp;
                 temp->suivant=temp2;
                 temp->precedent=NULL;
                 temp2->precedent=temp;
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
              queue->suivant=temp;
              temp->precedent=queue;
              temp->suivant=NULL;
              queue=temp;

    }
}
goto ici;
 }
int choix=0;
anagramme* ana;
motppl* ppl;
suffix* suf;
grad* napoli;
for (shki=0;shki<26;shki++) //verification de la forme ed et ing et les annagrammes et recherche des mot les proches lexicalement
{
    temp=t[shki].tete;
    while (temp!=NULL)
    {   finding(temp,t);
        if (temp->tetedeppl!=NULL)
        {
           nbdeppl++;
        }
        findanagram(temp,t);
        if (temp->tetedeana!=NULL)
        {
            nbdeana++;
        }
        veref(temp);
         if (!strcmp(temp->veref1,"oui"))
         {
             trouved=1;
         }
         if (!strcmp(temp->veref2,"oui"))
         {
             trouving=1;
         }
        verfsuff(temp,t);
         if (temp->tetedesuf!=NULL)
         {
             nbdesuff++;
         }
        if (temp->bolanna!=1)
        {
         finding2(temp,t);
        }
        if (temp->tetedegrad!=NULL)
        {
            nbdegrad++;
        }
        temp=temp->suivant;
}
}

reset: c=getch();

if (c!=13){
    goto reset;
}
int choix2=9;
system("cls");
message tab[15];
strcpy(tab[0].message,"1:AFFICHAGE DE LA LISTE GLOBAL AVEC LES PROPRIETES DE CES MOTS                                        ");
strcpy(tab[0].flicha,"->");
strcpy(tab[1].message,"2:DES MOTS FORMES A PARTIR D'AUTRES MOTS EN AJOUTANT UNE SOUS SEQUENCE DE LETTRE                      ");
strcpy(tab[1].flicha,"");
strcpy(tab[2].message,"3:DISTINGUER DE CES MOTS : LE PARTICIPE PASSE AVEC ED ET LA FORME ING                                 ");
strcpy(tab[2].flicha,"");
strcpy(tab[3].message,"4:SEQUENCE DE MOTS FORMES PAR L'AJOUT GRADUEL D'UNE LETTRE A LA FOIS A GAUCHE, A DROITE OU AU MILIEU  ");
strcpy(tab[3].flicha,"");
strcpy(tab[4].message,"5:LES MOTS LES PLUS PROCHES LEXICALEMENT (UNE SEULE LETTRE DIFFERENTE)                                ");
strcpy(tab[4].flicha,"");
strcpy(tab[5].message,"6:Les anagrammes                                                                                      ");
strcpy(tab[5].flicha,"");
strcpy(tab[8].message,"9:QUITTER                                                                                             ");
strcpy(tab[8].flicha,"");
strcpy(tab[6].message,"7:statistiques globales et de chaque mot                                                              ");
strcpy(tab[6].flicha,"");
strcpy(tab[7].message,"8:supprimer ou ajouter un mot                                                                         ");
strcpy(tab[7].flicha,"");
strcpy(tab[9].message,"supprimer un mot");
strcpy(tab[9].flicha,"->");
strcpy(tab[10].message,"ajouter un mot");
strcpy(tab[10].flicha,"");


la:

   Textecolor(3);

   printf("\n\n\n");
printf("                                             MENU                                             \n");
printf("                                            ------                                            \n");
printf("*************************************************************************************************************\n");
printf("*                                                                                                           *\n");
for (i=0;i<9;i++)
{
  printf("*%s %s",tab[i].flicha,tab[i].message);
  printf("    *\n");
  Sleep(0.00000000000000000000000001);
}
printf("*                                                                                                           *\n");
printf("*************************************************************************************************************\n");
c=getch();
  switch(c){
  case 72:  strcpy(tab[choix].flicha,"");
      if (choix==0)
      {
          choix=8;
      }
      else choix--;

      strcpy(tab[choix].flicha,"->");
      break;
  case 80: strcpy(tab[choix].flicha,"");
      choix=(choix+1)%9;
      strcpy(tab[choix].flicha,"->");

      break;
  case 49:
  case 50:
  case 51:
  case 52:
  case 53:
  case 54:
  case 55:
  case 56:
  case 57:c=c-49;
          goto end;
  case 13: c=choix;
  goto end;

      default: break;
  }
  system("cls");
goto la;
end:
Barrechargement2();
Textecolor(6);
switch(c){
 case 0:

     for (shki=0;shki<26;shki++) {
      temp=t[shki].tete;
      while (temp!=NULL){
        Textecolor(2);
           printf("_______________________________________________________________________________________________________________________\n");
        printf("_______________________________________________________________________________________________________________________\n");
        Textecolor(6);
        printf("\nle mot est %s",temp->mot);
        printf("\nce mot est compose de %d caracteres",temp->nbc);
        printf("\nle nombre de voyelles de ce mot est %d || le nombre de consonnes est %d || le nombre de syllabes est %d",temp->nbvoy,temp->nbcons,temp->nbsyll);
        printf("\nle mot est-il ordonne? %d",temp->bol);
        printf("\nle mot etant donne ordonne : %s\n",temp->ord);
        brr=temp->tetedesyll;
        if (brr!=NULL)
        { printf("les syllabes qui forment ce mot ' %s ' sont: \n",temp->mot);
        while(brr!=NULL)
        {
            printf("- %s\n",brr->mot);
            brr=brr->suivant;
        }
        }
         temp=temp->suivant;
      }
      }

        goto la;

 break;//1er case

    case 1 : system("cls");
        for (shki=0;shki<26;shki++) {
           temp=t[shki].tete;
              while (temp!=NULL){

               suf=temp->tetedesuf;
               if (suf!=NULL)
               { Textecolor(2);
           printf("_______________________________________________________________________________________________________________________\n");
        printf("_______________________________________________________________________________________________________________________\n");
          Textecolor(6);
                printf("les mots formes a partir de la meme sous sequence de '%s' sont : \n",temp->mot);
                }
                   while (suf!=NULL)
                   {
                      printf("%s\n",suf->mot);
                      suf=suf->suivant;
                    }
              temp=temp->suivant;
               }
        }



        goto la;

    case 2: system("cls");

        for(shki=0;shki<26;shki++){
            temp=t[shki].tete;
         while(temp!=NULL){
                 veref(temp);
          Textecolor(2);
           printf("_______________________________________________________________________________________________________________________\n");
        printf("_______________________________________________________________________________________________________________________\n");
        Textecolor(7);
         printf("le mot '%s' est-il sous la forme 'ed'?:%s\n",temp->mot,temp->veref1);
            printf("le mot '%s' est-il sous la forme 'ing'?:%s\n",temp->mot,temp->veref2);
        Textecolor(6);
        printf("le mot est : %s",temp->mot);
        RechING(temp->mot);
        RechED(temp->mot);
            temp=temp->suivant;
         }
        }



        goto la;
    case 3: system("cls");

        for (shki=0;shki<26;shki++){
            temp=t[shki].tete;
            while(temp!=NULL){
               napoli=temp->tetedegrad;
                  if (napoli!=NULL)
                  {
                   Textecolor(2);
           printf("_______________________________________________________________________________________________________________________\n");
        printf("_______________________________________________________________________________________________________________________\n");
          Textecolor(6);
                  printf("les mots qui sont formes a partir de lajout graduel de lettres a partir du mot %s sont : \n",temp->mot);
                  }
                          while (napoli!=NULL)
                         {
                          printf("--%s \n",napoli->mot);
                          napoli=napoli->suivant;
                          }
              temp=temp->suivant;
            }
        }

        goto la;

         case 4: system("cls");
            for(shki=0;shki<26;shki++){
            temp=t[shki].tete;
         while(temp!=NULL){
           ppl=temp->tetedeppl;
               if (ppl!=NULL){
                   Textecolor(2);
           printf("_______________________________________________________________________________________________________________________\n");
        printf("_______________________________________________________________________________________________________________________\n");
          Textecolor(6);
                   printf("les mots les plus proches  lexicalement de ce mot '%s' sont: \n",temp->mot);
                     while(ppl!=NULL)
                     {
                      printf("-- %s\n",ppl->mot);
                      ppl=ppl->suivant;
                     }
                }
          temp=temp->suivant;
        }
        }


        goto la;
    case 5 :system("cls");

        for (shki=0;shki<26;shki++){
           temp=t[shki].tete;
              while (temp!=NULL) {
                ana=temp->tetedeana;
                   if (ana!=NULL)

                   {  Textecolor(2);
           printf("_______________________________________________________________________________________________________________________\n");
        printf("_______________________________________________________________________________________________________________________\n");
          Textecolor(6);
                       printf("les anagrammes de ce mot '%s' sont : \n",temp->mot);
                    while(ana!=NULL)
                       {
                        printf("- %s\n",ana->mot);
                        ana=ana->suivant;
                        }
                   }
                temp=temp->suivant;
              }

        }

        goto la;
    case 6:       system("cls");
     printf("les statistiques de la structure sont : \n");
     printf("le nombre de mot : %d \n",nbdemot);
     printf("le nombre de liste de mot de la forme 'ed' : %d \n",trouved);
     printf("le nombre de liste de mot de la forme 'ing' : %d \n",trouving);
     printf("le nombre de liste qui constitue les annagrammes : %d \n",nbdeana);
     printf("le nombre de liste de mot forme a partir d'un suffix prefix ou l'ajout d'une sous sequence au milieu : %d \n",nbdesuff);
     printf("le nombre de liste forme a partir de mot plus proche lexicalement : %d \n",nbdeppl);
     printf("le nombre de liste forme a partir de l'ajout graduelle : %d \n",nbdegrad);
     printf("le nombre de liste forme a partir des syllabes est : %d",nbdesyll);


        goto la;
    case 7:
   again:system("cls");
    printf("*************************************************************************************************************\n");
     for (i=9;i<11;i++)
     {
         printf("%s %s\n",tab[i].flicha,tab[i].message);

     }
      printf("*************************************************************************************************************\n");
    c=getch();
    switch(c){
  case 72:  strcpy(tab[choix2].flicha,"");
      if (choix2==9)
      {
          choix2=10;
      }
      else choix2--;

      strcpy(tab[choix2].flicha,"->");
      break;
  case 80: strcpy(tab[choix2].flicha,"");
       if (choix2==10)
      {
          choix2=9;
      }
      else choix2++;
      strcpy(tab[choix2].flicha,"->");

      break;
  case 13:
      c=choix2-8;
      goto suite;
  case 49:
  case 50:
      c=c-48;
      goto suite;
    }
goto again;
suite:
if (c==2)
{
    system("cls");
printf("veuillez entrer le mot que vous voulez ajouter\n");
allouer(&temp);//on fait rentrer le mot avec les slash
inserer( temp ,t);
    printf("votre mot a bien %ct%c ajout%c dans la structure\n",130,130,130);
}
else{  printf("veuillez donner le mot que vous voulez supprimer :\n");
        scanf("%s",mot);
         supp_mot(t,mot);
         }
mise_a_jour(t,&nbdemot,&nbdeppl,&nbdeana,&trouved,&trouving,&nbdegrad,&nbdesuff);
        goto la;
    case 8:
    goto endofpro;
    default : printf("votre choix est incorrect");

       goto la;

        }
endofpro:
fin_programme();
return 0;
}
