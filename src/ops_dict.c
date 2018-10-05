/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_dict.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 23:00:05 by gfielder          #+#    #+#             */
/*   Updated: 2018/10/04 06:42:45 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ops.h"
#include "ft.h"

extern int g_error_flag;

#define NUMBER_OPS 5

const	t_op_dict_entry g_op_dict[] =
{
	{"+", &op_add},
	{"-", &op_sub},
	{"/", &op_div},
	{"*", &op_mul},
	{"%", &op_mod},
};

t_op_func	lookup(char *str, int len)
{
	int i;

	i = 0;
	while (i < NUMBER_OPS)
	{
		if (ft_strncmp(str, g_op_dict[i].key, len) == 0)
			return (g_op_dict[i].value);
		i++;
	}
	g_error_flag = OPERATOR_NOT_FOUND;
	return (0);
}
