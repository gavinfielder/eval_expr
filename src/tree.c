/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 12:52:49 by gfielder          #+#    #+#             */
/*   Updated: 2018/10/04 07:35:29 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "word.h"
#include "tree.h"
#include "debug.h"

t_word	*build_tree(t_word *current)
{
	if (current->prev == 0 && current->next == 0)
		return (current);
	current = trim_encompassing_brackets(current);
	if (current->prev == 0 && current->next == 0)
		return (current);
	current = get_breakpoint(current);
	current = break_at(current);
	current->left = build_tree(current->left);
	current->right = build_tree(current->right);
	return (current);
}

t_word	*break_at(t_word *word)
{
	word->left = word->prev;
	word->right = word->next;
	word->left->next = 0;
	word->right->prev = 0;
	word->prev = 0;
	word->next = 0;
	return (word);
}

t_word	*trim_encompassing_brackets(t_word *current)
{
	int		bracket;
	int		brackets_found;
	t_word	*safe;

	safe = 0;
	current = get_head(current);
	while (!safe)
	{
		if (!(current->type & BRACKET))
			safe = current;
		current = current->next;
	}
	current = get_head(current);
	bracket = (current->type % 2) * ((current->type % 4) - 2);
	brackets_found = bracket;
	while (bracket && current->next)
	{
		current = current->next;
		bracket += (current->type % 2) * ((current->type % 4) - 2);
	}
	if (brackets_found && current->next == 0)
		remove_word_from_list(get_head(current));
	if (brackets_found && current->next == 0)
		remove_word_from_list(get_tail(current));
	return (safe);
}

t_word	*get_breakpoint(t_word *cur)
{
	t_word	*op;
	int		bracket;

	op = 0;
	cur = get_tail(cur);
	bracket = 0;
	while (cur)
	{
		bracket += ((cur->type % 2) * ((cur->type % 4) - 2));
		if (bracket == 0 && (cur->type & OPERATOR))
		{
			if (op == 0)
				op = cur;
			if (cur->type & OP_ADDSUB)
			{
				op = cur;
				break ;
			}
		}
		cur = cur->prev;
	}
	return (op);
}

void	remove_leaves(t_word *word)
{
	if (word->left)
		free(word->left);
	if (word->right)
		free(word->right);
	word->left = 0;
	word->right = 0;
}
