/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:15:12 by mfukui            #+#    #+#             */
/*   Updated: 2025/01/03 18:24:15 by mfukui           ###   ########.fr       */
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

int ft_first_error(int *values, size_t size)
{
	if (!values)
	{
		return (0);
	}
	else if (ft_duplication(values, size) == 1)
	{
		ft_error(2);
		free(values);
		return (0);
	}
	return (1);
}

int	ft_duplication(int *arg, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!arg)
		return (0);
	while (i < size)
	{
		j = 0;
		while (i + j + 1 < size)
		{
			if (arg[i] == arg[i + j + 1])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_isnum(int *values)
{
	size_t	i;

	i = 0;
	if (!values)
		return (0);
	while(values[i])
		if(ft_isdigit(values[i]) == 0)
			return (0);
	return (1);
}
