FILES_C = src/main.c src/entry.c src/print.c src/cols.c
FILES_O = main.o entry.o print.o cols.o
NAME = ft_ls
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@make -C libft/ all
	@cp libft/libft.a ./
	@make -C printf/ all
	@cp printf/libftprintf.a ./
	@echo "\033[0;5;33mCompiling and building\033[0m"
	@gcc -c $(FLAGS) $(FILES_C) src/kane_alloc_wrap.c -I ./includes
	@gcc -o $(NAME) $(FLAGS) $(FILES_O) -I ./includes -L . -lftprintf
	@gcc -o $(NAME)2 $(FLAGS) $(FILES_O) kane_alloc_wrap.o -I ./includes -L . -lftprintf
	@cp $(NAME) test/
	@cp $(NAME)2 test/
	@echo "\033[0;32mFinished building \033[40;97m$(NAME)\033[0m"

clean:
	@/bin/rm -f $(FILES_O) kane_alloc_wrap.o
	@make -C libft/ clean
	@make -C printf/ clean

fclean:
	@/bin/rm -f $(FILES_O) kane_alloc_wrap.o
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(NAME)2
	@/bin/rm -f libft.a
	@/bin/rm -f libftprintf.a
	@make -C libft/ fclean
	@make -C printf/ fclean

re:	fclean all

retest:
	@echo "\033[0;34mRemaking for test\033[0m"
	@rm $(NAME)
	@gcc -c $(FLAGS) $(FILES_C) src/kane_alloc_wrap.c -I ./includes
	@gcc -o $(NAME) $(FLAGS) $(FILES_O) -I ./includes -L . -lftprintf
	@gcc -o $(NAME)2 $(FLAGS) $(FILES_O) kane_alloc_wrap.o -I ./includes -L . -lftprintf
	@cp $(NAME) test/
	@cp $(NAME)2 test/
