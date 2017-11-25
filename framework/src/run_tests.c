#include <sys/wait.h>
#include <stdlib.h>

#include "libunit.h"
#include "libftasm.h"

int		display_name(char const *name)
{
	ft_putstr(name);
	return (0);
}

int		fork_and_run(t_unit_test *current)
{
	int		pid;
	int		stat_loc;

	pid = 0;
	pid = fork();
	if (pid == 0)
	{
		current->f();

		exit(0);
	}
	else
	{
		if (pid == wait(&stat_loc))
		{
			return (1);
		}
		else
			return (0);
	}
}

int		run_tests(t_unit_test **list)
{
	t_result	result;
	t_unit_test	*tmp;

	ft_bzero((char*)&result, sizeof(t_result));
	tmp = *list;
	while (tmp)
	{
		display_name(tmp->name);
		result.ok += fork_and_run(tmp);
		result.total += 1;
		tmp = tmp->next;
	}
	return (0);
}
