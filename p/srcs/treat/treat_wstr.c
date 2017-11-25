/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_wstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 09:54:25 by ndudnicz          #+#    #+#             */
/*   Updated: 2016/01/20 09:34:07 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wchar.h>
#include <stdlib.h>

static wchar_t		*ft_wstrdup(wchar_t *wstr)
{
	wchar_t		*dup;
	int			i;

	i = 0;
	if (!(dup = (wchar_t*)malloc(sizeof(wchar_t) * ft_wstrlen(wstr) + 1)))
		return (NULL);
	while (wstr[i])
	{
		dup[i] = wstr[i];
		i++;
	}
	dup[i] = L'\0';
	return (dup);
}

int					treat_wstr(t_flag *flag, wchar_t *wstr)
{
	char	null_str;

	null_str = 0;
	if (wstr == NULL)
	{
		if (!(wstr = ft_wstrdup(L"(null)")))
			return (ft_free_return(flag, ERR_MALLOC, -1));
		null_str = 1;
	}
	else
	{
		if (valid_wstr(wstr) == -1)
			return (-1);
	}
	flag->len = (ft_wstrlen(wstr) > flag->precision && flag->precision != -1) ?
		flag->precision : ft_wstrlen(wstr);
	if (!ft_strchr(flag->attribut, '-'))
		flag->total += ft_putnchar(' ', flag->field_width - flag->len);
	flag->total += ft_putnwstr(wstr, flag->len);
	if (ft_strchr(flag->attribut, '-'))
		flag->total += ft_putnchar(' ', flag->field_width - flag->len);
	null_str == 1 ? free(wstr) : 1;
	return (0);
}
