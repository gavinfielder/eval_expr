/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 17:28:58 by gfielder          #+#    #+#             */
/*   Updated: 2018/10/05 06:07:54 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H

# include "word.h"

t_word	*build_tree(t_word *current);
t_word	*break_at(t_word *word);
t_word	*get_breakpoint(t_word *current);
void	remove_leaves(t_word *word);
int		trim_encompassing_brackets(t_word *current, t_word **safe,
		int bracket, int brackets_found);
t_word	*trim_all_encompassing_brackets(t_word *current);

#endif
