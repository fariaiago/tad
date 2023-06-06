#include "lista.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>

struct no
{
	int info;
	no_t *ant;
	no_t *prox;
};

struct lista
{
	no_t *inicio;
	no_t *fim;
};

lista_t *lst_criar()
{
	lista_t *lst = calloc(1, sizeof(lista_t));
	return lst;
}

lista_t *lst_ini(int num, ...)
{
	va_list arg;
	lista_t *lst = lst_criar();
	va_start(arg, num);
	for (int i = 0; i < num; i++)
		lst_ins(lst, va_arg(arg, int));
	va_end(arg);
	return lst;
}

void lst_impr(lista_t *lst)
{
	if(!lst)
	{
		printf("Lista nula\n");
		return;
	}
	no_t *itr = lst->inicio;
	while (itr)
	{
		printf("[%p : %d : %p]%s", itr->ant, itr->info, itr->prox, itr->prox ? " -> " : "");
		itr = itr->prox;
	}
	printf("\n");
}

static no_t *no_ini(int vlr)
{
	no_t *n = calloc(1, sizeof(no_t));
	if(n)
		n->info = vlr;
	return n;
}

bool lst_ins(lista_t *lst, int vlr)
{
	no_t *n = no_ini(vlr);
	if(!lst || !n)
		return false;
	if(!lst->inicio)
	{
		lst->inicio = n;
		lst->fim = n;
	}
	else
	{
		lst->fim->prox = n;
		n->ant =  lst->fim;
		lst->fim = n;
	}
	return true;
}

bool lst_mod(lista_t *lst, int vlh, int nv)
{
	if(!lst)
		return false;
	no_t *itr = lst->inicio;
	no_t *itr_rvs = lst->fim;
	while (itr)
	{
		if(itr->info == vlh)
		{
			itr->info = nv;
			return true;
		}
		if(itr_rvs->info == vlh)
		{
			itr_rvs->info = nv;
			return true;
		}
		if(itr == itr_rvs)
			return false;
		itr = itr->prox;
		itr_rvs = itr_rvs->ant;
	}
	return false;
}

bool lst_rm(lista_t *lst, int vlr)
{
	if(!lst)
		return false;
	no_t *itr = lst->inicio;
	no_t *itr_rvs = lst->fim;
	while (itr)
	{
		if(itr->info == vlr)
		{
			if(!itr->ant)
				lst->inicio = itr->prox;
			else
				itr->ant->prox = itr->prox;
			itr->prox->ant = itr->ant;
			free(itr);
			return true;
		}
		if(itr_rvs->info == vlr)
		{
			if(!itr_rvs->prox)
				lst->fim = itr_rvs->ant;
			else
				itr_rvs->prox->ant = itr_rvs->ant;
			itr_rvs->ant->prox = itr_rvs->prox;
			free(itr_rvs);
			return true;
		}
		if(itr == itr_rvs)
			return false;
		itr = itr->prox;
		itr_rvs = itr_rvs->ant;
	}
	return false;
}

void lst_lib(lista_t *lst)
{
	if(!lst)
		return;
	no_t *itr = lst->inicio, *itr_old;
	no_t *itr_rvs = lst->fim, *itr_rvs_old;
	while (itr)
	{
		itr_old = itr;
		itr_rvs_old = itr_rvs;
		if(itr == itr_rvs)
		{
			free(itr);
			break;
		}
		itr = itr->prox;
		itr_rvs = itr_rvs->ant;
		free(itr_old);
		free(itr_rvs_old);
	}
	free(lst);
}