/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:28:26 by mfukui            #+#    #+#             */
/*   Updated: 2024/11/12 18:36:06 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_algorithm(t_stack *st_a, t_stack *st_b)
{
	size_t	d;
	size_t	c;

	d = 0;
	while (d < ft_max_bitlen(st_a))
	{
		ft_firstpush(st_a, st_b, d);// 01&11 : 00&10 d = 0
		d++;
		c = 0;
		while (i < st_b->size)
		{
			if ((st_b->top[i] & (1 << d)) == 1)
			{
				ft_push(st_b, st_a);
				c++;
			}
			else
				ft_rotate(st_b);
			i++;
		}//10&&01&11 : 00 d = 1
		i = 0;
		while (i < st_a->size)
		{
			if (i++ < c)
				ft_rotate(st_a);//01&11&&10 : 00
			else
			{
				if ((st_a->top[i] & (1 << d)) == 0)
					ft_push(st_a, st_b);
				else
					ft_rotate(st_b);
				i++;
			}//10&&11 : 01&&00
		}
		d++;
	}
}

void	ft_firstpush(t_stack *st_a, t_stack *st_b, size_t order)
{
	size_t	i;

	i = 0;
	while (i < st_a->size)
	{
		if ((st_a->top[i] & (1 << order)) == 0)
			ft_push(st_a, st_b);
		else
			ft_rotate(st_a);
		i++;
	}
}

size_t	ft_secondpush(t_stack *st_a, t_stack *st_b, size_t order)
{
	size_t	i;
	size_t	count;

	i = 0;
	
}