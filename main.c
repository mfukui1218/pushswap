/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:15:15 by mfukui            #+#    #+#             */
/*   Updated: 2025/01/03 20:06:15 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_stack	*st_a;
	t_stack	*st_b;
	int		*values;
	size_t	*rank;

	if (argc <= 2)
	{
		argc = ft_word_c(argv[1], ' ', argc) + 1;
		argv = ft_split(argv[1], ' ');
	}
	else
		argv = argv + 1;
	values = ft_atoi_rmkd(argv, argc);
	if (ft_first_error(values, argc - 1) == 0)
		return (1);
	rank = ft_assign_rank(values, argc - 1);
	if (!rank)
		return (free(values), 1);
	st_a = init_stack(argc - 1, rank, values);
	st_b = init_stack(0, NULL, NULL);
	ft_doublefree(values, rank);
	if (!st_a || !st_b)
		return (free_stack(st_a), free_stack(st_b), ft_error(4), 1);
	main_algo(st_a, st_b, argc);
	return (free_stack(st_a), free_stack(st_b), 0);
}
