#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>

struct no
{
	int info;
	struct no *prox;
};

struct lista
{
	no_t *inicio;
};

lista_t *lst_criar()
{
	lista_t *lst = malloc(sizeof(lista_t));
	if(!lst)
		return NULL;
	lst->inicio = NULL;
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
	no_t *n = lst->inicio;
	printf("[%d]", n->info);
	while (n->prox)
	{
		n = n->prox;
		printf(" -> [%d]", n->info);
	}
	puts("");
}

static no_t *no_ini(int valor)
{
	no_t *n = malloc(sizeof(no_t));
	if(!n)
		return NULL;
	n->info = valor;
	n->prox = NULL;
	return n;
}

bool lst_ins(lista_t *lst, int valor)
{
	no_t *n = no_ini(valor);
	if(!n)
		return false;
	if(!lst->inicio)
		lst->inicio = n;
	else
	{
		n->prox = lst->inicio;
		lst->inicio = n;
	}
	return true;
}

bool lst_mod(lista_t *lst, int antigo, int novo)
{
	if(!lst->inicio)
		return false;
	no_t *tmp = lst->inicio;
	while (tmp->prox)
	{
		tmp = tmp->prox;
		if(tmp->info == antigo)
		{
			tmp->info = novo;
			return true;
		}
	}
	return false;
}

bool lst_rm(lista_t *lst, int valor)
{
	if(!lst->inicio)
		return false;
	no_t *tmp = lst->inicio, *ant = tmp;
	while (tmp->prox)
	{
		if(tmp->info == valor)
		{
			ant->prox = tmp->prox;
			free(tmp);
			return true;
		}
		ant = tmp;
		tmp = tmp->prox;
	}
	return false;
}

void lst_lib(lista_t *lst)
{
	no_t *n = lst->inicio;
	while (n->prox)
	{
		no_t *tmp = n;
		n = n->prox;
		free(tmp);
	}
	free(lst);
}