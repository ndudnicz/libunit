/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 16:10:08 by ndudnicz          #+#    #+#             */
/*   Updated: 2016/01/21 16:22:44 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <unistd.h>
#include "ft_printf.h"

static int		ft_putwchar_8b(wint_t wc)
{
	unsigned char	octet;
	int				total;

	total = 0;
	octet = wc;
	total = write(1, &octet, 1);
	return (total);
}

static int		ft_putwchar_16b(wint_t wc)
{
	unsigned char	octet_0;
	unsigned char	octet_6;
	unsigned char	octet;
	int				total;

	total = 0;
	octet_6 = wc % 64;
	octet_0 = (wc / 64) % 32;
	octet = (49280 / 256) | octet_0;
	total += write(1, &octet, 1);
	octet = (49280 % 256) | octet_6;
	total += write(1, &octet, 1);
	return (total);
}

static int		ft_putwchar_24b(wint_t wc)
{
	unsigned char	octet_0;
	unsigned char	octet_6;
	unsigned char	octet_12;
	unsigned char	octet;
	int				total;

	total = 0;
	octet_12 = wc % 64;
	octet_6 = (wc / 64) % 64;
	octet_0 = (wc / 4096) % 16;
	octet = (14712960 / 65536) | octet_0;
	total += write(1, &octet, 1);
	octet = (14712960 / 256) | octet_6;
	total += write(1, &octet, 1);
	octet = (14712960 % 256) | octet_12;
	total += write(1, &octet, 1);
	return (total);
}

static int		ft_putwchar_32b(wint_t wc)
{
	unsigned char	octet_6;
	unsigned char	octet_12;
	unsigned char	octet_18;
	unsigned char	octet;
	int				total;

	total = 0;
	octet_18 = wc % 64;
	octet_12 = (wc / 64) % 64;
	octet_6 = (wc / 4096) % 64;
	octet = (4034953344 / 16777216) | ((wc / 262144) % 8);
	total += write(1, &octet, 1);
	octet = (4034953344 / 65536) | octet_6;
	total += write(1, &octet, 1);
	octet = (4034953344 / 256) | octet_12;
	total += write(1, &octet, 1);
	octet = (4034953344 % 256) | octet_18;
	total += write(1, &octet, 1);
	return (total);
}

int				ft_putwchar(wint_t wc)
{
	int		number_len;

	number_len = ft_long_numberlen(wc, 2);
	if (number_len < 8)
		return (ft_putwchar_8b(wc));
	else if (number_len < 12)
		return (ft_putwchar_16b(wc));
	else if (number_len < 17)
		return (ft_putwchar_24b(wc));
	else
		return (ft_putwchar_32b(wc));
}
