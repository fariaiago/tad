#include "lista.h"
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

bool ListaBase_inserir(Lista *isto, void *info);
bool ListaBase_remover(Lista *isto, void *info);
bool ListaBase_modificar(Lista *isto, void *velho, void *novo);
void ListaBase_imprimir(Lista *isto);
void ListaBase_destruir(Lista *isto);

void Lista_construtor(Lista *isto)
{
	static ListaVtbl const vtbl = {
		&ListaBase_inserir,
		&ListaBase_remover,
		&ListaBase_modificar,
		&ListaBase_imprimir
	};
	isto->tblptr = &vtbl;
}

bool Lista_inserir(Lista *isto, void *info)
{
	return isto->tblptr->inserir(isto, info);
}

bool Lista_remover(Lista *isto, void *info)
{
	return isto->tblptr->remover(isto, info);
}

bool Lista_modificar(Lista *isto, void *velho, void *novo)
{
	return isto->tblptr->modificar(isto, velho, novo);
}

void Lista_imprimir(Lista *isto)
{
	isto->tblptr->imprimir(isto);
}

void Lista_destruir(Lista *isto)
{
	isto->tblptr->destruir(isto);
}

bool ListaBase_inserir(Lista *isto, void *info)
{
	assert(false && "Método abstrato");
	return false;
}

bool ListaBase_remover(Lista *isto, void *info)
{
	assert(false && "Método abstrato");
	return false;
}

bool ListaBase_modificar(Lista *isto, void *velho, void *novo)
{
	assert(false && "Método abstrato");
	return false;
}

void ListaBase_imprimir(Lista *isto)
{
	assert(false && "Método abstrato");
}

void ListaBase_destruir(Lista *isto)
{
	assert(false && "Método abstrato");
}