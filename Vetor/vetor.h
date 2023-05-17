#ifndef VECTOR_H
#define VECTOR_H

#include <stdbool.h>

typedef struct vetor tvetor;

/**
 * Inicializa um vetor
 * @return O vetor que foi criado
*/
tvetor *vetor_iniciar();

/**
 * Inicializa um vetor com X items
 * @param int Número de items
 * @param ... Items a serem inseridos
 * @return O vetor que foi criado
*/
tvetor *vetor_iniciarr(int, ...);

/**
 * Imprime o vetor
 * @param tvetor* Vetor que será impresso
*/
void vetor_imprimir(tvetor *);

/**
 * Insere item de valor X ao fim do vetor
 * @param tvetor* Vetor em que o valor será inserido
 * @param int Valor a ser inserido
*/
void vetor_inserir(tvetor *, int);

/**
 * Muda item, para valor X, do vetor na posição Y
 * @param tvetor* Vetor em que o valor será modificado
 * @param int Valor novo
 * @param int Posição modificada
 * @return O sucesso da operação
*/
bool vetor_modificar(tvetor *, int, int);

/**
 * Acha item de valor X do vetor
 * @param tvetor* Vetor em que o item será achado
 * @param int Valor do item a ser achado
 * @return A posição em que o valor foi encontrado, -1 caso não fora
*/
int vetor_achar(tvetor *, int);

/**
 * Move todos os items a partir de X o offset Y
 * @param tvetor* Vetor que será movido
 * @param int Posição de inicio
 * @param int Offset
 * @return O sucesso da operação
*/
bool vetor_mover(tvetor *, int, int);

/**
 * Remove item de valor X do vetor
 * @param tvetor* Vetor em que o item será removido
 * @param int Valor do item a ser removido
 * @return O sucesso da operação
*/
bool vetor_remover(tvetor *, int);

/**
 * Libera a memória do vetor
 * @param tvetor* Vetor a ser liberado
 * @return O sucesso da operação
*/
void vetor_liberar(tvetor *);

#endif