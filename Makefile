NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c sort.c utils.c utils2.c perser.c algorithm.c stack.c exception.c
OBJS = $(SRCS:.c=.o)

INCLUDES = -I./libft -I./ft_printf -I.

LIBFT = ./libft/libft.a
PRINTF = ./ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

%.o: %.c pushswap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C ./libft

$(PRINTF):
	make -C ./ft_printf

clean:
	make -C ./libft clean
	make -C ./ft_printf clean
	rm -f $(OBJS)

fclean: clean
	make -C ./libft fclean
	make -C ./ft_printf fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
