/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_brackets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 02:51:29 by gfielder          #+#    #+#             */
/*   Updated: 2018/10/05 03:04:00 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "word.h"

int	trim_encompassing_brackets(t_word *current, t_word **safe,
		int bracket, int brackets_found)
{
	*safe = 0;
	current = get_head(current);
	while (!(*safe))
	{
		if (!(current->type & BRACKET))
			*safe = current;
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
	{
		remove_word_from_list(get_head(current));
		remove_word_from_list(get_tail(current));
		return (1);
	}
	return (0);
}

t_word	*trim_all_encompassing_brackets(t_word *current)
{
	t_word	*safe;
	int		found_brackets;
	int		bracket;
	int		brackets_found;

	bracket = 0;
	brackets_found = 0;
	while (1)
	{
		found_brackets = trim_encompassing_brackets(current, &safe,
				bracket, brackets_found);
		current = safe;
		if (!found_brackets)
			break ;
	}
	return (safe);
}
