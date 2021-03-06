/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 02:24:53 by gfielder          #+#    #+#             */
/*   Updated: 2018/10/05 05:33:31 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "word.h"

# define PRINT_POINTERS 1

void	debug_print(char *str);
void	print_word(t_word *head);
void	print_list(t_word *head);
void	print_tree(t_word *head, int level);

#endif
