/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:26:01 by mfukui            #+#    #+#             */
/*   Updated: 2024/07/09 16:36:14 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	*ft_atoi_rmkd(size_t argc, const char **str)
{
	size_t	c;
	size_t	i;
	int		sign;
	long	*result;

	result = malloc(argc * sizeof(int));
	if (!result)
		return (NULL);
	c = 0;
	while(c < argc)
	{
		i = 0;
		sign = 1;
		while (str[c][i] == ' ' || (9 <= str[c][i] && str[c][i] <= 13))
			i++;
		if (str[c][i] == '+' || str[c][i] == '-')
			if (str[c][i++] == '-')
				sign = -1;
		while ('0' <= str[c][i] && str[c][i] <= '9')
		{
			if ((INT_MAX - (str[c][i] - '0')) / 10 < result[c] * sign)
				return (free(result), -2);
			if ((INT_MIN + (str[c][i] - '0')) / 10 > result[c] * sign)
				return (free(result), -2);
			result[c] = result[c] * 10 + (str[c][i++] - '0');
		}
		if (ft_isdigit(result[c]) == 0)
			return (-3);
		result[c++] *= sign;
	}
	return (result);
}

size_t	*ft_assign_rank(int *str)
{
	size_t	i;
	size_t	j;
	size_t	*result;

	result = malloc(sizeof(size_t) * ft_strlen(str));
	if (!result)
		return (NULL);
	i = 0;
	while(str[i])
		result[i++] = 0;
	i = 0;
	while(str[i])
	{
		j = 0;
		while(str[j])
		{
			if(str[j] > str[i])
				result[i]++;
			j++;
		}
		i++;
	}
	return (result);
}

size_t	ft_max_bitlen(int *rank)
{
	size_t	result;
	size_t	i;

	i = 0;
	result = 0;
	while(rank[i])
	{
		if(result < rank[i])
			result = rank[i];
		i++;
	}
	result = ft_bitlen(rank[i]);
	return (result);
}

size_t	ft_bitlen(size_t num)
{
	size_t	len;

	len = 0;
	while(num)
	{
		len++;
		num /= 2;
	}
	return (len);
}