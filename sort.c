/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:25:53 by mfukui            #+#    #+#             */
/*   Updated: 2024/07/17 17:08:41 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void ft_swap(t_stack *stack) //a1<->a2
{
    t_node *first;
    t_node *second;

    if (!stack->top || !stack->top->next)
        return;
    first = stack->top;
    second = stack->top->next;
    first->next = second->next;
    if(second->next)
        second->next->prev = first;
    second->prev = NULL;
    second->next = first;
    first->prev = second;
    stack->top = second;
}

void ft_push(t_stack *stack_a, t_stack *stack_b) //a  >>  b
{
    t_node    *new_dst;

    if(!stack_a || !stack_a->top)
        return;
    new_dst = stack_a->top;
    stack_a->top = new_dst->next;
    if(stack_a->top)
        stack_a->top->prev = NULL;
    new_dst->next = stack_b->top;
    if(stack_b->top)
        stack_b->top->prev = new_dst;
    stack_b->top = new_dst;
    stack_a->size--;
    stack_b->size++;
}

void ft_rotate(t_stack *stack) //a1 a2 >> a2 a3
{
    t_node     *last;
    t_node     *second_last;

    if (!stack->top || !stack->top->next)
        return;
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

void ft_revercse_rotate(t_stack *stack)///a1 b1 >> a1 a2
{   
    t_node   *first;
    t_node   *last;

    if (!stack->top || !stack->top->next)
        return;
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