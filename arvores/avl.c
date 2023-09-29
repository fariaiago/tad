#include "avl.h"
#include <stdio.h>
#include <string.h>

bool AVL_inserir(ArvoreBi *isto, void *vlr);
bool AVL_remover(ArvoreBi *isto, void *vlr);

void AVL_construtor(AVL *isto, size_t tmnh_dados)
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

void AVL_rebalancear(AVL *avl, NoAVL *no, NoAVL *pai)
{
	if (no->balanco == 1) // Rotação a esquerda
	{
		NoAVL *itr = no;
		while (itr)
		{
			itr->balanco -= 1;
			itr = (NoAVL *) itr->super.pai;
		}
		NoAVL *filho = (NoAVL *) no->super.dir;
		if (no->super.pai) //Atualiza o filho do pai se ele existe
		{
			if ((NoAVL *) no->super.pai->esq == no)
			{
				no->super.pai->esq = &filho->super;
			}
			else
			{
				no->super.pai->dir = &filho->super;
			}
		}
		if (no->super.dir && ((NoAVL *) no->super.dir)->balanco < 0) // Rotação dupla
		{
			NoAVL *neto = (NoAVL *) no->super.dir->esq;
			no->super.pai = &neto->super;
			no->super.dir = neto->super.esq;
			filho->super.pai = &neto->super;
			filho->super.esq = neto->super.dir;
			neto->super.esq = &no->super;
			neto->super.dir = &filho->super;
		}
		else // Rotação simples
		{
			filho->super.pai = no->super.pai;
			no->super.pai = &filho->super;
			no->super.dir = filho->super.esq;
			filho->super.esq = &no->super;
			printf("{} %d %d e%p t%p d%p ||\n", no->balanco, *((int *)no->super.info), no->super.esq, no, no->super.dir );
		}
		if (!filho->super.pai)
		{
			avl->super.raiz = &filho->super;
		}
	}
	else // Rotação a direita
	{
		NoAVL *itr = no;
		while (itr)
		{
			itr->balanco += 1;
			itr = (NoAVL *) itr->super.pai;
		}
		NoAVL *filho = (NoAVL *) no->super.esq;
		if (no->super.pai) //Atualiza o filho do pai se ele existe
		{
			if ((NoAVL *) no->super.pai->esq == no)
			{
				no->super.pai->esq = &filho->super;
			}
			else
			{
				no->super.pai->dir = &filho->super;
			}
		}
		if (((NoAVL *) no->super.dir)->balanco > 0) // Rotação dupla
		{
			NoAVL *neto = (NoAVL *) no->super.esq->dir;
			no->super.pai = &neto->super;
			no->super.esq = neto->super.dir;
			filho->super.pai = &neto->super;
			filho->super.dir = neto->super.esq;
			neto->super.dir = &no->super;
			neto->super.esq = &filho->super;
		}
		else // Rotação simples
		{
			filho->super.pai = no->super.pai;
			no->super.pai = &filho->super;
			no->super.esq = filho->super.dir;
			filho->super.dir = &no->super;
		}
		if (!filho->super.pai)
		{
			avl->super.raiz = &filho->super;
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
		isto->raiz = &n->super;
	else
	{
		NoAVL *itr = (NoAVL *) isto->raiz;
		while(true)
		{
			if (memcmp(n->super.info, itr->super.info, isto_avl->super.tmnh_dados) < 0)
				if (!itr->super.esq) // Inserção à esquerda
				{
					n->super.pai = &itr->super;
					itr->super.esq = &n->super;
					while (itr->super.pai)
					{
						itr = (NoAVL *) itr->super.pai;
						switch (itr->balanco)
						{
						case 0:
						case 1:
							itr->balanco -= 1;
							break;
						case -1:
							AVL_rebalancear(isto_avl, itr, (NoAVL *) itr->super.pai);
							break;
						default:
							itr->balanco -= 1;
							break;
						}
					}
					break;
				}
				else
				{
					itr = (NoAVL *) itr->super.esq;
				}
			else
				if (!itr->super.dir) // Inserção à direita
				{
					n->super.pai = &itr->super;
					itr->super.dir = &n->super;
					while (itr->super.pai)
					{
						itr = (NoAVL *) itr->super.pai;
						switch (itr->balanco)
						{
						case -1:
						case 0:
							itr->balanco += 1;
							break;
						case 1:
							AVL_rebalancear(isto_avl, itr, (NoAVL *) itr->super.pai);
							break;
						default:
							itr->balanco += 1;
							break;
						}
						// printf(" %d %d %p %p |", itr->balanco, *((int *)itr->super.info), itr->super.esq, itr->super.dir );
					}
					break;
				}
				else
					itr = (NoAVL *) itr->super.dir;
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