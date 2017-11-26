/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 16:18:20 by ndudnicz          #+#    #+#             */
/*   Updated: 2017/11/25 16:18:28 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>

#include "libunit.h"
#include "libftasm.h"
#include "libftprintf.h"

static int		display_name(char const *name)
{
	ft_printf("\t%20s: [", name);
	return (0);
}

static int		display_status(int stat_loc)
{
	if (WIFEXITED(stat_loc))
	{
		if (WEXITSTATUS(stat_loc))
			return (!ft_putstr("\033[91mKO\033[39m]\n"));
		else
			return (1 && ft_putstr("\033[92mOK\033[39m]\n"));
	}
	else if (WIFSIGNALED(stat_loc))
	{
		if (WTERMSIG(stat_loc) == SIGSEGV)
			return (!ft_putstr("\033[91mSEGV\033[39m]\n"));
		else if (WTERMSIG(stat_loc) == SIGBUS)
			return (!ft_putstr("\033[91mBUSE\033[39m]\n"));
		else
			return (!ft_putstr("\033[91m...\033[39m]\n"));
	}
	else
	{
		ft_putstr("\033[91mnope\033[39m]\n");
		return (0);
	}
}

static int		fork_and_run(t_unit_test *current)
{
	int		pid;
	int		stat_loc;

	pid = 0;
	pid = fork();
	if (pid == 0)
		exit(current->f());
	else
	{
		if (pid == wait(&stat_loc))
		{
			return (display_status(stat_loc));
		}
		else
			return (0);
	}
}

int				run_tests(t_unit_test **list)
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
	ft_printf("%u/%u tests checked\n", result.ok, result.total);
	return (0);
}
