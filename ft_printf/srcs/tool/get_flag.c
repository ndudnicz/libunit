/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 11:48:17 by ndudnicz          #+#    #+#             */
/*   Updated: 2016/01/21 13:16:47 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		get_conversion(char *fmt, t_flag *flag)
{
	if (flag->conversion == 0 && !(ft_strchr("sSpdDioOuUxXcCbB%", *fmt)))
		ft_free_exit(flag, ERR_BADFLAG);
	else
		flag->conversion = *fmt;
	flag_is_valid(flag);
	flag->p_format = fmt;
	return (0);
}

static int		get_modifier(char *fmt, t_flag *flag)
{
	if (!ft_strchr("hlzj", *fmt))
		return (get_conversion(fmt, flag));
	else
	{
		if (ft_strchr("hl", *fmt) && ft_strchr("hl", *(fmt + 1)))
		{
			flag->modifier[0] = *fmt;
			flag->modifier[1] = *(fmt + 1);
			if (flag->modifier[0] != flag->modifier[1])
				ft_free_exit(flag, ERR_BADFLAG);
			return (get_conversion(fmt + 2, flag));
		}
		else
		{
			flag->modifier[0] = *fmt;
			return (get_conversion(fmt + 1, flag));
		}
	}
}

static int		get_precision(char *fmt, t_flag *flag)
{
	if (*fmt != '.')
		return (get_modifier(fmt, flag));
	else if (*fmt == '.' && !ft_isdigit(*(fmt + 1)))
	{
		flag->precision = 0;
		return (get_modifier(fmt + 1, flag));
	}
	else
	{
		if (ft_atoi(fmt + 1) >= 0)
			flag->precision = ft_atoi(fmt + 1);
		else
			fmt++;
		fmt++;
		while (ft_isdigit(*fmt))
			fmt++;
		return (get_modifier(fmt, flag));
	}
}

static int		get_field_width(char *fmt, t_flag *flag)
{
	flag->field_width = ft_atoi(fmt);
	while (ft_isdigit(*fmt))
		fmt++;
	return (get_precision(fmt, flag));
}

int				get_attribut(char *fmt, t_flag *flag)
{
	while (ft_strchr("#0-+ ", *fmt))
	{
		if (!ft_strchr(flag->attribut, *fmt))
			flag->attribut[ft_strlen(flag->attribut)] = *fmt;
		fmt++;
	}
	return (get_field_width(fmt, flag));
}
