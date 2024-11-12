/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 02:19:12 by mfukui            #+#    #+#             */
/*   Updated: 2024/11/12 18:12:54 by mfukui           ###   ########.fr       */
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
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	size_t	size;
}	t_stack;


void	ft_swap(t_stack *stack);
void	ft_push(t_stack *st_a, t_stack *st_b);
void	ft_rotate(t_stack *stack);
void	ft_reverse_rotate(t_stack *stack);
void	ft_twosort(t_stack *stack);
void	ft_threesort(t_stack *stack);
void	ft_fivesort(t_stack *st_a, t_stack *st_b);
void	ft_radix_sort(t_stack *st_a, t_stack *st_b);
size_t	*ft_assign_rank(int *str);
size_t	ft_max_bitlen(int *rank);
size_t	ft_bitlen(size_t num);
void	ft_error(int i);


#endif