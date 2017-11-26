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
#include <ctype.h>

#include "libftasm.h"

int			ft_01_basic_test_isalpha(void)
{
	if (ft_isalpha(64) == isalpha(64))
		return (0);
	else
		return (-1);
}
