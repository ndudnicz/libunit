/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 15:53:26 by ndudnicz          #+#    #+#             */
/*   Updated: 2016/02/05 13:34:38 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		treat_10_right(t_flag *flag, long long int number, int extend,
		void (*f)(long long int, int))
{
	char	blank;
	char	sign;

	sign = number < 0 ? '-' : '+';
	flag->total = flag->len;
	blank = (ft_strchr(flag->attribut, '0') && flag->precision == -1) ?
		'0' : ' ';
	flag->field_width -= ft_strchr(flag->attribut, '+') ||
		ft_strchr(flag->attribut, ' ') || number < 0 ? extend + 1 : extend;
	if (blank == ' ')
		flag->total += ft_putnchar(blank, flag->field_width - flag->len);
	if ((ft_strchr(flag->attribut, '+') || ft_strchr(flag->attribut, ' ')) &&
			sign != '-')
	{
		ft_strchr(flag->attribut, '+') ? ft_putchar(sign) : ft_putchar(' ');
		flag->total++;
	}
	else if (sign == '-')
		ft_putchar(sign);
	flag->total = sign == '-' ? flag->total + 1 : flag->total;
	if (blank == '0')
		flag->total += ft_putnchar(blank, flag->field_width - flag->len);
	flag->total += ft_putnchar('0', extend);
	if (flag->len > 0)
		number < 0 ? (*f)(-number, 10) : (*f)(number, 10);
}

static void		treat_10_left(t_flag *flag, long long int number, int extend,
		void (*f)(long long int, int))
{
	char	sign;

	sign = number < 0 ? '-' : '+';
	flag->total = flag->len;
	flag->field_width -= ft_strchr(flag->attribut, '+') ||
		ft_strchr(flag->attribut, ' ') || number < 0 ? extend + 1 : extend;
	if ((ft_strchr(flag->attribut, '+') || ft_strchr(flag->attribut, ' ')) &&
			sign != '-')
	{
		ft_strchr(flag->attribut, '+') ? ft_putchar(sign) : ft_putchar(' ');
		flag->total++;
	}
	else if (sign == '-')
		ft_putchar(sign);
	flag->total = sign == '-' ? flag->total + 1 : flag->total;
	flag->total += ft_putnchar('0', extend);
	if (flag->len > 0)
		number < 0 ? (*f)(-number, 10) : (*f)(number, 10);
	flag->total += ft_putnchar(' ', flag->field_width - flag->len);
}

static void		switch_right(t_flag *flag, long long int number, int extend)
{
	void	(*f[3]);

	f[0] = &lld_putbase;
	f[1] = &z_putbase;
	f[2] = &j_putbase;
	if (flag->conversion == 'D')
		treat_10_right(flag, (long int)number, extend, f[0]);
	else if (flag->modifier[0] == 'h' && flag->modifier[1] == 'h')
		treat_10_right(flag, (char)number, extend, f[0]);
	else if (flag->modifier[0] == 'h' && flag->modifier[1] == '\0')
		treat_10_right(flag, (short)number, extend, f[0]);
	else if (flag->modifier[0] == '\0')
		treat_10_right(flag, (int)number, extend, f[0]);
	else if (flag->modifier[0] == 'l' && flag->modifier[1] == 0)
		treat_10_right(flag, (long int)number, extend, f[0]);
	else if (flag->modifier[1] == 'l')
		treat_10_right(flag, number, extend, f[0]);
	else if (flag->modifier[0] == 'z')
		treat_10_right(flag, (size_t)number, extend, f[1]);
	else if (flag->modifier[0] == 'j')
		treat_10_right(flag, (intmax_t)number, extend, f[2]);
}

static void		switch_left(t_flag *flag, long long int number, int extend)
{
	void	(*f[3]);

	f[0] = &lld_putbase;
	f[1] = &z_putbase;
	f[2] = &j_putbase;
	if (flag->conversion == 'D')
		treat_10_left(flag, (long int)number, extend, f[0]);
	else if (flag->modifier[0] == 'h' && flag->modifier[1] == 'h')
		treat_10_left(flag, (char)number, extend, f[0]);
	else if (flag->modifier[0] == 'h' && flag->modifier[1] == '\0')
		treat_10_left(flag, (short)number, extend, f[0]);
	else if (flag->modifier[0] == '\0')
		treat_10_left(flag, (int)number, extend, f[0]);
	else if (flag->modifier[0] == 'l' && flag->modifier[1] == 0)
		treat_10_left(flag, (long int)number, extend, f[0]);
	else if (flag->modifier[1] == 'l')
		treat_10_left(flag, number, extend, f[0]);
	else if (flag->modifier[0] == 'z')
		treat_10_left(flag, (size_t)number, extend, f[1]);
	else if (flag->modifier[0] == 'j')
		treat_10_left(flag, (intmax_t)number, extend, f[2]);
}

void			treat_decimal(t_flag *flag, long long int number)
{
	int		extend;

	if (flag->conversion == 'D')
		flag->len = ft_long_numberlen((long int)number, 10);
	else if (flag->modifier[0] == 'h' && flag->modifier[1] == 'h')
		flag->len = ft_long_numberlen((char)number, 10);
	else if (flag->modifier[0] == 'h' && flag->modifier[1] == '\0')
		flag->len = ft_long_numberlen((short)number, 10);
	else if (flag->modifier[0] == '\0')
		flag->len = ft_long_numberlen((int)number, 10);
	else if (flag->modifier[0] == 'l' && flag->modifier[1] == 0)
		flag->len = ft_long_numberlen((long int)number, 10);
	else if (flag->modifier[1] == 'l')
		flag->len = ft_long_numberlen(number, 10);
	else if (flag->modifier[0] == 'z')
		flag->len = ft_long_numberlen((size_t)number, 10);
	else if (flag->modifier[0] == 'j')
		flag->len = ft_long_numberlen((intmax_t)number, 10);
	flag->len = (flag->precision == 0 && number == 0) ? 0 : flag->len;
	extend = (flag->precision - flag->len) > 0 ?
		flag->precision - flag->len : 0;
	if (ft_strchr(flag->attribut, '-'))
		switch_left(flag, number, extend);
	else
		switch_right(flag, number, extend);
}
