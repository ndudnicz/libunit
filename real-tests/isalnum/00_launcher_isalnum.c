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
#include "h_01_basic_test_isalnum.h"
#include "h_02_basic_test_isalnum.h"
#include "h_03_basic_test_isalnum.h"
#include "h_04_basic_test_isalnum.h"
#include "h_05_basic_test_isalnum.h"
#include "h_06_basic_test_isalnum.h"
#include "h_07_basic_test_isalnum.h"
#include "h_08_basic_test_isalnum.h"
#include "h_09_basic_test_isalnum.h"
#include "h_10_basic_test_isalnum.h"
#include "h_11_basic_test_isalnum.h"

int		launcher_isalnum(void)
{
	t_unit_test		*list;
	int				ret;

	list = NULL;
	ft_putendl("FT_ISALNUM:");
	load_test(&list, "Basic test 01", &ft_01_basic_test_isalnum);
	load_test(&list, "Basic test 02", &ft_02_basic_test_isalnum);
	load_test(&list, "Basic test 03", &ft_03_basic_test_isalnum);
	load_test(&list, "Basic test 04", &ft_04_basic_test_isalnum);
	load_test(&list, "Basic test 05", &ft_05_basic_test_isalnum);
	load_test(&list, "Basic test 06", &ft_06_basic_test_isalnum);
	load_test(&list, "Basic test 07", &ft_07_basic_test_isalnum);
	load_test(&list, "Basic test 08", &ft_08_basic_test_isalnum);
	load_test(&list, "Basic test 09", &ft_09_basic_test_isalnum);
	load_test(&list, "Basic test 10", &ft_10_basic_test_isalnum);
	load_test(&list, "Basic test 11", &ft_11_basic_test_isalnum);
	ret = run_tests(&list);
	free_list(list);
	list = NULL;
	return (ret);
}
