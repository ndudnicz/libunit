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

int			basic_test_bzero(void)
{
	char const	*s1 = ft_strdup("coucou");
	char const	*s2 = ft_strdup(s1);

	bzero((char*)s1, 6);
	ft_bzero((char*)s2, 6);
	if (!memcmp(s1, s2, 6))
		return (0);
	else
		return (-1);
}
