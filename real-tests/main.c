/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 16:19:54 by ndudnicz          #+#    #+#             */
/*   Updated: 2017/11/25 16:19:59 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftasm.h"
#include "launcher_bzero.h"
#include "launcher_isalnum.h"
#include "launcher_isalpha.h"
#include "launcher_isdigit.h"
#include "launcher_atoi.h"

int		main(void)
{
	ft_putstr("*********************************\n");
	ft_putstr("**      42 - Unit Tests      ****\n");
	ft_putstr("*********************************\n");
	launcher_bzero();
	launcher_isalnum();
	launcher_isalpha();
	launcher_isdigit();
	launcher_atoi();
	return (0);
}
