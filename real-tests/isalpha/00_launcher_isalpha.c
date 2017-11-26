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
#include "h_01_basic_test_isalpha.h"
#include "h_02_basic_test_isalpha.h"
#include "h_03_basic_test_isalpha.h"
#include "h_04_basic_test_isalpha.h"
#include "h_05_basic_test_isalpha.h"
#include "h_06_basic_test_isalpha.h"
#include "h_07_basic_test_isalpha.h"
#include "h_08_basic_test_isalpha.h"

int		launcher_isalpha(void)
{
	t_unit_test		*list;

	list = NULL;
	ft_putendl("FT_ISALPHA:");
	load_test(&list, "Basic test 01", &ft_01_basic_test_isalpha);
	load_test(&list, "Basic test 02", &ft_02_basic_test_isalpha);
	load_test(&list, "Basic test 03", &ft_03_basic_test_isalpha);
	load_test(&list, "Basic test 04", &ft_04_basic_test_isalpha);
	load_test(&list, "Basic test 05", &ft_05_basic_test_isalpha);
	load_test(&list, "Basic test 06", &ft_06_basic_test_isalpha);
	load_test(&list, "Basic test 07", &ft_07_basic_test_isalpha);
	load_test(&list, "Basic test 08", &ft_08_basic_test_isalpha);
	run_tests(&list);
	free_list(list);
	list = NULL;
	return (0);
}
