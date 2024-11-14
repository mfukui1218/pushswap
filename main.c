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
	int	*values;
	size_t *rank;

	if (argc < 2)
		return (ft_error(0), 1);
	values = ft_atoi_rmkd(argv + 1, argc);
	if(!values)
		return (1);
	rank = ft_assign_rank(values, argc - 1);
	if (!rank)
    {
        free(values);
        return (1);
    }
	st_a = init_stack(argc - 1, rank);
	st_b = init_stack(0, NULL);
	free(rank);
	if (!st_a || !st_b)
	{
		free_stack(st_a);
		free_stack(st_b);
		return (ft_error(4), 1);
	}
	if (argc - 1 <= 3)
		ft_threesort(st_a, st_b, 0);
	else if (argc - 1 == 5)
		ft_fivesort(st_a, st_b);
	else
		ft_algorithm(st_a, st_b, ft_bitlen(argc - 1));
	printf("%zu\n", ft_bitlen(argc - 1));
	printf("Stack A: ");
    print_stack(st_a);
    printf("Stack B: ");
    print_stack(st_b);
	free_stack(st_a);
	free_stack(st_b);
	return (0);
}


char *int_to_binary(int n) {
    int bits = sizeof(int) * 1; // intのビット数（通常32ビット）
    char *binary_str = (char *)malloc(bits + 1); // 終端文字分+1
    if (!binary_str) return NULL; // メモリ確保エラー時

    binary_str[bits] = '\0'; // 文字列の終端

    for (int i = bits - 1; i >= 0; i--) {
        binary_str[i] = (n & 1) ? '1' : '0';
        n >>= 1; // 1ビット右シフト
    }

    return binary_str;
}

void print_stack(t_stack *stack)
{
    t_node *current;

    if (!stack || !stack->top) // 空のスタックの場合
    {
        printf("(empty)\n");
        return;
    }

    current = stack->top;
    while (current)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// int main(int argc, char **argv)
// {
// 	t_stack	*st_a;
// 	t_stack	*st_b;
// 	int	*values;
// 	size_t *rank;

// 	values = ft_atoi_rmkd(argv + 1);
// 	if(!values)
// 		return (ft_error(4), 1);
// 	rank = ft_assign_rank(values, argc - 1);
// 	if (!rank)
//     {
//         free(values);
//         return (1);
//     }
// 	st_a = init_stack(argc - 1, rank);
// 	st_b = init_stack(0, NULL);
// 	free(rank);
// 	printf("Stack A: ");
//     print_stack(st_a);
//     printf("Stack B: ");
//     print_stack(st_b);
// 	printf("\n");
// 	printf("------------");
// 	printf("\n");
// 	ft_push(st_a, st_b, 'b');
// 	printf("Stack A: ");
//     print_stack(st_a);
//     printf("Stack B: ");
//     print_stack(st_b);
// 	ft_push(st_b, st_a, 'b');
// 	printf("Stack A: ");
//     print_stack(st_a);
//     printf("Stack B: ");
//     print_stack(st_b);
// 	printf("\n");
// 	printf("------------");
// 	printf("\n");
// 	free_stack(st_a);
// 	free_stack(st_b);
// }