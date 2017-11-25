/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_numberlen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 14:53:49 by ndudnicz          #+#    #+#             */
/*   Updated: 2016/01/21 17:24:33 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>

int		ft_long_numberlen(long long int n, int base)
{
	int		len;

	len = 1;
	if (base > 1 && base < 37)
	{
		while (n /= (long long int)base)
			len++;
	}
	return (len);
}

int		ft_ulong_numberlen(unsigned long long int n, int base)
{
	int		len;

	len = 1;
	if (base > 1 && base < 37)
	{
		while (n /= (unsigned long long int)base)
			len++;
	}
	return (len);
}
