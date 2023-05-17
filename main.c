#include "Vetor/vetor.c"
#include <stdio.h>

int main(void)
{
	tvetor *v = vetor_iniciarr(9, 1, 2, 3, 4, 5, 6, 7, 8, 9);
	v->imp(v);
	v->mod(v, 200, 4);
	v->imp(v);
	v->lib(v);
	return 0;
}