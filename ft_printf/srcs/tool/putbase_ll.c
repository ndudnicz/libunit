/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putbase_ll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 09:54:16 by ndudnicz          #+#    #+#             */
/*   Updated: 2016/01/20 11:03:08 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "my_limits.h"
#include <wchar.h>

void	lld_putbase(long long int n, int base)
{
	if (n == INTMIN)
		ft_putstr("2147483648");
	else if (n == LLONGMIN - 1)
		ft_putstr("9223372036854775808");
	else
	{
		if (n >= base)
		{
			lld_putbase(n / base, base);
			lld_putbase(n % base, base);
		}
		else
		{
			if (n > 9)
				ft_putchar(n + 87);
			else
				ft_putchar(n + 48);
		}
	}
}

void	ulld_putbase(unsigned long long int n, int base, char upper)
{
	if (base > 36 || base < 2)
	{
		ft_putchar('0');
		return ;
	}
	if (n >= (unsigned int)base)
	{
		ulld_putbase(n / base, base, upper);
		ulld_putbase(n % base, base, upper);
	}
	else
	{
		if (n > 9)
			upper == 0 ? ft_putchar(n + 87) : ft_putchar(n + 55);
		else
			ft_putchar(n + 48);
	}
}

void	ld_putbase(long int n, int base)
{
	if (n == INTMIN)
		ft_putstr("2147483648");
	else if (n == LONGMIN - 1)
		ft_putstr("9223372036854775808");
	else
	{
		if (n >= base)
		{
			ld_putbase(n / base, base);
			ld_putbase(n % base, base);
		}
		else
		{
			if (n > 9)
				ft_putchar(n + 87);
			else
				ft_putchar(n + 48);
		}
	}
}

void	uld_putbase(unsigned long int n, int base, char upper)
{
	if (n >= (unsigned int)base)
	{
		uld_putbase(n / base, base, upper);
		uld_putbase(n % base, base, upper);
	}
	else
	{
		if (n > 9)
			upper == 0 ? ft_putchar(n + 87) : ft_putchar(n + 55);
		else
			ft_putchar(n + 48);
	}
}
