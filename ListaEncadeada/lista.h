#ifndef LISTA_H
#define LISTA_H

#include <stdbool.h>

typedef struct no no_t;

typedef struct lista lista_t;

/**
 * Cria uma lista
 * @return A lista criada
*/
lista_t *lst_criar();

/**
 * Inicializa uma lista com N nós
 * @param int Número de nós
 * @param ... Valor dos nós
 * @return A lista criada
*/
lista_t *lst_ini(int, ...);

/**
 * Imprime uma lista
 * @param lista_t Lista a ser impressa
*/
void lst_impr(lista_t *);

/**
 * Inicializa um nó
 * @param int O valor do nó
 * @return O nó criado
*/
static no_t *no_ini(int);

/**
 * Insere um nó na lista
 * @param lista_t* lista em que o nó será inserido
 * @param int Valor a ser inserido
 * @return O sucesso da inserção
*/
bool lst_ins(lista_t *, int);

/**
 * Modifica um nó da lista
 * @param lista_t* lista do nó será modificado
 * @param int Valor antigo
 * @param int Valor novo
 * @return O sucesso da inserção
*/
bool lst_mod(lista_t *, int, int);

/**
 * Remove um nó da lista
 * @param lista_t* lista de que o nó será removido
 * @param int Valor do nó a ser removido
 * @return O sucesso da inserção
*/
bool lst_rm(lista_t *, int);

/**
 * Libera uma lista da memória
 * @param lista_t* lista que será liberada
*/
void lst_lib(lista_t *);

#endif