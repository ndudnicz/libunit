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
#include "h_01_basic_test_atoi.h"
#include "h_02_basic_test_atoi.h"
#include "h_03_upper_bound_test_atoi.h"
#include "h_04_lower_bound_test_atoi.h"
#include "h_05_basic_test_atoi.h"

int		launcher_atoi(void)
{
	t_unit_test		*list;

	list = NULL;
	ft_putendl("FT_ATOI:");
	load_test(&list, "Basic test 01", &ft_01_basic_test_atoi);
	load_test(&list, "Basic test 02", &ft_02_basic_test_atoi);
	load_test(&list, "Upper bound test 03", &ft_03_upper_bound_test_atoi);
	load_test(&list, "Lower bound test 04", &ft_04_lower_bound_test_atoi);
	load_test(&list, "Basic test 05", &ft_05_basic_test_atoi);
	run_tests(&list);
	free_list(list);
	list = NULL;
	return (0);
}
