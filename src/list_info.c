/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 02:42:26 by gfielder          #+#    #+#             */
/*   Updated: 2018/10/04 03:14:28 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "word.h"

int		dist_from_head(t_word *word)
{
	int	dist;

	dist = 0;
	while (word->prev)
	{
		dist++;
		word = word->prev;
	}
	return (dist);
}

int		dist_from_tail(t_word *word)
{
	int	dist;

	dist = 0;
	while (word->prev)
	{
		dist++;
		word = word->prev;
	}
	return (dist);
}

int		get_abs_centerness(t_word *word)
{
	int	abs_centerness;

	abs_centerness = get_centerness(word);
	if (abs_centerness < 0)
		abs_centerness *= -1;
	return (abs_centerness);
}

int		get_centerness(t_word *word)
{
	int from_head;
	int from_tail;
	int centerness;

	from_head = dist_from_head(word);
	from_tail = dist_from_tail(word);
	centerness = from_tail - from_head;
	return (centerness);
}
