#include "arvores/arb.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
	int V[] = {1, 2, 3, 4, 5};
	ARB arb;
	ARB_construtor(&arb, sizeof(int));
	for (int i = 0; i < 5; i++)
	{
		ArvoreBi_inserir(&arb.super, &V[i]);
		ArvoreBi_imprimir(&arb.super);
	}
	// ArvoreBi_destruir(&arb.super);
	return EXIT_SUCCESS;
}