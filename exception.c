/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:30:05 by mfukui            #+#    #+#             */
/*   Updated: 2024/11/25 19:29:06 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_twosort(t_stack *st_a)
{
	if (st_a->top->data_order > st_a->top->next->data_order)
		ft_swap(st_a, 'a');
}

void	ft_threesort(t_stack *st_a, t_stack *st_b, int flag)
{
	if (st_a->top->data_order == 0 && st_a->top->next->data_order == 2 \
	&& st_a->top->next->next->data_order == 1)
		ft_threesort_h(st_a, st_b, flag);
	else
	{
		if (st_a->top->data_order == 1 && st_a->top->next->data_order == 0 \
		&& st_a->top->next->next->data_order == 2)
			ft_swap(st_a, 'a');
		else if (st_a->top->data_order == 1 && st_a->top->next->data_order == 2 \
		&& st_a->top->next->next->data_order == 0)
			ft_reverse_rotate(st_a, 'a');
		else if (st_a->top->data_order == 2 && st_a->top->next->data_order == 0 \
		&& st_a->top->next->next->data_order == 1)
			ft_rotate(st_a, 'a');
		else if (st_a->top->data_order == 2 && st_a->top->next->data_order == 1 \
		&& st_a->top->next->next->data_order == 0)
		{
			ft_swap(st_a, 'a');
			ft_reverse_rotate(st_a, 'a');
		}
		if (flag == 0)
			ft_swap(st_b, 'b');
	}
}

void	ft_threesort_h(t_stack *st_a, t_stack *st_b, int flag)
{
	ft_rotate(st_a, 'a');
	if (flag == 1)
		ft_swap(st_a, 'a');
	else
		ft_ss(st_a, st_b);
	ft_reverse_rotate(st_a, 'a');
}

void	ft_fivesort(t_stack *st_a, t_stack *st_b)
{
	size_t	i;

	i = 0;
	while (i < 5)
	{
		if (st_a->top->data_order == 3 || st_a->top->data_order == 4)
			ft_push(st_a, st_b, 'b');
		else
			ft_rotate(st_a, 'a');
		i++;
	}
	if (st_b->top->data_order == 4)
		ft_threesort(st_a, st_b, 1);
	else
		ft_threesort(st_a, st_b, 0);
	ft_push(st_b, st_a, 'a');
	ft_push(st_b, st_a, 'a');
	ft_rotate(st_a, 'a');
	ft_rotate(st_a, 'a');
}
