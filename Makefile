# プロジェクト名
NAME = push_swap

# コンパイラとフラグ
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# ソースファイルとオブジェクトファイル
SRCS = main.c sort.c utils.c utils2.c perser.c algorithm.c stack.c exception.c
OBJS = $(SRCS:.c=.o)

# ヘッダーファイル
INCLUDES = -I./libft -I./ft_printf -I.

# ライブラリ
LIBFT = ./libft/libft.a
PRINTF = ./ft_printf/libftprintf.a

# ルール定義
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

# コンパイルルール
%.o: %.c pushswap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# libftライブラリのビルド
$(LIBFT):
	make -C ./libft

# ft_printfライブラリのビルド
$(PRINTF):
	make -C ./ft_printf

# クリーンアップ
clean:
	make -C ./libft clean
	make -C ./ft_printf clean
	rm -f $(OBJS)

fclean: clean
	make -C ./libft fclean
	make -C ./ft_printf fclean
	rm -f $(NAME)

re: fclean all

# phonyターゲット
.PHONY: all clean fclean re
