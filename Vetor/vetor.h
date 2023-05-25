#ifndef VECTOR_H
#define VECTOR_H

#include <stdarg.h>
#include <stdbool.h>

typedef struct vetor vetor_t;

/**
 * Cria um vetor vazio
 * @return O vetor que foi criado
*/
vetor_t *vtr_criar();

/**
 * Inicializa um vetor com N items
 * @param int Número de items
 * @param ... Items a serem inseridos
 * @return O vetor que foi criado
*/
vetor_t *vtr_ini(int, ...);

/**
 * Imprime o vetor
 * @param vetor_t* Vetor que será impresso
*/
void vtr_impr(vetor_t *);

/**
 * Desloca uma casa a direita todos os items de vetor->capacidade - 1 até Y
 * @param vetor_t* Vetor que será movido
 * @param int Posição de fim
 * @return Se a operação é valida
*/
static bool vtr_mov_dir(vetor_t *, int);

/**
 * Desloca uma casa a esquerda todos os items a partir de Y até vetor->capacidade - 1
 * @param vetor_t* Vetor que será movido
 * @param int Posição de inicio
 * @return Se a operação é valida
*/
static bool vtr_mov_esq(vetor_t *, int);

/**
 * Expande a capacidade do vetor
 * @param vetor_t* Vetor a ser expandido
*/
static void vtr_exp(vetor_t *);

/**
 * Insere item de valor X no vetor
 * @param vetor_t* Vetor em que o valor será inserido
 * @param int Valor a ser inserido
*/
void vtr_ins(vetor_t *, int);

/**
 * Muda item, para valor X, do vetor na posição Y
 * @param vetor_t* Vetor em que o valor será modificado
 * @param int Valor novo
 * @param int Posição modificada
 * @return O sucesso da operação
*/
bool vtr_mod(vetor_t *v, int, int);

/**
 * Procura um item de valor X no vetor
 * @param vetor_t* Vetor em que o item será achado
 * @param int Valor do item a ser achado
 * @return A posição em que o valor foi encontrado, -1 caso não achado
*/
int vtr_proc(vetor_t *, int);

/**
 * Remove item de valor X no vetor
 * @param vetor_t* Vetor em que o item será removido
 * @param int Valor do item a ser removido
 * @return O sucesso da operação
*/
bool vtr_rm(vetor_t *, int);

/**
 * Libera a memória do vetor
 * @param vetor_t* Vetor a ser liberado
 * @return O sucesso da operação
*/
void vtr_lib(vetor_t *);

#endif