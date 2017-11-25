/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 14:51:26 by ndudnicz          #+#    #+#             */
/*   Updated: 2016/01/21 13:16:34 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		flag_is_valid_next(t_flag *flag)
{
	if (ft_strchr(flag->attribut, ' ') &&
			ft_strchr("sSpoOxXuUcCbB", flag->conversion))
		ft_free_exit(flag, ERR_BADFLAG);
	if (ft_strchr(flag->attribut, '-') && ft_strchr(flag->attribut, '0'))
		ft_free_exit(flag, ERR_BADFLAG);
	if (ft_strchr(flag->attribut, ' ') && ft_strchr(flag->attribut, '+'))
		ft_free_exit(flag, ERR_BADFLAG);
}

void			flag_is_valid(t_flag *flag)
{
	if (flag->modifier[0] == 'l' && ft_strchr("SCpD", flag->conversion))
		ft_free_exit(flag, ERR_BADFLAG);
	if (flag->modifier[1] == 'l' && ft_strchr("scD", flag->conversion))
		ft_free_exit(flag, ERR_BADFLAG);
	if ((ft_strchr("SC", flag->conversion) ||
		(ft_strchr("sc", flag->conversion) &&
		flag->modifier[0] == 'l')) && flag->precision > 0)
		ft_free_exit(flag, ERR_BADFLAG);
	if (ft_strchr("bB", flag->conversion) && (flag->modifier[0] == 'j' ||
				flag->modifier[0] == 'z'))
		ft_free_exit(flag, ERR_BADFLAG);
	if (ft_strchr("sScCpD", flag->conversion) && (flag->modifier[0] == 'h' ||
				flag->modifier[0] == 'z' || flag->modifier[0] == 'j'))
		ft_free_exit(flag, ERR_BADFLAG);
	if (ft_strchr(flag->attribut, '0') &&
			ft_strchr("sSpcC", flag->conversion))
		ft_free_exit(flag, ERR_BADFLAG);
	if (ft_strchr(flag->attribut, '+') &&
			ft_strchr("sSpoOxXuUcCbB", flag->conversion))
		ft_free_exit(flag, ERR_BADFLAG);
	if (ft_strchr(flag->attribut, '#') &&
			ft_strchr("sSpdDicCbB", flag->conversion))
		ft_free_exit(flag, ERR_BADFLAG);
	flag_is_valid_next(flag);
}
