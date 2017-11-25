/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 09:54:25 by ndudnicz          #+#    #+#             */
/*   Updated: 2016/01/18 10:30:57 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int		treat_str(t_flag *flag, char *str)
{
	int		len;
	char	null_str;

	null_str = 0;
	if (str == NULL)
	{
		if (!(str = ft_strdup("(null)")))
			return (ft_free_return(flag, ERR_MALLOC, -1));
		null_str = 1;
	}
	len = ((int)ft_strlen(str) > flag->precision && flag->precision != -1) ?
		flag->precision : (int)ft_strlen(str);
	if (!ft_strchr(flag->attribut, '-'))
	{
		flag->total += ft_putnchar(' ', flag->field_width - len);
		flag->total += ft_putnstr(str, len);
	}
	else
	{
		flag->total += ft_putnstr(str, len);
		flag->total += ft_putnchar(' ', flag->field_width - len);
	}
	null_str == 1 ? free(str) : 1;
	return (0);
}
