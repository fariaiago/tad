#ifndef PILHA_H
#define PILHA_H

#include <stdbool.h>

typedef struct fila fila_t;

/**
 * Cria uma fila
 * @return A fila criada
*/
fila_t *fla_criar(void);

/**
 * Inicializa uma fila
 * @param int Número de items
 * @param ... Items
 * @return A fila criada
*/
fila_t *fla_ini(int, ...);

/**
 * Imprime uma fila
 * @param fila_t* Pilha que será impressa
*/
void fla_impr(fila_t *);

/**
 * Insere um item ao topo da fila
 * @param fila_t* Pilha em que o valor será inserido
 * @param int O valor a ser inserido
 * @return O sucesso da operação
*/
bool fla_enqueue(fila_t *, int);

/**
 * Retira um item do topo da fila
 * @param fila_t* Pilha de que o valor será removido
 * @param int* Destino para o valor
 * @return O sucesso da operação
*/
bool fla_dequeue(fila_t *, int *);

/**
 * Lê o item no topo da fila
 * @param fila_t* Pilha de que o valor será removido
 * @param int* Destino para o valor
*/
void fla_topo(fila_t *, int *);

/**
 * Libera a memória de uma fila
 * @param fila_t* A fila cuja a memória será liberada
*/
void fla_lib(fila_t *);

#endif