/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnwstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 16:52:32 by ndudnicz          #+#    #+#             */
/*   Updated: 2016/01/18 17:58:36 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include "ft_printf.h"

int		ft_putnwstr(wchar_t *wstr, int n)
{
	int		i;
	int		total;

	i = 0;
	total = 0;
	while (wstr[i] && i < n)
	{
		total += ft_putwchar(wstr[i]);
		i++;
	}
	return (total);
}
