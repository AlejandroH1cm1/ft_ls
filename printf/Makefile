# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aherrera <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/11 03:11:46 by aherrera          #+#    #+#              #
#    Updated: 2018/05/14 02:50:13 by aherrera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES_C = ft_printf.c utils.c p_fo.c s_fo.c sfs.c pfos.c sfs2.c pfos2.c utils2.c
FILES_O = ft_printf.o utils.o p_fo.o s_fo.o sfs.o pfos.o sfs2.o pfos2.o utils2.o
NAME = libftprintf.a
FLAGS = -c -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@echo "\033[0;5;33mMaking printf\033[0m"
	@cp ../libft.a ./$(NAME)
	@gcc $(FLAGS) $(FILES_C) -I ../libft/includes
	@ar rc $(NAME) $(FILES_O) 
	@ranlib $(NAME)
	@echo "\033[0;32mFinished making \033[97;40mprintf\033[0m"

clean:
	@/bin/rm -f $(FILES_O)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
