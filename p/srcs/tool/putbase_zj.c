/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putbase_zj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 14:11:04 by ndudnicz          #+#    #+#             */
/*   Updated: 2016/01/19 10:55:21 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>
#include <unistd.h>

void	z_putbase(size_t n, int base, char upper)
{
	if (n >= (size_t)base)
	{
		z_putbase(n / base, base, upper);
		z_putbase(n % base, base, upper);
	}
	else
	{
		if (n > 9)
			upper == 0 ? ft_putchar(n + 87) : ft_putchar(n + 55);
		else
			ft_putchar(n + 48);
	}
}

void	j_putbase(intmax_t n, int base, char upper)
{
	if (n >= (intmax_t)base)
	{
		j_putbase(n / base, base, upper);
		j_putbase(n % base, base, upper);
	}
	else
	{
		if (n > 9)
			upper == 0 ? ft_putchar(n + 87) : ft_putchar(n + 55);
		else
			ft_putchar(n + 48);
	}
}

void	uj_putbase(uintmax_t n, int base, char upper)
{
	if (n >= (uintmax_t)base)
	{
		uj_putbase(n / base, base, upper);
		uj_putbase(n % base, base, upper);
	}
	else
	{
		if (n > 9)
			upper == 0 ? ft_putchar(n + 87) : ft_putchar(n + 55);
		else
			ft_putchar(n + 48);
	}
}
