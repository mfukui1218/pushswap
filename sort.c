/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:25:53 by mfukui            #+#    #+#             */
/*   Updated: 2024/11/12 18:07:31 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack->top || !stack->top->next)
		return (NULL);
	first = stack->top;
	second = stack->top->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	stack->top = second;
}

void	ft_push(t_stack *st_a, t_stack *st_b)
{
	t_node	*new_dst;

	if (!st_a || !st_a->top)
		return (NULL);
	new_dst = st_a->top;
	st_a->top = new_dst->next;
	if (st_a->top)
		st_a->top->prev = NULL;
	new_dst->next = st_b->top;
	if (st_b->top)
		st_b->top->prev = new_dst;
	st_b->top = new_dst;
	st_a->size--;
	st_b->size++;
}

void	ft_rotate(t_stack *stack)
{
	t_node	*last;
	t_node	*second_last;

	if (!stack->top || !stack->top->next)
		return (NULL);
	last = stack->top;
	while (last->next != NULL)
		last = last->next;
	second_last = last->prev;
	second_last->next = NULL;
	last->prev = NULL;
	last->next = stack->top;
	stack->top->prev = last;
	stack->top = last;
}

void	ft_revercse_rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack->top || !stack->top->next)
		return (NULL);
	first = stack->top;
	last = stack->top;
	while (last->next != NULL)
		last = last->next;
	stack->top = first->next;
	stack->top->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}
