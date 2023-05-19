#include "Vetor/vetor.h"
#include <stdio.h>

int main(void)
{
	tvetor *v = vtr_ini(vtr_ins_fim, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9);
	vtr_impr(v);
	vtr_lib(v);
	return 0;
}