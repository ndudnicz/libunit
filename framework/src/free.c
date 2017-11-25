#include <stdlib.h>

#include "libunit.h"

void	free_list(t_unit_test *list)
{
	t_unit_test		*tmp;

	while (list)
	{
		tmp = list->next;
		free(list->name);
		free(list);
		list = tmp;
	}
}
