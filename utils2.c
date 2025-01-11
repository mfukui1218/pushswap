/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:25:42 by mfukui            #+#    #+#             */
/*   Updated: 2025/01/03 20:11:16 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	main_algo(t_stack *st_a, t_stack *st_b, int argc)
{
	if (argc - 1 == 2)
		ft_twosort(st_a);
	else if (argc - 1 == 3)
		ft_threesort(st_a);
	else if (argc - 1 == 4)
		ft_foursort(st_a, st_b);
	else if (argc - 1 == 5)
		ft_fivesort(st_a, st_b);
	else
		ft_algorithm(st_a, st_b, ft_bitlen(argc - 1));
}

int	is_sign(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			return (-1);
		i++;
	}
	return (1);
}

int ft_isorder(t_stack *st_a)
{
	t_node *current;

	current = st_a->top;
	while(current && current->next)
	{
		if(current->data > current->next->data)
			return(0);
		current = current->next;
	}
	return (1);
}

int	ft_word_c(const char *str, char ch, int argc)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	if(argc == 1)
		return (-1);
	while (str[i])
	{
		while (str[i] == ch)
			i++;
		if (str[i] && str[i] != ch)
		{
			c++;
			while (str[i] && str[i] != ch)
			{
				if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '+' || str[i] == '-'))
					return (ft_error(1), -1);
				i++;
			}
		}
	}
	return (c);
}

void	ft_doublefree(int *values, size_t *rank)
{
	free(values);
	free(rank);
}
// void print_stack(t_stack *stack) {
//     t_node *current = stack->top;
//     printf("Stack: ");
//     while (current)
// 	{
//         printf("data:%d ", current->data);
// 		printf("data_order:%ld \n", current->data_order);
//         current = current->next;
//     }
//     printf("\n");
// }