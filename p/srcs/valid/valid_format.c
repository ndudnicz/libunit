/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 09:58:21 by ndudnicz          #+#    #+#             */
/*   Updated: 2016/01/21 13:19:39 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		valid_format(char *fmt)
{
	t_flag		*flag;

	while (*fmt)
	{
		if (*fmt == '%' && *(fmt++ + 1) != '%')
		{
			if (!(flag = init_flag()))
				return (ft_free_return(NULL, ERR_MALLOC, -1));
			if (get_attribut(fmt, flag) == -1)
				ft_free_exit(flag, ERR_BADFLAG);
			fmt = flag->p_format;
			reset_flag(flag);
		}
		fmt++;
	}
	return (0);
}
