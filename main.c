#include "arvores/abb.h"
#include <stdio.h>

int main(void)
{
	int V[] = {7, 5, 3, 1, 11, 9, 13};
	ABB abb;
	ABB_construtor(&abb, sizeof(int));
	for (int i = 0; i < 7; i++)
	{
		ArvoreBi_inserir(&abb.super, &V[i]);
	}
	ArvoreBi_imprimir(&abb.super);
	return 0;
}