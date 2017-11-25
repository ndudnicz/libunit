/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 13:07:31 by ndudnicz          #+#    #+#             */
/*   Updated: 2016/02/23 11:06:00 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "my_colors.h"

static int		ft_va_end(va_list ap)
{
	va_end(ap);
	return (0);
}

static char		*ft_reset_flag(t_flag *flag, int *total)
{
	char	*ptr_fmt;

	*total += flag->total;
	ptr_fmt = flag->p_format;
	reset_flag(flag);
	return (ptr_fmt);
}

static int		ft_sub_printf(char *format, va_list ap)
{
	t_flag		*flag;
	int			total;

	total = 0;
	while (*format)
	{
		if (*format == '{' && *(format + 1) != '{')
			format = treat_color((char*)format);
		else if (*format == '%' && *(format++ + 1) != '%')
		{
			if (!(flag = init_flag()))
				return (ft_free_return(NULL, ERR_MALLOC, -1));
			get_attribut((char*)format, flag);
			if (treat_flag(flag, ap) == -1)
				return (ft_free_return(flag, "", -1));
			format = ft_reset_flag(flag, &total);
		}
		else if (total++ || 1)
			ft_putchar(*format);
		format++;
	}
	return (total);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;

	va_start(ap, format);
	if (valid_format((char*)format) == -1)
		return (-1);
	return (ft_sub_printf((char*)format, ap) + ft_va_end(ap));
}
