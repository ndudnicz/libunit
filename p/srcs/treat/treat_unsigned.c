/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 15:53:26 by ndudnicz          #+#    #+#             */
/*   Updated: 2016/02/05 13:39:44 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			treat_u_right(t_flag *flag, unsigned long long int number,
		int extend, void (*f)(long long, int))
{
	char	blank;

	flag->field_width -= extend;
	blank = (ft_strchr(flag->attribut, '0') && flag->precision == -1) ?
		'0' : ' ';
	flag->total = flag->len;
	flag->total += ft_putnchar(blank, flag->field_width - flag->len);
	flag->total += ft_putnchar('0', extend);
	(*f)(number, 10);
}

static void			treat_u_left(t_flag *flag, unsigned long long int number,
		int extend, void (*f)(long long, int))
{
	flag->field_width -= extend;
	flag->total = flag->len;
	flag->total += ft_putnchar('0', extend);
	(*f)(number, 10);
	flag->total += ft_putnchar(' ', flag->field_width - flag->len);
}

static void			switch_right(t_flag *flag, unsigned long long int number,
		int extend)
{
	void	(*f[3]);

	f[0] = &ulld_putbase;
	f[1] = &z_putbase;
	f[2] = &uj_putbase;
	if (flag->conversion == 'U')
		treat_u_right(flag, (unsigned long int)number, extend, f[0]);
	else if (flag->modifier[0] == 'h' && flag->modifier[1] == 'h')
		treat_u_right(flag, (unsigned char)number, extend, f[0]);
	else if (flag->modifier[0] == 'h' && flag->modifier[1] == '\0')
		treat_u_right(flag, (unsigned short)number, extend, f[0]);
	else if (flag->modifier[0] == 0)
		treat_u_right(flag, (unsigned int)number, extend, f[0]);
	else if (flag->modifier[0] == 'l' && flag->modifier[1] == 0)
		treat_u_right(flag, (unsigned long int)number, extend, f[0]);
	else if (flag->modifier[1] == 'l')
		treat_u_right(flag, number, extend, f[0]);
	else if (flag->modifier[0] == 'z')
		treat_u_right(flag, (size_t)number, extend, f[1]);
	else if (flag->modifier[0] == 'j')
		treat_u_right(flag, (uintmax_t)number, extend, f[2]);
}

static void			switch_left(t_flag *flag, unsigned long long int number,
		int extend)
{
	void	(*f[3]);

	f[0] = &ulld_putbase;
	f[1] = &z_putbase;
	f[2] = &uj_putbase;
	if (flag->conversion == 'U')
		treat_u_left(flag, (unsigned long int)number, extend, f[0]);
	else if (flag->modifier[0] == 'h' && flag->modifier[1] == 'h')
		treat_u_left(flag, (unsigned char)number, extend, f[0]);
	else if (flag->modifier[0] == 'h' && flag->modifier[1] == '\0')
		treat_u_left(flag, (unsigned short)number, extend, f[0]);
	else if (flag->modifier[0] == 0)
		treat_u_left(flag, (unsigned int)number, extend, f[0]);
	else if (flag->modifier[0] == 'l' && flag->modifier[1] == 0)
		treat_u_left(flag, (unsigned long int)number, extend, f[0]);
	else if (flag->modifier[1] == 'l')
		treat_u_left(flag, number, extend, f[0]);
	else if (flag->modifier[0] == 'z')
		treat_u_left(flag, (size_t)number, extend, f[1]);
	else if (flag->modifier[0] == 'j')
		treat_u_left(flag, (uintmax_t)number, extend, f[2]);
}

void				treat_unsigned(t_flag *flag, unsigned long long int number)
{
	int		extend;

	if (flag->conversion == 'U')
		flag->len = ft_ulong_numberlen((unsigned long int)number, 10);
	else if (flag->modifier[0] == 'h' && flag->modifier[1] == 'h')
		flag->len = ft_ulong_numberlen((unsigned char)number, 10);
	else if (flag->modifier[0] == 'h' && flag->modifier[1] == '\0')
		flag->len = ft_ulong_numberlen((unsigned short)number, 10);
	else if (flag->modifier[0] == '\0')
		flag->len = ft_ulong_numberlen((unsigned int)number, 10);
	else if (flag->modifier[0] == 'l' && flag->modifier[1] == 0)
		flag->len = ft_ulong_numberlen((unsigned long int)number, 10);
	else if (flag->modifier[1] == 'l')
		flag->len = ft_ulong_numberlen(number, 10);
	else if (flag->modifier[0] == 'z')
		flag->len = ft_ulong_numberlen((size_t)number, 10);
	else if (flag->modifier[0] == 'j')
		flag->len = ft_ulong_numberlen((uintmax_t)number, 10);
	extend = (flag->precision - flag->len) > 0 ?
		flag->precision - flag->len : 0;
	if (ft_strchr(flag->attribut, '-'))
		switch_left(flag, number, extend);
	else
		switch_right(flag, number, extend);
}
