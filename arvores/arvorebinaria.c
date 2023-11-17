#include "arvorebinaria.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void _ArvoreBi_destruir(ArvoreBi *isto);

void ArvoreBi_construtor(ArvoreBi *isto)
{
	static struct ArvoreBiVtbl vtbl = {
//		NULL,
		&ArvoreBi_inserir,
		&ArvoreBi_remover
//		,&_ArvoreBi_destruir
	};
	isto->vtblptr = &vtbl;
}

bool ArvoreBi_inserir(ArvoreBi *isto, void *vlr)
{
	return isto->vtblptr->inserir(isto, vlr);
}

bool ArvoreBi_remover(ArvoreBi *isto, void *vlr)
{
	return isto->vtblptr->remover(isto, vlr);
}

NoA *ArvoreBi_procurar(ArvoreBi *isto, void *vlr)
{
	NoA *itr = isto->raiz;
	while (itr && memcmp(vlr, itr->info, isto->tmnh_dados) != 0)
	{
		itr = (memcmp(vlr, itr->info, isto->tmnh_dados) < 0) ? itr->esq : itr->dir;
	}
	return itr;
}

NoA *ArvoreBi_minimo(NoA *no)
{
	while (no->esq)
	{
		no = no->esq;
	}
	return no;
}

int NoA_altura(NoA *no)
{
	if (!no)
	{
		return -1;
	}
	else
	{
		int he = NoA_altura(no->esq),
		hd = NoA_altura(no->dir);
		if (he < hd)
		{
			return he + 1;
		}
		else
		{
			return hd + 1;
		}
	}
}

void pre(NoA *no)
{
	printf("%d ", *(int *)no->info);
	if (no->esq)
		pre(no->esq);
	if (no->dir)
		pre(no->dir);
}

void ordem(NoA *no)
{
	if (no->esq)
		ordem(no->esq);
	printf("%d ", *(int *)no->info);
	if (no->dir)
		ordem(no->dir);
}

void pos(NoA *no)
{
	if (no->esq)
		pos(no->esq);
	if (no->dir)
		pos(no->dir);
	printf("%d ", *(int *)no->info);
}

void ArvoreBi_imprimir(ArvoreBi *isto)
{
	printf("pre: ");
	pre(isto->raiz);
	printf("\nord: ");
	ordem(isto->raiz);
	printf("\npos: ");
	pos(isto->raiz);
	puts("");
}

void NoA_destruir(NoA *no)
{
	if (no->esq)
		NoA_destruir(no->esq);
	if (no->dir)
		NoA_destruir(no->dir);
	free(no->info);
	free(no);
}

void ArvoreBi_destruir(ArvoreBi *isto)
{
	/*isto->vtblptr->destruir(isto);
}

void _ArvoreBi_destruir(ArvoreBi *isto)
{*/
	if (isto->raiz)
		NoA_destruir(isto->raiz);
}