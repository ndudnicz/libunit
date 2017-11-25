#include <stdlib.h>

#include "libunit.h"
#include "libftasm.h"
#include "libft.h"//

static int	init_new_test(t_unit_test *new, char const *name, int (*f)(void))
{
	ft_bzero((char*)new, sizeof(t_unit_test));
	new->f = f;
	new->last = new;
	if (!(new->name = ft_strdup(name)))
		return (1);
	else
		return (0);
}

int			load_test(t_unit_test **list, char const *name , int (*f)(void))
{
	t_unit_test		*new;

	if (!(new = (t_unit_test*)malloc(sizeof(t_unit_test))) ||
	init_new_test(new, name, f))
		return (1);
	else
	{
		if (!(*list))
		{
			*list = new;

		}
		else
		{
			(*list)->last->next = new;
			(*list)->last = new;
		}
		return (0);
	}
}
