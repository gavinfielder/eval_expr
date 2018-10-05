/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 20:39:59 by gfielder          #+#    #+#             */
/*   Updated: 2018/10/04 06:45:40 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "word.h"
#include "ft.h"

void			build_word_list_helper(char *str, t_word *word);

unsigned short	detect_type(char c)
{
	if (c >= '0' && c <= '9')
		return (NUMERIC);
	else if (c == '*')
		return (OP_MUL);
	else if (c == '/')
		return (OP_DIV);
	else if (c == '%')
		return (OP_MOD);
	else if (c == '+')
		return (OP_ADD);
	else if (c == '-')
		return (OP_SUB);
	else if (c == ' ' || (c >= 9 && c <= 13))
		return (WHITESPACE);
	else if (c == '(' || c == '[' || c == '{')
		return (OPEN_BRACKET);
	else if (c == ')' || c == ']' || c == '}')
		return (CLOSE_BRACKET);
	else
		return (UNKNOWN);
}

t_word			*build_word_list(char *str, t_word *prev)
{
	t_word	*word;

	while (detect_type(*str) == WHITESPACE)
		str++;
	if (*str == '\0')
		return (0);
	word = malloc(sizeof(t_word));
	word->word = str;
	word->prev = prev;
	word->len = 1;
	word->left = 0;
	word->right = 0;
	build_word_list_helper(str, word);
	word->next = build_word_list(str + word->len, word);
	return (word);
}

void			build_word_list_helper(char *str, t_word *word)
{
	word->type = detect_type(*str);
	while (1)
	{
		while (detect_type(*(str + word->len)) == word->type
				&& !(detect_type(*(str + word->len)) & BRACKET))
			word->len++;
		if (((word->type & OP_ADDSUB)
					&& (detect_type(*(str + word->len)) & NUMERIC)))
			word->type = NUMERIC;
		else
			break ;
	}
	if (word->type == NUMERIC)
		word->value = ft_atoi(word->word);
}

void			remove_word_from_list(t_word *word)
{
	if (word->prev == 0 && word->next != 0)
		word->next->prev = 0;
	if (word->next == 0 && word->prev != 0)
		word->prev->next = 0;
	if (word->next != 0 && word->prev != 0)
	{
		word->next->prev = word->prev;
		word->prev->next = word->next;
	}
	free(word);
}
