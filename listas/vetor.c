#include "vetor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool Vetor_inserir(Lista *isto, void *info);
bool Vetor_remover(Lista *isto, void *info);
bool Vetor_modificar(Lista *isto, void *velho, void *novo);
void Vetor_imprimir(Lista *isto);

void Vetor_construtor(Vetor *isto, size_t tmnh_dados)
{
	Lista_construtor(&isto->super);
	const static ListaVtbl vtbl = {
		&Vetor_inserir,
		&Vetor_remover,
		&Vetor_modificar,
		&Vetor_imprimir
	};
	isto->super.tblptr = &vtbl;
	isto->capacidade = CAP_PADRAO;
	isto->tamanho = 0;
	isto->tmnh_dados = tmnh_dados;
	isto->dados = NULL;
}

bool Vetor_inserir(Lista *isto, void *info)
{
	if(!isto || !info)
		return false;
	
	Vetor *isto_vtr = (Vetor *) isto;
	if (!isto_vtr->dados)
	{
		isto_vtr->dados = calloc(isto_vtr->capacidade, sizeof(char *));
	}
	else if (isto_vtr->tamanho == isto_vtr->capacidade)
	{
		isto_vtr->capacidade *= 2;
		isto_vtr->dados = realloc(isto_vtr->dados, isto_vtr->capacidade * isto_vtr->tmnh_dados);
	}
	isto_vtr->dados[isto_vtr->tamanho] = malloc(isto_vtr->tmnh_dados);
	memcpy(isto_vtr->dados[isto_vtr->tamanho], info, isto_vtr->tmnh_dados);
	isto_vtr->dados[isto_vtr->tamanho];
	isto_vtr->tamanho++;
	return true;
}

bool Vetor_remover(Lista *isto, void *info)
{
	if(!isto || !info)
		return false;
	
	Vetor *isto_vtr = (Vetor *) isto;
	if (!isto_vtr->dados)
	{
		return false;
	}
	else
	{
		for (size_t i = 0; i < isto_vtr->tamanho; i++)
		{
			if (memcmp(isto_vtr->dados[i], info, isto_vtr->tmnh_dados) == 0)
			{
				isto_vtr->tamanho--;
				free(isto_vtr->dados[i]);
				for (; i < isto_vtr->tamanho; i++)
				{
					isto_vtr->dados[i] = isto_vtr->dados[i + 1];
				}
				isto_vtr->dados[isto_vtr->tamanho] = NULL;
				return true;
			}
		}
	}
	return false;
}

bool Vetor_modificar(Lista *isto, void *velho, void *novo)
{
	if(!isto || !velho || !novo)
		return false;
	
	Vetor *isto_vtr = (Vetor *) isto;
	if (!isto_vtr->dados)
	{
		return false;
	}
	else
	{
		for (size_t i = 0; i < isto_vtr->tamanho; i++)
		{
			if (memcmp(isto_vtr->dados[i], velho, isto_vtr->tmnh_dados) == 0)
			{
				memcpy(isto_vtr->dados[i], novo, isto_vtr->tmnh_dados);
				return true;
			}
		}
	}
	return true;
}

void Vetor_imprimir(Lista *isto)
{
	Vetor *isto_vtr = (Vetor *) isto;
	printf("{Vetor");
	if (isto_vtr->dados && isto_vtr->tamanho > 0)
	{
		printf("| info:%p", isto_vtr->dados[0]);
		for (size_t i = 1; i < isto_vtr->tamanho; i++)
		{
			printf(" -> info:%p", isto_vtr->dados[i]);
		}
	}
	puts("}");
}

void Vetor_destruir(Lista *isto)
{
	Vetor *isto_vtr = (Vetor *) isto;
	if (isto_vtr->dados)
	{
		for (size_t i = 1; i < isto_vtr->tamanho; i++)
		{
			free(isto_vtr->dados[i]);
		}
		isto_vtr->dados = NULL;
	}
}