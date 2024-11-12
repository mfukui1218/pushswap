/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 02:19:12 by mfukui            #+#    #+#             */
/*   Updated: 2023/11/12 12:17:58 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
    int		data;
	struct s_node	*next;
	struct s_node	*prev;
}   t_node;

typedef struct s_stack
{
	t_node	*top;
    size_t  size;
}   t_stack;


void	ft_swap(t_stack *stack);               // 先頭2つの要素を交換
void	ft_push(t_stack *stack_a, t_stack *stack_b); // 他のスタックにプッシュ
void	ft_rotate(t_stack *stack);              // ローテート
void	ft_reverse_rotate(t_stack *stack);      // リバースローテート

// ソートアルゴリズム
void	ft_twosort(t_stack *stack);             // 2つの要素のソート
void	ft_threesort(t_stack *stack);           // 3つの要素のソート
void	ft_fivesort(t_stack *stack_a, t_stack *stack_b); // 5つの要素のソート
void	ft_radix_sort(t_stack *stack_a, t_stack *stack_b); // ラディックスソート

// サポート関数
int		*ft_atoi_rmkd(size_t argc, const char **str); // 文字列から整数配列に変換
size_t	*ft_assign_rank(int *str);                  // ランク付け
size_t	ft_max_bitlen(int *rank);                   // 最大ビット長の取得
size_t	ft_bitlen(size_t num);                      // ビット長の計算

// エラー処理
void	ft_error(int i);                             // エラーメッセージ表示


#endif