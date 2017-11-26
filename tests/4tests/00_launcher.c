/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 11:06:26 by ndudnicz          #+#    #+#             */
/*   Updated: 2017/11/25 11:06:29 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libunit.h"
#include "h_01_basic_test.h"
#include "h_02_segv_test.h"
#include "h_03_buse_test.h"
#include "h_04_ko_test.h"
#include "libft.h"

int		launcher(void)
{
	t_unit_test		*list;
	int				ret;

	list = NULL;
	ft_putendl("4 TESTS:");
	load_test(&list, "Basic test", &basic_test);
	load_test(&list, "segv test", &segv_test);
	load_test(&list, "buse test", &buse_test);
	load_test(&list, "ko test", &ko_test);
	ret = run_tests(&list);
	free_list(list);
	list = NULL;
	return (ret);
}
