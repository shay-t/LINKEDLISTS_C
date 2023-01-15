#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include<stdlib.h>
#include<string.h>
#include"personne.h"
#include"liste.h"
 //insertion de la bibliotheque locale crée
//declartaion du menu
int menu(){
	int code;
	printf("\n GESTION D'UNE LISTE DE PERSONNES :\n");
	printf("0-Fin\n");
	printf("1-Insertion en tete de liste\n");
	printf("2-Insertion en fin de liste\n");
	printf("3-Retrait en tete de liste\n");
	printf("4-Retrait en fin de liste\n");
	printf("5-Retrait d'un element a partir de son nom\n");
	printf("6-Parcours de la liste\n");
	printf("7-Recherche dun element a partir de son nom \n");
	printf("8-Destruction de la liste\n");
	printf("\n");
	printf("\n-----------------------------------------\n");
	printf("Veuillez effectuer un choix\n");
    scanf("%d",&code);
	return code;
}
int main() {
	LISTE* li=creation(0, ecrirepersonne, comparerpersonne);;//pointeur de type LISTE creation avec initialisation
	bool sortir=0;
	while(!sortir){
		switch(menu()){
		    case 0:{
		             sortir=1;
            }break;
		    case 1:{
		        ch15 n1,n2;//declaration de deux tableaux de chaine
		        printf("veuillez saisir le nom de la personne\n");
		        scanf("%s",n1);
		        printf("veuillez saisir le prenom de la personne\n");
		        scanf("%s",n2);
		        PERSONNE* nouveau = creerpersonne(n1,n2);
		        insererteteliste(li,nouveau);//OBJET=nouveau- void*=PERSONNE
		        printf("les coordonnes de cette personne ont bien ete insere en tete de liste \n");
                printf("\n-----------------------------------------\n");
		    }break;
		    case 2:{
                ch15 n1,n2;//declaration de deux tableaux de chaine
		        printf("veuillez saisir le nom de la personne\n");
		        scanf("%s",n1);
		        printf("veuillez saisir le prenom de la personne\n");
		        scanf("%s",n2);
		        PERSONNE* nouveau = creerpersonne(n1,n2);
		        insererenfinliste(li,nouveau);//OBJET=nouveau- void*=PERSONNE
		        printf("les coordonnés de cette personne ont bien ete insere en fin de liste \n");
                printf("\n-----------------------------------------\n");
		    }break;
		    case 3:{
		        PERSONNE* extrait = (PERSONNE*) extraireentetedeliste(li);
				if(extrait != NULL){
					printf("la personne portant le nom %s et le prenom %s a ete supprimer de la tete de liste\n",
                           extrait->nom, extrait->prenom);
				}else{
					printf("la liste est vide");
				}
              printf("\n-----------------------------------------\n");
		    }break;
		    case 4:{
                PERSONNE* extrait = (PERSONNE*) extraireenfindeliste(li);
				if(extrait != NULL){
					printf("la personne portant le nom %s et le prenom %s  a ete supprimer de la  finde liste\n", extrait->nom,
                           extrait->prenom);
				}else{
					printf("la liste est vide");
				}
                printf("\n-----------------------------------------\n");
             }break;
		    case 5:{
		        ch15 n1;
		        printf("Veuillez saisir le nom de la personne que vous souhaitez saisir");
		        scanf("%s",n1);
		        PERSONNE* recherche = creerpersonne(n1, " ");
				PERSONNE* p = (PERSONNE*) chercherunobjet(li, recherche);
				if(extrairobjet(li, p)){
					printf("Element  dont le nom est %s et le prenom est %s extrait de la liste\n", p->nom, p->prenom);
				}
                printf("\n-----------------------------------------\n");
		     }break;
		    case 6:{
		        if(listevide(li)){
                    printf("la liste est vide\n");
		        }
		        else{
                listerliste(li);
                printf("\n-----------------------------------------\n");}
		    }break;
		    case 7:{
                ch15 n1;
		        printf("Veuillez saisir le nom de la personne que vous souhaitez saisir");
		        scanf("%s",n1);
		        PERSONNE* recherche = creerpersonne(n1, " ");
				PERSONNE* p = (PERSONNE*) chercherunobjet(li, recherche);
				if(p != NULL){
					printf("Cette personne : %s ,%s \n", p->nom, p->prenom);
				}else{
					printf("%s inconnue dans la liste\n", n1);
				}
                printf("\n-----------------------------------------\n");
		    }break;
		    case 8:{
                detruireliste(li);
                printf("la liste a ete detruite");
                printf("\n----------------------------------------\n");
		    }break;
		}
	}
}
