#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define CAPACIDADE 10

struct pilha
{
	int dados[CAPACIDADE];
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
	printf("T:%d ", plh->tamanho);
	for (int i = 0; i < CAPACIDADE - 1; i++)
		printf("[%d] -> ", plh->dados[i]);
	printf("[%d]\n", plh->dados[CAPACIDADE - 1]);
}

static bool plh_cheia(pilha_t *plh)
{
	return plh->tamanho == CAPACIDADE;
}

bool plh_push(pilha_t *plh, int vlr)
{
	if(!plh || plh_cheia(plh))
		return false;
	plh->dados[plh->tamanho] = vlr;
	plh->tamanho++;
	return true;
}

static bool plh_vazia(pilha_t *plh)
{
	return plh->tamanho == 0;
}

bool plh_pop(pilha_t *plh, int *dest)
{
	if(!plh || plh_vazia(plh))
		return false;
	plh->tamanho--;
	*dest = plh->dados[plh->tamanho];
	plh->dados[plh->tamanho] = 0;
	return true;
}

void plh_topo(pilha_t *plh, int *dest)
{
	if(!plh)
		return;
	*dest = plh->dados[plh->tamanho -1];
}

void plh_lib(pilha_t *plh)
{
	free(plh);
}