#ifndef ARVORE_H
#define ARVORE_H

#include <stdbool.h>

typedef struct no no_t;
typedef struct arvore arvore_t;

/**
 * Cria uma árvore binária
 * @return A árvore criada
*/
arvore_t *arb_criar(void);

/**
 * Insere um nó na árvore
 * @param arvore_t* Árvore em que o nó será inserido
 * @param int Valor do nó
 * @return O sucesso da operação
*/
bool arb_ins(arvore_t *, int);

/**
 * Insere um nó na árvore
 * @param arvore_t* Árvore de que o nó será removido
 * @param int Valor do nó
 * @return O sucesso da operação
*/
bool arb_rm(arvore_t *, int);

/**
 * Procura um nó na árvore
 * @param arvore_t* Árvore em que o nó será procurado
 * @param int Valor do nó
 * @return Ponteiro para o nó ou NULL
*/
no_t *arb_proc(arvore_t *, int);

/**
 * Calcula a altura de um nó na árvore
 * @param arvore_t* Árvore cuja altura do nó será calculada
 * @param int Valor do nó
 * @return A altura do nó ou -1
*/
int arb_alt(arvore_t *, int);

/**
 * Calcula o tamanho da árvore
 * @param arvore_t* Árvore cujo o tamanho será calculado
 * @return O tamanho da árvore
*/
int arb_tmnh(arvore_t *);

/**
 * Imprime uma árvore
 * @param arvore_t* Árvore que será impressa
*/
void arb_impr(arvore_t *);

/**
 * Libera a memória de uma árvore
 * @param arvore_t* Árvore que será liberada
*/
void arb_lib(arvore_t *);

#endif