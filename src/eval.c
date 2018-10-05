/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 21:56:33 by gfielder          #+#    #+#             */
/*   Updated: 2018/10/04 06:41:17 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "eval.h"
#include "word.h"
#include "tree.h"
#include "ops.h"

long	eval_expr(char *str)
{
	t_word	*head;
	int		value;

	head = build_word_list(str, 0);
	head = build_tree(head);
	value = eval_tree(head);
	return (value);
}

long	eval_tree(t_word *root)
{
	t_op_func	op;
	long		value;

	if (root->type == NUMERIC)
		return (root->value);
	op = lookup(root->word, root->len);
	if (op != 0)
	{
		value = op(eval_tree(root->left), eval_tree(root->right));
		remove_leaves(root);
		return (value);
	}
	else
		return (0);
}
