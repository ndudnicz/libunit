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
#include "h_01_basic_test_isdigit.h"
#include "h_02_basic_test_isdigit.h"
#include "h_03_basic_test_isdigit.h"
#include "h_04_basic_test_isdigit.h"

int		launcher_isdigit(void)
{
	t_unit_test		*list;
	int				ret;

	list = NULL;
	ft_putendl("FT_ISDIGIT:");
	load_test(&list, "Basic test 01", &ft_01_basic_test_isdigit);
	load_test(&list, "Basic test 02", &ft_02_basic_test_isdigit);
	load_test(&list, "Basic test 03", &ft_03_basic_test_isdigit);
	load_test(&list, "Basic test 04", &ft_04_basic_test_isdigit);
	ret = run_tests(&list);
	free_list(list);
	list = NULL;
	return (ret);
}
