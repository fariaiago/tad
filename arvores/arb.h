#ifndef ARB_H
#define ARB_H

#include "arvorebinaria.h"

#define COR_PRETO 0
#define COR_VERMELHO 1

typedef struct
{
	ArvoreBi super;
} ARB;

typedef struct
{
	NoA super;
	bool cor;
} NoARB;

void ARB_construtor(ARB *isto, size_t tmnh_dados);

#endif