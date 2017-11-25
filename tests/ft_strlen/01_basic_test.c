/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test_ft_strlen.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 11:06:41 by ndudnicz          #+#    #+#             */
/*   Updated: 2017/11/25 11:06:42 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libftasm.h"

int		basic_test(void)
{
	char const	*s = "toto";
	if (strlen(s) == ft_strlen(s))
		return (0);
	else
		return (-1);
}
