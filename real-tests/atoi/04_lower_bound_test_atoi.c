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

#include <stdlib.h>
#include <limits.h>

#include "libftasm.h"

int			ft_04_lower_bound_test_atoi(void)
{
	if (ft_atoi("-2147483648") == atoi("-2147483648"))
		return (0);
	else
		return (-1);
}
