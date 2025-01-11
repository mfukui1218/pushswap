/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 02:19:12 by mfukui            #+#    #+#             */
/*   Updated: 2025/01/03 20:12:45 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				data;
	size_t			data_order;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	size_t	size;
}	t_stack;

void	ft_swap(t_stack *stack, char c);
void	ft_ss(t_stack *st_a, t_stack *st_b);
void	ft_push(t_stack *st_a, t_stack *st_b, char c);
void	ft_rotate(t_stack *stack, char c);
void	ft_reverse_rotate(t_stack *stack, char c);
void	ft_twosort(t_stack *stack);
void	ft_threesort(t_stack *stack);
void	ft_foursort(t_stack *st_a, t_stack *st_b);
void	ft_fivesort(t_stack *st_a, t_stack *st_b);
void	ft_three_to_five(t_stack *st_a, t_stack *st_b);
void	ft_algorithm(t_stack *st_a, t_stack *st_b, size_t bitlen);
size_t	*ft_assign_rank(int *str, size_t size);
size_t	ft_bitlen(size_t num);
void	ft_error(int i);
int		*ft_atoi_rmkd(char **str, size_t size);
int		ft_duplication(int *arg, size_t size);
t_stack	*init_stack(size_t size, size_t *rank, int *values);
void	ft_malloc_node(t_stack *stack);
void	free_stack(t_stack *stack);
void	ft_firstpush(t_stack *st_a, t_stack *st_b);
size_t	ft_secondpush(t_stack *st_a, t_stack *st_b, size_t order);
void	ft_thirdpush(t_stack *st_a, t_stack *st_b, size_t order, size_t c);
void	ft_lastpush(t_stack *st_a, t_stack *st_b);
size_t	ft_strlenx(char **str);
void	print_stack(t_stack *stack);
char	*int_to_binary(int n);
int		atoi_helper(char str, int *res, int sign);
int		is_sp(char c);
void	ft_threesort_h(t_stack *st_a, t_stack *st_b, int flag);
void	main_algo(t_stack *st_a, t_stack *st_b, int argc);
t_node	*create_node(size_t data_order, int data);
int		is_sign(char *str);
int		ft_first_error(int *values, size_t size);
int		ft_isnum(int *values);
int		ft_isorder(t_stack *st_a);
int		ft_word_c(const char *str, char ch, int argc);
void	ft_doublefree(int *values, size_t *rank);

#endif
