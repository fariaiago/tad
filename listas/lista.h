#ifndef LISTA_BASE_H
#define LISTA_BASE_H

#include <stdbool.h>

struct ListaBase
{
	const struct ListaTabelaVirtual *tblptr;
} typedef Lista;

struct ListaTabelaVirtual
{
	bool (*inserir)(Lista *, void *);
	bool (*remover)(Lista *, void *);
	bool (*modificar)(Lista *, void *, void *);
	void (*imprimir)(Lista *);
	void (*destruir)(Lista *);
} typedef ListaVtbl;

/**
 * Inicializa uma Lista
 * @param Lista*isto Lista a ser inicializada
*/
void Lista_construtor(Lista *isto);

/**
 * Insere um item na Lista
 * @param Lista*isto Lista onde o item será inserido
 * @param void*info Item cujo o valor inserido
*/
bool Lista_inserir(Lista *isto, void *info);

/**
 * Remove um item da lista
 * @param Lista*isto Lista de onde o item será removido
 * @param void*info Valor cujo o equivalente será removido
*/
bool Lista_remover(Lista *isto, void *info);

/**
 * Modifica o valor de um item na lista
 * @param Lista*isto Lista em que o valor antigo será modificado
 * @param void*velho Valor antigo e que será procurado 
*/
bool Lista_modificar(Lista *isto, void *velho, void *novo);

/**
 * Imprime uma lista para a saída
*/
void Lista_imprimir(Lista *isto);

/**
 * Libera a memória de uma lista
*/
void Lista_destruir(Lista *isto);

#endif