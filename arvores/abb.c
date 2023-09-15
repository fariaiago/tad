#include "abb.h"
#include <string.h>

bool ABB_inserir(ArvoreBi *isto, void *vlr);
bool ABB_remover(ArvoreBi *isto, void *vlr);

void ABB_construtor(ABB *isto, size_t tmnh_dados)
{
	static struct ArvoreBiVtbl const vtbl = {
		&ABB_inserir,
		&ABB_remover
	};
	ArvoreBi_construtor(&isto->super);
	isto->super.vtblptr = &vtbl;
	isto->super.raiz = NULL;
	isto->super.tmnh_dados = tmnh_dados;
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
	NoA *n = no_criar(vlr, isto_abb->super.tmnh_dados);
	if (!n)
		return false;
	
	if(!isto->raiz)
		isto->raiz = n;
	else
	{
		NoA *itr = isto->raiz;
		while(true)
		{
			if (memcmp(n->info, itr->info, isto_abb->super.tmnh_dados) < 0)
				if (!itr->esq)
				{
					n->pai = itr;
					itr->esq = n;
					break;
				}
				else
					itr = itr->esq;
			else
				if (!itr->dir)
				{
					n->pai = itr;
					itr->dir = n;
					break;
				}
				else
					itr = itr->dir;
		}
	}
	return true;
}

void NoA_transplantar(ArvoreBi *isto, NoA *ant, NoA *novo)
{
	if (!ant->pai)
	{
		isto->raiz = novo;
	}
	else if (ant == ant->pai->esq)
	{
		ant->pai->esq = novo;
	}
	else
	{
		ant->pai->dir = novo;
	}
	if (novo)
	{
		novo->pai = ant->pai;
	}
}

bool ABB_remover(ArvoreBi *isto, void *vlr)
{
	NoA *rm = ArvoreBi_procurar(isto, vlr);
	if (!rm)
	{
		return false;
	}
	if (!rm->esq)
	{
		NoA_transplantar(isto, rm, rm->dir);
	}
	else if (!rm->dir)
	{
		NoA_transplantar(isto, rm, rm->esq);
	}
	else
	{
		NoA *min = ArvoreBi_minimo(rm->dir);
		if (min->pai != rm)
		{
			NoA_transplantar(isto, min, min->dir);
			min->dir = rm->dir;
			min->dir->pai = min;
		}
		NoA_transplantar(isto, rm, min);
		min->esq = rm->esq;
		min->esq->pai = min;
	}
	free(rm->info);
	free(rm);
	return true;
}