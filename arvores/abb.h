#ifndef ABB_H
#define ABB_H

#include "arvorebinaria.h"

typedef struct
{
	ArvoreBi super;
	size_t tmnh_dados;
} ABB;

void ABB_construtor(ABB *abb, size_t tmnh_dados);

#endif