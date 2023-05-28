#include "fila.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct no
{
	int info;
	struct no *prox;
} no_t;


struct fila
{
	no_t *topo;
	no_t *fundo;
};

fila_t *fla_criar(void)
{
	fila_t *fla = calloc(1, sizeof(fila_t));
	return fla;
}

fila_t *fla_ini(int num, ...)
{
	va_list arg;
	fila_t *fla = fla_criar();
	va_start(arg, num);
	for (int i = 0; i < num; i++)
		fla_push(fla, va_arg(arg, int));
	va_end(arg);
	return fla;
}

void fla_impr(fila_t *fla)
{
	if(!fla)
	{
		printf("Fila nula\n");
		return;
	}
	no_t *tmp = fla->topo;
	printf("T: %p F: %p ", fla->topo, fla->fundo);
	while (tmp)
	{
		printf("[%d; %p]%s", tmp->info, tmp->prox, tmp->prox ? " <- " : "");
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

bool fla_push(fila_t *fla, int vlr)
{
	if(!fla)
		return false;
	no_t *n = no_ini(vlr);
	n->info = vlr;
	if(!n)
		return false;
	if(!fla->topo)
	{
		fla->topo = n;
		fla->fundo = n;
	}
	else
	{
		fla->fundo->prox = n;
		fla->fundo = n;
	}
	return true;
}

bool fla_pop(fila_t *fla, int *dest)
{
	if(!fla)
		return false;
	if(!fla->topo || fla_vazia(fla))
		return false;
	else
	{
		no_t *tmp = fla->topo;
		*dest = tmp->info;
		fla->topo = tmp->prox;
		free(tmp);
	}
	return true;
}

void fla_topo(fila_t *fla, int *dest)
{
	if(!fla)
		return;
	if(!fla->topo)
		return;
	else
		*dest = fla->topo->info;
}

void fla_lib(fila_t *fla)
{
	no_t *tmp = fla->topo, *tmp2;
	while (tmp)
	{
		tmp2 = tmp;
		tmp = tmp->prox;
		free(tmp2);
	}
	free(fla);
}