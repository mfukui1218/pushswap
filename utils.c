/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:26:01 by mfukui            #+#    #+#             */
/*   Updated: 2024/11/12 18:10:37 by mfukui           ###   ########.fr       */
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
            {
                ft_error(1);
                free(result);
                return NULL;
            }
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

	result = (int *)malloc(sizeof(int) * ft_strlenx(str));
	if (!result)
		return (ft_error(4), NULL); 
	i = 0;
	while(str[i])
	{
		result[i] = 0;
		sign = 1;
		j = 0;
		while (str[i][j] == ' ' || (9 <= str[i][j] && str[i][j] <= 13))
			j++;
		if (str[i][j] == '+' || str[i][j] == '-')
			if (str[i][j++] == '-')
				sign = -1;
		while ('0' <= str[i][j] && str[i][j] <= '9')
		{
			if ((INT_MAX - (str[i][j] - '0')) / 10 < result[i] * sign)
				return (ft_error(3), free(result), NULL);
			if ((INT_MIN + (str[i][j] - '0')) / 10 > result[i] * sign)
				return (ft_error(3), free(result), NULL);
			result[i] = result[i] * 10 + (str[i][j] - '0');
			j++;
		}
		if(str[i][j] != '\0')
			return(ft_error(1), NULL);
		result[i] *= sign;
		i++;
	}
	if(ft_duplication(result, argc - 1) == 1)
		return(ft_error(2), NULL);
	return (result);
}

size_t ft_strlenx(char **str)
{
	size_t	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}