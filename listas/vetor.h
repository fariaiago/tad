#ifndef VETOR_H
#define VETOR_H

#include "lista.h"
#include <stdbool.h>
#include <stddef.h>

#define CAP_PADRAO 10

struct Vetor
{
	Lista super;
	size_t capacidade;
	size_t tamanho;
	size_t tmnh_dados;
	void **dados;
} typedef Vetor;

/**
 * Construtor de Vetor
 * @param Lista*isto Vetor a ser inicializado
*/
void Vetor_construtor(Vetor *isto, size_t tmnh_dados);

#endif