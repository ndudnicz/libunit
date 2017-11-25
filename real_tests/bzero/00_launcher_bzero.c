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
#include "01_basic_test_bzero.h"

int		launcher_bzero(void)
{
	t_unit_test		*list;

	ft_putendl("FT_BZERO:");
	load_test(&list, "Basic test", &basic_test_bzero);
	return (run_tests(&list));
}
