/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 20:40:02 by gfielder          #+#    #+#             */
/*   Updated: 2018/10/04 06:39:09 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORD_H
# define WORD_H

/*
** --------------------------------------------------------------------------
**                     Word Type specifiers and masks
** --------------------------------------------------------------------------
** # define BRACKET			0x001	 0000.0000.0001 mask: any bracket
** # define CLOSE_BRACKET	0x001	 0000.0000.0001 (c%2)*((c%4)-2) gets -1
** # define OPEN_BRACKET	0x003 	 0000.0000.0011 (c%2)*((c%4)-2) gets +1
** # define NUMERIC			0x004	 0000.0000.0100 unique
** # define OPERATOR		0x008	 0000.0000.1000 mask: if operator
** # define OP_ADDSUB		0x030	 0000.0011.0000 mask: if add or sub
** # define OP_ADD			0x018	 0000.0001.1000
** # define OP_SUB			0x028	 0000.0010.1000
** # define OP_MULDIVMOD	0x1C0	 0001.1100.0000 mask: if mul, div, or mod
** # define OP_MUL			0x048	 0000.0100.1000
** # define OP_DIV			0x088	 0000.1000.1000
** # define OP_MOD			0x108	 0001.0000.1000
** # define NONCONSIDER		0x800	 1000.0000.0000
** # define WHITESPACE 		0xA00	 1010.0000.0000
** # define UNKNOWN 		0xC00	 1100.0000.0000
*/

# define BRACKET 0x001
# define CLOSE_BRACKET 0x001
# define OPEN_BRACKET 0x003
# define NUMERIC 0x004
# define OPERATOR 0x008
# define OP_ADDSUB 0x030
# define OP_ADD 0x018
# define OP_SUB 0x028
# define OP_MULDIVMOD 0x1C0
# define OP_MUL 0x048
# define OP_DIV 0x088
# define OP_MOD 0x108
# define NONCONSIDER 0x800
# define WHITESPACE 0xA00
# define UNKNOWN 0xC00

typedef struct			s_word
{
	struct s_word		*next;
	struct s_word		*prev;
	char				*word;
	int					len;
	unsigned short		type;
	int					value;
	struct s_word		*left;
	struct s_word		*right;
}						t_word;

/*
** Defined in word.c
*/
t_word					*build_word_list(char *str, t_word *prev);
unsigned short			detect_type(char c);
void					remove_word_from_list(t_word *word);

/*
** Defined in list_info.c
** Centerness is defined as ( dist_from_tail - dist_from_head )
*/
int						dist_from_head(t_word *word);
int						dist_from_tail(t_word *word);
int						get_centerness(t_word *word);
int						get_abs_centerness(t_word *word);

/*
** Defined in list_nav.c
*/
t_word					*get_tail(t_word *head);
t_word					*get_head(t_word *head);

#endif
