#include "Pilha/plhlst.c"
#include <stdio.h>

int main(void)
{
	pilha_t *pilha = plh_ini(3, 1, 2, 3);
	plh_push(pilha, -5);
	plh_push(pilha, -2);
	plh_impr(pilha);
	int n;
	plh_pop(pilha, &n);
	plh_impr(pilha);
	plh_lib(pilha);
	return 0;
}