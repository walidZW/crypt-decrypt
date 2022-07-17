#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conio.c"
#include "affichage.c"

/*******************************************LES PROTOTYPES DES FONCTIONS********************************************/
void crypt_fich(char *nomfich1,char cle[],char *nomfich2);// la fonction du cryptqage
void decrypt_fich(char *nomfich1,char cle[],char *nomfich2);// la fonction de décryptage
int fich_egaux(char *fich1,char *fich2);//la fonction qui teste l'égalité entre de fichier
void creer_fich(char *fich);//la fonction de creation d'un fichier
/*****************************************LE PROGRAMME PRINCIPALE********************************************/

int main()
{
 system("mode con lines=53 cols=116");
 debut();
 interface1 :
 textbackground(BLACK);
 clrscr();
 textcolor(LIGHTGREEN);
 printf("***********************************VEUILLEZ ENTRER VOTRE CHOIX*******************************************\n");
 printf("*********************************************************************************************************\n\n\n\n");
  printf("1=====>crypter un fichier\n\n");
  printf("2=====>decrypter un fichier\n\n");
  printf("3=====>crypter et decrypter a la fois\n\n");
  printf("4=====>tester l'egalité entre deux fichiers\n\n");
  printf("5=====>quitter le progamme\n\n");

int choix;
int choix2;
char *nom1[20];
char *nom2[20];
char *nom3[20];
char *cle1[20];
scanf("%d",&choix);

if(choix==1){
    bonchoix:
    printf("veuillez choisir:\n");
    printf("1-UN FICHIER DEJA EXISTANT\n");
    printf("2-UN NOUVEAU FICHIER");
    scanf("%d",&choix2);
    if(choix2!=1 && choix2!=2){printf("ENTRER UN BON CHOIX!!\n");
    goto bonchoix;}
    if(choix2==2){printf("REMARQUE: VOUS DEVEZ CREER VOTRE FICHIER D'ABORD('*' POUR INDIQUER LA FIN D'ECRITURE)\n");
        printf("donner le nom du fichier que tu veux le crypter\n");
        scanf("%s",nom1);
        creer_fich(nom1);
        goto suite1;
    }
    printf("donner le nom du fichier que tu veux le crypter\n");
    scanf("%s",nom1);
    suite1:
    printf("donner le nom du fichier contenant le resultat du cryptage\n");
    scanf("%s",nom2);
    printf("donner la cle du cryptage\n");
    scanf("%s",cle1);
    crypt_fich(nom1,cle1,nom2);
    printf("VOTRE FICHIER A ETE CRYPTEE\n");
    goto interface1;
    }

    if(choix==2){
    printf("donner le nom de fichier a decrypter\n");
    scanf("%s",nom1);
    printf("donner le nom du fichier qui contient resultat\n");
    scanf("%s",nom2);
    printf("donner la clé\n");
    scanf("%s",cle1);
    decrypt_fich(nom1,cle1,nom2);
    printf("VOTRE FICHIER A ETE BIEN DECRYPTE\n");
    goto interface1;
    }

   if(choix==3){
    printf("donner le nom de fichier que tu veux le crypter\n");
    scanf("%s",nom1);
    printf("donner le nom de fichier qui contient le resultat du cryptage\n");
    scanf("%s",nom2);
    printf("donner le nom de fichier qui contient le resultat de decryptage\n");
    scanf("%s",nom3);
    printf("donner la clé\n");
    scanf("%s",cle1);
    crypt_fich(nom1,cle1,nom2);
    decrypt_fich(nom2,cle1,nom3);
    goto interface1;
    }

   int egalite,k;
   if(choix==4){
    printf("donner le nom du premier fichier\n");
    scanf("%s",nom1);
    printf("donner le nom du deuxieme fichier\n");
    scanf("%s",nom2);
    //egalite=fich_egaux(nom1,nom2);

    if(fich_egaux(nom1,nom2)==1){printf("les contenus des deux fichiers sont identiques\n");}
    else{printf("les contenus sont différents\n");};
    goto interface1;}

   if(choix==5){goto fin;}
   if(choix!=1 && choix!=2 && choix!=3 && choix!=4 && choix!=5){printf("VOTRE CHOIX EST INCORRECTE\n");
   goto interface1;}
   fin:
       fin();
}
/******************************************LES FONCTIONS **********************************/
void crypt_fich(char *nomfich1,char cle[],char *nomfich2)
{
    FILE *F = fopen(nomfich1,"r");
    FILE *H = fopen(nomfich2,"w+");
    char c ;
    char w;
    if (F!=NULL)
    {
       int i = 0 ;
       while ((c = fgetc(F))!=EOF)
       {

         c = c +cle[i%strlen(cle)] +((int)(abs(sin(i))*90)%70);
         fputc(c,H);
         i++ ;

        }

       }
       fclose(F);
       fclose(H);
}
/*------------------------------------------------------------------*/
void decrypt_fich(char *nomfich1,char cle[],char *nomfich2)
{
FILE *F = fopen(nomfich1,"r");
FILE *H = fopen(nomfich2,"w+");
    char c ;
    if (F!=NULL)
    {
       int i = 0 ;
       while ((c = fgetc(F))!=EOF)
       {


         c = c -cle[i % strlen(cle)] -((int)(abs(sin(i))*90)%70);

         fputc(c,H);
          i++ ;

       }

       }
       fclose(F);
       fclose(H);
}
/*---------------------------------------------------------*/
int fich_egaux(char *nomfich1,char *nomfich2){

int egaux=1;
char c1,c2;
FILE *fich1=fopen(nomfich1,"r+");
FILE *fich2=fopen(nomfich2,"r+");
if(fich1==NULL || fich2==NULL ){
    printf("erreur l'un des deux fichiers n'existe pas");
    }
while((c1=fgetc(fich1))!=EOF || (c2=fgetc(fich2))!=EOF){
    /*c1=fgetc(fich1);
    c2=fgetc(fich2);*/
    if(c1!=c2){return 0;

    }
    }
if(egaux==1){return 1;}

fclose(fich1);
fclose(fich2);

}
/*-----------------------------------------------------------*/
void creer_fich(char *nomfich){
FILE *fichier=fopen(nomfich,"w+");
char c;
while(1){
scanf("%c",c);
if(c=="*") break;
fputc(c,fichier);

}
printf("C'EST BON VOTRE FICHIER A ETE BIEN CREE\n");
fclose(fichier);
}
