/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 11:03:43 by gfielder          #+#    #+#             */
/*   Updated: 2018/10/04 05:31:19 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ops.h"

extern int	g_error_flag;

long	op_add(int n1, int n2)
{
	return (n1 + n2);
}

long	op_sub(int n1, int n2)
{
	return (n1 - n2);
}

long	op_div(int n1, int n2)
{
	if (n2 == 0)
	{
		g_error_flag = DIVISION_BY_ZERO;
		return (0);
	}
	return (n1 / n2);
}

long	op_mul(int n1, int n2)
{
	return (n1 * n2);
}

long	op_mod(int n1, int n2)
{
	if (n2 == 0)
	{
		g_error_flag = MODULO_BY_ZERO;
		return (0);
	}
	return (n1 % n2);
}
