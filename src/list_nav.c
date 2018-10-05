/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_nav.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 02:41:27 by gfielder          #+#    #+#             */
/*   Updated: 2018/10/04 03:14:16 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "word.h"

t_word	*get_tail(t_word *word)
{
	while (word->next != 0)
		word = word->next;
	return (word);
}

t_word	*get_head(t_word *word)
{
	while (word->prev != 0)
		word = word->prev;
	return (word);
}
