#ifndef ABB_H
#define ABB_H

#include "arvorebinaria.h"

typedef struct
{
	ArvoreBi super;
} ABB;

void ABB_construtor(ABB *abb, size_t tmnh_dados);

#endif