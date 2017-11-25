/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 15:53:26 by ndudnicz          #+#    #+#             */
/*   Updated: 2016/01/22 10:12:00 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		treat_p_right(t_flag *flag, unsigned long int number,
		int extend)
{
	char	blank;

	flag->len += 2;
	flag->total = flag->len;
	flag->field_width -= extend;
	blank = (ft_strchr(flag->attribut, '0') && flag->precision == -1) ?
		'0' : ' ';
	flag->total += ft_putnchar(blank, flag->field_width - flag->len);
	ft_putstr("0x");
	flag->total += ft_putnchar('0', extend);
	uld_putbase(number, 16, 0);
}

static void		treat_p_left(t_flag *flag, unsigned long int number,
		int extend)
{
	flag->len += 2;
	flag->total = flag->len;
	flag->field_width -= extend;
	ft_putstr("0x");
	flag->total += ft_putnchar('0', extend);
	uld_putbase(number, 16, 0);
	flag->total += ft_putnchar(' ', flag->field_width - flag->len);
}

void			treat_pointer(t_flag *flag, unsigned long int number)
{
	int		extend;

	flag->len = ft_ulong_numberlen(number, 16);
	extend = (flag->precision - flag->len) > 0 ?
		flag->precision - flag->len : 0;
	if (ft_strchr(flag->attribut, '-'))
		treat_p_left(flag, number, extend);
	else
		treat_p_right(flag, number, extend);
}
