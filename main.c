#include "arvores/abb.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
	int V[] = {7, 5, 3, 1, 11, 9, 13, 12};
	ABB abb;
	ABB_construtor(&abb, sizeof(int));
	for (int i = 0; i < 8; i++)
	{
		ArvoreBi_inserir(&abb.super, &V[i]);
	}
	ArvoreBi_imprimir(&abb.super);
	int num;
	sscanf(argv[1],"%d", &num);
	ArvoreBi_remover(&abb.super, &num);
	ArvoreBi_imprimir(&abb.super);
	ArvoreBi_destruir(&abb.super);
	return EXIT_SUCCESS;
}