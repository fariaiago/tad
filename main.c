#include "ListaEncadeada/lstini.c"
#include <stdio.h>

int main(void)
{
	lista_t *lista = lst_ini(9, 1, 2, 3, 4, 5, 6, 7, 8, 9);
	lst_impr(lista);
	lst_mod(lista, 5, 25);
	lst_rm(lista, 2);
	lst_impr(lista);
	lst_lib(lista);
	return 0;
}