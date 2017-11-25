/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 11:06:41 by ndudnicz          #+#    #+#             */
/*   Updated: 2017/11/25 11:06:42 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libftasm.h"

int		segv_test(void)
{
	char	d[4];

	if (!memcmp(ft_memset(d, 0, 40000), memset(d, 0, 4), 4))
		return (0);
	else
		return (-1);
}
