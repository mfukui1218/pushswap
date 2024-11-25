/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:15:15 by mfukui            #+#    #+#             */
/*   Updated: 2024/11/25 19:26:29 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_stack	*st_a;
	t_stack	*st_b;
	int		*values;
	size_t	*rank;

	if (argc < 2)
		return (ft_error(0), 1);
	values = ft_atoi_rmkd(argv + 1, argc);
	if (!values)
		return (1);
	rank = ft_assign_rank(values, argc - 1);
	if (!rank)
		return (free(values), 1);
	st_a = init_stack(argc - 1, rank);
	st_b = init_stack(0, NULL);
	free(rank);
	if (!st_a || !st_b)
		return (free_stack(st_a), free_stack(st_b), ft_error(4), 1);
	if (argc - 1 == 3)
		ft_threesort(st_a, st_b, 0);
	else if (argc - 1 == 5)
		ft_fivesort(st_a, st_b);
	else
		ft_algorithm(st_a, st_b, ft_bitlen(argc - 1));
	return (free_stack(st_a), free_stack(st_b), 0);
}
