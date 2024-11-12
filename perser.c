/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:15:12 by mfukui            #+#    #+#             */
/*   Updated: 2024/11/12 17:59:59 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_error(int i)
{
	if (i == 0)
		ft_printf("%s", "Error: Not enough arguments\n");
	else if (i == 1)
		ft_printf("%s", "Error: Non-integer argument detected\n");
	else if (i == 2)
		ft_printf("%s", "Error: Duplicate arguments detected\n");
	else if (i == 3)
		ft_printf("%s", "Error: Argument out of integer range\n");
	else if (i == 4)
		ft_printf("%s", "Error: Memory allocation failed\n");
	else if (i == 5)
		ft_printf("%s", "Error: Invalid instruction\n");
}


int	ft_duplication(int *arg)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (arg[i])
	{
		j = 0;
		while (arg[i + j + 1])
		{
			if (i != i + j + 1 && arg[i] == arg[i + j + 1])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
