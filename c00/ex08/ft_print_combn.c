/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmkargi <ahmkargi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 20:20:38 by ahmkargi          #+#    #+#             */
/*   Updated: 2026/08/29 14:07:25 by ahmkargi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_comb(int n, int pos, int start, int *comb)
{
	int	i;

	if (pos == n)
	{
		i = 0;
		while (i < n)
		{
			ft_putchar(comb[i] + '0');
			i++;
		}
		if (comb[0] != 10 - n)
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
		return ;
	}
	i = start;
	while (i <= 10 - (n - pos))
	{
		comb[pos] = i;
		print_comb(n, pos + 1, i + 1, comb);
		i++;
	}
}

void	ft_print_combn(int n)
{
	int	comb[10];

	if (n > 0 && n < 10)
		print_comb(n, 0, 0, comb);
}
