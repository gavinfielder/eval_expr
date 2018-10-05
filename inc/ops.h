/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 04:44:53 by gfielder          #+#    #+#             */
/*   Updated: 2018/10/04 06:38:55 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPS_H
# define OPS_H

typedef	long	(*t_op_func)	(int, int);

typedef	struct	s_op_dict_entry
{
	char		*key;
	t_op_func	value;
}				t_op_dict_entry;

# define OK 1
# define OPERATOR_NOT_FOUND -1
# define DIVISION_BY_ZERO -5
# define MODULO_BY_ZERO -6

t_op_func		lookup(char *str, int len);

long			op_add(int n1, int n2);
long			op_sub(int n1, int n2);
long			op_div(int n1, int n2);
long			op_mul(int n1, int n2);
long			op_mod(int n1, int n2);

#endif
