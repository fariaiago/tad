#include "lista.h"
#include <assert.h>

int main(void)
{
	int vlrs[] = {0, 5, 3, 2, 9, 11, 45, 4, 1, 7};
	lista_t *lst = lst_criar();
	lst_impr(lst);
	for (int i = 0; i < 10; i++)
		assert(lst_ins(lst, vlrs[i]) == true);
	assert(lst_mod(lst, 45, 32) == true);
	assert(lst_rm(lst, 3) == true);
	assert(lst_rm(lst, 6) == false);
	lst_impr(lst);
	lst_lib(lst);
	return 0;
}