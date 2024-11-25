/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:28:26 by mfukui            #+#    #+#             */
/*   Updated: 2024/11/25 18:54:00 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_algorithm(t_stack *st_a, t_stack *st_b, size_t bitlen)
{
	size_t	d;
	size_t	c;
	size_t	i;

	ft_firstpush(st_a, st_b);
	d = 1;
	while (d < bitlen)
	{
		c = ft_secondpush(st_a, st_b, d);
		i = 0;
		while (i++ < c)
			ft_rotate(st_a, 'a');
		ft_thirdpush(st_a, st_b, d, c);
		d++;
	}
	ft_lastpush(st_a, st_b);
}

void	ft_firstpush(t_stack *st_a, t_stack *st_b)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = st_a->size;
	while (i < size)
	{
		if ((st_a->top->data & (1 << 0)) == 0)
			ft_push(st_a, st_b, 'b');
		else
			ft_rotate(st_a, 'a');
		i++;
	}
}

size_t	ft_secondpush(t_stack *st_a, t_stack *st_b, size_t order)
{
	size_t	i;
	size_t	c;
	size_t	size;

	i = 0;
	c = 0;
	size = st_b->size;
	while (i < size)
	{
		if ((st_b->top->data & (1 << order)) != 0)
		{
			ft_push(st_b, st_a, 'a');
			c++;
		}
		else
			ft_rotate(st_b, 'b');
		i++;
	}
	return (c);
}

void	ft_thirdpush(t_stack *st_a, t_stack *st_b, size_t order, size_t c)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = st_a->size - c;
	while (i < size)
	{
		if ((st_a->top->data & (1 << order)) == 0)
			ft_push(st_a, st_b, 'b');
		else
			ft_rotate(st_a, 'a');
		i++;
	}
}

void	ft_lastpush(t_stack *st_a, t_stack *st_b)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = st_b->size;
	while (i++ < size)
		ft_push(st_b, st_a, 'a');
}
