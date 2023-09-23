#include "avl.h"
#include <string.h>

bool AVL_inserir(ArvoreBi *isto, void *vlr);
bool AVL_remover(ArvoreBi *isto, void *vlr);

void ABB_construtor(AVL *isto, size_t tmnh_dados)
{
	static struct ArvoreBiVtbl const vtbl = {
		&AVL_inserir,
		&AVL_remover
	};
	ArvoreBi_construtor(&isto->super);
	isto->super.vtblptr = &vtbl;
	isto->super.raiz = NULL;
	isto->super.tmnh_dados = tmnh_dados;
}

static NoAVL *no_criar(void *vlr, size_t tmnh_dados)
{
	NoAVL *n = malloc(sizeof(NoAVL));
	if(n)
	{
		n->super.info = malloc(tmnh_dados);
		memcpy(n->super.info, vlr, tmnh_dados);
		n->super.esq = NULL;
		n->super.dir = NULL;
		n->balanco = 0;
	}
	return n;
}

void AVL_rebalancear(NoAVL *no, NoAVL *pai)
{
	if (no->balanco == -1) // Rotação a esquerda
	{
		NoAVL *filho = no->super.dir;
		if ( ((NoAVL *) no->super.dir)->balanco < 0) // Rotação dupla
		{
			NoAVL *neto = no->super.dir->esq;
			if (no->super.pai->esq = no)
			{
				no->super.pai->esq = filho;
			}
			else
			{
				no->super.pai->dir = filho;
			}
			no->super.pai = neto;
			no->super.dir = neto->super.esq;
			filho->super.pai = neto;
			filho->super.esq = neto->super.dir;
			neto->super.esq = no;
			neto->super.dir = filho;
		}
		else // Rotação simples
		{
			if (no->super.pai->esq = no)
			{
				no->super.pai->esq = filho;
			}
			else
			{
				no->super.pai->dir = filho;
			}
			no->super.pai = filho;
			no->super.dir = filho->super.esq;
			filho->super.esq = no;
		}
	}
	else // Rotação a direita
	{
		NoAVL *filho = no->super.esq;
		if (((NoAVL *) no->super.dir)->balanco > 0) // Rotação dupla
		{
			NoAVL *neto = no->super.esq->dir;
			if (no->super.pai->esq = no)
			{
				no->super.pai->esq = filho;
			}
			else
			{
				no->super.pai->dir = filho;
			}
			no->super.pai = neto;
			no->super.esq = neto->super.dir;
			filho->super.pai = neto;
			filho->super.dir = neto->super.esq;
			neto->super.dir = no;
			neto->super.esq = filho;
		}
		else // Rotação simples
		{
			if (no->super.pai->esq = no)
			{
				no->super.pai->esq = filho;
			}
			else
			{
				no->super.pai->dir = filho;
			}
			no->super.pai = filho;
			no->super.esq = filho->super.dir;
			filho->super.dir = no;
		}
	}
}

bool AVL_inserir(ArvoreBi *isto, void *vlr)
{
	AVL *isto_avl = (AVL *) isto;
	if(!isto)
		return false;
	NoAVL *n = no_criar(vlr, isto_avl->super.tmnh_dados);
	if (!n)
		return false;
	
	if(!isto->raiz)
		isto->raiz = n;
	else
	{
		NoAVL *itr = isto->raiz;
		while(true)
		{
			if (memcmp(n->super.info, itr->super.info, isto_avl->super.tmnh_dados) < 0)
				if (!itr->super.esq)
				{
					n->super.pai = itr;
					itr->super.esq = n;
					while (itr->super.pai)
					{
						switch (itr->balanco)
						{
						case 0:
						case 1:
							itr->balanco -= 1;
							break;
						case -1:
							AVL_rebalancear(itr, itr->super.pai);
						default:
							itr->balanco -= 1;
							break;
						}
						itr = itr->super.pai;
					}
					break;
				}
				else
				{
					itr = itr->super.esq;
				}
			else
				if (!itr->super.dir)
				{
					n->super.pai = itr;
					itr->super.dir = n;
					while (itr->super.pai)
					{
						switch (itr->balanco)
						{
						case -1:
						case 0:
							itr->balanco += 1;
							break;
						case 1:
							AVL_rebalancear(itr, itr->super.pai);
						default:
							itr->balanco += 1;
							break;
						}
						itr = itr->super.pai;
					}
					break;
				}
				else
					itr = itr->super.dir;
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

bool AVL_remover(ArvoreBi *isto, void *vlr)
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