/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 02:40:05 by gfielder          #+#    #+#             */
/*   Updated: 2018/10/04 07:07:10 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "debug.h"
#include "word.h"

void	debug_print(char *str)
{
	printf("%s", str);
}

void	print_word(t_word *word)
{
	if (PRINT_POINTERS)
		printf("{\"%.*s\", type=0x%x, val=%i, prev=%p, next=%p} ",
				word->len, word->word,
				word->type, word->value, word->prev, word->next);
	else
		printf("{\"%.*s\", type=0x%x, val=%i} ", word->len, word->word,
				word->type, word->value);
}

void	print_list(t_word *head)
{
	print_word(head);
	if (head->next != 0)
		print_list(head->next);
}

void	print_tree(t_word *head, int level)
{
	const int	horiz_scale = 4;
	int			i;

	i = -1;
	while (++i < level * horiz_scale)
	{
		if (i % horiz_scale == horiz_scale - 1)
			printf("|");
		else
			printf(" ");
	}
	print_word(head);
	printf("\n");
	if (head->left)
		print_tree(head->left, level + 1);
	if (head->right)
		print_tree(head->right, level + 1);
}
