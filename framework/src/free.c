/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 16:17:47 by ndudnicz          #+#    #+#             */
/*   Updated: 2017/11/25 16:17:48 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libunit.h"

void	free_list(t_unit_test *list)
{
	t_unit_test		*tmp;

	while (list)
	{
		tmp = list->next;
		free((void*)list->name);
		free((void*)list);
		list->name = NULL;
		list->next = NULL;
		list->last = NULL;
		list = tmp;
	}
}
