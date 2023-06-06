#include "fila.h"
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

int main(void)
{
	int esperado[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	fila_t *fla = fla_criar();
	
	//Para tamanho < 10 inserção tem de dar certo
	for (int i = 0; i < 10; i++)
		assert(fla_enqueue(fla, i) == true);
	
	//Topo da fila tem de ser igual a esperado[0]
	int vlr1;
	fla_topo(fla, &vlr1);
	assert(vlr1 == esperado[0]);

	//Os valores tem de ser recebidos na ordem correta para obedecer FIFO
	for (int i = 0; i < 10; i++)
	{
		int vlr;
		assert(fla_dequeue(fla, &vlr) == true);
		assert(vlr == esperado[i]);
	}

	//Lista vazia, remoção deve falhar
	int vlr2;
	assert(fla_dequeue(fla, &vlr2) == false);
	fla_lib(fla);
	return 0;
}