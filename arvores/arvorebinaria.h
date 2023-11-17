#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

#include <stdlib.h>
#include <stdbool.h>

/**
 * Nó de uma árvore
*/
struct NoArvore
{
	struct NoArvore *pai;
	struct NoArvore *esq;
	struct NoArvore *dir;
	void *info;
} typedef NoA;

struct ArvoreBiVtbl;

struct ArvoreBinaria
{
	const struct ArvoreBiVtbl *vtblptr;
	NoA *raiz;
	size_t tmnh_dados;
} typedef ArvoreBi;

struct ArvoreBiVtbl
{
//	struct ArvoreBiVtbl *super;
	bool (*inserir)(ArvoreBi *isto, void *vlr);
	bool (*remover)(ArvoreBi *isto, void *vlr);
//	void (*destruir)(ArvoreBi *isto);
};

/**
 * Cria uma árvore binária
 * @return A árvore criada
*/
void ArvoreBi_construtor(ArvoreBi *isto);

/**
 * Insere um nó na árvore
 * @param ArvoreBi* Árvore em que o nó será inserido
 * @param int Valor do nó
 * @return O sucesso da operação
*/
bool ArvoreBi_inserir(ArvoreBi *isto, void *vlr);

/**
 * Insere um nó na árvore
 * @param ArvoreBi* Árvore de que o nó será removido
 * @param int Valor do nó
 * @return O sucesso da operação
*/
bool ArvoreBi_remover(ArvoreBi *isto, void *vlr);

/**
 * Procura um nó na árvore
 * @param ArvoreBi* Árvore em que o nó será procurado
 * @param int Valor do nó
 * @return Ponteiro para o nó ou NULL
*/
NoA *ArvoreBi_procurar(ArvoreBi *isto, void *vlr);

/**
 * Encontra o mínimo na subárvore
 * @param NoA*no Raíz da subárvore
 * @return Mínimo da subárvore
*/
NoA *ArvoreBi_minimo(NoA *no);

/**
 * Enconta a altura da subárvore com raíz NoA nó
 * @param NoA*no Nó raíz da subárvore
 * @return A altura do nó
*/
int NoA_altura(NoA *no);

/**
 * Imprime uma árvore
 * @param ArvoreBi* Árvore que será impressa
*/
void ArvoreBi_imprimir(ArvoreBi *isto);

/**
 * Libera a memória de uma árvore
 * @param ArvoreBi* Árvore que será liberada
*/
void ArvoreBi_destruir(ArvoreBi *isto);

/**
 * Libera a memória de um nó
 * @param NoA* Nó que será liberado
*/
void NoA_destruir(NoA *no);

#endif