#include "vetor.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>

#define CAPACIDADE 10

struct vetor
{
	int *array;
	int tamanho;
	int capacidade;
};

vetor_t *vtr_criar()
{
	vetor_t *v = malloc(sizeof(vetor_t));
	if(v)
		v->array = calloc(CAPACIDADE, sizeof(int));
	if(v->array)
	{
		v->tamanho = 0;
		v->capacidade = CAPACIDADE;
	}
	return v;
}

vetor_t *vtr_ini(int num, ...)
{
	va_list arg;
	vetor_t *v = vtr_criar();
	va_start(arg, num);
	for (int i = 0; i < num; i++)
		vtr_ins(v, va_arg(arg, int));
	va_end(arg);
	return v;
}

void vtr_impr(vetor_t *v)
{
	printf("T: %d C: %d ", v->tamanho, v->capacidade);
	for (int i = 0; i < v->capacidade - 1; i++)
		printf("[%d] -> ", v->array[i]);
	printf("[%d]\n", v->array[v->capacidade - 1]);
}

static bool vtr_mov_dir(vetor_t *v, int pos)
{
	if(pos < 0 || pos > v->capacidade)
		return false;
	for (int i = v->capacidade - 1; i > pos; i--)
		v->array[i] = v->array[i - 1];
	return true;
}

static bool vtr_mov_esq(vetor_t *v, int pos)
{
	if(pos >= 0 || pos >= v->capacidade)
		return false;
	for (int i = pos; i < v->capacidade; i++)
		v->array[i] = v->array[i + 1];
	return true;
}

static void vtr_exp(vetor_t *v)
{
	v->array = realloc(v->array, (v->capacidade * 2) * sizeof(int));
	memset(v->array + v->capacidade, 0, sizeof(int) * CAPACIDADE);
	v->capacidade *= 2;
}

void vtr_ins(vetor_t *v, int valor)
{
	if(v->tamanho == v->capacidade)
		vtr_exp(v);
	vtr_mov_dir(v, 0);
	v->array[0] = valor;
	v->tamanho++;
}

bool vtr_mod(vetor_t *v, int valor, int pos)
{
	if(pos > v->tamanho)
		return false;
	v->array[pos] = valor;
	return true;
}

int vtr_proc(vetor_t *v, int valor)
{
	for (int i = 0; i < v->tamanho; i++)
	{
		if(v->array[i] == valor)
			return i + 1;
	}
	return -1;
}

bool vtr_rm(vetor_t *v, int valor)
{
	int pos = vtr_proc(v, valor);
	if(pos == -1)
		return false;
	vtr_mov_esq(v, pos);
	v->array[v->tamanho - 1] = 0;
	v->tamanho--;
	return true;
}

void vtr_lib(vetor_t *v)
{
	free(v->array);
	free(v);
}