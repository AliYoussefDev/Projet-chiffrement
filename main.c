#include "chiffrement.h"

void test()
{
	char* c = "aBcD01";
	char* c_chiffre = chiffrement(c,2);
	for( int i = 0; i< longueur(c); i++)
	{
		printf("%c",c_chiffre[i]);
	}
	//lecture_fichier("81_fiches_Cuisine_Georges_Perec.txt");
	//ecriture_fichier(3,"abcd");
	//int cle = 3;
	//char* cle_en_char= "";
	//sprintf(cle_en_char,"%d",cle);
}

int main(int argc, char **argv)
{
	test();
	return 0;
}
