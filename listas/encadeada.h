#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

#include "lista.h"
#include <stdbool.h>
#include <stddef.h>

struct ListaNo
{
	void *info;
	struct ListaNo *prox;
} typedef No;

struct ListaEncadeada
{
	Lista super;
	size_t tmnh_dados;
	No *inicio;
} typedef ListaEncadeada;

/**
 * Construtor de ListaEncadeada
 * @param Lista*isto Lista a ser inicializada
*/
void ListaEncadeada_construtor(ListaEncadeada *isto, size_t tmnh_dados);

#endif