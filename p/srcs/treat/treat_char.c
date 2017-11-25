/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 18:11:16 by ndudnicz          #+#    #+#             */
/*   Updated: 2016/01/21 13:48:48 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	treat_char(t_flag *flag, int c)
{
	char	blank;

	blank = flag->conversion == '%' && ft_strchr(flag->attribut, '0') ?
		'0' : ' ';
	flag->total++;
	if (ft_strchr(flag->attribut, '-'))
	{
		ft_putchar(c);
		flag->total += ft_putnchar(' ', flag->field_width - 1);
	}
	else
	{
		flag->total += ft_putnchar(blank, flag->field_width - 1);
		ft_putchar(c);
	}
}
