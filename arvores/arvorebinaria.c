#include "arvorebinaria.h"
#include <stdio.h>
#include <stdlib.h>

void ArvoreBi_construtor(ArvoreBi *arv)
{
	static struct ArvoreBiVtbl vtbl = {
		&ArvoreBi_inserir,
		&ArvoreBi_remover,
		&ArvoreBi_procurar
	};
	arv->vtblptr = &vtbl;
}

bool ArvoreBi_inserir(ArvoreBi *arb, void *vlr)
{
	return arb->vtblptr->inserir(arb, vlr);
}

bool ArvoreBi_remover(ArvoreBi *arb, void *vlr)
{
	return arb->vtblptr->remover(arb, vlr);
}

NoA *ArvoreBi_procurar(ArvoreBi *arb, void *vlr)
{
	return arb->vtblptr->procurar(arb, vlr);
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
	printf("%d ", *(int *)no->info);
	if (no->esq)
		pos(no->esq);
	if (no->dir)
		pos(no->dir);
}

void ArvoreBi_imprimir(ArvoreBi *arb)
{
	pre(arb->raiz);
	puts("");
	ordem(arb->raiz);
	puts("");
	pos(arb->raiz);
	puts("");
}

void ArvoreBi_destruir(ArvoreBi *);