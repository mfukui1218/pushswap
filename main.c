/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:15:15 by mfukui            #+#    #+#             */
/*   Updated: 2024/11/12 17:58:43 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_stack	*st_a;
	t_stack	*st_b;

	if (argc < 2)
		return (0);
	st_a = init_stack(argc - 1, argv + 1);
	st_b = init_stack(0, NULL);
	if (!st_a || !st_b)
	{
		ft_error(4);
		return (1);
	}
	if (argc - 1 <= 3)
		ft_threesort(st_a);
	else if (argc - 1 <= 5)
		ft_fivesort(st_a, st_b);
	else
		ft_radix_sort(st_a, st_b);
	free_stack(st_a);
	free_stack(st_b);
	return (0);
}