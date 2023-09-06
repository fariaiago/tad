#include "abb.h"
#include <string.h>

bool ABB_inserir(ArvoreBi *isto, void *vlr);
bool ABB_remover(ArvoreBi *isto, void *vlr);
NoA *ABB_procurar(ArvoreBi *isto, void *vlr);
void ABB_imprimir(ArvoreBi *isto);

void ABB_construtor(ABB *isto, size_t tmnh_dados)
{
	static struct ArvoreBiVtbl const vtbl = {
		&ABB_inserir
	};
	ArvoreBi_construtor(&isto->super);
	isto->super.vtblptr = &vtbl;
	isto->super.raiz = NULL;
	isto->tmnh_dados = tmnh_dados;
}

static NoA *no_criar(void *vlr, size_t tmnh_dados)
{
	NoA *n = malloc(sizeof(NoA));
	if(n)
	{
		n->info = malloc(tmnh_dados);
		memcpy(n->info, vlr, tmnh_dados);
		n->esq = NULL;
		n->dir = NULL;
	}
	return n;
}

bool ABB_inserir(ArvoreBi *isto, void *vlr)
{
	ABB *isto_abb = (ABB *) isto;
	if(!isto)
		return false;
	NoA *n = no_criar(vlr, isto_abb->tmnh_dados);
	if (!n)
		return false;
	
	if(!isto->raiz)
		isto->raiz = n;
	else
	{
		NoA *itr = isto->raiz;
		while(true)
		{
			if (memcmp(n->info, itr->info, 4) < 0)
				if (!itr->esq)
				{
					itr->esq = n;
					break;
				}
				else
					itr = itr->esq;
			else
				if (!itr->dir)
				{
					itr->dir = n;
					break;
				}
				else
					itr = itr->dir;
		}
	}
	return true;
}

bool ABB_remover(ArvoreBi *isto, void *vlr)
{
	return true;
}

NoA *ABB_procurar(ArvoreBi *isto, void *vlr)
{
	return NULL;
}

void ABB_imprimir(ArvoreBi *isto)
{}