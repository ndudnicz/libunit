/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_wstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 10:01:00 by ndudnicz          #+#    #+#             */
/*   Updated: 2016/01/18 17:07:50 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include "ft_printf.h"

int		valid_wstr(wchar_t *wstr)
{
	while (wstr && *wstr)
	{
		if (ft_long_numberlen(*wstr, 2) > 24 || *wstr < 0)
			return (-1);
		wstr++;
	}
	return (0);
}
