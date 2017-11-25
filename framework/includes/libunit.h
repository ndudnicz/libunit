/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 11:07:51 by ndudnicz          #+#    #+#             */
/*   Updated: 2017/11/25 16:17:36 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

typedef struct	s_result
{
	unsigned int	ok;
	unsigned int	total;
}				t_result;

typedef struct	s_unit_test
{
	char const			*name;
	int					(*f)(void);
	struct s_unit_test	*next;
	struct s_unit_test	*last;
}				t_unit_test;

int				load_test(t_unit_test **list, char const *name,
							int (*f)(void));
int				run_tests(t_unit_test **list);
void			free_list(t_unit_test **list);

#endif
