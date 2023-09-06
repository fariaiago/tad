#include "encadeada.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool ListaEncadeada_inserir(Lista *isto, void *info);
bool ListaEncadeada_remover(Lista *isto, void *info);
bool ListaEncadeada_modificar(Lista *isto, void *velho, void *novo);
void ListaEncadeada_imprimir(Lista *isto);

void ListaEncadeada_construtor(ListaEncadeada *isto, size_t tmnh_dados)
{
	Lista_construtor(&isto->super);
	const static ListaVtbl vtbl = {
		&ListaEncadeada_inserir,
		&ListaEncadeada_remover,
		&ListaEncadeada_modificar,
		&ListaEncadeada_imprimir
	};
	isto->super.tblptr = &vtbl;
	isto->inicio = NULL;
	isto->tmnh_dados = tmnh_dados;
}

bool ListaEncadeada_inserir(Lista *isto, void *info)
{
	No *no = malloc(sizeof(No));
	if(!isto || !info || !no)
		return false;
	
	ListaEncadeada *isto_le = (ListaEncadeada *) isto;
	no->info = malloc(isto_le->tmnh_dados);
	memcpy(no->info, info, isto_le->tmnh_dados);
	no->prox = NULL;
	if (!isto_le->inicio)
	{
		isto_le->inicio = no;
	}
	else
	{
		no->prox = isto_le->inicio;
		isto_le->inicio = no;
	}
	return true;
}

bool ListaEncadeada_remover(Lista *isto, void *info)
{
	if(!isto || !info)
		return false;
	
	ListaEncadeada *isto_le = (ListaEncadeada *) isto;
	if (!isto_le->inicio)
	{
		return false;
	}
	else
	{
		No *itr = isto_le->inicio, *ant = itr;
		while (itr)
		{
			if (memcmp(itr->info, info, isto_le->tmnh_dados) == 0)
			{
				if (isto_le->inicio == itr)
				{
					isto_le->inicio = itr->prox;
				}
				ant->prox = itr->prox;
				free(itr);
				return true;
			}
			ant = itr;
			itr = itr->prox;
		}
	}
	return true;
}

bool ListaEncadeada_modificar(Lista *isto, void *velho, void *novo)
{
	if(!isto || !velho || !novo)
		return false;
	
	ListaEncadeada *isto_le = (ListaEncadeada *) isto;
	if (!isto_le->inicio)
	{
		return false;
	}
	else
	{
		No *itr = isto_le->inicio;
		while (itr->prox)
		{
			if (memcmp(itr->info, velho, isto_le->tmnh_dados) == 0)
			{
				memcpy(itr->info, novo, isto_le->tmnh_dados);
				return true;
			}
			itr = itr->prox;
		}
	}
	return true;
}

void ListaEncadeada_imprimir(Lista *isto)
{
	ListaEncadeada *isto_le = (ListaEncadeada *) isto;
	printf("{Lista Encadeada");
	if (isto_le->inicio)
	{
		No *itr = isto_le->inicio;
		printf("| info:%p|prox:%p", itr->info, itr->prox);
		while (itr->prox)
		{
			itr = itr->prox;
			printf(" -> info:%p|prox:%p", itr->info, itr->prox);
		}
	}
	puts("}");
}

void ListaEncadeada_destruir(Lista *isto)
{
	ListaEncadeada *isto_le = (ListaEncadeada *) isto;
	if (isto_le->inicio)
	{
		No *itr = isto_le->inicio, *ant;
		while (itr)
		{
			ant = itr;
			itr = itr->prox;
			free(ant);
		}
		isto_le->inicio = NULL;
	}
}