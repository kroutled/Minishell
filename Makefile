NAME = minishell

CC = gcc -Wall -Werror -Wextra

INCLUDE = -L libft -lft

SRC = main.c			\
	  echo.c			\
	  envinit.c			\
	  setenv.c			\
	  unsetenv.c		\
	  cd.c				\
	  mysplit.c			\

all: $(NAME)

$(NAME):
	$(MAKE) -C libft
	$(CC) $(SRC) $(INCLUDE) -o $(NAME)

clean:
	$(MAKE) -C libft fclean

fclean:
	$(MAKE) -C libft fclean
	rm -rf $(NAME)

re: fclean all
