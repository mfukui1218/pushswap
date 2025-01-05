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
	if (st_a->top->data_order == 1)
		ft_swap(st_a, 'a');
}

void	ft_threesort(t_stack *st_a)
{
	if (st_a->top->data_order == 0 && st_a->top->next->data_order == 2 \
	&& st_a->top->next->next->data_order == 1)
	{
		ft_swap(st_a, 'a');
		ft_rotate(st_a, 'a');
	}
	else if (st_a->top->data_order == 1 && st_a->top->next->data_order == 0 \
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
}

void	ft_foursort(t_stack *st_a, t_stack *st_b)
{
	size_t	i;

	if (st_a->top->data_order == 0 && st_a->top->next->data_order == 1 \
		&& st_a->top->next->next->data_order == 2)
		return ;
	i = 0;
	while (i < 4)
	{
		if (st_a->top->data_order == 2 || st_a->top->data_order == 3)
			ft_push(st_a, st_b, 'b');
		else
			ft_rotate(st_a, 'a');
		i++;
	}
	if (st_a->top->data_order == 0 && st_b->top->data_order == 2)
		ft_swap(st_b, 'b');
	else if (st_a->top->data_order == 1 && st_b->top->data_order == 3)
		ft_swap(st_a, 'a');
	else if (st_a->top->data_order == 1 && st_b->top->data_order == 2)
		ft_ss(st_a, st_b);
	ft_push(st_b, st_a, 'a');
	ft_push(st_b, st_a, 'a');
	ft_rotate(st_a, 'a');
	ft_rotate(st_a, 'a');
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
		ft_threesort(st_a);
	else
		ft_three_to_five(st_a, st_b);
	ft_push(st_b, st_a, 'a');
	ft_push(st_b, st_a, 'a');
	ft_rotate(st_a, 'a');
	ft_rotate(st_a, 'a');
}

void	ft_three_to_five(t_stack *st_a, t_stack *st_b)
{
	if (st_a->top->data_order == 0 && st_a->top->next->data_order == 2 \
	&& st_a->top->next->next->data_order == 1)
	{
		ft_ss(st_a, st_b);
		ft_rotate(st_a, 'a');
	}
	else if (st_a->top->data_order == 1 && st_a->top->next->data_order == 0 \
	&& st_a->top->next->next->data_order == 2)
		ft_ss(st_a, st_b);
	else if (st_a->top->data_order == 1 && st_a->top->next->data_order == 2 \
	&& st_a->top->next->next->data_order == 0)
	{
		ft_reverse_rotate(st_a, 'a');
		ft_swap(st_b, 'b');
	}
	else if (st_a->top->data_order == 2 && st_a->top->next->data_order == 0 \
	&& st_a->top->next->next->data_order == 1)
	{
		ft_rotate(st_a, 'a');
		ft_swap(st_b, 'b');
	}
	else if (st_a->top->data_order == 2 && st_a->top->next->data_order == 1 \
	&& st_a->top->next->next->data_order == 0)
	{
		ft_ss(st_a, st_b);
		ft_reverse_rotate(st_a, 'a');
	}
}