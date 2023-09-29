#include "arvores/avl.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
	int V[] = {4, 6, 2};
	AVL avl;
	AVL_construtor(&avl, sizeof(int));
	for (int i = 0; i < 3; i++)
	{
		ArvoreBi_inserir(&avl.super, &V[i]);
		ArvoreBi_imprimir(&avl.super);
	}
	ArvoreBi_destruir(&avl.super);
	return EXIT_SUCCESS;
}