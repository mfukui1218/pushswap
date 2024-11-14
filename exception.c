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
	if (st_a->top->data > st_a->top->next->data)
		ft_swap(st_a, 'a');
}

void	ft_threesort(t_stack *st_a, t_stack *st_b, int flag)
{
	if (st_a->top->data == 0 && st_a->top->next->data == 2 && st_a->top->next->next->data == 1)
	{
		ft_rotate(st_a, 'a');
		if(flag == 1)
			ft_swap(st_a, 'a');
		else
			ft_ss(st_a, st_b);
		ft_reverse_rotate(st_a, 'a');
	}
	else 
	{
		if (st_a->top->data== 1 && st_a->top->next->data== 0 \
		&& st_a->top->next->next->data == 2)
			ft_swap(st_a, 'a');
		else if (st_a->top->data== 1 && st_a->top->next->data== 2 \
		&& st_a->top->next->next->data == 0)
			ft_reverse_rotate(st_a, 'a');
		else if (st_a->top->data== 2 && st_a->top->next->data== 0 \
		&& st_a->top->next->next->data == 1)
			ft_rotate(st_a, 'a');
		else if (st_a->top->data== 2 && st_a->top->next->data== 1 \
		&& st_a->top->next->next->data == 0)
		{
			ft_swap(st_a, 'a');
			ft_reverse_rotate(st_a, 'a');
		}
		if(flag == 0)
			ft_swap(st_b, 'b');
	}
}

void	ft_fivesort(t_stack *st_a, t_stack *st_b)
{
	size_t	i;

	i = 0;
	while (i < 5)
	{
		if (st_a->top->data== 3 || st_a->top->data== 4)
			ft_push(st_a, st_b, 'b');
		else
			ft_rotate(st_a, 'a');
		i++;
	}
	if(st_b->top->data == 4)
		ft_threesort(st_a, st_b, 1);
	else
		ft_threesort(st_a, st_b, 0);
	ft_push(st_b, st_a, 'a');
	ft_push(st_b, st_a, 'a');
	ft_rotate(st_a, 'a');
	ft_rotate(st_a, 'a');
}
