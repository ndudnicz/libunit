/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 18:41:55 by ndudnicz          #+#    #+#             */
/*   Updated: 2016/01/13 16:26:09 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putnchar(char c, int n)
{
	int		i;

	i = 0;
	while (n > 0)
	{
		write(1, &c, 1);
		n--;
		i++;
	}
	return (i);
}
