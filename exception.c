/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:30:05 by mfukui            #+#    #+#             */
/*   Updated: 2024/11/12 17:57:10 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_twosort(t_stack *st_a)
{
	if (st_a->top > st_a->next)
		ft_swap(st_a);
}

void	ft_threesort(t_stack *st_a)
{
	if (st_a->top == 1 && st_a->top->next == 3 && st_a->top->next->next == 2)
	{
		ft_rotate(st_a);
		ft_swap(st_a);
		ft_revercse_rotate(st_a);
	}
	else if (st_a->top == 2 && st_a->top->next == 1 \
	&& st_a->top->next->next == 3)
		ft_swap(st_a);
	else if (st_a->top == 2 && st_a->top->next == 3 \
	&& st_a->top->next->next == 1)
		ft_revercse_rotate(st_a);
	else if (st_a->top == 3 && st_a->top->next == 1 \
	&& st_a->top->next->next == 2)
		ft_rotate(st_a);
	else if (st_a->top == 3 && st_a->top->next == 2 \
	&& st_a->top->next->next == 1)
	{
		ft_swap(st_a);
		ft_reverse_rotate(st_a);
	}
}

void	ft_fivesort(t_stack *st_a, t_stack *st_b)
{
	size_t	i;

	i = 0;
	while (i < 5)
	{
		if ((st_a->top[i] & (1 << 1)) == 1)
			ft_push(st_a, st_b);
		else
			ft_rotate(st_a);
		i++;
	}
}// totyuu
