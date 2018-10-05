/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 23:53:16 by gfielder          #+#    #+#             */
/*   Updated: 2018/10/04 06:51:30 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"
#include "ft.h"

int g_error_flag;

int	main(int argc, char **argv)
{
	long value;

	if (argc < 2)
		return (0);
	value = eval_expr(argv[1]);
	ft_putnbr(value);
	ft_putchar('\n');
	return (0);
}
