#include "arb.h"
#include <string.h>

int NIL_INFO = 0;
NoARB NIL = {
	.cor = COR_PRETO,
	.super = {
		.pai = NULL,
		.esq = NULL,
		.dir = NULL,
		.info = &NIL_INFO
	}
};

bool ARB_inserir(ArvoreBi *isto, void *vlr);
bool ARB_remover(ArvoreBi *isto, void *vlr);

void ARB_construtor(ARB *isto, size_t tmnh_dados)
{
	static struct ArvoreBiVtbl const vtbl = {
		&ARB_inserir,
		&ARB_remover
	};
	ArvoreBi_construtor(&isto->super);
	isto->super.vtblptr = &vtbl;
	isto->super.raiz = (NoA *) &NIL;
	isto->super.tmnh_dados = tmnh_dados;
}

static NoARB *no_criar(void *vlr, size_t tmnh_dados)
{
	NoARB *n = malloc(sizeof(NoARB));
	if(n)
	{
		n->super.info = malloc(tmnh_dados);
		memcpy(n->super.info, vlr, tmnh_dados);
		n->super.esq = (NoA *) &NIL;
		n->super.dir = (NoA *) &NIL;
		n->cor = COR_VERMELHO;
	}
	return n;
}

void ARB_rodar_esq(ARB *arv, NoARB *no)
{
	NoARB *tmp = (NoARB *) no->super.dir;
	no->super.dir = tmp->super.esq;
	if (tmp->super.esq != (NoA *) &NIL)
		tmp->super.esq->pai = (NoA *) no;
	tmp->super.pai = no->super.pai;
	if (no->super.pai == (NoA *) &NIL)
		arv->super.raiz = (NoA *) tmp;
	else if (no == (NoARB *)no->super.pai->esq)
		no->super.pai->esq = (NoA *) tmp;
	else
		no->super.pai->dir = (NoA *) tmp;
	tmp->super.esq = (NoA *) no;
	no->super.pai = (NoA *) tmp;
}

void ARB_rodar_dir(ARB *arv, NoARB *no)
{
	NoARB *tmp = (NoARB *) no->super.esq;
	no->super.esq = tmp->super.dir;
	if (tmp->super.dir != (NoA *) &NIL)
		tmp->super.dir->pai = (NoA *) no;
	tmp->super.pai = no->super.pai;
	if (no->super.pai == (NoA *) &NIL)
		arv->super.raiz = (NoA *) tmp;
	else if (no == (NoARB *)no->super.pai->dir)
		no->super.pai->dir = (NoA *) tmp;
	else
		no->super.pai->esq = (NoA *) tmp;
	tmp->super.dir = (NoA *) no;
	no->super.pai = (NoA *) tmp;
}

void ARB_consertar(ARB *arv, NoARB *no)
{
	NoARB *itr = no;
	while (( (NoARB *) itr->super.pai)->cor == COR_VERMELHO)
	{
		if (itr->super.pai == itr->super.pai->pai->esq)
		{
			NoARB *tmp = (NoARB *) itr->super.pai->pai->dir;
			if (tmp->cor == COR_VERMELHO)
			{
				itr->cor = COR_PRETO;
				tmp->cor = COR_PRETO;
				((NoARB *) itr->super.pai->pai)->cor = COR_VERMELHO;
				itr = (NoARB *) itr->super.pai->pai;
			}
			else 
			{
				if (itr == (NoARB *) itr->super.pai->dir)
				{
					itr = (NoARB *) itr->super.pai;
					ARB_rodar_esq(arv, no);
				}
				((NoARB *) itr->super.pai)->cor = COR_PRETO;
				((NoARB *) itr->super.pai->pai)->cor = COR_VERMELHO;
				ARB_rodar_dir(arv, (NoARB *) no->super.pai->pai);
			}
		}
		else
		{
			NoARB *tmp = (NoARB *) itr->super.pai->pai->esq;
			if (tmp->cor == COR_VERMELHO)
			{
				itr->cor = COR_PRETO;
				tmp->cor = COR_PRETO;
				((NoARB *) itr->super.pai->pai)->cor = COR_VERMELHO;
				itr = (NoARB *) itr->super.pai->pai;
			}
			else 
			{
				if (itr == (NoARB *) itr->super.pai->esq)
				{
					itr = (NoARB *) itr->super.pai;
					ARB_rodar_dir(arv, no);
				}
				((NoARB *) itr->super.pai)->cor = COR_PRETO;
				((NoARB *) itr->super.pai->pai)->cor = COR_VERMELHO;
				ARB_rodar_esq(arv, (NoARB *) no->super.pai->pai);
			}
		}
	}
	((NoARB *) arv->super.raiz)->cor = COR_PRETO;
}

bool ARB_inserir(ArvoreBi *isto, void *vlr)
{
	NoARB *novo = no_criar(vlr, isto->tmnh_dados);
	if (!isto || !novo)
		return false;
	
	NoARB *pai = &NIL;
	NoARB *itr = (NoARB *) isto->raiz;
	while (itr != &NIL)
	{
		pai = itr;
		if (memcmp(novo->super.info, itr->super.info, isto->tmnh_dados) < 0)
		{
			itr = (NoARB *) itr->super.esq;
		}
		else
		{
			itr = (NoARB *) itr->super.dir;
		}
	}
	novo->super.pai = (NoA *) pai;
	if (pai == &NIL)
	{
		isto->raiz = (NoA *) novo;
	}
	else if (memcmp(novo->super.info, pai->super.info, isto->tmnh_dados) < 0)
	{
		pai->super.esq = (NoA *) novo;
	}
	else
	{
		pai->super.dir = (NoA *) novo;
	}
	ARB_consertar((ARB *) isto, novo);
}

bool ARB_remover(ArvoreBi *isto, void *vlr)
{
	return true;
}