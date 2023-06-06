#include "fila.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define CAPACIDADE 10

struct fila
{
	int dados[CAPACIDADE];
	int tamanho;
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
		fla_enqueue(fla, va_arg(arg, int));
	va_end(arg);
	return fla;
}

void fla_impr(fila_t *fla)
{
	printf("T:%d ", fla->tamanho);
	for (int i = 0; i < CAPACIDADE - 1; i++)
		printf("[%d] <- ", fla->dados[i]);
	printf("[%d]\n", fla->dados[CAPACIDADE - 1]);
}

static bool fla_cheia(fila_t *fla)
{
	return fla->tamanho == CAPACIDADE;
}

bool fla_enqueue(fila_t *fla, int vlr)
{
	if(!fla || fla_cheia(fla))
		return false;
	fla->dados[fla->tamanho] = vlr;
	fla->tamanho++;
	return true;
}

static bool fla_vazia(fila_t *fla)
{
	return fla->tamanho == 0;
}

static void fla_mov(fila_t *fla, int tamanho)
{
	for(int i = 0; i < tamanho - 1; i++)
		fla->dados[i] = fla->dados[i + 1];
}

bool fla_dequeue(fila_t *fla, int *dest)
{
	if(!fla || fla_vazia(fla))
		return false;
	*dest = fla->dados[0];
	fla_mov(fla, fla->tamanho);
	fla->tamanho--;
	fla->dados[fla->tamanho] = 0;
	return true;
}

void fla_topo(fila_t *fla, int *dest)
{
	if(!fla)
		return;
	*dest = fla->dados[0];
}

void fla_lib(fila_t *fla)
{
	free(fla);
}