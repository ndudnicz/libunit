/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 14:51:26 by ndudnicz          #+#    #+#             */
/*   Updated: 2016/01/19 13:41:06 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wchar.h>
#include <stdlib.h>

void	ft_free_exit(t_flag *flag, char *msg)
{
	ft_putstr(msg);
	reset_flag(flag);
	exit(0);
}

int		ft_free_return(t_flag *flag, char *msg, int ret)
{
	ft_putstr(msg);
	reset_flag(flag);
	return (ret);
}
