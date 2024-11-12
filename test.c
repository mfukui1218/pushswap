#include "pushswap.h"

// int	**ft_itob(size_t argc, size_t *rank)
// {
// 	int		**result;
// 	size_t	i;
// 	size_t	j;

// 	**result = malloc(sizeof(int*) * argc);
// 	if (!result)
// 		return (NULL);
// 	i = 0;
// 	while (i++ < argc)
// 	{
// 		result[i] = malloc(sizeof(int) * 64);
// 		if (!result[i])
// 			return (NULL); 
// 		j = 0;
// 		while (rank[i])
// 		{
// 			result[i][j] = rank[i] % 2;
// 			rank[i] /= 2;
// 			j++;
// 		}
// 		while (j < 32)
// 			result[i][j] = 0;
// 	}
// 	return (result);
// }



void	ft_swap(int *x, int *y)
{
    int *a;
    int i;

	i = 0;
	while (i < 10)
	{
		*a = (1 << i);
		i++;
		printf("%d\n", *a);
	}
}

int	main()
{
	int a = 1;
	int b = 2;

	ft_swap(&a,&b);

	return 0;
}