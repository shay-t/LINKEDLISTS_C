typedef char ch15[16]; //renommer un tableau de chaine de caractére de taille 16 en "ch15"
typedef void objet;
//contient la declaration de la structure personne
typedef struct{
ch15 nom;
ch15 prenom;
}PERSONNE;
//fonction qui permet de creer PERSONNE
PERSONNE* creerpersonne(char* nom,char* prenom);

char* ecrirepersonne(objet* OBJET);
int comparerpersonne(objet* OBJET1,objet* OBJET2);
