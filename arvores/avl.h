#ifndef AVL_H
#define AVL_H

#include "arvorebinaria.h"

typedef struct
{
	ArvoreBi super;
} AVL;

typedef struct
{
	NoA super;
	short balanco;
} NoAVL;


void AVL_construtor(AVL *isto, size_t tmnh_dados);

#endif