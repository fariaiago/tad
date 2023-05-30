#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>

struct no
{
	int info;
	no_t *esq;
	no_t *dir;
};

struct arvore
{
	no_t *raiz;
};

arvore_t *arb_criar(void)
{
	arvore_t *arb = malloc(sizeof(arvore_t));
	if(arb)
		arb->raiz = NULL;
	return arb;
}

static no_t *no_criar(int vlr)
{
	no_t *n = malloc(sizeof(no_t));
	if(n)
	{
		n->info = vlr;
		n->esq = NULL;
		n->dir = NULL;
	}
	return n;
}

bool arb_ins(arvore_t *arb, int vlr)
{
	no_t *n = no_criar(vlr);
	if(!arb || !n)
		return false;
	if(!arb->raiz)
		arb->raiz = n;
	else
	{
		no_t *itr = arb->raiz;
		while(true)
		{
			if (n->info < itr->info)
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

bool arb_rm(arvore_t *arb, int vlr)
{
	no_t *itr = arb->raiz;
	while(itr)
	{
		if (vlr < itr->info)
			itr = itr->esq;
		else if (vlr > itr->info)
			itr = itr->dir;
		else
		{
			//TODO Remover nó
			return true;
		}
	}
	return false;
}

no_t *arb_proc(arvore_t *, int);

int arb_alt(arvore_t *, int);

int arb_tmnh(arvore_t *);

void arb_impr(arvore_t *);

void arb_lib(arvore_t *);