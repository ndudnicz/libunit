/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 15:23:53 by ndudnicz          #+#    #+#             */
/*   Updated: 2016/01/20 11:53:30 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		treat_2_right(t_flag *flag, unsigned long long int number,
		int base, int extend)
{
	char	blank;
	char	upper;

	upper = flag->conversion == 'B' ? 1 : 0;
	blank = ft_strchr(flag->attribut, '0') ? '0' : ' ';
	flag->field_width -= extend;
	flag->total += ft_putnchar(blank, flag->field_width - flag->len);
	flag->total += ft_putnchar('0', extend);
	ulld_putbase(number, base, upper);
}

static void		treat_2_left(t_flag *flag, unsigned long long int number,
		int base, int extend)
{
	char	upper;

	upper = flag->conversion == 'B' ? 1 : 0;
	flag->field_width -= extend;
	flag->total += ft_putnchar('0', extend);
	ulld_putbase(number, base, upper);
	flag->total += ft_putnchar(' ', flag->field_width - flag->len);
}

static void		switch_right(t_flag *flag, unsigned long long int number,
		int base, int extend)
{
	if (flag->modifier[0] == 'h' && flag->modifier[1] == 'h')
		treat_2_right(flag, (unsigned char)number, base, extend);
	else if (flag->modifier[0] == 'h' && flag->modifier[1] == '\0')
		treat_2_right(flag, (unsigned short)number, base, extend);
	else if (flag->modifier[0] == '\0')
		treat_2_right(flag, (unsigned int)number, base, extend);
	else if (flag->modifier[0] == 'l' && flag->modifier[1] == 0)
		treat_2_right(flag, (unsigned long int)number, base, extend);
	else if (flag->modifier[1] == 'l')
		treat_2_right(flag, number, base, extend);
}

static void		switch_left(t_flag *flag, unsigned long long int number,
		int base, int extend)
{
	if (flag->modifier[0] == 'h' && flag->modifier[1] == 'h')
		treat_2_left(flag, (unsigned char)number, base, extend);
	else if (flag->modifier[0] == 'h' && flag->modifier[1] == '\0')
		treat_2_left(flag, (unsigned short)number, base, extend);
	else if (flag->modifier[0] == '\0')
		treat_2_left(flag, (unsigned int)number, base, extend);
	else if (flag->modifier[0] == 'l' && flag->modifier[1] == 0)
		treat_2_left(flag, (unsigned long int)number, base, extend);
	else if (flag->modifier[1] == 'l')
		treat_2_left(flag, number, base, extend);
}

void			treat_base(t_flag *flag, long long int number, int base)
{
	int		extend;

	if (flag->modifier[0] == 'h' && flag->modifier[1] == 'h')
		flag->len = ft_ulong_numberlen((unsigned char)number, base);
	else if (flag->modifier[0] == 'h' && flag->modifier[1] == '\0')
		flag->len = ft_ulong_numberlen((unsigned short)number, base);
	else if (flag->modifier[0] == '\0')
		flag->len = ft_ulong_numberlen((unsigned int)number, base);
	else if (flag->modifier[0] == 'l' && flag->modifier[1] == '\0')
		flag->len = ft_ulong_numberlen((unsigned long int)number, base);
	else if (flag->modifier[1] == 'l')
		flag->len = ft_ulong_numberlen((unsigned long long int)number, base);
	flag->total = flag->len;
	extend = (flag->precision - flag->len) > 0 ?
		flag->precision - flag->len : 0;
	if (ft_strchr(flag->attribut, '-'))
		switch_left(flag, number, base, extend);
	else
		switch_right(flag, number, base, extend);
}
