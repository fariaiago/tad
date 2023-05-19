#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>

#define CAPACIDADE 10

typedef struct vetor
{
	int *array;
	int tamanho;
	int capacidade;
} tvetor;

/**
 * Cria um vetor vazio
 * @return O vetor que foi criado
*/
tvetor *vtr_criar()
{
	tvetor *v = malloc(sizeof(tvetor));
	v->array = calloc(CAPACIDADE, sizeof(int));
	v->tamanho = 0;
	v->capacidade = CAPACIDADE;
	return v;
}

/**
 * Inicializa um vetor com N items
 * @param ins Ponteiro de função com método de inserção
 * @param num Número de items
 * @param ... Items a serem inseridos
 * @return O vetor que foi criado
*/
tvetor *vtr_ini(void (*ins)(tvetor *, int), int num, ...)
{
	va_list arg;
	tvetor *v = vtr_criar();
	va_start(arg, num);
	for (int i = 0; i < num; i++)
		ins(v, va_arg(arg, int));
	va_end(arg);
	return v;
}

/**
 * Imprime o vetor
 * @param v Vetor que será impresso
*/
void vtr_impr(tvetor *v)
{
	printf("T:%d C:%d ", v->tamanho, v->capacidade);
	for (int i = 0; i < v->capacidade - 1; i++)
		printf("[%d] -> ", v->array[i]);
	printf("[%d]\n", v->array[v->capacidade - 1]);
}

/**
 * Desloca uma casa a direita todos os items de vetor->capacidade - 1 até Y
 * @param v Vetor que será movido
 * @param pos Posição de fim
 * @return Se a operação é valida
*/
bool vtr_mov_dir(tvetor *v, int pos)
{
	if(pos < 0 || pos > v->capacidade)
		return false;
	for (int i = v->capacidade - 1; i > pos; i--)
		v->array[i] = v->array[i - 1];
	return true;
}

/**
 * Desloca uma casa a esquerda todos os items a partir de Y até vetor->capacidade - 1
 * @param v Vetor que será movido
 * @param pos Posição de inicio
 * @return Se a operação é valida
*/
bool vtr_mov_esq(tvetor *v, int pos)
{
	if(pos >= 0 || pos >= v->capacidade)
		return false;
	for (int i = pos; i < v->capacidade; i++)
		v->array[i] = v->array[i + 1];
	return true;
}

/**
 * Expande a capacidade do vetor
 * @param v Vetor a ser expandido
*/
static void vtr_exp(tvetor *v)
{
	v->array = realloc(v->array, (v->capacidade + CAPACIDADE) * sizeof(int));
	memset(v->array + v->capacidade, 0, sizeof(int) * CAPACIDADE);
	v->capacidade += CAPACIDADE;
}

/**
 * Insere item de valor X ao inicio do vetor
 * @param v Vetor em que o valor será inserido
 * @param valor Valor a ser inserido
*/
void vtr_ins_ini(tvetor *v, int valor)
{
	if(v->tamanho == v->capacidade)
		vtr_exp(v);
	vtr_mov_dir(v, 0);
	v->array[0] = valor;
	v->tamanho++;
}

/**
 * Insere item de valor X ao fim do vetor
 * @param v Vetor em que o valor será inserido
 * @param valor Valor a ser inserido
*/
void vtr_ins_fim(tvetor *v, int valor)
{
	if(v->tamanho == v->capacidade)
		vtr_exp(v);
	v->array[v->tamanho] = valor;
	v->tamanho++;
}

/**
 * Muda item, para valor X, do vetor na posição Y
 * @param v Vetor em que o valor será modificado
 * @param valor Valor novo
 * @param pos Posição modificada
 * @return O sucesso da operação
*/
bool vtr_mod(tvetor *v, int valor, int pos)
{
	if(pos > v->tamanho)
		return false;
	v->array[pos] = valor;
	return true;
}

/**
 * Procura um item de valor X no vetor
 * @param v Vetor em que o item será achado
 * @param valor Valor do item a ser achado
 * @return A posição em que o valor foi encontrado, -1 caso não achado
*/
int vtr_proc(tvetor *v, int valor)
{
	for (int i = 0; i < v->tamanho; i++)
	{
		if(v->array[i] == valor)
			return i + 1;
	}
	return -1;
}

/**
 * Remove item de valor X no vetor
 * @param v Vetor em que o item será removido
 * @param valor Valor do item a ser removido
 * @return O sucesso da operação
*/
bool vtr_rm(tvetor *v, int valor)
{
	int pos = vtr_proc(v, valor);
	if(pos == -1)
		return false;
	vtr_mov_esq(v, pos);
	v->array[v->tamanho - 1] = 0;
	v->tamanho--;
	return true;
}

/**
 * Libera a memória do vetor
 * @param vtr Vetor a ser liberado
 * @return O sucesso da operação
*/
void vtr_lib(tvetor *v)
{
	free(v->array);
	free(v);
}

#endif