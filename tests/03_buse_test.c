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

int		buse_test(void)
{
	if (!memcmp(ft_memset("toto", 0, 4), memset("toto", 0, 4), 4))
		return (0);
	else
		return (-1);
}
