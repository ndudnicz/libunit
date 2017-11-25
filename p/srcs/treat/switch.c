/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 13:20:31 by ndudnicz          #+#    #+#             */
/*   Updated: 2016/01/22 10:09:39 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "my_colors.h"
#include <wchar.h>

static int		treat_flag_string(t_flag *flag, va_list ap)
{
	if (flag->conversion == 'c' && flag->modifier[0] == '\0')
		treat_char(flag, va_arg(ap, int));
	else if (flag->conversion == 's' && flag->modifier[0] == '\0')
	{
		if (treat_str(flag, va_arg(ap, char*)) == -1)
			return (-1);
	}
	else if (flag->conversion == 'C' ||
			(flag->conversion == 'c' && flag->modifier[0] == 'l'))
	{
		if (treat_wchar(flag, va_arg(ap, wint_t)) == -1)
			return (-1);
	}
	else if (flag->conversion == 'S' ||
			(flag->conversion == 's' && flag->modifier[0] == 'l'))
	{
		if (treat_wstr(flag, va_arg(ap, wchar_t*)) == -1)
			return (-1);
	}
	return (0);
}

int				treat_flag(t_flag *flag, va_list ap)
{
	if (flag->conversion == '%')
		treat_char(flag, '%');
	else if (ft_strchr("dDi", flag->conversion))
		treat_decimal(flag, va_arg(ap, long long int));
	else if (ft_strchr("oO", flag->conversion))
		treat_octal(flag, va_arg(ap, long long int));
	else if (ft_strchr("xX", flag->conversion))
		treat_hexa(flag, va_arg(ap, long long int));
	else if (ft_strchr("uU", flag->conversion))
		treat_unsigned(flag, va_arg(ap, unsigned long long int));
	else if (flag->conversion == 'p')
		treat_pointer(flag, va_arg(ap, unsigned long int));
	else if (ft_strchr("bB", flag->conversion))
		treat_base(flag, va_arg(ap, long long int), va_arg(ap, int));
	return (treat_flag_string(flag, ap));
}
