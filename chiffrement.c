#include "chiffrement.h"

char* chiffrement (char* chaine, int n)
{
	int longueur_ = longueur(chaine);
	char* resultat = (char*)(malloc(sizeof(char)*longueur_));
	int cle = (3*n)%26;
	int i = 0;
	type t;
	printf("\nLe texte chiffré est : ");
	
	while (chaine[i] != '\0')
	{
		t = type_caractere(chaine[i]);
		if (t == chiffre)
		{
			if (cle>9) //cle dépasse le nombre total de chiffres
				cle = cle%10;
				
			if(chaine[i]+cle>57)
				resultat[i] = (chaine[i]+cle-10); //57 correspond à '9', 48 à '0'. On revient à 0 si le numero du code est trop grand et qu'il ne correspond pas à un chiffre.
			else //lorsque le code additioné à la clé correspond toujours à un chiffre
				resultat[i] = (char)(chaine[i]+cle);
		}
		
		if (t == majuscule)
		{			
			if(chaine[i]+cle>90)
				resultat[i] = (chaine[i]+cle-26); 
			else
				resultat[i] = (char)(chaine[i]+cle);
		}
		
		if (t == minuscule)
		{
			if(chaine[i]+cle>122)
				resultat[i] = (chaine[i]+cle-26); 
			else
				resultat[i] = (char)(chaine[i]+cle);
		}
		i++;
	}
	return resultat;
}

int longueur(const char * chaine)
{
	int i =0;
	while (chaine[i] != '\0')
	{
		i++;
	}
	return i;
}

void afficher_chaine(char* chaine)
{
	int longueur = longueur(chaine)
	for( int i = 0; i< longueur(c); i++)
	{
		printf("%c",c_chiffre[i]);
	}
}

type type_caractere (char caractere) 
{
	type t;
	if (caractere >= 48 && caractere <= 57) // dans la table ASCII le code du caractère '0' est 48, '1' -> 49, ... '9' -> 57. est-ce que le programme convertit directement le cahr en int ?
	{
		t = chiffre;
	}
	else if (caractere >= 65 && caractere <= 90) // 'A' -> 65 et 'Z' -> 90
	{
		t = majuscule;
	}
	else if (caractere >= 97 && caractere <= 122) // 'a' -> 97 et 'z' -> 122
	{
		t = minuscule;
	}
	else if ((caractere >=33 && caractere<=47) || (caractere >=58 && caractere <=64) || (caractere >= 91 && caractere <= 96) || (caractere >= 123 && caractere <= 126))
	{
		t = symbole;
	}
	return t;
}

void lecture_fichier(char nom_fichier[])
{
	FILE* fichier = fopen(nom_fichier,"r"); // ouverture en lecture du fichier
	if( fichier != NULL )
	{
		char c = fgetc(fichier); // lecture du 1er caractère du fichier
		
		while( c != EOF ) // tant que le caractère lu n'est pas à la fin de fichier (End Of File)
		{
			printf("%c", c); // affichage
			c = fgetc(fichier); // lecture du caractère suivant
		}
		
		fclose(fichier); // fermeture du fichier
	}
	else
	{
		printf("Problème lors de l'ouverture du fichier %s. Assurez-vous que le fichier soit dans le dossier debug du projet.\n", nom_fichier);
	}
}

void ecriture_fichier(int cle, char* chaine)
{
	FILE* fichier = fopen("nouveau texte.txt","w"); // ouverture du fichier en ecriture
	
	char* cle_en_char;
	sprintf(cle_en_char,"Cle : %d",cle);
	
	if( fichier != NULL )
	{
		char c;
		if (cle == 3)
			c = '3';
		fputc(c,fichier); // ecriture de la clé en tant que premier caractère
		fputc('\n',fichier); 
		fputs(chaine,fichier); // ecriture du texte chiffré dans le fichier
		
		//faire appel à la fonction lecture
		
		fclose(fichier); // fermeture du fichier
	}
}

