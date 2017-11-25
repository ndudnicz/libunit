/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 16:49:26 by ndudnicz          #+#    #+#             */
/*   Updated: 2016/01/18 16:51:03 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include "ft_printf.h"

int		ft_wstrlen(wchar_t *wstr)
{
	int		i;
	int		total;

	i = 0;
	total = 0;
	while (wstr[i])
	{
		if (ft_long_numberlen(wstr[i], 2) < 8)
			total += 1;
		else if (ft_long_numberlen(wstr[i], 2) < 12)
			total += 2;
		else if (ft_long_numberlen(wstr[i], 2) < 17)
			total += 3;
		else
			total += 1;
		i++;
	}
	return (total);
}
