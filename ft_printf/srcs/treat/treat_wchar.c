/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_wchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 14:46:17 by ndudnicz          #+#    #+#             */
/*   Updated: 2016/01/20 09:34:31 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wchar.h>
#include <unistd.h>

int				treat_wchar(t_flag *flag, wint_t wc)
{
	int		number_len;

	if ((number_len = ft_long_numberlen(wc, 2)) > 24)
		return (-1);
	if (ft_strchr(flag->attribut, '-'))
	{
		flag->total += ft_putwchar(wc);
		flag->total += ft_putnchar(' ', flag->field_width - 1);
	}
	else
	{
		flag->total += ft_putnchar(' ', flag->field_width - 1);
		flag->total += ft_putwchar(wc);
	}
	return (0);
}
