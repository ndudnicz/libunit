/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher_bzero.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 18:22:39 by ndudnicz          #+#    #+#             */
/*   Updated: 2017/11/25 18:22:40 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libunit.h"
#include "h_01_basic_test_bzero.h"

int		launcher_bzero(void)
{
	t_unit_test		*list;
	int				ret;

	list = NULL;
	ft_putendl("FT_BZERO:");
	load_test(&list, "Basic test 01", &basic_test_bzero);
	ret = run_tests(&list);
	free_list(list);
	list = NULL;
	return (ret);
}
