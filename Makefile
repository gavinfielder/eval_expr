# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile (eval_expr)                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfielder <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/03 01:50:54 by gfielder          #+#    #+#              #
#    Updated: 2018/10/05 03:02:54 by gfielder         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = eval_expr
SRC = src/main.c src/eval.c src/tree.c src/list_nav.c src/list_info.c \
	  src/ops.c src/ops_dict.c src/word.c src/tree_brackets.c \
	  src/ft_atoi.c src/ft_strncmp.c src/ft_putchar.c src/ft_putnbr.c \
	  src/debug.c
OBJ = main.o eval.o tree.o list_nav.o list_info.o ops.o ops_dict.o word.o \
	  ft_atoi.o ft_strncmp.o ft_putchar.o ft_putnbr.o tree_brackets.o debug.o
IDIR = ./inc
CFLAGS = -Wall -Werror -Wextra

# ---------------------------------------------------------------------------- #
#                                Source files                                  #
# ---------------------------------------------------------------------------- #
# name			header		description                                        #
# main.c	    (none)		main                                               #
# eval.c		eval.h		functions for evaluating expression trees          #
# tree.c		tree.h		functions for building an expression tree          #
# tree_brackets.c tree.h	handles encompassing brackets for tree building    #
# word.c		word.h		functions for parsing a string into words          #
# list_nav.c	word.h		functions for navigating a word list               #
# list_info.c	word.h		functions for getting info about a list            #
# ops.c			ops.h		arithmetic operation functions                     #
# ops_dict.c	ops.h		lookup operator by string                          #
# ft_atoi.c		ft.h		                                                   #
# ft_strncmp.c	ft.h		                                                   #
# ft_putchar.c	ft.h                                                           #
# debug.c		debug.h		debug print functions                              #
# ---------------------------------------------------------------------------- #
#                               Header files                                   #
# ---------------------------------------------------------------------------- #
# eval.h			functions for evaluating expression trees                  #
# ops.h				arithmetic functions and their dictionary struct           #
# tree.h			functions for building an expression tree                  #
# word.h			t_word struct, type ids and bit masks, functions           #
# ft.h				ftlib functions                                            #
# ---------------------------------------------------------------------------- #

all: $(NAME)

$(NAME): src/objects
	gcc -o eval_expr -I$(IDIR) $(OBJ)
	make clean

src/objects:
	gcc $(CFLAGS) -I$(IDIR) -c $(SRC)

fclean:
	-rm *.o
	-rm eval_expr

clean:
	-rm *.o

re:
	make fclean
	make all
	make clean
