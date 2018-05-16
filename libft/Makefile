# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aherrera <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/19 15:14:20 by aherrera          #+#    #+#              #
#    Updated: 2018/05/15 19:05:57 by aherrera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
FILES_C = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_atoi.c ft_ctos.c ft_strshift.c ft_diff.c ft_small.c ft_utoa.c ft_strcomb.c
FILES_O = ft_memset.o ft_bzero.o ft_memcpy.o ft_memccpy.o ft_memmove.o ft_memchr.o ft_memcmp.o ft_strlen.o ft_strdup.o ft_strcpy.o ft_strncpy.o ft_strcat.o ft_strncat.o ft_strlcat.o ft_strchr.o ft_strrchr.o ft_strstr.o ft_strnstr.o ft_strcmp.o ft_strncmp.o ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o ft_toupper.o ft_tolower.o ft_atoi.o ft_ctos.o ft_strshift.o ft_diff.o ft_small.o ft_utoa.o ft_strcomb.o
FILES_C2 = ft_strclr.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strrev.c ft_itoa.c ft_strsplit.c ft_putwchar.c ft_putwstr.c get_next_line.c ft_isdigitstr.c
FILES_O2 = ft_strclr.o ft_memalloc.o ft_memdel.o ft_strnew.o ft_strdel.o ft_striter.o ft_striteri.o ft_strmap.o ft_strmapi.o ft_strequ.o ft_strnequ.o ft_strsub.o ft_strjoin.o ft_strtrim.o ft_putchar.o ft_putstr.o ft_putendl.o ft_putnbr.o ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o ft_strrev.o ft_itoa.o ft_strsplit.o ft_putwchar.o ft_putwstr.o get_next_line.o ft_isdigitstr.o

all: $(NAME)

$(NAME):
	@echo "\033[0;5;33mMaking libft\033[0m"
	@gcc $(FLAGS) -c  $(FILES_C) $(FILES_C2) -I includes
	@ar rc libft.a $(FILES_O) $(FILES_O2)
	@echo "\033[0;32mFinished making \033[97;40mlibft\033[0m"

clean:
	@echo "\033[0;5;33mRemoving .o files\033[0m"
	@/bin/rm -f *.o
	@echo "\033[0;32mRemoved .o files\033[0m"

fclean: clean
	@echo "\033[0;5;33mRemoving binaries and libraries\033[0m"
	@/bin/rm -f $(NAME)
	@echo "\033[0;32mRemoved binaries and libraries\033[0m"

re: fclean all
