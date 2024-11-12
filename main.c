/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:15:15 by mfukui            #+#    #+#             */
/*   Updated: 2023/11/12 16:11:46 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;

    if (argc < 2)
        return (0);

    stack_a = init_stack(argc - 1, argv + 1);
    stack_b = init_stack(0, NULL);

    if (!stack_a || !stack_b)
    {
        ft_error(4);
        return (1);
    }
    if (argc - 1 <= 3)
        ft_threesort(stack_a);
    else if (argc - 1 <= 5)
        ft_fivesort(stack_a, stack_b);
    else
        ft_radix_sort(stack_a, stack_b);

    free_stack(stack_a);
    free_stack(stack_b);

    return (0);
}