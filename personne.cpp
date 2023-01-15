#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include<stdlib.h>
#include<string.h>
#include"personne.h"
//fonction creation dune personne
PERSONNE* creerpersonne(char* nom,char* prenom){
    PERSONNE* p=(PERSONNE*)malloc(sizeof(PERSONNE));//allouer la memoire pour P de type pointeur sur PERSONNE
    strcpy(p->nom,nom);//permet de copier une chaine de caractere en une autre
    strcpy(p->prenom,prenom);
    return p;
}
//chaine
char* ecrirepersonne(objet* OBJET){
   PERSONNE* p = (PERSONNE*) OBJET;
   char* output=(char*)malloc(sizeof(char));
   snprintf(output,sizeof(PERSONNE),"%s %s\n",p->prenom,p->nom);
   return output;
}
int comparerpersonne(objet* OBJET1,objet* OBJET2){
    PERSONNE* p1 =(PERSONNE*)(OBJET1);
    PERSONNE* p2 =(PERSONNE*)(OBJET2);
    return strcmp((char*)p1->nom,(char*)p2->nom);
}
