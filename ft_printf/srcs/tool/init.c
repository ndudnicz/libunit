/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 12:17:52 by ndudnicz          #+#    #+#             */
/*   Updated: 2016/01/20 11:58:47 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

t_flag		*init_flag(void)
{
	t_flag		*flag;

	if (!(flag = (t_flag*)malloc(sizeof(t_flag))))
		return (NULL);
	flag->len = 0;
	flag->attribut[0] = 0;
	flag->field_width = 0;
	flag->precision = -1;
	flag->modifier[0] = 0;
	flag->conversion = 0;
	flag->p_format = NULL;
	flag->total = 0;
	return (flag);
}

void		reset_flag(t_flag *flag)
{
	if (flag)
	{
		flag->len = 0;
		ft_memset(flag->attribut, 0, 6);
		ft_memset(flag->modifier, 0, 3);
		flag->field_width = 0;
		flag->precision = 0;
		flag->conversion = 0;
		flag->p_format = NULL;
		flag->total = 0;
		free(flag);
		flag = NULL;
	}
}
