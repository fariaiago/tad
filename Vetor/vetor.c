#include "vetor.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

struct vetor
{
	int *array;
	int tamanho;
	int capacidade;
	void (*imp)(tvetor *);
	void (*ins)(tvetor *, int);
	bool (*mod)(tvetor *, int, int);
	bool (*rm)(tvetor *, int);
	void (*lib)(tvetor *);
};

#define CAPACIDADE 10

tvetor *vetor_iniciar()
{
	tvetor *v = malloc(sizeof(tvetor));
	v->array = calloc(CAPACIDADE, sizeof(int));
	v->tamanho = 0;
	v->capacidade = CAPACIDADE;
	v->imp = vetor_imprimir;
	v->ins = vetor_inserir;
	v->mod = vetor_modificar;
	v->rm = vetor_remover;
	v->lib = vetor_liberar;
	return v;
}

tvetor *vetor_iniciarr(int num, ...)
{
	va_list arg;
	tvetor *v = vetor_iniciar();
	va_start(arg, num);
	for (int i = 0; i < num; i++)
		v->ins(v, va_arg(arg, int));
	va_end(arg);
	return v;
}

void vetor_imprimir(tvetor *v)
{
	printf("T:%d C:%d ", v->tamanho, v->capacidade);
	for (int i = 0; i < v->capacidade - 1; i++)
	{
		printf("[%d] -> ", v->array[i]);
	}
	printf("[%d]\n", v->array[v->capacidade - 1]);
}

void vetor_inserir(tvetor *v, int valor)
{
	if(v->tamanho == v->capacidade)
	{
		v->array = realloc(v->array, (v->capacidade + CAPACIDADE) * sizeof(int));
		memset(v->array + v->capacidade, 0, sizeof(int) * CAPACIDADE);
		v->capacidade += CAPACIDADE;
	}
	v->array[v->tamanho] = valor;
	v->tamanho++;
}

bool vetor_modificar(tvetor *v, int valor, int pos)
{
	if(pos > v->tamanho)
		return false;
	v->array[pos] = valor;
	return true;
}

int vetor_achar(tvetor *v, int valor)
{
	for (int i = 0; i < v->tamanho; i++)
	{
		if(v->array[i] == valor)
			return i + 1;
	}
	return -1;
}

bool vetor_mover(tvetor *v, int pos, int offset)
{
	if(pos + offset > v->capacidade)
		return false;
	for (int i = pos; i < v->tamanho; i++)
	{
		v->array[i + offset] = v->array[i];
	}
	return true;
}

bool vetor_remover(tvetor *v, int valor)
{
	int pos = vetor_achar(v, valor);
	if(pos == -1)
		return false;
	vetor_mover(v, pos, -1);
	v->array[v->tamanho - 1] = 0;
	v->tamanho--;
	return true;
}

void vetor_liberar(tvetor *v)
{
	free(v->array);
	free(v);
}