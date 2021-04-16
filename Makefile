# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/12 19:44:56 by rbourgea          #+#    #+#              #
#    Updated: 2021/04/14 18:17:25 by rbourgea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECK	=	checker
PS		=	push_swap

CC		=	clang

HEADER	=	push_swap.h

OBJDIR	=	objs

SRC		=	libft_1.c libft_2.c others_1.c others_2.c others_3.c ft_split.c median.c small.c \
			parser_checker.c half_on_b.c exec_move.c find_farthest.c calc_move.c \
			op_1.c op_2.c op_3.c op_display_1.c op_display_2.c op_display_3.c bonus.c

SRC_C	=	checker.c $(SRC)
SRC_P	=	push_swap.c $(SRC)

OBJ_C 	=	$(addprefix $(OBJDIR)/, $(SRC_C:.c=.o))
OBJ_P 	=	$(addprefix $(OBJDIR)/, $(SRC_P:.c=.o))

CFLAGS	=	-Wall -Wextra -Werror -g #-fsanitize=address

all: 		$(CHECK) $(PS)

bonus: 		all

test:
			@./play.sh

$(CHECK): 	$(OBJ_C)
			@$(CC) $(CFLAGS) $(OBJ_C) -o $(CHECK)
			@echo '✔ Checker DONE'

$(PS): 	$(OBJ_P)
			@$(CC) $(CFLAGS) $(OBJ_P) -o $(PS)
			@echo '✔ Push_Swap DONE'

$(OBJDIR)/%.o: %.c
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@rm -f $(OBJ_C) $(OBJ_P)

fclean: 	clean
			@rm -f $(CHECK) $(PS)

re: 		fclean all

.PHONY: 	clean fclean all re bonus
