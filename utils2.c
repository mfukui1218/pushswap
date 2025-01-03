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
		ft_threesort(st_a, st_b, 0);
	else if (argc - 1 == 5)
		ft_fivesort(st_a, st_b);
	else
		ft_algorithm(st_a, st_b, ft_bitlen(argc - 1));
}

int	is_sign(char **str)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j])
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}
