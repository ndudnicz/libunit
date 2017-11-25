/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 12:54:58 by ndudnicz          #+#    #+#             */
/*   Updated: 2016/01/20 17:18:09 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_colors.h"
#include "ft_printf.h"
#include <stdlib.h>

static char		*get_color_next_next(char *color)
{
	if (!ft_strcmp(color, "{bold}"))
		return (BOLD);
	else if (!ft_strcmp(color, "{nobold}"))
		return (NOBOLD);
	else if (!ft_strcmp(color, "{under}"))
		return (UNDER);
	else if (!ft_strcmp(color, "{nounder}"))
		return (NOUNDER);
	else if (!ft_strcmp(color, "{blink}"))
		return (BLINK);
	else if (!ft_strcmp(color, "{noblink}"))
		return (NOBLINK);
	else
		return (NULL);
}

static char		*get_color_next(char *color)
{
	if (!ft_strcmp(color, "{lgray}"))
		return (LGRAY);
	else if (!ft_strcmp(color, "{dgray}"))
		return (DGRAY);
	else if (!ft_strcmp(color, "{lred}"))
		return (LRED);
	else if (!ft_strcmp(color, "{lgreen}"))
		return (LGREEN);
	else if (!ft_strcmp(color, "{lyellow}"))
		return (LYELLOW);
	else if (!ft_strcmp(color, "{lblue}"))
		return (LBLUE);
	else if (!ft_strcmp(color, "{lmagenta}"))
		return (LMAGENTA);
	else if (!ft_strcmp(color, "{lcyan}"))
		return (LCYAN);
	else if (!ft_strcmp(color, "{white}"))
		return (WHITE);
	else
		return (get_color_next_next(color));
}

static char		*get_color(char *color)
{
	if (!ft_strcmp(color, "{eoc}"))
		return (EOC);
	else if (!ft_strcmp(color, "{black}"))
		return (BLACK);
	else if (!ft_strcmp(color, "{red}"))
		return (RED);
	else if (!ft_strcmp(color, "{green}"))
		return (GREEN);
	else if (!ft_strcmp(color, "{yellow}"))
		return (YELLOW);
	else if (!ft_strcmp(color, "{blue}"))
		return (BLUE);
	else if (!ft_strcmp(color, "{magenta}"))
		return (MAGENTA);
	else if (!ft_strcmp(color, "{cyan}"))
		return (CYAN);
	else
		return (get_color_next(color));
}

char			*treat_color(char *fmt)
{
	char	*ptr_color;

	if (!(ptr_color = ft_strdupchr(fmt, '}')))
		return (fmt);
	if (!(get_color(ptr_color)))
	{
		free(ptr_color);
		return (fmt);
	}
	ft_putstr(get_color(ptr_color));
	free(ptr_color);
	fmt++;
	while (*fmt && *fmt != '}')
		fmt++;
	return (fmt);
}
