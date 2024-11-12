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

size_t	*ft_assign_rank(int *str)
{
	size_t	i;
	size_t	j;
	size_t	*result;

	result = malloc(sizeof(size_t) * ft_strlen(str));
	if (!result)
		return (NULL);
	i = 0;
	while (str[i])
		result[i++] = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[j])
		{
			if (str[j] > str[i])
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
	while (rank[i])
	{
		if (result < rank[i])
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
	while (num)
	{
		len++;
		num /= 2;
	}
	return (len);
}
