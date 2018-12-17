#include <stdio.h>
#include <stdlib.h>

typedef enum {minuscule, majuscule, chiffre, symbole} type; //on crée une enum pour identifier le type d'un caractère (demandé pour la fonction type_caractere)

char* chiffrement (char* chaine, int n); //applique la méthode de chiffrement César
int longueur(const char * chaine); // calcule la longueur d'une chaine de caractère
type type_caractere (char caractere); // fonction demandée qui détermine le type du caractère à chiffrer ou déchiffrer
void lecture_fichier(char nom_fichier[]); // ouvre et lit un fichier .txt (affiche sur la console le contenu du fichier)
void ecriture_fichier(int cle, char* chaine); // crée un nouveau fichier (ou écrase l'ancien) et y écrit le contenu de la chaine passée en paramètre












