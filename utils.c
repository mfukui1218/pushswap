/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:26:01 by mfukui            #+#    #+#             */
/*   Updated: 2024/11/25 19:35:35 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

size_t	*ft_assign_rank(int *str, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	*result;

	result = malloc(sizeof(size_t) * size);
	if (!result)
		return (ft_error(4), NULL);
	i = 0;
	while (i < size)
	{
		result[i] = 0;
		j = 0;
		while (j < size)
		{
			if (!str)
				return (ft_error(1), free(result), NULL);
			if (str[j] > str[i])
				result[i]++;
			j++;
		}
		i++;
	}
	return (result);
}

size_t	ft_bitlen(size_t num)
{
	size_t	len;

	len = 0;
	while (num)
	{
		len++;
		num /= 2;
	}
	return (len);
}

int	*ft_atoi_rmkd(char **str, size_t argc)
{
	size_t	i;
	size_t	j;
	int		sign;
	int		*result;

	result = ft_calloc(argc, sizeof(int));
	if (!result)
		return (ft_error(4), NULL);
	i = 0;
	while (str[i])
	{
		sign = 1;
		j = 0;
		while (is_sp(str[i][j]) == 1 || str[i][j] == '+' || str[i][j++] == '-')
			if (str[i][j++] == '-')
				sign = -1;
		while (ft_isdigit(str[i][j++] == 1))
			atoi_helper(str[i][j], result);
		if (str[i][j] != '\0')
			return (ft_error(1), NULL);
		result[i++] *= sign;
	}
	if (ft_duplication(result, argc - 1) == 1)
		return (ft_error(2), NULL);
	return (result);
}

void	atoi_helper(char str, int *res)
{
	if ((INT_MAX - (str - '0')) / 10 < *res * sign)
		return (ft_error(3), free(res), NULL);
	if ((INT_MIN + (str - '0')) / 10 > *res * sign)
		return (ft_error(3), free(res), NULL);
	*res = *res * 10 + (str - '0');
}

int	is_sp(int c)
{
	if (c == ' ' || (9 <= c && c <= 13))
		return (1);
	return (0);
}
