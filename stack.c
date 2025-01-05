/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:20:19 by mfukui            #+#    #+#             */
/*   Updated: 2025/01/03 20:16:59 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack)
		return ;
	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}

t_stack	*init_stack(size_t size, size_t *rank, int *values)
{
	t_stack	*stack;
	t_node	*node;
	t_node	*temp;
	size_t	i;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (ft_error(4), NULL);
	stack->top = NULL;
	stack->size = 0;
	i = 0;
	while (i < size)
	{
		node = create_node(rank[i], values[i]);
		if (!node)
			return (free_stack(stack), NULL);
		if (i == 0)
		{
			stack->top = node;
			temp = node;
		}
		else
		{
			temp->next = node;
			node->prev = temp;
			temp = node;
		}
		stack->size++;
		i++;
	}
	return (stack);
}

t_node	*create_node(size_t data_order, int data)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->data_order = data_order;
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
