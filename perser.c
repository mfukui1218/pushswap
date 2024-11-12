/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:15:12 by mfukui            #+#    #+#             */
/*   Updated: 2024/07/09 16:48:17 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void    ft_error(int i)
{
    // エラーコードが 0 の場合の処理
    if (i == 0)
        ft_printf("%s", "Error: Not enough arguments\n");  // 引数が不足している場合のエラーメッセージを表示
    // エラーコードが 1 の場合の処理
    else if (i == 1)
        ft_printf("%s", "Error: Non-integer argument detected\n");  // 整数以外の引数が検出された場合のエラーメッセージを表示
    // エラーコードが 2 の場合の処理
    else if (i == 2)
        ft_printf("%s", "Error: Duplicate arguments detected\n");  // 重複する引数が検出された場合のエラーメッセージを表示
    // エラーコードが 3 の場合の処理
    else if (i == 3)
        ft_printf("%s", "Error: Argument out of integer range\n");  // 引数が整数の範囲外である場合のエラーメッセージを表示
    // エラーコードが 4 の場合の処理
    else if (i == 4)
        ft_printf("%s", "Error: Memory allocation failed\n");  // メモリの割り当てに失敗した場合のエラーメッセージを表示
    // エラーコードが 5 の場合の処理
    else if (i == 5)
        ft_printf("%s", "Error: Invalid instruction\n");  // 無効な操作が検出された場合のエラーメッセージを表示
}


int ft_duplication(int *arg)   //重複 ?1:０
{
    size_t  i;
    size_t  j;

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
