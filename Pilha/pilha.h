#ifndef PILHA_H
#define PILHA_H

#include <stdbool.h>

typedef struct pilha pilha_t;

/**
 * Cria uma pilha
 * @return A pilha criada
*/
pilha_t *plh_criar(void);

/**
 * Inicializa uma pilha
 * @param int Número de items
 * @param ... Items
 * @return A pilha criada
*/
pilha_t *plh_ini(int, ...);

/**
 * Imprime uma pilha
 * @param pilha_t* Pilha que será impressa
*/
void plh_impr(pilha_t *);

/**
 * Insere um item ao topo da pilha
 * @param pilha_t* Pilha em que o valor será inserido
 * @param int O valor a ser inserido
 * @return O sucesso da operação
*/
bool plh_push(pilha_t *, int);

/**
 * Retira um item do topo da pilha
 * @param pilha_t* Pilha de que o valor será removido
 * @param int* Destino para o valor
 * @return O sucesso da operação
*/
bool plh_pop(pilha_t *, int *);

/**
 * Lê o item no topo da pilha
 * @param pilha_t* Pilha de que o valor será removido
 * @param int* Destino para o valor
*/
void plh_topo(pilha_t *, int *);

/**
 * Libera a memória de uma pilha
 * @param pilha_t* A pilha cuja a memória será liberada
*/
void plh_lib(pilha_t *);

#endif