#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include<stdlib.h>
#include<string.h>
#include"liste.h"
 //insertion de la bibliotheque locale crée
//declartaion du menu
int menu1(){
	int code;
	printf("\n GESTION D'UNE LISTE D'ENTIERS :\n");
	printf("0-Fin\n");
	printf("1-Creer une liste et Initialiser une liste\n");
	printf("2-Retourner le nombre d'objets\n");
	printf("3-Verifier si la liste est vide\n");
	printf("4-Inserer en tete de liste\n");
	printf("5-Inserer en fin de liste\n");
	printf("6-Retrait en tete de liste\n");
	printf("7-Retrait en fin de liste\n");
	printf("8-Retrait d'un objet a partir de sa referance\n");
	printf("9-Afficher les objets de la liste\n");
	printf("10-Chercher un objet\n");
	printf("11-Destruction de la liste\n");
	printf("\n");
	printf("\n-----------------------------------------\n");
	printf("Veuillez effectuer un choix\n");
    scanf("%d",&code);
	return code;
}
//programme principale
int main() {
	LISTE* li;//pointeur sur la liste
	int sortir=0;
	while(!sortir){
		switch(menu1()){
		    case 0:{
		          sortir=1;
		    }break;
			case 1:{
				li=creation(0,afficherChar,comparerChar);//creation liste de type non ordonée
                                                        //rmq :Quand on cree on initialise
				printf("votre liste a bien ete cree");
				printf("\n-----------------------------------------\n");
			}break;
			case 2:{
				printf("Le nombre des elements dans votre liste est:%d \n",nbELEMENT(li));
				printf("\n-----------------------------------------\n");
				}
				break;
			case 3:{
				if(listevide(li)){
					printf("la liste est vide");
				}
				else{
					printf("votre liste n'est pas vide");
				}
				printf("\n-----------------------------------------\n");
			}break;
			case 4:{
				int* n = (int*)malloc(sizeof(int));
				printf("veuillez saisir le nombre que vous souhaitez inserer en tete de liste:\n");
				scanf("%d",n);
				insererteteliste(li,n);
				printf("\n votre nombre ' %d ' a bien ete insere\n",*n);
				printf("\n-----------------------------------------\n");
			}break;
			case 5:{
				int*n=(int*)malloc(sizeof(int));
				printf("veuillez saisir le nombre que vous souhaitez inserer:\n");
				scanf("%d",n);
				insererenfinliste(li,n);
                printf("\n votre nombre ' %d ' a bien ete insere\n",*n);
                printf("\n-----------------------------------------\n");
			}break;
			case 6:{
			    if(!listevide(li)){
                    printf("le premier element de votre liste %d sera supprime\n",*(int*)extraireentetedeliste(li));
                    printf("cet element '%d' a ete supprimer",*(int*)extraireentetedeliste(li));
                    }
                else{
                    printf("votre liste est deja vide");
                }
                printf("\n-----------------------------------------\n");
			}break;
			case 7:{
			    if(!listevide(li)){
                    printf("le dernier element de votre liste %d sera supprime\n",*(int*)extraireenfindeliste(li));
                    printf("cet element  ete supprimer");
                    }
                else{
                    printf("votre liste est deja vide");
                }
                printf("\n-----------------------------------------\n");
			}break;
			case 8:{
			    if(!listevide(li)){
                    int* n;
                    int* d = (int*)malloc(sizeof(int));
                    printf("veuillez saisir element que vous souhaitez supprimer\n");
                    scanf("%d",d); //IL faut chercher si il existe puis le supprimer
                    n=(int*)chercherunobjet(li,d);
                    if(extrairobjet(li,n)){
                        printf("votre element %d est bien supprime",*n);
                    }
                    else{
                        printf("votre element %d n'existe pas dans la liste",*n);
                    }
                }
			    else{
                    printf("votre liste est vide");
			    }
			    printf("\n-----------------------------------------\n");
			}break;
			case 9:{ //bhala liste vide toujours vrai
                /*if(!listevide){//cad liste vide faux
                    printf("les elements de votre liste sont:\n");
                    listerliste(li);
			    }
			    else {
                   printf("votre liste est vide aucun element a lister");
			    }*/
			    listerliste(li);
			    printf("\n-----------------------------------------\n");
			}break;
			case 10:{
			    int*n=(int*)malloc(sizeof(int));
                printf("veuillez saisir element que vous souhaitez chercher");
                scanf("%d",n);
                if(!listevide(li)){
                    if(chercherunobjet(li,n) != NULL){
                    printf("lelement que vous chercher %d est bien trouve dans la liste",*(int*)chercherunobjet(li,n));
                    }
                    else{
                    printf("cet element nexiste pas dans la liste");
                    }
                }
                else{
                    printf("votre liste est deja vide");
                }
                printf("\n-----------------------------------------\n");
			}break;
			case 11:{
			     detruireliste(li);
			     printf("votre liste est detruite");

			     printf("\n-----------------------------------------\n");
			}break;
		}
	}

return 0;}
