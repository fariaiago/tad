#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct no
{
	int info;
	struct no *prox;
} no_t;


struct pilha
{
	no_t *topo;
	int tamanho;
};

pilha_t *plh_criar(void)
{
	pilha_t *plh = calloc(1, sizeof(pilha_t));
	return plh;
}

pilha_t *plh_ini(int num, ...)
{
	va_list arg;
	pilha_t *plh = plh_criar();
	va_start(arg, num);
	for (int i = 0; i < num; i++)
		plh_push(plh, va_arg(arg, int));
	va_end(arg);
	return plh;
}

void plh_impr(pilha_t *plh)
{
	if(!plh)
	{
		printf("Pilha nula\n");
		return;
	}
	no_t *tmp = plh->topo;
	printf("T: %p ", plh->topo);
	while (tmp)
	{
		printf("[%d; %p]%s", tmp->info, tmp->prox, tmp->prox ? " -> " : "");
		tmp = tmp->prox;
	}
	puts("");
}

/**
 * Inicializa um nó
 * @return O nó criado
*/
static no_t *no_ini(int vlr)
{
	no_t *n = malloc(sizeof(no_t));
	if(!n)
	{
		n->info = vlr;
		n->prox = NULL;
	}
	return n;
}

bool plh_push(pilha_t *plh, int vlr)
{
	if(!plh)
		return false;
	no_t *n = no_ini(vlr);
	n->info = vlr;
	if(!n)
		return false;
	if(plh->topo)
		n->prox = plh->topo;
	plh->topo = n;
	return true;
}

bool plh_pop(pilha_t *plh, int *dest)
{
	if(!plh)
		return false;
	if(!plh->topo)
		return false;
	else
	{
		no_t *tmp = plh->topo;
		*dest = tmp->info;
		plh->topo = tmp->prox;
		free(tmp);
	}
	return true;
}

void plh_topo(pilha_t *plh, int *dest)
{
	if(!plh)
		return;
	if(!plh->topo)
		return;
	else
		*dest = plh->topo->info;
}

void plh_lib(pilha_t *plh)
{
	no_t *tmp = plh->topo, *tmp2;
	while (tmp)
	{
		tmp2 = tmp;
		tmp = tmp->prox;
		free(tmp2);
	}
	free(plh);
}